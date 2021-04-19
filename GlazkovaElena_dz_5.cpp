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
void StarDraw   (int x, int y, double size, COLORREF starColor);

void SkyDraw    (int x1, int y1, int x2, int y2);
void GrassDraw  (int x1, int y1, int x2, int y2);
void SunDraw    (int x,  int y,  int r,  double size);
void CrowDraw   (double x0, double y0, double x1, double y1, double startAngle, double totalAngle, int sizeX, int sizeY, COLORREF color,
double hand, double legs, double head, double twist);
int main ()
    {
    txCreateWindow (800, 600);

    StartTitles();

  //  SkyDraw     (0, 0, 800, 440);
  //  GrassDraw   (0, 440, 800, 600);
 //   SunDraw     (120, 90, 50, 1) ;

 //   CrowDraw    (
//    ChildrenDraw (500, 450, 50, 100, TX_RED, 0, 0, 0, 0);
//    WoodDraw (650, 450, 1, TX_GREEN);
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

    POINT star[8] = {{x, y - 90*size}, {x + 30*size, y - 30*size}, {x + 90*size, y},
                    {x + 30*size, y + 30*size}, {x, y + 90*size}, {x - 30*size, y + 30*size},
                    {x - 90*size, y},{x - 30*size, y - 30*size} };
          txPolygon (star, 8);

/*         txLine (x,           y - 90*size, x + 30*size, y - 30*size);
 *         txLine (x + 30*size, y - 30*size, x + 90*size, y);
 *         txLine (x + 90*size, y,           x + 30*size, y + 30*size);
 *         txLine (x + 30*size, y + 30*size, x,           y + 90*size);
 *         txLine (x,           y + 90*size, x - 30*size, y + 30*size);
 *         txLine (x - 30*size, y + 30*size, x - 90*size, y);
 *         txLine (x - 90*size, y,           x - 30*size, y - 30*size);
 *         txLine (x - 30*size, y - 30*size, x,           y - 90*size);
 */

  //      }
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
        StarDraw    (rand()%(300-250+1) + 250 + i*100, rand()%(250-10+1) + 10 + i*10, 0.125*(rand()%(4-1)+1), TX_YELLOW);
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

void SunDraw (int x, int y, int r, double size)
    {
    txSetFillColor (RGB (255, 255, 0));
    txSetColor     (RGB (255, 255, 0), 5);

    txCircle (x, y, r);
    txLine (x - 100*size, y,           x + 100*size, y);
    txLine (x -  80*size, y - 60*size, x +  70*size, y +  70*size);
    txLine (x,            y - 90*size, x,            y + 100*size);
    txLine (x -  80*size, y + 70*size, x +  90*size, y -  60*size);

    txSetFillColor (RGB (0, 0, 255));
    txSetColor     (RGB (0, 0, 0), 1);

    txCircle (x - 20*size, y - 20*size, r/4);
    txCircle (x + 20*size, y - 20*size, r/4);

    txSetFillColor (RGB (0, 0, 0));
    txSetColor     (RGB (0, 0, 0), 1);

    txCircle (x - 20*size, y - 20*size, r/8);
    txCircle (x + 20*size, y - 20*size, r/8);

    }

//{void CrowDraw   (double x0, double y0, double x1, double y1, double startAngle, double totalAngle, int sizeX, int sizeY, COLORREF color,
//double hand, double legs, double head, double twist)
  //  {
    //txSetFillColor (RGB (0, 0, 0));
    //txSetColor     (RGB (0, 0, 0));

    //txArc (500, 100, 550, 150, 180, 180);

    //}
//}
