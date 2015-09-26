#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include<list>
#include<graphics.h>
#include<time.h>
#include<X11/Xlib.h>

using namespace std;

/**************************************************************************************************
//GLOBAL VARIABLES
**************************************************************************************************/


int score1, score2; // STRATEGIC SCORE OF PLAYERS AT THE CURRENT STATE

int count1, count2; // NUMBER OF COINS OF THE CORRESPONDING PLAYER ON BOARD

int gamegrid[8][8]; // GAME GRID THAT HAS THE CONFIGURATION OF THE CURRENT GAME STATE

int pointsgrid[8][8]; // GRID THAT HAS THE STRATEGIC POINTS FOR THE CORRESPONDING LOCATION

int color1,color2; // COLOR OF PLAYER'S COIN FOR GRAPHICS DISPLAY

int winsize =600; // SIZE OF WINDOW FOR GRAPHICS DISPLAY

int width=30; //SIZE OF GRID WIDTH (ONE BOX)

int leftend= (winsize- (8*width))/2; // POSITION FROM THE LEFT WHERE GRID BEGINS

int rightend = winsize-leftend; // POSITION ON THE RIGHT WHERE GRID ENDS

int radius=10; // RADIUS OF THE COINS

int font=2; //FONT SIZE FOR DISPLAY

int D=6; // DEPTH WHICH IS CONSIDERED AS THE LEAF OF THE TREE


/**************************************************************************************************
//CLASS DECLARATION FOR MINI-MAX IMPEMENTATION
**************************************************************************************************/

class current_state
{ 
  public:
         
  int depth; // DEPTH OF TREE
  
  int points; // CURRENT VALUE
  
  int pl; // 1 FOR PLAYER1 AND 2 FOR PLAYER2
  
  int posx,posy; // POSITIONS OF PLAY
  
  std::list<current_state> branches; // LIST OF CHILDREN FOR THE CURRENT NODE
  
  current_state(int p, int x=-1, int y=-1) //ARGUMENT CONSTRUCTOR
  { 
    posx=x; posy=y;
    pl=p; points=0; depth=0;
    branches.clear();
  }
};

/**************************************************************************************************
//CLASS DECLARATION FOR ALPHA BETA PRUNING IMPLEMENTATION
**************************************************************************************************/


class current_state_prune
{ 
   public: 
             
   int v; // CURRENT VALUE
   
   current_state_prune * ptr;  // SELF REFERENCING CLASS
   
   int posx,posy; //POSITIONS OF PLAY
   
   int minmax;  // IS -1 FOR MINIMISER(USER) AND 1 FOR (MAXIMISER)
   
   int depth; //DEPTH OF TREE
   
   int alpha; // THE BEST VALUE ACHIEVED FOR THE MAXIMISER ALONG THE PATH BACK TO THE ROOT
   
   int beta; // THE BEST VALUE ACHIEVED FOR THE MINIMISER ALONG THE PATH BACK TO THE ROOT
   
   current_state_prune(int p,int a=-1000, int b=1000, int x=-1, int y=-1) //ARGUMENT CONSTRUCTOR
   {
     alpha=a;
     beta=b;                      
     minmax=p;
     ptr=NULL;
     posx=x; posy=y;
     if(minmax==1)
     {
        v=-1000;
     }        
     else if(minmax==-1)
     {
        v=1000;
     }                          
   }                 
};

/**************************************************************************************************
//FUNCTION PROTOTYPES
**************************************************************************************************/


void createboard(); // CREATES THE INITIAL CONFIGURATION OF THE BOARD AND INITIALIZES ALL GLOBAL VARIABLES

void print_circle_solid(int , int , int ); //TO PRINT COINS IN SOLID FORMAT

void print_circle_empty(int , int , int ); //TO PRINT COINS IN EMPTY FORMAT

void create_window_box(); // CREATE WINDOW AND A SQUARE BOX FOR GRAPHICS DISPLAY

void heading(); // PRINT HEADING USING GRAPHICS

void  create_window_grids(); // CREATE THE GRIDS ON THE BOARD FOR GRAPHICS DISPLAY

void print_coins(); // PRINT COINS OF THE PLAYERS ON WINDOW USING GRAPHICS

void print_number(); // FUNCTION USED TO NUMBER THE GRIDS (X AND Y AXIS)

void print_score(); //FUNCTION TO PRINT THE SCORE ON WINDOW USING GRAPHICS

void printboard(); // FUNCTION TO PRINT COMPLETE GAME BOARD USING GRAPHICS

void suggest(int); // FUNCTION TO SUGGEST MOVES FOR THE PLAYER USING GRAPHICS

void print_board(); //PRINTS BOARD IN GRID FORMAT USING 'X' AND 'O' DISPLAY

void score(); // UPDATES THE GLOBAL VARIABLES SCORE1, SCORE2, COUNT1, COUNT2

void change(int, int, int, int, int); // CALLED BY FLIP FUNCTION TO FLIP THE COINS IN THE GIVEN DIRECTION

void flip(int, int, int); // FLIPS THE COINS GIVEN THE NEW INSERTION POSITION (x,y) AND THE PLAYER NUMBER

int isvalid(int, int, int); // CHECKS WHETHER THE GIVEN MOVE IS VALID OR NOT.. TAKES POSTION AND PLAYER NUMBER AS ARGUMENTS

void suggest(int);// SUGGEST MOVES FOR GIVEN PLAYER NUMBER ON CONSOLE

int possible(int);// RETURNS 0 OR 1 DEPENDING UPON WHETHER MOVES ARE AVAILABLE FOR THE PLAYER NUMBER

void two_player();// TWO PLAYER GAME FUNCTION

bool compare(current_state, current_state);// FUNCTION USED BY MIN_ELEMENT() AND MAX_ELEMENT() 

int count(current_state * ); //TO COUNT THE COINS OF PLAYER ON BOARD AFTER INSERTION OF A GIVEN POSITION

current_state * max(current_state * );  // MAX FUNCTION TO FIND THE BEST POINTS FOR MAXIMISER FROM ITS BRANCHES

current_state * min(current_state * );  // MIN FUNCTION TO FIND THE BEST POINTS FOR MINIMISER FROM ITS BRANCHES

void makebestmove(current_state * );// GIVES THE BEST MOVE FOR COMPUTER IN ONE PLAYER GAME USING MINMAX ALGORITHM

void best_move(current_state_prune); // GIVES THE BEST MOVE FOR COMPUTER IN ONE PLAYER GAME USING ALPHA BETA PRUNING

int random_generator(int ); //FUNCTION THAT GENERATES RANDOM MOVES AND HELPS IN GAME ANALYSIS BY PLAYING AGAINST COMPUTER

void one_player();// USER VERSUS COMPUTER GAME FUNCTION


