#include "TXLib.h"

int main ()
    {
    txCreateWindow (800, 600);

    txSetFillColor (RGB (0, 230, 245));
    txSetColor (RGB (0, 230, 245));

//txArc (double x0, double y0, double x1, double y1, double startAngle, double totalAngle, HDC dc=txDC())
txArc (100, 100, 120, 150, 45, 90);
txArc (200, 100, 250, 150, 45, 90);
txArc (300, 100, 350, 150, -90, 180);//270,180
txArc (400, 100, 450, 150, 90, 180);
txArc (500, 100, 550, 150, 180, 180);
txArc (600, 100, 650, 150, -90, 90);
txArc (700, 100, 750, 150, 180, 90);
txArc (500, 200, 550, 250, 90, 90);
txArc (400, 200, 450, 250, 0, 90);
txArc (300, 200, 350, 250, 0, 180);
 	return 0;
 	}
