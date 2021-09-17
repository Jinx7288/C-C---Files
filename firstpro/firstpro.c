#include<stdio.h>
typedef struct recnode *Rectangle;
typedef struct recnode
{
int x,y,h,w;
} Recnode;

Rectangle Recinit() {
    Rectangle R = (Rectangle)malloc(sizeof *R);
    R->x = 0;
    R->y = 0;
    R->w = 0;
    R->h = 0;
    return R;
}
int main() {
    Recnode rr;
    Rectangle R;
    R = &rr;
    rr.x = 1;
    rr.y = 1;
    rr.h = 12;
    rr.w = 13;
    printf("x=%d y=%d \n", R->x, R->y);
}


