#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BUFFER_SIZE 1000

/* Function declarations */
int indexOf(FILE *fptr, const char *word, int *line);
void Date();
void Booking(float *pay);
void Room_Info();
void Restaurant();
void Payment();
void Record();
void randomPasswordGeneration(int N);

void homepage()
{
	float *payment;
	payment = (float *)malloc(sizeof(float));
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
		printf("\n");
		choice = getche();
		choice = toupper(choice);
		switch (choice) // SWITCH STATEMENT WITH CHOICE
		{
		case '1':
			Room_Info();
			break;
		case '2':
			Booking(payment);
			break;
		case '3':
			Record();
			break;
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
	int countofrooms;
	int countofpersons;
	struct Room_Service R;
} s;

struct Payment
{
	int room;
	short int swimmingpool;
	short int pets;
	short int gym;
	short int hospitality;
	short int spa;
	short int indoor_games;
	int veg;
	int non_veg;
	int total;
} cash;

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
	Date();
	printf(" \n Press any key to continue: \n");
	getch();
	system("cls");
	homepage();
	system("cls");

	return 0;
}

void Date()
{
	time_t t;
	time(&t);
	for (int i = 0; i < 80; i++)
		printf("-");
	printf("\nCurrent date and time : %s", ctime(&t));
	for (int i = 0; i < 80; i++)
		printf("-");
}

void Booking(float *pay)
{
	FILE *f, *r;
	int room;
	char test;
	f = fopen("add.txt", "a+");
	if (f == 0)
	{
		f = fopen("add.txt", "w+");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}
	while (1)
	{
		system("cls");
		printf("\t\t\t Enter Customer Details:");
		printf("\n**********\n");
		printf("Enter Name:\n");
		scanf("%s", s.name);
		printf("Enter Address:\n");
		scanf("%s", s.address);
		printf("Enter Phone Number:\n");
		scanf("%s", s.phonenumber);
		printf("Enter Nationality:\n");
		scanf("%s", s.nationality);
		printf("Enter Email:\n");
		scanf(" %s", s.email);
		printf("Enter Period(\'x\'days):\n");
		scanf("%s", &s.period);
		printf("Enter the number of persons for the stay in the hotel: \n");
		scanf("%d", &s.countofpersons);
		printf("Enter Arrival date(dd\\mm\\yyyy):\n");
		scanf("%s", &s.arrivaldate);
		printf("\n");
		printf("Choose the Room that you want:\n");
		printf("\t\t\t\t  Types-of-Rooms     No.of Rooms   Cost/day \n");
		printf("\t\t\t\t ********************************************\n");
		printf("\t\t\t\t  Suite-room       \t   2 \t   $400/day\n");
		printf("\t\t\t\t  Deluxe-Rooms     \t   3 \t   $320/day\n");
		printf("\t\t\t\t  Semi-Deluxe-room \t   5 \t   $260/day\n");
		printf("\t\t\t\t  Normal-Room      \t   8 \t   $100/day\n\n\n\n");
		printf("\n");
		printf("\t\t\t\t  Room-numbers                              Types-of-Rooms \n");
		printf("\t\t\t\t ************************************************************\n");
		printf("\t\t\t\t   101, 201                                 Suite Rooms\n");
		printf("\t\t\t\t   102, 202, 302                            Deluxe Rooms\n");
		printf("\t\t\t\t   103, 203, 303, 403, 405                  Semi-Deluxe Rooms\n");
		printf("\t\t\t\t   104, 204, 301, 304, 305, 401, 402, 404   Normal Rooms\n");
		//opening file of rooms
		FILE *fptr;
		char path[100];

		char word[50];

		int line;

	SearchRoom:
		/* Input word to search in file */
		printf("Enter the Room to be searched: \n");
		scanf("%s", word);

		/* Try to open file */
		fptr = fopen("rooms.txt", "r");

		/* Exit if file not opened successfully */
		if (fptr == NULL)
		{
			printf("Unable to open file.\n");
			printf("Please check you have read/write previleges.\n");

			exit(EXIT_FAILURE);
		}

		// Find index of word in fptr
		indexOf(fptr, word, &line);

		if (line != -1)
		{
			printf("'%s' room is Available\n", word);
			strcpy(s.roomnumber, word);
		}
		else
		{
			printf("'%s' room is not Available\n", word);
			goto SearchRoom;
		}
		// Close file
		fclose(fptr);
		printf("\t\t\t Facilities\n");
		printf("Enter 'Y' if you want particular facility, if not press any key.\n");
		printf("Swimming pool:\t");
		scanf(" %c", &s.R.swimming_pool);
		printf("pets:\t");
		scanf(" %c", &s.R.pets);
		printf("Gym:\t");
		scanf(" %c", &s.R.gym);
		printf("Hospitality:\t");
		scanf(" %c", &s.R.hospitality);
		printf("Spa:\t");
		scanf(" %c", &s.R.spa);
		printf("Indoor Games:");
		scanf(" %c", &s.R.indoor_games);
		fwrite(&s, sizeof(s), 1, f);
		fflush(stdin);
		printf("\n\n1 Room is successfully booked!!");
		printf("\n Press esc key to exit,  any other key to add another customer detail:");
		test = getche();
		if (test == 27)
			break;
	}
	fclose(f);
}

void Room_Info()
{
	char test;
	while (1)
	{
		system("cls");
		printf("\n\n\n\n\n");
		printf("\t\t\t\t\t\t Room-Information \n\n");
		printf("\t\t\t\t  Types-of-Rooms     No.of Rooms   Cost/day \n");
		printf("\t\t\t\t ********************************************\n");
		printf("\t\t\t\t  Suite-room       \t   2 \t   $400/day\n");
		printf("\t\t\t\t  Deluxe-Rooms     \t   3 \t   $320/day\n");
		printf("\t\t\t\t  Semi-Deluxe-room \t   5 \t   $260/day\n");
		printf("\t\t\t\t  Normal-Room      \t   8 \t   $100/day\n\n\n\n");
		printf("\t\t\t\t\t     Room-Facilities \n\n");
		printf("\t\t\t\t\t Facilities    \t   Cost/day \n");
		printf("\t\t\t\t\t*****************************\n");
		printf("\t\t\t\t\t Swimming-pool \t   $10/day\n");
		printf("\t\t\t\t\t pet           \t   $2/day\n");
		printf("\t\t\t\t\t gym           \t   $2/day\n");
		printf("\t\t\t\t\t hospitality   \t   $2/day\n");
		printf("\t\t\t\t\t spa           \t   $8/day \n");
		printf("\t\t\t\t\t indoor-games  \t   $2/day \n\n\n\n");
		printf("\t\t\t\t\t   Restaurant-Information \n\n");
		printf("\t\t\t\t\t Type          \t   Cost/day \n");
		printf("\t\t\t\t\t*****************************\n");
		printf("\t\t\t\t\t veg-food      \t   $10/day \n");
		printf("\t\t\t\t\t nonveg-food   \t   $15/day\n\n");
		printf("\t Press esc key to exit,  any other key to add another customer detail:\n");
		test = getche();
		if (test == 27)
			break;
	}
}

void Restaurant()
{
}

void Payment(float *pay)
{
	int c, c1, c2;
	printf("Please select your payment method: 1.net banking, 2.debit card");
	scanf("%d", &c);
	if (c = 1)
	{
		printf("Select the bank type to proceed the transaction: 1.SBI, 2.ICICI");
		scanf("%d", &c1);
		printf("Please enter your login details");
		scanf("%d", &c2);
		printf("Please enter the OTP which has sent to your mobile");
	}
}

void Record()
{
}

int indexOf(FILE *fptr, const char *word, int *line)
{
	char str[BUFFER_SIZE];
	char *pos;

	*line = -1;

	while ((fgets(str, BUFFER_SIZE, fptr)) != NULL)
	{

		// compare the room number in the file.
		pos = strstr(str, word);

		if (pos != NULL)
		{
			*line += 1;
			break;
		}
	}

	return 0;
}

//Generating the random OTP
void randomPasswordGeneration(int N)
{

	// Seed the random-number generator
	// with current time so that the
	// numbers will be different every time
	srand((unsigned int)(time(NULL)));

	// Array of numbers
	char numbers[] = "0123456789";

	// Stores the random password
	char password[N];

	// Iterate over the range [0, N]
	for (int i = 0; i < N; i++)
	{
		password[i] = numbers[rand() % 10];
		printf("%c", password[i]);
	}
}