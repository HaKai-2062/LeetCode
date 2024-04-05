class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int maxSum = 0;
        std::string temp;
        for (int i = 0; i < s.size(); i++)
        {
            int duplicateAt = -1;
            
            // This loop is to truncate the temp string 
            int j;
            for (j = 0; j < temp.size(); j++)
            {
                if (temp[j] == s[i])
                {
                    duplicateAt = j;
                    break;
                }
            }

            temp.insert(temp.end(), s[i]);
            // shrink string to j+1
            if (duplicateAt != -1)
            {
                temp = temp.substr(j + 1, temp.size());
            }

            if (temp.size() > maxSum)
                maxSum = temp.size();
        }
        return maxSum;
    }
};