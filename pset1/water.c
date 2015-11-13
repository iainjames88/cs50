#include <cs50.h>
#include <stdio.h>


int get_minutes();
void print_water_usage(int minutes);

int main(void)
{
    int minutes = get_minutes();
    print_water_usage(minutes);

    return 0;
}

int get_minutes()
{
    int n;

    do {
        printf("minutes: ");
        n = GetInt();
    } while(n < 0);

    return n;
}

void print_water_usage(int minutes)
{
    int water_usage = (minutes * 192) / 16;
    printf("bottles: %d\n", water_usage);
}
