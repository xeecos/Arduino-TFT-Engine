#include "MeMCore.h"
#include <SoftwareSerial.h>

MeSerial tft(PORT_3);
struct Point3d{
  float x;
  float y;
  float z;
};
struct Point2d{
  float x;
  float y;
};
float fLen = 2000.0;
float cx = 160;
float cy = 120;
float verts[24] = {10,-10,10,
                  10,10,10,
                  -10,10,10,
                  -10,-10,10,
                  10,-10,-10,
                  10,10,-10,
                  -10,10,-10,
                  -10,-10,-10};
/*
 *  3  0
 * 2  1
 *  7  4
 * 6  5 
 */
Point3d points[8];
Point3d currentPoints[8];
Point2d positions[8];
void setup() 
{
  for(int i=0;i<8;i++){
    points[i].x = verts[i*3]*4;
    points[i].y = verts[i*3+1]*4;
    points[i].z = verts[i*3+2]*4;
  }
  Serial.begin(115200);
  tft.begin(115200);
  delay(1000);
  cls();
  delay(1000);
}
void cls(){
  tft.println("CLS(0);");
  tft.println("DR0;");
}
int prevX = 0;
int prevY = 0;
void drawBox(int x,int y){ 
  tft.print("BOXF(");
  tft.print(prevX);
  tft.print(",");
  tft.print(prevY); 
  int w = prevX+40;
  int h = prevY+40;
  tft.print(",");
  tft.print(w);
  tft.print(",");
  tft.print(h);
  tft.print(",0);");  
  tft.print("BOXF(");
  tft.print(x);
  tft.print(",");
  tft.print(y);
  tft.print(",");
  w = x+40;
  h = y+40;
  tft.print(w);
  tft.print(",");
  tft.print(h);
  tft.print(",4);");  
  prevX = x;
  prevY = y;
}
void eraseLine(int x1,int y1,int x2,int y2){
  tft.print("PL(");
  tft.print(x1);
  tft.print(",");
  tft.print(y1);
  tft.print(",");
  tft.print(x2);
  tft.print(",");
  tft.print(y2);
  tft.print(",0);");
}
void drawLine(int x1,int y1,int x2,int y2){
  tft.print("PL(");
  tft.print(x1);
  tft.print(",");
  tft.print(y1);
  tft.print(",");
  tft.print(x2);
  tft.print(",");
  tft.print(y2);
  tft.print(",4);");
}
void render(){
  tft.println();
}
int tx=0,ty=0;
void loop() 
{
  tx+=10;
  ty+=10;
  if(tx>359){
    tx = 0;
  }
  if(ty>359){
    ty = 0;
  }
  renderView(tx,ty);
  delay(25);
}
long t = 0;
void renderView(float t,float p) {
  int i;
  t=t*PI/180.0;
  p=p*PI/180.0;
  for(i=0;i<8;i++){
    currentPoints[i] = pointNewView(points[i],t,p);
  }
  eraseLine(positions[0].x,positions[0].y,positions[1].x,positions[1].y);
  eraseLine(positions[0].x,positions[0].y,positions[3].x,positions[3].y);
  eraseLine(positions[0].x,positions[0].y,positions[4].x,positions[4].y);
  eraseLine(positions[6].x,positions[6].y,positions[2].x,positions[2].y);
  eraseLine(positions[6].x,positions[6].y,positions[5].x,positions[5].y);
  eraseLine(positions[6].x,positions[6].y,positions[7].x,positions[7].y);
  eraseLine(positions[2].x,positions[2].y,positions[3].x,positions[3].y);
  eraseLine(positions[2].x,positions[2].y,positions[1].x,positions[1].y);
  eraseLine(positions[4].x,positions[4].y,positions[5].x,positions[5].y);
  eraseLine(positions[4].x,positions[4].y,positions[7].x,positions[7].y);
  eraseLine(positions[1].x,positions[1].y,positions[5].x,positions[5].y);
  eraseLine(positions[3].x,positions[3].y,positions[7].x,positions[7].y);
  for(i=0;i<8;i++){
    positions[i].x = cx+fLen/(fLen-currentPoints[i].x)*currentPoints[i].y;
    positions[i].y = cy-fLen/(fLen-currentPoints[i].x)*currentPoints[i].z;
  }
  drawLine(positions[0].x,positions[0].y,positions[1].x,positions[1].y);
  drawLine(positions[0].x,positions[0].y,positions[3].x,positions[3].y);
  drawLine(positions[0].x,positions[0].y,positions[4].x,positions[4].y);
  drawLine(positions[6].x,positions[6].y,positions[2].x,positions[2].y);
  drawLine(positions[6].x,positions[6].y,positions[5].x,positions[5].y);
  drawLine(positions[6].x,positions[6].y,positions[7].x,positions[7].y);
  drawLine(positions[2].x,positions[2].y,positions[3].x,positions[3].y);
  drawLine(positions[2].x,positions[2].y,positions[1].x,positions[1].y);
  drawLine(positions[4].x,positions[4].y,positions[5].x,positions[5].y);
  drawLine(positions[4].x,positions[4].y,positions[7].x,positions[7].y);
  drawLine(positions[1].x,positions[1].y,positions[5].x,positions[5].y);
  drawLine(positions[3].x,positions[3].y,positions[7].x,positions[7].y);
  render();
}
 
 
Point3d pointNewView(Point3d v,float theta, float phi) {
  Point3d newCoords;
  newCoords.x = v.x*cos(theta)*sin(phi)+v.y*sin(theta)*sin(phi)+v.z*cos(phi);
  newCoords.y = -v.x*sin(theta)+v.y*cos(theta);
  newCoords.z = -v.x*cos(theta)*cos(phi)-v.y*sin(theta)*cos(phi)+v.z*sin(phi);
  return newCoords;
}
