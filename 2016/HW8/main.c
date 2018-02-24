#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAMELEN 50
#define MAXRECORD 500

typedef struct Person {
    int id;                
    char name[NAMELEN];       
} Person;

typedef struct record_s {
    int id; // telefon numarasi 1,2
    char number[NAMELEN];         // tel nosu 
} Record;

typedef struct Records_s {
    Record data[MAXRECORD];      
    int size;        //kac tane tel no su var           
} Records;

typedef struct people_s {
    Person data[MAXRECORD];    // insanlarin kayitlari
    int size;  //kac tane insan var (dosya size ı)
} People;


int findSizeOfFile(char* filename);

/* ========== IMPLEMENT THE FUNCTIONS BELOW ========== */
/*
	Write Records.data array to the filename.
	Note that file should be binary.
*/
void writeRecords(Records records, char* filename) {

    FILE *fb;
    int line;
    line = 0;
    
    fb = fopen(filename, "wb");
    if( fb == NULL ){
        printf("File is not open -- %s!\n", filename);
        exit(1);
    }
    
    while( records.size != line ){
        fwrite(&records.data[line].id, sizeof(records.data[line].id), 1, fb);
        fwrite(records.data[line].number, sizeof(records.data[line].number), 1, fb);
        line++;
    }
    
    fclose(fb);
}

/*
    Reads Record structs from the binary file and places them to Records.data array.
    Note that the number of Record structs in the file is unkown.
*/
void readRecords(Records *records, char* filename) {

    FILE *fb;
    int line;
    Record tempR;
    line = 0;
    
    fb = fopen(filename, "rb");
    if( fb == NULL ){
        printf("File is not open -- %s!\n", filename);
        exit(1);
    } 
    
    while(fread(&tempR.id, sizeof(tempR.id), 1, fb) == 1)
    {
        fread(tempR.number, sizeof(tempR.number), 1, fb);
        strcpy(records->data[line].number, tempR.number);
        records->data[line].id = tempR.id;
        line++;
    }
    
    records->size = line;
    fclose(fb);

}

/*
    Write People.data array to the filename.
    Note that file should be binary.
*/
void writePeople(People people, char* filename) {
    FILE *fb;
    int line;
    line = 0;
    
    fb = fopen(filename, "wb");
    if( fb == NULL ){
        printf("File is not open -- %s!\n", filename);
        exit(1);
    }
    
    while( people.size != line ){
        fwrite(&people.data[line].id, sizeof(people.data[line].id), 1, fb);
        fwrite(people.data[line].name, sizeof(people.data[line].name), 1, fb);
        line++;
    }
        
    fclose(fb);
    
}

/*
	Reads Person structs from the binary file and places them to People.data array.
	Note that the number of Person structs in the file is unkown.
*/
void readPeople(People *people, char* filename) {

    FILE *fb;
    Person tempP;
    int line;
    line = 0;
    
    fb = fopen(filename, "rb");
    if( fb == NULL ){
        printf("File is not open -- %s!\n", filename);
        exit(1);
    }      
    
    while(fread(&tempP.id, sizeof(tempP.id), 1, fb) == 1)
    {
        fread(tempP.name, sizeof(tempP.name), 1, fb);
        strcpy(people->data[line].name, tempP.name);
        people->data[line].id = tempP.id;
        line++;
    }
    
    people->size = line;
    fclose(fb);

}

/**
  * Reads the input file and constructs People and Records structs.
  	Note that each Record in Records is unique (should not present multiple times).
  */
void read(char* filename, People *people, Records *records) {
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
        
        /* read the size of cell phone */
        fscanf(fptr, "%s", str);
        records->size += (atoi(str));
        
        /* read for all cell phone */
        while(records->size != count){
            fscanf(fptr, "%s", records->data[count].number);
            records->data[count].id = people->data[line].id;
            count++;
        }
        line++;
    }
     
    fclose(fptr);
}

int findSizeOfFile(char* filename){
    FILE *fptr;
    int lines;
    char ch;
    lines = 0;
    
    fptr = fopen(filename,"r");
    while( (ch = fgetc(fptr)) != EOF)
    {
        if (ch == '\n')  
            lines++; 
    }
    fclose(fptr);
    lines++;
    return lines;
}

/* ========== IMPLEMENT THE FUNCTIONS ABOVE ========== */

void print(People people, Records records) {
	int i,j,found = 0;
	/* header */
	printf("%-5s %-30s %-20s\n", "ID","NAME","NUMBER(s)");
	/* line */
	for (i = 0; i < 57; ++i)
		printf("-");
	printf("\n");

	for (i = 0; i < people.size; ++i) {
		found = 0;
		printf("%-5d %-30s", people.data[i].id, people.data[i].name);
		for (j = 0; j < records.size; ++j) {
                   	if(records.data[j].id == people.data[i].id) {
                            
                            if(found)
                                    printf("%36s", "");
				printf("%-20s\n", records.data[j].number);
				found = 1;
			}
		}
		printf("\n");
	}

}

int isPeopleEq(People ppl1, People ppl2) {
	int i;
	if(ppl1.size != ppl2.size)
		return 0;
	for (i = 0; i < ppl1.size; ++i)
		if(strcmp(ppl1.data[i].name,ppl2.data[i].name) ||
			ppl1.data[i].id != ppl2.data[i].id)
			return 0;
	return 1;
}

int isRecordsEq(Records rec1, Records rec2) {
	int i;
	if(rec1.size != rec2.size)
		return 0;
	for (i = 0; i < rec1.size; ++i)
		if(strcmp(rec1.data[i].number,rec2.data[i].number) ||
			rec1.data[i].id != rec2.data[i].id)
			return 0;
	return 1;
}

int main(int argc, char** argv) {
	People people1,people2;
	Records records1,records2;
	people1.size = 0;
	records1.size = 0;
        
	read(argv[1],&people1, &records1);
        print(people1, records1);
	writePeople(people1,"people.bin");
	writeRecords(records1,"records.bin");
	readRecords(&records2,"records.bin");
	readPeople(&people2,"people.bin");
	print(people2, records2);
	printf("%s\n", isRecordsEq(records1,records2) ? "RECORDS ARE SAME" : "RECORDS ARE DIFFERENT!");
	printf("%s\n", isPeopleEq(people1,people2) ? "PEOPLE ARE SAME" : "PEOPLE ARE DIFFERENT!");

	return 0;
}
