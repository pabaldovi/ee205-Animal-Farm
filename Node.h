///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_13a_animal_farm_3 - EE 205 - Spr 2022
///
/// @file Node.h
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

class Node {
    private:
        friend class List;
        friend class SinglyLinkedList;

    protected:
        /*static protected member function*/
        static bool compareByAddress(const Node *node1, const Node *node2);

        /*protected attribute*/
        Node *next = nullptr;

    public:
        virtual void dump() const;
        virtual bool validate() const noexcept;
        virtual bool operator>(const Node &rightSide);
};