
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include<stdio.h>

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

