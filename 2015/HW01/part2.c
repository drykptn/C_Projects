/*
* Write a C code to calculate the age of a tree. It will contain two functions, the first function will take the circumference
* of tree as input and returns the diameter of tree as output. The second function will take the diameter that calculated
* by the first function and the growth factor of tree species as inputs, calculate the age of tree according to the formula :
* Age of Tree = Diameter of Tree x Growth Factor and returns the age of tree as output. (Take Pi= 3.14)
* Growth factors of some species as following :
* American Elm = 4 ; Austrian Pine = 4.5 ; Black Cherry = 5 ; Scotch Pine = 3.5
*/
#include<stdio.h>
int main(){
int currentYear, currentMonth, currentDay, birthdayYear, birthdayMonth;
int birthdayDay, result1, planetHour, planetDay, planetMonth, totalDay;
int  year, month, day, a, b, c;
	printf("Please enter the current date. \n");
	
	printf("Year:");
	scanf("%d", &currentYear);
	
	printf("Month:");
	scanf("%d", &currentMonth);
	
	printf("Day:");
	scanf("%d", &currentDay);
	
	printf("Please enter your birthday.\n");
	
	printf("Year:");
	scanf("%d", &birthdayYear);
	
	printf("Month:");
	scanf("%d", &birthdayMonth);
	
	printf("Day:");
	scanf("%d", &birthdayDay);
	
	/* yillar farki */
	a= currentYear- birthdayYear;
	
	/* aylar farki */
	b=currentMonth-birthdayMonth;
	
	/*  gunler farki */
	c=currentDay-birthdayDay;
	
	/* (yillar farki*bir yildaki gun sayisi)+(aylar farki*bir yildaki ay sayisi)+(gunler farki)*/
	result1 =  (a* 365)+(b*30)+(c); 

	/*for another planet*/
	printf("You have lived %d days.\n", result1);
	
	printf("Please enter about the time of another planet\n");
	
	printf("How many hours is a day?");
	scanf("%d", &planetHour);
	
	printf("How many days is a month?");
	scanf("%d", &planetDay);
	
	printf("How many months is a year?");
	scanf("%d", &planetMonth);
	
	 /* Diger gezegendeki toplam gun sayisi */
	totalDay = ((result1*24)/planetHour);      
	
	 /*  toplam gun sayisinin bir yıldaki toplam gun sayisina (gun*ay) bolumunden yil bulunur */
	year = (totalDay)/(planetDay*planetMonth);  
	
	/* toplam gun sayisindan yillari cikarip bir aydaki gun sayisina (gun*ay*yıl) bolumunden ay bulunur */
	month = (totalDay-(year*planetMonth*planetDay))/planetDay;   
	
	/* toplam gun sayisindan toplam yil ve aylar cikarilinca kalan gun sayisi bulunur*/ 
	day = ((totalDay-(year*planetMonth*planetDay))-(month*planetDay));   
	
	printf("If you lived in a planet where a day is %d hours,", planetHour);
	printf("a month is  %d days and a year is ", planetDay); 
	printf("%d months: you were %d years,", planetMonth, year); 
	printf("%d months and %d days old\n", month, day);
	return 0;
}
