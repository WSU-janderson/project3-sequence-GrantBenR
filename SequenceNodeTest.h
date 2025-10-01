#ifndef SEQUENCE_NODE_TEST_H
#define SEQUENCE_NODE_TEST_H

#include <string>
#include <ostream>
#include "Sequence.h"
#include "SequenceNode.h"

class SequenceNodeTest
{
    private:
    public:
        bool TEST_SN_SequenceNode();// empty constructor
        bool TEST_SN_SequenceNode_string();// parameterized constructor with string
        bool TEST_SN_SequenceNode_int();// parameterized constructor with int
        bool TEST_SN_get_item();// getter for item
        bool TEST_SN_get_item_ref();// getter for item reference
        bool TEST_SN_set_item_string();// setter for item with string
        bool TEST_SN_set_item_int();// setter for item with int
        bool TEST_SN_get_next();// getter for next
        bool TEST_SN_set_next();// setter for next
        bool TEST_SN_get_prev();// getter for prev
        bool TEST_SN_set_prev();// setter for prev
        bool TEST_SN_operator_equals_string();// operator= with string
        bool TEST_SN_operator_equals_int();// operator= with int
        bool TEST_SN_operator_equals_SequenceNode();// operator= with SequenceNode
        bool TEST_SN_operator_ostream();// operator<< for ostream
};
#endif