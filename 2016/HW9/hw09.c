/*
In	this	homework,	you	will	continue	on	your	HW08.	You	will	manage	the	contacts	directory	as	you	did	before	but	you	will	
use	linked	list	to	hold	phone	record	for	each	person.	You	are	responsible	for	the	allocation	and	freeing	the	necessary	space	
for	phone	records.	 Do	not	keep	any	additional	space	for	phone	records. 	
	
You	are	also	asked	to	implement	serializer/deserializer	functions	for	the	People	struct.	You	need	to	create	a	binary	file	that	
contains	all	information	of	the	People	struct.	One	recommended	approach	is	to	store	name,	expenditure,	number	of	phone	
numbers	and	the	phone	numbers	for	a	person.	
	
Figure 1 Content of a binary file. Mind that no space wasted! 	
	
In	this	homework,	you	are	given	the	total	of	phone	bills	(defined	as	expenditures)	of	a	person.	Some	persons’	expenditure	
information	is	unknown	and	denoted	as	-1.	You	need	to	calculate	expected	expenditure	for	every	person	with	unknown	
expenditure.	Expenditure	can	be	calculated	as	follows:	
	
Expected	Expenditure	for	p  = 	E/N ×	K

E = 	Total	expenditure	of	every	person	with	known	expenditures
	
N =	⋕ 	of	phone	numbers	for	every	person	with	known	expenditures
K =	⋕ of	phone	numbers	of	the	p /
		
Each	function	is	described	with	comments	in	starter	code.	Any	attempt	for	unnecessary	memory	allocation	and	
unnecessary	file	writes	will	be	graded	0.	You	need	to	implement	both	read	and	write	functions	for	getting	full	credit.	
Therefore	you	will	not	have	partial	credit	if	you	implement	just	one	of	read	or	write	functions.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAMELEN 50
#define MAXRECORD 500

typedef struct record_s {
    int id;
    char number[NAMELEN];
    struct record_s *next;
} Record;

typedef struct person_s {
    int id;
    char name[NAMELEN];
    double expenditure;           // tel faturasi
    Record *numbers;		
} Person;

typedef struct people_s {
    Person data[MAXRECORD];
    int size;
} People;


/*
 Write People.data array to the filename.
*/
void writePeople(People people, char* filename) {

}

/*
 Reads Person structs from file and places them to People.data array.
 Note that the number of Person structs in the file is unkown.
*/
void readPeople(People *people, char* filename) {

}

/*
 Calculates the expected expenditure for the person with unknown expenditure.
 Persons' expenditure is -1 if their expenditure is unknown.
 You should calculate average bill amount for a phone number and multiply it by
 the phone number count for the person.
*/
void imputation(People *people) {
}

/*
 Reads the input file and constructs People struct.
 Note that the number of phone numbers in file is unknown unlike your
 previous homework. You should keep phone numbers in the linked list
 (numbers field)
*/
void read(char* filename, People *people) {
	char str[NAMELEN];
    FILE *fptr;
    int count;
    int line;
    count = 0;
    line = 0;
    
    fptr = fopen(filename, "r");
    if( fptr == NULL ){
        printf("File is not open -- %s!\n", filename);
        exit(1);
    }
    people->size = findSizeOfFile(filename);    
    records->size = 0;
    
    while(people->size != line){
        /* read the person id  */
        fscanf(fptr, "%d", &people->data[line].id);
        
        /* read the person name */
        fscanf(fptr, "%s", people->data[line].name);
       
        /* let a space then */
        strcat(people->data[line].name , " ");
        
        /* read the surname and add */
        fscanf(fptr, "%s", str);
        strcat(people->data[line].name , str);
        
        /* read the person expenditure  */
        fscanf(fptr, "%lf", &people->data[line].expenditure);

        /* read for all cell phone */
        while( (ch = fgetc(fptr)) != EOF && (ch = fgetc(fptr)) != '\n' )
    	{   
            fscanf(fptr, "%s", records->data[count].number);
            records->data[count].id = people->data[line].id;
            count++;
        }

        line++;
    }
     
    fclose(fptr);
}

void print(People people) {
    int i,found = 0;
    Record *rec;
    /* header */
    printf("%-5s %-30s %-20s %-20s\n", "ID","NAME","EXPENDITURE","NUMBER(s)");
    /* line */
    for (i = 0; i < 78; ++i)
        printf("-");
    printf("\n");

    for (i = 0; i < people.size; ++i) {
        found = 0;
        printf("%-5d %-30s %-20.4f", people.data[i].id, people.data[i].name, people.data[i].expenditure);
        rec = people.data[i].numbers;
        while(rec) {
            if(found)
                printf("%57s", "");
            else
                found = 1;
            printf("%-20s\n", rec->number);
            rec = rec->next;
        }
        printf("\n");
    }
}

int isPeopleEq(People ppl1, People ppl2) {
    Record *rec1,*rec2;
    int i,found = 0;
    int p1size = 0, p2size = 0;
    if(ppl1.size != ppl2.size)
        return 0;
    for (i = 0; i < ppl1.size; ++i){
        if(strcmp(ppl1.data[i].name,ppl2.data[i].name))
            return 0;
        if(ppl1.data[i].id != ppl2.data[i].id)
            return 0;

        p1size = p2size = 0;
        rec1 = ppl1.data[i].numbers;
        while(rec1) {
            ++p1size;
            rec1 = rec1->next;
        }

        rec2 = ppl2.data[i].numbers;
        while(rec2) {
            ++p2size;
            rec2 = rec2->next;
        }

        if(p1size != p2size) {
            return 0;
        }

        rec1 = ppl1.data[i].numbers;
        while(rec1) {
            rec2 = ppl2.data[i].numbers;
            found = 0;
            while(!found && rec2) {
                if(strcmp(rec1->number,rec2->number) == 0) {
                    found = 1;
                    break;
                }
                rec2 = rec2->next;
            }
            if(!found) {
                return 0;
            }
            rec1 = rec1->next;
        }
    }
    return 1;
}

int main(int argc, char** argv) {
    People people1,people2;
   
    people1.size = 0;
   
    read(argv[1],&people1);
   
    print(people1);
   
    writePeople(people1,"people.bin");
   
    readPeople(&people2,"people.bin");
   
    print(people2);
   
    printf("%s\n", isPeopleEq(people1,people2) ? "PEOPLE ARE SAME" : "PEOPLE ARE DIFFERENT!");
    printf("Making imputation\n");
   
    imputation(&people1);
   
    print(people1);
   
    return 0;
}
