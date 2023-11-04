class Solution {
public:
    string convert(string s, int numRows) {
        string retVal;
        if(numRows>1)
        {
            vector<string> rowsVector(numRows);
            rowsVector.reserve(numRows);
            unsigned int maxJump = 2*(numRows-1);

            for(unsigned int i = 0; i <= 1; i++)
            {
                string outerStrings;
                for(unsigned int j = 0; j < s.length(); j++)
                {
                    unsigned int index;
                    index = i*(numRows-1)+j*2*(numRows-1);
                    if(index>=s.length())
                    {
                        break;
                    }
                    outerStrings.push_back(s[index]);
                }
                rowsVector.at(i*(numRows-1))=outerStrings;
            }

            for(unsigned int i = 1; i < (numRows-1); i++)
            {
                string innerStrings;
                unsigned int modReturns0Jump;
                modReturns0Jump = 2*(numRows-1-i);
                unsigned int modReturns1Jump;
                modReturns1Jump = maxJump - modReturns0Jump;
                unsigned int index = i;
                for(unsigned int j = 0; index < s.length(); j++)
                {
                    innerStrings.push_back(s[index]);
                    bool select = j%2;
                    if(select)
                    {
                        index += modReturns1Jump;
                    }
                    else
                    {
                        index += modReturns0Jump;
                    }
                }
                rowsVector.at(i) = innerStrings;
            }

            for(unsigned int vectorIterator = 0; vectorIterator < numRows; vectorIterator++)
            {
                retVal.append(rowsVector[vectorIterator]);
            }
        }
        else if(numRows == 1)
        {
            retVal = s;
        }
        return retVal;
    }
};