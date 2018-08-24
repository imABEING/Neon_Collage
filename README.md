# Neon Collage

My programming approach has always been to been to use the right tools to create a great finished product. I've always found simplicity to be more difficult to achieve, especially in a creative role, and so I have always strived towards it. My goal with this assignment has been to generate an a Pixku image that pleasures the human eye with a balance between structure and chaos, creativity and technicality, simplicity and complexity.

This image was generated using [Pixku](https://github.com/MuvikLabs/Pixku) and [Runt](https://github.com/MuvikLabs/runt), by [MuvikLabs](https://github.com/MuvikLabs).


![alt text](https://github.com/imABEING/Neon_Collage_2/blob/master/NeonCollage.png)


## Creative Process
First, I experimented with the code in testimage.c. After recognizing that the base of the image used a simple rectangle, I altered the code to an 8x8 cell square grid. From there, I randomized the order of colors in each square to add some excitement to the grid. Wanting to include more shapes, I wrote a function to generate an inverted traingle, and used this shape as the base of the image. I used black as the base color of the image, using it to fill in the other half of each square cell, effectively making another triangle pattern to compliment the random colored ones. I then focused on changing the default color scheme to a set of neon colors, replacing the stock purple (1), orange(3), green(5), and blue(7) colors with more eye-popping RGB codes. I then adjusted the height and width of the square function to add a small square in the top left corner of each grid cell, and randomized the color to make a computer art collage.



## Technical Methods
I focused on using the most I could out of Pixku by making use of all three special words, and using C coding proficiency. Using pxclr, I made the following changes:
color 1 to RGB "153 0 153" (neon purple)
color 3 to RGB "255 128 0" (neon orange)
color 5 to RGB "0 225 0" (neon green)
and color 7 to RGB "0 255 255" (neon blue)

I imported <stdlib.h> to make use of the rand() function for randomizing the order of colors, using the formula "c  = rand() % (MAX_NUM + 1 - MIN_NUM) + MIN_NUM;", defining MAX_NUM as 7 and MIN_NUM as 0 to create a range of 8, for the 8 color palette. The random value is re-initialized between the traingle and square functions to avoid repeating colors. 

To generate the triangle function, I used nested for loops. The first counts the width using the formula "for(i=0; i<h; i++)", h being the input variable for width. The second loop generates the height using "for(j=0; j<=i; j++)", increasing the height by the width "h". Lastly, the code is printed into the Runt program using the line "fprintf(fp, "%d %d %d pxpt\n", i + xpos, j + ypos, c);", where the width and height are added to the input x position and y positions over the course of the loop, respectively.

Two nested for loops in the main() function create an 8x8 grid for both the trangle and square functions by increasing the width and height of the from 1 to 8, to be multplied by 32 in the functions xpos and ypos arguements, making a 256x256 pixel image.

