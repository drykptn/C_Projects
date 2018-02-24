/*----------------------------------------------------------------------------*/
/*
In this part of the homework, you will use Taylor series to calculate sine and cosine.
The user will enter an integer as degree and another integer that defines the first n elements of
the series. You are not allowed to use math library functions for calculations, that is you
must write your own functions with the same input/output format of the math library
function. In addition, use the following function signatures to make your program modular:
The function named getInputs will wait for user to enter the degree and n value. If ‘E’ is
entered instead, the exit variable will be 1, otherwise
*/
/*                                                                            */
/* HW04_141044025_Derya_Kaptan			                              */
/*						                              */
/* ---------------------------------------------------------------------------*/
/* Created on 24/03/2016 by Derya_Kaptan	                       	      */
/* 						                              */
/*			               			                      */
/*----------------------------------------------------------------------------*/
/*                            Includes 				    	      */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
/*----------------------------------------------------------------------------*/
/*                              DEFINES                                       */
/*----------------------------------------------------------------------------*/
#define PI 3.14
#define TRUE 1
/*----------------------------------------------------------------------------*/
/*                           Function Prototypes   			      */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*					      			              */ 
/*Girilen degerin ustunu almak icin fonksiyon                                 */
double pw( double a, int k );

/*Girilen degerin faktoriyelini almak icin fonksiyon                          */
double fac( int j );

/*Taylor serisine gore sine hesaplayan fonksiyon                              */
double sine( int degree, int n );

/*Taylor serisine gore cosine hesaplayan fonksiyon                            */
double cosine( int degree, int n);

/*Input alınan fonksiyon                                                      */
void getInputs( int* degree, int* n, int* exit );


/*Main fonksiyonu                                                             */
int main(){
	int *degree, *n, *exit, y=0;
	int x= 30, z = 4;
		exit = &y;
		degree = &x;
		n= &z;

	while(*exit != 1)
	{
		
		getInputs(degree, n, exit); 
		//getInputs(degree, n, exit);	// Hangisi doğru emin olamadım
		if(*exit == 0)
		{
		
			sine(*degree, *n);
			cosine(*degree, *n);
		}
	}
	return *exit;
}
void getInputs(int* degree, int* n, int* exit) 
{
	
/* Maksimum 50 karakter alabilir.                                             */
	char input[5000];
	int i = 0, j = 0, a = 0, b = 0;

        
	scanf(" %5000[^\n]&", input );

/*Girilen input 'E' ve 'e' nin ASCII degerlerinden birine esit olursa         */
			*exit=0;


	if((input[0] == 101 || input[0] == 69) && input[1] == '\0')
		*exit = 0;
	else if(input[0] == 101 || input[0] == 69)
		*exit = 1;


	else if((input[0]>47 && input[0]<58))	
/*Farklı bir input girilirse                                                 */	
	{
		if(*n<0)
			*exit=0;
		
		else 
		{
			*exit = 0;

			if(input[0] == 45)
				i = 1;
			while(input[i] != 32)
			{
		
				a = a * 10 + (input[i] - 48);
				i++;
			}
		*degree = a;
			if(input[0] == 45)		
				*degree *= (-1);
			
			if(input[i+1]=='\n')
				*exit=0;
			else if(input[i+1]== 45)
				*exit = 0;
			for(j = i+1; input[j] != '\0'; j++)
			{
				b = b * 10 + (input[j] - 48);
			}
		
				*n = b;
		}	
	}
	else
		*exit=0;
}



double pw( double a, int k ) 
{
	int i; 
	double result=1;
/*Girilen sayiyi ustu kadar yan yana yazip carpma                             */
	if(k==0)
		return result;
	else if(k>1)
		for( i=1 ; i<=k ; i++ ) 
		{
			result *=a;
		}
	else
		result = a;
	
	return result;	
}

double fac(int j) 
{       
	int i;
	double result=1;
/*girilen deger 0 dan kucukse faktoriyel hesaplamaz                          */	
	if (j>0) 
	{
/*1 den baslayarak girilen degere kadar sayilari carparak faktoriyele ulasilir*/
		for (i=1;i<=(j) ;i++) 
		{
			result *=i;
		}
	}
	
	return result;
}

double sine( degree, n ) 
{
	int i;
	double sum, result=0;
/*girilen aci degeri 360 tan buyukse 360 a gore modu alinip isleme girer      */

	if(degree>360)
		degree=degree%360;
	else if (degree < 0)
		degree += ((int)(degree/360) + 1) * 360;
/*girilen n degeri kadar dongu devam eder.                                   */	 
	for( i=0 ; i<n ; i++ ) 
	{
/*girilen aci derece cinsinden oldugu icin radyana cevrilir                  */
		double rad=(degree*PI)/180;
/*formuldeki degeri(2*n+1) bir degiskene atariz                              */
		int m=2*i+1;
/*toplam=(pow(-1,n)*pow(rad,2*n+1))/factorial(2*n+1)                         */
		sum=(pw(-1,i)*pw(rad,m))/fac(m);
		result += sum;
	}	
	printf("sin(%d) where n is %d = %1.4f\n", degree, n, result);
	return result;	
}

double cosine( degree, n )
{
	int i;
	double sum, result=0;
/*girilen aci degeri 360 tan buyukse 360 a gore modu alinip isleme girer     */	
	
	if(degree>360)
		degree=degree%360;
	else if (degree < 0)
		degree += ((int)(degree/360) + 1) * 360;
		
/*girilen n degeri kadar dongu devam eder ve toplama eklenir                  */ 
	for( i=0 ; i<n ; i++ ) 
	{
/*girilen aci derece cinsinden oldugu icin radyana cevrilir                   */
		double rad=(degree*PI)/180;
/*formuldeki degeri(2*n) bir degiskene atariz                                 */ 
		int k=2*i;
/*toplam=(pow(-1,n)*pow(rad,2*n))/factorial(2*n)                              */
		sum=(pw(-1,i)*pw(rad,k))/fac(k);
		result += sum;
	}	
	printf("cos(%d) where n is %d = %1.4f\n", degree, n, result);
	return result;	
}
