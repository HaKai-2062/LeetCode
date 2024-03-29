#include <unordered_set>

class Solution
{
public:
	bool containsDuplicate(std::vector<int>& nums)
	{
		std::unordered_set<int> hashSet;

		for (int i = 0; i < nums.size(); i++)
		{
			if (hashSet.find(nums[i]) != hashSet.end())
				return true;

			hashSet.insert(nums[i]);
		}

		return false;
	}
};