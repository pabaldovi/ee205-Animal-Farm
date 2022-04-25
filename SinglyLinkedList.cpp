///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_13a_animal_farm_3 - EE 205 - Spr 2022
///
/// @file SinglyLinkedList.cpp
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <iostream>
#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList() {
    assert(validate());
}

void SinglyLinkedList::push_front(Node *newNode) {
    assert(validate());
    assert(newNode != nullptr);
    assert(!isIn(newNode));

    if (head != nullptr) {
        newNode -> next = head;
        head = newNode;
    } else {
         newNode -> next = nullptr;
         head = newNode;
    }

    count++;
    assert(validate());
}

Node* SinglyLinkedList::pop_front() noexcept {
    assert(validate());

    if (head == nullptr)
        return nullptr;

    Node *temp = head;

    if (head -> next != nullptr)
        head = head -> next;
    else
        head = nullptr;

    temp -> next = nullptr;
    count--;

    assert(validate());
    return temp;
}

void SinglyLinkedList::insert_after(Node *currentNode, Node *newNode) {
    assert(validate());

    assert(currentNode != nullptr);
    assert(isIn(currentNode));
    assert(newNode != nullptr);
    assert(!isIn(newNode));
    assert(head != nullptr);

    newNode -> next = currentNode -> next;
    currentNode -> next = newNode;
    count++;

    assert(validate());
}

void SinglyLinkedList::dump() const noexcept {
    std::cout << "SinglyLinkedList: head=[" << head << "]" << std::endl;
    for (Node *temp = head; temp != nullptr; temp = temp -> next)
        temp -> dump();
}

bool SinglyLinkedList::validate() const noexcept {
    if (head == nullptr)
        assert(List::size() == 0);

    if (head != nullptr) {
        assert(List::size() > 0);
        for (Node *temp = head; temp != nullptr; temp = temp -> next)
            temp -> validate();
    }

    return true;
}