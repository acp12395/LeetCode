class Solution {
private:
    enum class ordering{SPACE, SIGN, ZEROS, NUMBERS, ELSE};
public:
    int myAtoi(string s) {
        long retValStorage = 0;
        int retVal = 0;
        bool sign = false;
        ordering order = ordering::SPACE;
        
        for(auto& i : s)
        {
            if(order != ordering::ELSE)
            {
                switch(order)
                {
                    case ordering::SPACE:
                    {
                        if(i == ' ')
                        {

                        }
                        else if(i == '-')
                        {
                            order = ordering::SIGN;
                            sign = true;
                        }
                        else if(i == '+')
                        {
                            order = ordering::SIGN;
                        }
                        else if(i == '0')
                        {
                            order = ordering::ZEROS;
                        }
                        else if(i >= '1' && i <= '9')
                        {
                            order = ordering::NUMBERS;
                            retValStorage *= 10;
                            retValStorage += static_cast<long>(i-'0');
                        }
                        else
                        {
                            order = ordering::ELSE;
                        }
                        break;
                    }
                    case ordering::SIGN:
                    {
                        if(i == '0')
                        {
                            order = ordering::ZEROS;
                        }
                        else if(i >= '1' && i <= '9')
                        {
                            order = ordering::NUMBERS;
                            retValStorage *= 10;
                            retValStorage += static_cast<long>(i-'0');
                        }
                        else
                        {
                            order = ordering::ELSE;
                        }
                        break;
                    }
                    case ordering::ZEROS:
                    {
                        if(i == '0')
                        {
                            
                        }
                        else if(i >= '1' && i <= '9')
                        {
                            order = ordering::NUMBERS;
                            retValStorage *= 10;
                            retValStorage += static_cast<long>(i-'0');
                        }
                        else
                        {
                            order = ordering::ELSE;
                        }
                        break;
                    }
                    case ordering::NUMBERS:
                    {
                        if(i >= '0' && i <= '9')
                        {
                            order = ordering::NUMBERS;
                            retValStorage *= 10;
                            retValStorage += static_cast<long>(i-'0');
                            if(sign && retValStorage >= 2147483648)
                            {
                                retValStorage = 2147483648;
                                order = ordering::ELSE;
                            }
                            else if(!sign && retValStorage >= 2147483647)
                            {
                                retValStorage = 2147483647;
                                order = ordering::ELSE;
                            }
                        }
                        else
                        {
                            order = ordering::ELSE;
                        }
                        break;
                    }
                }
            }
            else
            {
                break;
            }
        }
        if(sign)
        {
            retValStorage *= -1;
        }
        retVal = static_cast<int>(retValStorage);
        return retVal;
    }
};