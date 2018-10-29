/*
Programmname: Vector
Version: 1.0
Date: 28.10.2018
Name: Groﬂ Philipp, Pfleghaar Patrick
*/


#include "MyVector.h"
#include <iostream>

// this is only our Programm for testing the vector
int main()
{
	MyVector<int> numberVec;
	int a = 1;
	int b = 2;
	int c = 3;
	numberVec.push_back(1);
	numberVec.push_back(2);
	numberVec.push_back(3);

	for (size_t i = 0; i < numberVec.size(); i++)
	{
		std::cout << numberVec.at(i) ;
		
	}
	numberVec.pop_back();
	numberVec.push_back(4);

	for (size_t i = 0; i < numberVec.size(); i++)
	{
		std::cout << numberVec.at(i) ;

	}
	size_t pos;
	std::cin >> pos;
	try {
		std::cout << numberVec.at(pos);
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}
	system("pause");
};