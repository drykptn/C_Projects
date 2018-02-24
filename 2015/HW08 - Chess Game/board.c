/*
In this homework, you will write a 2-player chess game using your hw#05.
*/
/*---------------------------------------------------------------------------*/
/* 	                                                                     */
/* HW08_141044025_Derya_Kaptan		                                     */
/*               		                                             */
/* --------------------------------------------------------------------------*/
/* Created on 23/04/2016 by Derya_Kaptan			             */
/* 									     */
/*									     */
/*---------------------------------------------------------------------------*/
/*                            Includes 				             */
/*---------------------------------------------------------------------------*/
#include<stdio.h>
#include <string.h>
#include<math.h>
#include<stdlib.h>
/*---------------------------------------------------------------------------*/
/*                              Defines                                      */
#define BOARD_SIZE 8
/*---------------------------------------------------------------------------*/
/*                           Function Prototypes        	             */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
 
char getPlayer( char * board , char sc, int sr);
/* This function checks rocks and  whether rocks can move from source cell   */
/* to target cell.                                                           */
int isPieceMovable(char *board, char sc, int sr, char tc, int tr);	                                          

/*This function will check whether a queen can move from source cell to the  */
/*target cell.                                                               */
int isQueenMovable(char *board , char sourceCol, int sourceRow, char targetCol, 
		           int targetRow);

/*This function will check whether a pwan can move from source cell to the   */
/*target cell.                                                               */
int isPawnMovable(char *board , char sourceCol, int sourceRow, char targetCol, 
		          int targetRow);
		  
/*This function will check whether a bishop can move from source cell to the */
/*target cell.                                                               */
int isBishopMovable(char *board , char sourceCol, int sourceRow, char targetCol, 
		            int targetRow);

/*This function will check whether a king can move from source cell to the   */
/*target cell.                                                               */
int isKingMovable(char *board, char sourceCol, int sourceRow, char targetCol, 
	 	          int targetRow);

/*This function will check whether a rook can move from source cell to the   */
/*target cell.                                                               */
int isRookMovable(char *board , char sourceCol, int sourceRow, char targetCol, 
		          int targetRow);

/*This function will check whether a knight can move from source cell to the */ 
/*target cell.                                                               */
int isKnightMovable(char *board, char sourceCol, int sourceRow, char targetCol, 
	 	            int targetRow);

/*This function will check whether the given cell is valid according to      */
/*the board sizes                                                            */
int isValidCell(char col, int row);
int isBlack(char currPlayer);
int isWhite(char currPlayer);

int checkRook(char *board,int target,int source , int lowerUpper );

int conversion(char col, int row);

/*This function will print the current state of the board as show above.     */
void printBoard(char *board);

int checkRock( char targetRock, int lowerOrUpperCase );
/*This function will take the row and column values of a specific cell on the*/ 
/*board.                                                                     */
void getPosition(char *col, int *row);

int isInCheck(char * board);
int controlKnight(char * board, int target );

char findCol( int value );

int controlKing(char * board, int target , int count);

int makeMove(char *board, char sc, int sr, char tc, int tr);

int controlCheck(char * board, int target );

int controlKnightPosibility(char * board, int target , int count);

/* This function initialized the board                                       */
void initBoard( char* board);
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

int main() {
    char board [BOARD_SIZE*BOARD_SIZE], empty;
    int player = 1; /* 1 white, 0 black */
    char sc,tc; /* source/target cols */
    int sr,tr; /* source/target rows */
    int moveStatus = 0;
    int checkStatus = 0;
    char currPlayer;

    initBoard(board);

    do {
        printBoard(board);
        printf("%s player move > ", player ? "White" : "Black");
        getPosition(&sc,&sr);
        scanf("%c", &empty);
        getPosition(&tc,&tr);
        scanf("%c", &empty);
        currPlayer = getPlayer(board, sc,sr);

        if(!isValidCell(sc,sr)) {
            printf("Source position is invalid\n");
            continue;
        }
        if(!isValidCell(tc,tr)) {
            printf("Target position is invalid\n");
            continue;
        }
        if((isBlack(currPlayer) && player) ||
           (isWhite(currPlayer) && !player)) {
            printf("Illegal piece. \n");
            continue;
        }

        moveStatus = makeMove(board,sc,sr,tc,tr);
    
        switch(moveStatus) {
            case 0:
                printf("Invalid move!\n");
                break;
            case 1:
                printf("Your king is in check!\n");
                ++checkStatus;
                break;
            case 4:
                printf("şah durumunda başka taş oynayamazsın");
                player = !player;
                checkStatus = 0;
                break;
            case 3:
                printf("Check!\n ");
            case 2:
                player = !player;
                checkStatus = 0;
                break;

        }
    } while(checkStatus < 2);
    printf("%s player WINS!\n", player ? "Black" : "White");
    return 0;
}
/* This function initializes the board.                                      */
void initBoard(char *board)
{  
	int i;
	char arr[64]= { 'r','n','b','q','k','b','n','r',
					'p','p','p','p','p','p','p','p',
					' ',' ',' ',' ',' ',' ',' ',' ',
					' ',' ',' ',' ',' ',' ',' ',' ',
					' ',' ',' ',' ',' ',' ',' ',' ',
					' ',' ',' ',' ',' ',' ',' ',' ',
					'P','P','P','P','P','P','P','P',
					'R','N','B','Q','K','B','N','R'};

	for (i = 0; i < 65; i += 1)
	{
		board[i]=arr[i];
	}
} 
/*tasin siyah olup olmadigini kontrol eder*/
int isBlack( char currPlayer )
{
	char arr[6]={"pqkbnr"};
	int i, result = 0;

	for( i = 0 ; i < 6 ; i++ )
	{
		if( arr[i] == currPlayer )
		{
			result = 0;
			i = 7;
		}
	}
	return result;
}   
/*tasin beyaz olup olmadigini kontrol eder*/
int isWhite( char currPlayer )
{
	char arr[6]={"PQKBNR"};
	int i, result = 0;

	for( i = 0 ; i < 6 ; i++ )
	{
		if( arr[i] == currPlayer )
		{
			result = 1;
			i = 7;
		}
	}
	return result;
}
/*board un col ve row una gore hangi tas oldugunu bulur*/
char getPlayer( char * board , char sourceCol, int sourceRow )
{
	int source;
	source = conversion ( sourceCol , sourceRow );
	return board[source];
}
/* kendi tasi olup olmadigini kontrol eder/ lowerorupper beyaz veya siyah olma 
durumuna bakar*/
int checkRock( char targetRock, int lowerOrUpperCase ) 
{     
	int i, result = 1;     
	char* arr;
	
	if( lowerOrUpperCase == 0 )
	{
		arr = "pqkbnr";
	}
	else
	{
		arr = "PQKBNR";
	}
	for( i = 0 ; i < 6 ; i++ )
	{
		if( arr[i] == targetRock )
		{
			result = 0;
			i = 7;
		}
	}
	return result;
}
/* girilen degerin board degerlerinden biri olup olmadigini 
kontrol eder*/
int isValidCell(char col, int row)
{
	char array[16]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
			        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	int i, result = 0;
	
	for ( i=0 ; i<16 ; i++ )
	{
		if ( col==array[i] )
		{
			if (row>=0 && row<=8 )
			{
				result = 1;
				i = 17;
			}
		}
	}
	return result;
}
/* board icin input alir*/
void getPosition(char *col, int *row)
{
	scanf("%c", col);
	scanf("%d", row);	
}
/* row ve col u kullanarak board da index i bulur*/
int conversion(char col, int row )
{	

	int m, r, result, convert;

	convert=(int)col;
/* ascii degerine gore harflerin degerini bulup modunu alir*/
	m=convert%97;		
	
	r=8-(row);
	result=m+r*8;
	
	return result;
}
/* board i print eder*/
void printBoard(char *board)
{
	int i, j;
	
	printf("  a b c d e f g h \n");
	printf("  - - - - - - - - \n" );
	for(i = 0; i < 8; i++)
	{
		printf("%d|", (8-i));	
		for( j = 0; j < 8; j++)
		{
		    if( j== 0)
			    printf("%c", board[i*8+j] );
		
		    else
		        printf(" %c", board[i*8+j] );
		
		}
		printf("|\n");
	}	
	printf("  - - - - - - - - \n");
	
}
/* board in indexini kontrol eder */
int checkBoard(char *board)
{
	/* find board's size */
	int len=(int)strlen(board);
	if ( len == 64 )
		return 1;
	else
	{
		printf("Board is not initialized");
		return 0;
	}
}
/* sah in tehdit altinda oldugu durumu kontrol eder*/
int isInCheck( char * board )
{	
	int  target;
/* beyaz sah in tehdit altinda oldugu durum*/
	for ( target = 0 ; board[ target ] != 'K' ; target++ );
	if( controlCheck( board , target ) == 1 )
		return 1;
/* siyah sah in tehdit altinda oldugu durum*/	
	for ( target = 0 ; board[ target ] != 'k' ; target++ );
	if ( controlCheck( board , target ) == 2 )
		return 2;
	return 0;
}
/* tasin oldugu index e gore bulundugu col u bulur*/
char findCol( int value )
{
	char col;
	int letter = value % 8;
	if ( letter == 0 )
		col= 'a';
	else if ( letter == 1 )
		col= 'b';
	else if ( letter == 2 )
		col= 'c';
	else if ( letter == 3 )
		col= 'd';
	else if ( letter == 4 )
		col= 'e';
	else if ( letter == 5 )
		col= 'f';
	else if ( letter == 6 )
		col= 'g';
	else if ( letter == 7 )
		col= 'h';
	return col;
}
/* sah in at haricindeki tehditlerini kontrol eder*/
int controlKing(char * board, int target , int count)
{
	int i, sourceCol, result = 0;
	char sourceRow;
	char targetCol;
	int targetRow;

	targetRow = target / 8;
	targetCol = findCol( target ); 

	for ( i = target + count ; board[ target ] != ' ' && 
	      i < 64 ; i = i + count )
	{
		sourceRow = i / 8 ;
		sourceCol = findCol( i );

		result = isPieceMovable( board , sourceCol , sourceRow ,
		         targetCol, targetRow);
		if ( result == 1 )
			 i = 65;
	}
	return result;
}
/* sah in beyaz veya siyah olma durumuna gore tum tehditleri kontrol eder*/
int controlCheck(char * board, int target )
{
	int targetRow;
	char targetCol;
	char man ;

	targetRow = target / 8;
	targetCol = findCol( target ); 
	man = getPlayer(board , targetCol, targetRow);
/* dikeyde asagi dogru*/
	if ( controlKing( board, target , 8) == 1 )
	{
		if( man == 'k' )
			return 2;
		else if( man == 'K' )
			return 1;
	}
/* dikeyde yukari dogru*/
	else if ( controlKing( board, target  , -8) == 1 )
	{
		if( man == 'k' )
			return 2;
		else if( man == 'K' )
			return 1;
	}
/*sag asagi capraz*/
	else if ( controlKing( board, target  , 8 + 1) == 1 )
	{
		if( man == 'k' )
			return 2;
		else if( man == 'K' )
			return 1;
	}
/*sol asagi capraz*/
	else if ( controlKing( board, target  , 8 - 1) == 1 )
	{
		if( man == 'k' )
			return 2;
		else if( man == 'K' )
			return 1;
	}
/*yukari sag capraz*/
	else if ( controlKing( board, target  , -8 + 1) == 1 )
	{
		if( man == 'k' )
			return 2;
		else if( man == 'K' )
			return 1;
	}
/*yukari sol capraz*/
	else if ( controlKing( board, target  , -8 - 1) == 1 )
	{
		if( man == 'k' )
			return 2;
		else if( man == 'K' )
			return 1;
	}
/* at kontrolu*/
	else if ( controlKnight( board, target ) == 1)
	{	
		if( man == 'k' )
			return 2;
		else if( man == 'K' )
			return 1;
	}
	return 0;
}
/* at in hareketine gore sah tehditlerini inceler*/
int controlKnight(char * board, int target )
{
/* 2 yukari 1 sol hareket*/
	if ( controlKnightPosibility(board , target, -16 -1 ) == 1 )
		return 1;
/* 2 yukari 1 sag hareket*/
	else if ( controlKnightPosibility(board , target, -16 +1 ) == 1 )
		return 1;
/* 1 yukari 2 sol */
	else if ( controlKnightPosibility(board , target, -2 -8 ) == 1 )
		return 1;
/* 1 yukari 2 sag*/
	else if ( controlKnightPosibility(board , target, 2 -8 ) == 1 )
		return 1;
/* 2 asagi 1 sag*/
	else if ( controlKnightPosibility(board , target, 16 +1 ) == 1 )
		return 1;
/* 2 asagi 1 sol*/
	else if ( controlKnightPosibility(board , target, 16 -1 ) == 1 )
 		return 1;
 /* 1 asagi 2 sag*/
	else if ( controlKnightPosibility(board , target, 8 +2 ) == 1 )
		return 1;
/* 1 asagi 2 sol*/
    else if ( controlKnightPosibility(board , target, 8 -2 ) == 1 )
		return 1;
	return 0;
}
/* at yapabilecegi hareketleri kontrol eder*/
int controlKnightPosibility(char * board, int target , int count)
{
	int sourceCol, targetCol;
	char sourceRow, targetRow;
	
	targetCol = target  / 8 ;
	targetRow = findCol( target );

	sourceRow = ( target + count ) / 8;
	sourceCol = findCol(target + count );

	if ( isPieceMovable( board , sourceCol , sourceRow , targetCol ,
	                     targetRow ) == 1 )
		return 1;	
	return 0;
}
/* butun taslarin hamlelerini kontrol eder/source-destination*/
int isPieceMovable( char *board, char sc, int sr, char tc, int tr)
{

	char targetCol =tc, sourceCol = sc;
	int targetRow=tr, sourceRow=sr, source, result;
	
	result=checkBoard( board );
	
/* tahta initiliazed edilmisse */
	if ( result != 0 )
	{
		/* conversion fonk ile index i bulur*/
		source = conversion(  sourceCol, sourceRow  );

		if ( board[source]=='p' || 
		     board[source]=='P' )
		{
			result=isPawnMovable( board ,sourceCol, sourceRow, 
			                      targetCol, targetRow);
		}
		else if ( board[source]=='r' || 
		          board[source]=='R' )
		{
			result=isRookMovable( board, sourceCol, sourceRow, 
			                      targetCol, targetRow);
		}
		else if ( board[source]=='n' || 
		          board[source]=='N' )
		{
			result=isKnightMovable( board, sourceCol, sourceRow, 
			                        targetCol, targetRow);
		}
		else if ( board[source]=='k' || 
		          board[source]=='K' )
		{
			result=isKingMovable( board, sourceCol, sourceRow, 
			                      targetCol, targetRow);
		}
		else if ( board[source]=='b' || 
		          board[source]=='B' )
		{
			result=isBishopMovable( board, sourceCol, sourceRow, 
			                        targetCol, targetRow);
		}
		else if ( board[source]=='q' || 
		          board[source]=='Q' )
		{
			result=isQueenMovable( board, sourceCol, sourceRow, 
			                       targetCol, targetRow);
		}
	}
	return result;
}
/* sah durumu olmadigi surece hamle yapar*/
int makeMove(char *board, char sc, int sr, char tc, int tr)
{
	int isCheck = 0, target, source;
	char temp, temp2, rock;

	source = conversion( sc, sr );
	target = conversion( tc, tr);
	isCheck = isInCheck( board );
	rock = getPlayer( board , sc, sr );

	/*şah durumunda bir taşı varken başka taş oynama durumu*/
	if ( (isBlack ( rock ) == 0 && isCheck == 2 && board[source] != 'k' ) 
		|| ( isWhite(rock) == 1 && isCheck == 1 && 
		     board[source] != 'K'))
		return 4;
	if ( isPieceMovable( board , sc, sr, tc, tr) == 0 )
		return 0;

	temp2 = board[target]; 
	temp = board[ source ];
	board[ source ] = ' ';
	board[ target ] = temp ;

	if( isInCheck( board ) != 0 )
	{	
		board[ source ] = temp;
		board[ target ] = temp2;
		return 1;
	}
	if ( (isBlack(rock) == 0 && isInCheck(board) == 1 ) || 
		 (isWhite(rock) == 1 && isInCheck(board) == 2 ))
		return 3;
	return 2;
}
/*piyonun hareketini kontrol eder*/
int isPawnMovable(char *board , char sourceCol, int sourceRow, char targetCol, 
int targetRow)
{
	char rock; 
	int source, target, result = 0;
	
	source=conversion( sourceCol, sourceRow );
	target=conversion( targetCol, targetRow);

	rock=board[source];

	if( rock=='p' )
	{
		if((source + 8) < (int)strlen(board) && board[source + 8] == ' ' 
		   &&  (source + 8) == target )
		{
			/*piyonun önü boşsa*/
			result = 1;
			
		}
		/* ilk harekette 2 hamle yapmasini kontrol eder*/
		else if ( sourceRow == 7 && (source + 16) < (int)strlen(board) 
		          && board[source + 16] == ' ' 
		   &&  (source + 16) == target  )
		{
			result = 1;
		}
		else if( (source + 8 + 1) < (int)strlen(board) )
		{
			/*çapraz sağ da taş varsa*/
			if( ( board[(source + 8) + 1] ) != ' ' && 
			      checkRock((board[(source + 8) + 1]), 0) == 1 &&
			      (source+8+1) == target )
			{
				result = 1;
				/*çapraz solda taş varsa*/
			}
			else if( board[(source + 8 - 1)] != ' ' && 
			         checkRock((board[(source + 8) - 1]), 0) == 1 && 
			         (source + 8 - 1) == target )
			{
				result = 1;
			}
		}
	}
	if( rock=='P' )
	{
		/* piyonun onu bossa*/
		if( (source - 8) >= 0 && board[source - 8] == ' ' && 
		    (source - 8) == target)
		{
			result = 1;
		}
		/* ilk harekette piyonun 2 hamle yapmasini saglar*/
		else if ( sourceRow == 2 && (source - 16) < (int)strlen(board) 
		          && board[source - 16] == ' ' 
		   &&  (source - 16) == target  )
		{
			result = 1;
		}
		/*çapraz sağ da taş varsa*/
		else if( (source - 8 + 1) >= 0 &&  
		         ( board[ ( source - 8 ) + 1 ] ) != ' ' && 
		         (source - 8 + 1) == target  && 
		         checkRock((board[(source - 8) + 1]), 1) == 1)
		{
				result = 1;
		}
		/*çapraz solda taş varsa*/
		else if((source - 8 - 1) >= 0 && 
			board[(source - 8 - 1)] != ' ' && 
			checkRock((board[source - 8 - 1]), 1) == 1 && 
			(source - 8 - 1) == target )
		{
			result = 1;
		}
	}
	return result;
}
/* kalenin hamlelerini inceler*/
int isRookMovable( char *board , char sourceCol, int sourceRow, char targetCol, 
                   int targetRow )
{
	char rock; 
	int source, target, result = 0;
	
	source = conversion( sourceCol, sourceRow );
	target = conversion( targetCol, targetRow);
	
	rock = board[ source ];
	/* queen icinde ayni islemi tekrar kullanir */
	if ( rock == 'r' || rock == 'q')
	{
		result = checkRook(board, target, source, 0);
	}
	else if ( rock == 'R' || rock == 'Q')
	{
		result = checkRook(board, target, source, 1);
	}
	return result;
}
/* sah in hamlelerini inceler*/
int isKingMovable(char *board, char sourceCol, int sourceRow, char targetCol, 
	 	    int targetRow)
{
	char rock; 
	int source, target, result = 0;
	
	source = conversion( sourceCol, sourceRow );
	target = conversion( targetCol, targetRow);
	
	rock = board[ source ];
	if ( rock == 'k')
	{	
		/*Şahın önü boş veya doluysa*/
		if ( ( source + 8 ) < (int)strlen( board ) && 
		     ( source + 8) == target &&
		     checkRock((board[source + 8 ]), 0) == 1)
		{ 
		    	result = 1;
		}
		/*arkası boş veya doluysa*/
		else if ( ( source - 8 ) >= 0 && 
		          ( source - 8 ) == target &&
			  checkRock((board[source - 8 ]), 0) == 1)
		{ 
		    	result = 1;
		}
			
		/*çapraz ön sağda taş varsa veya boşsa*/		
		else if ( ( source + 8 + 1 ) < (int)strlen( board ) &&  
		          ( source + 8 + 1 ) == target &&
		          checkRock((board[source + 8 + 1 ]), 0) == 1)
		{ 
		    	result = 1;
		}

		/*çapraz solda taş varsa veya boşsa		*/
		else if ( ( source + 8 - 1 ) < (int)strlen( board ) &&  
		          ( source + 8 - 1 ) == target &&
			  checkRock((board[source + 8 - 1 ]), 0) == 1 )
		{ 
		    	result = 1;
		}

		/*çapraz arka sağda taş varsa veya boşsa*/	
		else if ( ( source - 8 + 1 ) >= 0 &&  
		          ( source - 8 + 1 ) == target &&
		           checkRock((board[source - 8 + 1 ]), 0) == 1 )
		{ 
		     	result = 1;
		}

		/*çapraz solda taş varsa veya boşsa		*/
		else if ( ( source - 8 - 1 ) >= 0 &&  
		          ( source - 8 - 1 ) == target &&
		          checkRock((board[source - 8 - 1 ]), 0) == 1)
		{ 
		    	result = 1;
		}
	}
	else if ( rock == 'K')
	{	
		/*Şahın önü boş veya doluysa*/
		if ( ( source - 8 ) >= 0 && ( source - 8 ) == target &&
		     checkRock((board[source - 8 ]), 1) == 1 )
			result = 1;
	
		/*arkası boş veya doluysa*/
		else if ( ( source + 8 ) < (int)strlen( board ) && 
		          ( source + 8 ) == target &&
		          checkRock((board[source + 8 ]), 1) == 1)
			result = 1;	
	
		/*çapraz ön sağda taş varsa veya boşsa		*/
		else if ( ( source - 8 + 1 ) >= 0 &&  
		          ( source - 8 + 1 ) == target &&
		          checkRock((board[source - 8 + 1 ]), 1) == 1)
			result = 1;
	
		/*çapraz solda taş varsa veya boşsa		*/
		else if ( ( source - 8 - 1 ) >= 0 &&  
		          ( source - 8 - 1 ) == target &&
		          checkRock((board[source - 8 - 1]), 1) == 1)
			result = 1;
	
		/*çapraz arka sağda taş varsa veya boşsa		*/
		else if ( ( source + 8 + 1 ) < (int)strlen( board ) &&  
		          ( source + 8 + 1 ) == target &&
		          checkRock((board[source + 8 ]), 1) == 1)
			result = 1;
	
		/*çapraz solda taş varsa veya boşsa		*/
		else if ( ( source + 8 - 1 ) < (int)strlen( board ) &&  
		          ( source + 8 - 1 ) == target &&
		          checkRock((board[source + 8 ]), 1) == 1)
			result = 1;
	}
	return result;	
}
/*atin hamlelerini inceler*/
int isKnightMovable(char *board, char sourceCol, int sourceRow, char targetCol, 
	 	   int targetRow)
{
	char rock; 
	int source, target, result = 0;

	source = conversion(  sourceCol, sourceRow  );
	target = conversion( targetCol, targetRow );
	
	rock = board[ source ];
	if ( rock == 'n')
	{
		/*ön sağ hamle*/
		if ( ( source + 16 + 1 ) < (int)strlen( board ) && 
		     ( source + 16 + 1 ) == target &&
		       checkRock((board[source + 16 + 1 ]), 0) == 1) 
			result = 1;		    

		/*ön sol hamle*/
		else if ( ( source + 16 - 1 ) < (int)strlen( board ) && 
		          ( source + 16 - 1 ) == target &&
		          checkRock((board[source + 16 - 1 ]), 0) == 1) 
			result = 1;	    

		/*arka sağ hamle*/
		else if ( ( source - 16 + 1) >= 0 && 
		          ( source - 16 + 1 ) == target &&
		          checkRock((board[source - 16 + 1 ]), 0) == 1) 
			result = 1;
		     
		/*arka sol hamle  */   
		else if ( ( source - 16 - 1 ) >= 0 && 
		          ( source - 16 - 1 ) == target &&
		          checkRock((board[source - 16 - 1 ]), 0) == 1) 	
			result = 1;
	
		/*yatay sağ ön hamle*/
		else if ( ( source + 2 + 8) < (int)strlen( board ) && 
		          ( source + 2 + 8) == target &&
		          checkRock((board[source + 2 + 8 ]), 0) == 1)  
			result = 1;  
		
		/*yatay sağ arka hamle*/
		else if ( ( source + 2 - 8 ) >= 0 && 
		          ( source + 2 - 8) == target &&
		          checkRock((board[source + 2 - 8 ]), 0) == 1) 
			result = 1;
			
		/*yatay sol ön hamle*/
		else if ( ( source - 2 + 8) < (int)strlen( board ) && 
		          ( source - 2 + 8) == target &&
		          checkRock((board[source - 2 + 8 ]), 0) == 1) 
			result = 1;		     
		     
		/*yatay sol arka hamle*/     
		else if ( ( source - 2 - 8 ) >= 0 && 
		          ( source - 2 - 8 ) == target &&
		          checkRock((board[source - 2 - 8 ]), 0) == 1) 
			result = 1;	
	}
	if ( rock == 'N')
	{
		/*ön sağ hamle*/
		if ( ( source - 16 + 1 ) >= 0 && 
		          ( source - 16 + 1 ) == target &&
		          checkRock((board[source - 16 + 1 ]), 1) == 1) 
			result = 1;		    

		/*ön sol hamle*/
		else if ( ( source - 16 - 1 ) >= 0 && 
		          ( source - 16 - 1 ) == target &&
		          checkRock((board[source - 16 - 1 ]), 1) == 1) 
			result = 1;	    

		/*arka sağ hamle*/
		else if ( ( source + 16 + 1 ) < (int)strlen( board ) && 
		          ( source + 16 + 1 ) == target &&
		          checkRock((board[source + 16 + 1 ]), 1) == 1) 
			result = 1;
		     
		/*arka sol hamle  */   
		else if ( ( source + 16 - 1 ) < (int)strlen( board ) && 
		          ( source + 16 - 1 ) == target &&
		          checkRock((board[source + 16 - 1 ]), 1) == 1) 	
			result = 1;
	
		/*yatay sağ ön hamle*/
		else if ( ( source - 2 + 8) < (int)strlen( board ) && 
		          ( source - 2 + 8) == target &&
		          checkRock((board[source - 2 + 8 ]), 1) == 1) 
			result = 1;  
		
		/*yatay sağ arka hamle*/
		else if ( ( source + 2 + 8) < (int)strlen( board ) && 
		          ( source + 2 + 8) == target &&
		          checkRock((board[source + 2 + 8 ]), 1) == 1) 
			result = 1;
			
		/*yatay sol ön hamle*/
		else if ( ( source + 2 - 8 ) >= 0 && 
		          ( source + 2 - 8 ) == target &&
		          checkRock((board[source + 2 - 8 ]), 1) == 1) 
			result = 1;		     
		     
		/*yatay sol arka hamle*/     
		else if (( source - 2 - 8 ) >= 0 && 
		         ( source - 2 - 8 ) == target &&
		          checkRock((board[source - 2 - 8 ]), 1) == 1)
			result = 1;
	}
	return result;
}
/*fil in hamlelerini inceler*/
int checkBishop(char *board,int target,int source , int lowerUpper )
{
	int i, result = 0, k = abs ( target - source );
	
	/*sağ çapraz için*/
	if ( k % 9 == 0 )
	{
		/*asagidan yukari hamle yaparken*/
		if ( target > source )
		{
			for ( i = source + 9 ;  i <= target ;  i += 9 )
			{
				if ( i < target && board[i] != ' ' )
				{
					result = 0;
					i = target + 1;
				}
				else if ( target == i && checkRock(board[i],
				          lowerUpper )==1)
					result = 1;
			}
		}
		/*yukaridan asagi hamle yaparken*/
		else if ( source > target )
		{
			for ( i = source - 9 ;  i >= target ;  i -= 9 )
			{
				if ( i > target && board[i] != ' ' )
				{
					result = 0;
					i = target - 1;
				}
				else if ( target == i && 
			                  checkRock(board[i],lowerUpper )==1)
					result = 1;
			}
		}
	}
	/*sol çapraz hamle*/
	if ( k % 7 == 0 )
	{
		/* asagidan yukari hamle yaparken*/
		if ( target > source )
		{
			for ( i = source + 7 ;  i <= target ;  i += 7 )
			{
				if ( i < target && board[i] != ' ' )
				{
					result = 0;
					i = target + 1;
				}
				else if ( target == i && 
				          checkRock(board[i],lowerUpper )==1 )
					result = 1;	
			}
		}
		/*yukaridan asagi hamle yaparken*/
		else if ( source > target )
		{
			for ( i = source - 7 ;  i >= target ;  i -= 7 )
			{
				if ( i > target && board[i] != ' ' )
				{
					result = 0;
					i = target - 1;
				}
				else if ( target == i && 
				          checkRock(board[i],lowerUpper )==1 )
					result = 1;
			}
		}
	}
	return result;
}
/* fil ve vezir in capraz hareketini inceler*/
int isBishopMovable(char *board , char sourceCol, int sourceRow, char targetCol, 
		  int targetRow)
{
	char rock; 
	int source, target, result = 0;
	
	source = conversion(  sourceCol, sourceRow  );
	target = conversion( targetCol, targetRow );
	
	rock = board[ source ];
	if ( rock == 'b' || rock == 'q')
	{	
		result = checkBishop( board, target, source , 0 );	
	}
	else if ( rock == 'B' || rock == 'Q')
	{
		result = checkBishop( board, target, source , 1 );	
	}
	return result;
}	
/*vezir i kale ve fil yardimiyla bulur*/
int isQueenMovable(char *board , char sourceCol, int sourceRow, char targetCol, 
		           int targetRow)
{
	int result = 0;
	result=isBishopMovable( board , sourceCol, sourceRow, targetCol, 
		         targetRow);
	if(result==0)
		result=isRookMovable( board , sourceCol, sourceRow, targetCol, 
                       targetRow );                       
	return result;
}
/* kalenin hamlelerini inceler*/
int checkRook(char *board,int target,int source , int lowerUpper )
{
	int k, i, result = 0;
	/*dikey için*/
	k = abs( target - source );
	if ( k % 8 == 0 )
	{
		/*asagidan yukari hareketi inceler*/
		if ( target > source )
		{
			for ( i = source + 8 ;  i <= target ;  i += 8 )
			{
				if ( i < target && board[i] != ' ' )
				{
					result = 0;
					i = target + 1;
				}
				else if ( target == i && 
				checkRock(board[i],lowerUpper )==1)		
					result = 1;
			}
		}
		/*yukaridan asagi hareketi inceler*/
		else if ( source > target )
		{
			for ( i = source - 8 ;  i >= target ;  i -= 8 )
			{
				if ( i > target && board[i] != ' ' )
				{
					result = 0;
					i = target - 1;
				}
				else if ( target == i && 
				checkRock(board[i],lowerUpper )==1 )		
					result = 1;
			}
		}	
	}
	/*yatay hamle*/
	if ( k < 8 && (target / 8) == (source / 8))
	{
		/*sağ hamle*/
	      	if ( target > source )
		{
			for( i = source+1 ; i <= target  ; i++ )
			{	
				if ( i < target && board[i] != ' ' )
				{
					result = 0;
					i = target + 1;
				}
				else if ( target == i && 
				checkRock(board[i],lowerUpper )==1 )		
					result = 1;
			}
		}
		/*sol hamle*/
		else if ( source > target )
		{
			for( i = source - 1 ; i >= target  ; i-- )
			{
				if ( i > target && board[i] != ' ' )
				{
					result = 0;
					i = target - 1;
				}
				else if ( target == i && checkRock(board[i],
				          lowerUpper )==1 )
					result = 1;
			}
		}		
	}	
	return result;
}
