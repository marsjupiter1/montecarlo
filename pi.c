// gcc pi.c -lm
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ATTEMPTS 100000
#define DIAMETER 20000
#define RADIUS (DIAMETER/2)

static int getRandom(int low, int high)
{
    return rand() % (high + 1 - low) + low;
}

int main(int args, char **argc)
{
    int InTheCircle = 0;
    int OnTheEdge = 0;
    int OutOfCircle = 0;
    for (int i = 0; i < ATTEMPTS; i++)
    {
        int x = getRandom(0, DIAMETER);
        int y = getRandom(0, DIAMETER);
        int x1 = x - DIAMETER / 2;
        int y1 = y - DIAMETER / 2;

        // we are sticking with integer arithmetic for the simulation
        int hypotenuse = (int)sqrt((double)((x1 * x1) + (y1 * y1)));
        // printf("%d %d %d\n",x,y,hypotenuse);
        if (hypotenuse == RADIUS)
        {
            OnTheEdge++;
            InTheCircle++;
        }
        else if (hypotenuse > RADIUS)
        {
            OutOfCircle++;
        }
        else
        {
            InTheCircle++;
        }
    }
    int square_area = DIAMETER * DIAMETER;
    float pi1 =4 * (float)(InTheCircle - OnTheEdge)/(float)ATTEMPTS;
    float pi2 = 4 * (float)(InTheCircle + OnTheEdge)/(float)ATTEMPTS;
    printf("In %d, out %d edge %d pi %f %f\n", InTheCircle, OutOfCircle, OnTheEdge, pi1, pi2);
}