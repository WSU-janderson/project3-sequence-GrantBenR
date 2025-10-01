#include "SequenceNode.h"
#include <string>
#include <ostream>
SequenceNode::SequenceNode()
{
    this->item("");
    this->next(nullptr);
    this->prev(nullptr);
}
/// parameterized constructor, next and prev are set to nullptr and the
/// node's element is set to the given value
SequenceNode::SequenceNode(std::string item, SequenceNode* next, SequenceNode* prev) : item(item), next(next), prev(prev){}

// SequenceNode.item getter
std::string SequenceNode::get_item()
{
    return this->item;
}
// SequenceNode.item setter
void SequenceNode::set_item(std::string item_value)
{
    this->item = item_value;
    return;
}
// SequenceNode.next getter
SequenceNode* SequenceNode::get_next()
{
    return this->next;
}
// SequenceNode.next setter
void SequenceNode::set_next(SequenceNode* next_value)
{
    this->item = item_value;
    return;
}
// SequenceNode.next getter
SequenceNode* SequenceNode::get_prev()
{
    return this->prev;
}
// SequenceNode.prev setter
void SequenceNode::set_prev(SequenceNode* prev_value)
{
    this->item = item_value;
    return;
}