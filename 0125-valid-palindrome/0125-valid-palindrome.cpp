class Solution
{
public:
    bool isPalindrome(std::string s)
    {
        size_t index = s.size() - 1;

        for (int i = 0; i < s.size(); i++)
        {
            // Skip non alphanumeric elements from start
            if ((s[i] < 'A' || s[i] > 'z') && (s[i] < '0' || s[i] > '9'))
                continue;
            if (s[i] > 'Z' && s[i] < 'a')
                continue;

            // Skip non alphanumeric elements from end
            while (((s[index] < 'A' || s[index] > 'z') && (s[index] < '0' || s[index] > '9')) || s[index] > 'Z' && s[index] < 'a')
                index--;

            // If they cross over then they should be fine
            if (index <= i)
                break;

            // For capitalization from start
            if (s[i] >= 'a' && s[i] <= 'z')
                s[i] -= 32;

            // For capitalization from end
            if (s[index] >= 'a' && s[index] <= 'z')
                s[index] -= 32;

            if (s[i] != s[index])
            {
                return false;
            }
                

            // since i is incremented, index is decremented
            index--;
        }

        return true;
    }
};