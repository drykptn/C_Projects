/*
In this homework you will write a game called “minesweeper” that player is going to open cells
until the game will be terminated by “win” and returns the number of moves is made until win
when the player finds every “un-mined” cells or by “loose” when they hits a mine.
The player will choose a cell either to open or to flag it until the game is terminated. Every
time the player made a move the program should print whole grid with current moves, ask the
player their next move and get their choice.
If a closed cell is chosen; it can be either opened or flagged.
If a closed_empty cell is chosen to open; it will be open, its 8 neighbor will be checked for
emptiness and empty neighbors are also opened.
If a closed_mined cell is chosen to open; the game will be terminated by a loose message.
If a flagged cell is chosen; it can only be un-flagged.
If all empty cells are found; the game will be terminated by a win message.
You will print the grid with 'e' for empty cells; 'f' for flagged cells; '.' for closed cells.
In your code you will use an enumerated data type called “cell” as following
typedef enum {mined,
empty,
flaggedMined,
flaggedEmpty,
closedEmpty,
closedMined,
}cell;
The grid will be a GRIDSIZE x GRIDSIZE multi-dim array of cell.
*/
#include <stdio.h>
#include <stdlib.h>
#define gridSize 4

typedef enum {
    mined,
    empty,
    flaggedMined,
    flaggedEmpty,
    closedEmpty,
    closedMined
}cell;
int isLocationLegal(int x, int y);
/* return value int result=0 if the location is illegal and result=1 if the 
 * location is legal(in the grid).
 */

int openCell(cell grid[][gridSize], int x, int y);
/* return value int result = -2 when the cell is not opened with the case of 
 * illegal location; or flagged cell.
 */
int isCellEmpty(cell grid[][gridSize], int x, int y);
/* return value int result=0 if the cell is not an empty cell and result=1 the
 * cell is an empty cell.
 */
int startGame(cell grid[][gridSize]);
int asMain();
void flagCell(cell grid[][gridSize], int x, int y); 
/* return value int result = -2 when the cell is not flagged with the case of 
 * illegal location; or already flagged cell.
 */
void printGrid(cell grid[][gridSize]);


/* It takes input from user ( row and column )*/
void takeInputs(int *r, int *c);

/* If user lost the game, close the game or continiue */
int lose(cell grid[][gridSize]);

/* if user won the game, close the game or continiue */
int win(cell grid[][gridSize]);

/* if user want to play again, it goes to startGame function 
 * for lose and win   
 */
int startAgainOrExit(cell grid[][gridSize]);

/* For choice screen information */
void display(char *choice);

/* It calculates size of closedEmpty in grid */
int calculateEmptyCell(cell grid[][gridSize]);

/* grid teki ClosedEmpty sayisi ile acilan cell sayisini karsilastirir.
 * Eger esitse oyunu kazanir, degilse devam eder.
 */
int checkWin(cell grid[][gridSize], int countEmptyCell);

/* It initalized the grid */
void initGrid(cell grid[][gridSize]);

int main(int argc, char const *argv[]) {
    asMain();
    return 0;
}

int asMain(){
    cell grid[gridSize][gridSize];
    startGame(grid);
    return 0;
}

int startGame(cell grid[][gridSize]){
    int row;        
    int col;
    int game_continue;     /* Flag 1: continue playing, 0: quit game */
    int count;             /* size of move                           */     
    int countEmptyCell;    /* size of empty cell in grid             */
    char choice;           /* for open/flag/exit                     */
    row = 0;
    col = 0;
    game_continue = 1;
    countEmptyCell = 0;
    count = 0;

    initGrid(grid);
    printGrid(grid);
    /* Calculate size of closedEmpty then assign to countEmptyCell */
    countEmptyCell = calculateEmptyCell(grid);
    /* oyun false olana kadar devam eder */
    do {
        /* Choice screen */
        display(&choice);
        /* if user want to exit from game */
        if(choice == 'e' ){ 
            printf("Game over\n");
            game_continue = 0;
        }
        /* if user enter a wrong choice give an error and exit from game*/
        else if( choice != 'f' && choice != 'o' ){
            printf("You entered wrong choice\n");
            game_continue = 0;
        }
        else{
            /* take inputs from users ( row and col )*/
            takeInputs(&row, &col);
            printf("You entered [%d, %d]\n\n", row, col);
            /* if user want to open a cell */
            if( choice == 'o'){
                /* if location is not legal */
                if( openCell(grid, row, col) == -2 )
                    game_continue = 0;
                else{ 
                    /* continue */
                    game_continue = 1;
                    /* if user open a mined cell*/
                    if(grid[row][col] == closedMined){
                        grid[row][col] = mined;
                        game_continue = lose(grid);
                    }
                    /* print board */
                    printGrid(grid);
                }
            }
            /* if user want to flag a cell */
            else if(choice == 'f' ){
                if( isLocationLegal(row, col) != 0 ){
                    if( grid[row][col] != empty ){
                        flagCell(grid, row, col);            
                        printGrid(grid);
                    }
                }
                else
                    game_continue = 0;
            }
            /* if all empty cell opened */
            if( checkWin(grid, countEmptyCell) == 1 )
                game_continue = win(grid);           
            count++;
        }
    } while (game_continue);
    return 0;
}

void display(char *choice){
    printf("\nWhat do you want?\n");
    printf("1.Open the cell -> 'o'\n");
    printf("2.Flag the cell -> 'f'\n");
    printf("3.Exit -> 'e'\n");   
    scanf(" %c", &*choice);
}


void takeInputs(int *r, int *c){
    printf("Enter selection:\n");
    printf("Row --> ");
    scanf("%d", &(*r));
    printf("Col --> ");
    scanf("%d", &(*c));
}
/* It's calculate empty cell in grid */
int calculateEmptyCell(cell grid[][gridSize])
{
    int i;
    int j;
    int count;
    count = 0;
    for (i = 0; i < gridSize; ++i)
    {   
        for (j = 0; j < gridSize; j++ )
        {
            /* if cell is empty */
            if( grid[i][j] == closedEmpty)
                count++;
        }
    }
    return count;
}
/* Acilan hucrelerle bos olan hucre sayisini karsilastirir, esitse oyunu 
 * kazanir.
 */
int checkWin(cell grid[][gridSize], int countEmptyCell){
    int i;
    int j;
    int count;
    count = 0;
    for (i = 0; i < gridSize; ++i)
    {   
        for (j = 0; j < gridSize; j++ )
        {
            if( grid[i][j] == empty)
                count++;
        }
    }
    if( countEmptyCell == count)
        return 1;
    return -1;
}

int openCell(cell grid[][gridSize], int x, int y){
    if( grid[x][y] == flaggedMined || grid[x][y] == flaggedEmpty )
        return -2;

     /* if location is not legal, so return -2 */
    if( isLocationLegal(x, y) == 0 )
        return -2;
    /*
            8 adjacent cells

                    N.W  N  N.E
                      \  |  /
                       \ | /
                  W----Cell----E
                       / | \
                      /  |  \
                   S.W   S  S.E

            Cell--> Current Cell (x, y)
            N --> North  (x-1, y)
            S --> South  (x+1, y)
            E --> East       (x, y+1)
            W --> West       (x, y-1)
            N.E--> North-East (x-1, y+1)
            N.W--> North-West (x-1, y-1)
            S.E--> South-East (x+1, y+1)
            S.W--> South-West (x+1, y-1)
     */
    /* Current Cell  */
    if( isCellEmpty(grid, x, y) == 1 ){
        grid[x][y] = empty;
        /*  East */
        if( isLocationLegal(x, y+1) != 0 ){
            if( isCellEmpty(grid, x, y+1) == 1 ){
                grid[x][y+1] = empty;
            }
        }
        /* West */
        if( isLocationLegal(x, y-1) != 0 ){
            if( isCellEmpty(grid, x, y-1) == 1 )
                grid[x][y-1] = empty;
        }
        /* North */
        if( isLocationLegal(x-1, y) != 0 ){
            if( isCellEmpty(grid, x-1, y) == 1 )
                grid[x-1][y] = empty;
        }
        /* South */
        if( isLocationLegal(x+1, y) != 0 ){
            if( isCellEmpty(grid, x+1, y) == 1 )
                grid[x+1][y] = empty;
        }
        /* North-East */
        if( isLocationLegal(x-1, y+1) != 0 ){
            if( isCellEmpty(grid, x-1, y+1) == 1 )
                grid[x-1][y+1] = empty;
        }
        /* North-West */
        if( isLocationLegal(x-1, y-1) != 0 ){
            if( isCellEmpty(grid, x-1, y-1) == 1 )
                grid[x-1][y-1] = empty;
        }
        /* South-East */
        if( isLocationLegal(x+1, y+1) != 0 ){
            if( isCellEmpty(grid, x+1, y+1) == 1 )
                grid[x+1][y+1] = empty;
        }
        /* South-West */
        if( isLocationLegal(x+1, y-1) != 0 ){
            if( isCellEmpty(grid, x+1, y-1) == 1 )
                grid[x+1][y-1] = empty;
        }
    }
    return 1;
}
/* if cell is empty return 1, else 0 */
int isCellEmpty(cell grid[][gridSize], int x, int y){
    if( grid[x][y] == closedEmpty )
        return 1;
    return 0;
}
/* The function creates an example board */
void initGrid(cell grid[][gridSize]) {
    int i;         /* for loop       */
    int j;         /* for empty cell */     
    /* until board size */
    for (i = 0; i < gridSize; ++i)
    {   
        /* put empty cell for j */
        for (j = 0; j < gridSize ; j++ )
            grid[i][j] = closedEmpty;
    }
    for (i = 0; i < gridSize; ++i)
    {   
        /* put mined cell for j */
        for (j = 1; j < gridSize ; j += 2 )
            grid[i][j] = closedMined;
    }
}
/* if a cell is wanted to be flagged; check if it is empty or mined: if it is 
 * empty, flag as flagged-empty; if it is mined, flag as flagged-mined
 */
void flagCell(cell grid[][gridSize], int x, int y){
    /* if cell has a mine */
    if( grid[x][y] == closedMined )
        grid[x][y] = flaggedMined;
    /* if cell has not a mine */
    else if (grid[x][y] == closedEmpty)
        grid[x][y] = flaggedEmpty;
    /* if user want to remove the flag, return first stiuation */
    else if (grid[x][y] == flaggedEmpty)
        grid[x][y] = closedEmpty;
    else if (grid[x][y] == flaggedMined)
        grid[x][y] = closedMined;
}

/* It prints the board */
void printGrid(cell grid[][gridSize]){
    int r, c;
    /* for number of grid */
    printf(" ");
    for (r = 0; r < gridSize; r++)
        printf("  %d", r);
    printf("\n");
    /* print grid */
    for (r = 0; r < gridSize; r++) {
        printf("%d ", r);
        for (c = 0; c < gridSize; c++) {
            if( grid[r][c] == empty )
                printf(" %c ", 'e');
            else if( grid[r][c] == flaggedEmpty || grid[r][c] == flaggedMined )
                printf(" %c ", 'f');
            else if( grid[r][c] ==  mined )
                printf(" %c ", 'm');
            else
                printf(" %c ", '.');			
        }
        printf("\n");
    }
}

int isLocationLegal(int x, int y){
    /* if location smaller than 0 or greater than board size, return 1*/
    if( x < gridSize && x >= 0 ){
        if( y < gridSize && y >= 0)
            return 1;
    }
    return 0;
}

int lose(cell grid[][gridSize])
{
    int result;
    printGrid(grid);
    result = startAgainOrExit(grid);
    return result;
}

int win(cell grid[][gridSize])
{
    int result;
    result = startAgainOrExit(grid);
    return result;
}
int startAgainOrExit(cell grid[][gridSize]){
    int result;
    char answer;
    result = 1;

    printf("\nYou lost the game!\n");
    printf("\nWould you like to play again? (y/n)--> ");
    scanf(" %c", &answer);
 
    if( answer == 'Y' || answer == 'y' ){
        initGrid(grid);
        startGame(grid);
    }
    else
    {
        result = 0;
        return result;
    }
    return result;
}
