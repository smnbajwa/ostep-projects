/**
 * Author: Saman Bajwa
 * March 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool substring_in_string(char *string, char* substring);
void search_and_print(FILE *fp, char *substring);

int main(int argc, char **argv)
{
    switch (argc)
    {
        case 1:
            printf("wgrep: searchterm [file ...]\n");
            return 1;

        case 2:
            search_and_print(stdin, argv[1]);
            break;

        default:
            for (int i = 2; i < argc; i++)
            {
                FILE *fp = fopen(argv[i], "r");

                if (fp == NULL)
                {
                    printf("wgrep: cannot open file\n");
                    return 1;
                }

                search_and_print(fp, argv[1]);

                fclose(fp);
            }
            break;
    }

    return 0;
}

void search_and_print(FILE *fp, char *substring)
{
    char *buf = NULL;
    size_t size = 0;

    while (getline(&buf, &size, fp) > 0)
    {
        if (substring_in_string(buf, substring))
            printf("%s", buf);
    }

    free(buf);
}

bool substring_in_string(char *string, char* substring)
{
    for (int i = 0; string[i] != 0; i++)
    {
        int k = i;

        for (int j = 0;; j++)
        {
            if (substring[j] == 0)
                return true;

            if (substring[j] != string[k])
                break;
            else
                k++;
        }
    }

    return false;
}
