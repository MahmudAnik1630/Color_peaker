#include"graphics.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include "inputbox.h"
#include "cc.h"
#include <cstdlib>
using namespace std;

struct UserInfo {
    char username[50];
    char password[50];
    int highScore;
};

void saveUserInfo(const UserInfo& user) {
    ofstream file("userinfo.dat", ios::binary);
    file.write(reinterpret_cast<const char*>(&user), sizeof(UserInfo));
    file.close();
}

UserInfo loadUserInfo() {
    UserInfo user;
    ifstream file("userinfo.dat", ios::binary);
    if (file.is_open()) {
        file.read(reinterpret_cast<char*>(&user), sizeof(UserInfo));
        file.close();
    } else {

        strcpy(user.username, "Guest");
        strcpy(user.password, "");
        user.highScore = 0;
    }
    return user;
}
void drawUserInfo(const UserInfo& user, int point) {
    setcolor(15);
    settextstyle(3, HORIZ_DIR, 3);
    char info[100];
    sprintf(info, "Username: %s", user.username);
    outtextxy(680, 30, info);

    sprintf(info, "High Score: %d", user.highScore);
    outtextxy(680, 260, info);
}


void HighInfo(const UserInfo& user, int point) {
    setcolor(15);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
    char info[100];


     ifstream file("userinfo.dat", ios::binary);
    if (file.is_open()) {
        UserInfo user;
        file.read(reinterpret_cast<char*>(&user), sizeof(UserInfo));

    outtextxy(100,30,"High Score Player:");
    sprintf( info,"%s", user.username);
    outtextxy(200, 100, info);


    sprintf(info, "High Score: %d", user.highScore);
    outtextxy(200, 260, info);
     file.close();
}
}
void getUsername(UserInfo& user) {
    char buffer[50];
    inputbox(buffer, 50, "Enter your Username:");
    strcpy(user.username, buffer);
}
//**********************************************************Check Luck***************************************

void shuffle(int arr[], int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

//****************************************************************//
void display(int *x1,int *x2 , int *x3, int *x4 ,int *y1,int *y2 , int *y3, int *y4, int values[],int numValues,char* cye,char* cb , char *cbl,char *cre)
{
readimagefile("bg.jpg",0,0,850,500);
    int i;
for( i=0;i<6;i++)
{

    srand(time(NULL));
shuffle(values, numValues);

*x1= values[0];
*x2= values[1];
*x3= values[2];
*x4= values[3];
printf("%d \n",values[0]);

if(i!=5)
{

outtextxy(330, 450, "Shuffling");
}
else
{

    outtextxy(330, 450, "Shuffling Done");
    delay(1000);
   // cleardevice();
    outtextxy(330, 400, "Pick The color");
}

int color[7]={YELLOW ,BLACK ,BLUE ,  RED};
int xa[7]={*x1  , *x2 , *x3 ,  *x4};

for(int i=0;i<=3;i++)
{


    setcolor(WHITE);
            circle(xa[i], *y1, 50);
			setfillstyle(SOLID_FILL,color[i]);
			floodfill(xa[i],*y1,WHITE);

}

delay(500);

}

outtextxy(280, 450, "Find hidden treasures ");

}
//*********************************************************//
//***************************************************************//
void again_display(int *x1,int *x2 , int *x3, int *x4 ,int *y1,int *y2 , int *y3, int *y4, int values[],int numValues,char* cye,char* cb , char *cbl,char *cre)
{
    char color= WHITE;
    cleardevice();
readimagefile("bg.jpg",0,0,850,500);

    setcolor(color);
            circle(*x1, *y1, 50);
			setfillstyle(SOLID_FILL,*cye);
			floodfill(*x1,*y1,color);

			setcolor(color);
            circle(*x2, *y2, 50);
			setfillstyle(SOLID_FILL,*cb);
			floodfill(*x2,*y2,color);


			setcolor(color);
            circle(*x3, *y3, 50);
			setfillstyle(SOLID_FILL,*cbl);
			floodfill(*x3,*y3,color);


			setcolor(color);
            circle(*x4, *y4, 50);
			setfillstyle(SOLID_FILL,*cre);
			floodfill(*x4,*y4,color);
			delay(100);

}

void where_is_trasure(int *x , int *y,int x1,int x2 , int x3, int x4 ,int y1,int y2 , int y3, int y4,int*z1,int*z2,int*z3,int*z4,char *color,char cye,char cb , char cbl,char cre)
{
    srand(time(NULL));


    int randomValue = (rand() % 4)+1;


    switch (randomValue) {
        case 1:
           // printf(" 1 found.\n");
            *x=x1;
            *y=y1;
            *z1=80;
            *z2= y3 ;
            *z3= y4 ;
            *z4=y4;
            strcpy(color, "yellow" );

            break;
        case 2:
            printf("2 found\n");
            *x=x2;
            *y=y2;
            *z2=80;
            *z1=y1;
            *z3= y3 ;
            *z4=y4;

            strcpy(color, "black" );
            break;
        case 3:
           printf("3 found\n");
        *x=x3;
           *y=y3;
            *z3=80;
            *z2=y2;
            *z1=y1;
            *z4=y4;
            strcpy(color, "blue" );
            break;
        case 4:
         //   printf("4 found\n");
            *x=x4;
            *y=y4;
            *z1=y1;
            *z2=y2;
            *z3= y3 ;
            *z4=80;
          strcpy(color, "red" );
            break;

    }


}



//*************************Main**************************************//

int colorpicker() {
     initwindow(850,500,"Color Picker");
readimagefile("bg.jpg",0,0,850,500);
     settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
     char text[20];
char color[10];
int values[] = {100, 300, 500,700};
int numValues = sizeof(values) / sizeof(values[0]);

int x1,x2,x3,x4;
int y1,y2,y3,y4;
y1=y2=y3=y4=200;
char cye=YELLOW , cb=BLACK , cbl=BLUE,cre=RED;
display(&x1,&x2,&x3,&x4,&y1,&y2,&y3,&y4,values,numValues,&cye,&cb,&cbl,&cre);

int limit=1;
while(1)
{

    if(ismouseclick(WM_LBUTTONDOWN))
    {
        int mx, my,x,y,z1,z2,z3,z4;
            getmouseclick(WM_LBUTTONDOWN, mx, my);
            if(limit==1)
            {


            where_is_trasure(&x,&y,x1,x2,x3,x4,y1,y2,y3,y4,&z1,&z2,&z3,&z4, color,cye,cb,cbl,cre);

            limit=0;
            }


 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
 //sprintf(text, " Cheat: Treasure is: %s .\n ", color); // Cheat Function

         //  outtextxy(50, 300, text);

            if ((mx - x) * (mx - x) + (my - y) * (my - y) <= 2500)
                {



               again_display(&x1,&x2,&x3,&x4,&z1,&z2,&z3,&z4,values,numValues,&cye,&cb,&cbl,&cre); // Carrect function

readimagefile("t1.jpg",x-50,150,x+50,250);
settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
                sprintf(text, "YOU WIN", color);
                outtextxy(330, 400, text);
               break;


            }
            else if((mx - x1) * (mx - x1) + (my - y1) * (my - y1) <= 2500 || (mx - x2) * (mx - x2) + (my - y2) * (my - y2) <= 2500 || (mx - x3) * (mx - x3) + (my - y3) * (my - y3) <= 2500  || (mx - x4) * (mx - x4) + (my - y4) * (my - y4) <= 2500 )
                {


                    again_display(&x1,&x2,&x3,&x4,&z1,&z2,&z3,&z4,values,numValues,&cye,&cb,&cbl,&cre); // Carrect function
                    readimagefile("t1.jpg",x-50,150,x+50,250);


settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
                sprintf(text, "Treasure is: %s .\n you loose", color);

           outtextxy(50, 400, text);

    delay(5000);
                break;
            }


    }
    delay(40);
}



    delay(50000);
    closegraph();
    return 0;
}








//**********************************************************Check Luck ended code***************************************

int main()
{
	initwindow(1024,600,"Color Picker");

	char a[100];
	char b[100];
	int yaxis= 0;
	int xaxis= 50;
	int yaxis1=50;
	int xaxis1=0;
	int i,c;
	int color1=15;
	int color2=14;
	int color3=13;
	int color4=12;
	int color5=11;
	int color6=10;
	int color7=9;
	int color8=8;
	int colordest= 8;
    int ppoint=1;
UserInfo user = loadUserInfo();
getUsername(user);
start:

	while(1)
	{

		int point=0;
		int life=5;
        int mouseX = mousex();
        int mouseY = mousey();
		readimagefile("menu.jpg",0,0,1024,700);
		settextstyle(1,HORIZ_DIR,4);


//*************************EXIT*************************************************8
		int left = 117, top = 438, right = 318, bottom = 492;
		  setcolor(COLOR(98, 45,14));
          rectangle(left, top, right, bottom);
        int width = right - left;
        int height = bottom - top;
        int area = width * height;
		if(ismouseclick(WM_LBUTTONDOWN))
		{


		if (mouseX >= left && mouseX <= right && mouseY >= top && mouseY <= bottom)
		{

			readimagefile("bg.jpg",0,0,1024,700); // exit
		    delay(1000);
			return 0;
		}
		}
//***************************************************************************

//*******************************Luck*********************************************8


          left = 117, top = 203, right = 318, bottom = 254;
		  setcolor(COLOR(98, 45,14));
          rectangle(left, top, right, bottom);
		  width = right - left;
          height = bottom - top;
          area = width * height;


		if(ismouseclick(WM_LBUTTONDOWN))
		{


		if (mouseX >= left && mouseX <= right && mouseY >= top && mouseY <= bottom)
		{


colorpicker() ;

		}

		}

//******************************High Score*********************************************
		  left = 117, top = 282, right = 318, bottom = 333;
		  setcolor(COLOR(98, 45,14));
          rectangle(left, top, right, bottom);
		  width = right - left;
          height = bottom - top;
          area = width * height;


		if(ismouseclick(WM_LBUTTONDOWN))
		{


		if (mouseX >= left && mouseX <= right && mouseY >= top && mouseY <= bottom)
		{

			 readimagefile("bg.jpg",0,0,1024,700);
			 HighInfo(user, point);
		     delay(4000);


		}

		}

//****************************Credit************************************

	      left = 117, top = 360, right = 318, bottom = 410;
		  setcolor(COLOR(98, 45,14));
          rectangle(left, top, right, bottom);
		  width = right - left;
          height = bottom - top;
          area = width * height;


		if(ismouseclick(WM_LBUTTONDOWN))
		{


		if (mouseX >= left && mouseX <= right && mouseY >= top && mouseY <= bottom)
		{

			readimagefile("credit.jpg",0,0,1024,700); // exit
		    delay(4000);


		}

		}



//*********************************Play*******************************************
		  left = 110, top = 116.5, right = 326, bottom = 180;
		  setcolor(COLOR(255, 66,81));
          rectangle(left, top, right, bottom);
		  width = right - left;
          height = bottom - top;
          area = width * height;
		if(ismouseclick(WM_LBUTTONDOWN))
		{
clearmouseclick(WM_LBUTTONDOWN);



		if (mouseX >= left && mouseX <= right && mouseY >= top && mouseY <= bottom)
		{
		    drawUserInfo(user, point);
		    readimagefile("background1.jpg",0,0,1024,700);
delay(500);

			while(1)
			{
			    int n=0;//while loop controller;
            readimagefile("bg.jpg",0,0,1024,700);


			setcolor(color1);
			setfillstyle(SOLID_FILL,color1);
			fillellipse(xaxis,yaxis,50,50);

			setcolor(color2);
			setfillstyle(SOLID_FILL,color2);
			fillellipse(xaxis+190,yaxis,50,50);

			setcolor(color3);
			setfillstyle(SOLID_FILL,color3);
			fillellipse(xaxis+390,yaxis,50,50);

			setcolor(color4);
			setfillstyle(SOLID_FILL,color4);
			fillellipse(xaxis+560,yaxis,50,50);



			setcolor(colordest);
			setfillstyle(SOLID_FILL,colordest);
			fillellipse(865,480,50,50);

			setcolor(2);
			rectangle(700,400,1024,700);

			setcolor(15);
			settextstyle(3,HORIZ_DIR,1);
			outtextxy(755,559,"follow the color and clash the bubble");


			yaxis+=50;

			if (yaxis >= 650)
			{
				yaxis=0;
				color1 = rand()%15;
				color2 =color1+1;
				color3 = color2+1;
				color4 = color3+1;
				c = rand()%4;
				if (c==0)
					colordest = color1;
				else if (c==1)
					colordest = color2;
				else if (c==2)
					colordest = color3;
				else colordest = color4;


			}
			drawUserInfo(user, point);
			setcolor(WHITE);
			settextstyle(4,HORIZ_DIR,3);
			sprintf(a,"you gain %d Point",point);
			outtextxy(680,150,a);

			setcolor(WHITE);
			settextstyle(4,HORIZ_DIR,3);
			sprintf(b,"you have %d more life",life);
			outtextxy(680,200,b);

			if (ismouseclick(WM_LBUTTONDOWN))

			{

				clearmouseclick(WM_LBUTTONDOWN);
				int x = getpixel(mousex(),mousey());
				if (x<= colordest)
				{
					point++;
					yaxis=0;
					color1 = rand()%12;
					color2 =color1+1;
					color3 = color2+1;
					color4 = color3+1;
					c = rand()%4;
					if (c==0)
						colordest = color1;
					else if (c==1)
						colordest = color2;
					else if (c==2)
						colordest = color3;
					else
						colordest = color4;
				}
				else
					life--;
				if(life==0)
				{
				     if (point > user.highScore) {
                                user.highScore = point;
                                saveUserInfo(user);

				    }
					readimagefile("lost.jpg",0,0,1024,700);
					delay(5000);



					readimagefile("Menu.jpg",0,0,1024,700);
point=0;
					break;
				}

				if(point==(ppoint*10))
				{
				    ppoint++;
				    if(2==ppoint)
                    {


					readimagefile("win.gif",0,0,1024,700);
					delay(5000);

					readimagefile("congo.jpg",0,0,1024,700);
					delay(5000);
					life=5;
					//int point=0;
		            int life=5;
		            readimagefile("background2.jpg",0,0,1024,700);
		delay(4000);
		}
		n++;
					while(n)
	    {




		readimagefile("bg.jpg",0,0,1024,700);

		setcolor(color1);
		setfillstyle(SOLID_FILL,color1);
		fillellipse(xaxis,yaxis,50,50);

		setcolor(color2);
		setfillstyle(SOLID_FILL,color2);
		fillellipse(xaxis+190,yaxis,50,50);

		setcolor(color3);
		setfillstyle(SOLID_FILL,color3);
		fillellipse(xaxis+390,yaxis,50,50);

		setcolor(color4);
		setfillstyle(SOLID_FILL,color4);
		fillellipse(xaxis+560,yaxis,50,50);

        setcolor(color5);
		setfillstyle(SOLID_FILL,color5);
		fillellipse(xaxis1,yaxis1,50,50);

		setcolor(color6);
		setfillstyle(SOLID_FILL,color6);
		fillellipse(xaxis1,yaxis1+150,50,50);

        setcolor(color7);
		setfillstyle(SOLID_FILL,color7);
		fillellipse(xaxis1,yaxis1+300,50,50);

        setcolor(color8);
		setfillstyle(SOLID_FILL,color8);
		fillellipse(xaxis1,yaxis1+450,50,50);


            setcolor(colordest);
			setfillstyle(SOLID_FILL,colordest);
			fillellipse(865,480,50,50);

		setcolor(2);
			rectangle(700,400,1024,700);

			setcolor(15);
			settextstyle(3,HORIZ_DIR,1);
			outtextxy(755,559,"follow the color and clash the bubble");

		yaxis+=50;
        xaxis1+=50;

		if (yaxis >= 650|| xaxis1>=1024)
		{

			xaxis1=0;
			yaxis=0;
			color1 = rand()%15;
			color2 =color1+1;
	     color3 = color2+1;
	     color4 = color3+1;
	     color5 = color4+1;
            color6 = color5+1;
            color7 = color6+1;
            color8 = color7+1;
            c = rand()%8;
			if (c==0)
				colordest = color1;
			else if (c==1)
				colordest = color2;
			else if (c==2)
				colordest = color3;
			else if (c==3)
                colordest = color4;
            else if (c==4)
				colordest = color5;
            else if (c==5)
				colordest = color6;
            else if (c==6)
				colordest = color7;
            else if (c==7)
				colordest = color8;
		}
		drawUserInfo(user, point);
		setcolor(RED);
			settextstyle(4,HORIZ_DIR,3);
			sprintf(a,"you gain %d Point:",point);
			outtextxy(660,150,a);

			setcolor(RED);
			settextstyle(4,HORIZ_DIR,3);
			sprintf(b,"you have %d more life:",life);
			outtextxy(650,200,b);

		if (ismouseclick(WM_LBUTTONDOWN))

		{

				clearmouseclick(WM_LBUTTONDOWN);
				int x = getpixel(mousex(),mousey());
				if (x<= colordest)/////latest change;
				{
					point++;
					yaxis=0;
					xaxis1=0;
					color1 = rand()%15;
					color2 =color1+1;
					color3 = color2+1;
					color4 = color3+1;
                    color5 = color4+1;
                    color6 = color5+1;
                    color7 = color6+1;
                    color8 = color7+1;

					c = rand()%8;
					if (c==0)
						colordest = color1;
					else if (c==1)
						colordest = color2;
					else if (c==2)
						colordest = color3;

					else if (c==3)
						colordest = color4;
					else if (c==4)
						colordest = color5;
                    else if (c==5)
						colordest = color6;
					else if (c==6)
						colordest = color7;
                    else if (c==7)
						colordest = color8;
				}
				else
					life--;
				if(life==0)
				{
				     if (point > user.highScore) {
                                user.highScore = point;
                                saveUserInfo(user);
				    }
				    point=0;
					readimagefile("lost.jpg",0,0,1024,700);
					delay(5000);
					goto start;
					return 0;
				}
				if(point==(ppoint*10))
				{
				    n--;
ppoint++;
if(3==ppoint)
{


					readimagefile("win.gif",0,0,1024,700);
					delay(5000);
					}

				}
				printf("%d %d\n",point,life);

        }
		delay (50);

		//while cancel;
	}


				}
				printf("%d %d\n",point,life);

			}
			delay (200);
		}
	}
	}
	}

	return 0;
}



