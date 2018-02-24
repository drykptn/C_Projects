/*
In	the	last	part,	you’re	given	a	travelling	card	(IstanbulCard)	automation.	Every	member	has	a	balance(bakiye)	and	a	
remaining	monthly	use	(Aylık	kullanım	hakkı).	There	are	3	different	card	types:	Normal,	Student,	and	Teacher	cards.	Cards	
are	charged	with	different	amounts:	Normal	cards	are	charged	2.30₺,	student	cards	are	charged	1.15₺,	teacher	cards	are	
charged	1.65₺.	If	user	has	a	monthly	subscription,	you	should	decrease	it	by	1.	If	user	has	no	subscription,	you	should	
charge	user	according	to	his/her	card	type.	If	remaining	monthly	use	is	lower	than	1,	you	should	assume	that	user	does	not	
have	a	monthly	subscription.	
	
You	should	not	use	if	statements	or	ternary	operator	for	determining	user’s	card	types,	you	can	only	use	switch	statement.	
Card	types	are	represented	with	integers:	
Normal	Card	:	1,	Student	Card	:	2,	Teacher	Card	:	3	
	
Return	values	and	error	conditions:	
	
-	Insufficient	balance	or	monthly	use:	return	-1	
	
-	Invalid	card	type:	return	-2	
	
-	0,	if	there	is	no	error.	
*/
#include <stdio.h>

int charge(int cardType, int* monthlyUse, double* balance);

int main(int argc, char const *argv[])
{
	int monthlyUse = 0;
	double balance = 20.0;
	if(!(charge(1,&monthlyUse, &balance) < 0))
	printf("Remaining monthly use: %d – Remaining Balance: %.2f\n",monthlyUse,balance);
	else
	printf("Insufficient balance.");
	return 0;
}

int charge(int cardType, int* monthlyUse, double* balance){
	if(*monthlyUse < 1)
	{		
		switch(cardType){
			case 1:           /* normal card */
				/* if she/her has insufficient balance */
				if( *balance < 2.30 )
					return -1;
				*balance -=	2.30;
				return 0;	
			case 2:           /* student card */
				/* if she/he has insufficient	balance */
				if( *balance < 1.15 )
					return -1;
				*balance -= 1.15;
				return 0;
			case 3:			  /* teacher card */
				/* if she/he has insufficient	balance */
				if( *balance < 1.65 )
					return -1;
				*balance -= 1.65;
				return 0;
			default:          /* invalid card type */
				return -2;
		}
	}
	else
	    /* if he/she has monthly use*/
		*monthlyUse -= 1;
	return 0;	
}
