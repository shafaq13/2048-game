#include <stdio.h>
#include <string.h>//records name
#include <conio.h>//key board hit
#include <time.h>//random
#include <stdlib.h>//clear screen
#include <ctype.h>//escape button and up and down 

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define BR 219 
#define Exit 57

int matrix[5][5];
int m_score=0;
int count=0;

void initialize();
void Random_Value();
void score();
void start();
void Display();
int check();
void end();
void intro();
void wait();
void record();
void Down_M();
void Up_M();
void Left_M();
void Right_M();


void score()//this function is use to calculate the sum of the number on the grid after every move
{
	int i,j,sum=0;

	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(matrix[i][j]!=0)
			{
				sum=sum+matrix[i][j];
			}
		}

	}
	m_score=sum;
//pf in display
}

int check()/*it check whether the grid is full or not and also check that 2048 apper on the grid.
            If any condition turn true so assign flag value and return*/
{
	int i,j,flag,x=0;
	
	for(j=0 ; j<4 ; j++)
	{
		for(i=0 ; i<4 ; i++)
		{
			if (matrix[i][j]==2048)
			{
				flag=0;
				return flag;
			}
	    }
    }
    
	for(i=0 ; i<4 ; i++)
	{
		for(j=0 ; j<4 ; j++)
		{		
    		
			if ( matrix[i][j]!=0 && matrix[i+1][j] != matrix[i][j]  && matrix[i][j]!=matrix[i][j+1] )
			{
			  x++;
			  if(x==16)
			  {
			  	flag=1;
			  	return flag;
			  }
  			}
  			else 
  			{
  				flag=2;
  				return flag;//we dont need to check each bock because even if condition is true for one box then it can return and continue the game.
		    }
		}
	}
	
    
}

void intro()//give the instruction to the player
{
char start;
printf("\n\n\t\t\t**********Game 2048**********\t\t\t\n");
printf("Rules: \n");
printf("Press on arrow key to move\n");
printf("The game will end if 4 by 4 matrix will be full\n");
printf("to exit the game press 9\n");
printf("Press any key to start the game");
while(!kbhit());

}
void Start()//call the random function twice to generate two random value in the start and call display function placing the the random value in that   
{
Random_Value();
Random_Value();
Display();
}

void Display()//grids and digits are diplayed everytime when key is pressed.
{
    int i,j;
    system("cls");
    printf("\n\n\n\t\t\t2048\n");
    printf("\t\t\t\t\t\t SCORE  : %d\t\tMOVES: %d\n\n\n\n",m_score,count);
    printf("\t\t\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR);

    for(i=0;i<4;i++)
    {
    printf("\t\t\t %c      %c      %c      %c      %c\n",BR,BR,BR,BR,BR);/*leftover space around the digit in a box and the vertical border
																		in first half */
        printf("\t\t\t %c",BR);
        for(j=0;j<4;j++)
        {
            if(matrix[i][j]==0)
            {
                printf("      %c",BR);  // where number not is being generated and it is null we give 6 spaces and print a border ofcoursew.
            }
            else
                printf(" %4d %c",matrix[i][j],BR);//the boxes where  any no. is present will have 1 space on both ends of the 4 digit no.   
        }
        printf("\n\t\t\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR,BR);
    }

}

void end(int game_on)//diplay the statement according to win or loss
{ 
	if(game_on==0) // user won the game if game_on is 0
	{
		printf("\n\n\n\t\t\t*******CONGRATULATIONS YOU WON*******");
	}
	else// user loss the game if game_on is 1
	{
		printf("\n\n\n\t\t\tYOU LOST!!!");
	}
	printf("\n\nPress any key to add record\n");
	while(!kbhit());// any key in the keybord will be press to continue.

	
}

void record()//player record is saved in file and displayed
{
	FILE *fptr;
	char name[200];
	
	fptr=fopen("Game.txt","a");
	printf("************************************************************************");
	printf("\n\nRECORD FOR THE NEW PLAYER\n");
	printf("\nEnter the name of the player : ");
	gets(name);
	
	fprintf(fptr,"\nRECORD FOR THE NEW PLAYER\n");
	fprintf(fptr,"Player Name = %s\n",name);
	fprintf(fptr,"Moves = %d\n",count);
	fprintf(fptr,"Total Score = %d\n",m_score);          //these steps will print the data in the file and not on screen
	
	printf("\n\n/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/");
	printf("\n\nRECORD FOR THE NEW PLAYER\n");                                         //this is to be displayed on the screen for the user
	printf("Player Name = %s\n",name);
	printf("Moves = %d\n",count);
	printf("Total Score = %d\n\n",m_score);
	printf("/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/");
	while(!kbhit());
	fclose(fptr);

}

void Move(int Arrow)//takes user to the function according to the key which is pressed.And increment of count is done to save moves and random value is generate which is all displayed in the function display  
{
	int a,i,j;
    switch(Arrow)
    {
        case UP:
            {
                Up_M();
                break;
            }
        case DOWN:
            {
                Down_M();
                break;
            }
        case LEFT:
            {
                Left_M();
                break;
            }
        case RIGHT:
            {
                Right_M();
                break;
            }
        default:
            {
                return;
            }
    }
    count=count+1;//increment of the move
    score();
	Random_Value();
    Display();
}
void initialize()//all matrix is initialize to the 0
{
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			matrix[i][j]=0;
		}
	}
}


int main ()
{
    char Arrow;
    int game_on;
    
    initialize();
    intro();
    Start();
    
    Arrow=DOWN;
    
    while(Arrow!=Exit)//loop will repeat untill digit nine is press
    {
        Arrow=getch();
        fflush(stdin);
        Move(Arrow);
        game_on = check();//value return will decide user win the game or loss or will continue
        if(game_on==2)//game will be continue
         {
            continue;
         }
        else if(game_on==0 || game_on==1)//game end user win or loss
        {	
          end(game_on);
          system("cls");
          record();
          break;
        }
    }

    system("cls");
    printf("\n\n\n\t****THANKYOU FOR PLAYING****");
	return 0;
}


