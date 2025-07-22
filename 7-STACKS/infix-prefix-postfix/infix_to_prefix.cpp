// stack implementation of infix-expression to prefix-expression

#include <iostream>
#include <stack>
#include <map>
#include <string>

bool isAlphaNumeric(char character)
{
    if (character >= 'A' && character <= 'Z' || character >= 'a' && character <= 'z' || character >= '0' && character <= '9')
        return true;
    else
        return false;
}

std::string reverse_infix_expression(std::string infix_expression)
{
    std::string reversed_string = "";
    int_fast64_t index = infix_expression.length() - 1;

    while (index >= 0)
    {
        if (infix_expression[index] == '(')
        {
            reversed_string += ')';
        }
        else if (infix_expression[index] == ')')
        {
            reversed_string += '(';
        }
        else
        {
            reversed_string += infix_expression[index];
        }

        --index;
    }

    return reversed_string;
}

std::string infix_to_prefix(std::string infix_expression)
{
    std::string reversed_infix_expression = reverse_infix_expression(infix_expression);

    int_fast64_t index = 0;
    std::string prefix_expression = "";
    std::stack<char> expression_stack;

    std::map<char, int_fast64_t> priority_value;
    priority_value['^'] = 3;
    priority_value['/'] = 2;
    priority_value['*'] = 2;
    priority_value['+'] = 1;
    priority_value['-'] = 1;

    while (index < reversed_infix_expression.length())
    {
        char character = reversed_infix_expression[index];

        if (isAlphaNumeric(character))
        {
            prefix_expression += character;
        }
        else if (character == '(')
        {
            expression_stack.push(character);
        }
        else if (character == ')')
        {
            while (!expression_stack.empty() && expression_stack.top() != '(')
            {
                prefix_expression += expression_stack.top();
                expression_stack.pop();
            }
            expression_stack.pop();
        }
        else
        {
            if (character == '^')
            {
                while (!expression_stack.empty() && priority_value[character] <= priority_value[expression_stack.top()])
                {
                    prefix_expression += expression_stack.top();
                    expression_stack.pop();
                }
            }
            else
            {
                while (!expression_stack.empty() && priority_value[character] < priority_value[expression_stack.top()])
                {
                    prefix_expression += expression_stack.top();
                    expression_stack.pop();
                }
            }

            expression_stack.push(character);
        }

        ++index;
    }

    while (!expression_stack.empty())
    {
        prefix_expression += expression_stack.top();
        expression_stack.pop();
    }

    return reverse_infix_expression(prefix_expression);
}

int main()
{

    std::string infix_string = "(a+b)*c-d+f";

    std::cout << infix_to_prefix(infix_string) << std::endl;

    return 0;
}
