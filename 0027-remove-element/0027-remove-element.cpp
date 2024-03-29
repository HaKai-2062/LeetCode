#include <vector>

class Solution
{
public:
    int removeElement(std::vector<int>& nums, int val)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val)
            {
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            std::cout << nums[i] << " ";
        }
        std::cout << std::endl;
        return nums.size();
    }
};