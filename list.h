//
// Created by hloi on 9/12/2022.
//

#ifndef CH04DLINKEDLISTFA22_LIST_H
#define CH04DLINKEDLISTFA22_LIST_H


namespace KW {
    template<typename Item_Type>
    class list {
    private:
// Insert definition of nested class DNode here.
#include "DNode.h"

    public:
// Insert definition of nested class iterator here.
//#include "list_iterator.h"
/** Construct an empty list. */
        list() {
            head = nullptr;
            tail = nullptr;
            num_items = 0;
        }
        /** Construct a copy of a list. */
        list(const list<Item_Type>& other) {
            head = nullptr;
            tail = nullptr;
            num_items = 0;
            for (const_iterator itr = other.begin(); itr != other.end();
                 ++itr) {
                push_back(*itr);
            }
        }
        /** Destroy a list. */
        ~list() {
            while (head != nullptr) {
                DNode *current = head;
                head = head->next;
                delete current;
            }
            tail = nullptr;
            num_items = 0;
        }

        /** Assign the contents of one list to another. */
        list<Item_Type>& operator=(const list<Item_Type>& other) {
// Make a copy of the other list.
            list<Item_Type> temp_copy(other);  // calling copy constructor
// Swap contents of self with the copy.
            swap(temp_copy);
// Return -- upon return the copy will be destroyed.
            return *this;
        }

        void push_front(const Item_Type& item) {
            head = new DNode(item, nullptr, head); // Step 1
            if (head->next != nullptr)
                head->next->prev = head; // Step 2
            if (tail == nullptr) // List was empty.
                tail = head;
            num_items++;
        }

        void push_back(const Item_Type& item) {
            if (tail != nullptr) {
                tail->next = new DNode(item, tail, nullptr); // Step 1
                tail = tail->next; // Step 2
                num_items++;
            } else { // List was empty.
                push_front(item);
            }
        }

        iterator insert(iterator pos, const Item_Type& item) {
            // Create a new node linked before node referenced by pos.

// Check for special cases
            if (pos.current == head) {
                push_front(item);
                return begin();
            } else if (pos.current == nullptr) { // Past the last node.
                push_back(item);
                return iterator(this, tail);
            }

            DNode* new_node = new DNode(item,
                                        pos.current->prev,
                                        pos.current); // Step 1
            // Update links
            pos.current->prev->next = new_node; // Step 2
            pos.current->prev = new_node; // Step 3
            num_items++;
            return iterator(this, new_node);
        }
// Give iterator access to private members of list.
        friend class iterator;
// Insert definition of nested class const_iterator here.
//#include "list_const_iterator.h"

// Give const_iterator access to private members of list.
        friend class const_iterator;

    private:
// Data fields
/** A reference to the head of the list */
        DNode *head;
/** A reference to the end of the list */
        DNode *tail;
/** The size of the list */
        int num_items;

    };
}
#endif //CH04DLINKEDLISTFA22_LIST_H