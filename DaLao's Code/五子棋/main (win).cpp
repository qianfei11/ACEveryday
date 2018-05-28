///    Edition 0.8            Copyright 2017 Zhaoyu Isaac Deng , All Right Reserved
/// Update Dairy: #0.2 General  #0.3 POS display|core optimize  #0.4 arrow keys|welcome display
/// #0.5 Regret  #0.6 board move loop  #0.7 icon refresh  #0.8 partly refresh

#include<conio.h>
#include<windows.h>
#include<dos.h>
#define CLRSCR system("cls");
#define OUTTYPE "%2s"
#define GOTOINF gotoxy(1,BOARD);
#define PERIOD 70

#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>                       /// UPDATE: | AI |
                                        /// option menu
                                        /// optimize check Algorithm
#define CHESS 5
#define SLEN 10
#define BOARD (SLEN*2+1)
#define FLASH 0.001

void welcome(void);
void envir(void);
void print(void);
int Icon(void);
int checkchess(void);
void regret(void);
void gameover(int);
void delay(double);
void delay(unsigned int);
void gotoxy(unsigned,unsigned);

const char* board[BOARD][BOARD]={0};
int check[SLEN][SLEN]={0};
int reg[SLEN*SLEN][3]={0};
int turn=-1;                    /// -1==white  1==black
int row=0, col=0;
char  con;              /// Windows char
int count=0, undo=0;

const char * BLACK="X",  * WHITE ="O",   * POS  ="*";
const char * LT   =".",  * TOP   =".",   * RT   =".";
const char * LEFT =".",  * CENTER=".",   * RIGHT=".";
const char * LF   =".",  * FOOT  =".",   * RF   =".";
const char * SPACE=" ";

int main(void)
 {
    int s;
    welcome();
    envir();
    s=Icon();
    gameover(s);
    return 0;
 }

 void welcome(void)
 {
    printf("|     Welcome To Play       |\n");
    printf("|     %d In Line Game        |\n",CHESS);
    printf("|      Board: %2d X %2d       |\n",SLEN,SLEN);
    printf("|                           |\n");
    printf("|        Copyright:         |\n");
    printf("|    Zhaoyu Isaac Deng      |\n");
    //printf("\033[?25l");
    getch();
    CLRSCR;
 }

void envir(void)
{
    for(int j=0;j<BOARD;j++)
        for(int k=0;k<BOARD;k++)
            board[j][k]=SPACE;

    board[0][0]=LT;
    board[0][BOARD-1]=RT;
    board[BOARD-1][0]=LF;
    board[BOARD-1][BOARD-1]=RF;

    for(int i=2;i<BOARD-2;i+=2){
        board[0][i]=TOP;
        board[BOARD-1][i]=FOOT;
        board[i][0]=LEFT;
        board[i][BOARD-1]=RIGHT;
    }
    for(int j=2;j<BOARD-2;j+=2)
        for(int k=2;k<BOARD-2;k+=2){
            board[j][k]=CENTER;
        }
}

void print(void)
{
    CLRSCR;                         ///clear screen
    for(int j=0;j<BOARD;j++){               /// columns
        for(int k=0;k<BOARD;k++)            /// rows
        {
            if((j-1)%2==0 && (k-1)%2==0){
                int sam=check[(j-1)/2][(k-1)/2];      /// sample
                if(sam==0) printf("  ");
                else if(sam==-1) printf(OUTTYPE,WHITE);
                else if(sam==1) printf(OUTTYPE,BLACK);
                else if( sam==3 || sam==-2 || sam==2 ) printf(OUTTYPE,POS);
            }
            else printf(OUTTYPE,board[j][k]);
        }
        putchar('\n');
    }
    if(turn==1) printf("  %s  Black turn",BLACK);
    else     printf("  %s  White turn",WHITE);
    printf("    POS(%2d,%2d)  undo: %d\n",row+1,col+1,undo);
}

#define LOCATE  check[row][col]
#define NOTCHESS  LOCATE==0
#define ISWHITE  LOCATE==-1
#define ISBLACK  LOCATE==1
#define GOTOCURR gotoxy(2*(1+2*col),1+2*row);
#define printSPACE { GOTOCURR printf(OUTTYPE,SPACE); }
#define printPOS { GOTOCURR printf(OUTTYPE,POS); }
#define printWHITE { GOTOCURR printf(OUTTYPE,WHITE); }
#define printBLACK { GOTOCURR printf(OUTTYPE,BLACK); }
#define INFORM { GOTOINF; if(turn>0) printf("  %s  Black turn",BLACK); else printf("  %s  White turn",WHITE); printf("    POS(%2d,%2d)  undo: %d\n",row+1,col+1,undo); }
#define MOVE  {if(NOTCHESS) LOCATE=3;else if(ISWHITE) LOCATE=-2;else if(ISBLACK) LOCATE=2;INFORM}
#define RESTORE  {if(LOCATE==3) {LOCATE=0; printSPACE} else if(LOCATE==-2) {LOCATE=-1; printWHITE} else if(LOCATE==2) {LOCATE=1;printBLACK} }
#define PUTDOWN {if(turn==-1) { printWHITE LOCATE=turn; } else if(turn==1) { printBLACK LOCATE=turn; } }
#define MEMORY {reg[count][0]=turn; reg[count][1]=row; reg[count][2]=col;}
#define PLACE {PUTDOWN; MEMORY; turn=-turn; count++; INFORM; }

int Icon(void)
{
    unsigned int s=0;
    LOCATE=3;
    print();
    //system("stty -echo");
    while(1)
    {
        //gotoxy(0,BOARD+2);
        if(kbhit()) {
            //system("clear");
            //gotoxy(0,BOARD+2);
            while((con=getch())!='`')
            {
                //gotoxy(2+2*(1+2*col),2+2*row);        /// Linux ??
                //printf("  ");
                if(con==-32)  con=getch();
                if(con=='w'||con=='s'||con=='a'||con=='d'||con==' '||
                    /*con==65||con==66||con==67||con==68||con=='/'||*/con=='r'){
                    if(con!=' ' && con!='/') RESTORE;
                    switch(con){                                    /// edge situation
                    case 'w': if(row>0)      row--; else row=SLEN-1;MOVE; printPOS break;
                    case 's': if(row<SLEN-1) row++; else row=0;     MOVE; printPOS break;
                    case 'a': if(col>0)      col--; else col=SLEN-1;MOVE; printPOS break;
                    case 'd': if(col<SLEN-1) col++; else col=0;     MOVE; printPOS break;
                    case 72 : if(row>0)      row--; else row=SLEN-1;MOVE; printPOS break;
                    case 80 : if(row<SLEN-1) row++; else row=0;     MOVE; printPOS break;
                    case 75 : if(col>0)      col--; else col=SLEN-1;MOVE; printPOS break;
                    case 77 : if(col<SLEN-1) col++; else col=0;     MOVE; printPOS break;
                    case ' ': if(LOCATE==3)         PLACE; break;
                    case '/': if(LOCATE==3)         PLACE; break;
                    case 'r': if(count>=0)   regret(); break;
                    default : break;
                    }
                }
                //print();
                if(count==SLEN*SLEN) return 0;
                if(checkchess()) return 1;
                break;
            }
            if(con=='`') return 2;
        }
        else {
            if(s%PERIOD==0){                // FLASH*500
                GOTOCURR
                if(LOCATE==-1)      { LOCATE=-2; printf(OUTTYPE,POS); }
                else if(LOCATE==-2) { LOCATE=-1; printf(OUTTYPE,WHITE); }
                else if(LOCATE== 1) { LOCATE= 2; printf(OUTTYPE,POS); }
                else if(LOCATE== 2) { LOCATE= 1; printf(OUTTYPE,BLACK); }
                //print();
            }
            s++;
            delay(FLASH);
        }
    }

}

int checkchess(void)
{
    bool judge;
    int  pres;
    for(int j=0;j<SLEN;j++)        /// check rows || columns
        for(int k=0;k<SLEN;k++)
            if(check[j][k]!=0){
                pres=check[j][k];
                judge=true;
                if(j<=SLEN-CHESS && k<=SLEN-CHESS){             /// should contain '='
                    for(int l=1;l<CHESS;l++)
                        if(check[j+l][k+l]!=pres) judge=false;          ///oblique right
                    if(judge==true) return 1;
                }
                judge=true;
                if(j<=SLEN-CHESS && k>=CHESS-1){
                    for(int l=1;l<CHESS;l++)
                        if(check[j+l][k-l]!=pres) judge=false;          ///oblique left
                    if(judge==true) return 1;
                }
                judge=true;
                if(k<=SLEN-CHESS){
                    for(int l=1;l<CHESS;l++)
                        if(check[j][k+l]!=pres) judge=false;            ///horizontal
                    if(judge==true) return 1;
                }
                judge=true;
                if(j<=SLEN-CHESS){
                    for(int l=1;l<CHESS;l++)
                        if(check[j+l][k]!=pres) judge=false;            ///vertical
                    if(judge==true) return 1;
                }
            }
    return 0;
}

void gameover(int s)
{
    gotoxy(1,BOARD+1);
    if(s){
        if(s==2) printf("\tForce exit\n");
        else if(turn==1) printf("\t-----%s White Won-----\n",WHITE);
        else        printf("\t-----%s Black Won-----\n",BLACK);
    }
    else printf("\t-----Tied-----\n");
    //system("stty echo");
    //printf("\033[?25h");
}

void delay(double z)
{
    double start=(double)clock()/CLOCKS_PER_SEC;            /// bug faster
    while(((double)clock()/CLOCKS_PER_SEC)-start<z);
}

void regret(void)
{
    if(count) {
        count--; turn=-turn; undo++;
        row=reg[count][1];
        col=reg[count][2];
        for(int j=0;j<3;j++)
            reg[count][j]=0;
    }
    INFORM;
    printPOS;
    LOCATE=3;
}

void gotoxy(unsigned x,unsigned y)
{
    COORD pos;
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
