// stack implementation of conversion of infix-expression to postfix-expression

#include <iostream>
#include <stack>
#include <map>

std::string infix_to_postfix(std::string infix_expression)
{
    std::string postfix_expression = "";
    std::stack<char> expression_stack;
    int_fast64_t index = 0;
    int_fast64_t size = infix_expression.length();

    std::map<char, int> priority_table;
    priority_table['^'] = 3;
    priority_table['*'] = 2;
    priority_table['/'] = 2;
    priority_table['-'] = 1;
    priority_table['+'] = 1;

    while (index < size)
    {
        char character = infix_expression[index];

        if (character >= 'A' && character <= 'Z' || character >= 'a' && character <= 'z' || character >= '0' && character <= '9')
        {
            postfix_expression = postfix_expression + character;
        }
        else if (character == '(')
        {
            expression_stack.push(character);
        }
        else if (character == ')')
        {
            while (!expression_stack.empty() && expression_stack.top() != '(')
            {
                postfix_expression = postfix_expression + expression_stack.top();
                expression_stack.pop();
            }
            expression_stack.pop();
        }
        else
        {
            while (!expression_stack.empty() && expression_stack.top() != '(' && priority_table[character] <= priority_table[expression_stack.top()])
            {
                postfix_expression = postfix_expression + expression_stack.top();
                expression_stack.pop();
            }
            expression_stack.push(character);
        }

        ++index;
    }

    while (!expression_stack.empty())
    {
        postfix_expression = postfix_expression + expression_stack.top();
        expression_stack.pop();
    }

    return postfix_expression;
}

int main()
{

    std::string infix_string = "a+b*(c^d-e)";

    std::cout << infix_to_postfix(infix_string) << std::endl;

    return 0;
}