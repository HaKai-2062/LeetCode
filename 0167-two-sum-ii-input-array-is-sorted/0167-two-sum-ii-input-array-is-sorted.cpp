class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target)
    {
        std::vector<int> result;
        result.reserve(3);

        for (int i = 0; i < numbers.size(); i++)
        {
            int left = numbers[i];
            int difference = target - left;
            int search = binarySearch(numbers, difference, i+1);

            if (search != -1)
            {
                result.push_back(i + 1);
                result.push_back(search + 1);
            }
        }

        return result;
    }
    
    int binarySearch(std::vector<int>& numbers, int target, int lowerBound)
    {
        int left = lowerBound;
        int right = numbers.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (numbers[mid] == target)
            {
                return mid;
            }
            
            if (target < numbers[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return -1;
    }
};