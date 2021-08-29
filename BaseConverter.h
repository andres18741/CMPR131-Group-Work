#pragma once
#include <iostream>
#include <math.h>
#include "input.h"
using namespace std;

//Precondition: N/A
//Postcondition: display the menu for the base converter function
void showMenu2();

//Precondition: N/A
//Postcondition: the driver function for the base converter portion of the program
void baseConverter();

//Precondition: int base and int inputNum
//Postcondition: uses the base and inputNum for base conversion and displays the result of the conversion 
int findResult(int base, int inputNum);

void baseConverter()
{
	system("cls");
	char userOption;
	int inputNum = 0;
	int inputBase = 0;

	do
	{
		showMenu2();
		cin >> userOption;
		cout << "\n";

		if (userOption == 'A' || userOption == 'a')
		{
			cout << "\nEnter an integer of base 10 : ";
			cin >> inputNum;
			cout << "\n";
		}
		if (userOption == 'B' || userOption == 'b')
		{
			inputBase = inputInteger("\nEnter a base number within the range of (2 - 36) : ", 2, 36);
			cout << "\n";

			cout << inputNum << " (base of 10) = " << findResult(inputBase, inputNum) << " (base of " << inputBase << " )\n";
		}
		if (userOption == 'C' || userOption == 'c')
		{
			for (int i = 2; i <= 36; i++)
			{
				cout << "\t" << findResult(i, inputNum) << " (base of " << i << " )\n";
			}
		}
	} while (userOption != '0');
}

int findResult(int base, int inNum)
{
	int num = 0;
	int quotient = inNum;
	int remainder = 0;
	int i = 0;

	while (quotient != 0)
	{
		remainder = quotient % base;
		quotient = quotient / base;

		num = (remainder * pow(10, i)) + num;
		i++;
	}
	return num;
}

void showMenu2()
{
	cout << "\n\t2.) Base Converter\n";
	cout << "______________________________________________\n";
	cout << "A. Enter an Integer Number (base 10)\n";
	cout << "B. Specify and Converting Base\n";
	cout << "C. Display All Converted Bases (2 - 36)\n";
	cout << "______________________________________________\n";
	cout << "0. Exit To Menu\n";
	cout << "______________________________________________\n";
	cout << "Option : ";
}