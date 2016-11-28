#include "TFTEngine.h"
#include <SoftwareSerial.h>

TFTEngine tft(12,13);

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
vector3d points[8];
vector3d currentPoints[8];
vector2d positions[8];
TFTLine lines[12];
uint8_t vertices[24] = {0,1,0,3,0,4,1,2,1,5,2,3,2,6,3,7,4,5,4,7,5,6,6,7};
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
  tft.cls();
  tft.render();
  delay(1000);
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
  for(i=0;i<8;i++){
    positions[i].x = cx+fLen/(fLen-currentPoints[i].x)*currentPoints[i].y;
    positions[i].y = cy-fLen/(fLen-currentPoints[i].x)*currentPoints[i].z;
  }
  for(i=0;i<12;i++){
    lines[i].start(positions[vertices[i*2]].x,positions[vertices[i*2]].y);
    lines[i].end(positions[vertices[i*2+1]].x,positions[vertices[i*2+1]].y);
    tft.draw(lines[i]);
  }
  tft.render();
}
vector3d pointNewView(vector3d v,float theta, float phi) {
  vector3d newCoords;
  newCoords.x = v.x*cos(theta)*sin(phi)+v.y*sin(theta)*sin(phi)+v.z*cos(phi);
  newCoords.y = -v.x*sin(theta)+v.y*cos(theta);
  newCoords.z = -v.x*cos(theta)*cos(phi)-v.y*sin(theta)*cos(phi)+v.z*sin(phi);
  return newCoords;
}
