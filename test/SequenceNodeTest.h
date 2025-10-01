class SequenceNodeTest
{
public:
    bool TEST_SequenceNode();// empty constructor
    bool TEST_SequenceNode_string();// parameterized constructor with string
    bool TEST_SequenceNode_int();// parameterized constructor with int
    bool TEST_get_item();// getter for item
    bool TEST_get_item_ref();// getter for item reference
    bool TEST_set_item_string();// setter for item with string
    bool TEST_set_item_int();// setter for item with int
    bool TEST_get_next();// getter for next
    bool TEST_set_next();// setter for next
    bool TEST_get_prev();// getter for prev
    bool TEST_set_prev();// setter for prev
    bool TEST_operator_equals_string();// operator= with string
    bool TEST_operator_equals_int();// operator= with int
    bool TEST_operator_equals_SequenceNode();// operator= with SequenceNode
    bool TEST_operator_ostream();// operator<< for ostream
};