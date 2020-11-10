#include<iostream>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<cstdio>
#include<termios.h> 
#include<string.h>
#include"car.h"

#define PASSWORD    "pass"

using namespace std;

static struct termios old, nw;
 
/* Initialize new terminal i/o settings */
void initTermios(int echo)
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  nw = old; /* make new settings same as old settings */
  nw.c_lflag &= ~ICANON; /* disable buffered i/o */
  nw.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
  tcsetattr(0, TCSANOW, &nw); /* use these new terminal i/o settings now */
}
 
/* Restore old terminal i/o settings */
void resetTermios(void)
{
  tcsetattr(0, TCSANOW, &old);
}
 
/* Read 1 character - echo defines echo mode */
char getch_(int echo)
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}
 
/* Read 1 character without echo */
char getch(void)
{
  return getch_(0);
}
 
/* Read 1 character with echo */
char getche(void)
{
  return getch_(1);
}
 



int main()
{
	void user_credentials();//************************************************************move this
    user_credentials();
	int choice,vehicle_number1,dn;
	while(1) {
	system("clear");

     cout << "\n\n\t\t ****** CAR PARKING RESERVATION SYSTEM ******";
     cout <<"\n\n                                          ";
     cout<<" \n\t\t\t======================";
     cout << "\n\n\t\t\t  1. Arrival of a Car";
     cout << "\n\n\t\t\t  2. Total no of cars Arrived";
     cout << "\n\n\t\t\t  3. Departure of the car";
     cout << "\n\n\t\t\t  4. Exit Program";
     cout<<" \n\t\t\t======================";
     cout << "\n\n";
     cout << "\t\t\t Select Your Choice ::";
     cin>>choice;
     switch(choice)
     {
      case 1 :
        {		
        		char cont;
        		cout<<"\n\n\t\t==Do You Want to continue==y/n ";
        		cin>>cont;
        		if(cont=='y')
        		{
        		
				ofstream f1("parking3.dat",ios::binary|ios::out|ios::app);
                a.user_ip();
                f1.write((char*)&a,sizeof(a));
        }
            	break;
        }
       case 2 :
           {
           	system("clear");
  		   cout << "\n\n\t\t*** View the Records in the Parking Database ***";
           cout << "\n";
           ifstream infile("parking3.dat",ios::binary|ios::in);
           int dn=1;
           while (infile.read((char *)&a,sizeof (a)))
		   {
			system("clear");
           cout << "\n";
           cout<<"\n\n\tThe Car position in parking lot : "<<dn;
           dn++;
           a.details();
           cout<<"\n";
           cout<<"\n\n\n";
           getchar();
           cout<<endl;
       	   }
       
           break;
       	   }
       	case 3:	
		   {
		   
		   parking_delete();
		   break;
	}
 
   		
   		case 4: 
		   {
		   	system("clear");
		   	cout<<"\n\n\n\t\t\tThank you!\n";
		   exit(0);
   			break;
   		}
   		default : 
		   {
		   cout<<"\n\n\t\t Invalid user input";
			cout<<"\n\n\t\tPress Enter to continue";
			 
   	
   	}
   }
cin.get();
}}
//cpo
void user_credentials(){
   string user_password ="";
   char ch;
   cout <<"\n\n\n\n\n\n\n\t\t\t\t\tCar Parking Reservation System Login";
   cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Password: ";

 int c=0;
    char pass[30]={0};
    int len=0;
    while((ch=getch())!='\n')
    {
        if(ch==0x7f)    // use 0x08 in turboc (WINDOWS)
        {
            if(len==0)  continue;
            printf("\b \b"); len--; continue;
        }
        printf("%c",'*');
        pass[len]=ch;
        len++;
    }
    pass[len]='\0';
   if(strcmp(pass,"pass")){
      cout << "\n\n\n\n\t\t\t\t\t  Access Granted! Welcome To Our System \n\n";
      getchar();
	  return;
      
   }else{
      cout << "\n\n\n\n\t\t\t\t\tAccess Aborted...Please Try Again!!\n";
      getchar();
      system("clear");
      user_credentials();
   }
}
