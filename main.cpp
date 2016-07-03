#include<dos.h>
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


int pscore,cscore;                   //global variables


//*********************PROTOTYPES*************************************************
void toss();
void playerturn();
void computerturn();
void chkwinner();
int randgen();
//***************************************************************************

//**************************RANDOM GENERATOR*******************************
int randgen()
{
 int randn;
 randn=random(6)+1;               // RANDOM number GENERATOR  function
 return randn;
}

//***************************TOSS()***********************************************
void toss()
{
 clrscr();
 int innum,tossvar,choice,tchoice,tflag,pflag,flag=1;
 while(flag==1)
 {
  printf("\nSELECT ODD OR EVEN\n1.Odd\n2.Even\nEnter Your Choice: ");
  scanf("%d",&choice);
  if(!(choice==1||choice==2))
  {
   printf("wrong choice");
   flag=1;
  }
  else flag=0;
 }
 if(choice==2)
  {
  printf("\nYou opted even\n");         //FOR EASE IN CHECKING ODD EVEN later
  choice=0;
  }
 if( choice==1)
 printf("\nYou opted odd\n");

 pflag=1;
 while(pflag==1)
 {
  printf("Enter your number for toss(1-6): ");       //{
  scanf("%d",&innum);
  if(innum<1||innum>6)
  {
   pflag=1;                                     //TO GET NUMBER WITHIN THE LIMITS
   printf("Enter number within the limits");
 }
 else
 pflag=0;                                                          //}
 }


// printf("\nenter your number for toss(1-6): \n");
// scanf("%d",&innum);
 tossvar=randgen();
 printf("computer: %d",tossvar);
 if((tossvar+innum)%2==choice)
 {
 do
 {
  printf("\nYou Won The Toss\n1.Bat\n2.Bowl");
  printf("\nenter your choice: ");
  scanf("%d",&tchoice);
  switch (tchoice)
  {
   case 1:	 playerturn();
		 computerturn();
		 tflag=0;
		 break;
   case 2:       computerturn();
		 playerturn();
		 tflag=0;
		 break;
   default:      printf("\nwrong choice");
		 tflag=1;
  }
  }while(tflag==1);
  }
  else
 {
  printf("\nYou Lost The Toss\nPress any key to proceed");
  getch();
		 //modifications to be added
  computerturn();      //computer will always opt for batting
  playerturn();       //a random variable to be added which will randomly opt
 }

}
//***************************************************************************

//*******************************PLAYER TURN********************************
void playerturn()
{
 int shot,ran,flag,close=0;
 clrscr();

 printf("\nThis is your Batting. enter a key to start");
 getch();
while(close==0)
{
 ran=randgen();
 flag=1;
 while(flag==1)
 {
  printf("\nEnter your number(1-6): ");       //{
  scanf("%d",&shot);
  if(shot<1||shot>6)
  {
   flag=1;                                     //TO GET NUMBER WITHIN THE LIMITS
   printf("\nEnter number within the limits");
  }
  else
   flag=0;                                                          //}
 }
 if(shot==ran)
  {
   printf("\ncomputer: %d\n",ran);
   printf("\nyou are out\nyour score is: %d\npress any key to proceed",pscore);
   getch();

   close=1;
  }

 else
  {
   printf("\ncomputer: %d\n",ran);
   pscore=pscore+shot;
   close=0;
  }
}


}

//***********************************************************************




//******************COMPUTER TURN*************************************

void computerturn()
{
int shot,ran,flag,close=0;
clrscr();
printf("\nThis is computer Batting. Enter a key to start");
getch();
while(close==0)
{
 ran=randgen();
 flag=1;
 while(flag==1)
 {
  printf("\nThe computer has played his shot. Enter your number(1-6): ");
  scanf("%d",&shot);
  if(shot<1||shot>6)
  {
   flag=1;
   printf("Enter number within the limits");
  }
  else
   flag=0;
 }
 if(shot==ran)
  {
  printf("\ncomputer: %d",ran);
  printf("\nyou bowled computer\ncomputer's score is: %d\npress any key to proceed",cscore);
  getch();
  close=1;
  }
 else
  {
  printf("\ncomputer: %d",ran);
  cscore=cscore+ran;
  close=0;
  }
}
}
//**************************************************************************



//***********************TO cHECK WINNER*************************************
void chkwinner()
{
clrscr();
printf("\nCOMPUTER SCORE: %d\nPLAYER SCORE: %d",cscore,pscore);
if(pscore>cscore)
 printf("\nyou win by %d runs",(pscore-cscore));
else if(cscore>pscore)
 printf("\nyou lose computer wins by %d runs",(cscore-pscore));
else
 printf("\nIts a tie");
}

//*************************************************************************




//*********************************MAIN()***********************************

int  main()
{
char ch;
int ctr;
randomize();
do
  {
  clrscr();
  pscore=0; cscore=0;
  char str[]={"\nWelcome to odd even game\nenter any key to start the game"};
  for(ctr=0;str[ctr]!='\0';ctr++)
  {
  delay(30);
  printf("%c",str[ctr]);
  }

 // printf("Welcome to odd even game\nenter any key to start the game");

  getch();
  toss();
 // playerturn();
 // computerturn();
  chkwinner();
  printf("\ndo you want to play again(y/n)?");
  cin>>ch;
 // scanf("%c",&ch);///////////////////////
  }while(ch=='y'||ch=='Y');
getch();
return 0;
}
//*****************************END OF MAIN*********************************************
