class Solution {
public:
    int divide(int dividend, int divisor) {
        int quotient = 0;
        constexpr int minLim = -2147483648;
        constexpr long absMinLim = 2147483648;
        unsigned int absDivisor = abs(divisor);
        unsigned int partialAbsDividend = 0;
        bool dividendSign, divisorSign, quotientSign;
        bool isDividendMinLim = (dividend == minLim);
        int localDividendCopy = dividend;    // Needed for internal manipulation

        divisorSign = (divisor<0);

        for(int bitIndex = 31; bitIndex >= 0; bitIndex--)
        {
            if(bitIndex == 31)
            {
                dividendSign = (localDividendCopy>>bitIndex)&1;
                quotientSign = dividendSign^divisorSign;
                if(isDividendMinLim)
                {
                    partialAbsDividend = 1;
                    quotient = quotientSign;
                }
                else
                {
                    quotient = quotientSign;
                }
                if(dividendSign == true && (!isDividendMinLim))
                {
                    localDividendCopy-=1;
                }
                else
                {}
            }
            else
            {
                bool bit;
                bit = (localDividendCopy>>bitIndex)&1;
                if(dividendSign == true && (!isDividendMinLim))
                {
                    bit = !bit;
                }
                partialAbsDividend = (partialAbsDividend<<1)|bit;
                if(partialAbsDividend<absDivisor)
                {
                    if(quotientSign == false)
                    {
                        quotient = quotient<<1;
                    }
                    else
                    {
                        quotient = (quotient<<1)|1;
                    }
                }
                else
                {
                    if(quotientSign == false)
                    {
                        quotient = (quotient<<1)|1;
                    }
                    else
                    {
                        quotient = quotient<<1;
                    }
                    partialAbsDividend = partialAbsDividend-absDivisor;
                }
            }
        }
        if((quotientSign == true && (quotient!=minLim)) || (quotient == minLim && (abs(dividend) == (absMinLim-1))))
        {
            quotient+=1;
        }

        return quotient;
    }
};