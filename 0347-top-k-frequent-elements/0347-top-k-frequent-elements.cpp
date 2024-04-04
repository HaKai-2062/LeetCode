class Solution
{
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k)
    {
        std::unordered_map<int, int> hashMap;

        // index = count, value = my val
        // k+1 size
        std::vector<std::vector<int>> frequency(nums.size() + 1);

        for (auto& num : nums)
        {
            if (hashMap.find(num) != hashMap.end())
                hashMap[num] += 1;
            else
                hashMap[num] = 0;
        }

        for (std::pair<const int, int>& Entry : hashMap)
        {
            frequency[Entry.second].push_back(Entry.first);
        }

        // iterate from right to left and append until k
        std::vector<int> result;
        for (int i = nums.size(); i >= 0; i--)
        {
            if (result.size() >= k)
                break;

            if (!frequency[i].empty())
                result.insert(result.end(), frequency[i].begin(), frequency[i].end());
        }

        return result;
    }
};