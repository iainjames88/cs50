#include <cs50.h>
#include <stdio.h>


int get_pyramid_height();
void print_half_pyramid(int height);

int main(void)
{
    int pyramid_height = get_pyramid_height();
    print_half_pyramid(pyramid_height);

    return 0;
}

int get_pyramid_height()
{
    int n;

    do {
        printf("Height: ");
        n = GetInt();
    } while(n <= 0);

    return n;
}

void print_half_pyramid(int height)
{
    int width = height + 1;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j < width - (i + 2))
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
