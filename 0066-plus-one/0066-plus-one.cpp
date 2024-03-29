#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits)
	{
		//increment last num
		if (digits[digits.size() - 1] != 9)
			digits[digits.size() - 1]++;
		else
		{
			//if last num is 9
			for (int i = digits.size() - 1; i >= 0 && digits[i] == 9; i--)
			{
				digits[i] = 0;
				if (i - 1 >= 0)
				{
					if (digits[i - 1] != 9)
					{
						digits[i - 1]++;
						//since we set the previous num we skip one step
						i--;
						//we break because a middle number has been incremented so we dont need to increment any further
						break;
					}
				}
				//if it is the first element then add 1
				else
				{
					digits.insert(digits.begin(), 1);
				}
			}
		}

		return digits;
    }
};
