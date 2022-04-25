///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_13a_animal_farm_3 - EE 205 - Spr 2022
///
/// @file Node.cpp
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "Node.h"
#include "config.h"

bool Node::compareByAddress(const Node *node1, const Node *node2) {
    return node1 > node2;
}

void Node::dump() const {
    FORMAT_LINE_FOR_DUMP("Node", "this") << this << std::endl;
    FORMAT_LINE_FOR_DUMP("Node", "next") << next << std::endl;
}

bool Node::validate() const noexcept {
    //next should not point to itself
    if (next == next -> next)
        return false;

    //nullptr is a valid value for next
    if (next == nullptr)
        return true;

    //true for all other cases
    return true;
}

bool Node::operator>(const Node &rightSide) {
    return compareByAddress(this, &(Node&)rightSide);
}
