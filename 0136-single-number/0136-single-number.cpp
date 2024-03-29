#include <iostream>
#include <vector>

class Solution
{
public:
	int singleNumber(std::vector<int> digits)
	{
		int myDigit = digits[0];
		
		for (int i = 1; i < digits.size(); i++)
		{
			myDigit = myDigit ^ digits[i];
		}

		return myDigit;
	}
};