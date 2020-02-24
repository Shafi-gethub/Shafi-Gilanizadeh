/*
fileName: MatrixType.h
Author  : Shafi Gilanizadeh
Due date: feb.12.2020
Purpose : The header file will contain all the function prototypes that will be used through out the programs execution
*/


#pragma once
#include <fstream>
using namespace std;

const int MAX_ROWS = 10;
const int MAX_COLS = 10;
class MatrixType
{
public:
    MatrixType();                                              // Default constructor   
    void MakeEmpty();                                          // function to set everything to 00
    void SetSize(int rowsSize, int colSize);                   // Setsize will set the size of our private veriables
    void StoreItem(int item, int row, int col);                // storItem will store the item at specific slot in the matrix
    void Print(ostream& outfile);                              // print function will print the matrices

    // ??????????????????????????????????????????????????????????????????????????????????????????????? ask why i cant use ofstream as described in the assignment

    /*  pre:    will have three different functions add, sub, mult to perform the matrix operatios
        post:   sed of the users intenion, we will perform matametical operation on the matrix and return the result
    */
    void Add(MatrixType otherOperand, MatrixType& result);
    void Sub(MatrixType otherOperand, MatrixType& result);
    void Mult(MatrixType otherOperand, MatrixType& result);

    /*
        pre: using operators are by choice, instead of calling the functions from testdriver to perform any operations, we will use operators .
        post: using operator are very convinient for user to perform the task, user doesnt need to call any function to perform add, sub or mult
              user the directly add, sub or mult the object of the class and it will be performed.
    
    */
    MatrixType operator+(MatrixType other);
    MatrixType operator-(MatrixType subobject);
    MatrixType operator*(MatrixType multobject);
  
    /*
        pre:    boolean functions will determine if the matrixes meet all the requirements to complete the task
        post:   the functions will return true and allow the operations if it meets the pre defined conditions
    */
    bool AddSubCompatible(MatrixType otherOperand);
    bool MultCompatible(MatrixType otherOperand);
private:
    // private members, thees members are only accessible by clas member functions
    int values[MAX_ROWS][MAX_COLS];
    int numRows;
    int numCols;
};

