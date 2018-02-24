/*
In this part you will write a function to draw a simple car that contains two stacked
rectangles and two circles as wheels.

Write a function that draws rectangle.

Write a function that draws two circles near each other.

Write a function to draw a car using two functions above.
*/

#include <stdio.h>
#include <math.h>

void drawRectangle(int width,int height, int startingPoint, int printLastLine);
void drawDoubleCircle(int radius, int startingPoint , int whellDistance);
void drawCar();

int main(int argc, char const *argv[])
{

	drawCar();
 	return 0;
}
void drawCar(){
	drawRectangle (40, 10, 11, 0);
	drawRectangle (60, 10, 1, 1);
	drawDoubleCircle(4, 7 ,28);
}

/* Dikdortgen cizen fonksiyon   */
void drawRectangle(int width,int height, int startingPoint, int printLastLine){
	int i;          /* for loop */
	int j;          /* for loop */
	int space;      /* for starting point */
	/* Dikdortgenin uzunlugu */
	for (i = 1; i <= height; ++i)
	{	
		/* starting point icin birakilan bosluk dongusu */
		for (space = 1; space < startingPoint; ++space)
			printf(" ");
		/* Dikdortgenin genisligi */
		for (j= 1; j <= width; ++j)
		{
			/* Eger ilk satirda da ise yukseklik kadar * basacak */
			if (i == 1 )
				printf("*");
			else{
			/* Eger ilk satirda da ise yukseklik kadar * basacak */
				if(j == 1 || j == width)
					printf("*");	
				else
					printf(" ");
			}
		}
		printf("\n");
	}
	/* Eger user 0 girerse son line basilmayacak */
	if( printLastLine == 0 ){
		for (i = 1; i < printLastLine; ++i){
			for (j = 0; i < startingPoint; ++i)
				printf(" ");
			printf("*");
		}	
	}
	/* Eger user 1 girerse son line dikdortgen genisliginde basilacak */
	else if( printLastLine == 1 ){
		for (i = 1; i < width + startingPoint; ++i){
			for (j = 0; i < startingPoint; ++i)
				printf(" ");
			printf("*");
		}
		printf("\n");
	}
}
void drawDoubleCircle(int radius, int startingPoint , int whellDistance){
	int i;					/* for loop */
	int j; 					/* for loop */
	int space;				/* for starting point */
	double distance;		/* for whellDistance */
    
    for (i = 0; i <= 2 * radius; i++)
    {
    	/* starting point kadar bosluk sayisi birak */
    	for (space = 0; space < startingPoint; ++space)
        		printf(" ");
        for (j = 0; j <= 2 * radius; j++)
        {
        	/* yatay ve dikeyde cap kadar aralik bul */
            distance = sqrt((double)(i - radius) * (i - radius) + (j - radius) * (j - radius));
            /* Satirlar arasi duzen icin 0.5 farkla * print et */
            if (distance < radius + 0.5)     
                printf("*");
            /* Dısında kalan kisim icin bosluk bas */
            else
            	printf(" ");
        }
        /* whell distance kadar bosluk sayisi birak */
        for (space = 0; space < whellDistance; ++space)
      		printf(" ");

      	/* Onceki circle algortiması */
        for (j = 0; j <= 2 * radius; j++)
        {
            distance = sqrt((double)(i - radius) * (i - radius) + (j - radius) * (j - radius));
            if (distance < radius + 0.5)
               	printf("*");
            else
            	printf(" ");
        }
        printf("\n");
    }

}
