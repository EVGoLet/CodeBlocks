//{===========================================================================
//! @file       GlazkovaElena_dz_5.cpp
//!
//! @brief      Пример мультфильма
//!
//!             проба пера с использованием (TX Library, TXLib, CodeBlocks).
//!
//!             $Date: 2021-04-14$
//!             $Copyright: (C) EVGoLet/CodeBlocks (Elena Glazkova) <oleterterra@gmail.com> $
//}===========================================================================
#include "TXLib.h"

void SkyDraw    (int x1, int y1, int x2, int y2);
void GrassDraw  (int x1, int y1, int x2, int y2);
void SunDraw    (int x,  int y,  int r,  double size);

int main ()
    {
    txCreateWindow (800, 600);

    SkyDraw     (0, 0, 800, 440);
    GrassDraw   (0, 440, 800, 600);
    SunDraw     (120, 90, 50, 1) ;
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
    SunDraw (620, 60, 20, 0.5) ;
    SunDraw (420, 260, 10, 0.3) ;

    return 0;
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

