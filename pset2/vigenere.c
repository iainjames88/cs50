#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


int encrypt_character(char character, int offset);
void encrypt_message(char *message, char *keyword);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Supply an alpha argument!\n");

        return 1;
    }

    char *keyword = argv[1];
    int length_of_keyword = strlen(keyword);

    for (int i = 0; i < length_of_keyword; i++)
    {
        if (isalpha(keyword[i]) == 0)
        {
            printf("Supply an alpha argument! \n");

            return 1;
        }
    }

    printf("Enter a message: ");
    char *message = GetString();
    encrypt_message(message, keyword);

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

void encrypt_message(char *message, char *keyword)
{
    int length_of_message = strlen(message);
    int length_of_keyword = strlen(keyword);
    int pos = 0;

    for (int i = 0; i < length_of_message; i++)
    {
        if (pos == length_of_keyword)
        {
            pos = 0;
        }

        if ((message[i] >= 97 && message[i] <= 122) || (message[i] >= 65 && message[i] <= 90))
        {
            int offset = (int) keyword[pos];
            if (offset >= 97 && offset <= 122)
            {
                printf("%c", encrypt_character(message[i], offset - 97));
            }
            else
            {
                printf("%c", encrypt_character(message[i], offset - 65));
            }
            pos++;
        }
        else
        {
            printf("%c", message[i]);
        }
    }

    printf("\n");
}
