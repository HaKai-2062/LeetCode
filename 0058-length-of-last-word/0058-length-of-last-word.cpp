class Solution {
public:
	int lengthOfLastWord(std::string s)
	{
		int lastWordLen = 0;
		for (int i = s.size() - 1; i >= 0; i--)
		{
			if (s[i] != ' ')
				lastWordLen++;
			if (s[i] == ' ')
				if (lastWordLen > 0)
					break;
		}
		return lastWordLen;
	}
};