#include <stdio.h>
#define DAY_OF_YEAR 365
#define DAY_OF_MONTH 30
#define MONTH_OF_YEAR 12

int theAge(int day, int month, int year, int today, int this_month, 
	       int this_year);
int daysLeft(int day, int month, int today, int this_month);

int main(int argc, char const *argv[])
{
	int day, month, year, today, this_month, this_year, age, days;

	printf("Please enter your birthday\n");	
	printf("day : ");
	scanf("%d", &day); 

	printf("month : ");
	scanf("%d", &month); 

	printf("year : ");
	scanf("%d", &year); 

	printf("today : ");
	scanf("%d", &today); 

	printf("this_month : ");
	scanf("%d", &this_month); 

	printf("this_year : ");
	scanf("%d", &this_year); 
	
	printf("day : %d, month : %d, year : %d, today : %d, this_month : %d, this_year : %d\n",day, month, year, today, this_month, this_year);

	age = theAge(day, month, year,today,this_month, this_year);
 	days = daysLeft(day, month, today, this_month);

 	/*  Days left to birthday, Age of the user */
 	printf("days : %d, age : %d \n", days, age);
 
	return 0;
}

int theAge(int day, int month, int year, int today, int this_month,
	       int this_year)
{
	int calc_year;    /* yillar arasi fark */
    int calc_month;   /* aylar arasi fark */
    int calc_day;     /* gunler arasi fark */
    int birthday;     /* kisinin yasi */

	/* yillar arasi farki hesapla */
    calc_year = (this_year - year) * MONTH_OF_YEAR * DAY_OF_MONTH;
    
    /* aylar arasi farki hesapla */
    calc_month = (month - this_month - 1) * DAY_OF_MONTH;
	
	/* gunler arasi farki hesapla */
    calc_day = DAY_OF_MONTH - (today - day);

	/* hepsinin toplaminin gun sayisina bolumu yasi verir */	
	birthday = (calc_year + calc_month + calc_day) / DAY_OF_YEAR;
	
	return birthday;
}

int daysLeft(int day, int month, int today, int this_month){
	
	int calc_month;
	int calc_day;
	int birthday;

	calc_month = (month - this_month - 1) * DAY_OF_MONTH;
	calc_day = DAY_OF_MONTH - (today - day);
	birthday = calc_month + calc_day;

	printf("%d\n", birthday);
	
	return birthday;
}