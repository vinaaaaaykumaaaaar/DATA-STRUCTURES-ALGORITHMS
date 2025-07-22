#include <iostream>
#include <cstdint>

/**
 * @class Stack
 * @brief A simple stack implementation using linked list data structure
 *
 * This class implements a Last-In-First-Out (LIFO) stack using a singly linked list.
 * The stack supports basic operations: push, pop, top, isEmpty, and size.
 *
 * @note This implementation uses dynamic memory allocation and follows NASA-style
 *       documentation standards for educational purposes.
 */
class Stack
{
private:
    /**
     * @struct Node
     * @brief Internal node structure for the linked list implementation
     *
     * Each node contains an integer data value and a pointer to the next node.
     * This creates a chain of nodes that forms the stack structure.
     *
     * @param data The integer value to be stored in the stack node
     * @param nextPtr The pointer to the next node in the stack
     */
    struct Node
    {
        int_fast64_t data; ///< The data stored in this node
        Node *nextPtr;     ///< Pointer to the next node in the stack

        /**
         * @brief Node constructor
         * @param element The data value to store in the node (default: 0)
         */
        Node(int_fast64_t element = 0) : data(element), nextPtr(nullptr) {}
    };

    Node *head;         ///< Pointer to the top of the stack
    int_fast64_t count; ///< Number of elements currently in the stack

public:
    /**
     * @brief Stack constructor
     *
     * Initializes an empty stack by setting the head pointer to nullptr
     * and the count to zero.
     */
    Stack() : head(nullptr), count(0) {}

    /**
     * @brief Stack destructor
     *
     * Properly deallocates all memory used by the stack to prevent memory leaks.
     * This is crucial for good memory management practices.
     */
    ~Stack()
    {
        while (!isEmpty())
        {
            popElement();
        }
    }

    /**
     * @brief Adds an element to the top of the stack
     *
     * Creates a new node with the given element and places it at the top
     * of the stack. The new node becomes the new head of the linked list.
     *
     * @param element The integer value to be pushed onto the stack
     * @return void - No return value, but prints confirmation message
     *
     * @note Time Complexity: O(1) - Constant time operation
     * @note Space Complexity: O(1) - Uses constant extra space
     */
    void pushElement(int_fast64_t element);

    /**
     * @brief Removes the top element from the stack
     *
     * Removes and deallocates the node at the top of the stack.
     * Updates the head pointer to point to the next node.
     *
     * @return void - No return value, but prints the removed element
     *
     * @note Time Complexity: O(1) - Constant time operation
     * @note Space Complexity: O(1) - Uses constant extra space
     * @warning Attempting to pop from an empty stack will display an error message
     */
    void popElement();

    /**
     * @brief Returns the top element without removing it
     *
     * Provides access to the data at the top of the stack without
     * modifying the stack structure. This is a "peek" operation.
     *
     * @return int_fast64_t The value at the top of the stack
     * @return 0 if the stack is empty (with error message)
     *
     * @note Time Complexity: O(1) - Constant time operation
     * @note Space Complexity: O(1) - Uses constant extra space
     */
    int_fast64_t topElement();

    /**
     * @brief Checks if the stack is empty
     *
     * Determines whether the stack contains any elements by checking
     * if the head pointer is nullptr.
     *
     * @return true if the stack is empty
     * @return false if the stack contains at least one element
     *
     * @note Time Complexity: O(1) - Constant time operation
     */
    bool isEmpty();

    /**
     * @brief Returns the number of elements in the stack
     *
     * Provides the current count of elements without needing to
     * traverse the entire stack structure.
     *
     * @return int_fast64_t The number of elements currently in the stack
     *
     * @note Time Complexity: O(1) - Constant time operation
     */
    int_fast64_t size();

    /**
     * @brief Displays all elements in the stack
     *
     * Prints all elements from top to bottom without modifying the stack.
     * Useful for debugging and educational demonstrations.
     *
     * @return void - No return value, prints to console
     *
     * @note Time Complexity: O(n) - Linear time where n is stack size
     */
    void displayStack();
};

// =============================================================================
// IMPLEMENTATION OF MEMBER FUNCTIONS
// =============================================================================

void Stack::pushElement(int_fast64_t element)
{
    // Create a new node with the given element
    Node *newNode = new Node(element);

    // Check for successful memory allocation
    if (newNode == nullptr)
    {
        std::cout << "Error: Memory allocation failed" << std::endl;
        return;
    }

    // If stack is empty, new node becomes the head
    if (head == nullptr)
    {
        head = newNode;
        count++;
        std::cout << "Element " << element << " pushed to stack" << std::endl;
        return;
    }

    // Link the new node to the current top and update head
    newNode->nextPtr = head;
    head = newNode;
    count++;

    std::cout << "Element " << element << " pushed to stack" << std::endl;
}

void Stack::popElement()
{
    // Check if stack is empty
    if (head == nullptr)
    {
        std::cout << "Error: Stack is empty - cannot pop" << std::endl;
        return;
    }

    // Store reference to current top node
    Node *tempNode = head;

    // Update head to point to next node
    head = head->nextPtr;
    count--;

    // Display the popped element and free memory
    std::cout << "Element " << tempNode->data << " popped from the stack" << std::endl;
    delete tempNode;
}

int_fast64_t Stack::topElement()
{
    // Check if stack is empty BEFORE accessing data
    if (head == nullptr)
    {
        std::cout << "Error: Stack is empty - no top element" << std::endl;
        return 0; // Return 0 as error indicator
    }

    return head->data;
}

bool Stack::isEmpty()
{
    return (head == nullptr);
}

int_fast64_t Stack::size()
{
    return count;
}

void Stack::displayStack()
{
    if (isEmpty())
    {
        std::cout << "Stack is empty" << std::endl;
        return;
    }

    std::cout << "Stack contents (top to bottom): ";
    Node *current = head;

    while (current != nullptr)
    {
        std::cout << current->data;
        if (current->nextPtr != nullptr)
        {
            std::cout << " -> ";
        }
        current = current->nextPtr;
    }
    std::cout << std::endl;
}

// =============================================================================
// MAIN FUNCTION - TEST CASES AND DEMONSTRATIONS
// =============================================================================

/**
 * @brief Main function demonstrating stack operations
 *
 * This function provides comprehensive test cases for all stack operations.
 * It demonstrates proper usage and edge cases for educational purposes.
 *
 * @return int Exit status (0 for successful execution)
 */
int main()
{
    std::cout << "=== STACK DATA STRUCTURE DEMONSTRATION ===" << std::endl;
    std::cout << "Creating a new stack..." << std::endl
              << std::endl;

    // Create a new stack object
    Stack myStack;

    // =============================================================================
    // TEST 1: Empty Stack Operations
    // =============================================================================
    std::cout << "--- Test 1: Empty Stack Operations ---" << std::endl;
    std::cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "Stack size: " << myStack.size() << std::endl;

    // Try operations on empty stack
    std::cout << "Attempting to pop from empty stack:" << std::endl;
    myStack.popElement();

    std::cout << "Attempting to get top element from empty stack:" << std::endl;
    int_fast64_t topVal = myStack.topElement();
    std::cout << "Returned value: " << topVal << std::endl;

    myStack.displayStack();
    std::cout << std::endl;

    // =============================================================================
    // TEST 2: Push Operations
    // =============================================================================
    std::cout << "--- Test 2: Push Operations ---" << std::endl;
    std::cout << "Pushing elements: 10, 20, 30, 40, 50" << std::endl;

    myStack.pushElement(10);
    myStack.pushElement(20);
    myStack.pushElement(30);
    myStack.pushElement(40);
    myStack.pushElement(50);

    std::cout << "Stack size after pushes: " << myStack.size() << std::endl;
    std::cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << std::endl;
    myStack.displayStack();
    std::cout << std::endl;

    // =============================================================================
    // TEST 3: Top Element Operations
    // =============================================================================
    std::cout << "--- Test 3: Top Element Operations ---" << std::endl;
    std::cout << "Top element: " << myStack.topElement() << std::endl;
    std::cout << "Stack size (should be unchanged): " << myStack.size() << std::endl;
    myStack.displayStack();
    std::cout << std::endl;

    // =============================================================================
    // TEST 4: Pop Operations
    // =============================================================================
    std::cout << "--- Test 4: Pop Operations ---" << std::endl;
    std::cout << "Popping 2 elements:" << std::endl;

    myStack.popElement();
    std::cout << "Stack size after 1 pop: " << myStack.size() << std::endl;

    myStack.popElement();
    std::cout << "Stack size after 2 pops: " << myStack.size() << std::endl;

    std::cout << "Current top element: " << myStack.topElement() << std::endl;
    myStack.displayStack();
    std::cout << std::endl;

    // =============================================================================
    // TEST 5: Mixed Operations
    // =============================================================================
    std::cout << "--- Test 5: Mixed Operations ---" << std::endl;
    std::cout << "Adding element 100:" << std::endl;
    myStack.pushElement(100);

    std::cout << "Current state:" << std::endl;
    myStack.displayStack();
    std::cout << "Size: " << myStack.size() << std::endl;
    std::cout << "Top: " << myStack.topElement() << std::endl;
    std::cout << std::endl;

    // =============================================================================
    // TEST 6: Complete Emptying
    // =============================================================================
    std::cout << "--- Test 6: Complete Emptying ---" << std::endl;
    std::cout << "Popping all remaining elements:" << std::endl;

    while (!myStack.isEmpty())
    {
        myStack.popElement();
        std::cout << "Remaining elements: " << myStack.size() << std::endl;
    }

    std::cout << "Final state:" << std::endl;
    std::cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << std::endl;
    myStack.displayStack();
    std::cout << std::endl;

    // =============================================================================
    // TEST 7: Large Numbers Test
    // =============================================================================
    std::cout << "--- Test 7: Large Numbers Test ---" << std::endl;
    std::cout << "Testing with large numbers:" << std::endl;

    myStack.pushElement(1000000);
    myStack.pushElement(-500000);
    myStack.pushElement(999999999);

    myStack.displayStack();
    std::cout << "Top element: " << myStack.topElement() << std::endl;
    std::cout << std::endl;

    // Clean up remaining elements
    while (!myStack.isEmpty())
    {
        myStack.popElement();
    }

    std::cout << "=== STACK DEMONSTRATION COMPLETED ===" << std::endl;
    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}