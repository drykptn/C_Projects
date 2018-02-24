/*
In	this	part	you	will	deal	with	prime	numbers	and	Goldbach	conjecture.	Goldbach	conjecture	claims	that	every	even	integer	
that	is	greater	than	2	can	be	written	as	a	sum	of	two	prime	numbers.	You	will	implement	 isPrime function	that	checks	
whether	given	integer	is	a	prime	number	or	not	and	 goldbach 	function	which	takes	an	integer	and	returns	two	prime	
numbers	whose	sum	is	equal	to	given	integer.		
	
Please	consider	that	each	different	approach	may	result	in	finding	different	prime	numbers	so	that	there	will	be	multiple	
correct	solution	for	 goldbach 	function.	
*/

#include <stdio.h>

int isPrime(int num);
int goldbach(int num, int *p1, int *p2);

int main(int argc, char** argv) {
    
    int p1;
    int p2 ;
    int num;
    scanf("%d", &num);
 
    if(goldbach(num,&p1,&p2))
        printf("%d = %d + %d\n",num,p1,p2); /* may print 824 = 821 + 3 */
    else
        printf("You should provide even number.\n");
    return (0);
}
/* 
 *  This function takes an integer and returns two prime numbers whose sum is 
 *  equal to given integer.		 
 */
int goldbach(int num, int *p1, int *p2){
    int i;
    int j;
    
    /* Error check */
    if (num % 2 != 0 || num <= 2)
        return 0; 
    
    for (i = 3; i <= num/2 ; i++)
    {
        for (j = 3; j < num; ++j)
        {
            /* If i and j are prime numbers */
            if( isPrime(i) == -1 && isPrime(j) == -1)
            {
                if ( num == i + j ) 
                {
                    /* If find a goldbach number, so assign i and j to pointers */
                    *p1 = i;
                    *p2 = j;
                    return -1;
                } 
            } 
        }
    }
    return 0;
}
/* This function checks	whether	given integer is a prime number	or not */
int isPrime(int num){
    int i;
    if(num < 2)
        return 0;
    for( i = 2 ; i <= num - 1; i++){
        if(num % i == 0)
            return 0;    /* it is not a prime number, so return 0 */
    }
        return -1;   /* else it is a prime number */
}
