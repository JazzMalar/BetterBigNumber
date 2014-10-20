#include "stdafx.h"
#include "TestBigNumber.h"
#include "BigNumber.h"
#include <iostream>

using namespace std;

CTestBigNumber::CTestBigNumber()
{
}


CTestBigNumber::~CTestBigNumber()
{
}

void CTestBigNumber::TestAll()
{
	cout << "Starting Tests for CBigNumber... " << endl;
	TestEquals();
	TestGreaterThan();
	TestSmallerThan();
	TestAddition();
	TestMultiplication();
}

void CTestBigNumber::TestMultiplication()
{
	CBigNumber bn1(1);
	CBigNumber bn2(1);
	CBigNumber bn3(1);

	bool t1 = false;
	bn1 = 2;
	bn2 = 5;
	bn3 = bn1 * bn2;
	if (bn3 == 10) t1 = true;

	bool t2 = false;
	bn1 = 3;
	bn2 = 2;
	bn3 = bn1 * bn2;
	if (bn3 == 6) t2 = true;

	bool t3 = false;
	bn1 = 100;
	bn2 = 10;
	bn3 = bn1 * bn2;
	if (bn3 == 1000) t3 = true;

	bool t4 = false;
	bn1 = 1;
	bn2 = 1;
	bn3 = bn1 * bn2;
	if (bn3 == 1) t4 = true;

	bool t5 = false;
	bn1 = 1;
	bn2 = 0;
	bn3 = bn1 * bn2;
	if (bn3 == 0) t5 = true;

	bool t6 = false;
	bn1 = 6789;
	bn2 = 7899;
	bn3 = bn1 * bn2;
	if (bn3 == (6789 * 7899)) t6 = true;

	if (t1 && t2 && t3 && t4 && t5 && t6)
	{
		cout << "TestMultiplication : Erfolgreich" << endl;
	}
	else
	{
		cout << "TestMultiplication : Fehlgeschlagen" << endl;
	}

}


void CTestBigNumber::TestAddition()
{
	CBigNumber bn1(0);
	CBigNumber bn2(0);
	CBigNumber bn3(0);

	bool t1 = false;
	bn1 = 1234;
	bn2 = 12;
	bn3 = bn1 + bn2;
	if (bn3 == 1246) t1 = true;

	bool t2 = false;
	bn1 = 9;
	bn2 = 2;
	bn3 = bn1 + bn2;
	if (bn3 == 11) t2 = true;

	bool t3 = false;
	bn1 = 9;
	bn2 = 1;
	bn3 = bn1 + bn2;
	if (bn3 == 10) t3 = true;

	bool t4 = false;
	bn1 = 12;
	bn2 = 0;
	bn3 = bn1 + bn2;
	if (bn3 == 12) t4 = true;

	if (t1 && t2 && t3 && t4)
	{
		cout << "TestAddition : Erfolgreich" << endl;
	}
	else
	{
		cout << "TestAddition : Fehlgeschlagen" << endl;
	}

	bn1 = NULL;

}

void CTestBigNumber::TestEquals()
{
	CBigNumber bn1(0);
	CBigNumber bn2(0);

	bool t1 = false;
	bn1 = 12345;
	bn2 = 12345;
	if (bn1 == bn2) t1 = true;

	bool t2 = true;
	bn1 = 10;
	bn2 = 100;
	if (bn1 == bn2) t2 = false;

	bool t3 = true;
	bn1 = 10;
	bn2 = 11;
	if (bn1 == bn2) t3 = false;

	bool t4 = false;
	bn1 = 0;
	if (bn1 == 0) t4 = true;

	if (t1 && t2 && t3 && t4)
	{
		cout << "TestEquals : Erfolgreich" << endl;
	}
	else
	{
		cout << "TestEquals : Fehlgeschlagen" << endl;
	}

}

void CTestBigNumber::TestGreaterThan()
{
	CBigNumber bn1(0);
	CBigNumber bn2(0);

	bool t1 = false;
	bn1 = 123456;
	bn2 = 12345;
	if (bn1 > bn2) t1 = true;

	bool t2 = false;
	bn1 = 12345;
	bn2 = 12344;
	if (bn1 > bn2) t2 = true;

	bool t3 = true;
	bn1 = 9;
	bn2 = 10;
	if (bn1 > bn2) t3 = false;

	bool t4 = false;
	bn1 = 800;
	bn2 = 0;
	if (bn1 > bn2) t4 = true;

	if (t1 && t2 && t3 && t4)
	{
		cout << "TestGreaterThan : Erfolgreich" << endl;
	}
	else
	{
		cout << "TestGreaterThan : Fehlgeschlagen" << endl;
	}
}

void CTestBigNumber::TestSmallerThan()
{
	CBigNumber bn1(0);
	CBigNumber bn2(0);

	bool t1 = false;
	bn1 = 12345;
	bn2 = 123456;
	if (bn1 < bn2) t1 = true;

	bool t2 = false;
	bn1 = 12344;
	bn2 = 12345;
	if (bn1 < bn2) t2 = true;

	bool t3 = true;
	bn1 = 10;
	bn2 = 9;
	if (bn1 < bn2) t3 = false;

	bool t4 = false;
	bn1 = 0;
	bn2 = 880;
	if (bn1 < bn2) t4 = true;

	if (t1 && t2 && t3 && t4)
	{
		cout << "TestSmallerThan : Erfolgreich" << endl;
	}
	else
	{
		cout << "TestSmallerThan : Fehlgeschlagen" << endl;
	}
}