//
// Created by jrpao on 12/04/2020.
//

#ifndef FINALLINKEDLIST_LINKED_LIST_H
#define FINALLINKEDLIST_LINKED_LIST_H
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

namespace utec
{
    struct node {
        int data = 0;
        node* next_node = nullptr;
    };

    inline namespace first {
        class linked_list_t {
        private:
            node* head = nullptr;
            node* tail = nullptr;
            size_t size = 0;
        public:
            // constructors
            linked_list_t() = default;
            linked_list_t(const linked_list_t& other);
            linked_list_t&operator=(const linked_list_t& other);
            linked_list_t(linked_list_t&& other) noexcept ;
            linked_list_t&operator=(linked_list_t&& other) noexcept ;

            // destroyers
            ~linked_list_t();

            // add operations
            void push_front(int value);
            void push_back(int value);
            void insert(size_t index, int value);

            // remove operations
            void pop_front();
            void pop_back();
            void erase(size_t index);

            // traversal operations
            int& item(size_t index);
            const int& item(size_t index) const;

            // get size of list
            size_t size_linked_list() const;

            node *getNode(size_t index);
            node * getHead() const;
        };
    }
}

#endif //FINALLINKEDLIST_LINKED_LIST_H
