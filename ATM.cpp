#include <iostream>
#include <string>
#include <iomanip>
#include <locale>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void loading()
{
	string loadingText = ".................";
	for (int i = 0; i < loadingText[i]; i++)
	{
		cout << loadingText[i];
		Sleep(50);//printing out hello message and 200 mill seconds
	}
}

bool login()
{
	string accountNums[] = { "000001", "000002", "000003" };
	string accountInput;

	int SIZE = sizeof(accountNums) / sizeof(accountNums[0]);

	while (1)
	{
		cout << "\nEnter your account number: ";
		cin >> accountInput;

		system("cls");
		loading();
		system("cls");

		for (int i = 0; i < SIZE; i++)
		{

			if (accountInput == accountNums[i])
			{


				cout << "\nAccount Valid!\n" << endl;
				system("PAUSE");
				return 0;


			}

		}

		cout << "\nInvalid Account Number\n";
	}
}


void showMenu()//function for menu
{
	cout << "**********MENU**********" << endl;
	cout << "* 1. Check Balance     *" << endl;
	cout << "* 2. Withdraw          *" << endl;
	cout << "* 3. Deposit           *" << endl;
	cout << "* 4. Exit              *" << endl;
	cout << "************************" << endl;
}

void startText()
{
	string welcome = "Welcome to the Smart Bank INC. ATM!";
	for (int i = 0; i < welcome[i]; i++)
	{
		cout << welcome[i];
		Sleep(60);//printing out hello message and 200 mill seconds
	}
}

int main()
{
	srand(time(NULL));

	//Variables
	int option = 0;
	long double balance = long double(rand() % 4000 + 100);
	long double deposit = 0.00;
	long  double withdraw = 0.00;



	startText();
	cout << endl << endl;
	system("PAUSE");
	system("cls");//clear console
	login();

	do
	{
		system("cls");
		cout << endl; //spacing from top 
		showMenu();
		cout << "Option: ";
		cin >> option;
		if (option < 1 || option > 4 || cin.fail())//if input != valid, throw error
		{
			system("cls");
			cout << "\nInvalid Option!" << endl << endl;
			showMenu();
			cin.clear();
			cin.ignore();
			cout << "Option: ";
			cin >> option;

		}

		switch (option)//switch cases to go through menu options
		{
		case 1:
			system("cls");//clear console
			cout.imbue(locale("en_US.utf8"));//csv format for numbers
			cout << fixed << setprecision(2) << showpoint;
			cout << "\nBalance: " << "$" << balance << endl;
			system("PAUSE");
			break;

		case 2:
			system("cls");
			cout << "\nEnter the amount you want to withdraw: $";
			cin >> withdraw;
			if (balance < withdraw)
			{
				cout << "\nInsufficient Funds!" << endl;
				cout << "\nEnter the amount you want to withdraw: ";
				cin >> withdraw;
			}
			balance -= withdraw; break;

		case 3:
			system("cls");
			cout << "\nEnter the amount you want to deposit: $";
			cin >> deposit;
			balance += deposit;
			break;

		case 4:
			system("cls");
			string exit = "Thank You for using Smart Bank INC.";
			for (int i = 0; i < exit[i]; i++)
			{
				cout << exit[i];
				Sleep(60);//printing out goodbye message and 200 mill seconds
			}
			cout << endl; break;
		}
	} while (option != 4);//break loop if 4

	return 0;
}
