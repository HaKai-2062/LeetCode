#include <vector>

class Solution
{
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == nums.size()-1)
                break;

            while (nums[i] == nums[i + 1])
            {
                nums.erase(nums.begin() + (i+1));
                if (i + 1 == nums.size())
                {
                    break;
                }
            }
        }
        return nums.size();
    }
};