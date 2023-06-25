def get_precedence(op):
    if op in ['+', '-']:
        return 1
    elif op in ['*', '/']:
        return 2
    else:
        return 0

def perform_operation(num1, num2, op):
    if op == '+':
        return num1 + num2
    elif op == '-':
        return num1 - num2
    elif op == '*':
        return num1 * num2
    elif op == '/':
        return num1 / num2
    else:
        return 0

def evaluate_expression(expression):
    operands = []
    operators = []

    i = 0
    while i < len(expression):
        ch = expression[i]
        if ch == ' ':
            i += 1
            continue

        if ch.isdigit():
            num = 0
            while i < len(expression) and expression[i].isdigit():
                num = num * 10 + int(expression[i])
                i += 1
            operands.append(num)
        elif ch == '(':
            operators.append(ch)
            i += 1
        elif ch == ')':
            while operators and operators[-1] != '(':
                num2 = operands.pop()
                num1 = operands.pop()
                op = operators.pop()
                result = perform_operation(num1, num2, op)
                operands.append(result)
            operators.pop()
            i += 1
        else:
            while operators and get_precedence(ch) <= get_precedence(operators[-1]):
                num2 = operands.pop()
                num1 = operands.pop()
                op = operators.pop()
                result = perform_operation(num1, num2, op)
                operands.append(result)
            operators.append(ch)
            i += 1

    while operators:
        num2 = operands.pop()
        num1 = operands.pop()
        op = operators.pop()
        result = perform_operation(num1, num2, op)
        operands.append(result)

    return operands[0]

expression = "3*(1+4/2)+3*1"
result = evaluate_expression(expression)
print("Result:", result)
