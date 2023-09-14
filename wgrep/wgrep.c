//
// Created by kareem on 11/2/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char *argv[]) {

    if (argc == 1) {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);

    }

    FILE *fptr;
    int i = 2;
    if (argc != 2) {
        while (i < argc) {
            fptr = fopen(argv[i], "r");
            if (fptr == NULL) {
                printf("wgrep: cannot open file\n");
                exit(1);
            }
            int size_of_grep = 0;

            while (argv[1][size_of_grep] != '\0') {
                size_of_grep++;
            }

            char buffer1[size_of_grep + 1];

            char *buffer2 = NULL;
            size_t n = 10;
            int itr = 0;
            int flag = 0;
            while (getline(&buffer2, &n, fptr) != -1) {


                while (1) {
                    flag = 0;
                    int tmp = itr;

                    for (int j = 0; j < size_of_grep; ++j) {

                        buffer1[j] = buffer2[itr];
                        if (buffer2[itr] == '\n') {
                            flag = 1;
                            break;
                        }
                        itr++;
                    }
                    itr = tmp + 1;

                    //buffer1[size_of_grep + 1] = '\0';
                    // printf("%s\n", buffer1);

                   // buffer1[size_of_grep] = '\0';

                    if (strcmp(buffer1, argv[1]) == 0) {
                        printf("%s", buffer2);
                        flag = 1;
                    }
                    memset(buffer1, 0, size_of_grep + 1);
                    if (flag == 1) break;

                }
                itr = 0;

            }
            i++;
        }
    } else
    {
        FILE *in = stdin;

        if (in == NULL) {
            printf("wgrep: cannot open file\n");
            exit(1);
        }
        int size_of_grep = 0;

        while (argv[1][size_of_grep] != '\0') {
            size_of_grep++;
        }

        char buffer1[size_of_grep + 1];

        char *buffer2 = NULL;
        size_t n = 100;
        int itr = 0;
        int flag = 0;

        while (getline(&buffer2, &n, in) != -1) {


            while (1) {
                flag = 0;
                int tmp = itr;

                for (int j = 0; j < size_of_grep; ++j) {

                    buffer1[j] = buffer2[itr];
                    if (buffer2[itr] == '\n') {
                        flag = 1;
                        break;
                    }
                    itr++;

                }
                itr = tmp + 1;

                //buffer1[size_of_grep + 1] = '\0';
                // printf("%s\n", buffer1);

                //buffer1[size_of_grep] = '\0';

                if (strcmp(buffer1, argv[1]) == 0) {
                    printf("%s", buffer2);
                    flag = 1;
                }
                memset(buffer1, 0, size_of_grep + 1);
                if (flag == 1) break;

            }
            itr = 0;

        }
        free(buffer2);
        i++;




    }







}