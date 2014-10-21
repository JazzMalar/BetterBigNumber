// BetterBigNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BigNumber.h"
#include "TestBigNumber.h"
#include <iostream>
#include <ctime>


CBigNumber fact(int factorial)
{
	// CBigNumber tmp(1);
	CBigNumber result(1); 
	CBigNumber factor(1);

	result = factor * result; 

	for (int i = 2; i <= factorial; i++)
	{
		factor = i; 

		result = factor * result;

	}

	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{

	// TEST FRAMEWORK
	CTestBigNumber test;
	test.TestAll(); 
	//test.TestMultiplication();

	/*

	CBigNumber bnC(0);
	cout << "Benoetigte Zeit um 1000! zu berechnen = ";
	long starttime = clock(); //Startzeit

	//Zur Zeitmessung sind mehrere Durchläufe geeigneter
	int loops = 10;
	for (int i = 0; i < loops; i++)
	{
		bnC = fact(1000);
	}

	long endtime = clock(); //Endzeit

	cout << ((double)(endtime - starttime) / ((double)CLOCKS_PER_SEC / 1000)) / loops << "ms" << endl; //Gemittelte Zeit ausgeben

	*/

	return 0;
}