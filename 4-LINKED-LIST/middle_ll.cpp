#include <iostream>

using namespace std;

class LinkedList
{
private:
    /**
     * @struct Node
     * @brief Internal struct representing each element in the list.
     */
    struct Node
    {
        int data;
        Node *next;

        Node(int value, Node *nextPtr = nullptr)
        {
            this->data = value;
            this->next = nextPtr;
        }
    };

    Node *head;   ///< Pointer to the first node in the list
    size_t count; ///< Number of elements in the list

public:
    LinkedList()
    {
        head = nullptr;
        count = 0;
    }

    // Destructor releases all allocated nodes
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
        if (head == nullptr)
        {
            insertAtFront(value);
            return;
        }

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
        Node *curr = head, *prev = nullptr;
        while (curr->next != nullptr)
        {
            if (curr->data == value)
            {
                if (prev != nullptr)
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
        return false;
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
     * @brief Get the number of elements currently in the list.
     * @return Size of the list.
     */
    size_t size() const
    {
        return count;
    }

    void display()
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

    /**
     * @brief Prints the middle element of the list using the “tortoise & hare” approach.
     */
    void middle()
    {
        if (head == nullptr)
        {
            std::cout << "List is empty.\n";
            return;
        }

        Node *slow = head;
        Node *fast = head;

        // Advance fast by 2 steps and slow by 1 step,
        // but only while fast and fast->next are valid.
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;       // move slow by 1
            fast = fast->next->next; // move fast by 2
        }

        // When fast hits the end (or one past it), slow is at middle.
        std::cout << "Middle element: " << slow->data << std::endl;
    }
};

int main()
{

    LinkedList list;
    list.insertAtBack(10);
    list.insertAtBack(20);
    list.insertAtBack(30);
    list.insertAtBack(40);
    list.insertAtBack(50);
    list.insertAtBack(60);

    std::cout << "Current list: ";
    list.display(); // [10 -> 20 -> 30 -> 40 -> 50]

    list.middle(); // prints: Middle element: 30

    return 0;
}