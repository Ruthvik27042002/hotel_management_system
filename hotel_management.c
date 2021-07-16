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
		printf(" \n Enter 1 -> Book a Room");
		printf("\n------------------------");
		printf(" \n Enter 2 -> External RoomServices");
		printf("\n----------------------------------");
		printf(" \n Enter 3 -> Restaurant Food Servicses");
		printf("\n-----------------------------------");
		printf(" \n Enter 4 -> Payment for Selected Room");
		printf("\n-----------------------------------");
		printf(" \n Enter 5 -> View Record");
		printf("\n-----------------------");
		printf(" \n Enter 6 -> Exit");
		printf("\n-----------------");
		printf("\n");
		for (i = 0; i < 80; i++)
			printf("-");
		choice = getche();
		choice = toupper(choice);
		switch(choice)           // SWITCH STATEMENT
		{	
			case '1':
				Booking();break;
			case '2':
				Room_Info();break;
			case '3':
				Restaurant();break;
			case '4':
				Payment();break;
			case '5':
				Record();break;
			case '6':
				system("cls");
				printf("\n\n\t **THANK YOU**");
				printf("\n\t FOR TRUSTING OUR SERVICE");
			//	Sleep(2000);
				exit(0);
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\n Press any key to continue");
				getch();
		}
	}
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

};

void Booking() {

};

void Room_Info() {

};

void Restaurant() {

};

void Payment() {

};

void Record() {

};