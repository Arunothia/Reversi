#include "header.h"


/**************************************************************************************************
//INITIAL BOARD BEING CREATED
**************************************************************************************************/

void createboard()
{ 
  score1=score2=4; // INITIALIZING SCORES OF PLAYERS
  
  count1=count2=2; // INITIALIZING GLOBAL VARIABLES COUNT1, COUNT2
  
  int i,j;
  for(i=0; i<8; i++)
  { 
    for(j=0; j<8; j++)
    { 
      if(((i==3)&&(j==3))||((i==4)&&(j==4)))
      { 
         gamegrid[i][j]='X';
      }  
      else if(((i==3)&&(j==4))||((i==4)&&(j==3)))
      {
         gamegrid[i][j]='O';
      }  
      else
      {
         gamegrid[i][j]='.';
      }  
    }
  }
  for(i=0; i<8; i++)
  { for(j=0; j<8; j++)
    { 
      if((i<=5)&&(i>=2)&&(j<=5)&&(j>=2)) //SWEET SIXTEEN
      { 
         pointsgrid[i][j]=2;
      }  
      else if(((i==0)||(i==7))&&((j==0)||(j==7))) //CORNERS
      {
         pointsgrid[i][j]=5;
      }    
      else if(((i==1)||(i==6))&&((j==1)||(j==6))) //X SQUARES
      {
         pointsgrid[i][j]=-2;
      }   
      else if((((i==0)||(i==7))&&((j==1)||(j==6)))||(((i==1)||(i==6))&&((j==0)||(j==7)))) //C SQUARES
      { 
         pointsgrid[i][j]=-1;
      }  
      else
      {
         pointsgrid[i][j]=1;
      }  
    } 
  } 
}


/**************************************************************************************************
//FUNCTION TO PRINT CIRCLE IN SOLID FORMAT
**************************************************************************************************/

void print_circle_solid(int x, int y, int p)
{ 
  int color;
  if(p==1)
  {  
    color=color1;
  }
  else if(p==2)
  {
    color=color2; 
  }
  
  setcolor(color);
  circle(x,y,radius);  
  //setfillstyle(SOLID_FILL,color);
  floodfill(x,y,color);
}     


/**************************************************************************************************
//FUNCTION TO PRINT CIRCLE IN EMPTY FORMAT
**************************************************************************************************/

void print_circle_empty(int x, int y, int p)
{ 
  int color;
  if(p==1)
  {  
    color=color1;
  }
  else if(p==2)
  {
    color=color2; 
  }
  
  setcolor(color);
  circle(x,y,radius);  
  //setfillstyle(EMPTY_FILL,color);
  floodfill(x,y,color);
}   

/**************************************************************************************************
// CREATE WINDOW AND A SQUARE BOX
***************************************************************************************************/

void create_window_box()
{
  
  int gd = DETECT,gm;//left=,top=100,right=200,bottom=200,x= 300,y=150,radius=50;
  initgraph(&gd,&gm,NULL);
  line(leftend,leftend,leftend,rightend);
  line(leftend,leftend,rightend,leftend);
  line(rightend,leftend,rightend,rightend);
  line(leftend,rightend,rightend,rightend);  
}

/**************************************************************************************************
// PRINT HEADING
**************************************************************************************************/

void heading()
{
  //settextstyle(1,0,font+2);
  char p[] = "REVERSI - ARUNOTHIA";
  outtextxy(leftend, 0+width, p); 
}

/**************************************************************************************************
// CREATE THE GRIDS 
**************************************************************************************************/

void  create_window_grids()
{  
  for(int i=1; i<8; i++)
  { 
     line((leftend+(i*width)),leftend, (leftend+(i*width)), rightend);
  }   
  for(int i=1; i<8; i++)
  {
     line(leftend,(leftend+(i*width)), rightend, (leftend+(i*width)));
  }
}

/**************************************************************************************************
//TO PRINT THE CORRESPONDING CIRCLES FOR COINS ON BOARD
**************************************************************************************************/

void print_coins()
{  
  for(int i=0; i<8; i++)  
  {
    for(int j=0; j<8; j++)
    { 
       if(gamegrid[i][j]=='O')
       {
         print_circle_solid((leftend+(2*i+1)*(width/2)),(leftend+(2*j+1)*(width/2)),1);           
       }
       else if(gamegrid[i][j]=='X')
       {
         print_circle_solid((leftend+(2*i+1)*(width/2)),(leftend+(2*j+1)*(width/2)),2);           
       }
    }
   }
} 

/**************************************************************************************************
//TO PRINT THE ROWS AND COLUMNS NUMBER
**************************************************************************************************/

void print_number()
{  
  for(int i=1; i<=8; i++)
  {  
     char s[] = {'0'+i,'\0'};
     setcolor(15);
     //settextstyle(1,0,font);
     outtextxy((leftend-(width/2)), (leftend + ((2*i-1)*(width/2))), s);
     outtextxy((leftend + ((2*i-1)*(width/2))), (leftend-(width/2)), s);
  }  
}

/**************************************************************************************************  
//TO PRINT SCORE
**************************************************************************************************/

void print_score()
{  
  char s1[]={ '0'+count1/10, '0'+count1%10,'\0'};
  char p1[]="PLAYER 1";
  print_circle_solid(leftend+width/2, rightend+3*width/2, 1);
  setcolor(15);
  //settextstyle(1,0,font);
  outtextxy(leftend+3*width/2, rightend +3*width/2, s1);
  outtextxy(leftend, rightend+width/2, p1); 
  char s2[]={ '0'+count2/10, '0'+count2%10, '\0'};
  char p2[]="PLAYER 2";
  print_circle_solid(rightend-width/2,rightend+3*width/2, 2);
  setcolor(15);
  //settextstyle(1,0,font);
  outtextxy(rightend-5*width/2, rightend+3*width/2, s2);
  outtextxy(leftend+ 11*width/2, rightend+width/2, p2); 
}

  
/**************************************************************************************************
//FUNCTION TO PRINT GRID USING GRAPHICS
**************************************************************************************************/

void printboard()
{   
   create_window_box();
   heading();
   create_window_grids();
   print_coins();  
   print_number();
   print_score();
   
}

/**************************************************************************************************
//SUGGESTING MOVES USING GRAPHICS 
**************************************************************************************************/

void suggest(int p)
{   
   create_window_box();
   heading();
   create_window_grids();
   print_coins();  
   print_number();
   print_score();
   
  //TO PRINT SUGGESTED CIRCLES
  for(int i=0; i<8; i++)  
  {
    for(int j=0; j<8; j++)
    { 
       if(isvalid(i,j,p))
       {
         print_circle_empty((leftend+(2*i+1)*(width/2)),(leftend+(2*j+1)*(width/2)),p);           
       }       
       
    }
   }  
}

/**************************************************************************************************
//FUNCTION TO PRINT THE BOARD IN GRID FORMAT
**************************************************************************************************/

void print_board()
{ 
  int i,j;
  system("CLS");
  cout<<"  WELCOME TO THE WORLD OF REVERSI\n\n\n";
  cout<<"        ";
  for(i=0; i<8; i++)
  { 
    cout<<i+1<<"      ";
  }
  cout<<"\n";
  for(i=0; i<8; i++)
  { 
    cout<<"     ";
    for(j=0; j<8; j++)
    { 
      cout<<"-------";
    }  
    cout<<"\n  "<<i+1<<"  ";
    for(j=0; j<8; j++)
    { 
     cout<<"|  "<<gamegrid[i][j]<<"  |";
    }
   cout<<"\n";
  }
  cout<<"     ";
  for(i=0; i<8; i++)
  { 
    cout<<"-------";
  }
  cout<<"\n\n\n";
  cout<<"SCORE BOARD\n\n\n";
  cout<<"THE SCORE OF PLAYER 'O' IS : "<<count1<<"\n\n";
  cout<<"THE SCORE OF PLAYER 'X' IS : "<<count2<<"\n\n";
}

/**************************************************************************************************
//FUNCTION TO CALCULATE SCORE
**************************************************************************************************/

void score()
{ 
  int i,j,s1=0,s2=0,c1=0,c2=0;
  for(i=0; i<8; i++)
  { 
    for(j=0; j<8; j++)
    { if(gamegrid[i][j]=='O')
      { 
        s1+=pointsgrid[i][j];
        c1++;
      }
      else if(gamegrid[i][j]=='X')
      { 
        s2+=pointsgrid[i][j];
        c2++;
      }
    }
  }   
  score1=s1;count1=c1;
  score2=s2;count2=c2;
}

/**************************************************************************************************
// FUNCTION TO FLIP THE COINS IN THE CHOSEN DIRECTION
**************************************************************************************************/


void change(int i, int j, int r, int c, int p)
{ 
  char ch1,ch2; int m=i+r; int n=j+c;
  if(p==1)
  { 
    ch1='X'; ch2='O';
  }
  else
  { 
    ch1='O'; ch2='X'; 
  }
  while((gamegrid[m][n]==ch1)&&(m>=0)&&(m<=7)&&(n>=0)&&(n<=7)) 
  { 
    gamegrid[m][n]=ch2;
    m=m+r;
    n=n+c;
  }
}

/**************************************************************************************************
//FUNCTION THAT CHOSES THE DIRECTION OF FLIP
**************************************************************************************************/

void flip(int i, int j, int p)
{ 
 int m,n,k,w,r=0,c=0;
 char ch1,ch2;
  if(p==1)
  { 
    ch1='X'; ch2='O'; 
  }
  else
  { 
    ch1='O'; ch2='X'; 
  }
 for(k=i-1; k<=i+1; k++)
 { 
   for(w=j-1; w<=j+1; w++)
   { 
    if(((k==i)&&(w==j))||(k<0)||(k>7)||(w<0)||(w>7))
    { 
      continue;
    }  
    m=k; n=w; r=c=0;
    if(gamegrid[m][n]==ch1)
    { 
      r=m-i; c=n-j;
      while(gamegrid[m][n]==ch1)
     { 
       m=m+r;
       n=n+c;
     }
    if((gamegrid[m][n]==ch2)&&!((r==0)&&(c==0))&&((m>=0)&&(m<=7)&&(n>=0)&&(n<=7)))
    {
       change(i,j,r,c,p);
    } 
    else
    r=c=0;
   }
  }
 }
}

/**************************************************************************************************
//FUNCTION THAT RETURNS '0' FOR INVALID MOVES AND '1' FOR VALID MOVES
**************************************************************************************************/

int isvalid(int i, int j,int p)
{ 
  char ch1,ch2;
  int k,w,m,n;
  
  if(gamegrid[i][j]!='.')
  { 
    return 0;
  }
  
  int r=0,c=0;
  if(p==1)
  { 
    ch1='X'; ch2='O';
  }
  else
  { 
    ch1='O'; ch2='X';
  } 
  
  for(k=i-1; k<=i+1; k++)
  { 
    for(w=j-1; w<=j+1; w++)
    { if(((k==i)&&(w==j))||(k<0)||(k>7)||(w<0)||(w>7)) 
      { 
       continue;
      }
      m=k; n=w;
      if(gamegrid[m][n]==ch1)
      { 
       r=m-i; c=n-j;
       while(gamegrid[m][n]==ch1) 
       { 
        m=m+r;
        n=n+c;
       }
      if((gamegrid[m][n]==ch2)&&((m<8)&&(m>=0)&&(n<8)&&(n>=0)))
      { 
        goto step;
      } 
      else 
      { 
        r=c=0;  
      }
     }
   } 
  } 
  step:
  if((r==0)&&(c==0))
  {
   return 0;
  }
 return 1;
} 

/**************************************************************************************************
//FUNCTION THAT PRINTS ALL CANDIDATE MOVES AVAILABLE ON CONSOLE
**************************************************************************************************/

void suggest_grid (int p)
{    
  system("CLS");
  if(p==1)
  { 
    cout<<"\n\t\tTHE CHOICES AVAILABLE FOR USER (PLAYER 1)\n\n";
  }
  else
  {
    cout<<"\n\t\tTHE CHOICES AVAILABLE FOR THE COMPUTER (PLAYER 2)\n\n";
  }   
  int r=0;
  int i,j;
  for(i=0; i<8; i++)
  { 
    for(j=0; j<8; j++)
    { 
      if(isvalid(i,j,p))
      { 
        cout<<"\n"<<r+1<<"th CHOICE  : X : "<<i+1<<"  Y : "<<j+1<<"\n\n";
        r++;
      }
    }
  } 
 if(r==0)
 { 
   cout<<"\nNO VALID POSITION SO THE PLAYER IS BEING SKIPPED!\n\n";
   system("pause");
 } 
}

/**************************************************************************************************
//FUNCTION THAT CHECKS WHETHER MOVES ARE STILL AVAILABLE FOR THE PLAYER
**************************************************************************************************/

int possible(int p)
{ 
  int i,j;
  for(i=0; i<8; i++)
  { 
    for(j=0; j<8; j++)
    { 
      if(isvalid(i,j,p))
      { 
        return 1;
      }
    }
  }
 return 0;
}

/**************************************************************************************************
//FUNCTION FOR TWO PLAYER GAME 
**************************************************************************************************/

void two_player()
{ 
  createboard();
  int x1,y1,x2,y2,i=0;
  printboard();
  while(possible(1)||possible(2))
  { 
    if(i%2==0)
    { 
      closegraph();
      suggest(1);
      suggest_grid(1);
      if(possible(1))
      { 
        cout<<"\n\nPLAYER 1 SHOULD ENTER HIS POSITION :\n\n\nx : ";
        cin>>x1;
        cout<<"\n\ny : ";
        cin>>y1;
        if(isvalid(x1-1,y1-1,1)==0) 
        {
         continue;
        }
      }
       else
      { 
        i++; 
        cout<<"\nMOVE BEING SKIPPED\n\n";
        system("pause");
        continue;
      }
     
      gamegrid[x1-1][y1-1]='O';
      flip(x1-1,y1-1,1);
      score();
    }
   else
    { 
      closegraph();        
      suggest(2);
      suggest_grid(2);
      if(possible(2))
      { 
        cout<<"\n\nPLAYER 2 SHOULD ENTER HIS POSITION :\n\n\nx : ";
        cin>>x2;
        cout<<"\n\ny : ";
        cin>>y2;
        if(isvalid(x2-1,y2-1,2)==0)
        {
          continue;
        } 
      }
       else
      {
        i++; 
        cout<<"\nMOVE BEING SKIPPED\n\n";
        system("pause");
        continue;
      }

      gamegrid[x2-1][y2-1]='X';
      flip(x2-1,y2-1,2);
      score();
    }
    i++;
  }
 if(!(possible(1)||possible(2)))
 { 
   if(count1>count2)
   { 
     cout<<"\n\n THE GAME IS OVER!!!\n\nPLAYER 1 HAS WON THE GAME\n\n";
     cout<<"\t\tENTER ANY NUMBER TO CONTINUE!!\n\n";
     cin>>i;
   }
  else
   { 
     cout<<"\n\n THE GAME IS OVER!!!\n\nPLAYER 2 HAS WON THE GAME\n\n";    
     cout<<"ENTER ANY NUMBER TO CONTINUE!!\n\n";
     cin>>i;
   }     
 }
}

/**************************************************************************************************
//COMPARE FUNCTION FOR MIN/MAX ELEMENT
**************************************************************************************************/

bool compare(current_state c1, current_state c2)
{ 
  return (c1.points<c2.points);
}

/**************************************************************************************************
//TO COUNT THE COINS OF PLAYER ON BOARD AFTER INSERTION OF A GIVEN POSITION
**************************************************************************************************/

int count(current_state * cs)
{
  int value;  
  char ch;
  if(cs->pl==1)
  {
     ch='O';
  }
  else
  {
     ch ='X';
  } 
  int tempgrid[8][8];
  for(int i=0; i<8; i++)
  { 
    for(int j=0; j<8; j++)
    {
      tempgrid[i][j]=gamegrid[i][j];
    }
  }  
  gamegrid[cs->posx][cs->posy]=ch;
  flip(cs->posx,cs->posy,cs->pl);
  score();
  value = count2;
  for(int i=0; i<8; i++)
  { 
    for(int j=0; j<8; j++)
    { 
      gamegrid[i][j]=tempgrid[i][j];
    }
  }
  score(); 
  return value;
}  

/**************************************************************************************************
// MAX FUNCTION TO FIND THE BEST POINTS FOR MAXIMISER FROM ITS BRANCHES
**************************************************************************************************/

current_state * max(current_state * cs)
{
  current_state * ptr= &(*cs->branches.begin());
  int max=-1000;
  for (std::list<current_state>::iterator it=cs->branches.begin(); it!=cs->branches.end(); ++it)
  { 
    if((it->points)>max)
    {
      ptr= &(*it);                               
      max = it->points;
    }
    else if((it->points)==max)  
    { 
       if(count(&(*it))>count(ptr))
       {
         ptr = &(*it);
       }  
  
    }   
   }   
    return ptr;
}   

/**************************************************************************************************
// MIN FUNCTION TO FIND THE BEST POINTS FOR MINIMISER FROM ITS BRANCHES
**************************************************************************************************/

current_state * min(current_state *cs)
{
  current_state * ptr;
  int min=1000;
  for (std::list<current_state>::iterator it=cs->branches.begin(); it!=cs->branches.end(); ++it)
  { 
    if((it->points)<min)
    {
      ptr= &(*it);                               
      min = it->points;
    }
    else if((it->points)==min)  
    { 
       if(count(&(*it))<count(ptr))
       {
         ptr = &(*it);
       }  
    } 
   }  
    return ptr;
}         

            
/*************************************************************************************************
//FUNCTION BESTMOVE FOR ONE PLAYER GAME USING MINMAX ALGORITHM
**************************************************************************************************/

void makebestmove(current_state *cs)
{ 
  char ch;
  int p;
  if(cs->pl==1)
  { 
    p=2;ch='O';
  }
  else
  {
    p=1;ch='X';
  }
  if(!possible(cs->pl))
  { 
    if(cs->pl==1)
    {
       cs->points=score2-score1+5;
    }
    else
    {
       cs->points=score2-score1-5;
    }       
    return;
  }
  if(cs->depth==D)
  { 
    cs->points=score2-score1;
    return;
  }
  else
  { 
    for(int a=0; a<8; a++)
    { 
      for(int b=0; b<8; b++)
        { 
          if(isvalid(a,b,cs->pl))
          { 
            char tempgrid[8][8];
            cs->branches.push_back(current_state(p,a,b));
            (cs->branches.back()).depth=cs->depth+1;
            for(int i=0; i<8; i++)
            { 
             for(int j=0; j<8; j++)
             {
              tempgrid[i][j]=gamegrid[i][j];
             }
            }  
            gamegrid[a][b]=ch;
            flip(a,b,cs->pl);
            score();
            makebestmove(&cs->branches.back());
            for(int i=0; i<8; i++)
            { 
              for(int j=0; j<8; j++)
              { 
                gamegrid[i][j]=tempgrid[i][j];
              }
            }
            score();
          }
        }
    }
    if(cs->depth%2==0)
    { 
      //cs->points=std::max_element(cs->branches.begin(),cs->branches.end(),compare)->points;
      cs->points = max(cs)->points;
    }
    else
    { 
      //cs->points=std::min_element(cs->branches.begin(),cs->branches.end(),compare)->points;
      cs->points = min(cs)->points;
    } 
  }
 if(cs->depth==0)
 { 
   cs->posx = max(cs)->posx;
   //cs->posx=std::max_element(cs->branches.begin(),cs->branches.end(),compare)->posx;
   cs->posy = max(cs)->posy;
   //cs->posy=std::max_element(cs->branches.begin(),cs->branches.end(),compare)->posy; 
 }
}

/**************************************************************************************************
//BEST MOVE : MAXIMISER FUNCTION USING ALPHA - BETA PRUNING
**************************************************************************************************/

void best_move(current_state_prune * cs)
{  
  char ch;   
  int p;
  if(cs->minmax==-1)
  {
    p=1; ch='O';                 
  }     
  else
  {
    p=2; ch='X';
  }              
  if(!possible(p))
  {
     if(p==1)
     {
       cs->v = score2 - score1 + 5;
     }
     else
     {
       cs->v = score2 - score1 - 5;
     }      
     return ;
  }                  
  if(cs->depth==D)
  {
    cs->v = score2-score1;
    return ;
  }
  else                
  { int flag=0;
     for(int a=0; (a<8)&&(flag==0); a++)
     {
        for(int b=0; b<8; b++)
        {
            if(isvalid(a,b,p))
            {  int tempgrid[8][8];
               cs->ptr = new current_state_prune(-(cs->minmax), cs->alpha, cs->beta, a, b);
               cs->ptr->depth = cs->depth+1;
                for(int i=0; i<8; i++)
                { 
                   for(int j=0; j<8; j++)
                   {
                      tempgrid[i][j]=gamegrid[i][j];
                   }
                }  
               gamegrid[a][b]=ch;
               flip(a,b,p);
               score(); 
               best_move(cs->ptr);
               for(int i=0; i<8; i++)
               { 
                  for(int j=0; j<8; j++)
                  { 
                    gamegrid[i][j]=tempgrid[i][j];
                  }
               }
               score();
               if(cs->minmax==1)
               {         
                  if((cs->v)<(cs->ptr->v))
                  {
                      cs->v=cs->ptr->v;
                      if(cs->depth==0)
                      {
                        cs->posx=cs->ptr->posx;
                        cs->posy=cs->ptr->posy;
                      }                
                  }    
                  if((cs->alpha)<(cs->v))
                  {
                     cs->alpha=cs->v;
                  }   
                  if((cs->v)>(cs->beta))
                  {
                     flag=1;
                     break;                 //PRUNE                 
                  }                             
                  else
                  {
                      delete cs->ptr;
                     // continue;
                  }   
               }   
               
               if(cs->minmax==-1)
               {
                  if((cs->v)>(cs->ptr->v))
                  {
                      cs->v=cs->ptr->v;      
                  }   
                  if(cs->beta>(cs->v))
                  {
                     cs->beta=cs->v;
                  }   
                  if((cs->v)<(cs->alpha))
                  {
                      flag=1;
                      break;               //PRUNE                 
                  }                             
                  else
                  {
                      delete cs->ptr;
                      //continue;
                  }   
               }                         
            }
        }
     }
  } 
                     
} 

/**************************************************************************************************
//FUNCTION THAT GENERATES RANDOM MOVES AND HELPS IN GAME ANALYSIS BY PLAYING AGAINST COMPUTER
**************************************************************************************************/    

int random_generator(int algo_choice)
{ 
  int size=20;
  int a[size][2];
  createboard();  
  int x1,y1; int k=1; 
  while(possible(1)||possible(2))
  { k++;
    if(k%2==0)
    { 
      if(!possible(1))
      {
         continue;
      }               
      int f=0;
      for(int i=0; i<8; i++)
      { 
         for(int j=0; j<8; j++)
         { 
            if(isvalid(i,j,1))
            {
              a[f][0]=i;
              a[f][1]=j;
              f++;
            }  
         }
      }          
         int r= rand() % f;
         x1= a[r][0]; 
         y1= a[r][1];
         gamegrid[x1][y1]='O';
         flip(x1,y1,1);
         score();
    }
    else
    { 
      if(!possible(2))
      { 
        continue;
      }
      else
      { int x,y;
       
      if(algo_choice==2)
        {
           current_state_prune gameptr(1);
           gameptr.depth=0;
           best_move(&gameptr);
           x=gameptr.posx;
           y=gameptr.posy;
        }
        else
        {
            current_state gameptr(2);
            makebestmove(&gameptr);
            x=gameptr.posx;
            y=gameptr.posy;
        }     
        gamegrid[x][y]='X';
        flip(x,y,2);
        score();
      }
    }
  }
  if(!(possible(1)||possible(2)))
 { 
   if(count1>count2)
   { 
    return 0;
   }
  else
   { 
    return 1;
   }
 }
}


/**************************************************************************************************
//FUNCTION FOR ONE PLAYER GAME
**************************************************************************************************/

void one_player()
{ 
  int choice; 
  system("CLS");
  cout<<"\n\nCHOSE THE ALGORITHM YOU WOULD LIKE THE COMPUTER TO FOLLOW\n\nPRESS\n\n 1: MIN-MAX ALGORITHM\n\n 2: ALPHA- BETA PRUNING DONE WITH MIN-MAX\n\n";
  step:
  cin>>choice;
  if((choice!=1)&&(choice!=2))
  {
     cout<<"\n\nINVALID CHOICE.. PLEASE RE-ENTER \n\n";
     goto step;
  }                             
  createboard();  
  int x1,y1; int i=0; char ch;
  printboard();
  while(possible(1)||possible(2))
  { 
    if(i%2==0)
    { 
      closegraph();        
      suggest(1);
      suggest_grid(1);
      if(possible(1))
      { 
        cout<<"\n\nUSER SHOULD ENTER HIS/HER POSITION :\n\n\nx : ";
        cin>>x1;
        cout<<"\n\ny : ";
        cin>>y1;
        if(!(isvalid(x1-1,y1-1,1)))
        {
         continue;
        } 
      }  
      else
      { 
        i++;
        cout<<"\nMOVE BEING SKIPPED\n\n";
        system("pause");
        continue;
      }
      gamegrid[x1-1][y1-1]='O';
      flip(x1-1,y1-1,1);
      score();
    }
    else
    { 
      if(!possible(2))
      { 
        i++;
        cout<<"\n\nGAME PASSED AS NO VALID MOVES AVAILABLE\n\n";
        system("pause");
        continue;
      }
      else
      { 
        int x,y;
          
        if(choice==2)
        {
           current_state_prune gameptr(1);
           gameptr.depth=0;
           closegraph();
           suggest(2);
           suggest_grid(2);
           best_move(&gameptr);
           x=gameptr.posx;
           y=gameptr.posy;
        }
        else
        {
            current_state gameptr(2);
            closegraph();
            suggest(2);
            suggest_grid(2);
            makebestmove(&gameptr);
            x=gameptr.posx;
            y=gameptr.posy;
        }       
        cout<<"\n\nTHE COMPUTER CHOSES TO MAKE THE MOVE : "<<x+1<<" , "<<y+1<<"\n";
        cout<<"\n\t\tENTER ANY CHARACTER TO CONTINUE : ";
        cin>>ch;
        gamegrid[x][y]='X';
        flip(x,y,2);
        score();
      }
    }
   i++;
  }
  if(!(possible(1)||possible(2)))
 { 
   closegraph();
   printboard();
   if(count1>count2)
   { 
    cout<<"\n\n THE GAME IS OVER!!!\n\nUSER HAS WON THE GAME\n\n";
    system("pause");
   }
  else
   { 
    cout<<"\n\n THE GAME IS OVER!!!\n\nCOMPUTER HAS WON THE GAME\n\n";
    system("pause");
   }
 }
}
  
/**************************************************************************************************  
//FUNCTION MAIN 
**************************************************************************************************/

int main()
{ 
  XInitThreads(); 
 time_t timer;
 int choice; char ch; int c,test,i; int win;
 int gd=DETECT,gm; 
 initgraph(&gd,&gm,NULL);
 do 
 { 
   srand(time(NULL));
   system("CLS");
   cout<<"WELCOME TO THE WORLD OF REVERSI\n\n\n";
   cout<<"PRESS \n\n1 : FOR TWO PLAYER GAME \n\n2 : FOR USER VERSUS COMPUTER GAME \n\n3 : TO HAVE A RANDOM GAME GENERATOR TO PLAY AGAINST COMPUTER\n\nANY OTHER NUMBER TO QUIT \n\n";
   cin>>choice;
   
   switch(choice)
   { 
     case 1  :  cout<<"\nTHE USER IS ALSO GIVEN THE CHOICE TO SELECT THE COLORS OF THE COINS OF \n\nPLAYER 1 AND PLAYER 2\n";
                cout<<"\n\nPRESS\n\n\n \n\n1 : BLUE\n\n2 : GREEN\n\n3 : CYAN\n\n4 : RED\n\n5 : MAGENTA\n\n6 : BROWN\n\n7 : LIGHTGREY\n\n8 : DARKGREY\n\n9 : LIGHTBLUE\n\n10: LGHTGREEN\n\n11: LIGHTCYAN\n\n12: LIGHTRED\n\n13: LIGHTMAGENTA\n\n14: YELLLOW\n\n15: WHITE\n\n\n";
                cout<<"\n\nCOLOUR FOR PLAYER 1 : "; cin>>color1;
                cout<<"\n\nCOLOR FOR PLAYER 2 : "; cin>>color2;
                two_player();
                break;
     case 2  :  cout<<"\nTHE USER IS ALSO GIVEN THE CHOICE TO SELECT THE COLORS OF THE COINS OF \n\nUSER AND COMPUTER\n";
                cout<<"\n\nPRESS\n\n\n \n\n1 : BLUE\n\n2 : GREEN\n\n3 : CYAN\n\n4 : RED\n\n5 : MAGENTA\n\n6 : BROWN\n\n7 : LIGHTGREY\n\n8 : DARKGREY\n\n9 : LIGHTBLUE\n\n10: LGHTGREEN\n\n11: LIGHTCYAN\n\n12: LIGHTRED\n\n13: LIGHTMAGENTA\n\n14: YELLLOW\n\n15: WHITE\n\n\n";
                cout<<"\n\nCOLOUR FOR USER : "; cin>>color1;
                cout<<"\n\nCOLOR FOR COMPUTER : "; cin>>color2;
                cout<<"\n\nENTER THE DEPTH OF SEARCH U WANT \n\n";
                cin>>D;
                one_player();
                break;
     case 3  :  win=0;
                cout<<"\nSELECT THE ALGORITHM WITH WHICH THE COMPUTER IS TO PLAY THE RANDOM GAME\n\nPRESS\n\n1 : MIN_MAX ALGORITHM\n\n2 : ALPHA- BETA PRUNING DONE WITH MIN-MAX\n\n";
                cin>>c;
                cout<<"\n\nENTER THE DEPTH OF SEARCH U WANT \n\n";
                cin>>D;
                cout<<"\nTHE NUMBER OF GAMES YOU WANT TO RUN RANDOM : \n\n";
                cin>>test;
                i=1;
                timer = (time(NULL));
                while(i<=test)
                { 
                  if(random_generator(c))
                  {
                    win++;
                  }                      
                  i++;
                }  
                cout<<"THE NUMBER OF WINS : "<<win<<"\n\nPERCENTAGE OF WIN : "<<((win*100.0)/(test))<<"\n\n";
                cout<<"THE TIME TAKEN FOR THIS EVALUATION : "<<time(NULL)-timer<<" SECONDS \n\n";
                break;            
     default :  system("CLS"); 
                cout<<"HOPE TO SEE U SOON....Bye!!\n";
   } 
   cout<<"\n\nWANT TO PLAY A FRESH NEW GAME?? (y/n) : ";
   cin>>ch;
 } while((ch=='y')||(ch=='Y'));

return 0;

}

 
