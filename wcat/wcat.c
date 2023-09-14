//
// Created by kareem on 11/2/22.
//

#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 512
int main(int argc,char *argv[])
{
    int i = 1;
    while (i < argc )
    {
        FILE *fptr;
        fptr = fopen(argv[i],"r");
        if(fptr == NULL)
        {
            printf("wcat: cannot open file\n");
            exit(1);
        }
        char buffer [BUFFER_SIZE];
        while (fgets(buffer,BUFFER_SIZE,fptr) != NULL)
        {
            printf("%s", buffer);
        }

        fclose(fptr);

        i ++ ;

    }


}
