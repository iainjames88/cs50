#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int encrypt_character(char character, int offset);
void encrypt_message(char *message, int offset);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Supply a non-negative argument\n");

        return 1;
    }

    int offset = atoi(argv[1]);
    printf("Enter a message: ");
    char *message = GetString();
    encrypt_message(message, offset);

    return 0;
}

int encrypt_character(char character, int offset)
{
    int n = (int) character;

    if (n >= 97 && n <= 122)
    {
        return ((n - 97 + offset) % 26) + 97;
    }
    else if (n >= 65 && n <= 90)
    {
        return ((n - 65 + offset) % 26) + 65;
    }

    return character;
}

void encrypt_message(char *message, int offset)
{
    for (int i = 0; i < strlen(message); i++)
    {
        printf("%c", encrypt_character(message[i], offset));
    }

    printf("\n");
}
