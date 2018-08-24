#include <stdio.h>
#include <stdlib.h>
#include <math.h>



#define MAX_NUM 7
#define MIN_NUM 0

void triangle(FILE *fp, int xpos, int ypos, int w, int h, int c)
{
    int i, j;
    
    fprintf(fp, "1 153 0 153 pxclr\n");
    fprintf(fp, "3 255 128 0 pxclr\n");
    fprintf(fp, "7 0 255 255 pxclr\n");
    
    for(i=0; i<h; i++) //row
    {
        for(j=0; j<=i; j++) //column
        {
            fprintf(fp, "%d %d %d pxpt\n", i + xpos, j + ypos, c);
        }
    }
    
}

void square(FILE *fp, int xpos, int ypos, int w, int h, int c)
{
    int x, y;
    
    fprintf(fp, "5 0 225 0 pxclr\n");
    
    for(y = 0; y < h; y++) {
        for(x = 0; x < w; x++) {
            fprintf(fp, "%d %d %d pxpt\n", x + xpos, y + ypos, c);
        }
    }
}


int main(int argc, char *argv[])
{
    FILE *fp;
    int x, y, z, c;
    
    fp = fopen("run.rnt", "w");
    fprintf(fp, "# generated image using NeonCollage program\n");

    for(x = 0; x < 8; x++) 
    {
        for(y = 0; y < 8; y++) 
        {
            c  = rand() % (MAX_NUM + 1 - MIN_NUM) + MIN_NUM;   
            triangle(fp, x * 32, y * 32, 32, 32, c);
            c  = rand() % (MAX_NUM + 1 - MIN_NUM) + MIN_NUM;
            square(fp, x * 32, y * 32, 6, 6, c);         
        }
    }  
    
    fprintf(fp, "\"NeonCollage.png\" pxsave\n");
    fclose(fp);
    return 0;
}
