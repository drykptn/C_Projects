/*
* In this part you will write a function that plots the graph of a given function
* int fTheFunction(int x, int functionNumber). f is a hidden function that takes an integer and
* returns an integer. There are 5 such functions that your function is going to be tested with.
* Your function should plot x and y axis lines also.
* First function is f(x)=2*x and its graph is in the sample output below.
*/
#include <stdio.h>
#include <math.h>

void drawFunction(int xAxis,int yAxis,int functionNumber);
int fTheFunction(int x, int functionNumber);

int main(int argc, char const *argv[])
{
	drawFunction(40,40,1);
	return 0;
}

void drawFunction(int xAxis,int yAxis,int functionNumber){
	int i;        /* for loop   */
	int j;        /* for loop   */
	int row;      /* for x axis */
	int col;      /* for y axis */   
        int k;        /* for loop   */       
        double m;     /* for loop   */ 
        double n;     /* for loop   */ 

        row = 50;
	//col = fTheFunction(xAxis, functionNumber);
	col = 30;
        int num = col/row;

        /* if x and y equals each other */
	if ( row == col ){
                /* until y axis */
		for ( i = 0; i < yAxis; i++)
		{
                    /* draw "|" for y axis */
                    for (k = 0; k < 1; ++k)
                           printf("|");
                    /* for space */
		    for ( j = yAxis ; j > i; j-- )
		        printf(" "); 
                    
                    printf("*");      	
		    printf("\n"); 
	  	}
		printf("|");
	  	/* draw "-" for x axis */
                for (i=0; i<xAxis; i++)
                    printf("-");
	  	
	}
        /* if y is greater than x */
	else if( col > row ){
                 /* until y axis */
		for ( i = 0; i < yAxis; i++)
		{
                    /* draw "|" for y axis */
                    for (k = 0; k < 1; ++k)
                            printf("|");
                    /* sapce decrease till gradient */
		    for ( j = yAxis ; j > i; j-= (double)col/(double)row )
		        printf(" ");    
                    /* for regular graph */
                    if( i%num == 0 )            
                        printf("*");      	
                    printf("\n"); 
                }
                printf("|");
                /* draw "-" for x axis */
 		for (i=0; i<xAxis; i++)
                    printf("-");
        }
        /* if x is greater than y */
	else{
             /* until y axis */
            for ( m = 0; m < yAxis; m++)
            { 
                 /* draw "|" for y axis */
                for (k = 0; k < 1; ++k)
                        printf("|");
                /* space decrease till gradient */
                for ( n =  yAxis ; n > m; n -= (double)col/(double)row )
                    printf(" "); 
                /* for regular graph */
                if( yAxis - m  < m )
                    printf("*");  
                printf("\n"); 
            } 
             /* draw "-" for x axis */
            for (m = 0; m < xAxis; m++)
                 printf("-");	
	}
}
