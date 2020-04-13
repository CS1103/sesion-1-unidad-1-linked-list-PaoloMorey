//
// Created by jrpao on 12/04/2020.
//

#include "linked_list.h"
utec::first::linked_list_t::linked_list_t(const utec::linked_list_t &other) {
    if(other.size_linked_list() == 0){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    else{
        size = 1;
        auto current = other.getHead();
        head = new node{current->data, nullptr};
        tail = head;
        size_t i = 1;
        while (i < other.size_linked_list()) {
            current = current->next_node;
            this->push_back(current->data);
            ++i;
        }
    }

}

utec::linked_list_t &utec::first::linked_list_t::operator=(const utec::linked_list_t &other) {
    if(other.size_linked_list() == 0){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    else{
        size = 1;
        auto current = other.getHead();
        head = new node{current->data, nullptr};
        tail = head;
        size_t i = 1;
        while (i < other.size_linked_list()) {
            current = current->next_node;
            this->push_back(current->data);
            ++i;
        }
    }
    return *this;
}

utec::first::linked_list_t::linked_list_t(utec::linked_list_t &&other) noexcept {
    size = move(other.size);
    head = move(other.head);
    tail = move(other.head);
    other.size = 0;
    other.head = nullptr;
    other.tail = nullptr;
}

utec::linked_list_t &utec::first::linked_list_t::operator=(utec::linked_list_t &&other) noexcept {
    node* current = head;
    while(current != nullptr){
        node* next = head->next_node;
        delete current;
        current = next;
    }
    head = nullptr;
    size = 0;

    size = move(other.size);
    head = move(other.head);
    tail = move(other.head);
    other.size = 0;
    other.head = nullptr;
    other.tail = nullptr;
    return *this;
}

utec::first::linked_list_t::~linked_list_t() {
    auto current = head;
    while (current != nullptr){
        auto next = current->next_node;
        delete current;
        current = next;
    }
    cout << endl <<  "Destruyendo la lista...";
}

void utec::first::linked_list_t::push_front(int value) {
    head = new node{value, head};
    if (tail == nullptr) tail = head;
    size++;

}

void utec::first::linked_list_t::push_back(int value) {
    auto new_node = new node{value, nullptr};
    if(head == nullptr){
        head = tail = new_node;
        size++;
    }
    else{
        tail->next_node = new_node;
        tail = new_node;
        size++;
    }
}

void utec::first::linked_list_t::insert(size_t index, int value) {
    if(head == tail){
        head = new node{value, tail};
        if(tail == nullptr)
            head = tail;
    }
    else{
        auto aux = getNode(index-1);
        aux->next_node = new node{value, getNode(index)};
    }
    size++;
}

void utec::first::linked_list_t::pop_front() {
    if (head == tail) {
        delete head;
        head = tail = nullptr;
        size = 0;
    }
    else {
        auto next = head->next_node;
        delete head;
        head = next;
        size--;
    }
}

void utec::first::linked_list_t::pop_back() {
    if (head == tail) {
        delete head;
        head = tail = nullptr;
        size = 0;
    } else{
        auto aux = getNode(size - 2);
        delete tail;
        tail = aux;
        aux->next_node = nullptr;
        size--;
    }
}

void utec::first::linked_list_t::erase(size_t index) {
    if (head == tail){
        delete head;
        head = tail = nullptr;
    }
    else if(index == 0){
        this->pop_front();
    }
    else if(index == size-1){
        this->pop_back();
    }
    else{
        auto aux = getNode(index + 1);
        delete getNode(index);
        getNode(index-1)->next_node = aux;
        size--;
    }
}

int &utec::first::linked_list_t::item(size_t index) {
    auto actual = head;
    while (index--)
        actual = actual->next_node;
    return actual->data;
}

const int &utec::first::linked_list_t::item(size_t index) const {
    auto actual = head;
    while (index--)
        actual = actual->next_node;
    return actual->data;
}

size_t utec::first::linked_list_t::size_linked_list() const {
    return size;
}

utec::node *utec::first::linked_list_t::getNode(size_t index) {
    auto actual = head;
    size_t  i = 0;
    while (i < index){
        actual = actual->next_node;
        i++;
    }
    return actual;
}

utec::node * utec::first::linked_list_t::getHead() const {
    return head;
}