#include "TXLib.h"

void SkyDraw (int x1, int y1, int x2, int y2);
void GrassDraw (int x1, int y1, int x2, int y2);
void SunDraw (int x, int y, int r, float sizeX);
void AirplaneDraw (int x, int y, int r);
void WindowDraw (int x, int y, int r);
void ChildrenDraw (int x, int y, int sizeX, int sizeY, COLORREF color,
double hand, double legs, double head, double twist);
void WoodDraw (int x, int y, float sizeY, COLORREF color);
void RoofDraw (int x, int y);
void WallDraw (int x, int y);
void IronMenDraw (int x, int y, int sizeX, int sizeY, COLORREF color);


int main ()
    {
    txCreateWindow (800, 600);

    SkyDraw (0, 0, 800, 440);
    GrassDraw (0, 440, 800, 600);
    SunDraw (120, 90, 50, 1) ;
    ChildrenDraw (500, 450, 50, 100, TX_RED, 0, 0, 0, 0);
    WoodDraw (650, 450, 1, TX_GREEN);
    AirplaneDraw (200, 100, 30);
    AirplaneDraw (450, 100, 30);

    for (int i = 250; i < 345; i +=30 )
        WindowDraw (i, 110, 10);

    RoofDraw (100, 550);
    WallDraw (100, 355);

    float k = 2;
    for (int i = 80; i < 250; i +=50 )
        WoodDraw (i, 250, k, TX_GREEN);

    IronMenDraw (400, 350, 50, 50, TX_GRAY);
    ChildrenDraw (300, 450, 50, 100, TX_RED, 0, 0, 0, 0);
    SunDraw (620, 60, 20, 0.5) ;
    SunDraw (420, 260, 10, 0.3) ;

    return 0;
    }

void IronMenDraw (int x, int y, int sizeX, int sizeY, COLORREF color)
    {
    txSetColor (RGB (240, 230, 245));
    txSetFillColor (color);
    txRectangle (x, y - 0.5 * sizeY , x + 0.5 * sizeX, y);
    txRectangle (x - 0.5 * sizeX, y, x + 1.5 * sizeX, y + 0.5 * sizeY);
    txRectangle (x - 0.25 * sizeX, y + 0.5 * sizeY, x + sizeX, y + 1.5 * sizeY);
    txRectangle (x - 0.1 * sizeX, y + 1.5 * sizeY , x + 0.1 * sizeX, y + 2 *sizeY);
    txRectangle (x + 0.5 * sizeX, y + 1.5 * sizeY , x + 0.7 * sizeX, y + 2* sizeY);
    }

void SkyDraw (int x1, int y1, int x2, int y2)
    {
    txSetFillColor (RGB (0, 230, 245));
    txSetColor (RGB (0, 230, 245));
    txRectangle (x1, y1, x2, y2);
    }

void GrassDraw (int x1, int y1, int x2, int y2)
    {
    txSetFillColor (RGB (0, 200, 0));
    txSetColor (RGB (0, 200, 0));
    txRectangle (x1, y1, x2, y2);
    }

void SunDraw (int x, int y, int r, float sizeX)
    {
    txSetFillColor (RGB (255, 255, 0));
    txSetColor (RGB (255, 255, 0), 5);
    txCircle (x, y, r);
    txLine (x - 100 * sizeX, y, x + 100 * sizeX, y);
    txLine (x - 80 * sizeX, y - 60 * sizeX, x + 70 * sizeX, y + 70 * sizeX);
    txLine (x, y - 90 * sizeX, x, y + 100 * sizeX);
    txLine (x - 80 * sizeX, y + 70 * sizeX, x + 90 * sizeX, y - 60 * sizeX);
    }

void AirplaneDraw (int x, int y, int r)
    {
    txSetFillColor (RGB (255, 255, 255));
    txSetColor (RGB (255, 255, 255));
    txCircle (x, y, r);
    txEllipse (x, y/1.4, x + 200, y * 1.5);
    txCircle (x + x/4, y - y/3, r);
    txCircle (x + x/3, y + y/3, r);
    }

void WindowDraw (int x, int y, int r)
    {
    txSetFillColor (RGB (0, 0, 0));
    txSetColor (RGB (0, 0, 0));
    txCircle (x, y, r);
    }

void ChildrenDraw (int x, int y, int sizeX, int sizeY, COLORREF color,
double hand, double legs, double head, double twist)
    {
    txSetColor (color);
    txSetFillColor (color);

    POINT star[3] = {{x - sizeX/2, y - (0.35 + twist) * sizeY }, {x, y - 0.55 * sizeY }, {x + sizeX/2, y - (0.35 + twist) * sizeY }};
       txPolygon (star, 3);

    txLine (x, y - (0.35 + twist) * sizeY, x, y - 0.7*sizeY);

    txLine (x, y - (0.35 + twist) * sizeY, x - (0.2 + legs) * sizeX, y);
    txLine (x, y - (0.45 + twist) * sizeY, x + (0.5 + legs) * sizeX, y);

    txLine (x, y - 0.65 * sizeY, x - sizeX/2, y - 0.4 * sizeY);
    txLine (x, y - 0.65 * sizeY, x + sizeX/1.2, y - (0.65 + hand) * sizeY);

    txCircle (x, y - sizeY + (0.3 + head) * sizeX, 0.3 * sizeX);
    }

void WoodDraw (int x, int y, float sizeY, COLORREF color)
    {
    txSetColor (RGB (128, 100, 0));
    txSetFillColor (RGB (128, 100, 0));
    txRectangle (x - 10, sizeY * y, x , sizeY * y - 100);

    txSetColor (color);
    txSetFillColor (color);

    POINT wood1[] = {{x - 50,   ((sizeY * y - 50)/2)}, {x,  ((sizeY * y - 100)/2)}, {x+50,  ((sizeY * y - 50)/2)}, {x,  ((sizeY * y - 50)/2)}, {x - 50,   (sizeY * y - 50)}, {x,  (sizeY * y - 100)}, {x + 50, (sizeY * y - 50)}};
       txPolygon (wood1, 7);
    }

void RoofDraw (int x, int y)
    {
    txSetColor (RGB (0, 0, 0), 5);
    POINT roof1[] = {{x-50, (y-50)/2}, {x, (y-100)/2}, {x+150, (y-50)/2}};
       txPolygon (roof1, 3);
    }

void WallDraw (int x, int y)
    {
    txSetColor (RGB (250, 128, 128), 5);
    txSetFillColor (RGB (250, 128, 128));
    txRectangle (x-50, y+100, x +150 , y-100);
    }




