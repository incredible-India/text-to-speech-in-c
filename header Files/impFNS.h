

//function declaration
void gotoxy(int,int);
void setcolor(int);
//global variable we will use it for the loop and all...
int i,j;

//for changing the co-ordinate of console window
void gotoxy(int a, int b)
{

    COORD x;
    x.X=a;
    x.Y=b;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),x);

}
//color of text
void setcolor(int ForgC) //for changing the forGround color
{
     WORD wColor;


     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;


     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {

          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
//Exit function ...
void ExitFn()
{
    extern int i;
    char *ch = (char *) malloc(6*sizeof(char));

    ch = "exit()";

    system("cls");

    gotoxy(40,12);
    for(i=0;i< strlen(ch);i++)
    {

        print("%c",ch[i]);
        sleep(100);

    }
    free(ch);
    gotoxy(40,14);
    setcolor(1);
    printf("Thanks For Visiting Us");
    sleep(100);
    exit(0);



}
