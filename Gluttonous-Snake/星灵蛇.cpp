#include <iostream>
#include <cstdio>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <sstream>
#include <fstream>

//   修改游戏介绍  
using namespace std;
bool double_fly;
bool return_main;
int cross_num;
static int length=3;
static int length2=3;
static int direction=2;
static int direction2=1;
static int temp;
static int times;
static int score=1;
static int your_score;
static int died=0;
static int died2=0;
static int died3=0;
static int mainlist=0;
static bool rush=0,jump=0;
static int a,judge_role; 
string id;
	

struct Snake
{
	int x;
	int y;
} snake[500];
Snake snake2[500];

struct Cross
{
	int x;
	int y;	
} cross[20];

struct Smile
{
	int x;
	int y;	
} smile[3];
Smile smile2[3];

struct User
{
	string id;
	string score;
}user[1000]; 

struct Warp_gate //折跃门 
{
	int x;
	int y;
} warp_gate[4];



void color(int a)//颜色函数
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
void gotoxy(int x,int y)
{
HANDLE hout;
COORD coord;
coord.X=x;
coord.Y=y;
hout=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hout,coord);
}
void screen()
{ 
int i,j; 
if(double_fly==1)
{

	for(i=28;i==28;i++)
	{
		for(j=1;j<=23;j++)
		{
			gotoxy(i,j);
			color(4);
			printf("▇");
			color(7);
		}	
	}
}
for(i=56;i<=56;i++) 
{
for(j=1;j<=23;j++)
{
gotoxy(i,j);
color(17);
printf("▇");
color(7);
}
}
for(i=0;i<=0;i++) 
{
for(j=1;j<=23;j++)
{
gotoxy(i,j);
color(17);
printf("▇");
color(7);
}
}
for(j=1;j<=1;j++) 
{
for(i=0;i<=57;i+=2)
{
gotoxy(i,j);
color(17);
printf("▇");
color(7);
}
}

for(j=23;j<=23;j++)
{
for(i=0;i<=57;i+=2)
{
gotoxy(i,j);
color(17);
printf("▇");
color(7);
}
}

gotoxy(64,2);
printf("▅▅▅▅▅▅▆▇▇▇▇▆▅▅▅▅▄\n");
gotoxy(64,3);
printf("▅▄▅▅▅▆▇▆▅▅▅▆▅▃▃▃▃\n");
gotoxy(64,4);
printf("▅▄▄▄▅▆▅▄▃▂▂▃▄▄▃▃\n");
gotoxy(64,5);
printf("▃▃▃▃▆▅▄▃▂▂▂▂▃▄▃▃▃\n");
gotoxy(64,6);
printf("▃▂▃▃▆▅▄▃▂▂▂▂▃▅▃▃▂\n"); 
gotoxy(64,7);
printf("▄▃▃▃▆▅▄▃▂▂▂▁▃▄▃▃▂\n");
gotoxy(64,8);
printf("▃▃▃▃▅▆▅▄▅▅▄▃▄▃▂▂▁\n");
gotoxy(64,9);
printf("▃▂▃▂▄▅▄▃▄▃▄▃▃▂▁▁▁\n");
gotoxy(64,10);
printf("▃▂▂▂▃▅▄▃▄▃▃▃▂▁▁▁▁\n");
gotoxy(64,11);
printf("▂▂▂▂▂▄▄▄▄▃▃▃▂▁▁▁▁\n");
gotoxy(64,12);
printf("▂▁▂▁▁▅▆▅▄▃▂▃▂▁▁▁▁\n");
gotoxy(64,13);
printf("▁▁▁▁▃▄▄▄▃▂▂▁ ▁▁▁▁\n");
gotoxy(64,14);
printf("▂▄▅▅▄▄▅▄▃▃▃▂\n");
gotoxy(64,15);
printf("▂▃▄▄▄▄▃▂▃▁▃▅▅▄▃\n");
gotoxy(64,16);
printf("▅▅▅▅▅▅▅▄▃▅▃▄▅▅▅▅▄\n");
gotoxy(64,19);if(double_fly==0)
{ 
	printf("your score: 0 %c",11);
}
}
void write(string a)
{
	int i;
	for(i=0;;i++)
	{
		if(a[i]!='\0')
		{
		printf("%c",a[i]);
		Sleep(15);
		}
		else break;
	}
}

void rubbish()
{ 
if(double_fly==1)
{
gotoxy(snake[length].x,snake[length].y);
printf(" ");
gotoxy(snake2[length2].x,snake2[length2].y);
printf(" ");
}
else
{
gotoxy(snake[length].x,snake[length].y);
printf(" ");
}
}

void screen1()
{
	int i,j;
	for(i=0;i<=100;i++)
	for(j=0;j<=30;j++)
	{
		gotoxy(i,j);
		printf(" ");
	}
	Sleep(200);
	
}

void dieself() 
{
	int i;
	for(i=1;i<=length;i++)
	{
		if((snake[i].x==snake[0].x)&&(snake[i].y==snake[0].y))//0 is head
			{
				printf("\a"); 
				//color(12);
				//printf("你反身一口咬死了自己…");
				//color(7);
				//getch();
						Sleep(200); 
						died=1;
						printf("\a"); 
						screen1();
			}
	}	
	if(double_fly==1)
	{
		for(i=1;i<=length2;i++)
	{
		if((snake2[i].x==snake2[0].x)&&(snake2[i].y==snake2[0].y))//0 is head
		{
			printf("\a"); 
			//color(12);
			//printf("你反身一口咬死了自己…");
			//color(7);
			//getch();
					Sleep(200); 
					died2=1;
					printf("\a"); 
					screen1();
		}
	}
	}
}

void diewall()
{
	int i,j;
	if(double_fly==0)
	{
		if(snake[0].y==3) 
		{	
			if(snake[0].x==70) 
			{
				printf("\a");
				gotoxy(69,3);
				color(12);
				printf("+1s");
				color(7);
				Sleep(5000);
				died=1;
				printf("\a"); 
				screen1();
			}
			else return ;
		}
		else if((snake[0].x>55)||(snake[0].x<2)||(snake[0].y<2)||(snake[0].y>22))
		{
						Sleep(200); 
						died=1;
						printf("\a"); 
						screen1();
		}
    }
	if(double_fly==1)
	{
		
		if(snake[0].x==28||snake[0].x==29||snake[0].x==1||snake2[0].x==56||snake[0].y==23||snake[0].y==1)
		{
			Sleep(200);
			died=1;
			printf("\a");
			screen1();
		}
		if(snake2[0].x==29||snake2[0].x==28||snake2[0].x==56||snake[0].x==1||snake2[0].y==23||snake2[0].y==1)
		{
			Sleep(200);
			died2=1;
			printf("\a");
			screen1();
		}
	}
}
void copy()
{
	int i;
	for(i=length;i>=1;i--)
	{
		snake[i].x=snake[i-1].x;
		snake[i].y=snake[i-1].y;
	}
	if(double_fly==1)
	{
		for(i=length2;i>=1;i--)
		{
			snake2[i].x=snake2[i-1].x;
			snake2[i].y=snake2[i-1].y;
		}	
	}
}

void* judge_direction(void* args)
{
	for(;;) 
	{
		//Sleep(1);
		
		if(double_fly==0)
		{
			char a;
			a=getch();
		if(judge_role==1)
		{
			
			if(a=='Q')
		    rush=1;
		    else rush=0;
		}
		else if(judge_role==2)
		{
		    if(a=='E')
		    jump=1;
		}
		switch(a)
		{
			case 72:direction=1;break;//up
			case 80:direction=2;break;//down
			case 75:direction=3;break;//left
			case 77:direction=4;break;//right
			default:break; //in this way, if there is no keyin , just go on
		}
		}
		if(double_fly==1)
		{
			switch(getch())
			{
			case 87:direction=1;break;//up
			case 83:direction=2;break;//down
			case 65:direction=3;break;//left
			case 68:direction=4;break;//right
			case 72:direction2=1;break;//up
			case 80:direction2=2;break;//down
			case 75:direction2=3;break;//left
			case 77:direction2=4;break;//right
			default:break; //in this way, if there is no keyin , just go on
			}
		}
	}
}

void keyin()
{
	if(rush==0)
	Sleep(temp-300);
	else 
	Sleep((temp-300)/4);
	if(double_fly==0)
	{
		if(jump==0)
		switch(direction)
		{
			case 1:
				snake[0].y-=1;
				break;
			case 2:
				snake[0].y+=1;
				break;
			case 3:
				snake[0].x-=1;
				break;
			case 4:
				snake[0].x+=1;
				break;
			default:
				exit(1);			
		}
		else if(jump==1)
		{
		
			switch(direction)
		{
			case 1:
				snake[0].y-=3;
				break;
			case 2:
				snake[0].y+=3;
				break;
			case 3:
				snake[0].x-=5;
				break;
			case 4:
				snake[0].x+=5;
				break;
			default:
				exit(1);			
		}
			jump=0;
		}
	}
	if(double_fly==1)
		{
			switch(direction)
			{
				case 1:
					snake[0].y-=1;
					break;
				case 2:
					snake[0].y+=1;
					break;
				case 3:
					snake[0].x-=1;
					break;
				case 4:
					snake[0].x+=1;
					break;
				default:
					exit(1);			
			}
			switch(direction2)
			{
				case 1:
					snake2[0].y-=1;
					break;
				case 2:
					snake2[0].y+=1;
					break;
				case 3:
					snake2[0].x-=1;
					break;
				case 4:
					snake2[0].x+=1;
					break;
				default:
					exit(1);			
			}
		}
}
void warp_in() //进入折跃门 
{
	if((snake[0].x==warp_gate[0].x||snake[0].x==warp_gate[0].x-1)&&snake[0].y==warp_gate[0].y)
	{
		snake[0].x=warp_gate[1].x;
		snake[0].y=warp_gate[1].y;
	}
	else if((snake[0].x==warp_gate[2].x||snake[0].x==warp_gate[2].x-1)&&snake[0].y==warp_gate[2].y)
	{
		snake[0].x=warp_gate[3].x;
		snake[0].y=warp_gate[3].y;
	}
	else if((snake2[0].x==warp_gate[0].x||snake2[0].x==warp_gate[0].x-1)&&snake2[0].y==warp_gate[0].y)
	{
		snake2[0].x=warp_gate[1].x;
		snake2[0].y=warp_gate[1].y;
	}
	else if((snake2[0].x==warp_gate[0].x||snake2[0].x==warp_gate[2].x-1)&&snake2[0].y==warp_gate[2].y)
	{
		snake2[0].x=warp_gate[3].x;
		snake2[0].y=warp_gate[3].y;
	}
}
void double_fly_game()
{
	warp_gate[0].x=27;
	warp_gate[0].y=2;
	warp_gate[1].x=30;
	warp_gate[1].y=22;
	warp_gate[2].x=55;
	warp_gate[2].y=2;
	warp_gate[3].x=2;
	warp_gate[3].y=22;
	screen1();
	gotoxy(0,0);
	double_fly=1;
	char qqq,jjj;
	int temp2;
	length=length2=3;
	write("欢迎来到拉克希尔仪式\n"); //Alarak Marash 
	write("众所周知，塔达林是星灵的一个分支组织。\n");
	write("拉克希尔仪式是塔达林的升格仪式，而Alarak是塔达林的升格第一人\n");
	write("在与Artanis结盟后，Alarak决定对现任的大领主——Marash发起拉克希尔仪式。\n");
	write("拉克希尔仪式的规则是：进行仪式的两方搜集灵能，若其中一方被推入地嗪深渊或是虚空中则另一方获得胜利。\n");
	write("地图的中央是地嗪深渊，Alarak出生在右边的陆地，用光标键操作，Marash出生在左边陆地，用WSAD操作\n");
	write("只有通过陆地右上角的wrap gate才能够折跃到另一块陆地上，双方需要拾取");color(14);printf(" $ ");color(7);write("来获取灵能\n");
	write("每获取一点灵能，都会使对方身体变长，这会使对方更容易掉入深渊\n"); 
	write("并且双方的身体都有等离子护盾覆盖，只有头部裸露在外，双方应保护好自己的头部。");
	write("下面请选择人物性格\n\n"); 
	getch();
	printf("请Marash选择双方的性格： A 暴躁的 B 普通的 C 温和的\n");
	cin>>qqq;
	switch(qqq)
	{
		case'A':temp=300;
		case'B':temp=350;
		case'C':temp=450;
		default :temp=450;
	}
	system("cls");
	gotoxy(0,0);
	printf("请Alarak选择双方的性格： A 暴躁的 B 普通的 C 温和的\n");
	cin>>jjj;
	switch(jjj)
	{
		case'A':temp2=300;
		case'B':temp2=350;
		case'C':temp2=450;
		default: temp=450;
	}
	temp=(temp+temp2)/2;
	system("cls");
	int i,j;
	died=died2=0;
	direction=2;
	direction2=1;
	srand(time(0));
	for(i=0;i<=3;i++)
	{
		snake[i].x=4;
		snake[i].y=5-i;
		snake2[i].x=53;
		snake2[i].y=18+i;
	}
	for(j=0;j<=2;j++)
	{
		smile[j].x=rand()%23+3;
		smile[j].y=rand()%19+3;		
		smile2[j].x=rand()%22+31;
		smile2[j].y=rand()%20+2;
	}
	screen1();
	screen();
	for(j=1;j<=3;j++)//draw the snake
	{
		gotoxy(snake[j].x,snake[j].y);
		printf("*");
		gotoxy(snake2[j].x,snake2[j].y);
		printf("*"); 
	}
	for(j=0;j<=2;j++)
	{
		gotoxy(smile[j].x,smile[j].y);
		color(14);
		printf("$");//同上 
		color(7);
		gotoxy(smile2[j].x,smile2[j].y);
		color(14);
		printf("$");//同上 
		color(7);
	}
	pthread_t input;//线程id  
	int ret=pthread_create(&input,NULL,judge_direction,NULL); 
	pthread_detach(input);
	while(kbhit())
	getch();
	direction=2;
	direction2=1;
	while(1)
	{
	color(219); 
	gotoxy(54,2);
	printf("●");
	gotoxy(2,22);
	printf("●");
	gotoxy(26,2);
	printf("●");
	gotoxy(30,22);
	printf("●");
	color(07);
		keyin();
		warp_in(); 
		int i,j,k;
		gotoxy(snake[0].x,snake[0].y);
		color(10);
		printf("*");//draw the head
		color(7);
		gotoxy(snake2[0].x,snake2[0].y);
		color(12);
		printf("*");//draw the head
		color(7);
		diewall();
		dieself();
		for(i=1;i<=length;i++)
		{
			if(snake2[0].x==snake[i].x&&snake2[0].y==snake[i].y)
			died2=1;
		}
		for(i=1;i<=length2;i++)
		{
			if(snake[0].x==snake2[i].x&&snake[0].y==snake2[i].y)
			died=1;
		}
		if(snake[0].x==snake2[0].x&&snake[0].y==snake2[0].y)
		{
			died3=1;
		}
		if(died==1)
		{	
			char c;
			screen1();
			gotoxy(5,5);
			printf("           Alarak赢了");
			//getch();
			printf("\n           是否退出游戏：A 退出 B 退出\n");
			cin>>c;
			switch(c)
			{
				case 'A':exit(1);
				case 'B':exit(1);
				default: ;
			}
		}
		
		if(died2==1)
		{
			char c;
			screen1();
			gotoxy(5,5);
			printf("           Marash赢了");
			//getch();
			printf("\n           是否退出游戏：A 退出 B 退出\n");
			cin>>c;
			switch(c)
			{
				case 'A':exit(1);
				case 'B':exit(1);
				default: ;
			}	 	
		}
		for(i=0;i<=2;i++)
		{
			int a=0,b=0;
			if(((snake[0].x==smile[i].x)&&(snake[0].y==smile[i].y))) 
				a=1;
			if(((snake[0].x==smile2[i].x)&&(snake[0].y==smile2[i].y)))
				a=2;
			if(((snake2[0].x==smile2[i].x)&&(snake2[0].y==smile2[i].y))) 
				b=1;	//eat food
			if(((snake2[0].x==smile[i].x)&&(snake2[0].y==smile[i].y)))
				b=2;	
			if(a==1)
			{
				length2+=1;
					int c;
					srand(time(NULL));
					while(a==1)
				{
					smile[i].x=(rand()%24+3);
					smile[i].y=(rand()%19+2);
					for(c=0;c<=length;c++)
					{ 
						if(((snake[c].x==smile[i].x)&&(snake[c].y==smile[i].y))) //check if they are one
						{
							a=1;break;
						}
						else a=0;
					}
					for(c=0;c<=2;c++)
					{
						if(i==c) continue;
						if(a==1) break;
						if(smile[i].x==smile[c].x&&smile[i].y==smile[c].y)
						{
							a=1;break;
						}
						else a=0;
					}
					for(c=0;c<=length2;c++)
					{ 
						if(a==1) break;
						if(((snake2[c].x==smile[i].x)&&(snake2[c].y==smile[i].y))) //check if they are one
						{
							a=1;break;
						}
						else a=0;
					}
				}
					
			}
			if(a==2)
			{
				length2+=1;
					int c;
					srand(time(NULL));
					while(a==2)
				{
					smile2[i].x=(rand()%24+31);
					smile2[i].y=(rand()%19+3);
					for(c=0;c<=length;c++)//problem
					{ 
						if(((snake[c].x==smile2[i].x)&&(snake[c].y==smile2[i].y))) //check if they are one
						{
							a=2;break;
						}
						else a=0;
					}
					for(c=0;c<=2;c++)
					{
						if(i==c) continue;
						if(a==2) break;
						if(smile2[i].x==smile2[c].x&&smile2[i].y==smile2[c].y)
						{
							a=2;break;
						}
						else a=0;
					}
					for(c=0;c<=length2;c++)//problem
					{ 
						if(a==2) break;
						if(((snake2[c].x==smile2[i].x)&&(snake2[c].y==smile2[i].y))) //check if they are one
						{
							a=2;break;
						}
						else a=0;
					}
				}
					
			}
			if(b==1)
			{
				length+=1;
					int c;
					srand(time(NULL));
					while(b==1)
				{					
					smile2[i].x=(rand()%24+31);
					smile2[i].y=(rand()%19+3);
					for(c=0;c<=length2;c++)
					{ 
						if(((snake2[c].x==smile2[i].x)&&(snake2[c].y==smile2[i].y))) //check if they are one
						{
							b=1;break;
						}
						else b=0;
					}
					for(c=0;c<=2;c++)
					{
						if(i==c) continue;
						if(b==1) break;
						if(smile2[i].x==smile2[c].x&&smile2[i].y==smile2[c].y)
						{
							b=1;break;
						}
						else a=0;
					}
					for(c=0;c<=length;c++)
					{ 
						if(b==1) break;
						if(((snake[c].x==smile2[i].x)&&(snake[c].y==smile2[i].y))) //check if they are one
						{
							b=1;break;
						}
						else b=0;
					}
				}
					
			}
			if(b==2)
			{
				length+=1;
					int c;
					srand(time(NULL));
					while(b==2)
				{					
					smile[i].x=(rand()%24+3);
					smile[i].y=(rand()%19+2);
					for(c=0;c<=length2;c++)
					{ 
						if(((snake2[c].x==smile[i].x)&&(snake2[c].y==smile[i].y))) //check if they are one
						{
							b=2;break;
						}
						else b=0;
					}
					for(c=0;c<=2;c++)
					{
						if(i==c) continue;
						if(b==2) break;
						if(smile[i].x==smile[c].x&&smile[i].y==smile[c].y)
						{
							b=2;break;
						}
						else b=0;
					}
					for(c=0;c<=length;c++)
					{ 
						if(b==2) break;
						if(((snake[c].x==smile[i].x)&&(snake[c].y==smile[i].y))) //check if they are one
						{
							b=2;break;
						}
						else b=0;
					}
				}
					
			}
				gotoxy(smile[i].x,smile[i].y);
				color(14);
				printf("$");
				color(7);
				gotoxy(smile2[i].x,smile2[i].y);
				color(14);
				printf("$");
				color(7);
		} 
				rubbish();
				copy();
	}
}

void hero_list()
{
	mainlist=0;
	screen1();
	string user_id;
	string user_score;
	string fly1,fly2; 
	int k=0;
	 ifstream acco("请全屏进行游戏并打开大写锁定",ios::in);
	 while(getline(acco,user_id)&&getline(acco,user_score)&&getline(acco,fly1)&&getline(acco,fly2))
	 {
	 	user[++k].id=user_id;
	 	user[k].score=user_score;
	 }
	 int ii,iii;
	 string by_score;
	 string by_id;
	 for(ii=1;ii<=k;ii++)
	 for(iii=2;iii<=k;iii++)
	 {
	 	if((user[iii].score.length()>user[iii-1].score.length())||user[iii].score.length()<user[iii-1].score.length())
	 	{
	 		if(user[iii].score.length()>user[iii-1].score.length())
	 		{
	 		by_id=user[iii].id;
			by_score=user[iii].score;
			user[iii].id=user[iii-1].id;
			user[iii].score=user[iii-1].score;
			user[iii-1].id=by_id;
			user[iii-1].score=by_score;
			}
			else ;
		}
	 	else if(user[iii].score>user[iii-1].score)
	 	{
	 		by_id=user[iii].id;
			by_score=user[iii].score;
			user[iii].id=user[iii-1].id;
			user[iii].score=user[iii-1].score;
			user[iii-1].id=by_id;
			user[iii-1].score=by_score; 	
		}
	 }
	 if(k>20)
	 {
	 	k=20;
	 }
	gotoxy(0,0);
	 for(ii=1;ii<=k;ii++)
	 {
	 	cout<<setw(20)<<user[ii].id; 
	 	cout<<"  得分："<<user[ii].score<<endl;
	 }
	 acco.close();
	 cout<<"5s后返回主菜单…\n";
	 Sleep(1000);
	 cout<<"-1s…";	
	 Sleep(1000);
	 cout<<"-1s…";	
	 Sleep(1000);
	 cout<<"-1s…";	
	 Sleep(1000);
	 cout<<"-1s…";	
	 Sleep(1000);
	 cout<<"-1s…";	  
	 mainlist=1;
}



void save(string id,int final_score) 
{
     string user_id;
	 int user_score;
	 user_id=id;
	 user_score=final_score;
	 ofstream user;
	 user.open("请全屏进行游戏并打开大写锁定",ios::app);
	 user<<user_id<<endl<<user_score<<endl;
	 user.close(); 
}


void paint()
{
	
color(1);
cout<<"           ■■■   ■     ■  ■■■  ■    ■ ■■■■";
color(7);
cout<<endl;
color(2);
cout<<"          ■    ■  ■■   ■ ■    ■ ■   ■  ■";
color(7);
cout<<endl;
color(3);
cout<<"          ■        ■ ■  ■ ■    ■ ■  ■   ■";
color(7);
cout<<endl;
color(4);
cout<<"           ■■■   ■  ■ ■ ■■■■ ■■     ■■■";
color(7);
cout<<endl;
color(5);
cout<<"                ■  ■   ■■ ■    ■ ■  ■   ■";
color(7);
cout<<endl;
color(6);
cout<<"          ■    ■  ■     ■ ■    ■ ■   ■  ■";
color(7);
cout<<endl;
color(8);
cout<<"           ■■■   ■     ■ ■    ■ ■    ■ ■■■■";
color(7);
cout<<endl;
Sleep(1000);

}

void paint2()
{
	color(12);
cout<<"           ■■■   ■     ■  ■■■  ■    ■ ■■■■";
color(7);
cout<<endl;
color(13);
cout<<"          ■    ■  ■■   ■ ■    ■ ■   ■  ■";
color(7);
cout<<endl;
color(15);
cout<<"          ■        ■ ■  ■ ■    ■ ■  ■   ■";
color(7);
cout<<endl;
color(14);
cout<<"           ■■■   ■  ■ ■ ■■■■ ■■     ■■■";
color(7);
cout<<endl;
color(8);
cout<<"                ■  ■   ■■ ■    ■ ■  ■   ■";
color(7);
cout<<endl;
color(10);
cout<<"          ■    ■  ■     ■ ■    ■ ■   ■  ■";
color(6);
cout<<endl;
color(11);
cout<<"           ■■■   ■     ■ ■    ■ ■    ■ ■■■■";
color(7);

}


void start_gif()
{
	 
paint();if(kbhit()) return;
system("cls");
cout<<endl;
paint();if(kbhit()) return;
system("cls");
cout<<endl<<endl;
paint();if(kbhit()) return;
system("cls");
cout<<endl<<endl<<endl;
paint();if(kbhit()) return;
system("cls");
cout<<endl<<endl<<endl<<endl;
paint();if(kbhit()) return;
system("cls");
cout<<endl<<endl<<endl<<endl<<endl;
paint();//Beep(150,300);
system("cls");if(kbhit()) return;
cout<<endl<<endl<<endl<<endl<<endl<<endl;
paint2();Sleep(1000);//Beep(200,300);
system("cls");if(kbhit()) return;
cout<<endl<<endl<<endl<<endl<<endl<<endl;
paint();//Beep(250,300);
system("cls");if(kbhit()) return;
cout<<endl<<endl<<endl<<endl<<endl<<endl;
paint2();Sleep(1000);//Beep(200,300);
system("cls");if(kbhit()) return;
cout<<endl<<endl<<endl<<endl<<endl<<endl;
paint();//Beep(350,300);
system("cls");if(kbhit()) return;
cout<<endl<<endl<<endl<<endl<<endl<<endl;
paint2();Sleep(1000);//Beep(200,300);
system("cls");if(kbhit()) return;
cout<<endl<<endl<<endl<<endl<<endl<<endl;
paint();//Beep(250,300);
system("cls");if(kbhit()) return;
cout<<endl<<endl<<endl<<endl<<endl<<endl;
paint2();Sleep(1000);//Beep(180,300);
 
}

int main()
{
	
	start_gif();
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	paint2();
	printf("\n\n            Designed by 何宗达\n\n");
	write("\n          欢迎来到星灵蛇游戏");
	write("\n          星灵蛇是“方舟”——亚顿之矛上的街机小游戏");
	write("\n          传说星灵大主教Artanis每天都玩星灵蛇游戏");
	write("\n          ......");
	Sleep(500);
	write("\n          你好，朋友，请告诉我你的名字 ："); 
	getline(cin,id); 
	screen1();
loop2:
	void copy();
	void keyin();
	void diewall();
	void dieself();
	void rubbish();
	void screen();
	void screen1();
	screen1(); 
	direction=2;
	return_main=0;
	int i=0,j=0,k=0;
	gotoxy(0,0);
	
	cout<<"   请选择游戏模式(严格区分大小写并以回车键结尾)\n";
	cout<<"   A. 单人模式——虚空中的探索\n";
	cout<<"   B. 双人模式——拉克希尔仪式\n";
	cout<<"   C. 查看排行榜 \n  "<<endl;
	
	char choice;
	scanf("%c",&choice);
	switch(choice)
	{
		case 'A':break;
		case 'B':temp=450;double_fly_game();break;
		case 'C':hero_list();while(mainlist==0) ;goto loop2; break;
		default:goto loop2;
	}
	cout<<"\n\n\n\n  ";
	write("请选择你的英雄:\n");
	cout<<"  A. Artanis——Artanis拥有利刃冲锋技能\n";
	cout<<"  B. Zeratul——Zeratul拥有闪烁技能\n   "; 
rejudge:
	char choice_role;
	scanf("%c",&choice_role);
	switch(choice_role)
	{
		case 'A':judge_role=1;break;
		case 'B':judge_role=2;break;
		default :goto rejudge;
	} 
	screen1(); 
	gotoxy(0,0);
	if(judge_role==1)
{	
	write(" 众所周知，Artanis是达拉姆的大主教——一位年轻的圣堂武士\n");
	write(" 在本模式中你要控制Artanis搜集灵能——");color(14);printf(" $ ");color(7);
	write("\n 并躲避脊针爬虫形成的障碍——");color(12);printf(" X ");color(7);
	write("\n 每次拾取灵能后Artanis都会变得更强（长？）");
	write("\n 难度越高 Artanis移动的越快 单次拾取获取的能量也就越高\n");
	write(" Artanis作为一个圣堂武士可以使用「利刃冲刺」技能来冲锋\n");
	color(11);
	printf(" Q键");
	color(7);
	write(" 让Artanis开启「利刃冲刺」，方向键中断该技能\n"); 
}
	else if(judge_role==2)
{	
	write(" 众所周知，Zeratul是黑暗圣堂的教长——一位令人尊敬的长者\n");
	write(" 在本模式中你要控制Zeratul搜集灵能——");color(14);printf(" $ ");color(7);
	write("\n 并躲避脊针爬虫形成的障碍——");color(12);printf(" X ");color(7);
	write("\n 每次拾取灵能后Zeratul都会变得更强（长？）");
	write("\n 难度越高 Zeratul移动的越快 单次拾取获取的能量也就越高\n");
	write(" Zeratul作为一个黑暗圣堂武士可以使用「闪烁」技能来向前闪现躲避障碍\n");
	color(11);
	printf(" E键");
	color(7);
	write(" 让Zeratul施放「闪烁」\n"); 
}
	write(" 下面请选择难度\n ");
	printf("A  easy          B normal\n ");
	printf("C  difficult     D Assistant Wang\n "); 
loop5: 
		//write 
	scanf("%c",&choice);
	switch(choice)
	{
		case 'A':temp=550;times=1;cross_num=4;break;
		case 'B':temp=450;times=2;cross_num=8;break;
		case 'C':temp=400;times=3;cross_num=12;break;
		case 'D':temp=350;times=4;cross_num=20;break;
		default: goto loop5;
	}
	if(judge_role==1)
	switch(choice)
	{
		case 'A':cout<<"单人easy 难度：Artanis移动的很慢 \n";break;
		case 'B':cout<<"单人normal 难度：Artanis移动的较慢 \n";break;
		case 'C':cout<<"单人difficult 难度：Artanis移动的较快 \n";break;
		case 'D':cout<<"单人nightmarish 难度：Artanis在这里看不到未来\n";break; 
		default: ; 
	}
	else if(judge_role==2)
	switch(choice)
	{
		case 'A':cout<<"单人easy 难度：Zeratul移动的很慢 \n";break;
		case 'B':cout<<"单人normal 难度：Zeratul移动的较慢 \n";break;
		case 'C':cout<<"单人difficult 难度：Zeratul移动的较快 \n";break;
		case 'D':cout<<"单人nightmarish 难度：Zeratul在这里看不到未来\n";break; 
		default: ; 
	} 
	cout<<"   请稍等 游戏正在载入中";
	score=0;
	your_score=0;
	died=0;
	length=3;
	Beep(523,500);
	//Sleep(400);
	cout<<".";
	Beep(587,500);
	//Sleep(400);
	cout<<".";
	Beep(659,500);
	//Sleep(400);
	cout<<".";	
	Beep(698,500);	
	//Sleep(400);
	cout<<".";
	Beep(784,500);
	//Sleep(400);
	cout<<".";
	Beep(880,500);
	//Sleep(400);
	cout<<".";
	Beep(980,500);
	Beep(1060,500);
	srand(time(0));
	for(j=0;j<=3;j++)
	{
		snake[j].x=4;
		snake[j].y=5-j;
	}
	for(k=0;k<=cross_num-1;k++)
	{
		cross[k].x=rand()%50+3;
		cross[k].y=rand()%20+3;
	}
	for(j=0;j<=2;j++)
	{
		smile[j].x=rand()%52+3;
		smile[j].y=rand()%15+3;
	}
	screen1();
	screen();
	for(j=1;j<=3;j++)//draw the snake
	{
		gotoxy(snake[j].x,snake[j].y);
		//color(3);
		printf("*");
		//color(7);
	}	
	for(j=0;j<=cross_num-1;j++)
	{
		gotoxy(cross[j].x,cross[j].y);
		color(12);
		printf("X");//这里的数字可以改成别的图标 
		color(7);
	}
	for(j=0;j<=2;j++)
	{
		gotoxy(smile[j].x,smile[j].y);
		color(14);
		printf("$");//同上 
		color(7);
	}
	pthread_t input;//线程id 
	int ret=pthread_create(&input,NULL,judge_direction,NULL); 
	pthread_detach(input);
	direction=2;
	while(1)
	{
		if(return_main==1)
		goto loop2;
		keyin();
		int i,j,k;
		gotoxy(snake[0].x,snake[0].y);
		if(judge_role==1)
	{
		color(15);
		printf("#");//draw the head
		color(7);
	}
		else if(judge_role==2)
	{
		color(10);
		printf("#");//draw the head
		color(7);
	}	
	gotoxy(64,20);
	color(11);
	if(judge_role==1)
{
	if(rush==1)
	{
	printf("Artanis使用了利刃冲刺        ");
	}
	else if(!a)
	{
	printf("Artanis在虚空中探索          ");	
	} 
	color(7);
}
	else if(judge_role==2)
{	
	if(jump==1)
	{
	printf("Zeratul使用了闪烁        ");
	}
	else
	{
	printf("Zeratul在虚空中探索          ");	
	} 
	color(7);
}	
		diewall();
		dieself();
		for(i=0;i<=cross_num-1;i++)
		{
			if((snake[0].x==cross[i].x)&&(snake[0].y==cross[i].y)) //撞到障碍
			{
				//	color(12);
				//	printf("you choose death");
				//	color(7);
					Sleep(200); 
					died=1;
					printf("\a"); 
					screen1();

				//	getch();  
				
			}
		}
		if(died==1)
		{	
			save(id,your_score);	
			gotoxy(30,10);
			if(judge_role==1)
			write("Artanis由于你的操作湮灭在了虚空中");
			else if(judge_role==2)
			write("Zeratul由于你的操作湮灭在了虚空中");
			Sleep(1000);
			gotoxy(30,11);
			write("game over\n");
			write("                              你的分数: ");printf("%d  ",your_score);
			write("再来一局？\n");
			printf("                              Y:是   N:否 \n");
			printf("                              ");
			char con;
			scanf("%c",&con);
			switch(con)
			{
			case 'Y':goto loop2;//exit(1);
			break;
			case 'N':exit(1);break;
			default: ;
			}
		}
		for(i=0;i<=2;i++)
		{
			 a=0;
			if((snake[0].x==smile[i].x)&&(snake[0].y==smile[i].y)) 
				a=1;//eat food
			if(a==1)
			{ 
				int b=0;//
				length+=1;
				score+=1;
				your_score=score*times;	
				gotoxy(64,19);
				printf("your score: %d %c",your_score,11);			
				loop1:
					int c;
					srand(time(NULL));
					smile[i].x=(rand()%50+2);
					smile[i].y=(rand()%19+2);
					for(c=0;c<=length;c++)
					{ 
						if(((snake[c].x==smile[i].x)&&(snake[c].y==smile[i].y))) //check if they are one
						{goto loop1;}
					
					}
					for(j=0;j<=2;j++)
					{
						if(i==j) continue;
						if(smile[i].x==smile[j].x&&smile[i].y==smile[j].y)
						{
							goto loop1;
						}
					}
					for(j=0;j<=cross_num-1;j++)
					{
						if((smile[0].x==cross[j].x)&&(smile[0].y==cross[j].y))
						{
						goto loop1;
						}	
					}
					
			}
				
				gotoxy(smile[i].x,smile[i].y);
				color(14);
				printf("$");
				color(7);
			
		} 
				rubbish();
				copy();
	}
		return 0;
}

