#include <string>
#include <ostream>
#include "SequenceNode.h"

/// default constructor, next and prev are set to nullptr and the node's
/// element is set to the empty string
SequenceNode::SequenceNode() : next(nullptr), prev(nullptr)
{
    this->set_item("");
}
/// parameterized constructor, next and prev are set to nullptr and the
/// node's element is set to the given value
SequenceNode::SequenceNode(std::string item_value) : next(nullptr), prev(nullptr)
{
    this->set_item(item_value);
}
SequenceNode::SequenceNode(int item_value) : next(nullptr), prev(nullptr)
{
    this->set_item(item_value);
}
SequenceNode::SequenceNode(std::string item_value, SequenceNode* next_value, SequenceNode* prev_value) : next(next_value), prev(prev_value)
{
    this->set_item(item_value);
}
SequenceNode::SequenceNode(int item_value, SequenceNode* next_value, SequenceNode* prev_value) : next(next_value), prev(prev_value)
{
    this->set_item(item_value);
}
SequenceNode::SequenceNode(const SequenceNode& s) : next(nullptr), prev(nullptr)
{
    *this = s;
}
SequenceNode::~SequenceNode()
{
    delete(this);
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
}
// SequenceNode.item setter for int
void SequenceNode::set_item(int item_value)
{
    this->item = std::to_string(item_value);
}
// SequenceNode.next getter
SequenceNode* SequenceNode::get_next() const
{
    return this->next;
}
// SequenceNode.next setter
void SequenceNode::set_next(SequenceNode* next_value)
{
    if (next_value == nullptr)
    {
        next_value = new SequenceNode();
    }
    next_value->prev = this;
    this->next = next_value;
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
        this->prev = new SequenceNode(prev_value->get_item(), this, this->get_prev()->get_prev());
    }
    else
    {
        // if old prev does not have values, use nullptr
        this->prev = new SequenceNode(prev_value->get_item(), this, nullptr);
    }
}
// What happens when you go sequence[i] = string
SequenceNode& SequenceNode::operator=(const std::string& item_value)
{
    this->set_item(item_value);
    return *this;
}
// What happens when you go sequence[i] = int
/**
 *
 * @param item_value int
 * @return this SequenceNode&
 */
SequenceNode& SequenceNode::operator=(const int item_value)
{
    this->set_item(item_value);
    return *this;
}
SequenceNode& SequenceNode::operator=(const SequenceNode& sn)
{
    this->set_item(sn.get_item());
    this->next = sn.next;
    this->prev = sn.prev;
    return *this;
}
bool SequenceNode::operator==(const SequenceNode* sn) const 
{
    if (sn != nullptr)
    {
        bool are_items_equal = (this->get_item() == sn->get_item());
        bool are_next_equal = (this->get_next() == sn->get_next());
        bool are_prev_equal = (this->get_prev() == sn->get_prev());
        return (are_items_equal && are_next_equal && are_prev_equal);
    }
    else
    {
        return false;
    }
    
}
bool SequenceNode::operator!=(const SequenceNode* sn) const 
{
    if (sn != nullptr)
    {
        const bool are_items_equal = (this->get_item() == sn->get_item());
        const bool are_next_equal = (this->get_next() == sn->get_next());
        const bool are_prev_equal = (this->get_prev() == sn->get_prev());
        return !(are_items_equal && are_next_equal && are_prev_equal);
    }
    else
    {
        return true;
    }
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