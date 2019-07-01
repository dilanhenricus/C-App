#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <conio.h>
using namespace std;

class Customer {
public:
	string accountNumber = "";
	Customer() { }
};

class SLCOM {
private:
	string userName = "admin";
	string userloginName = "admin";
	string primaryCommand;
	string command;
	int insertCursor = 0;
	
	vector<Customer> customers;
	int session = 0;
	int initialize = 1;
public:
	SLCOM() {
		cout << "============================" << endl;
		cout << "| SLCOM Management Systems |" << endl;
		cout << "| Copyright (c) 2019       |" << endl;
		cout << "| Version 1.0              |" << endl;
		cout << "============================" << endl;
		cout << "\n";
	}
	void clearScreen()
	{
		system("cls");
		cout << "============================" << endl;
		cout << "| SLCOM Management Systems |" << endl;
		cout << "| Copyright (c) 2019       |" << endl;
		cout << "| Version 1.0              |" << endl;
		cout << "============================" << endl;
		cout << "\n";
	}
	void exit()
	{
		clearScreen();
		cout << "Shutting down system....................................done" << endl;
		cout << "Developed by Dilan Henricus (c) 2019" << endl;
		cout << "Version 1.0" << endl;
		cout << "Goodbye!" << endl;
	}
	void login()
	{

		string inputUser;
		string inputPass;
		int loginAttempt = 0;

		while (loginAttempt < 5)
		{
			cout << "Enter User ID: ";
			cin >> inputUser;
			cout << "Enter Password for user " + inputUser + ": ";
			cin >> inputPass;
			clearScreen();
			if (inputUser == userName && inputPass == userloginName)
			{
				session = 1;
				break;
			}
			else
			{
				cout << "================================================" << endl;
				cout << "| ALERT!                                       |" << endl;
				cout << "================================================" << endl;
				cout << "| Login failed!                                |" << endl;
				cout << "| Please check your credentials and try again! |" << endl;
				cout << "|                                              |" << endl;
				cout << "================================================" << endl;
				cout << "\n";
				loginAttempt++;
			}
		}
		if (loginAttempt == 5)
		{
			cout << "================================================" << endl;
			cout << "| ALERT!                                       |" << endl;
			cout << "================================================" << endl;
			cout << "| Too many failed login attempts!              |" << endl;
			cout << "| SLOCOM Management Systems will now shutdown. |" << endl;
			cout << "|                                              |" << endl;
			cout << "| Goodbye!                                     |" << endl;
			cout << "================================================" << endl;
		}
		else {
			mainMenu();
		}
	}

	void mainMenu()
	{
		while (initialize == 1)
		{
			clearScreen();
			cout << "Welcome to SLCOM Management Main Menu.";
			cout << "\n\n";
			cout << "1. Manage Customer Details" << endl;
			cout << "2. View Account Details" << endl;
			cout << "3. View Package Details" << endl;
			cout << "4. Calculate and Print Bill" << endl;
			cout << "5. Help" << endl;
			cout << "6. Exit" << endl;
			cout << "\n Please enter the preferred option to continue..." << endl;
			cout << "\n>";

			cin >> command;
			if (command == "1")
			{
				customerManager();				
			}
			else if (command == "2")
			{
				viewAllCustomers();
			}
			else if (command == "3")
			{

			}
			else if (command == "4")
			{

			}
			else if (command == "5")
			{

			}
			else if (command == "6")
			{
				exit();
				break;
			}
			else
			{
				cout << "Invalid input. Please try again" << endl;
				cout << "\n>";
			}
		}

	}

	void viewAllCustomers() {
		for (Customer customer : customers) {
			cout << "================================================" << endl;
			cout << "Customer account number : " + customer.accountNumber << endl;
			cout << "================================================" << endl;
			cout << "\n";
		}

		cout << "Press Enter to return to the main menu........... "<< endl;
		string temp;
		_getch();
	}

	void newCustomer()
	{
		clearScreen();
		cout << "Add new customer wizard... Enter B to go back to previous menu" << endl;
		cout << "\n";
		while (initialize == 1)
		{
			string accountNumber;
			cout << "Please enter the Customer account number:" << endl;
			cout << "\n>";

			cin >> accountNumber;
			if (accountNumber == "")
			{
				cout << "Please insert the Customer ID" << endl;
				cout << "\n>";

			}

			string customername;
			cout << "Please enter Customer Name:" << endl;
			cout << "\n";

			cin >> customername;
			if (customername == "")
			{
				cout << "Please enter the Customer Name" << endl;
				cout << "\n";

			}

			string customerAddress;
			cout << "Please enter the Customer Address:" << endl;
			cout << "\n";

			cin >> customerAddress;
			if (customerAddress == "")

			{
				cout << "Please enter the Customer Address" << endl;
				cout << "/n";

			}
			string customerTele;
			cout << "Please enter the Customer Telephone Number:" << endl;
			cout << "/n";

			cin >> customerTele;
			if (customerTele == "")

			{
				cout << "Please enter the Customer Telephone Number:" << endl;
				cout << "/n";

			}

			else if (accountNumber == "B") {
				break;
			}
			else
			{
				Customer customer;
				customer.accountNumber = accountNumber;
				customers.push_back(customer);
				insertCursor++;
				break;
			}
		}
	}
	void editCustomer()
	{

	}
	void deleteCustomer()
	{

	}

	void customerManager()
	{
		

		while (initialize == 1)
		{
			clearScreen();
			cout << "Manage Customer Details" << endl;
			cout << "\n";
			cout << "1. Add New Customer Account" << endl;
			cout << "2. Edit Customer Account" << endl;
			cout << "3. Delete Customer Account" << endl;
			cout << "4. Go to Main Menu" << endl;
			cout << "\n\n Please enter the preferred option to continue..." << endl;
			cout << "\n>";
			cin >> command;
			if (command == "1")
			{
				newCustomer();
			}
			else if (command == "2")
			{
				editCustomer();
			}
			else if (command == "3")
			{
				deleteCustomer();
			}
			else if (command == "4")
			{
				break;
			}
			else
			{
				cout << "Invalid input. Please try again..." << endl;
				cout << "\n>";
			}
		}

	}
};

int main ()
{
	SLCOM slcom;
	slcom.clearScreen();
	slcom.login();
}




