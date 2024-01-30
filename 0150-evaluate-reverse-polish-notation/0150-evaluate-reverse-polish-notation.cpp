class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> container;
        for(auto& token : tokens)
        {
            if(token == "+")
            {
                int secondOperand = container.top();
                container.pop();
                int firstOperand = container.top();
                container.pop();
                container.push(firstOperand + secondOperand);
            }
            else if(token == "-")
            {
                int secondOperand = container.top();
                container.pop();
                int firstOperand = container.top();
                container.pop();
                container.push(firstOperand - secondOperand);
            }
            else if(token == "*")
            {
                int secondOperand = container.top();
                container.pop();
                int firstOperand = container.top();
                container.pop();
                container.push(firstOperand * secondOperand);
            }
            else if(token == "/")
            {
                int secondOperand = container.top();
                container.pop();
                int firstOperand = container.top();
                container.pop();
                container.push(firstOperand / secondOperand);
            }
            else
            {
                container.push(stoi(token));
            }
        }
        return container.top();
    }
};