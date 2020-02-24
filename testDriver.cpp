/*

fileName: testDriver.cpp
Author  : Shafi Gilanizadeh
Due date: feb.12.2020
Purpose : The purpose of this program is tobe able to process all matricea operations such as addition, multiplication and subtraction.
In this program, we will be using 2D arrays, nested for loops, classes and operators.

*/

#include "MatrixType.hpp"
#include <iostream>
using namespace std;


// DONT forget to use ENUM TYPE for switch conditions .........................????????
enum selection {NEW,ADD,SUB,MULT,PRINT, SLOT,QUIT };

int main()
{
	int choice, param, itemm;				// veriables for user to input the choice from menu, parameter and itemm = for element of the matrix
	int inputColumn, inputRow;				// veriable for user to input the number of rows and columns 
	bool LOOP = true;						// boolean veriable to control the while loop
	int slot1, slot2, slot3;				// veriable for user input choices
	MatrixType ClassObject[10];				// An array of object to have access to all class instancces and the funcitons
	const int MENU_OPTIONS = 6;			// A constant variable to determine the number of available menu 
	bool nslots[10];

	for (int i = 0; i < 10; i++)
	{
		nslots[i] = false;
	}

	// Menu: The user willl have to choice an option from the menu, inorder to be proccessed for the next promt
	// ************************* MENU **************************************
	cout << "Choice and parameters:" << endl;
	cout << "0 New Matrix			Usage: 0 <matrix>  " << endl;
	cout << "1 Add Matrices			Usage: 1 <matrix>   <matrix>   <matrix>  " << endl;
	cout << "2 Subtrack Matrices		Usage: 2 <matrix>   <matrix>   <matrix>  " << endl;
	cout << "3 Multiply Matrices		Usage: 3 <matrix>   <matrix>   <matrix>  " << endl;
	cout << "4 Print Matrices		Usage: 4 <matrix>  " << endl;
	cout << "5 print number of filled slots " << endl;
	cout << "6 Quit				Usage: 5 \n\n";
	

	while (LOOP == true)
	{
		// pre: the purpose is to check if the user enters any option that are not available in the menu
		// post: If so, allow the user to re-enter their choice and re-proccess the choice from the meun	
		cout << "Enter Choice and parameters: " << endl;
		cin >> choice;
		if(choice <0 || choice > MENU_OPTIONS)
			cerr << "Invalid menu option selection....! "<< endl;

		// Pre: Based of the user input, we will be matching it to the cases available into the switch statement
		// Post: After ivoking the correct case, we will call the appropriate function or operator to perfrom the specific task
		switch (choice)
		{
		case NEW:
			cin >> param;						// ask the user to enter a object parameter, in whcih the matrix will be obtained as a number of slot in the 2D array
			if (nslots[param])
			{
				cout << "\nSlot is already created....";
				break;
			}
			nslots[param] = true;
			cout << "Creating new matrix in slot  " << param << "." << endl;
			cout << "Enter row and column size: ";
			// allow the user to enter the number of row and column for the new matrix they are intended to create
			cin >> inputRow >> inputColumn;		
			// we will be setting the size of object at specific slot based of the bumber of rows and columns
			ClassObject[param].SetSize(inputRow, inputColumn);

			/*	Pre: we will be using a nested for loop to allow the user to enter the number of rows and columns of the matrixes
				post: we will be pushing the element into the array using the storItem function one by one. So all the elmenets will be stored
				2D array in the specific position based of the total number of rows and columns
			*/	
			for (int i = 0; i < inputRow; i++)
			{
				cout << "Row " << i << ":";
				for (int j = 0; j < inputColumn; j++)
				{
					cin >> itemm;
					ClassObject[param].StoreItem(itemm, i, j);		// pass the elements one by one
				}
			}
			ClassObject[param].Print(cout);							// call the print function to display the matrix at specific object  
			break;
		case ADD:
			cout << "Add Matrices " << endl;
			cin >> slot1 >> slot2 >> slot3;							// allow the user to input which matrixes needs to be addedd
			// the function add caling routin is uncommanded because now the operator is used to sum the matrices
			//ClassObject[slot1].Add(ClassObject[slot2], ClassObject[slot3]);
			// add the slot 1 and 2 and store the result in slot 3
			nslots[slot1] = true;
			nslots[slot2] = true;
			nslots[slot3] = true;

			ClassObject[slot3]=ClassObject[slot1] + ClassObject[slot2];
			break;
		case SUB:
			cout << "Subtrack Matrices " << endl;
			// pre: The objct calling function rotin is uncommanded
			// post: the user will enter the slots which needs to be performed with operations
			cin >> slot1 >> slot2 >> slot3;
			nslots[slot1] = true;
			nslots[slot2] = true;
			nslots[slot3] = true;

			
			//ClassObject[slot1].Sub(ClassObject[slot2], ClassObject[slot3]);
			ClassObject[slot3] = ClassObject[slot2] - ClassObject[slot1];

			break;
		case MULT:
			cout << "Multiply Matrices " << endl;
			cin >> slot1 >> slot2 >> slot3;
			nslots[slot1] = true;
			nslots[slot2] = true;
			nslots[slot3] = true;

			//assObject[slot1].Mult(ClassObject[slot2], ClassObject[slot3]);
			ClassObject[slot3] = ClassObject[slot1] * ClassObject[slot2];
			break;
		case SLOT:
			for (int i = 0; i < 10; i++)
			{
				if (nslots[i] == true)
					cout << "Slots number: " << i << " : " << nslots[i] << " " << endl;
			}
			break;
		case PRINT:
			// user need to select which slot to print
			cout << "Print Matrices " << endl;
			cin >> slot1;
			ClassObject[slot1].Print(cout);
			break;
		
		case QUIT:
			cout << "Quite " << endl;
			LOOP = false;
			break;
		default:
			cout << "Invalid inupt..!" << endl;
			break;
		}
	}
	return 0;
}