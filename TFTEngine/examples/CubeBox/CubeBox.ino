#include "TFTEngine.h"
#include <SoftwareSerial.h>

TFTEngine tft(A3,A2);

float cx = 160, cy = 120, focalLength = 2000.0;
int tx=0,ty=0;
float verts[24] = {10,-10,10, 10,10,10, -10,10,10, -10,-10,10, 10,-10,-10, 10,10,-10, -10,10,-10, -10,-10,-10};
uint8_t vertices[24] = {0,1,0,3,0,4,1,2,1,5,2,3,2,6,3,7,4,5,4,7,5,6,6,7};
vector3d points[8];
vector3d currentPoints[8];
vector2d positions[8];
TFTLine lines[12];
void setup() 
{
  
  Serial.begin(115200);
  for(int i=0;i<8;i++){
    points[i].x = verts[i*3]*4;
    points[i].y = verts[i*3+1]*4;
    points[i].z = verts[i*3+2]*4;
  }
  tft.begin(115200);
  delay(1000);
  tft.cls();
  tft.render();
  delay(1000);
}
void loop() 
{
  tx+=10;
  ty+=10;
  tx = tx>359?0:tx;
  ty = ty>359?0:ty;
  drawView();
  tft.render();
  delay(25);
}

void drawView() 
{
  int i;
  float t=tx*PI/180.0;
  float p=ty*PI/180.0;
  for(i=0;i<8;i++){
    currentPoints[i] = pointNewView(points[i],t,p);
    positions[i].x = cx+focalLength/(focalLength-currentPoints[i].x)*currentPoints[i].y;
    positions[i].y = cy-focalLength/(focalLength-currentPoints[i].x)*currentPoints[i].z;
  }
  for(i=0;i<12;i++){
    lines[i].start(positions[vertices[i*2]].x,positions[vertices[i*2]].y);
    lines[i].end(positions[vertices[i*2+1]].x,positions[vertices[i*2+1]].y);
    tft.draw(&lines[i]);
  }
}

vector3d pointNewView(vector3d v,float theta, float phi) 
{
  vector3d newCoords;
  newCoords.x = v.x*cos(theta)*sin(phi)+v.y*sin(theta)*sin(phi)+v.z*cos(phi);
  newCoords.y = -v.x*sin(theta)+v.y*cos(theta);
  newCoords.z = -v.x*cos(theta)*cos(phi)-v.y*sin(theta)*cos(phi)+v.z*sin(phi);
  return newCoords;
}