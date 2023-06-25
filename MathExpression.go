package main

import (
	"fmt"
	"strconv"
	"strings"
)

// Operator precedence map
var precedence = map[string]int{
	"+": 1,
	"-": 1,
	"*": 2,
	"/": 2,
}

// Stack data structure
type Stack []string

// Push adds an element to the top of the stack
func (s *Stack) Push(val string) {
	*s = append(*s, val)
}

// Pop removes and returns the top element of the stack
func (s *Stack) Pop() string {
	index := len(*s) - 1
	element := (*s)[index]
	*s = (*s)[:index]
	return element
}

// Perform operation based on the operator
func performOperation(operands *Stack, operator string) {
	num2, _ := strconv.Atoi(operands.Pop())
	num1, _ := strconv.Atoi(operands.Pop())

	switch operator {
	case "+":
		operands.Push(strconv.Itoa(num1 + num2))
	case "-":
		operands.Push(strconv.Itoa(num1 - num2))
	case "*":
		operands.Push(strconv.Itoa(num1 * num2))
	case "/":
		operands.Push(strconv.Itoa(num1 / num2))
	}
}

// Evaluate the mathematical expression
func evaluateExpression(expression string) int {
	operators := Stack{}
	operands := Stack{}

	tokens := strings.Split(expression, "")

	for _, token := range tokens {
		if token == " " {
			continue
		}

		if _, err := strconv.Atoi(token); err == nil {
			operands.Push(token)
		} else if token == "(" {
			operators.Push(token)
		} else if token == ")" {
			for len(operators) > 0 && operators[len(operators)-1] != "(" {
				performOperation(&operands, operators.Pop())
			}
			operators.Pop() // Discard "("
		} else {
			for len(operators) > 0 && precedence[token] <= precedence[operators[len(operators)-1]] {
				performOperation(&operands, operators.Pop())
			}
			operators.Push(token)
		}
	}

	for len(operators) > 0 {
		performOperation(&operands, operators.Pop())
	}

	result, _ := strconv.Atoi(operands.Pop())
	return result
}

func main() {
	expression := "3*(4/2+1)+3*1"
	result := evaluateExpression(expression)
	fmt.Println("Result:", result) // Output: 12
}
