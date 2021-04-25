//{===========================================================================
//! @file       GlazkovaElena_dz_5.cpp
//!
//! @brief      example cartoon
//!
//!             pen test using (TX Library, TXLib, CodeBlocks).
//!
//!             $Date: 2021-04-14$
//!             $Copyright: (C) EVGoLet/CodeBlocks (Elena Glazkova) <oleterterra@gmail.com> $
//}===========================================================================
#include "TXLib.h"
void StartTitles();
void Utro();
void StarDraw     (int x, int y, double size, COLORREF starColor);
void SkyDraw      (int x1, int y1, int x2, int y2);
void GrassDraw    (int x1, int y1, int x2, int y2);

void SunDraw      (int x,  int y,  int r,  double size, double sizeY, COLORREF diskColor, COLORREF luchColor,
                   double luch, double eyes, double smile);
void WoodListDraw (int x, int y, double sizeR, double sizeX, double sizeY, COLORREF stvolColor, COLORREF granstColor,
                   COLORREF listColor, COLORREF grancrColor, double stvol, double leaf);
void CrowDraw     (int x0, int y0, int x1, int y1, int sizeX, int sizeY, COLORREF color,COLORREF wingcolor, COLORREF legcolor,
                   double twist);
void WoodDraw     (int x, int y, double sizeX, double sizeY, COLORREF color, double leaf);
void ChildrenDraw (int x, int y, int sizeX, int sizeY, COLORREF color,
                   double hand, double legs, double head, double twist);
int main ()
    {
    txCreateWindow (800, 600);

    StartTitles();
    Utro();

    ChildrenDraw (500, 450, 50, 100, TX_RED, 0, 0, 0, 0);

//    AirplaneDraw (200, 100, 30);
//    AirplaneDraw (450, 100, 30);

//    for (int i = 250; i < 345; i +=30 )
//        WindowDraw (i, 110, 10);

/*     RoofDraw (100, 550);
 *     WallDraw (100, 355);
 *
 *     float k = 2;
 *     for (int i = 80; i < 250; i +=50 )
 *         WoodDraw (i, 250, k, TX_GREEN);
 *
 *     IronMenDraw (400, 350, 50, 50, TX_GRAY);
 *     ChildrenDraw (300, 450, 50, 100, TX_RED, 0, 0, 0, 0);
 */
  //  SunDraw (620, 60, 20, 0.5) ;
 //  SunDraw (420, 260, 10, 0.3) ;

    return 0;
    }

void StarDraw   (int x, int y, double size, COLORREF starColor)
    {
    txSetColor     (starColor);
    txSetFillColor (starColor);

    POINT star[8] = {{x, ROUND(y - 90*size)}, {ROUND(x + 30*size), ROUND(y - 30*size)},
                     {x + ROUND(90*size), y}, {ROUND(x + 30*size), ROUND(y + 30*size)},
                     {x, ROUND(y + 90*size)}, {ROUND(x - 30*size), ROUND(y + 30*size)},
                     {ROUND(x - 90*size), y}, {ROUND(x - 30*size), ROUND(y - 30*size)} };
          txPolygon (star, 8);
    }

void StartTitles()
    {
    txPlaySound ("sound/titr.wav");
    int t = 0;

    while (t <= 75)
        {
        txClear();

        txSetFillColor (RGB(255 - t*3, 255 - t*3, 255 - t*3));
        txSetColor     (TX_WHITE);

        txSelectFont ("Segoe Script", 80);
        txTextOut (800 - t*10, 100, "Если");
        txTextOut (850 - t*10, 150, " звезды ");
        txTextOut (900 - t*10, 200, "  зажигаются,");
        Sleep (50);
        t++;
        }
    for (int i = 1; i<=8; i++)
        {
        StarDraw  (rand()%(300-250+1) + 250 + i*100, rand()%(250-10+1) + 10 + i*10, 0.125*(rand()%(4-1)+1), TX_YELLOW);
        }
    txSleep (1000);
    txTextOut (-450 + t*10, 300, " ЗНАЧИТ");

    while (t >= 0)
        {
        txSetFillColor (RGB(255 - t*3, 255 - t*3, 255 - t*3));
        txSetColor     (RGB(255 - t*3, 255 - t*3, 255 - t*3));
        txRectangle (0, 400, 800, 600);

        txSetColor (TX_BLACK);
        txSelectFont ("Segoe Script", 90);
        txTextOut (350 - t*10, 400, "это ");

        txSelectFont ("Segoe Script", 80);
        txTextOut (200 - t*10, 480, "кому-нибудь нужно");

        txSleep (50);
        t--;
        }


    txSleep (2000);
    txPlaySound (NULL);  //завершение музыки
    }

void Utro()
    {
    txBegin();

    SkyDraw      (0,   0, 800, 440);
    GrassDraw    (0, 440, 800, 600);
    WoodListDraw (200, 320, 1, 1, 1, TX_BROWN, TX_LIGHTRED, TX_LIGHTGREEN, TX_GREEN, 0, 1);
    WoodDraw     (650, 450, 1, 1, TX_GREEN, 1);


    int x = 800;
    while (x >= 100)
        {
        WoodListDraw(200, 320, 1, 1, 1, TX_BROWN, TX_LIGHTRED, TX_LIGHTGREEN, TX_GREEN, 0, x%2);
        WoodDraw    (650, 450, 1, 1, TX_GREEN, x%5);
        SunDraw     (120, 90, 50, 1, 1, TX_YELLOW, TX_LIGHTRED, x%10, 8, x%10) ;
        txSleep (300);
        x -= 55;
        }
    CrowDraw     (620, 400, 670, 440, 1, 1, RGB (255, 157, 60), RGB (255, 255, 255), RGB (125, 125, 255), 5);
    txEnd();
    }

void SkyDraw (int x1, int y1, int x2, int y2)
    {
    txSetFillColor (RGB (0, 230, 245));
    txSetColor     (RGB (0, 230, 245));

    txRectangle (x1, y1, x2, y2);
    }
void GrassDraw (int x1, int y1, int x2, int y2)
    {
    txSetFillColor (RGB (0, 200, 0));
    txSetColor     (RGB (0, 200, 0));

    txRectangle (x1, y1, x2, y2);
    }

void SunDraw (int x, int y, int r, double size, double sizeY, COLORREF diskColor, COLORREF luchColor,
                   double luch, double eyes, double smile)
    {
    txSetFillColor (diskColor);
    txSetColor     (luchColor,2);

    txLine (x - 100*size, y,           x + 100*size, y);
    txLine (x -  80*size, y - 60*size, x +  70*size, y +  70*size);
    txLine (x,            y - 90*size, x,            y + 100*size);
    txLine (x -  80*size, y + 70*size, x +  90*size, y -  60*size);
    txCircle (x, y, r);

    txSetFillColor (RGB (0, 0, 255));    //глаз
    txSetColor     (RGB (0, 0, 0), 1);

    txCircle (x - 20*size, y - 20*size, r/4);
    txCircle (x + 20*size, y - 20*size, r/4);

    txSetFillColor (RGB (0, 0, 0));       //зрачок
    txSetColor     (RGB (0, 0, 0), 1);

    txCircle (x - 20*size, y - 20*size, r/8);
    txCircle (x + 20*size, y - 20*size, r/8);

    txSetColor (TX_BLACK, 3);         //усы
    txLine (x - 20*size, y + (10 - smile)*sizeY, x +  5*size, y + 5*sizeY);
    txLine (x +  5*size, y + 5*sizeY,            x + 30*size, y + (10 - smile)*sizeY);

    txSetFillColor (RGB (255, 0, 0));  //рот
    txSetColor     (RGB (255, 0, 0), 2);

    txArc (x - 10*size, y + (20 - smile)*sizeY, x + 10*size, y + 10*sizeY, 180, 180);
    txArc (x - 10*size, y + (30 - smile)*sizeY, x + 10*size, y + 10*sizeY, 180, 180);
    //txArc (100, 100, 120, 150, 45, 90);
    }

void WoodListDraw (int x, int y, double sizeR, double sizeX, double sizeY, COLORREF stvolColor, COLORREF granstColor,
                COLORREF cronaColor, COLORREF grancrColor, double stvol, double leaf)
    {
    txSetColor (granstColor, 2);
    txSetFillColor (stvolColor);

    txRectangle (x, y, x + (40 + stvol)*sizeX, y + 200*sizeY);

    txSetColor (grancrColor, 2);
    txSetFillColor (cronaColor);

    txCircle (x + (20 - leaf)*sizeX,   y + 100*sizeY,          50*sizeR);
    txCircle (x + (10 - leaf)*sizeX,   y + leaf,               30*sizeR);
    txCircle (x - (30 + leaf*4)*sizeX, y + (100 + leaf)*sizeY, 30*sizeR);
    txCircle (x + (70 - leaf*4)*sizeX, y + (110 + leaf)*sizeY, 30*sizeR);
    txCircle (x + (50 - leaf)*sizeX,   y + 50*sizeY,           50*sizeR);
    txCircle (x - (30 + leaf)*sizeX,   y + 40*sizeY,           50*sizeR);
    txCircle (x + (20 - leaf)*sizeX,   y,                      50*sizeR);
    txCircle (x - (30 + leaf*4)*sizeX, y + leaf,               30*sizeR);

    }

void WoodDraw (int x, int y, double sizeX, double sizeY, COLORREF color, double leaf)
    {
    txSetColor (RGB (128, 100, 0));
    txSetFillColor (RGB (128, 100, 0));
    txRectangle (x - 10, y * sizeY, x , y * sizeY - 100);

    txSetColor (color);
    txSetFillColor (color);
    POINT wood[7] = {{ROUND(x - (50 - leaf)*sizeX), ROUND((y * sizeY - 50)/2)}, {ROUND(x + (0 - leaf)*sizeX), ROUND((y * sizeY - 100)/2)},
                     {ROUND(x + (50 + leaf)*sizeX), ROUND((y * sizeY - 50)/2)}, {ROUND(x + (0 - leaf)*sizeX), ROUND((y * sizeY - 50)/2)},
                     {ROUND(x - (50 - leaf)*sizeX), ROUND(y * sizeY - 50)}, {ROUND(x + (0 - leaf)*sizeX), ROUND(y * sizeY - 100)},
                     {ROUND(x + (50 + leaf)*sizeX), ROUND(y * sizeY - 50)}};
          txPolygon (wood, 7);
    }
void ChildrenDraw (int x, int y, int sizeX, int sizeY, COLORREF color,
double hand, double legs, double head, double twist)
    {
    txSetColor (color);
    txSetFillColor (color);

    POINT star[3] = {{ROUND(x - sizeX/2), ROUND(y - (0.35 + twist) * sizeY )}, {x, ROUND(y - 0.55 * sizeY)}, {ROUND(x + sizeX/2), ROUND(y - (0.35 + twist)*sizeY)}};
          txPolygon (star, 3);

    txLine (x, y - (0.35 + twist)*sizeY, x,                        y - 0.7*sizeY);
    txLine (x, y - (0.35 + twist)*sizeY, x - (0.2 + legs) * sizeX, y);
    txLine (x, y - (0.45 + twist)*sizeY, x + (0.5 + legs) * sizeX, y);
    txLine (x, y - 0.65*sizeY,   x - sizeX/2,   y - 0.4 * sizeY);
    txLine (x, y - 0.65*sizeY, x + sizeX/1.2, y - (0.65 + hand) * sizeY);

    txCircle (x, y - sizeY + (0.3 + head) * sizeX, 0.3 * sizeX);
    }
void CrowDraw     (int x0, int y0, int x1, int y1, int sizeX, int sizeY, COLORREF color, COLORREF wingcolor, COLORREF legcolor,
                   double twist)
    {
    txSetColor (color);
    txSetFillColor (color);

    txArc (x0, y0, x1, y1, 0, 180);
    txLine (x0, y0 + 18, x1, y0 + 18);

    POINT body[10] = {{ROUND(x1), ROUND(y0 +22)}, {ROUND(x1 + 5), ROUND(y0 + 22 + 100)}, {ROUND(x1 + 120), ROUND(y0 + 22 + 105)},
                      {ROUND(x1 +  80), ROUND(y0 + 22 + 100)}, {ROUND(x1 + 115), ROUND(y0 + 22 + 98)}, {ROUND(x1 + 85), ROUND(y0 + 22 + 95)},
                      {ROUND(x1 + 110), ROUND(y0 + 22 + 95)}, {ROUND(x1 + 120), ROUND(y0 + 22 + 93)},{ROUND(x1 + 70), ROUND(y0 + 22 + 85)},
                      {ROUND(x1 +  30), ROUND(y0 + 20)}};
          txPolygon (body, 10);

    txCircle (x1 + 10, y0 + 10, 25);

    txSetColor (wingcolor);
    txSetFillColor (wingcolor);

    POINT wing[6] = {{ROUND(x1 + 30), ROUND(y0 + 20)}, {ROUND(x1 +  35), ROUND(y0 + 20 + 80)},
                     {ROUND(x1 + 45), ROUND(y0 + 20 + 75)}, {ROUND(x1 + 50), ROUND(y0 + 20 + 80)},
                     {ROUND(x1 + 55), ROUND(y0 + 20 + 74)}, {ROUND(x1 + 70), ROUND(y0 + 22 + 83)}
                    };
          txPolygon (wing, 6);

    txSetColor (legcolor);
    txSetFillColor (legcolor);

    POINT legl[3] = {{ROUND(x1 + 20), ROUND(y0 + 22 + 100)}, {ROUND(x1 + 23), ROUND(y0 + 22 + 130)},
                     {ROUND(x1 + 25), ROUND(y0 + 22 + 100)},
                    };
          txPolygon (legl, 3);

    txLine (x1 + 23, y0 + 22 + 130, x1 + 23 - 5, y0 + 22 + 130 + 5);
    txLine (x1 + 23, y0 + 22 + 130, x1 + 23,     y0 + 22 + 130 + 5);
    txLine (x1 + 23, y0 + 22 + 130, x1 + 23 + 5, y0 + 22 + 130 + 5);

    POINT legr[3] = {{ROUND(x1 + 40), ROUND(y0 + 22 + 100)}, {ROUND(x1 + 43), ROUND(y0 + 20 + 130)},
                     {ROUND(x1 + 45), ROUND(y0 + 22 + 100)}
                    };
          txPolygon (legr, 3);

    txLine (x1 + 43, y0 + 22 + 130, x1 + 43 - 5, y0 + 22 + 130 + 5);
    txLine (x1 + 43, y0 + 22 + 130, x1 + 43,     y0 + 22 + 130 + 5);
    txLine (x1 + 43, y0 + 22 + 130, x1 + 43 + 5, y0 + 22 + 130 + 5);

    txCircle (x1 + 10, y0 + 5, 15);

    txSetFillColor (TX_BLACK);
    txCircle (x1 + 5, y0 + 5, 5);
    }
