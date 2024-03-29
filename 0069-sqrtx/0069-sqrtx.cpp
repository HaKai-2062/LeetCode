class Solution
{
public:
    int mySqrt(int x)
    {
        int left = 0, right = 0, result = 0;
        right = x;

        long mid = 0;

        while (left <= right)
        {
            mid = left + (right - left) / 2;

            long long squareOfMid = (mid * mid);

            if (squareOfMid > x)
            {
                right = mid - 1;
            }
            else if (squareOfMid < x)
            {
                left = mid + 1;
                result = mid;
            }
            else
            {
                return mid;
            }
        }

        return result;
    }
};