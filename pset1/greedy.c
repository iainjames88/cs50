#include <cs50.h>
#include <stdio.h>


const int QUARTER = 25;
const int DIME = 10;
const int NICKEL = 5;
const int PENNY = 1;

float get_change();
int get_coins(float change);

int main(void)
{
    float change = get_change();
    printf("change to be given is %.2f\n", change);

    int n = get_coins(change);
    printf("minimum number of coins is %d\n", n);

    return 0;
}

float get_change()
{
    float n;

    do {
        printf("Oh hai! How much change is owed?: ");
        n = GetFloat();
    } while(n <= 0);

    return n;
}

int get_coins(float change)
{
    int n = (int) (change *= 100);
    int count = 0;

    while (n > 0)
    {
        if (n >= QUARTER)
        {
            n -= QUARTER;
            count++;
        }
        else if (n >= DIME)
        {
            n -= DIME;
            count++;
        }
        else if (n >= NICKEL)
        {
            n -= NICKEL;
            count++;
        }
        else
        {
            n -= PENNY;
            count++;
        }
    }

    return count;
}
