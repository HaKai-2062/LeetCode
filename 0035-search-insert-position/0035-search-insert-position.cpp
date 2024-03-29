#include <vector>

class Solution
{
public:
    int searchInsert(std::vector<int>& nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (target < nums[i])
                return 0;
            else if (target == nums[i])
                return i;
            else if (i + 1 < nums.size() && target > nums[i] && target < nums[i + 1])
                return i + 1;
        }
        //if it is bigger then always return the last element
        return nums.size();
    }
};