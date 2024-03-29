class Solution
{
public:
	bool isValid(std::string s)
	{
		if (s.size() <= 1)
			return false;

		std::vector<char> stack;
		std::unordered_map<int, int> closeParanthesis{ 
			{ '}', '{'},
			{ ')', '('},
			{ ']' , '['}};

		for (int i = 0; i < s.size(); i++)
		{
			// Close paranthesis
			if (closeParanthesis.find(s[i]) != closeParanthesis.end())
			{
				// Pop the last open parantheses from the stack
				if (stack.size() && stack[stack.size() - 1] == closeParanthesis[s[i]])
				{
					stack.pop_back();
				}
				else
				{
					return false;
				}
			}
			// Open paranthesis
			else
			{
				stack.push_back(s[i]);
			}
		}
		if (stack.size())
			return false;

		return true;
	}
};