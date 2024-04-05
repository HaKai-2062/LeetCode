class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int maxSum = 0;
        int left = 0;
        std::unordered_map<char, int> hashMap;

        for (int i = 0; i < s.size(); i++)
        {
            if (hashMap.find(s[i]) == hashMap.end() || hashMap[s[i]] < left)
            {
                hashMap[s[i]] = i;
                maxSum = std::max(maxSum, i - left + 1);
            }
            else
            {
                left = hashMap[s[i]] + 1;
                hashMap[s[i]] = i;
            }
        }

        return maxSum;
    }
};