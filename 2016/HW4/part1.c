/*
In this part, you will build an array with some modifications with the given array as input parameter and return it on output
array parameter. We want you to write a function (addPadding) that takes an array and adds padding (additional array
elements) to left and right side of this array. Padding operation is explained below. addPadding function also takes array
size (integer), padding width (integer, number of elements that you will add both sides) and padding method (function
pointer) as argument. You must implement three different padding methods. These methods are described below:
Example:
inputArr: [5, 6, 7, 8, 9]
-Zero padding: All padding values are 0.
ouputArr: [0, 0, 0, 5, 6, 7, 8, 9, 0, 0, 0], paddingWidth: 3
-Same padding: Padding values are the value of the first element of input array (inputArr[0]) for left padding and
the value of the last element of input array (inputArr[arraySize-1]) for right padding.
ouputArr: [5, 5, 5, 5, 5, 6, 7, 8, 9, 9, 9, 9, 9], paddingWidth: 4
-Half padding: Padding values are half of the value of the first element of input array (inputArr[0]/2) for left padding
and half of the value of the last element of input array (inputArr[arraySize-1]/2) for right padding.
ouputArr: [2.5, 2.5, 5, 6, 7, 8, 9, 4.5, 4.5], paddingWidth: 2
addPadding function will only copy input array to output array and shift output array by paddingWidth. Padding values are
assigned by calling the given function in paddingMethod parameter.
Note: You can assume that output array can have at most 255 elements.
*/
#include <stdio.h>


void addPadding(double inputArr[], int inputArraySize, double outputArr[], 
                int *outputArraySize, int paddingWidth, 
                void paddingMethod(double[],int, int));
void zeroPadding(double outputArr[], int outputArraySize, int paddingWidth);
void samePadding(double outputArr[], int outputArraySize, int paddingWidth);
void halfPadding(double outputArr[], int outputArraySize, int paddingWidth);
void assignArr(double outputArr[], int outputArraySize, int paddingWidth, 
	             double firstPadding, double lastPadding);

/*
 * 
 */

int main(int argc, char** argv) {
    double inputArr[] = {5, 6, 7, 8, 9};
    double outputArr[255];
    int outputArrSize = 0;
   
    addPadding(inputArr, 5 , outputArr, &outputArrSize, 8, zeroPadding);

    for (int i = 0; i < outputArrSize; ++i)
       	printf("%lf\n", outputArr[i]);
    
    return (0);
}

void addPadding(double inputArr[], int inputArraySize, double outputArr[], 
                int *outputArraySize, int paddingWidth, 
                void paddingMethod(double[],int, int)){
	int i, j;
	/* calculate output array size */
	*outputArraySize = 2 * paddingWidth + inputArraySize;

/* padding width kadar bosluk birak ve input array ini output arrayine yaz*/
	for (i = paddingWidth, j = 0; i < inputArraySize + paddingWidth; ++i, j++)
		outputArr[i] = inputArr[j];

	/* send to padding method */
	paddingMethod(outputArr, *outputArraySize, paddingWidth);	
}

void zeroPadding(double outputArr[], int outputArraySize, int paddingWidth){
	/* send to assignArr() function */
	assignArr(outputArr, outputArraySize, paddingWidth, 0 , 0);
}

void samePadding(double outputArr[], int outputArraySize, int paddingWidth){
	/* send to assignArr() function */
	assignArr(outputArr, 
		      outputArraySize, 
		      paddingWidth, 
		      /* input array inin ilk elemani */
		      outputArr[paddingWidth] ,   
		      /* input array inin son elemani */
		      outputArr[outputArraySize - paddingWidth-1]);                   
}

void halfPadding(double outputArr[], int outputArraySize, int paddingWidth){
	/* send to assignArr() function */
	assignArr(outputArr, 
		      outputArraySize, 
		      paddingWidth, 
		      /* input array inin ilk elemaninin yarisi */
		      (double)outputArr[paddingWidth]/(double)2 ,
		      /* input array inin son elemaninin yarisi */ 
		      (double)outputArr[outputArraySize - paddingWidth - 1]/(double)2);
}

/* butun fonksiyonlarda ayni islem yapildigi icin tek bir fonksiyon a gonderdildi */
void assignArr(double outputArr[], int outputArraySize, int paddingWidth, 
	             double firstPadding, double lastPadding){
	int i;
	/* for first place */
	for (i = 0; i < paddingWidth; ++i)
		outputArr[i] = firstPadding;     /* add coming padding value */
	/* for last place */
	for (i = outputArraySize - paddingWidth; i < outputArraySize+1; ++i)
		outputArr[i] = lastPadding;      /* add coming padding value */
}
