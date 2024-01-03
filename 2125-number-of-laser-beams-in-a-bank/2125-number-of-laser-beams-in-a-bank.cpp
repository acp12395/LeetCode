class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int beamsCount = 0;
        int floorDevices;
        int lastFindingDevNo = 0;
        string::size_type deviceFinderIndex;
        for(auto& floor : bank)
        {
            deviceFinderIndex = -1;
            floorDevices = -1;
            do
            {
                floorDevices++;
                deviceFinderIndex++;
                deviceFinderIndex = floor.find('1',deviceFinderIndex);
            } while (deviceFinderIndex != string::npos);
            if(floorDevices > 0)
            {
                beamsCount += (lastFindingDevNo * floorDevices);
                lastFindingDevNo = floorDevices;
            }
        }
        return beamsCount;
    }
};