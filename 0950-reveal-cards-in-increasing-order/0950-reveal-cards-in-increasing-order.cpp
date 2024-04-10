class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> sortingQueue;
        vector<int> l_deck = deck;
        sort(l_deck.begin(), l_deck.end(), std::greater<int>());
        for(auto& number : l_deck)
        {
            sortingQueue.push(number);
            sortingQueue.push(sortingQueue.front());
            sortingQueue.pop();
        }
        int index = l_deck.size() - 2;
        while(index >= 0)
        {
            l_deck[index--] = sortingQueue.front();
            sortingQueue.pop();
        }
        l_deck[l_deck.size() - 1] = sortingQueue.front();
        return l_deck;
    }
};