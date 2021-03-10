#include "TXLib.h"

void sky(int x1, int y1,int x2,int y2)
{
txSetFillColor(RGB(0, 230, 245));
txSetColor(RGB(0, 230, 245));
txRectangle(x1, y1, x2, y2);
}

void grass(int x1, int y1,int x2,int y2)
{
txSetFillColor(RGB(0, 200, 0));
txSetColor(RGB(0, 200, 0));
txRectangle(x1, y1, x2, y2);
}

void sun(int x, int y,int r)
{
txSetFillColor(RGB(255, 255, 0));
txSetColor(RGB(255, 255, 0),5);
txCircle(x, y, r);
txLine (x-100, y, x+100, y);
txLine (x-80, y-60, x+70, y+70);
txLine (x, y-90, x, y+100);
txLine (x-80, y+70, x+90, y-60);
}

void cloud(int x, int y, int r)
{
txSetFillColor(RGB(255, 255, 255));
txSetColor(RGB(255, 255, 255));
txCircle(x, y, r);
txEllipse (x, y/1.4, x*2, y*1.5);
txCircle(x*1.8, y, r);
txCircle(x+x/4, y-y/3, r);
txCircle(x+x/3, y+y/3, r);

}
void window(int x, int y, int r)
{
txSetFillColor(RGB(0, 0, 0));
txSetColor(RGB(0, 0, 0));
txCircle(x, y, r);

}

void children (int x, int y, int sizeX, int sizeY, COLORREF color,
double hand, double legs, double head, double twist)
{
txSetColor (color);
txSetFillColor (color);

POINT star[3] = {{x-50, y-50}, {x, y-100}, {x+50, y-50}};
          txPolygon (star, 3);

txLine (x, y - (0.35 + twist) * sizeY, x, y - 0.7*sizeY);

txLine (x, y - (0.35 + twist) * sizeY, x - (0.2 + legs) * sizeX, y);
txLine (x, y - (0.45 + twist) * sizeY, x + (0.5 + legs) * sizeX, y);

txLine (x, y - 0.65*sizeY, x - sizeX/2, y - 0.4*sizeY);
txLine (x, y - 0.65*sizeY, x + sizeX/1.2, y - (0.65 + hand) * sizeY);

txCircle (x, y - sizeY + (0.3 + head) * sizeX, 0.3*sizeX);
}

void wood (int x, int y, int sizeX, int sizeY, COLORREF color)
{
txSetColor (RGB(128, 100, 0));
txSetFillColor (RGB(128, 100, 0));
txRectangle(x-10, y, x , y-100);

txSetColor (color);
txSetFillColor (color);

POINT wood1[] = {{x-50, (y-50)/2}, {x, (y-100)/2}, {x+50, (y-50)/2},{x,(y-50)/2},{x-50, y-50}, {x, y-100}, {x+50, y-50}};
          txPolygon (wood1, 7);


  }

void roof(int x,  int y)
{
txSetColor(RGB(0, 0, 0),5);
POINT roof1[] = {{x-50, (y-50)/2}, {x, (y-100)/2}, {x+150, (y-50)/2}};
          txPolygon (roof1, 3);
}
void wall(int x,  int y)
{
txSetColor(RGB(250, 128, 128),5);
txSetFillColor (RGB(250, 128, 128));
txRectangle(x-50, y+100, x +150 , y-100);
}


int main()
{
txCreateWindow (800, 600);

sky(0,0,800,440);
grass(0,440,800,600);
sun(120,90,50) ;
children(500, 450, 100, 200, TX_RED, 0, 0, 0, 0);
wood(650, 450, 100, 200, TX_GREEN);
cloud(200,100,30);
cloud(40,50,30);
for (int i = 250; i < 345; i +=30 )
window(i,110,10);
roof(100, 550);
wall(100,355);

return 0;
}
