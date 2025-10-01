#include "SequenceNode.h"
#include <string>
#include <ostream>
SequenceNode::SequenceNode()
{

}
/// parameterized constructor, next and prev are set to nullptr and the
/// node's element is set to the given value
SequenceNode::SequenceNode(std::string item) : next(nullptr), prev(nullptr), item(item)
{

}
std::string SequenceNode::item()
{
    return this->item;
}
SequenceNode* SequenceNode::next()
{
    return this->next;
}
SequenceNode* SequenceNode::prev()
{
    return this->prev;
}