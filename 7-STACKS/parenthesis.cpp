#include <iostream>
#include <string>
#include <cstdint>

/**
 * @class BalancedParenthesesChecker
 * @brief A class to check if parentheses, brackets, and braces are balanced in a string
 *
 * This class uses a stack-based approach to determine if opening and closing
 * brackets are properly matched and balanced. It supports three types of brackets:
 * - Parentheses: ( )
 * - Square brackets: [ ]
 * - Curly braces: { }
 *
 * @note This implementation follows NASA-style documentation standards and
 *       uses the previously created Stack class for educational purposes.
 */
class BalancedParenthesesChecker
{
private:
    /**
     * @struct Node
     * @brief Internal node structure for the stack implementation
     *
     * Each node contains a character data value and a pointer to the next node.
     * This creates a chain of nodes that forms the stack structure for bracket checking.
     *
     * @param data The character value to be stored in the stack node
     * @param nextPtr The pointer to the next node in the stack
     */
    struct Node
    {
        char data;     ///< The character stored in this node
        Node *nextPtr; ///< Pointer to the next node in the stack

        /**
         * @brief Node constructor
         * @param element The character value to store in the node (default: '\0')
         */
        Node(char element = '\0') : data(element), nextPtr(nullptr) {}
    };

    Node *head;         ///< Pointer to the top of the stack
    int_fast64_t count; ///< Number of elements currently in the stack

    /**
     * @brief Adds a character to the top of the internal stack
     *
     * @param element The character to be pushed onto the stack
     * @return void
     */
    void push(char element);

    /**
     * @brief Removes the top character from the internal stack
     *
     * @return void
     */
    void pop();

    /**
     * @brief Returns the top character without removing it
     *
     * @return char The character at the top of the stack, or '\0' if empty
     */
    char top();

    /**
     * @brief Checks if the internal stack is empty
     *
     * @return true if the stack is empty, false otherwise
     */
    bool isEmpty();

public:
    /**
     * @brief BalancedParenthesesChecker constructor
     *
     * Initializes an empty stack for bracket checking operations.
     */
    BalancedParenthesesChecker() : head(nullptr), count(0) {}

    /**
     * @brief BalancedParenthesesChecker destructor
     *
     * Properly deallocates all memory used by the internal stack.
     */
    ~BalancedParenthesesChecker()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    /**
     * @brief Checks if the given string has balanced brackets
     *
     * This function processes each character in the input string and uses a stack
     * to keep track of opening brackets. When a closing bracket is encountered,
     * it checks if it matches the most recent opening bracket.
     *
     * @param expression The string to be checked for balanced brackets
     * @return true if all brackets are properly balanced and matched
     * @return false if brackets are unbalanced or mismatched
     *
     * @note Time Complexity: O(n) - where n is the length of the string
     * @note Space Complexity: O(n) - worst case when all characters are opening brackets
     *
     * Algorithm Steps:
     * 1. Iterate through each character in the string
     * 2. If opening bracket found, push to stack
     * 3. If closing bracket found, check if it matches top of stack
     * 4. If stack is empty at end, brackets are balanced
     */
    bool isBalanced(const std::string &expression);

    /**
     * @brief Determines if a character is an opening bracket
     *
     * @param ch The character to check
     * @return true if the character is '(', '[', or '{'
     * @return false otherwise
     */
    bool isOpeningBracket(char ch);

    /**
     * @brief Determines if a character is a closing bracket
     *
     * @param ch The character to check
     * @return true if the character is ')', ']', or '}'
     * @return false otherwise
     */
    bool isClosingBracket(char ch);

    /**
     * @brief Checks if opening and closing brackets form a matching pair
     *
     * @param opening The opening bracket character
     * @param closing The closing bracket character
     * @return true if they form a valid pair: (), [], or {}
     * @return false if they don't match
     */
    bool isMatchingPair(char opening, char closing);

    /**
     * @brief Provides detailed analysis of bracket balance with step-by-step output
     *
     * This function performs the same balance checking as isBalanced() but provides
     * detailed output showing each step of the process for educational purposes.
     *
     * @param expression The string to be analyzed
     * @return true if balanced, false otherwise
     */
    bool analyzeBalance(const std::string &expression);
};

// =============================================================================
// IMPLEMENTATION OF PRIVATE MEMBER FUNCTIONS (INTERNAL STACK)
// =============================================================================

void BalancedParenthesesChecker::push(char element)
{
    Node *newNode = new Node(element);

    if (newNode == nullptr)
    {
        std::cout << "Error: Memory allocation failed" << std::endl;
        return;
    }

    newNode->nextPtr = head;
    head = newNode;
    count++;
}

void BalancedParenthesesChecker::pop()
{
    if (head == nullptr)
    {
        return; // Silent return for internal operations
    }

    Node *tempNode = head;
    head = head->nextPtr;
    count--;
    delete tempNode;
}

char BalancedParenthesesChecker::top()
{
    if (head == nullptr)
    {
        return '\0'; // Return null character if empty
    }

    return head->data;
}

bool BalancedParenthesesChecker::isEmpty()
{
    return (head == nullptr);
}

// =============================================================================
// IMPLEMENTATION OF PUBLIC MEMBER FUNCTIONS
// =============================================================================

bool BalancedParenthesesChecker::isBalanced(const std::string &expression)
{
    // Process each character in the expression
    for (int_fast64_t i = 0; i < expression.length(); i++)
    {
        char currentChar = expression[i];

        // If opening bracket, push to stack
        if (isOpeningBracket(currentChar))
        {
            push(currentChar);
        }
        // If closing bracket, check for matching pair
        else if (isClosingBracket(currentChar))
        {
            // If stack is empty, no matching opening bracket
            if (isEmpty())
            {
                return false;
            }

            // Check if the closing bracket matches the top opening bracket
            char topBracket = top();
            pop();

            if (!isMatchingPair(topBracket, currentChar))
            {
                return false;
            }
        }
        // Ignore all other characters (letters, numbers, spaces, etc.)
    }

    // Expression is balanced if stack is empty (all brackets matched)
    return isEmpty();
}

bool BalancedParenthesesChecker::isOpeningBracket(char ch)
{
    return (ch == '(' || ch == '[' || ch == '{');
}

bool BalancedParenthesesChecker::isClosingBracket(char ch)
{
    return (ch == ')' || ch == ']' || ch == '}');
}

bool BalancedParenthesesChecker::isMatchingPair(char opening, char closing)
{
    return ((opening == '(' && closing == ')') ||
            (opening == '[' && closing == ']') ||
            (opening == '{' && closing == '}'));
}

bool BalancedParenthesesChecker::analyzeBalance(const std::string &expression)
{
    std::cout << "Analyzing expression: \"" << expression << "\"" << std::endl;
    std::cout << "Step-by-step process:" << std::endl;

    int_fast64_t step = 1;

    for (int_fast64_t i = 0; i < expression.length(); i++)
    {
        char currentChar = expression[i];

        std::cout << "Step " << step << ": Character '" << currentChar << "' at position " << i;

        if (isOpeningBracket(currentChar))
        {
            push(currentChar);
            std::cout << " -> Opening bracket found, pushed to stack" << std::endl;
            std::cout << "         Stack size: " << count << std::endl;
        }
        else if (isClosingBracket(currentChar))
        {
            std::cout << " -> Closing bracket found" << std::endl;

            if (isEmpty())
            {
                std::cout << "         Error: No matching opening bracket (stack is empty)" << std::endl;
                return false;
            }

            char topBracket = top();
            pop();

            if (isMatchingPair(topBracket, currentChar))
            {
                std::cout << "         Match found: '" << topBracket << "' matches '" << currentChar << "'" << std::endl;
                std::cout << "         Stack size: " << count << std::endl;
            }
            else
            {
                std::cout << "         Error: Mismatch - '" << topBracket << "' does not match '" << currentChar << "'" << std::endl;
                return false;
            }
        }
        else
        {
            std::cout << " -> Non-bracket character, ignored" << std::endl;
        }

        step++;
    }

    bool result = isEmpty();
    std::cout << "Final result: " << (result ? "BALANCED" : "NOT BALANCED") << std::endl;

    if (!result)
    {
        std::cout << "Reason: " << count << " unmatched opening bracket(s) remain" << std::endl;
    }

    return result;
}

// =============================================================================
// UTILITY FUNCTIONS FOR TESTING
// =============================================================================

/**
 * @brief Prints test results in a formatted manner
 *
 * @param testName Description of the test case
 * @param expression The expression being tested
 * @param expected Expected result (true/false)
 * @param actual Actual result from the function
 */
void printTestResult(const std::string &testName, const std::string &expression,
                     bool expected, bool actual)
{
    std::cout << "Test: " << testName << std::endl;
    std::cout << "Expression: \"" << expression << "\"" << std::endl;
    std::cout << "Expected: " << (expected ? "BALANCED" : "NOT BALANCED") << std::endl;
    std::cout << "Result: " << (actual ? "BALANCED" : "NOT BALANCED") << std::endl;
    std::cout << "Status: " << (expected == actual ? "PASS ✓" : "FAIL ✗") << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

// =============================================================================
// MAIN FUNCTION - TEST CASES AND DEMONSTRATIONS
// =============================================================================

/**
 * @brief Main function demonstrating balanced parentheses checking
 *
 * This function provides comprehensive test cases for the balanced parentheses
 * problem, demonstrating various scenarios including edge cases.
 *
 * @return int Exit status (0 for successful execution)
 */
int main()
{
    std::cout << "=== BALANCED PARENTHESES PROBLEM DEMONSTRATION ===" << std::endl;
    std::cout << "This program checks if brackets are properly balanced in expressions." << std::endl;
    std::cout << "Supported brackets: ( ) [ ] { }" << std::endl
              << std::endl;

    // Create checker object
    BalancedParenthesesChecker checker;

    // =============================================================================
    // TEST 1: Simple Balanced Cases
    // =============================================================================
    std::cout << "=== TEST 1: Simple Balanced Cases ===" << std::endl;

    std::string test1[] = {
        "()",
        "[]",
        "{}",
        "(())",
        "[[]]",
        "{{}}"};

    for (int i = 0; i < 6; i++)
    {
        bool result = checker.isBalanced(test1[i]);
        printTestResult("Simple balanced brackets", test1[i], true, result);
    }

    // =============================================================================
    // TEST 2: Simple Unbalanced Cases
    // =============================================================================
    std::cout << "=== TEST 2: Simple Unbalanced Cases ===" << std::endl;

    std::string test2[] = {
        "(",
        ")",
        "[",
        "]",
        "{",
        "}",
        "(()",
        "())"};

    for (int i = 0; i < 8; i++)
    {
        bool result = checker.isBalanced(test2[i]);
        printTestResult("Simple unbalanced brackets", test2[i], false, result);
    }

    // =============================================================================
    // TEST 3: Mixed Bracket Types
    // =============================================================================
    std::cout << "=== TEST 3: Mixed Bracket Types ===" << std::endl;

    struct TestCase
    {
        std::string expression;
        bool expected;
        std::string description;
    };

    TestCase test3[] = {
        {"()[]{}", true, "All types balanced"},
        {"([{}])", true, "Nested mixed brackets"},
        {"[({})]", true, "Complex nesting"},
        {"({[]})", true, "Multiple nesting levels"},
        {"([)]", false, "Interleaved brackets"},
        {"([{})", false, "Missing closing bracket"},
        {"){", false, "Wrong order"},
        {"([{]})", false, "Mismatched in middle"}};

    for (int i = 0; i < 8; i++)
    {
        bool result = checker.isBalanced(test3[i].expression);
        printTestResult(test3[i].description, test3[i].expression,
                        test3[i].expected, result);
    }

    // =============================================================================
    // TEST 4: Expressions with Other Characters
    // =============================================================================
    std::cout << "=== TEST 4: Expressions with Other Characters ===" << std::endl;

    TestCase test4[] = {
        {"a(b)c", true, "Letters with brackets"},
        {"x = (a + b) * [c - d]", true, "Mathematical expression"},
        {"if (condition) { print(\"hello\"); }", true, "Code-like expression"},
        {"array[index] = function(param)", true, "Programming syntax"},
        {"(a + b] * c", false, "Math with mismatched brackets"},
        {"if (condition { print(\"error\"); }", false, "Missing closing parenthesis"}};

    for (int i = 0; i < 6; i++)
    {
        bool result = checker.isBalanced(test4[i].expression);
        printTestResult(test4[i].description, test4[i].expression,
                        test4[i].expected, result);
    }

    // =============================================================================
    // TEST 5: Edge Cases
    // =============================================================================
    std::cout << "=== TEST 5: Edge Cases ===" << std::endl;

    TestCase test5[] = {
        {"", true, "Empty string"},
        {"abc123", true, "No brackets at all"},
        {"   ", true, "Only spaces"},
        {"((((((((((", false, "Only opening brackets"},
        {"))))))))))", false, "Only closing brackets"}};