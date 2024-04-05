class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int maxSum = 0;
        int left = 0;
        std::unordered_set<int> hashSet;

        for (int i = 0; i < s.size(); i++)
        { 
            while (hashSet.find(s[i]) != hashSet.end())
            {
                hashSet.erase(s[left]);
                left++;
            }

            hashSet.insert(s[i]);
            if (hashSet.size() > maxSum)
                maxSum = hashSet.size();
        }

        return maxSum;
    }
};