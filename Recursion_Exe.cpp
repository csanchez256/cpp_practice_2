// chris sanchez; this was an exercise that combines std::string, vectors, and recursion 
// I borrowed the idea of integer concatenation from:
// https://social.msdn.microsoft.com/Forums/vstudio/en-US/2152b1bb-fb6b-4863-a7b8-60fcfbe26a95/integer-concatenation?forum=vclanguage

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>


int digitSummation(int n) {

	//convert number to a string
	std::string numberToString = std::to_string(n);
	std::vector<char> stringToVector;

	//base case: if there's only one digit, convert it back, then return the integer
	if (numberToString.length() == 1) {
		return n;
	}

	// load vector with characters in string
	for (int i = 0; i < numberToString.length(); ++i)
		stringToVector.push_back(numberToString[i]);

	// save the first digit
	int firstDigit;
	firstDigit = stringToVector[0] - '0'; // (ascii character) - 48

	// remove first digit
	stringToVector.erase(stringToVector.begin());

	// convert the rest of the string to an integer
	// The syntax is <var> << 1 << 2 << 3 << 4
	std::ostringstream concat;

	for (int i = 0; i < stringToVector.size(); ++i)
		concat << stringToVector[i] - '0';

	std::stringstream concatString(concat.str());

	int convertBackToInt;
	concatString >> convertBackToInt;

	//add the digit with recursive call of function
	return firstDigit + digitSummation(convertBackToInt);
}

int main()
{
	std::cout << "Enter a number " << '\n';
	int input;
	std::cin >> input;
	std::cout << "Summation: " << digitSummation(input) << '\n';
	return 0;
}