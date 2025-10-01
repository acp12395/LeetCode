class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int retVal = numBottles;
        int emptyBottles = numBottles;
        while(emptyBottles >= numExchange)
        {
            int exchangedBottles = emptyBottles / numExchange;
            retVal += exchangedBottles;
            emptyBottles = exchangedBottles + emptyBottles % numExchange;
        }
        return retVal;
    }
};