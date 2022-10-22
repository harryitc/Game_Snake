/* 
graphics in Dev-C++ - nguyenvanquan7826 
*/
#include<stdio.h>
#include <winbgim.h> 
#include<windows.h>
#include<mmsystem.h>
#include<stdlib.h>
#include<conio.h>
#include<sstream>
#include<string>
#include<time.h>
#define dai 300
#define rong 200
#define MAX 100
using namespace std;
#pragma comment(lib, "Winmm.lib")
int main();
char sc[200];
struct toado // khoi dong toa do x y
{
	int x;
	int y;
};
	typedef struct toado TOADO;
	TOADO dot[MAX]; // cho con ran co 25 dot
	int ran=5;
struct diemnguoichoi
{
	int diem;
	char s[30];
};
	typedef struct diemnguoichoi DNC;
// MUC LUC
//void Nhap_High_Score(char aaa[30],int diemm);
void showText(int x,int y,char *str){
	int c = getcolor();
	int color = rand() % 16 + 1;
	setcolor(color);
	outtextxy(x+3,y,str);
	setcolor(c);
	Sleep(30);
}
void setCircle(int x, int y, int r)
{
//			int c = getcolor();
//			setcolor(c);
//			int color = rand() % 16 + 1;
			setcolor(2);
//			circle(x,y,r);
			setfillstyle(1,2);
			circle(x,y,r);
			floodfill(x,y,2);
//			setcolor(c);
}
//void Tao_Menu();
void Khoi_Tao_Con_Ran();
//void DiChuyen();
//void Help();
//void choose_Menu();
//void about_Me();
//void huong_dan();
void Khoi_Tao_Con_Ran_Down(int e, int d); // c: td.x || d: td.y 
void Khoi_Tao_Con_Ran_Left(int e, int d);
void Khoi_Tao_Con_Ran_Right(int e , int d);
void Khoi_Tao_Con_Ran_Up(int e, int d); // c: td.x || d: td.y 
void ve_ran();
bool ktrachambien();
bool ktrachamthan();
void xoa_du_lieu_cu();
void Khoi_Tao_Snake_First(int e , int d );
void loop(); // vong lap chinh thay vi su dung ham main
void hoaqua(int quax, int quay, int *ab, int*bc);
//void xemkq();
//////================================
/*void textbackground(WORD color) // màu nen
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
 
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;
 
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void textcolor(WORD color) // mau chu
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
 
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;
 
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void gotoXY(int x, int y) // di den toa do x, y
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}*/

// ======TAO MENU======== 

// ====== TAO KHUNG=========
void tao_Khung()
{
	// 20 50 600 400
setbkcolor(0);
cleardevice();
	setfillstyle(1,5);
//	rectangle(20,50,600,400);
	bar(20,40,10,410);
	bar(20,40,610,50);	
	bar(610,50,600,400);	
	bar(600,400,10,410);	
	/*
	for(int i=1;i<=dai;i+=20) // tao hang ngang tren
	{
		outtextxy(a,b,"-");
		a++;
	}
	b=50;
	for(int i=1;i<=rong;i+=10)// tao hang doc ben phai
	{
		outtextxy(a,b,"|");
		
		b++;
	}
	a--;
	for(int i=1;i<=dai;i+=20)// tao hang ngnag duoi
	{
		outtextxy(a,b,"-");
		a--;
	}
	b--;
	for(int i=1;i<=rong;i+=10)
	{
		outtextxy(a,b,"|");
		b--;
	}
*/	
}
// ========== di chuyen 
/// khoi tao con ran
void Khoi_Tao_Con_Ran_Down(int e, int d) // c: td.x || d: td.y || e: td.x0|| f: td.y0
{
	int aa=e;
	int bb=d;
	for(int i=ran-1;i>0;i--)	
	{
		dot[i].x = aa;
		dot[i].y = bb;
		dot[i].y = dot[i-1].y;
		dot[i].x = dot[i-1].x;
		aa+=10;			
		bb+=10;
	}
	dot[0].y+=10;
}
void Khoi_Tao_Con_Ran_Up(int e, int d)
{
	int a = e;
	int b = d;
	for(int i=ran-1;i>0;i--)
	{
		dot[i].x = a;
		dot[i].y = b;
		dot[i].x = dot[i-1].x;
		dot[i].y = dot[i-1].y;
		a+=10;
		b+=10;
	}
	dot[0].y-=10;
}
void Khoi_Tao_Con_Ran_Right(int e, int d)
{
	int a = e;
	int b = d;
	for(int i=ran-1;i>0;i--)
	{
		dot[i].x = a;
		dot[i].y = b;
		dot[i].x = dot[i-1].x;
		dot[i].y = dot[i-1].y;
		a+=10;
		b+=10;
	}
	dot[0].x+=10;
}
void Khoi_Tao_Snake_First(int e , int d ) //  truyen vao 2 tham so la td.x td.y
{
	int aa= e;
	int bb= d;
	for(int i=0;i<ran;i++)
	{
		dot[i].x = aa;
		dot[i].y = bb;
		aa-=10; 
	}
}

bool ktrachambien()
{
	if(dot[0].x == 600  || dot[0].x == 20)	return true;
	if(dot[0].y == 400 || dot[0].y == 50) return true;
	return false;
}
void Khoi_Tao_Con_Ran_Left(int e, int d)
{
	int a = e;
	int b = d;
	for(int i=ran-1;i>0;i--)
	{
		dot[i].x = a;
		dot[i].y = b;
		dot[i].x = dot[i-1].x;
		dot[i].y = dot[i-1].y;
		a+=10;
		b+=10;
	}
	dot[0].x-=10;
}
void ve_ran()
{			//      ran : ooo0
	for(int i=0;i<ran;i++)
	{
		if(i==0)
		{
			setCircle(dot[i].x,dot[i].y,5);
			//////
		}else
		{
			setCircle(dot[i].x,dot[i].y,5);
			
		}
	}
}
void draw_snake(int c, int d)
{
	for(int i=0;i<ran;i++)
	{
		if(i==0)
		{
			circle(dot[i].x,dot[i].y,5);
		}else
		{
			circle(dot[i].x,dot[i].y,5);
		}
	}
}
void xoa_du_lieu_cu() // xoa du lieu cu cua snake di truoc no
{
	for(int i=0;i<ran;i++)
	{
		setcolor(0);
		setfillstyle(1,0);
		circle(dot[i].x,dot[i].y,5);
		floodfill(dot[i].x,dot[i].y,0);
	}
}
/*void score(int *sd)
{
	setcolor(3);
	outtextxy(70,10,"Score
	*/ 

char *chuoii = new char[5];
void loop()
{
	setwindowtitle("Game Snake Playingggg......");
	DNC dnc;
	dnc.diem = 0;
	TOADO hq;
	hq.x = 0;
	hq.y = 0;
	srand((int)time(0));
	bool gameover = false;
	TOADO td;
	td.x=250; //  dat con ran co toa do x =15
	td.y=200; // dat con ran co toa do y =10
	tao_Khung();
	Khoi_Tao_Snake_First(td.x,td.y);
	ve_ran();
	int check = 2;
	int ab,bc;
	int fruit=0;
/*	gotoXY(35,23);
	printf("p: Pause(dung game)");
	gotoXY(70,10);
	printf("Score: %d",dnc.diem);*/
	// check = 0 : up || check =1 : down||   check =2 : right ||  check =3: left|| vi tui da khai bao define
//	ostringstream ostr;
	while(gameover == false)
	{
		if(dot[0].x == ab && dot[0].y == bc)
		{
			PlaySound("D:\\game snake\\eatFood.wav",NULL,SND_ASYNC);
			setcolor(0);
			setfillstyle (SOLID_FILL, 0);
			circle(hq.x,hq.y,5);
			floodfill(hq.x,hq.y,0);
			dnc.diem+=20;
			ran++;
			fruit=0;
			
		}
		settextstyle(10,0,4);
		showText(630,100,"P : Pause Screen(Pause màn hình)");
		showText(630,150,"ESC: Restart Game");
		settextstyle(10,0,4);
		showText(630,50,"Score: ");
	//	moveto(640,50);
//		ostr<<dnc.diem;
		sprintf(chuoii,"%d",dnc.diem);
		showText(750,50,chuoii);
//	showText(640,50,sprintf(sc,"%d",dnc.diem));
		xoa_du_lieu_cu();
		if(fruit == 0)
		{
			hoaqua(hq.x,hq.y,&ab,&bc);
			fruit =1;
		}
			int x = getcolor();
	int c = rand() % 14 + 1;
		setcolor(c);setfillstyle (SOLID_FILL, c);
		circle (ab, bc,5);
		floodfill (ab, bc,getcolor());
	setcolor(x);setfillstyle (1,15);
		if(check == 0) //  di len
		{
			td.y-=10;
			Khoi_Tao_Con_Ran_Up(td.x,td.y);
		}
		if(check == 1) // di xuong
		{
			td.y+=10;
			Khoi_Tao_Con_Ran_Down(td.x,td.y);
		}
		if(check == 2 )// di qua phai
		{
			td.x+=10;
			Khoi_Tao_Con_Ran_Right(td.x,td.y);
		}
		if(check ==3) // di qua trai
		{
			td.x-=10;
			Khoi_Tao_Con_Ran_Left(td.x,td.y);
		}	
				ve_ran();
				if(kbhit())
				{
					
					char c= getch();
					PlaySound("D:\\game snake\\beep.wav",NULL,SND_ASYNC);
					
					if( c == 'w' && check!=1|| c == 72)
					{
					//	PlaySound("D:\\game snake\\beep.wav",NULL,SND_ASYNC);
						check = 0;
					}
					if(c == 's' && check != 0 ||  c == 80)
					{
					//	PlaySound("D:\\game snake\\beep.wav",NULL,SND_ASYNC);
						check =1;
					}
					if(c == 'd' && check !=3 || c == 77)
					{
					//	PlaySound("D:\\game snake\\beep.wav",NULL,SND_ASYNC);
						check = 2;
					}
					if( c== 'a' && check !=2 || c == 75)
					{
					//	PlaySound("D:\\game snake\\beep.wav",NULL,SND_ASYNC);
						check = 3;
					}
					if( c == 112)
					{
						setcolor(4);
						settextstyle(4,0,4);
						outtextxy(630,200,"Stopping....");
						while(1)
						{
							
							if(kbhit())
							{
								char x = getch();
							
							if (x==112) break;
						}
					
					}
					settextstyle(4,0,4);
						outtextxy(630,200,"                     ");
					}
				}
				
				if(ktrachambien()!=ktrachamthan())
				{
					PlaySound("D:\\game snake\\endGame.wav",NULL,SND_ASYNC);
					gameover = true;
				}
	}
	setbkcolor(12);
	cleardevice();
	
//	Nhap_High_Score(dnc.s,dnc.diem);
settextstyle(7,0,5);
	setcolor(0);
	outtextxy(450,300,"YOU LOSE");
	moveto(450,400);
	outtext(chuoii);
//	moveto(25,11);
//	outtext("1. Play Game Again: press 'h' ");
//	moveto(25,12);
//	outtext("2. Press 'ESC' to out ");
	getch();
	closegraph();

}

bool ktrachamthan()
{
	for(int i=1;i<ran;i++)
	{
		if(dot[0].x == dot[i].x && dot[0].y == dot[i].y) return true;
	}
	return false;
}
void hoaqua(int quax, int quay,int *ab, int *bc)
{
	quax= (3+rand()% (59-2))*10;
	quay=(6+ rand() % (39-5))*10;
	*ab=quax;
	*bc=quay;
//	setcolor(9);
//	floodfill(quax,quay,9);
}
// ====== ham main
int main()
{
	initwindow(1200,800);
	setbkcolor(15);
	ShowWindow(GetConsoleWindow(),SW_HIDE);// hide console
	SetConsoleOutputCP(65001);
	PlaySound("D:\\game snake\\ngauhung.wav",NULL,SND_ASYNC);
	SetConsoleTitle("Game Snake"); // tieu de cua game
	loop();
	return 0;
}
