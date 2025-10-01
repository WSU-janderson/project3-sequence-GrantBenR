#include <iostream>
#include <ostream>
#include <string>
#include "SequenceNodeTest.h"
#include "Sequence.h"
#include "SequenceNode.h"

SequenceNodeTest::SequenceNodeTest() {}
// empty constructor for SequenceNode
bool SequenceNodeTest::TEST_SN_SequenceNode()
{
    std::cout << "- - SequenceNode::SequenceNode() - - " << std::endl;
    SequenceNode* test_node = new SequenceNode();
    std::cout << "Item: " << test_node->get_item() << std::endl;
    if (test_node->get_item() != "") 
    {
        std::cout << "Error: Item is not initialized to: \"\"." << std::endl;
        std::cout << "- - - - FAIL - - - -" << std::endl;
        return false;
    }
    std::cout << "Next: " << test_node->get_next() << std::endl;
    if (test_node->get_next() != nullptr) {
        std::cout << "Error: Next is not initialized to: nullptr." << std::endl;
        std::cout << "- - - - FAIL - - - -" << std::endl;
        return false;
    }
    std::cout << "Prev: " << test_node->get_prev() << std::endl;
    if (test_node->get_prev() != nullptr) {
        std::cout << "Error: Prev is not initialized to: nullptr." << std::endl;
        std::cout << "- - - - FAIL - - - -" << std::endl;
        return false;
    }
    delete test_node;
    std::cout << "- - - - PASS - - - -" << std::endl;
    std::cout << std::endl;
    return true;
}
// parameterized constructor with string
bool SequenceNodeTest::TEST_SN_SequenceNode_string()
{
    std::cout << "- - SequenceNode::SequenceNode(string) - - " << std::endl;
    SequenceNode* test_node = new SequenceNode("test");
    std::cout << "Item: " << test_node->get_item() << std::endl;
    if (test_node->get_item() != "test") 
    {
        std::cout << "Error: Item is not initialized to: \"test\"." << std::endl;
        std::cout << "- - - - FAIL - - - -" << std::endl;
        return false;
    }
    std::cout << "Next: " << test_node->get_next() << std::endl;
    if (test_node->get_next() != nullptr) {
        std::cout << "Error: Next is not initialized to: nullptr." << std::endl;
        std::cout << "- - - - FAIL - - - -" << std::endl;
        return false;
    }
    std::cout << "Prev: " << test_node->get_prev() << std::endl;
    if (test_node->get_prev() != nullptr) {
        std::cout << "Error: Prev is not initialized to: nullptr." << std::endl;
        std::cout << "- - - - FAIL - - - -" << std::endl;
        return false;
    }
    delete test_node;
    std::cout << "- - - - PASS - - - -" << std::endl;
    std::cout << std::endl;
    return true;
}
// parameterized constructor with int
bool SequenceNodeTest::TEST_SN_SequenceNode_int()
{
    std::cout << "- - SequenceNode::SequenceNode(int) - - " << std::endl;
    SequenceNode* test_node = new SequenceNode(5);
    std::cout << "Item: " << test_node->get_item() << std::endl;
    if (test_node->get_item() != "5")
    {
        std::cout << "Error: Item is not initialized to: \"5\"." << std::endl;
        std::cout << "- - - - FAIL - - - -" << std::endl;
        return false;
    }
    std::cout << "Next: " << test_node->get_next() << std::endl;
    if (test_node->get_next() != nullptr) {
        std::cout << "Error: Next is not initialized to: nullptr." << std::endl;
        std::cout << "- - - - FAIL - - - -" << std::endl;
        return false;
    }
    std::cout << "Prev: " << test_node->get_prev() << std::endl;
    if (test_node->get_prev() != nullptr) {
        std::cout << "Error: Prev is not initialized to: nullptr." << std::endl;
        std::cout << "- - - - FAIL - - - -" << std::endl;
        return false;
    }
    delete test_node;
    std::cout << "- - - - PASS - - - -" << std::endl;
    std::cout << std::endl;
    return true;
}
// getter for item
bool SequenceNodeTest::TEST_SN_get_item()
{
    std::cout << "- - SequenceNode::get_item() - - " << std::endl;
    SequenceNode* test_node = new SequenceNode("test");
    std::cout << "Item: " << test_node->get_item() << std::endl;
    if (test_node->get_item() != "test") 
    {
        std::cout << "Error: get_item() did not return: \"test\"." << std::endl;
        std::cout << "- - - - FAIL - - - -" << std::endl;
        return false;
    }
    delete test_node;
    std::cout << "- - - - PASS - - - -" << std::endl;
    std::cout << std::endl;
    return true;
}
// getter for item reference
bool SequenceNodeTest::TEST_SN_get_item_ref()
{
    std::cout << "- - SequenceNode::get_item_ref() - - " << std::endl;
    SequenceNode* test_node = new SequenceNode("test");
    std::cout << "Item: " << test_node->get_item_ref() << std::endl;
    if (test_node->get_item_ref() != "test") 
    {
        std::cout << "Error: get_item_ref() did not return: \"test\"." << std::endl;
        std::cout << "- - - - FAIL - - - -" << std::endl;
        return false;
    }
    delete test_node;
    std::cout << "- - - - PASS - - - -" << std::endl;
    std::cout << std::endl;
    return true;
}
// setter for item with string
bool SequenceNodeTest::TEST_SN_set_item_string()
{
    std::cout << "- - SequenceNode::set_item(string) - - " << std::endl;
    SequenceNode* test_node = new SequenceNode("test");
    test_node->set_item("new_test");
    std::cout << "Item: " << test_node->get_item() << std::endl;
    if (test_node->get_item() != "new_test") 
    {
        std::cout << "Error: Item is not set to: \"new_test\"." << std::endl;
        std::cout << "- - - - FAIL - - - -" << std::endl;
        return false;
    }
    delete test_node;
    std::cout << "- - - - PASS - - - -" << std::endl;
    std::cout << std::endl;
    return true;
}
// setter for item with int
bool SequenceNodeTest::TEST_SN_set_item_int()
{
    std::cout << "- - SequenceNode::set_item(int) - - " << std::endl;
    SequenceNode* test_node = new SequenceNode(5);
    test_node->set_item(10);
    std::cout << "Item: " << test_node->get_item() << std::endl;
    if (test_node->get_item() != "10") 
    {
        std::cout << "Error: Item is not set to: \"10\"." << std::endl;
        std::cout << "- - - - FAIL - - - -" << std::endl;
        return false;
    }
    delete test_node;
    std::cout << "- - - - PASS - - - -" << std::endl;
    std::cout << std::endl;
    return true;
}
// getter for next
bool SequenceNodeTest::TEST_SN_get_next()
{
    std::cout << "- - SequenceNode::get_next() - - " << std::endl;
    SequenceNode* test_node = new SequenceNode("test");
    std::cout << "Next: " << test_node->get_next() << std::endl;
    if (test_node->get_next() != nullptr) {
        std::cout << "Error: get_next() did not return: nullptr." << std::endl;
        std::cout << "- - - - FAIL - - - -" << std::endl;
        return false;
    }
    delete test_node;
    std::cout << "- - - - PASS - - - -" << std::endl;
    std::cout << std::endl;
    return true;
}
// setter for next
bool SequenceNodeTest::TEST_SN_set_next()
{
    std::cout << "- - SequenceNode::set_next() - - " << std::endl;
    SequenceNode* test_node = new SequenceNode("test");
    SequenceNode* next_node = new SequenceNode("next");
    test_node->set_next(next_node);
    std::cout << "Next: " << &(test_node->get_next()) << std::endl;
    if (test_node->get_next() != next_node) {
        std::cout << "Error: Next is not set to the correct node." << std::endl;
        std::cout << "- - - - FAIL - - - -" << std::endl;
        return false;
    }
    delete test_node;
    delete next_node;
    std::cout << "- - - - PASS - - - -" << std::endl;
    std::cout << std::endl;
    return true;
}
// getter for prev
bool SequenceNodeTest::TEST_SN_get_prev()
{
    std::cout << "- - SequenceNode::get_prev() - - " << std::endl;
    SequenceNode* test_node = new SequenceNode("test");
    std::cout << "Prev: " << test_node->get_prev() << std::endl;
    if (test_node->get_prev() != nullptr) {
        std::cout << "Error: get_prev() did not return: nullptr." << std::endl;
        std::cout << "- - - - FAIL - - - -" << std::endl;
        return false;
    }
    delete test_node;
    std::cout << "- - - - PASS - - - -" << std::endl;
    std::cout << std::endl;
    return true;
}   
// setter for prev
bool SequenceNodeTest::TEST_SN_set_prev()
{
    std::cout << "- - SequenceNode::set_prev() - - " << std::endl;
    SequenceNode* test_node = new SequenceNode("test");
    SequenceNode* prev_node = new SequenceNode("prev");
    test_node->set_prev(prev_node);
    std::cout << "Prev: " << test_node->get_prev() << std::endl;
    if (test_node->get_prev() != prev_node) {
        std::cout << "Error: Prev is not set to the correct node." << std::endl;
        std::cout << "- - - - FAIL - - - -" << std::endl;
        return false;
    }
    delete test_node;
    delete prev_node;
    std::cout << "- - - - PASS - - - -" << std::endl;
    std::cout << std::endl;
    return true;
}
// operator= with string
bool SequenceNodeTest::TEST_SN_operator_equals_string()
{
    std::cout << "- - SequenceNode::operator=(string) - - " << std::endl;
    SequenceNode* test_node = new SequenceNode("test");
    *test_node = "new_test";
    std::cout << "Item: " << test_node->get_item() << std::endl;
    if (test_node->get_item() != "new_test") 
    {
        std::cout << "Error: Item is not set to: \"new_test\"." << std::endl;
        std::cout << "- - - - FAIL - - - -" << std::endl;
        return false;
    }
    delete test_node;
    std::cout << "- - - - PASS - - - -" << std::endl;
    std::cout << std::endl;
    return true;
}
// operator= with int
bool SequenceNodeTest::TEST_SN_operator_equals_int()
{
    std::cout << "- - SequenceNode::operator=(int) - - " << std::endl;
    SequenceNode* test_node = new SequenceNode(5);
    *test_node = 10;
    std::cout << "Item: " << test_node->get_item() << std::endl;
    if (test_node->get_item() != "10") 
    {
        std::cout << "Error: Item is not set to: \"10\"." << std::endl;
        std::cout << "- - - - FAIL - - - -" << std::endl;
        return false;
    }
    delete test_node;
    std::cout << "- - - - PASS - - - -" << std::endl;
    std::cout << std::endl;
    return true;
}
// operator= with SequenceNode
bool SequenceNodeTest::TEST_SN_operator_equals_SequenceNode()
{
    std::cout << "- - SequenceNode::operator=(SequenceNode) - - " << std::endl;
    SequenceNode* test_node = new SequenceNode("test");
    SequenceNode* other_node = new SequenceNode("other");
    *test_node = *other_node;
    std::cout << "Item: " << test_node->get_item() << std::endl;
    if (test_node->get_item() != "other") 
    {
        std::cout << "Error: Item is not set to: \"other\"." << std::endl;
        std::cout << "- - - - FAIL - - - -" << std::endl;
        return false;
    }
    delete test_node;
    delete other_node;
    std::cout << "- - - - PASS - - - -" << std::endl;
    std::cout << std::endl;
    return true;
}
// operator<< for ostream
bool SequenceNodeTest::TEST_SN_operator_ostream()
{
    std::cout << "- - SequenceNode::operator<<(ostream) - - " << std::endl;
    SequenceNode* test_node = new SequenceNode("test");
    std::cout << "Node: " << *test_node << std::endl;
    delete test_node;
    std::cout << "- - - - PASS - - - -" << std::endl;
    std::cout << std::endl;
    return true;
}