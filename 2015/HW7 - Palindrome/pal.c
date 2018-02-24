/*
In this part, you will write a recursive palindrome finder function. A palindrome is a sequence of characters
which reads the same backward or forward (“abcdedcba”, “abba”). This function has some differences from
standard palindrome.
 In the input string, there may be punctuations, spaces etc. that you must ignore. You will match only
letters. For example, “ab, cd!ed~cb%a” is a palindrome but "ab!ab" is not.
 The function must work case insensitive. For example, “AbcDedCba” is a palindrome.
Your function returns 1 if the given string is a palindrome, otherwise (any invalid conditions and not
palindrome) it returns 0.
*/
/*----------------------------------------------------------------------------*/
/* 	                                                                      */
/* HW07_141044025_Derya_Kaptan					              */
/*               				                              */
/* ---------------------------------------------------------------------------*/
/* Created on 15/04/2016 by Derya_Kaptan			              */
/* 									      */
/*									      */
/*----------------------------------------------------------------------------*/
/*                            Includes 				    	      */
/*----------------------------------------------------------------------------*/ 
#include<stdio.h>
/*----------------------------------------------------------------------------*/
/*                              Description                                   */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                This is a recursive palindrome finder function              */
/*----------------------------------------------------------------------------*/
/*                           Function Prototypes   			      */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* 									      */

int isPalindrome(char * str);

/* This function is calculates array's size                                   */
int size(char * str);

/* This function is copies arrays each other                                  */
void stringCopy(char * str,char * arr);

/* This function just takes letters and copies other array.                   */
int foo( char * str , char * arr , int i, int j );

#include<stdio.h>
int main(){
    char str[150]={"deryaaMyred"};
	printf("%d\n", isPalindrome( str ));
    return 0;
}
int isPalindrome( char * str )
{
	int i = 0, len, j = 0;
	char arr[150];
	
	foo( str , arr , i , j );
	
/* len equals arr 's size                                                    */	
	len = size( arr );

/* This loop controls middle of the array and if equals each other, this      */
/* array is palindrome array.                                                 */
	for( i = 0; i < len/2; i++ ) 
	{
		if( arr[i] != arr[ len - i - 1 ] )
			return 0;	
	}
	return 1;           
}
int size ( char * str )
{
	int i;
	for ( i = 0; str[i] != '\0'; ++i);
	return i;
}
/* Recursive function                                                         */
int foo( char * str , char * arr , int i, int j )
{
	if ( str[i] != '\0')
	{
/* if value is a letter                                                       */
		if((str[i] >= 97 && str[i] <= 122 ) || 
		   (str[i] >= 65 && str[i] <= 90))
   		{
			stringCopy( str , arr);
		}
		return foo( str , arr , i + 1 , j );
	}
	else
		return 0;
}
/*This funtion uses instead of strcpy                                         */
void stringCopy(char * str,char * arr){
    int i = 0;

    while( str[i] != '\0' )
    {
    	arr[i] = str[i];
   		i++;
    }
   arr[i]='\0';
}
/*----------------------------------------------------------------------------*/
/*                                END                                         */
/*----------------------------------------------------------------------------*/
