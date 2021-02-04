#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
#define SIN(x) sin(x * 3.141592653589/180)
#define COS(x) cos(x * 3.141592653589/180)

// s[][] is scaling matrix. p[][] is to store
// points that needs to be scaled.
// p[0][0] is x coordinate of point.
// p[1][0] is y coordinate of given point.
void findNewCoordinate(int s[][2], int p[][1])
{
    int temp[2][1] = { 0 };

    for (int i = 0; i < 2; i++)
for (int j = 0; j < 1; j++)
   for (int k = 0; k < 2; k++)
temp[i][j] += (s[i][k] * p[k][j]);

    p[0][0] = temp[0][0];
    p[1][0] = temp[1][0];
}

// Scaling the Polygon
void scale(int x[], int y[], int sx, int sy)
{
    // Triangle before Scaling
    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[0], y[0]);

    // Initializing the Scaling Matrix.
    int s[2][2] = { sx, 0, 0, sy };
    int p[2][1];


    // Scaling the triangle
    for (int i = 0; i < 3; i++)
    {
p[0][0] = x[i];
p[1][0] = y[i];

findNewCoordinate(s, p);

x[i] = p[0][0];
y[i] = p[1][0];
    }

    // Triangle after Scaling
    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[0], y[0]);
}

void rotate(float a[][2], int n, int x_pivot, int y_pivot,int angle){
    int i = 0;
    while (i < n)
    {
// Shifting the pivot point to the origin
// and the given points accordingly

int x_shifted = a[i][0] - x_pivot;
int y_shifted = a[i][1] - y_pivot;
// Calculating the rotated point co-ordinates
// and shifting it back
a[i][0] = x_pivot + (x_shifted*COS(angle)
 - y_shifted*SIN(angle));
a[i][1] = y_pivot + (x_shifted*SIN(angle)
 + y_shifted*COS(angle));
cout << "(" << a[i][0] << ", " << a[i][1] << ") ";
i++;
    }
    }
void translatePoint ( int P[], int T[]){
    cout<<"Original Coordinates :"<<P[0]<<","<<P[1];

    putpixel (P[0], P[1], 1);

    // calculating translated coordinates
    P[0] = P[0] + T[0];
    P[1] = P[1] + T[1];

    cout<<"\nTranslated Coordinates :"<< P[0]<<","<< P[1];

    // Draw new coordinatses
    putpixel (P[0], P[1], 3);
    }

// Driven Program
int main()
{
    int ch;
    int gd=DETECT,gm,errorcode;
    initgraph(&gd, &gm,"c:\\turboc3\\bgi");
    switch(ch){
    case 1:
    {
    int x[] = { 100, 200, 300 };
    int y[] = { 200, 100, 200 };
    int sx = 2, sy = 2;
    scale(x, y, sx, sy);
    break;
    }
    case 2:
    {
    int size1 = 4;//No. of vertices
    float points_list1[][2] = {{100, 100}, {150, 200},
{200, 200}, {200, 150}};
    rotate(points_list1, size1, 0, 0, 90);
    break;
    }
    case 3:
    {
    int P[2] = {5, 8}; // coordinates of point
    int T[] = {2, 1}; // translation factor
    translatePoint ( P, T);
    break;
    }
    case 4:
    {
float shx,shy;
char ch;
int x1=50,y1=100,x2=100,y2=200;
rectangle(x1,y1,x2,y2);
delay(10);
cout<<"enter the direction of shear : ";
cin>>ch;
if(ch=='x')
{
cout<<"enter x-direction of shear : ";
cin>>shx;
y1=y1+shx*x1;
y2=y2+shx*x2;
setcolor(RED);
rectangle(x1,y1,x2,y2);
}
else
{
cout<<"enter y-direction of shear : ";
cin>>shy;
x1=x1+shy*y1;
x2=x2+shy*y2;
setcolor(RED);
rectangle(x1,y1,x2,y2);
}

    break;
    }
    default:
    {
    cout<<"Invalid Choice!!";
    }
}
    getch();
    closegraph();
    return 0;
}

