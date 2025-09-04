class Solution {
public:
    int findClosest(int x, int y, int z) {
        int diffXZ = abs(x - z);
        int diffYZ = abs(y - z);
        return diffXZ < diffYZ ? 1 : diffXZ == diffYZ ? 0 : 2;
    }
};