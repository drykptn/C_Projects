/*
In the second part, you will make a convolution operation over a given array. This operation has two components: First
component is an input array and second component is a kernel array. The relationship between these two components are
shown in figure 1. Kernel array moves on the input array in each iteration and calculates one array element for the output
array.
one element = K 1 ∗ A i + K 2 ∗ A i+1 + ⋯ + K j ∗ A i+j−1
If you look at the output array in the figure 1, you can see that the size of the array shrinks after convolution operation. To
prevent that, you will add some padding to the inputArray and get an output array with the same size. You can use the
function that you wrote in the part 1 for the padding operation.
Another parameter, stride that effects the step for the convolution operation. Stride is the amount of kernel movement for
each iteration. Stride is 1 for the figure 1. If stride is 2, then you will move the kernel not one element, but 2 elements for
one iteration. If there is no error return 0, otherwise return -1.
PaddingType parameter is an enum type. Definition of that type is given below.
Error condition:
-kernelSize > inputArrSize return -1;
*/
#include <stdio.h>


typedef enum _paddingType { ZERO, HALF, SAME} PaddingType;


/*-------------------------------PART 1--------------------------------------*/
void addPadding(double inputArr[], int inputArraySize, double outputArr[], 
                int *outputArraySize, int paddingWidth, 
                void paddingMethod(double[],int, int));
void zeroPadding(double outputArr[], int outputArraySize, int paddingWidth);
void samePadding(double outputArr[], int outputArraySize, int paddingWidth);
void halfPadding(double outputArr[], int outputArraySize, int paddingWidth);
void assignArr(double outputArr[], int outputArraySize, int paddingWidth, 
	             double firstPadding, double lastPadding);
/*---------------------------------------------------------------------------*/


int convolution(double inputArr[], int inputArraySize, double kernelArr[], 
	            int kernelArraySize, double outputArr[], int *outputArraySize, 
	            int stride, PaddingType padding);

int main(int argc, char const *argv[])
{
	double inputArr[] = {3, 5, 7, 9, 11, 13, 15};
	double kernelArr[] =  {-1, 2, 0.5, 4, 1.7};
	double outputArr[255];
	int outputArrSize = 0;
	int i;
	convolution(inputArr, 7, kernelArr, 5, outputArr, &outputArrSize, 2, SAME);

	for ( i = 0; i < outputArrSize; ++i)
	{
		printf("%.2lf\n", outputArr[i]);
	}

	return 0;
}

int convolution(double inputArr[], int inputArraySize, double kernelArr[], 
	            int kernelArraySize, double outputArr[], int *outputArraySize, 
	            int stride, PaddingType padding)
{
	int paddingWidth;                 /* for padding width    */
	double temp[255];                 /* temp array for input */  
	int tempSize;                     /* size of temp array   */
	int i;                            /* for loop             */
	int j;							  /* for loop             */	

    /* error check   */
	if( kernelArraySize > inputArraySize )
		return -1;
	if( kernelArraySize < 0 )
		return -1;

	/* find padding with formula  */
	paddingWidth = (kernelArraySize - 1) / 2;
	
	/* find size of output array with formula */
	*outputArraySize = (inputArraySize - kernelArraySize + 2 * paddingWidth) / 
	                   stride +1;
	
	/* error check */
    if( paddingWidth < 0 )
		return -1;
	if( *outputArraySize < 0 )
		return -1;
		
	/* send to padding method */
	if( padding == ZERO)
		addPadding(inputArr, inputArraySize, temp, &tempSize, paddingWidth, zeroPadding);
	else if( padding == SAME)
		addPadding(inputArr, inputArraySize, temp, &tempSize, paddingWidth, samePadding);
	else if( padding == HALF)
		addPadding(inputArr, inputArraySize, temp, &tempSize, paddingWidth, halfPadding);
	else
		return -1;

	/* until size of output array */
	for (j = 0; j < *outputArraySize; ++j)
	{
		/* until size of kernel array */
		for ( i = 0; i < kernelArraySize; ++i)
			/* kernel array and temp array multiply and add output array */
			outputArr[j] += temp[i + j * stride] * kernelArr[i];
	}
	return 0;
}


/*-------------------------------PART 1--------------------------------------*/

void assignArr(double outputArr[], int outputArraySize, int paddingWidth, 
	             double firstPadding, double lastPadding);


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
