class Solution
{
public:
	int maxProfit(std::vector<int>& prices)
	{
		int buyDay = 0;
		int sellDay = 1;
		int maximumProfit = 0;

		if (prices.size() <= 1)
			return 0;

		for (int i = 0; i < prices.size(); i++)
		{
			// Cant buy on last day
			if (prices[i] < prices[buyDay] && i < prices.size() - 1)
			{
				buyDay = i;
				sellDay = i + 1;
			}
			// Cant sell on previous set sell day or below
			else if (prices[i] > prices[sellDay] && i > sellDay)
			{
				sellDay = i;
			}

			// Check profits
			if (prices[sellDay] > prices[buyDay] && maximumProfit < prices[sellDay] - prices[buyDay])
				maximumProfit = prices[sellDay] - prices[buyDay];
		}

		return maximumProfit;
	}
};