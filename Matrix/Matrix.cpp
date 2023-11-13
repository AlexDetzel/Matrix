// Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include "MyMatrix.h"

void fillWithHands(MyMatrix& matrix)
{
    int number;

    for (int i = 0; i < matrix.getRows(); i++)
    {
        for (int j = 0; j < matrix.getCols(); j++)
        {
            matrix.fillOneValue(i, j, 1);
        }
    }

    for (int i = 0; i < matrix.getRows(); i++)
    {
        for (int j = 0; j < matrix.getCols(); j++)
        {
            for (int ii = 0; ii < matrix.getRows(); ii++)
            {
                for (int jj = 0; jj < matrix.getCols(); jj++)
                {
                    if (i == ii && j == jj)
                    {
                        std::cout << "@" << "\t";
                    }
                    else
                        std:cout << matrix.getOneValue(ii, jj) << "\t";
                }
                std::cout << "\n\n";
            }
            std::cout << "Write nubber:" << "\n";
            std::cin >> number;
            matrix.fillOneValue(i, j, number);
        }
    }
}

void openInterface()
{
    while (true)
    {
        int rows;
        int cols;
        int command;
        int action;
        string path;
        MyMatrix matrix(1,1);
        std::cout << "Hello, here you creat your own Matrix and make with her different things" << "\n";
        std::cout << "Firstly how you want to creat your matrix?" << "\n";
        std::cout << "1.Creat Random Matrix" << "\t" << "2.Creat Matrix from CSV file" << "\t";
        std::cout << "3.Creat Matrix b Myself" << "\t" << "4.Exit App" << "\n";
        std::cout << "Write here your choice:" << "\t" << "\n\n";
        std::cin >> command;
        if (command == 4)
        {
            break;
        }
        switch (command)
        {
        case 1:
        {
            std::cout << "Write count of rows your random Matrix:" << "\n";
            std::cin >> rows;
            std::cout << "\n";
            std::cout << "Write count of cols your random Matrix:" << "\n";
            std::cin >> cols;
            std::cout << "\n";
            MyMatrix newMatrix(rows, cols);
            matrix = newMatrix;
            matrix.fillRand();
            break;
        }
        case 2:
        {
            std::cout << "Write path to your Matrix:" << "\n";
            std::cin >> path;
            std::cout << "\n";
            MyMatrix newMatrix(path);
            matrix = newMatrix;
            break;
        }
        case 3:
        {
            std::cout << "Write count of rows your random Matrix:" << "\n";
            std::cin >> rows;
            std::cout << "\n";
            std::cout << "Write count of cols your random Matrix:" << "\n";
            std::cin >> cols;
            std::cout << "\n";
            MyMatrix newMatrix(rows, cols);
            matrix = newMatrix;
            fillWithHands(matrix);
            break;
        }
        }
        while (true)
        {
            std::cout << "Its your Matrix now:" << "\n";
            matrix.print();
            std::cout << "\n";
            std::cout << "What you would want to do with her?" << "\n";
            std::cout << "1.Multiply by Number" << "\t" << "2.Find the determinant" << "\t";
            std::cout << "3.Find transposed Matrix" << "\t" << "4.Find reverse Matrix" << "\t";
            std::cout << "5.Safe in .CSV file" << "\t" << "6.Leave This Matrix and go to main menu" << "\n";
            std::cout << "Write here your choice:" << "\n\n";
            std::cin >> action;
            std::cout << "\n";
            if (action == 6) break;
            switch (action)
            {
            case 1:
                double multiplier;
                std::cout << "Write multiplier:" << "\n";
                std::cin >> multiplier;
                matrix = matrix * multiplier;
                std::cout << "You successfully multiplied the Matrix" << "\n";
                break;
            case 2:
                std::cout << "Determinant of matrix: " << matrix.det() << "\n";
                break;
            case 3:
                matrix = matrix.getTransposedMatrix();
                std::cout << "Transposed Matrix was found" << "\n";
                break;
            case 4:
                matrix = matrix.getReverseMatrix();
                std::cout << "Reverse Matrix was found" << "\n";
                break;
            case 5:
                string path;
                std::cout << "Write name of File to safe Matrix in format \"xxxx.csv\" : " << matrix.det() << "\n";
                std::cin >> path;
                std::cout << "\n";
                matrix.safeInCSV(path);
                std::cout << "Matrix successfully safed in CSV" << "\n";
                break;
            }
        }
    }
}




int main()
{
    openInterface();
  
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
