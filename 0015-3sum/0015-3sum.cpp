class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> solutionSet;

        for (int i = 0; i < nums.size()-2; i++)
        {
            // Number was checked
            if (i > 0 && nums[i - 1] == nums[i])
            {
                continue;
            }

            int left = i + 1;
            // once right most is discovered we dont need to go to check right most?
            int right = nums.size()-1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0)
                {
                    solutionSet.push_back({nums[i], nums[left], nums[right]});
                    left += 1;
                    while (nums[left] == nums[left - 1] && left < right)
                    {
                        left += 1;
                    }
                }
                else if (sum < 0)
                {
                    left += 1;
                }
                else if (sum > 0)
                {
                    right -= 1;
                }
            }
        }
        return solutionSet;
    }
};