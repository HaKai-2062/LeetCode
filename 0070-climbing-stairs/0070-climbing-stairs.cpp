class Solution
{
public:
    uint32_t climbStairs(uint8_t n)
    {
        if (n < 2)
            return n;

        uint32_t beforePrevious = 1;
        uint32_t previous = 2;

        // calculate n-1 and n-2 combos and sum them
        for (uint8_t i = 3; i <= n; i++)
        {
            uint32_t temp = previous;
            previous = beforePrevious + previous;
            beforePrevious = temp;
        }
        return previous;
    }
};