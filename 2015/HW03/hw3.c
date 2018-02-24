/*---------------------------------------------------------------------------*/
/*
You will wite a program which asks users for an integer and checks if the number is an odd, a
factorial or a narcissistic number, depending on the user choice. The program will keep running
until the user wants to exit by entering y. Example run of the program should look like:ODD
Definition: A number is odd if it is not divisible by 2.
Numbers that are not odd are even. Compare with another pair -- evil and odious numbers.
First ten: 1, 3, 5, 7, 9, 11, 13, 15, 17, 19
There are 5000 odd numbers below 10,000.
FACTORIAL
Definition: The n-th factorial is the product of the first n natural numbers.
The factorial deserved an exclamation mark for its notation: k! = 1*2*3*...*k.
First ten: 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800
There are 7 factorials below 10,000.
NARCISSISTIC
Definition: A k-digit number n is called narcissistic if it is equal to the sum of k-th powers of its
digits. They are also called Plus Perfect numbers.
First ten: 1, 2, 3, 4, 5, 6, 7, 8, 9, 153
There are 16 narcissistic numbers below 10,000.
*/
/* 	                                                                     */
/* HW03_141044025_Derya_Kaptan					             */
/*               				                             */
/* --------------------------------------------------------------------------*/
/* Created on 06/03/2016 by Derya_Kaptan			             */
/* 									     */
/*									     */
/*---------------------------------------------------------------------------*/
/*                            Includes 				    	     */
/*---------------------------------------------------------------------------*/ 
#include<stdio.h>
#include<math.h>

/*---------------------------------------------------------------------------*/
/*                           Function Prototypes   			     */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/* 									     */ 

/* This function checks whether the given number is an odd number            */ 
void oddNumber( int );

/*This function checks whether the given number is  a factorial number       */
int factorialNumber( int );

/*This function checks whether the given number is a narcissistic number     */
void narcissisticNumber( int );

/*This function checks choice and calculates digits                          */ 
int fonk(int);

void drawBox();

int main() {
	int number;
	char yesNo; /* yesNo=for continue */
	
	drawBox();
	while (1) {
	printf("Please enter a positive integer:");
	scanf(" %d&", &number);
	
/*if the given number small than zero                                        */	
		if ( number<0 ) {
			printf("ERROR! Please enter a positive integer \n");
		}
		
/*if the given number big than zero or equal zero                            */		
		else if ( number>=0) {
		 	fonk(number);
		}
		printf("Do you want to continue (y/n)?");
		scanf(" %c&", &yesNo);
		
/*if the user choice another character                                       */
		if(yesNo=='n') {
			printf("Good Bye !\n");
			return 0;			
		}
	}
	return 0;
}

/*Function Definition*/
void oddNumber( int number ) {
    
    /* function body*/
    
/* if a number's mode is not equal zero, this number is an odd number        */
	if (number%2!=0)
		printf("%d is a odd number !\n", number);
	else 
		printf("%d is not a odd number !\n", number);
}

/*Function Definition*/
int factorialNumber( int number ) {
	
	/* function body*/
	
	int i=1, result=1;

	while ( 1) {
	    
/* starting with 1 products all numbers                                      */	    
		result = result*i;
		i++;	
		
/* if this results equals number, the given number is a factorial number.    */		
		if ( result==number ) {
			printf("%d is a factorial number !\n", number);
			return 0;
		}
		else if( result>number ) {
			printf("%d is not a factorial number !\n", number);
			return 0;
		}
	}
}

/*Function Definition*/		
void narcissisticNumber( int number ) {
	
	/* function body*/
/*digit = digit place, temp = number of temporary value, i= a random number  */
	int digit=0, temp=number, remainder,i , division, result=0;

/* while the given number not equal zero                                     */
	while ( temp!=0) {
		temp=temp/10; /*the given number divide 10 till find digit places    */
		digit++;
	}

/*i=a random number, k=digit place                                           */	
	for(i=0; i<digit; i++) {
	    
/*the number divide 10 till equal 0                                          */
		division = number/pow(10,i); 
/* then get the numbers of modes                                             */
		remainder = division%10;
/* then respectively,take them the numbers of power                          */
		result += pow(remainder,digit);
	}
/*if result equals number, this number is a narcissistic number.             */	
	if( result==number ) 
		printf("%d is a narcissistic number !\n", number);
	else 
		printf("%d is not a narcissistic number !\n", number);

}
	
int fonk(int number) {
/*print the intented list                                                    */
		int choice;
		printf( "Which property would you like to check?\n" );
		printf( "1)Odd number\n" );
		printf( "2)Factorial number\n" );
		printf( "3)Narcissistic number\n" );
		printf( "Please enter(1/2/3):");	
		scanf("%d", &choice );

/*the user enters a choice                                                   */
	switch (choice ) {
			case 1: 
			/*if case equals choice,enter the function*/
				oddNumber( number );	
				break;
			case 2:
			/*if case equals choice,enter the function*/
				factorialNumber( number );
				break;
			case 3:
			/*if case equals choice,enter the function*/
			/*if the number smaller than 10,number is a narcissistic number  */
				if (number<10) {
					printf("%d is a narcissistic number !\n", number);
				}
				else {
					narcissisticNumber(number);
				}
				break;
			default:
			/*if the choise not equal any of them, doing this*/
				printf("Please try again\n");
				break;
		}
	return 0;		
}

void drawBox() {
	printf("************************************************************\n");
	printf("*                                WELCOME !                 *\n");
	printf("*     This program checks whether the given number         *\n");
	printf("*       is an odd, a factorial or a narcissistic number    *\n");
	printf("*		                                           *\n");
	printf("************************************************************\n");
}
