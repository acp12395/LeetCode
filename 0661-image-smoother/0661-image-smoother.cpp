class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> retImage(img.size(),vector<int>(img[0].size(),int()));
        for(int row = 0; row < img.size(); row++)
        {
            for(int column = 0; column < img[0].size(); column++)
            {
                int sum = 0;
                int addedElementCounter = 0;
                if(row != 0)
                {
                    if(column != 0)
                    {
                        sum += img[row - 1][column - 1];
                        addedElementCounter++;
                    }
                    sum += img[row - 1][column];
                    addedElementCounter++;
                    if(column != (img[0].size() - 1))
                    {
                        sum += img[row - 1][column + 1];
                        addedElementCounter++;
                    }
                }
                if(column != 0)
                {
                    sum += img[row][column - 1];
                    addedElementCounter++;
                }
                sum += img[row][column];
                addedElementCounter++;
                if(column != (img[0].size() - 1))
                {
                    sum += img[row][column + 1];
                    addedElementCounter++;
                }
                if(row != (img.size() - 1))
                {
                    if(column != 0)
                    {
                        sum += img[row + 1][column - 1];
                        addedElementCounter++;
                    }
                    sum += img[row + 1][column];
                    addedElementCounter++;
                    if(column != (img[0].size() - 1))
                    {
                        sum += img[row + 1][column + 1];
                        addedElementCounter++;
                    }
                }
                retImage[row][column] = sum/addedElementCounter;
            }
        }
        return retImage;
    }
};