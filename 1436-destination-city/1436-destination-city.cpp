class Solution {
private:
    enum class originOrDestination
    {
        NONE,
        ORIGIN,
        DESTINATION,
        BOTH
    };
    originOrDestination assignOriginOrDestination(originOrDestination previouslyFoundAt, originOrDestination nowFoundAt)
    {
        originOrDestination retVal;
        switch(previouslyFoundAt)
        {
            case originOrDestination::NONE:
            {
                retVal = nowFoundAt;
                break;
            }
            default:
            {
                retVal = originOrDestination::BOTH;
                break;
            }
        }
        return retVal;
    }
public:
    string destCity(vector<vector<string>>& paths) {
        string retString;
        unordered_map<string, originOrDestination> storageMap;
        for(auto& cities: paths)
        {
            storageMap[cities[0]] = assignOriginOrDestination(storageMap[cities[0]], originOrDestination::ORIGIN);
            storageMap[cities[1]] = assignOriginOrDestination(storageMap[cities[1]], originOrDestination::DESTINATION);
        }
        for(auto&& uniqueDestinationFinder : storageMap)
        {
            if(uniqueDestinationFinder.second == originOrDestination::DESTINATION)
            {
                retString = uniqueDestinationFinder.first;
                break;
            }
        }
        return retString;
    }
};