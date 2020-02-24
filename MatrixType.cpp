/*
fileName: MAtrixType.cpp
Author  : Shafi Gilanizadeh
Due date: feb.12.2020
Purpose : The purpose of MatrixType.cpp is to implement the functions with the most efficient and clear solutions to perform the tasks.
*/
#include "MatrixType.hpp"
#include <iostream>
#include <fstream>
using namespace std;

/*	pre : The default constructor will reset the private variable, it helps the variable tobe assigned with any random or junk number from the compiler
	post: the user can now easily assign the number of rows and column, now forsure the veriables are holding a null value.
*/
MatrixType::MatrixType()
{
	numRows = 0;
	numCols = 0;
}

/* pre:	The puspose of storeItem is to store the values of the matrix as the user defines them.
   post: as user send the values at the specific number of rows/colums or the slot at the matrix, the storeitem function will store it at that position
*/
void MatrixType::StoreItem(int item, int row, int col)
{

	values[row][col] = item;
}

/* pre: the print function will print the matrixes defined or called by uer to be displayed in the screen
   post: As soon as the pint function gets the cout stream class operator as function prototype, outfile will perform the displying process
		everything in the array will be displayed in the screen.

*/
void MatrixType::Print(ostream& outfile)	// Why ofstream. i chenged to ostream,its not a file objet  so ofstream wont work ????????????????????????????????????????????????????????????
{
	for (int i = 0; i < numRows; i++)
	{
		outfile << "[";
		for (int j = 0; j < numCols; j++)
		{
			outfile << values[i][j] << " ";
		}
		cout << "]" << endl;
	}
}

/* pre: the purpose setsize is to continously update and set the number of rows and collumn to the private veriables
   post: As the user entered the size of different matrixes in different slots, setSizze will update the size of private member functions so later we can use it
*/

void MatrixType::SetSize(int rowsSize, int colSize)
{
	numRows = rowsSize;
	numCols = colSize;
}

/* pre: The puspose of Makeempty function is to make a new empty matrix for the result OR dump everything out and fill it with zero's
   post: In most cases user needs to guarantee that the matrix is not filled with junk numbers from compiler, it resets everything to NULL

*/
void MatrixType::MakeEmpty()
{
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			values[i][j] = 0;
		}

	}
}

/* pre: The purpose of add function is to add two matrixes and return the result
   post: after having multiple matrixes, the user is able to choice if any of the two needs to be added, as soon as the user choices to add the two matrixes
		 a new location for the size of the two matrix will be created and setted to null to be ready to store the proper result values in the new matrix

*/
void MatrixType::Add(MatrixType otherOperand, MatrixType& result)
{
	if (!otherOperand.AddSubCompatible(*this))
		return;
	//this->AddSubCompatible(otherOperand);
	//AddSubCompatible(otherOperand);

	result.SetSize(numRows, numCols);
	result.MakeEmpty();

	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			result.StoreItem(otherOperand.values[i][j] + values[i][j], i, j);

		}
	}


}

/*  pre: The purpose of the sub function is to subtrack a matrix from the other matrix
	post: The sub funtion will automatically create a new empty spot of the same size for the result as soon as the user wants to subtrack two matrixes
		  The nested for loop will have access to each element in each row and column to perform the task.
*/

void MatrixType::Sub(MatrixType otherOperand, MatrixType& result)
{
	if (!AddSubCompatible(*this))
		return;
	result.SetSize(numRows, numCols);
	result.MakeEmpty();

	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			result.StoreItem(otherOperand.values[i][j] - values[i][j], i, j);
			//cout << "\n" << result.values[i][j];
		}
	}



}

/* pre: the purpose of multiplication function is to multiply two matrices, the design of this function will wor the way to multiply each row by each column of two matrices.
   post: the multiplication function will check if the two matrices are qualifying to be multiplied, after qualifying result, the function will automatically create a 
		new matrix of the same row and column size and store the result of the multuplication of the two matrices into the new matrix.

*/
void MatrixType::Mult(MatrixType otherOperand, MatrixType& result)
{

	if (!MultCompatible(otherOperand))
		return;

	result.SetSize(numCols, otherOperand.numRows);
	// result.SetSize(this->numCols, otherOperand.numRows);		// equivalent statement
	result.MakeEmpty();

	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			for (int k = 0; k < numRows; k++)
			{
				result.values[i][j] = result.values[i][j] + values[i][k] * otherOperand.values[k][j];

			}
		}
	}
}


/* pre: The purpose of addsubcomp, is to check if two matrices qualifies to be addedd or subtrackted with eachother
	post: the funtion will check the number of rows and column of the two matrixes to see if they both has the same size, if so, then it will allow the other functions
		to perform their jobs, so this function will work as a pre testing condition.
*/

bool MatrixType::AddSubCompatible(MatrixType otherOperand)
{
	 return (numRows == otherOperand.numRows && numCols == otherOperand.numCols);
	 
}
/* pre: The purpose of multcomp, is to check if two matrices qualifies to be multiplied with eachother.
	post: the funtion will check the number of columns and rows of the two matrixes to see if they both has the same size, if so, then it will allow the other functions
		to perform their jobs, so this function will work as a pre testing condition.
*/
bool MatrixType::MultCompatible(MatrixType otherOperand)
{
	return (numCols == otherOperand.numRows);
}


/* pre: 
The whole purpose of using operators is to make a very easy and effiect calling routin to the functions, the user doesnt need to call the function and pass something
		as a parameter and ect. the operators will allow to perform the same by applying the matamatical operations to the object itself, add, sub, mult, two objects.
  post: operators will be called as soon as the user defines the + - * between two class objects, operator will allow the users to add two class objects, operator will 
		ivoke the specific function to perform the task. 

*/

MatrixType MatrixType::operator+(MatrixType other)
{
	MatrixType res;
	res.SetSize(numRows, numCols);
	res.MakeEmpty();
	Add(other, res);
	return res;
}

MatrixType MatrixType::operator-(MatrixType subobject)
{
	MatrixType subResult;
	subResult, SetSize(numRows, numCols);
	subResult.MakeEmpty();
	Sub(subobject, subResult);

	return subResult;

}

MatrixType MatrixType ::operator*(MatrixType multobject)
{
	MatrixType multRes;
	multRes.SetSize(numRows, numCols);
	multRes.MakeEmpty();

	Mult(multobject, multRes);
	return multRes;

}



