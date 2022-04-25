///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_13a_animal_farm_3 - EE 205 - Spr 2022
///
/// @file List.cpp
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
#include <cassert>
#include "List.h"

bool List::empty() const noexcept {
    return head == nullptr;
}

unsigned int List::size() const noexcept {
    return List::count;
}

bool List::isIn(Node *aNode) const {
    if (aNode == nullptr)
        throw std::invalid_argument("Given node must not be null");

    Node *currentNode = head;

    while (currentNode != nullptr) {
        if (currentNode == aNode)
            return true;

        currentNode = currentNode -> next;
    }

    return false;
}

bool List::isSorted() const noexcept {
    if (count <= 1)
        return true;

    for (Node *temp = head; temp -> next != nullptr; temp = temp -> next) {
        if (*temp > *temp -> next)
            return false;

        return true;
    }

    return false;
}

Node* List::get_first() const noexcept {
    return head;
}

void List::deleteAllNodes() noexcept {
    assert( validate() );
    while( head != nullptr ) {
        pop_front();
    }
    #ifdef DEBUG
        std::cout << PROGRAM_NAME << ": All Nodes have been deleted" << std::endl ;
    #endif
    assert( validate() );
}

Node *List::get_next(const Node *currentNode) {
    if (currentNode == nullptr)
        throw std::invalid_argument("Current node is null");

    return currentNode -> next;
}