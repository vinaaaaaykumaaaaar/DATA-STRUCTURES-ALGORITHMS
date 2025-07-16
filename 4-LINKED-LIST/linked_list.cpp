/**
 * @file linked_list.cpp
 * @brief A beginner-friendly, industry-standard implementation of a singly linked list in C++.
 *
 * This program defines a LinkedList class supporting:
 *  - insertAtFront(value)
 *  - insertAtBack(value)
 *  - remove(value)
 *  - find(value)
 *  - display()
 *  - size()
 *  - clear()
 *
 * It includes:
 *  - Proper encapsulation (private Node struct, public API)
 *  - Resource management (destructor to clean up nodes)
 *  - Detailed comments and Doxygen-style documentation
 */

#include <iostream>  // std::cout, std::endl
#include <stdexcept> // std::runtime_error

/**
 * @class LinkedList
 * @brief Singly linked list of integers.
 *
 * This class manages a collection of integer values in a dynamically
 * allocated, singly linked structure. It exposes an easy-to-use API
 * for insertion, removal, search, and traversal.
 */
class LinkedList
{
private:
    /**
     * @struct Node
     * @brief Internal struct representing each element in the list.
     */
    struct Node
    {
        int data;   ///< Value stored in this node
        Node *next; ///< Pointer to the next node (or nullptr if end)

        /// Constructor for convenience
        Node(int value, Node *nextPtr = nullptr)
            : data(value), next(nextPtr) {}
    };

    Node *head;   ///< Pointer to the first node in the list
    size_t count; ///< Number of elements in the list

public:
    /// Default constructor initializes an empty list
    LinkedList() : head(nullptr), count(0) {}

    /// Destructor releases all allocated nodes
    ~LinkedList()
    {
        clear();
    }

    /**
     * @brief Insert a new node with given value at the front.
     * @param value The integer to insert.
     */
    void insertAtFront(int value)
    {
        head = new Node(value, head);
        ++count;
    }

    /**
     * @brief Insert a new node with given value at the back.
     * @param value The integer to insert.
     */
    void insertAtBack(int value)
    {
        if (!head)
        {
            // If list is empty, front insertion is equivalent
            insertAtFront(value);
            return;
        }
        // Traverse to last node
        Node *curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = new Node(value);
        ++count;
    }

    /**
     * @brief Remove the first occurrence of value from the list.
     * @param value The integer to remove.
     * @return True if removal succeeded; false if value not found.
     */
    bool remove(int value)
    {
        Node *curr = head;
        Node *prev = nullptr;

        while (curr != nullptr)
        {
            if (curr->data == value)
            {
                // Found node to delete
                if (prev)
                {
                    prev->next = curr->next;
                }
                else
                {
                    head = curr->next;
                }
                delete curr;
                --count;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false; // value not found
    }

    /**
     * @brief Search for a value in the list.
     * @param value The integer to find.
     * @return True if found; false otherwise.
     */
    bool find(int value) const
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            if (curr->data == value)
            {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    /**
     * @brief Print all values in the list to stdout.
     *
     * Format: [val1 -> val2 -> ... -> valN]
     */
    void display() const
    {
        std::cout << "[";
        Node *curr = head;
        while (curr != nullptr)
        {
            std::cout << curr->data;
            if (curr->next)
            {
                std::cout << " -> ";
            }
            curr = curr->next;
        }
        std::cout << "]" << std::endl;
    }

    /**
     * @brief Get the number of elements currently in the list.
     * @return Size of the list.
     */
    size_t size() const
    {
        return count;
    }

    /**
     * @brief Remove all elements from the list, freeing memory.
     */
    void clear()
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            Node *next = curr->next;
            delete curr;
            curr = next;
        }
        head = nullptr;
        count = 0;
    }
};

/**
 * @brief Demonstrates usage of the LinkedList class.
 */
int main()
{
    LinkedList list;

    // Insert some elements
    list.insertAtFront(10);
    list.insertAtFront(20);
    list.insertAtBack(30);
    list.insertAtBack(40);

    std::cout << "List after insertions: ";
    list.display(); // Expected: [20 -> 10 -> 30 -> 40]
    std::cout << "Size: " << list.size() << std::endl;

    // Search for values
    int toFind = 30;
    if (list.find(toFind))
    {
        std::cout << toFind << " found in the list." << std::endl;
    }
    else
    {
        std::cout << toFind << " NOT found." << std::endl;
    }

    // Remove an element
    int toRemove = 10;
    bool removed = list.remove(toRemove);
    std::cout << (removed ? "Removed " : "Could not remove ") << toRemove << std::endl;

    std::cout << "List after removal: ";
    list.display(); // Expected: [20 -> 30 -> 40]
    std::cout << "Size: " << list.size() << std::endl;

    // Clear all elements
    list.clear();
    std::cout << "After clear(), list size = " << list.size() << std::endl;
    std::cout << "List after clear(): ";
    list.display(); // Expected: []

    return 0;
}
