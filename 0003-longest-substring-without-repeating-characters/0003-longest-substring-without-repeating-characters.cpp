class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int maxSum = 0;
        
        for (int i = 0; i < s.size(); i++)
        {
            int sum = 0;
            int left = i;

            std::unordered_set<int> hashSet;

            while (left < s.size() && hashSet.find(s[left]) == hashSet.end())
            {
                hashSet.insert(s[left]);
                sum++;
                left++;
            }

            if (sum > maxSum)
                maxSum = sum;
        }
        return maxSum;
    }
};