#include <string>
#include <ostream>
#include <iostream>
#include "SequenceNode.h"

SequenceNode::SequenceNode() : next(nullptr), prev(nullptr)
{
    std::string empty_string = "";
    this->set_item(empty_string);
    return;
}
/// parameterized constructor, next and prev are set to nullptr and the
/// node's element is set to the given value
SequenceNode::SequenceNode(std::string item_value) : next(nullptr), prev(nullptr)
{
    this->set_item(item_value);
    return;
}
SequenceNode::SequenceNode(int item_value) : next(nullptr), prev(nullptr)
{
    this->set_item(item_value);
    return;
}

// SequenceNode.item getter
std::string SequenceNode::get_item() const
{
    return this->item;
}
std::string& SequenceNode::get_item_ref() 
{ 
    return this->item;
}
// SequenceNode.item setter
void SequenceNode::set_item(std::string item_value)
{
    this->item = item_value;
    return;
}
// SequenceNode.item setter for int
void SequenceNode::set_item(int item_value)
{
    this->item = std::to_string(item_value);
    return;
}
// SequenceNode.next getter
SequenceNode* SequenceNode::get_next() const
{
    return this->next;
}
// SequenceNode.next setter
void SequenceNode::set_next(SequenceNode* next_value)
{
    this->next = next_value;
    return;
}
// SequenceNode.next getter
SequenceNode* SequenceNode::get_prev() const
{
    return this->prev;
}
// SequenceNode.prev setter
void SequenceNode::set_prev(SequenceNode* prev_value)
{
    this->prev = prev_value;
    return;
}
// What happens when you go sequence[i] = string
SequenceNode& SequenceNode::operator=(const std::string& item_value)
{
    this->set_item(item_value);
    return *this;
}
// What happens when you go sequence[i] = int
SequenceNode& SequenceNode::operator=(const int item_value)
{
    this->set_item(item_value);
    return *this;
}
SequenceNode& SequenceNode::operator=(const SequenceNode& sn)
{
    this->set_item(sn.get_item());
    this->set_next(sn.get_next());
    this->set_prev(sn.get_prev());
    return *this;
}
std::ostream& operator<<(std::ostream& os, const SequenceNode& s)
{
    os << "{item: \"" << s.get_head()->get_item() << "\", next: \"" << s.get_next()->get_item() << "\", prev: \"" << s.get_prev()->get_item() << "\"}"
    return os;
}