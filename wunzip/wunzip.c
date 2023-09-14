//
// Created by kareem on 11/4/22.
//

#include <stdio.h>
#include <stdlib.h>

int main (int argc ,char *argv[])
{
    if (argc < 2) {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }
    int i = 1 ;

    while (i < argc)
    {
        FILE *fptr;
        fptr = fopen(argv[i], "r");
        if (fptr == NULL) {
            printf("file not found\n");
            exit(1);

        }
        char c = 48;
        int n = 0;
        while (!feof(fptr))
        {
            //printf("here");
            fread(&n, sizeof(int), 1, fptr);
            fread(&c, 1, 1, fptr);

            if(feof(fptr)) break;
            for (int ii = 0; ii < n; ++ii)
            {
                printf("%c", c);
            }
        }
        i++;
    }



}