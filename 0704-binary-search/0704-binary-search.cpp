class Solution
{
public:
	int search(std::vector<int>& nums, int target)
	{
		if (nums.size() == 0 || (nums.size() == 1 && nums[0] != target))
			return -1;

		int low = 0, high = nums.size()-1;
		while (low <= high)
		{
			int mid = static_cast<int>(floor(low + (high - low) / 2));
 
			if (target == nums[mid])
				return mid;

			if (target < nums[mid])
				high = mid - 1;
			else if (target > nums[mid])
				low = mid + 1;
		}
		return -1; 
	}
};