//
// Created by hloi on 9/12/2022.
//

#ifndef CH04DLINKEDLISTFA22_LIST_H
#define CH04DLINKEDLISTFA22_LIST_H
#include <iostream>

using std::cout;
using std::endl;

namespace KW {
    template<typename Item_Type>
    class list {
    private:
// Insert definition of nested class DNode here.
#include "DNode.h"

// Data fields
/** A reference to the head of the list */
            DNode *head;
/** A reference to the end of the list */
            DNode *tail;
/** The size of the list */
            int num_items;


    public:
// Insert definition of nested class iterator here.
//#include "list_iterator.h"
// Insert definition of nested class iterator here.
#include "list_iterator.h"
// Give iterator access to private members of list.

#include "list_const_iterator.h"
// Give iterator access to private members of list.
            friend class const_iterator;
            friend class iterator;

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
//        friend class iterator;
// Insert definition of nested class const_iterator here.
//#include "list_const_iterator.h"

// Give const_iterator access to private members of list.
//        friend class const_iterator;

    // swap function for the list
    void swap(list<Item_Type>& other) {
            std::swap(head, other.head);
            std::swap(tail, other.tail);
            std::swap(num_items, other.num_items);
        }
        iterator begin() {
            iterator return_value(this, head);
            return return_value;
        }

        const_iterator begin() const {
            const_iterator return_value(this, head);
            return return_value;
        }

        iterator end() {
            iterator return_value(this, nullptr);
            return return_value;
        }

        /** Return a const_iterator to the end of the list
            @return a const_iterator to the end of the list
         */
        const_iterator end() const {
            const_iterator return_value(this, nullptr);
            return return_value;
        }

        void pop_front() {
            if (head == NULL)
                throw std::invalid_argument
                        ("Attempt to call pop_front() on an empty list");
            DNode* removed_node = head;
            head = head->next;
            delete removed_node;
            if (head != NULL)
                head->prev = NULL;
            else
                tail = NULL;
            num_items--;
        }

        void pop_back() {
            if (tail == nullptr) {
                throw std::invalid_argument("Attempt to call pop_back() on an empty list.");
            }
            DNode* remove_node = tail;
            tail = tail->prev;
            delete remove_node;
            if (tail != nullptr) {
                tail->next = nullptr;
            }
            else {
                head = nullptr;
            }
            num_items--;
        }

        void printInfo() {
            for (list::iterator itr = begin(); itr != end();
                 ++itr) {
                cout << *itr << endl;
            }
        }

        void printInfo2() {
                const const_iterator begin2 = begin();
                const const_iterator end2 = end();
                for (const list::const_iterator itr = begin(); itr != end();
                     ++itr) {
                    cout << *itr << endl;
                }
            }


        iterator get(int pos) {
            iterator ibegin = begin();
            for (int i=0; i<pos; i++) {
                ++ibegin;
            }
            return ibegin;
        }
    };
} // namespace kw
#endif //CH04DLINKEDLISTFA22_LIST_H
