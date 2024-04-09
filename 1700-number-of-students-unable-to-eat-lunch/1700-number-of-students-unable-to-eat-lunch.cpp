class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int i = 0, j = 0;
        int jLimit;
        while(i < sandwiches.size())
        {
            jLimit = students.size() - j;
            bool sandwichTaken = false;
            while(jLimit > 0)
            {
                if(sandwiches[i] == students[j])
                {
                    i++;
                    j++;
                    sandwichTaken = true;
                    break;
                }
                else
                {
                    students.push_back(students[j]);
                    j++;
                }
                jLimit--;
            }
            if(!sandwichTaken)
            {
                break;
            }
        }
        return students.size() - j;
    }
};