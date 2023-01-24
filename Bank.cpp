#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>

void Atm(void);
void noteDetails(int *);
void noteEntry(int *b[2]);
void newUser(void);
int readData(void);
void displayData(void);
void gotoxy(int,int);
int loginAc(void);
void downData(void);
int res(void);
void primayDispaly(void);
void writeBal(void);
void transferBal(void);
char data[6][25];
long int Id=0,H=0,balId=0;
FILE *fp;
int i=4,Balance=0;
                        //H=2: EOF
int main(void)
{
    int p;
    system("color b8");
    if(i==4)
   {
       system("cls");
       primayDispaly();
   }
    else
        {   system("cls");
    printf("\n\t\t\tYou have Entered Wrong Username or Password");
            Sleep(1000);
            printf("\n\n\t\t\tYou Have %d attempt Left!",i);
            Sleep(1000);

        }
     p=loginAc();
    if(p==1)
        Atm();
    else
        {
         while(i-1)
         {
             i--;
	        main();
         }
        if(i==1)
        printf("\n\t\t\t\tYou have Entered Invilid Username or Password!");
        Sleep(500);
        printf("\n\t\tYour Have Reached to the maximum time limit");
        Sleep(500);
        printf("\n\t\tPlease Reastart the program to Login Your Account.");
        Sleep(500);
        printf("\n\n\t\t\tThanks For using  our service!\n\n");
         getch(); exit(1);

         } return 0;
}


int loginAc(void)
{
    char user[2][20];
    system("cls");
    Sleep(100);
     printf("\n\t\t\t\tACCOUNT LOGIN WINDOW");
     readData();
     Sleep(200);
    printf("\n\n\t\t\t\tEnter Username: ");
    gets(user[0]);
    Sleep(50);
    printf("\n\t\t\t\tEnter Password: ");
    gets(user[1]);
    while(1)
       {    if(strcmp(user[0],data[0])==0||strcmp(user[1],data[1])==0)
            return 1;
        else if(H==2)    return 0;
        else readData();
       }

}


int readData(void)
{
    char ch;
    int a=0,comma=0,A=0;
    fp=fopen("data.txt","r+");
    if(fp==NULL)
       { H=1; newUser();}

   fseek(fp,Id,0);
    while(1)
    {
        ch=getc(fp);
        if(ch==EOF)
        {  H=2; Id=0; data[A-1][a]='\0'; fclose(fp); break; }
        if(ch=='#')
        {
            A++;
            ch='?';
        }
        if(ch==',')
        { data[A-1][a]='\0'; ch='?'; A++; a=0; comma++; }

        if(comma==5)
        { balId=ftell(fp); fscanf(fp,"%d",&Balance); ch='?';}

        if(ch!='?')
        {
            data[A-1][a]=ch;
            a++;
        }

         if(ch=='\n')
       { Id=ftell(fp); data[A-1][a]='\0';  fclose(fp);
         break;  }

    }

}

void newUser(void)
{
    char name[20];
    fp=fopen("data.txt","r+");
     if(fp==NULL)
     {
         fp=fopen("Data.txt","w");
         fclose(fp);
         fp=fopen("data.txt","r+");
     }
fseek(fp,0,2);
if(H=1)
{   system("cls");
    printf("You Have No Any Account, Please Create a New Account Below :");
}
 system("cls"); H=0;
printf("\n\t\t\t\tCREATE NEW ACCOUNT");
printf("\n\t\t\tEnter Username: ");   //For username
gets(name);
fprintf(fp,"#%s",name);
printf("\t\t\tEnter a strong Password: "); //For password
gets(name);
fprintf(fp,",%s",name);
 printf("\t\t\tEnter Account Holder Name: "); //For Name
gets(name);
fprintf(fp,",%s",name);
printf("\t\t\tEnter Fathers name: "); //Fathers name
gets(name);
fprintf(fp,",%s",name);
printf("\t\t\tEnter Date of Birth(DD/MM/YYYY): "); //Age of the person
gets(name);
fprintf(fp,",%s,        \n",name);
fclose(fp);

}


void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void displayData(void)
{
    int x,y,i,j=0;
    system("cls");
      x=50; y=3;
    for(i=1;i<=51;i++)
    {
        j++;
        gotoxy(x,y);
        printf("-");
        x++;
        if(i==50)
        {x=50; y++; y++; i=0; }
        if(j==500)
        break;

    }
     x=50; y=3; j=0;
    for(i=1;i<=20;i++)
    {
        j++;
        gotoxy(x,y);
        printf("|");
        y++;
        if(i==19)
        {x=x+25; y=3; i=0;}
        if(j==57)
        break;
    }

    gotoxy(52,4);
    printf("Name");
    gotoxy(52,6);
    printf("Father's Name");
    gotoxy(52,8);
    printf("User Name");
    gotoxy(52,10);
    printf("Password");
    gotoxy(52,12);
    printf("Date of Birth");
    gotoxy(52,14);
    printf("Balance");
    x=4;
    for(i=0;i<=4;i++)
    {
        gotoxy(77,x);
        x+=2;
        printf("%s",data[i]);
    }
    gotoxy(77,x);
    printf("%d.00",Balance);
    gotoxy(100,21);

}

void downData(void)
{
    char reName[20];
    int x;
    FILE *f;
    printf("Enter File Name: ");
    scanf("%s",reName);
    f=fopen("%s","W");
    fputs("pankaj",f);
    fclose(f);
}


void Atm(void)
{
    int x,n[2],a;
    system("cls");
    while(1)
    {   system("cls");
    printf("\n\n\t\t\t1. Press 1 to Check Balance");
    Sleep(50);
    printf("\n\t\t\t2. Press 2 to Add Balance");
    Sleep(50);
    printf("\n\t\t\t3. Press 3 for Balance withdrawal");
    Sleep(50);
    printf("\n\t\t\t4. Press 4 For Account Management");
    Sleep(50);
    printf("\n\t\t\t5. Press 5 For Balance Transfer");
    Sleep(50);
    printf("\n\t\t\t6. Press 6 to Logout Your Account");
    Sleep(50);
    printf("\n\t\t\t7. Press 7 to Exit\n\t\t");
    x=getch();
    x=x-48;
    switch(x)
    {
      case 1:
          printf("\n\t\tBalance Loading");


          printf("\n\t\t\tYour Account Balance is %d.00",Balance);
          printf("\n\n\t\tPress Any Key to Go to Menu");
          getch();
              break;
      case 2:

          printf("\n\n\t\t\t\tBalance Adding Portal!");
          Sleep(70);
          printf("\n\n\t\t\tEnter Your Balance: ");
              a=res();
              if((Balance+a)>2000000000)
              {
                  Sleep(100);
                  printf("\n\n\t\t\t\tMaximum Limit Exceeds This Amount!");
                  Sleep(50);
                  printf("\n\t\t\t\tKeep Account Balance Under 2000000001");
                  break;

              }
              Balance+=a;
              writeBal();
              Sleep(500);
              printf("\n\n\t\tBalance added sucessfully!");
              Sleep(1000);
            printf("\n\n\t\tPress Any Key to Go to Menu");
            getch();
              break;
      case 3:
                Sleep(500);
              printf("\n\n\t\t\t\tBALANCE WITHDRAWAL PORTAL");
              Sleep(70);
              printf("\n\n\t\t\t\tEnter Balance: ");
              a=res();
              if((Balance-a)<0)
              {
                  printf("\n\n\t\t\t\tInsufficient Balance!");
                  break;
              }
              Balance-=a;
              writeBal();
              noteDetails(&a);
                Sleep(50);
              printf("\n\n\t\t\tNow Your Balance is %d.00",Balance);
                Sleep(2000);
           printf("\n\n\t\tPress Any Key to Go To Menu");
            getch();
              break;
      case 4:
            Sleep(100);
            printf("\n\t\t\t\tAccount Management");
            Sleep(100);
            printf("\n\n\t\t\t1. Press 1 to Rasister a new Account.");
            Sleep(50);
            printf("\n\t\t\t2. Press 2 to view your Account Profile.");
            Sleep(50);
            printf("\n\t\t\t3. press 3 to go back.");
            x=getch();
            Sleep(200);
            x=x-48;
            if(x==1)
                newUser();
            else if(x==2)
                {   readData();
                    displayData();  }
            else if(x==3)
                break;
            else printf("Invilid Key");
            Sleep(1500);
             printf("\n\n\t\tPress Any Key to Go To Menu");
            getch();
            break;

      case 5:
            transferBal(); break;
      case 6:
            i=4; main(); break;
      case 7:
            Sleep(50);
          printf("\n\t\t\t\tThanks for using our service!");
          Sleep(500);
          printf("\n\n\t\t\tPress Any key to Continue");
          getch();
          exit(1);

      default :
          Sleep(200);
          printf("\n\tInvilid Key!");
          Sleep(500);
          break;
            }

    }


}

void noteDetails(int *X)
{
    int x,a,b,c;
        x=*X;
        Sleep(100);
        a=(x/2000);
        if(a==0) {}
        else printf("\n\t\t\tNote of 2000 = %d",a);

        x=x-(a*2000);

        b=x/500;
        Sleep(50);
        if(b==0) {}
            else printf("\n\t\t\tNote of 500 = %d",b);

        x=x-(b*500);

         c=x/100;
         Sleep(50);
         if(c==0) {}
            else printf("\n\t\t\tNote of 100 = %d",c);

}

void noteEntry(int *b[2])
{
    printf("\t\t\tWelcome to Note Entry ATM Portal\n");
    printf("\n\tEnter Number of 100 notes: ");
    *b[0]=res();
    printf("\n\tEnter Number of 500 Notes: ");
    *b[1]=res();
    printf("\n\tEnter Number of 2000 Notes: ");
    *b[2]=res();
}

int res(void)
{int x,y=0,b[15],i=0,X,Y;
while(1)
   { x=getch();
    if(x>=48&&x<=57)
        {x=(x-48);
        y=(y*10)+x;
        i++;  b[0]=0;
        b[i]=y;
        printf("%d",x);}
        else if(x==13&&i!=0)
            break;

    }
    return(y);
}

void primayDispaly(void)
{
    int x=0,y=0;
    Sleep(100);
    printf("\n\t\t\t\tYour Most Welcome to Our Banking Service!");
    Sleep(1000);
    printf("\n\n\t\t\t1. Press 1 to Sign in your Account");
    Sleep(50);
    printf("\n\t\t\t2. Press 2 to Rasister a New Account");
    Sleep(50);
    printf("\n\t\t\t3. Press 3 to Exit");

    x=getch();
    x=x-48;
    switch(x)
    {
        case 1: break;
        case 2: newUser(); break;
        case 3: Sleep(50); printf("\n\n\t\t\t\tThanks For Visiting!"); Sleep(500); printf("\n\t\t\t\tPress any key to Exit"); getch(); exit(1);
        default: Sleep(50); printf("\n\n\t\t\t\tInvilid Key Pressed!"); Sleep(1000); system("cls"); primayDispaly();
    }


}

void writeBal()
{
    fp=fopen("data.txt","r+");
    fseek(fp,balId,0);
    fprintf(fp,"%d",Balance);
    fclose(fp);
}

void transferBal(void)
{
    char acNo[10],Data[8][25];
    int x,recoverBal=Balance;
    Data[8][25]=data[8][25];
    printf("\n\t\t\tEnter Account Number: ");
    gets(acNo);
    printf("\n\t\t\tEnter Balance: ");
    x=res();
    Balance-=x;
    writeBal();
    Id=0;
    readData();
     while(1)
       {    if(strcmp(acNo,data[5])==0)
            { Balance+=x; writeBal(); break;}
        else if(H==2)  { Id=0; H=0; printf("\n\n\t\t\t\tYou Have Entered Wrong Account Number!"); data[8][25]=Data[8][25]; writeBal(); break;   }
        else readData();
       }
}

