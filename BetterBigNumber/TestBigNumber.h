#pragma once

#ifndef __TESTBIGNUMBER__H
#define __TESTBIGNUMBER__H

class CTestBigNumber
{
public:
	CTestBigNumber();
	~CTestBigNumber();

	void TestAll();
	void TestAddition();
	void TestMultiplication();
	void TestGreaterThan();
	void TestSmallerThan();
	void TestEquals();

};

#endif