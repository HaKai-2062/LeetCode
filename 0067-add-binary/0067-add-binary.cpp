#include <vector>

class Solution {
public:
	std::string addBinary(std::string a, std::string b) 
	{
		//make strings of samne size
		while (a.size() != b.size())
		{
			if (a.size() > b.size())
				b = '0' + b;
			else
				a = '0' + a;
		}

		bool carry = false;
		
		for (int i = a.size() - 1; i >= 0; i--)
		{
			if ((a[i] == '1' && b[i] == '0' && !carry) || (a[i] == '0' && b[i] == '1' && !carry))
				a[i] = '1';
			else if (a[i] == '0' && b[i] == '0' && !carry)
				a[i] = '0';
			else if (a[i] == '1' && b[i] == '1' && !carry)
			{
				a[i] = '0';
				carry = true;
			}
			else if ((a[i] == '1' && b[i] == '0' && carry) || (a[i] == '0' && b[i] == '1' && carry))
			{
				a[i] = '0';
				carry = true;
			}
			else if (a[i] == '0' && b[i] == '0' && carry)
			{
				a[i] = '1';
				carry = false;
			}
			else if (a[i] == '1' && b[i] == '1' && carry)
			{
				a[i] = '1';
				carry = true;
			}
		}
		if (carry)
			a = '1' + a;
		return a;
	}
};