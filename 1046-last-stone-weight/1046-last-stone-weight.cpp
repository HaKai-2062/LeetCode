class Solution
{
public:
	int lastStoneWeight(std::vector<int>& stones)
	{
		int totalStones = stones.size();
		std::make_heap(stones.begin(), stones.end());
		int difference = 0;
	
		while (totalStones > 1)
		{
			std::pop_heap(stones.begin(), stones.end());
			int value1 = stones.back();
			stones.pop_back();
			
			std::pop_heap(stones.begin(), stones.end());
			int value2 = stones.back();
			stones.pop_back();

			int value = std::abs(value1 - value2);
			totalStones -= 2;
		
			if (value != 0)
			{
				stones.push_back(value);
				std::push_heap(stones.begin(), stones.end());
				totalStones++;
			}
		}
	
		if (stones.size() == 0)
			return 0;

		return stones[0];
	}
};