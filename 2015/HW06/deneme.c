/*                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                   */
/*                  *           Derya KAPTAN             *                   */
/*                  *                                    *                   */
/*                  *             141044025              *                   */
/*                  *                                    *                   */
/*                  *             04/04/2016             *                   */
/*                  *                                    *                   */
/*                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                   */
/*                                                                           */
/*****************************************************************************/
/* Bu fonksiyon binary bir dosyadan verileri cekerek istenilen formatta yeni bir txt dosyasina yazar      */
/*****************************************************************************/
#include <stdio.h>
/*****************************************************************************/
/*                                                                           */
/*                           Struct Prototipleri                             */
/*                                                                           */
/*****************************************************************************/
/* Ogrenci numarasi, adi ve soyadi icin olusturulan struct yapisi            */
typedef struct 
{
	int id;
	char name[30];
	char surname[30]; 
}Student;

/*Ogretmenin derecesi, numarasi, adi ve soyadi icin olusturulan struct yapisi*/
typedef struct 
{
	char degree[30];
	int id;
	char name[30];
	char surname[30];
}Lecturers;

/* Dersin kodu, adi ve dersi veren ogretmenin numarasi icin olusturulan      */
/* struct yapisi                                                             */
typedef struct 
{
	int lectureCode;
	char lectureName[30];
	int lecturerId;
}Lectures;

/* Ders programinda  dersin adi, baslama saati, kac saat surecegi ve dersin  */
/* kodu icin olusturulan struct yapisi                                       */
typedef struct 
{
	char className[30];
	char day[30];
	int startTimeLecture;
	int duration;
	int lectureCode;	
}Schedule;

/* Dersi alan ogrencinin numarasi ve dersin kodu icin olusturulan struct     */
/* yapisi */
typedef struct 
{
	int studentId;
	int lectureCode;
}Courses;

/* Student struct ini student array degiskeni olusturarak tanimlanir         */
Student student[30];

/* Lecturers struct ini lecturers array degiskeni olusturarak tanimlanir     */
Lecturers lecturers[30];

/* Lectures struct ini lectures array degiskeni olusturarak tanimlanir       */
Lectures lectures[30];

/* Schedule struct ini schedule array degiskeni olusturarak tanimlanir       */
Schedule schedule[30];

/* Courses struct ini courses array degiskeni olusturarak tanimlanir         */
Courses courses[30];


int main()
{ 

	FILE *inPtr;  /* input.dat dosya                                         */
	FILE *outPtr; /* output.txt dosyasi                                      */
	
	int i;
	int j;
	int count1[20] = {0};  /* Hangi hocanin ayni dersi kac kez verdigi deger */
	int count2[20] = {0};  /* Hangi ogrencinin kac ders aldıgını veren deger */
	char day[10][10]; /*Ogrencinin derslerinin hangi gun oldugunu veren deger*/
	int studentSize = 0;  /* Ogrenci sayisi icin verilen deger               */
	int lecturersSize = 0; /* Ogretmen sayisi icin verilen deger             */
	int lecturesSize = 0; /* Ders sayisi icin verilen deger                  */
	int scheduleSize = 0; /* Ders programi icin verilen deger                */
	int coursesSize = 0;  /* Ders listesi icin verilen deger                 */
	
	outPtr = fopen( "output.txt" , "w" );
    /* input ve output dosyalarinin acilmasi                                 */
	if ( ( inPtr = fopen( "input.dat" , "rb" ) ) ==  NULL )
			printf("File open error!\n");
			
	else
	{	
		/* Ogrenci sayisinin dosyadan okunmasi                               */
		fread( &studentSize, sizeof( int ) , 1 , inPtr );
		printf("%d\n",studentSize );
		/* Ogrenci sayisi 0 dan buyukse ogrenci bilgerinin okunmasi          */
		if( studentSize > 0)
		{	
			/* Student struct inin dosyadan okunmasi                         */
			fread( student, sizeof( Student ), studentSize, inPtr);
			/* okunan degerlerin ekrana basilmasi                            */
			for ( i = 0 ; i < studentSize ; ++i )
			{
				printf("%d %s %s\n", student[i].id, 
					               student[i].name, 
					               student[i].surname);
			}	
		}	
		/* Ogretmen sayisinin dosyadan okunmasi                              */
		fread( &lecturersSize, sizeof( int ), 1 , inPtr );
		printf("%d\n", lecturersSize);
		/* Ogretmen sayisi 0 dan buyukse ogretmen bilgerinin okunmasi        */
		if( lecturersSize > 0)
		{	
			/* Lecturers struct inin dosyadan okunmasi                       */
			fread( lecturers, sizeof( Lecturers ), lecturersSize , inPtr);
			/* okunan degerlerin ekrana basilmasi                            */
			for ( i = 0 ; i < lecturersSize ; ++i )
			{
				printf("%s %d %s %s\n", lecturers[i].degree, 
					                    lecturers[i].id ,
					                    lecturers[i].name, 
					                    lecturers[i].surname);
			}	
		}
		
		/* Ders sayisinin dosyadan okunmasi                                  */
		fread( &lecturesSize, sizeof( int ), 1 , inPtr );
		printf("%d\n", lecturesSize);
		/* Ders sayisi 0 dan buyukse ders bilgilerinin okunmasi              */
		if( lecturesSize > 0)
		{	
			/* Lectures struct inin dosyadan okunmasi                        */
			fread( lectures, sizeof( Lectures ), lecturesSize, inPtr);
			/* okunan degerlerin ekrana basilmasi                            */
			for ( i = 0 ; i < lecturesSize ; ++i )
			{
				printf("%d %s %d\n", lectures[i].lectureCode, 
					                 lectures[i].lectureName, 
					                 lectures[i].lecturerId);
			}	
		}
		
		/* Ders programi liste sayisinin okunmasi                            */
		fread( &scheduleSize, sizeof( int ), 1 , inPtr );
		printf("%d\n", scheduleSize);
		/* Ders programi liste sayisi 0 dan buyukse bilgilerin okunmasi      */
		if( scheduleSize > 0)
		{	/* Schedule struct inin dosyadan okunmasi                        */
			fread( schedule, sizeof( Schedule ), scheduleSize, inPtr);
			/* okunan degerlerin ekrana basilmasi                            */
			for ( i = 0 ; i < scheduleSize ; ++i )
			{
				printf("%s %s %d %d %d\n", schedule[i].className, 
										   schedule[i].day, 
										   schedule[i].startTimeLecture, 
										   schedule[i].duration, 
										   schedule[i].lectureCode);
			}	
		}
		
		/* Ders listesi sayisinin dosyadan okunmasi                          */
		fread( &coursesSize, sizeof( int ), 1 , inPtr );
		printf("%d\n", coursesSize);
		/* Ders listesi sayisi 0 dan buyukse bilgilerin okunmasi             */
		if( coursesSize > 0)
		{	/* Courses struct ını dosyadan okunmasi                          */
			fread( courses, sizeof( Courses ), coursesSize, inPtr);
			/* okunan degerlerin ekrana basilmasi                            */
			for ( i = 0 ; i < coursesSize ; ++i )
			{
				printf("%d %d\n", courses[i].studentId, 
					              courses[i].lectureCode);
			}
		}	
		/* txt uzantili dosyaya bilgileri yazmak icin dosyayi kontrol eder*/
            if ( outPtr==  NULL )
                printf("File open error message!\n");
			else
            {
            	fprintf( outPtr , "Lecture-Lecturer\n" );
                printf("\nLecture-Lecturer\n");      
                /* count1 u hesaplamak icin*/
                

                /* bilgileri ekrana basmak icin*/
                for(i=0;i<lecturesSize;i++)          
                {
                    for(j=0; j<lecturesSize ;j++)
                    {
                        if(lectures[i].lecturerId == lecturers[j].id)     
                            printf("%s %s %s %d\n" , 
                            	                 lectures[i].lectureName,
                            	                 lecturers[j].name, 
                            	                 lecturers[j].surname, 
                            	                 count1[i] ); 
                    }   
                } 
                /* output.txt ye Lecture-Lecturer listesini yazar            */
                for(i=0;i<lecturesSize;i++)          
                {
                    for(j=0; j<lecturesSize ;j++)
                    {
                        if(lectures[i].lecturerId == lecturers[j].id)     
                			fprintf( outPtr ,"%s %s %s %d\n" , 
                				                       lectures[i].lectureName,
                				                       lecturers[j].name, 
                            	                       lecturers[j].surname, 
                            	                       count1[i] );
                	}
                }
				fprintf( outPtr , "\nStudent-Lecture\n" );
				printf("\nStudent-Lecture\n");

				for ( i = 0 ; i < coursesSize ; ++i )           
                {
                    for ( j = 0 ; j < coursesSize ; ++j )
                    {
                        if( student[i].id == courses[j].studentId )
                            count2[i]++;
                    }
                    
                }
				for ( i = 0; i < studentSize ; ++i )
				{
					printf("%d %s %s %d\n", student[i].id,
					                        student[i].name,
					                        student[i].surname,
					                        count2[i] );
				}
				/* output.txt ye Studen-Lecture listesini yazar              */
				for ( i = 0; i < studentSize ; ++i )
				{
					fprintf( outPtr , "%d %s %s %d\n", student[i].id,
					                                   student[i].name,
					                                   student[i].surname,
					                                   count2[i] );
				}
				
				fprintf( outPtr , "\nStudent-Day\n" );
				printf("\nStudent-Day\n");
				
				for ( i = 0 ; i < coursesSize ; ++i )
				{
					for ( j = 0 ; j < coursesSize ; ++j )
                    {
                        if( courses[i].studentId == courses[j].studentId )
                            count2[i]++;
                    }
				}

				for ( i = 0; i < studentSize ; ++i )
				{
					printf("%d %s %s\n", student[i].id,
					                     student[i].name,
					                     student[i].surname
					                            );
				}
				/* output.txt ye Student-Day listesini yazar                 */
				for ( i = 0; i < studentSize ; ++i )
				{
					fprintf( outPtr , "%d %s %s\n", student[i].id,
					                     student[i].name,
					                     student[i].surname
					                            );
				}			
		}		
		fclose( inPtr );
		fclose( outPtr ); 
	}
	return 0;	
}
int findSize( strct  x )
{
	int i ;
	int j;

	for ( i = 0 ; i < coursesSize ; i++ )           
    {
        for ( j = 0 ; j < coursesSize ; j++ )
       {
            if( x[i].y == courses[j].lectureCode )
               	count1[i]++;
        }
    }

}
