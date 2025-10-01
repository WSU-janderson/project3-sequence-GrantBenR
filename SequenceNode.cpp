#include <string>
#include <ostream>
#include <iostream>
#include "SequenceNode.h"

/// default constructor, next and prev are set to nullptr and the node's
/// element is set to the empty string
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
SequenceNode::SequenceNode(int item_value, SequenceNode* next_value, SequenceNode* prev_value) : item(item_value), next(next_value), prev(prev_value)
{
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
    // make sure the new next value, has a prev value of the current node
    if (this->get_next() != nullptr)
    {
        // if old next has properties copy them
        this->next = new SequenceNode(next_value->get_item(), this->get_next()->get_next(), this*);
    }
    else
    {
        // if old next does not have properties, use nullptr
        this->next = new SequenceNode(next_value->get_item(), nullptr, this*);
    }
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
    if (this->get_prev() != nullptr)
    {
        // if old prev has values, copy them
        this->prev = new SequenceNode(prev_value->get_item(), this*, this->get_prev()->get_prev());
    }
    else
    {
        // if old prev does not have values, use nullptr
        this->prev = new SequenceNode(prev_value->get_item(), this*, nullptr);
    }
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
    os << "{item: \"" << s.get_item();
    os << "\", next: \"";
    if (s.get_next() == nullptr) 
    {
        os << "nullptr";
    }
    else
    {
        os << s.get_next()->get_item();
    }
    os << "\", prev: \"";
    if (s.get_prev() == nullptr) 
    {
        os << "nullptr";
    }
    else
    {
        os << s.get_prev()->get_item();
    }
    os << "\"}";
    return os;
}