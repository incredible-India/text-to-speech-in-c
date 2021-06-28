

//function declaration
void gotoxy(int,int);
void setcolor(int);
void intro(void);
void BasicInstructions(void);
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

        printf("%c",ch[i]);
        Sleep(100);

    }

    fflush(stdin);
    gotoxy(40,14);
    setcolor(1);
    printf("Thanks For Visiting Us");
    Sleep(10);
     //  free(ch);
    exit(0);



}

void intro()
{

      extern int i,j;
      char userChoice ;
        char *_ch = "printf(\"Welcome to Text To Voice App\")\n >>> \t Welcome to Text To Voice App";
        SetConsoleTitle("Text To Voice");
      system("cls");
      gotoxy(40,12);
      setcolor(3);

     /*  for(i=0;i< strlen(_ch);i++)
    {

        printf("%c",_ch[i]);
        Sleep(100);

   } */
 system("cls");

 gotoxy(10,2);

 setcolor(4);



 printf("%s",__DATE__);

  gotoxy(10,4);

 setcolor(6);

 printf(" 1 : Get Start");

  gotoxy(10,6);

 setcolor(2);

 printf(" 2 : date Today");

 gotoxy(10,8);

 setcolor(3);

 printf(" 3 : Help And instructions");

  gotoxy(10,10);

 setcolor(4);

 printf(" 4 : Exit");

   gotoxy(10,12);

 setcolor(6);

 printf(">>> \t");





  for(;;)
  {


        userChoice = getch();

      switch(userChoice)
      {

      case '1':
        break;
      case '2':
        break;
      case '3':
        BasicInstructions();
      case '4':
        ExitFn();
        break;
      default :
        printf("\a");
        j++;
        if(j == 3)
        {
            ExitFn();

        }
        continue ;
      }

  }




}


void BasicInstructions()
{

    char ch;
    system("cls");

    FILE *read__Data = fopen("./Instruction/ins.txt","r");

    if(read__Data == NULL)
    {


    gotoxy(40,12);

        printf("Something Went Wrong ErrorId : 404");

         gotoxy(40,14);

          printf("press Any key to exit");

         getch();

         exit(0);
    }


    gotoxy(10,3);
    setcolor(7);
    printf("Instructions\n");
    printf("\n");

    ch = fgetc(read__Data);

    while(ch != EOF)
    {
        printf("%c",ch);
        Sleep(2);

          ch = fgetc(read__Data);

    fflush(stdin);


    }

    fclose(read__Data);



    printf("\npress Any key to exit\n");

         getch();

        ExitFn();



}
