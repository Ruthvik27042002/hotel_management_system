#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

void Date();
void Booking();
void Room_Info();
void Restaurant();
void Payment();
void Record();

void homepage()
{
	while (1)
	{
		int i = 0;
		char choice;
		system("cls");
		for (i = 0; i < 80; i++)
			printf("-");
		printf("\n");
		printf("\t\t   **********  |MAIN MENU|  *********** \n");
		for (i = 0; i < 80; i++)
			printf("-");
		printf("\n");
		printf("\t\t Please enter your choice for menu:");
		printf("\n\n");
		printf("\n------------------------");
		printf(" \n Enter 1 -> Hotel Room_info");
		printf("\n----------------------------------");
		printf(" \n Enter 2 -> Book a Room");
		printf("\n-----------------------------------");
		printf(" \n Enter 3 -> View your Booked Record");
		printf("\n-----------------------");
		printf(" \n Enter 4 -> Exit");
		printf("\n-----------------");
		printf("\n");
		for (i = 0; i < 80; i++)
			printf("-");
		choice = getche();
		choice = toupper(choice);
		switch(choice)           // SWITCH STATEMENT WITH CHOICE
		{	
			case '1':
				Room_Info();break;
			case '2':
				Booking();break;
			case '3':
				Record();break;
			case '4':
				system("cls");
				printf("\n\n\t **THANK YOU**");
				printf("\n\t FOR TRUSTING OUR SERVICE");
				exit(0);
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\n Press any key to continue");
				getch();
		}
	}
}

struct Room_Service 
{
	char swimming_pool;
	char pets;
	char gym;
	char hospitality;
	char spa;
	char indoor_games;
};


struct CustomerDetails
{
	char roomnumber[10];
	char name[20];
	char address[25];
	char phonenumber[15];
	char nationality[15];
	char email[20];
	char period[10];
	char arrivaldate[10];
	struct Room_Service R;
} s;

int main()
{
	int i = 0;
	char choice;
	system("cls"); // FOR CLEARING SCREEN
	printf("\t\t*****************\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*           WELCOME TO Taj Athulya              *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*        OUR ADRESS:-Taj Athulya , Four star    *\n");
	printf("\t\t*        ADRESS:23-24, Taj East Gate Rd,        *\n");
	printf("\t\t*        Taj Nagari Phase 1, Near Shilpgram,    *\n");
	printf("\t\t*        Telipara,Tajganj, Agra,Uttar Pradesh   *\n");
	printf("\t\t*               282001, India                   *\n");
	printf("\t\t*     CONTACT US:18-87454575552,035455852       *\n");
	printf("\t\t*****************\n\n\n");
	printf(" \n Press any key to continue:");
	getch();
	system("cls");
	homepage();
	system("cls");
	
	return 0;
}

void Date() {
	// time_t t;
	// time(&t);
	// for(int i=0;i<80;i++)
	// printf("-");
	//     printf("\nCurrent date and time : %s",ctime(&t));
	//     for(int i=0;i<80;i++)
	// printf("-");
}

void Booking() {
    FILE *f;
	char test;
	f=fopen("add.txt","a+");
	if(f==0)
	{   f=fopen("add.txt","w+");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}
	while(1)
	{
		system("cls");
		printf("\n Enter Customer Details:");
		printf("\n**********");
		printf("Enter Name:\n");
		scanf("%s",s.name);
		printf("Enter Address:\n");
		scanf("%s",s.address);
		printf("Enter Phone Number:\n");
		scanf("%s",s.phonenumber);
		printf("Enter Nationality:\n");
		scanf("%s",s.nationality);
		printf("Enter Email:\n");
		scanf(" %s",s.email);
		printf("Enter Period(\'x\'days):\n");
		scanf("%s",&s.period);
		printf("Enter Arrival date(dd\\mm\\yyyy):\n");
		scanf("%s",&s.arrivaldate);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		printf("\n\n1 Room is successfully booked!!");
		printf("\n Press esc key to exit,  any other key to add another customer detail:");
		test=getche();
		if(test==27)
			break;
			
	}
	fclose(f);
}

void Room_Info() {
	
}

void Restaurant() {

}

void Payment() {

}

void Record() {

}