class Solution
{
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
    {
        std::unordered_map<std::string, std::vector<std::string>> hashMap;

        for (int i = 0; i < strs.size(); i++)
        {
            std::string oldWord = strs[i];
            std::sort(strs[i].begin(), strs[i].end());
            hashMap[strs[i]].push_back(oldWord);
        }

        std::vector<std::vector<std::string>> result;
        for (auto& keys : hashMap)
        {
            result.push_back(keys.second);
        }
        
        return result;
    }
};