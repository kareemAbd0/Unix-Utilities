//
// Created by kareem on 11/4/22.
//
//

#include <stdio.h>
#include <stdlib.h>

int main (int argc ,char *argv[])
{
    if (argc < 2) {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    FILE *fptrw;
    fptrw = fopen("temp.txt","w");
    int i=1;
    while (i < argc) {

        FILE *fptrt;
        fptrt = fopen(argv[i], "r");
        while (!feof(fptrt)) {

            char c = (char) fgetc(fptrt);
            if (feof(fptrt)) break;
            fprintf(fptrw,"%c",c);
        }
        fclose(fptrt);
        i++;
    }

    fclose(fptrw);


    FILE *fptr;
    fptr = fopen("temp.txt", "r");
    if (fptr == NULL) {
        printf("file not found\n");
        exit(1);

    }
    int flag = 0;
    while (!feof(fptr)) {
        char c = (char) fgetc(fptr);

        int count = 1;

        if (c == '\n') {
            while (fgetc(fptr) == '\n') count ++;
            if (feof(fptr))
            {
                //printf("%d",count);
                fwrite(&count, sizeof(int), 1, stdout);
                fwrite(&c, sizeof(char), 1, stdout);

                break;
            }
            fseek(fptr, -1, SEEK_CUR);
            fwrite(&count, sizeof(int), 1, stdout);
            fwrite(&c, sizeof(char), 1, stdout);
            flag = 1;

            continue;
        }

        while ((char) fgetc(fptr) == c && (!feof(fptr))) {


            count++;
        }
        if (feof(fptr) && flag == 1) break;
       fwrite(&count, sizeof(int), 1, stdout);
       fwrite(&c, sizeof(char), 1, stdout);
       if (feof(fptr)) break;

        fseek(fptr, -1, SEEK_CUR);
        flag = 0;
    }
    remove("temp.txt");




}