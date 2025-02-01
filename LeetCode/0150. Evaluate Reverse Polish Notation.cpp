class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> num;
        for (auto& it : tokens) {
            if (it.size() > 1 || isdigit(it[0])) {  // 處理負數與數字
                num.push(stoll(it));
            } else {
                long long num1 = num.top(); num.pop();
                long long num2 = num.top(); num.pop();
                switch (it[0]) {
                    case '+': num.push(num2 + num1); break;
                    case '-': num.push(num2 - num1); break;
                    case '*': num.push(num2 * num1); break;
                    case '/': num.push(num2 / num1); break;
                }
            }
        }
        return num.top();
    }
};
