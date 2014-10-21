#include "stdafx.h"
#include "BigNumber.h"


// CBigNumber::CBigNumber() : CBigNumber(0) { }

CBigNumber::CBigNumber(int number)
{

	// pointer to the current position in the digit array
	unsigned int *pDigit = m_digits; 

	if (number < 0)
	{
		m_positive = false;
		number *= -1;
	}

	unsigned int digitsToConsider = 0;
	if (number > 0)
	{
		for (int i = 0; i < DIGITCOUNT; i++)
		{

			if (number > 0)
			{
				*pDigit = number % m_base;
				number /= m_base;

				digitsToConsider++;
			}

			pDigit++;
		}
	}

	m_validDigits = digitsToConsider;

}

CBigNumber::CBigNumber(char* arr)
{

	int j = 0;

	int arrayLength = strlen(arr);

	switch (*arr)
	{
	case '-':
		m_positive = false;
		j = 1;
		break;
	case '+':
		j = 1;
		break;
	}

	// if the input is too long or too short, just use the 
	// significant numbers.
	// also, if the first symbol was a '-' or a '+' take a number 
	// more into account (we don't want to loose accuracy for the
	// plus / minus sign).
	char* endOfArray;
	if (arrayLength >= (DIGITCOUNT + j))
	{
		endOfArray = arr + (DIGITCOUNT + j) - 1;
		m_validDigits = DIGITCOUNT;
	}
	else
	{
		endOfArray = arr + arrayLength - 1;
		m_validDigits = arrayLength - j;
	}

	for (int i = DIGITCOUNT - 1; i >= 0; i--)
	{
		// if the number is shorter than allowed digits
		// fill the rest with zeroes.
		if (i >= arrayLength - j)
		{
			m_digits[i] = 0;
		}
		else
		{
			m_digits[i] = (*endOfArray) - 48;
			endOfArray--;
		}
	}

	// DEBUG
	/*
	for (int k = 0; k < DIGITCOUNT; k++)
	{
	cout << m_digits[k] << endl;
	}
	*/
}
CBigNumber& CBigNumber::operator-=(const CBigNumber& rop)
{
	// ToDo :  implement
	return *this;
}

CBigNumber& CBigNumber::operator*=(const CBigNumber& rop)
{

	return *this;

}

CBigNumber CBigNumber::operator*(const CBigNumber& rop) const
{

	CBigNumber result(0);
	CBigNumber finalResult(0); 

	const unsigned int *pDigitLop = this->m_digits; 
	const unsigned int *pDigitRop = rop.m_digits; 

	unsigned int *pDigitResult = result.m_digits; 
	unsigned int iDigitsLop = this->m_validDigits;
	unsigned int iDigitsRop = rop.m_validDigits; 
	unsigned int base = rop.m_base; 

	for (unsigned int i = 0; i < iDigitsLop; i++)
	{
		result.m_validDigits = 0; 
		unsigned int carry = 0;

		// as we loop through the digits of the left operator (loop above), 
		// we need to keep in mind, that for every turn, the base of the result
		// increases by (base). So we move the pointer for every turn one position.
		// while doing so, we initialize the value in the result and increase the
		// valid digit count
		for (unsigned int j = 0; j < i; j++)
		{
			*pDigitResult = 0; 
			pDigitResult++; 
			result.m_validDigits++; 
		}

		// while (iDigitsRop-- > 0)
		for (unsigned int j = 0; j < iDigitsRop; j++)
		{
			unsigned int digit = 0; 
			
			digit = *pDigitLop * *pDigitRop + carry;
			*pDigitResult = digit % base; 
			carry = digit / base; 

			result.m_validDigits++; 

			pDigitRop++; 
			pDigitResult++; 
		}

		if (carry > 0) 
		{
			*pDigitResult = carry; 
			result.m_validDigits++; 
		}

		if (finalResult.m_validDigits == 0)
		{
			finalResult = result; 
		}
		else 
		{
			finalResult = finalResult + result; 
		}

		pDigitLop++; 

		pDigitRop = rop.m_digits; 
		pDigitResult = result.m_digits; 
	}

	return finalResult; 

}

CBigNumber CBigNumber::operator+(const CBigNumber& rop) const
{
	CBigNumber result(0);

	const unsigned int *pDigitLop = this->m_digits;
	const unsigned int *pDigitRop = rop.m_digits;

	unsigned int *pDigitResult = result.m_digits;
	unsigned int iDigitsLop = this->m_validDigits;
	unsigned int iDigitsRop = rop.m_validDigits;
	unsigned int base = rop.m_base;
	unsigned int carry = 0; 
	unsigned int digitsToConsider = 0;
	unsigned int digitsTreshold = 0; 

	if (this->m_validDigits > rop.m_validDigits)
	{
		digitsToConsider = this->m_validDigits;
	}
	else
	{
		digitsToConsider = rop.m_validDigits;
	}

	for (unsigned int i = 0; i < digitsToConsider; i++)
	{
		int digit;

		if (i >= rop.m_validDigits)
		{
			digit = *pDigitLop + carry;
			result.m_validDigits++; 
		}
		else if (i >= this->m_validDigits)
		{
			digit = *pDigitRop + carry;
			result.m_validDigits++;
		}
		else
		{
			digit = *pDigitLop + *pDigitRop + carry;
			result.m_validDigits++;
		}

		*pDigitResult = digit % base;
		carry = digit / base;

		pDigitResult++;
		pDigitLop++;
		pDigitRop++;

	}

	if (carry > 0)
	{
		*pDigitResult = carry; 
		result.m_validDigits++;
	}

	return result;
}

CBigNumber& CBigNumber::operator+=(const CBigNumber& rop)
{
	
	return *this + rop; 

}

bool CBigNumber::operator<(const CBigNumber& rop) const
{
	bool result = false;

	if (this->m_validDigits > rop.m_validDigits)
	{
		result = false;
	}
	else if (this->m_validDigits < rop.m_validDigits)
	{
		result = true;
	}
	else
	{
		const unsigned int* pDigitLop = m_digits + m_validDigits - 1;
		const unsigned int* pDigitRop = rop.m_digits + rop.m_validDigits - 1;

		for (int i = this->m_validDigits - 1; i >= 0; i--)
		{
			if (*pDigitLop > *pDigitRop)
			{
				result = false;
			}
			else if (*pDigitLop < *pDigitRop)
			{
				result = true;
			}
			else
			{
				result = false;
			}

			pDigitLop--;
			pDigitRop--;
		}
	}

	return result;
}

bool CBigNumber::operator>(const CBigNumber& rop) const
{

	bool result = false;

	if (this->m_validDigits > rop.m_validDigits)
	{
		result = true;
	}
	else if (this->m_validDigits < rop.m_validDigits)
	{
		result = false;
	}
	else
	{
		const unsigned int* pDigitLop = m_digits + m_validDigits - 1;
		const unsigned int* pDigitRop = rop.m_digits + rop.m_validDigits - 1;

		for (int i = this->m_validDigits - 1; i >= 0; i--)
		{
			if (*pDigitLop > *pDigitRop)
			{
				result = true;
			}
			else if (*pDigitLop < *pDigitRop)
			{
				result = false;
			}
			else
			{
				result = false;
			}

			pDigitLop--;
			pDigitRop--;

		}
	}

	return result;
}

bool CBigNumber::operator==(const CBigNumber& rop) const
{
	bool result = true;

	if ((*this > rop) || (*this < rop))
	{
		result = false;
	}

	return result;
}

istream& operator>>(std::istream& lop, CBigNumber& rop)
{
	// STRING VERSION
	// DOES NOT WORK! I'd like to call the char* constructor
	// with the string, but that does not work.. hmm..
	/*
	string inputData;
	lop >> inputData;

	rop = CBigNumber(inputData);

	return lop;
	*/

	// CHAR ARRAY VERSION 
	char* inputData = new char[CBigNumber::DIGITCOUNT + 1];

	std::cout << "Grosse Zahl eingeben :" << endl;
	lop >> inputData;

	rop = CBigNumber(inputData);

	return lop;
}

ostream& operator<<(std::ostream& lop, const CBigNumber& rop)
{
	std::string out;

	if (rop.m_positive)
	{
		out += "+";
	}
	else
	{
		out += "-";
	}

	for (int i = 0; i < CBigNumber::DIGITCOUNT; i++)
	{
		out = out + std::to_string(rop.m_digits[i]);
	}


	lop << out << endl;

	return lop;
}

CBigNumber::~CBigNumber()
{
}
