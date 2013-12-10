#include <stdio.h>
#include <conio.h>
int get_numpad_num (int,int);
int get_x_from_numpad_num(int num);
int get_y_from_numpad_num(int num);
void show_title();
void add_players(int num);
void clear_players();
void show_players();
int check_win();
int get_input();
int check_num_available_or_not(int num);
int check_bord_filled_or_not();
int check_game_over();
int adding_value();

int turn=0;
int players[3][3];	
int main ()
{	

	int j,k,num;
	//start of game
    start:;	
	//clearing the players
	clear_players();
	show_players();
	int z;
	for(z=0;z<10;z++)
	{
		//to store if the player wants to restart or not
		int val;
		val=adding_value();
		if (val==1)
		{
			goto end_game;
		}
		show_players();
		//printf("%d",check_bord_filled_or_not());
		switch (check_game_over())
		{
		case 2:
             
              if (turn==0)
                 printf("\n X wins");
              else
                  printf("\n X wins");
             
        case 1:
             turn=1;
             goto end_game;
             break;
        }
		/*if  (check_game_over()!=0)
			{
		goto end_game;
			}*/
	}	
	end_game:;
	char ans;
	printf("\n Play again?(y/n)");
	ans=getch();
	if (ans=='y')
	   goto start;
    else 
         printf("\n\t\t THANK YOU FOR PLAYING");
         getch();
	return 0;
}


int get_numpad_num(int x,int y)
{
int num=3*y+x+1;
return num;
}


int get_x_from_numpad_num(int num)
{
	int x;
	x=(num-1)%3;
	return x;	
}

int get_y_from_numpad_num(int num)
{
	int y;
	y=(num-1)/3;
	return y;	
}


void show_players()
{
	int j,k;
	char p[3][3];
	printf("\n");
	printf("\n");
	printf("\n");
	

	show_title();
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	  printf("\t keys and their position on bord:\n");
	printf("\n");	  
      printf("\t\t\t\t 7 | 8 | 9\n");
      printf("\t\t\t\t---+---+--- \n");
      printf("\t\t\t\t 4 | 5 | 6\n");
      printf("\t\t\t\t---+---+--- \n");
      printf("\t\t\t\t 1 | 2 | 3\n");	
	printf("\n");

	printf("\n");
	printf("\n");
	printf("\n");      
	printf("\n");	
	printf("\n");
	printf("\n");    	
	
	
	for (k=0;k<3;k++)
	{
		for (j=0;j<3;j++)
			if(players[j][k]==1)
				p[k][j]='X';
			else if(players[j][k]==2)
				p[k][j]='O';
			else
				p[k][j]=' ';	
			printf("\n");
	}

    printf("\t\t\t\t %c | %c | %c\n",p[2][0],p[2][1],p[2][2]);
      printf("\t\t\t\t---+---+--- \n");
      printf("\t\t\t\t %c | %c | %c\n",p[1][0],p[1][1],p[1][2]);
      printf("\t\t\t\t---+---+--- \n");
      printf("\t\t\t\t %c | %c | %c\n",p[0][0],p[0][1],p[0][2]);	
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t");
	if (turn==1)
	   printf("O's turn");
     else 
          printf("X's Turn");
	printf("\n");
    	printf("\n\t\t\tPress \'ESC\' to quit");	
	printf("\n\a");		
}

void clear_players()
{
	int j,k;
	for (k=0;k<3;k++)
	{
		for (j=0;j<3;j++)
			players[j][k]=0;
	}
}
void add_players(int num)
{
	players [get_x_from_numpad_num( num)][get_y_from_numpad_num(num)]= turn + 1;
}
int check_win()
{
	int j;
	for(j=0;j<3;j++)
	{
		if( players[j][0]==players[j][1] && players[j][0]==players[j][2] && players[j][0] !=0 )
			return 1;		
		else if( players[0][j]==players[1][j] && players[0][j]==players[2][j] && players[0][j] !=0  )
			return 1;
	}
	if(players[1][1] !=0)
	{
		if( players[0][0]==players[1][1] && players[0][0]==players[2][2] )
			return 1;
		else if( players[2][0]==players[1][1] && players[0][0]==players[0][2] )
			return 1;
	}
	return 0;
}


int get_input()
{
	int num;
	char n;

	do 
	{
		n=getch();		
		if (n>='1' && n<='9')
		 	num =n;
		 else if (n==27) //27==esc;
		 return -1;
		 else
		 {
             show_players();
				printf("\a \noption not available.   Enter choice(1-9)");
				num=0;
		}
	}
	while (num==0);
	return num-48;
}


int check_num_available_or_not(int num)
{
	if(players [get_x_from_numpad_num( num)][get_y_from_numpad_num(num)]==0)
		//0 if available
		return 0;
	else 
		return 1;
}

int check_bord_filled_or_not()
{
	int count=9;
	int c;
	for(c=1 ; c<=9 ; c++)
	{
		if(check_num_available_or_not(c)== 0)
		count--;
	}
	//9 if no place is available
	return count;
}

int check_game_over()
{
	if (check_win()==1)
		return 2;
	else if (check_bord_filled_or_not()==9)
		return 1;
	else
		return 0;
}


int adding_value()
{
	int c;
	g_input:;
	printf("\nenter choice(1-9)");
	c= get_input();
	if (c==-1) 
		 return 1;
	if(check_num_available_or_not(c)== 1)
	{
        show_players();
		printf("\aThe position is already occupied");
		goto g_input;
	}	
	else
	{
		add_players(c);
		turn++;
		turn%=2;
	}
	return 0;
}

void show_title()
{
  printf("         _____ ___   __      _____         __   _____   __     ___\n");
  printf("           |    |   /  \\       |    /\\    /  \\    |    /  \\   | \n");
  printf("           |    |   |     --   |   /__\\   |       |    |  |   |---\n");
  printf("           |   _|_  \\__/       |  /    \\  \\__/    |    \\__/   |___    \n");
     
}
