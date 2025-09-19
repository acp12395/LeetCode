class Spreadsheet {
private:
    vector<vector<int>>* sheet;
    int getVal(string str)
    {
        if(str[0] >= '0' && str[0] <= '9')
        {
            return stoi(str);
        }
        else
        {
            int letterIndex = static_cast<int>(str[0] - 'A');
            int row = stoi(str.substr(1)) - 1;
            return (*sheet)[row][letterIndex];
        }
    }
public:
    Spreadsheet(int rows) {
        vector<vector<int>>* sheetInitializer = new vector<vector<int>>(rows, vector<int>(26, 0));
        sheet = sheetInitializer;
    }

    ~Spreadsheet()
    {
        delete sheet;
        sheet = nullptr;
    }
    
    void setCell(string cell, int value) {
        int letterIndex = static_cast<int>(cell[0] - 'A');
        int row = stoi(cell.substr(1)) - 1;
        (*sheet)[row][letterIndex] = value;
    }
    
    void resetCell(string cell) {
        int letterIndex = static_cast<int>(cell[0] - 'A');
        int row = stoi(cell.substr(1)) - 1;
        (*sheet)[row][letterIndex] = 0;
    }
    
    int getValue(string formula) {
        int plusIndex = formula.find("+");
        string val1 = formula.substr(1, plusIndex - 1);
        string val2 = formula.substr(plusIndex + 1);
        return getVal(val1) + getVal(val2);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */