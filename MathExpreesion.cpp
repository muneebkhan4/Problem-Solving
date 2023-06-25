#include <iostream>
#include <stack>
#include <string>

int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0;
}

int performOperation(int num1, int num2, char op) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        default:
            return 0;
    }
}

int evaluateExpression(const std::string& expression) {
    std::stack<int> operands;
    std::stack<char> operators;

    int i = 0;
    while (i < expression.length()) {
        char ch = expression[i];
        if (ch == ' ') {
            i++;
            continue;
        }

        if (isdigit(ch)) {
            int num = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            operands.push(num);
        } else if (ch == '(') {
            operators.push(ch);
            i++;
        } else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                int num2 = operands.top();
                operands.pop();
                int num1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                int result = performOperation(num1, num2, op);
                operands.push(result);
            }
            operators.pop();
            i++;
        } else {
            while (!operators.empty() && getPrecedence(ch) <= getPrecedence(operators.top())) {
                int num2 = operands.top();
                operands.pop();
                int num1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                int result = performOperation(num1, num2, op);
                operands.push(result);
            }
            operators.push(ch);
            i++;
        }
    }

    while (!operators.empty()) {
        int num2 = operands.top();
        operands.pop();
        int num1 = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();
        int result = performOperation(num1, num2, op);
        operands.push(result);
    }

    return operands.top();
}

int main() {
    std::string expression = "3*(1+4/2)+3*1";
    int result = evaluateExpression(expression);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
