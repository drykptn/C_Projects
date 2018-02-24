#include <stdio.h>
#define PI 3.14

int testFunc( float value );
float diameter(float circumference);
float ageOfTree(float diameter , float growth_factor);

int main(int argc, char const *argv[])
{

	float dia, age, pine, circumference; 

	printf("Please enter a circumference of tree ->\n");
	scanf("%f", &circumference);
	
	dia = diameter(circumference);

	printf("Please enter a growth factor -> \n");
	printf("American Elm  = 4;\nAustrian Pine = 4.5;\nBlack Cherry  = 5;\nScotch Pine   = 3.5\n");
	scanf("%f", &pine);

	
	age = ageOfTree(dia, pine);
	
	/* Diameter of the tree , Age of tree */
	printf( "dia : %.3f, age : %.3f\n", dia, age);
	printf( "dia : %e, age : %e\n", dia, age);
	
	
	return 0;
}

/* This function calculates diameter of tree */
float diameter(float circumference){
	float diameter = 0;
	/* If user enter a wrong input */
	if( testFunc(circumference) == 1 || testFunc(circumference) == 2 )
		printf("Circumference/Diameter can't be equals 0 or smaller than 0\n");
	else if ( testFunc(circumference) == 0 )
		/* Calculate diameter of tree */
		diameter = circumference / PI;
	return diameter;
}

/* This function calculates age of tree */
float ageOfTree(float diameter , float growth_factor){
	float ageOfT = 0.0;	
	/* If user enter a wrong diameter */
	if( testFunc(diameter) == 1 || testFunc(diameter) == 2 )
			printf("Circumference/Diameter can't be equals 0 or smaller than 0\n");
	/* If user enter a wrong growth factor */
	if ( growth_factor == 4 || growth_factor == 4.5 || 
		 growth_factor == 5 || growth_factor == 3.5){
		if ( testFunc(diameter) == 0 )
			/* Calculate age of tree*/
			ageOfT = diameter * growth_factor;
	}
	else
		printf("Wrong growth factor\n");
	return ageOfT;
}
/* This function controls the given values */
int testFunc( float value ){
	/* If value is equal 0 */
	if( value == 0.0 )
		return 1;
	/* If value is smaller than 0 */
	else if( value < 0 )
		return 2;
	return 0;
}
