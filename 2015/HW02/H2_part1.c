/* HW02_141044025_Derya_Kaptan                                      */
/*  Created on 27/02/2016 by Derya_Kaptan  		       */
/* Description									       */
/* ----------- 									       */ 
/* Program that calculate the grade of three students.        */
/*--------------------------------------------------------------------------*/
/* Includes                                                                              */
/*--------------------------------------------------------------------------*/
#include <stdio.h> 
/*--------------------------------------------------------------------------*/ 
/* 			Function Prototypes */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

 
#include<stdio.h>
void calculateLastGrade() {
int midtermWeight1,  homeworkWeight1, finalWeight, midtermGrade1;
int  homeworkGrade1, finalGrade, a, b, c;
float average;
	printf("Please enter the 1. midterm weight:");	
	scanf("%d", &midtermWeight1);
	
	printf("Please enter the 1. homework weight:");	
	scanf("%d", &homeworkWeight1);
	
	printf("Please enter the final exam weight:");	
	scanf("%d", &finalWeight);
	
	printf("Please enter the 1. midterm grade:");	
	scanf("%d", &midtermGrade1);
	
	printf("Please enter the 1. homework grade:");	
	scanf("%d", &homeworkGrade1);
	
	printf("Please enter the final exam grade:  ");	
	scanf("%d", &finalGrade);
	/* (all grades*weight) */
	a=midtermGrade1*midtermWeight1;  
	b=homeworkGrade1*homeworkWeight1;
	c=finalGrade*finalWeight;
	/* the sum of all grades/100 */
	average=(float)(a+b+c)/100;
	printf("your final grade is:  %f", average);
}
int main() {
	calculateLastGrade( );
	printf("\n");	 
	calculateLastGrade( );
	printf("\n");
	calculateLastGrade( );
	printf("\n");
	return 0;
}
