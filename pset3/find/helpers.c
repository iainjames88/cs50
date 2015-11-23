/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"


bool linear_search(int value, int values[], int n)
{
    if (n < 0)
    {
        return false;
    }

    for (int i = 0; i < n; i++)
    {
        if (values[i] == value)
        {
            return true;
        }
    }

    return false;
}

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    return linear_search(value, values, n);
}

void bubble_sort(int values[], int n)
{
    bool swap = false;

    for (int i = 0; i < n - 1; i++)
    {
        if (values[i] > values[i+1])
        {
            swap = true;
            int t = values[i];
            values[i] = values[i+1];
            values[i+1] = t;
        }
    }
    if (swap == true)
    {
        sort(values, n);
    }

    return;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    bubble_sort(values, n);

    return;
}
