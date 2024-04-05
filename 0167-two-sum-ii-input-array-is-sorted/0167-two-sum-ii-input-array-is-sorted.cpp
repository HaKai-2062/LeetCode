class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target)
    {
        std::vector<int> result;
        result.reserve(3);
        int upperBound = numbers.size() - 1;
 

        for (int i = 0; i < numbers.size(); i++)
        {
            int left = numbers[i];
            int difference = target - left;
            
            int lowerBound = i + 1;
            int search = binarySearch(numbers, difference, lowerBound, upperBound);

            if (search != -1)
            {
                result.push_back(i + 1);
                result.push_back(search + 1);
                break;
            }
        }

        return result;
    }
    
    int binarySearch(std::vector<int>& numbers, int target, int lowerBound, int& upperBound)
    {
        int left = lowerBound;
        int right = upperBound;

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
                upperBound = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return -1;
    }
};