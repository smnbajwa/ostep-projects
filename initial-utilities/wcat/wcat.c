/**
 * Author: Saman Bajwa
 * March 2024
*/

include <stdio.h>

#define MAX_STRING_LENGTH 80

int main(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        FILE *fp = fopen(argv[i], "r");

        if (fp == NULL)
        {
            printf("wcat: cannot open file\n");
            return 1;
        }

        char s[MAX_STRING_LENGTH];

        while (fgets(s, MAX_STRING_LENGTH, fp) != NULL)
        {
            printf("%s", s);
        }
        
        fclose(fp);
    }

    return 0;
}