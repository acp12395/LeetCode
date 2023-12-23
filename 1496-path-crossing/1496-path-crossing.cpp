class Solution {
public:
    bool isPathCrossing(string path) {
        bool crossingPathFlag = false;
        int x = 0;
        int y = 0;
        map<pair<int,int>,int> pointCounterMap;
        pointCounterMap[{0,0}]++;
        for(auto& direction : path)
        {
            if(direction == 'N')
            {
                y++;
            }
            else if(direction == 'S')
            {
                y--;
            }
            else if(direction == 'E')
            {
                x++;
            }
            else
            {
                x--;
            }
            pointCounterMap[{x,y}]++;
        }
        for(auto& point : pointCounterMap)
        {
            if(point.second > 1)
            {
                crossingPathFlag = true;
                break;
            }
        }
        return crossingPathFlag;
    }
};