#include<stdio.h>
#include<math.h>

int main(void) {
    float po_x, po_y, height, width, x, y;

    printf("Give the x and y of the starting point ");
    scanf("%f%f", &po_x, &po_y);
    printf("Rectangle height is ");
    scanf("%f", &height);
    printf("Rectangle width is ");
    scanf("%f", &width);
    printf("Now, give the coordinate of the point in space ");
    scanf("%f%f", &x, &y);

    if ((x < po_x) || (x > (po_x + width)) || (y < po_y) || (y > (po_y + height))) 
        printf("Point is outside the rectangle");
    else {
        if ((x == po_x) || (x == (po_x + width)) || (y == po_y) || (y == (po_y + height)))
            printf("Point is over a triangle line");
        else 
            printf("Point is inside the triangle"); 
    }
    return 0;
}
