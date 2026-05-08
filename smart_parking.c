#include <reg51.h>

// IR Sensors
sbit IR1 = P1^0;
sbit IR2 = P1^1;

// LEDs for Slot 1
sbit RED1 = P2^0;
sbit GREEN1 = P2^1;

// LEDs for Slot 2
sbit RED2 = P2^2;
sbit GREEN2 = P2^3;

void delay(unsigned int time)
{
    unsigned int i, j;

    for(i = 0; i < time; i++)
        for(j = 0; j < 1275; j++);
}

void main()
{
    while(1)
    {
        // Parking Slot 1
        if(IR1 == 1)
        {
            GREEN1 = 1;
            RED1 = 0;
        }
        else
        {
            GREEN1 = 0;
            RED1 = 1;
        }

        // Parking Slot 2
        if(IR2 == 1)
        {
            GREEN2 = 1;
            RED2 = 0;
        }
        else
        {
            GREEN2 = 0;
            RED2 = 1;
        }

        delay(100);
    }
}