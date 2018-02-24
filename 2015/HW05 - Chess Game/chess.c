/*
You will write a chess simulator that performs basic operations in a game. We have an 8x8 board of
which the columns and rows are represented by characters and integers, respectively as shown
below.
You will use lowercase and uppercase letters for the black and white users, respectively. You will
display the board in the following form:
You will store the board in a character array of size 64 and perform all of the operations using
pointers.
The three main operations that can be performed in this stage of the game are 1) Initializing theboard by placing the pieces in the correct order for both users, 2) Checking whether the piece can
move from its position to a specified cell 3) Displaying the board 4) Exit.
A sample run of the program is given you as an attachment in the file “example_run.txt”. Note that
in the example run, the last two “movable” commands (command number:2) fails because of the
invalid inputs. The program will accept command from the user until he want to exit by entering
command number 4.
To execute these commands you will need several helper functions as given below.
void getPosition(char *col, int *row) : This function will take the row and column values of a
specific cell on the board.
int isValidCell(char col, int row) : This function will check whether the given cell is valid
according to the board sizes and returns 1 if it is valid, otherwise 0.
void printBoard(char *board) : This function will print the current state of the board as show
above.
int isPieceMovable(char *board) : It asks the user the source and target positions and check
whether the piece in the source cell can be movable to the target cell. If the piece is movable it
returns 1, otherwise 0. There are two things to consider while deciding a move is valida or not: 1)
Whether the move is valid according to the general rules of the game, i.e. if there is another piece of
the same player on the target cell, the move is not valid. 2) Whether the move is valid dependsing
on the type of the piece in the source cell and the state of the board, e.g. a rock can not move to a
cell if there is another piece on its path. Please note that, in this homework, you will not move any
piece but only check the validness of the move.
int isKnightMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow):
This function will check whether a knight can move from source cell to the target cell according to
the rules of the game.
int isRookMovable(char *board , char sourceCol, int sourceRow, char targetCol, int targetRow):
This function will check whether a rook can move from source cell to the target cell.
...
The functions for other type of the pieces are similar and you will write each of them. For
simplicity, assume that pawns always move one square straight forward.
The main function is provided you below to guide you writing your functions. The emptyBuffer()
function is necessary to get rid of remnants of a command that could not be executed. For example,
before initializing the board, if the user wants to execute the following command
>2 a5 b7
to check the movableness of the piece, the command cannot be executed. The arguments a5 and b7
become useless and should be read to empty the input buffer.
*/
#include<stdio.h>


int conversion( char *col, int *row );
/*This function will take the row and column values of a specific cell on the 
board.*/
void getPosition( char *col, int *row );

/*This function will check whether the given cell is valid
according to the board sizes*/
int isValidCell( char col, int row );

/*This function will print the current state of the board as show
above.*/
void printBoard( char *board );

int isPieceMovable( char *board );

void emptyBuffer();


/*This function will check whether a knight can move from source cell to the 
target cell according to the rules of the game*/
int isKnightMovable( char *board, char sourceCol, int sourceRow, char targetCol, 
int targetRow );

/*This function will check whether a rook can move from source cell to the 
target cell.*/
int isRookMovable( char *board , char sourceCol, int sourceRow, char targetCol, 
int targetRow );


void emptyBuffer()
{
	while ( getchar() != '\n' );
}
int main()
{
	char board [64];
	int initComplete = 0;
	char empty;

	int command;
	scanf("%d", &command);

	while(command!=4)
	{
		switch(command)
		{
			case 1: initBoard(board); 
				initComplete = 1; 
				printf("OK\n");
				break;
			case 2: 
				/*Read space character after command number*/
				scanf("%c", &empty);
				if (initComplete)
				{
					if( isPieceMovable(board) )
						printf("YES\n");
					else
						printf("NO\n");
				}
				else
				{  
					printf("Board is not initialized!\n");
					emptyBuffer();
				}
				break;
			case 3: 
				if (initComplete)
					printBoard(board);
				else  
					printf("Board is not initialized!\n");
					emptyBuffer();
				break;

			default: 
				printf("Invalid command!\n"); emptyBuffer();
				break;

		}	
		
		scanf("%d", &command);
	
	}
	return 0;
}
void printBoard(char *board)
{
	int i, j;
	
	printf("   a b c d e f g h \n");
	printf("   - - - - - - - - \n" );
	for(i = 0; i < 8; i++)
	{
		printf("%d| ", (8-i));	
		for( j = 0; j < 8; j++)
		{
			printf("%c ", board[i*8+j] );
		}
		printf("|\n");
	}

	printf("   - - - - - - - - \n");
	
}
void getPosition(char *col, int *row)
{
	scanf(" %c&", col);
	scanf(" %d&", row);	
}

int conversion(char *col, int *row )
{	
	char sourceCol, targetCol;
	int m, r, i, n, k, source, convert1, convert2; 
	int sourceRow, targetRow, target;
	int array[8]= {97, 98, 99, 100, 101, 102, 103, 104}; 
	
	getPosition( &sourceCol, &sourceRow );
	
	getPosition( &targetCol, &targetRow );
	
	
	convert1=(int)sourceCol;
	
	for ( i=0 ; i<8 ; i++ )
	{
		if ( convert1==array[i] )
		{
			m=convert1%97;		
		}
	}
	
	r=8-(sourceRow);
	source=m+r*8;
	
	convert2=(int)targetCol;
	
	for ( i=0 ; i<8 ; i++ )
	{
		if ( convert2==array[i] )
		{
			m=convert2%97;		
		}
	}
	
	r=8-(targetRow);
	target=m+r*8;
}

//tekrar kontrol et!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


int isValidCell(char col, int row)
{
	char array[8]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
	int i;
	
	
	if( col>=array[0] && col<=array[7] && row>=0 && row<=8 )
	{
		printf("yes");

	}
	else
		return 0;
}

int isPieceMovable( char *board , char sourceCol, int sourceRow, char targetCol, 
int targetRow )
{
	char col;
	int row, source, target, i;
	
	sourceCol=col;
	sourceRow=row;
	
	conversion(&col, &row);
	
	printf("%d ", conversion(&col, &row));
	
	for( i=0 ; i<64 ; i++ )
	{
		source = i;
	
		if( board[i]=='p' || board[i]=='P' )
		{
			isPwanMovable( board, sourceCol, sourceRow, targetCol, 
				       targetRow);
		}
		else if( board[i]=='r' || board[i]=='R' )
		{
			isRookMovable( board, sourceCol, sourceRow, targetCol, 
				       targetRow);
		}
		else if( board[i]=='n' || board[i]=='N' )
		{
			isKnightMovable( board, sourceCol, sourceRow, targetCol, 
				         targetRow);
		}
		else if( board[i]=='k' || board[i]=='K' )
		{
			isKingMovable( board, sourceCol, sourceRow, targetCol, 
				       targetRow);
		}
		else if( board[i]=='b' || board[i]=='B' )
		{
			isBishopMovable( board, sourceCol, sourceRow, targetCol, 
				         targetRow);
		}
		else if( board[i]=='q' || board[i]=='Q' )
		{
			isQueenMovable( board, sourceCol, sourceRow, targetCol, 
				        targetRow);
		}

	}

}
int isKingMovable(char *board, char sourceCol, int sourceRow, char targetCol, 
	 	    int targetRow)
{
	if( rock == 'k')
	{	

		//Şahın önü boş veya doluysa
		if( board[ source +=8 ] == ' ' || board[ source +=8 ] != ' ')
		{
			if( (source += 8) == target )
				printf("YES");
			else if( (source += 8) != target )
				printf("NO");	
		}
		//arkası boş veya doluysa
		else if( board[ source -=8 ]== ' ' || board[ source -=8 ]!= ' ')
		{
			if( (source -= 8) == target )
				printf("YES");
			else if( (source -= 8) != target )
				printf("NO");	
		}
		//çapraz ön sağda ve solda taş varsa veya boşsa		
		else if( (board[ ( source += 8 ) += 1 ] ) != ' ' || 
		          board[ ( source += 8 ) += 1 ] ) == ' ' ||
		          board[ ( source += 8 ) -= 1 ] ) == ' ' || 
		          board[ ( source += 8 ) -= 1 ] ) != ' ' )
		{
			source = (source += 8 );	
			
			if( ( source += 1 ) == target || ( source -= 1 ) == target )
				printf("YES");
			else if( source != target )
				printf("NO");	
		}	
		
		//çapraz arka sağda ve solda taş varsa veya boşsa		
		else if( (board[ ( source -= 8 ) += 1 ] ) != ' ' ||
		          board[ ( source -= 8 ) += 1 ] ) == ' ' ||
		          board[ ( source -= 8 ) -= 1 ] ) == ' ' ||
		          board[ ( source -= 8 ) -= 1 ] ) != ' ' )
		{	
			source = (source -= 8);	
			
			if( ( source += 1 ) == target || ( source += 1 ) == target )
				printf("YES");
			else if( source != target )
				printf("NO");	
		}	
		
		else
			printf("NO");
	if( rock == 'K')
	{	
		//Şahın önü boş veya doluysa
		if( board[ source -=8 ] == ' ' || board[ source -=8 ] != ' ')
		{
			if( (source -= 8) == target )
				printf("YES");
			else if( (source -= 8) != target )
				printf("NO");	
		}
		//arkası boş veya doluysa
		else if( board[ source +=8 ]== ' ' || board[ source +=8 ]!= ' ')
		{
			if( (source += 8) == target )
				printf("YES");
			else if( (source += 8) != target )
				printf("NO");	
		}
		//çapraz ön sağda ve solda taş varsa veya boşsa		
		else if( (board[ ( source -= 8 ) += 1 ] ) != ' ' || 
		          board[ ( source -= 8 ) += 1 ] ) == ' ' ||
		          board[ ( source -= 8 ) -= 1 ] ) == ' ' || 
		          board[ ( source -= 8 ) -= 1 ] ) != ' ' )
		{
			source = (source -= 8 );	
			
			if( ( source += 1 ) == target || ( source -= 1 ) == target )
				printf("YES");
			else if( source != target )
				printf("NO");	
		}	
		
		//çapraz arka sağda ve solda taş varsa veya boşsa		
		else if( (board[ ( source += 8 ) += 1 ] ) != ' ' ||
		          board[ ( source += 8 ) += 1 ] ) == ' ' ||
		          board[ ( source += 8 ) -= 1 ] ) == ' ' ||
		          board[ ( source += 8 ) -= 1 ] ) != ' ' )
		{	
			source = (source += 8);	
			
			if( ( source += 1 ) == target || ( source -= 1 ) == target )
				printf("YES");
			else if( source != target )
				printf("NO");	
		}	
		
		else
			printf("NO");
}

int isKnightMovable(char *board, char sourceCol, int sourceRow, char targetCol, 
	 	   int targetRow)
{
	if ( rock=='n')
	{
		//ön sağ ve sol hamle
		
		if ( board[ ( source += 16 ) += 1 ] == ' ' ||
		     board[ ( source += 16 ) += 1 ] != ' ' ||
		     board[ ( source += 16 ) -= 1 ] == ' ' ||
		     board[ ( source += 16 ) -= 1 ] != ' ' )	
		
		{
			source = ( source += 16 );
			
			if( ( source += 1) == target || ( source -= 1) == target )
				printf("YES");
			else if( source != target )
				printf("NO");		
		
		}
		
		//arka sağ ve sol hamle
		if ( board[ ( source -= 16 ) += 1 ] != ' ' ||
		     board[ ( source -= 16 ) += 1 ] == ' ' ||
		     board[ ( source -= 16 ) -= 1 ] == ' ' ||
		     board[ ( source -= 16 ) -= 1 ] != ' ' )	
		
		{
			source = ( source -= 16 );
			
			if( ( source += 1 ) == target || ( source -= 1 ) == target )
				printf("YES");
			else if( source != target )
				printf("NO");		
		
		}
	
		//yatay sağ hamle
		if ( board[ ( source += 2 ) += 8 ] == ' ' ||
		     board[ ( source += 2 ) += 8 ] != ' ' ||
		     board[ ( source += 2 ) -= 8 ] == ' ' ||
		     board[ ( source += 2 ) -= 8 ] != ' ' )
		{
			source = ( source += 2 );
			
			if( ( source += 8 ) == target || ( source -= 8 ) == target )
				printf("YES");
			else if( source != target )
				printf("NO");		
		
		}
	
		//yatay sol hamle
		if ( board[ ( source -= 2 ) += 8 ] != ' ' ||
		     board[ ( source -= 2 ) += 8 ] == ' ' ||
		     board[ ( source -= 2 ) -= 8 ] == ' ' ||
		     board[ ( source -= 2 ) -= 8 ] != ' ' )
		{
			source = ( source -= 2 );
			
			if( ( source += 8 ) == target || ( source -= 8 ) == target )
				printf("YES");
			else if( source != target )
				printf("NO");			
		}
			
	}
	if ( rock=='N')
	{
		//ön sağ ve sol hamle
		
		if ( board[ ( source -= 16 ) += 1 ] == ' ' ||
		     board[ ( source -= 16 ) += 1 ] != ' ' ||
		     board[ ( source -= 16 ) -= 1 ] == ' ' ||
		     board[ ( source -= 16 ) -= 1 ] != ' ' )	
		
		{
			source = ( source -= 16 );
			
			if( ( source += 1) == target || ( source -= 1) == target )
				printf("YES");
			else if( source != target )
				printf("NO");		
		
		}
		
		//arka sağ ve sol hamle
		if ( board[ ( source += 16 ) += 1 ] != ' ' ||
		     board[ ( source += 16 ) += 1 ] == ' ' ||
		     board[ ( source += 16 ) -= 1 ] == ' ' ||
		     board[ ( source += 16 ) -= 1 ] != ' ' )	
		
		{
			source = ( source += 16 );
			
			if( ( source += 1 ) == target || ( source -= 1 ) == target )
				printf("YES");
			else if( source != target )
				printf("NO");		
		
		}
	
		//yatay sağ hamle
		if ( board[ ( source += 2 ) += 8 ] == ' ' ||
		     board[ ( source += 2 ) += 8 ] != ' ' ||
		     board[ ( source += 2 ) -= 8 ] == ' ' ||
		     board[ ( source += 2 ) -= 8 ] != ' ' )
		{
			source = ( source += 2 );
			
			if( ( source += 8 ) == target || ( source -= 8 ) == target )
				printf("YES");
			else if( source != target )
				printf("NO");		
		
		}
	
		//yatay sol hamle
		if ( board[ ( source -= 2 ) += 8 ] != ' ' ||
		     board[ ( source -= 2 ) += 8 ] == ' ' ||
		     board[ ( source -= 2 ) -= 8 ] == ' ' ||
		     board[ ( source -= 2 ) -= 8 ] != ' ' )
		{
			source = ( source -= 2 );
			
			if( ( source += 8 ) == target || ( source -= 8 ) == target )
				printf("YES");
			else if( source != target )
				printf("NO");			
		}
			
	}
		
}










