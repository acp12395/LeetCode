class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int kTickets = tickets[k];
        int requiredTime = 0;
        for(int index = 0; index < tickets.size(); index++)
        {
            if(tickets[index] <= kTickets)
            {
                requiredTime += tickets[index];
            }
            else
            {
                requiredTime += kTickets;
            }
            if(index == k)
            {
                kTickets--;
            }
        }
        return requiredTime;
    }
};