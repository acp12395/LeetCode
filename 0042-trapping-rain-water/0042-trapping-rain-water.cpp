class Solution {
public:
    int trap(vector<int>& height) {
        int leftIndex = -1, rightIndex = height.size();
        int heightSizeMinus1 = height.size() - 1;
        bool waterPoured = false;
        int waterCount = 0;
        int waterGroupLeft = 0, waterGroupRight = 0;
        stack<int> peakStackLeft, peakStackRight;
        while(!(leftIndex >= rightIndex && waterPoured == true && peakStackLeft.top() == peakStackRight.top()) && (rightIndex > 0 && leftIndex < heightSizeMinus1))
        {
            leftIndex++;
            rightIndex--;
            waterPoured = false;
            if(peakStackLeft.empty())
            {
                if(height[leftIndex] > 0)
                {
                    peakStackLeft.push(height[leftIndex]);
                }
            }
            else if(height[leftIndex] < peakStackLeft.top())
            {
                waterGroupLeft += peakStackLeft.top() - height[leftIndex];
            }
            else
            {
                if(height[leftIndex] > peakStackLeft.top())
                {
                    peakStackLeft.push(height[leftIndex]);
                }
                waterCount += waterGroupLeft;
                waterGroupLeft = 0;
                waterPoured = true;
            }
            if(peakStackRight.empty())
            {
                if(height[rightIndex] > 0)
                {
                    peakStackRight.push(height[rightIndex]);
                }
            }
            else if(height[rightIndex] < peakStackRight.top())
            {
                waterGroupRight += peakStackRight.top() - height[rightIndex];
            }
            else
            {
                if(height[rightIndex] > peakStackRight.top())
                {
                    peakStackRight.push(height[rightIndex]);
                }
                if(!(waterPoured && leftIndex > rightIndex))
                {
                    waterCount += waterGroupRight;
                    waterGroupRight = 0;
                    waterPoured = true;
                }
            }
        }
        return waterCount;
    }
};