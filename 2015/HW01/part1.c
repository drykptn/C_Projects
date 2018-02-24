/*
* In this part you will write a C code to ask a user his/her birth date as day, month and year respectively and you will
* calculate how many days left to his/her birthday and how old is he/she and then you will print this information on the
* screen.
* Your code should include two functions, one for calculating the number of days to the birthday and the other to
* calculate the age.
* DO NOT use condition and conditional operators.
* Take A Year = 365 Days
* A Month = 30 Days
*/


#include<stdio.h>
int main() {
int midtermWeight1, midtermWeight2, midtermWeight3, homeworkWeight1;
int homeworkWeight2, finalWeight, midtermGrade1, midtermGrade2;
int  midtermGrade3, homeworkGrade1, homeworkGrade2, finalGrade;
float average;
	printf("please enter the 1.midterm weight:  ");	
	scanf("%d", &midtermWeight1);
	printf("please enter the 2.midterm weight:  ");	
	scanf("%d", &midtermWeight2);
	printf("please enter the 3.midterm weight:  ");	
	scanf("%d", &midtermWeight3);
	printf("please enter the 1.homework weight:  ");	
	scanf("%d", &homeworkWeight1);
	printf("please enter the 2.homework weight:  ");	
	scanf("%d", &homeworkWeight2);
	printf("please enter the final exam weight:  ");	
	scanf("%d", &finalWeight);
	printf("please enter the 1.midterm grade:  ");	
	scanf("%d", &midtermGrade1);
	printf("please enter the 2.midterm grade:  ");	
	scanf("%d", &midtermGrade2);
	printf("please enter the 3.midterm grade:  ");	
	scanf("%d", &midtermGrade3);
	printf("please enter the 1.homework grade:  ");	
	scanf("%d", &homeworkGrade1);
	printf("please enter the 2.homework grade:  ");	
	scanf("%d", &homeworkGrade2);
	printf("please enter the final exam grade:  ");	
	scanf("%d", &finalGrade);
	/* (all grades*weight) */
int a, b, c, d, e, f;
	a=midtermGrade1*midtermWeight1;  
	b=midtermGrade2*midtermWeight2;
	c=midtermGrade3*midtermWeight3;
	d=homeworkGrade1*homeworkWeight1;
	e=homeworkGrade2*homeworkWeight2;
	f=finalGrade*finalWeight;
	/* the sum of all grades/100 */
	average=(float)(a+b+c+d+e+f)/100;
	printf("your final grade is:  %.2f", average);
	return 0;
}
