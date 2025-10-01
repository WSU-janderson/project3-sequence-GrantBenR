#include <iostream>
#include <osstream>
#include <string>
#include "SequenceNodeTest.h"
#include "Sequence.h"
#include "SequenceNode.h"

// empty constructor
bool SequenceNodeTest::TEST_SequenceNode()
{
    std::cout << "- - SequenceNode::SequenceNode() - - " << std::endl;
    SequenceNode* test_node = new SequenceNode();
    delete test_node;
    return true;
}
// parameterized constructor with string
bool SequenceNodeTest::TEST_SequenceNode_string()
{
    std::cout << "- - SequenceNode::SequenceNode(string) - - " << std::endl;
    SequenceNode* test_node = new SequenceNode("test");
    delete test_node;
    return true;
}
// parameterized constructor with int
bool SequenceNodeTest::TEST_SequenceNode_int()
{
    std::cout << "- - SequenceNode::SequenceNode(int) - - " << std::endl;
    SequenceNode* test_node = new SequenceNode(5);
    delete test_node;
    return true;
}
// getter for item
bool SequenceNodeTest::TEST_get_item()
{
    std::cout << "- - SequenceNode::get_item() - - " << std::endl;
    SequenceNode* test_node = new SequenceNode("test");
    std::cout << "Item: " << test_node->get_item() << std::endl;
    delete test_node;
    return true;
}
// getter for item reference
bool SequenceNodeTest::TEST_get_item_ref()
{
    std::cout << "- - SequenceNode::get_item_ref() - - " << std::endl;
    SequenceNode* test_node = new SequenceNode("test");
    std::cout << "Item: " << test_node->get_item_ref() << std::endl;
    delete test_node;
    return true;
}
// setter for item with string
bool SequenceNodeTest::TEST_set_item_string()
{
    std::cout << "- - SequenceNode::set_item(string) - - " << std::endl;
    SequenceNode* test_node = new SequenceNode("test");
    test_node->set_item("new_test");
    std::cout << "Item: " << test_node->get_item() << std::endl;
    delete test_node;
    return true;
}
// setter for item with int
bool SequenceNodeTest::TEST_set_item_int()
{
    std::cout << "- - SequenceNode::set_item(int) - - " << std::endl;
    SequenceNode* test_node = new SequenceNode(5);
    test_node->set_item(10);
    std::cout << "Item: " << test_node->get_item() << std::endl;
    delete test_node;
    return true;
}
// getter for next
bool SequenceNodeTest::TEST_get_next()
{
    std::cout << "- - SequenceNode::get_next() - - " << std::endl;
    SequenceNode* test_node = new SequenceNode("test");
    std::cout << "Next: " << test_node->get_next() << std::endl;
    delete test_node;
    return true;
}
// setter for next
bool SequenceNodeTest::TEST_set_next()
{
    std::cout << "- - SequenceNode::set_next() - - " << std::endl;
    SequenceNode* test_node = new SequenceNode("test");
    SequenceNode* next_node = new SequenceNode("next");
    test_node->set_next(next_node);
    std::cout << "Next: " << test_node->get_next() << std::endl;
    delete test_node;
    delete next_node;
    return true;
}
// getter for prev
bool SequenceNodeTest::TEST_get_prev()
{
    std::cout << "- - SequenceNode::get_prev() - - " << std::endl;
    SequenceNode* test_node = new SequenceNode("test");
    std::cout << "Prev: " << test_node->get_prev() << std::endl;
    delete test_node;
    return true;
}   
// setter for prev
bool SequenceNodeTest::TEST_set_prev()
{
    std::cout << "- - SequenceNode::set_prev() - - " << std::endl;
    SequenceNode* test_node = new SequenceNode("test");
    SequenceNode* prev_node = new SequenceNode("prev");
    test_node->set_prev(prev_node);
    std::cout << "Prev: " << test_node->get_prev() << std::endl;
    delete test_node;
    delete prev_node;
    return true;
}
// operator= with string
bool SequenceNodeTest::TEST_operator_equals_string()
{
    std::cout << "- - SequenceNode::operator=(string) - - " << std::endl;
    SequenceNode* test_node = new SequenceNode("test");
    *test_node = "new_test";
    std::cout << "Item: " << test_node->get_item() << std::endl;
    delete test_node;
    return true;
}
// operator= with int
bool SequenceNodeTest::TEST_operator_equals_int()
{
    std::cout << "- - SequenceNode::operator=(int) - - " << std::endl;
    SequenceNode* test_node = new SequenceNode(5);
    *test_node = 10;
    std::cout << "Item: " << test_node->get_item() << std::endl;
    delete test_node;
    return true;
}
// operator= with SequenceNode
bool SequenceNodeTest::TEST_operator_equals_SequenceNode()
{
    std::cout << "- - SequenceNode::operator=(SequenceNode) - - " << std::endl;
    SequenceNode* test_node = new SequenceNode("test");
    SequenceNode* other_node = new SequenceNode("other");
    *test_node = *other_node;
    std::cout << "Item: " << test_node->get_item() << std::endl;
    delete test_node;
    delete other_node;
    return true;
}
// operator<< for ostream
bool SequenceNodeTest::TEST_operator_ostream()
{
    std::cout << "- - SequenceNode::operator<<(ostream) - - " << std::endl;
    SequenceNode* test_node = new SequenceNode("test");
    std::cout << "Item: " << *test_node << std::endl;
    delete test_node;
    return true;
}