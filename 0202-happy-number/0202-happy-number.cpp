#include <iostream>
#include <unordered_map>

class Solution
{
public:
	bool isHappy(int n)
	{
		std::unordered_map<int, int> hashMap;

		while (hashMap.find(n) == hashMap.end())
		{
			int temp = n;
			int temp2 = 0;

			while (temp != 0)
			{
				temp2 += (temp % 10) * (temp % 10);
				temp /= 10;
			}

			hashMap.insert({ n, n });
			n = temp2;
		}

		if (n == 1)
			return true;
		
		return false;
	}
};