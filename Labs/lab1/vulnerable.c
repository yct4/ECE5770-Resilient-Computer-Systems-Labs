/* vulnerable.c */

/* This program has a buffer overflow vulnerability. */
/* Our task is to exploit this vulnerability */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int bof(char *str)
{
    char buffer[12];

    /* The following statement has a buffer overflow problem */ 
    strcpy(buffer, str);

    return 1;
}

int main(int argc, char **argv)
{
    char str[512];
    FILE *badfile;

    badfile = fopen("badfile", "r");
    fread(str, sizeof(char), sizeof(str), badfile);
    bof(str);

    printf("Returned Properly\n");
    return 0;
}
