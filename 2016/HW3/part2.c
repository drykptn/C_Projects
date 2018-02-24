/*
Write	a	function	that	dispenses	change.	Function	takes	8	parameters,	first	parameter	is	the	paid	amount,	second	parameter	
is	the	due	amount.	Rest	of	the	parameters	are	the	number	of	Turkish	lira	coins	that	should	be	returned	from	this	function.	
Parameters	are	sorted	in	descending	order.	Your	function	should	return	0	in	case	of	error,	1	otherwise.	
*/
#include <stdio.h>

int dispenseChange(double paid, double due, int *tl1, int *krs50, int *krs25, 
                   int *krs10, int *krs5, int *krs1);

/* This function takes total liras and convert to coins */
void assignKurus(int temp, int *tl1, int *krs50, int *krs25,int *krs10, int *krs5, 
                 int *krs1);

int main(int argc, char** argv) {
    int tl1 = 0;
    int krs50 = 0; 
    int krs25 = 0;
    int krs10 = 0;
    int krs5 = 0;
    int krs1 = 0;
    double paid = 8.80;
    double due = 3.00;
    
    if(dispenseChange(paid, due, &tl1, &krs50 , &krs25, &krs10, &krs5, &krs1)) /* returns 1 */
        printf("Change: 1TL:%d\n50 kurus:%d\n25 kurus:%d\n10 kurus:%d\n5 kurus:%d\n1 kurus:%d\n",tl1,krs50,krs25,krs10,krs5,krs1);
    else
        printf("Unable to dispense change.");
    return (0);
}

int dispenseChange(double paid, double due, int *tl1, int *krs50, int *krs25, 
                   int *krs10, int *krs5, int *krs1){
    double liras;                   /* difference between paid and due */
    double coinsDue;                /* coins of due                    */
    double coinsPaid;               /* coins of paid                   */  
    int temp;                       /* temporary value                 */
       
    if( paid > due ){
        coinsDue = due - (int)due;           /* coins of due */
        if( coinsDue > 0 ){                  
            coinsPaid = paid - (int)paid;
            
            if( coinsPaid < coinsDue )
                liras = (int)paid - (int)due - 1;  
            
            else if( coinsPaid > coinsDue )
                liras = (int)paid - (int)due;
            
            *tl1 = liras;
            coinsDue = 1 - coinsDue; /* for the rest of coins ( 1.80 -> 0.20 )*/
            coinsDue += coinsPaid;   /* add coins of paid to coins of due     */
            
            /* If total coins bigger than 0.99, decrease coins of due 1 lira */
            if( coinsDue > 0.99 ){
                coinsDue -= 1;
                temp = coinsDue * 100;   /* convert to integer for readability*/
                assignKurus(temp, tl1, krs50, krs25, krs10, krs5, krs1);
            }
            else{
                temp = coinsDue * 100;   /* convert to integer for readability*/
                assignKurus(temp, tl1, krs50, krs25, krs10, krs5, krs1);
            }
            return 1;
        }
        /* if coins of due equal zero, we just take coins of paid */
        else if( coinsDue == 0.0 ){
            liras = (int)paid - (int)due;
            *tl1 = liras;
            coinsPaid = paid - (int)paid;
            coinsPaid *= 100;           /* convert to integer for readability*/
            
            assignKurus(coinsPaid, tl1, krs50, krs25, krs10, krs5, krs1);
            return 1;
        }
    }
    /* If paid equals due, all of coins equal 0 */
    else if( paid == due ){
        *tl1 = 0;
        *krs50 = 0;
        *krs25 = 0;
        *krs10 = 0;
        *krs5 = 0;
        *krs1 = 0;
        return 1;
    }        
    return 0;
        
}
void assignKurus(int temp, int *tl1, int *krs50, int *krs25,int *krs10, int *krs5, 
                 int *krs1){
    int num = 0;
    /* if coins have 0.50 kurus */
    if(temp >= 50){
        *krs50 = 1;                       
        temp -= 50;                    /* decrease for the rest of coins*/
    }
    /* if coins have 0.25 kurus */
    if(temp >= 25){
        *krs25 = 1;
        temp -= 25;                    /* decrease for the rest of coins*/
    }
    /* if coins have 0.10 kurus */
    if(temp >= 10){
        num = (int)temp/10;
        *krs10 = num;
        temp -= num*10;                /* decrease for the rest of coins*/ 
    }
    /* if coins have 0.05 kurus */
    if(temp >= 5){
        num = (int)temp/5;
        *krs5 = num;
        temp -= num*5;                 /* decrease for the rest of coins*/
    }
    /* if coins have 0.01 kurus */
    if(temp >= 1){
        num = (int)temp;
        *krs1 = num;               
    }
}
