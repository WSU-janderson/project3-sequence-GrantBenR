#include <string>
#include <ostream>
#include <utility>
#include "SequenceNode.h"

/**
 * default constructor, next and prev are set to nullptr and the node's
 * element is set to the empty string
 *
 * @return void
 */
SequenceNode::SequenceNode() : next(nullptr), prev(nullptr)
{
    this->set_item("");
}
/**
 * parameterized constructor, next and prev are set to nullptr and the
 * node's element is set to the given value
 *
 * @param item_value std::string
 * @return void
 */
SequenceNode::SequenceNode(std::string item_value) : next(nullptr), prev(nullptr)
{
    this->set_item(std::move(item_value));
}
/**
 * parameterized constructor, next and prev are set to nullptr and the
 * node's element is set to the given value
 *
 * @param item_value int
 * @return void
 */
SequenceNode::SequenceNode(const int item_value) : next(nullptr), prev(nullptr)
{
    this->set_item(item_value);
}
/**
 * Parameterized constructor that expects values for next and prev
 *
 * @param item_value std::string
 * @param next_value SequenceNode*
 * @param prev_value SequenceNode*
 * @return void
 */
SequenceNode::SequenceNode(std::string item_value, SequenceNode* next_value,
                           SequenceNode* prev_value) : next(next_value), prev(prev_value)
{
    this->set_item(std::move(item_value));
}
/**
 * Parameterized constructor that expects values for next and prev
 *
 * @param item_value int
 * @param next_value SequenceNode*
 * @param prev_value SequenceNode*
 * @return void
 */
SequenceNode::SequenceNode(int item_value, SequenceNode* next_value, SequenceNode* prev_value) : next(next_value),
    prev(prev_value)
{
    this->set_item(item_value);
}
/**
 * Deepcopy constructor for SequenceNode
 *
 * @param s SequenceNode&
 * @return void
 */
SequenceNode::SequenceNode(const SequenceNode& s) : next(nullptr), prev(nullptr)
{
    *this = s;
}

/**
 * Destructor for SequenceNode
 *
 * @return void
 */
SequenceNode::~SequenceNode()
{
    delete(this);
}

/**
 * SequenceNode.item getter
 *
 * @return item std::string
 */
std::string SequenceNode::get_item() const
{
    return this->item;
}

/**
 * SequenceNode.item& getter
 *
 * @return item_ref std::string&
 */
std::string& SequenceNode::get_item_ref()
{ 
    return this->item;
}

/**
 * SequenceNode.item setter
 *
 * @param item_value
 * @return void
 */
void SequenceNode::set_item(std::string item_value)
{
    this->item = std::move(item_value);
}
/**
 * SequenceNode.item setter for int
 *
 * @param item_value
 * @return void
 */
void SequenceNode::set_item(int item_value)
{
    this->item = std::to_string(item_value);
}

/**
 * SequenceNode.next getter
 *
 * @return next SequenceNode*
 */
SequenceNode* SequenceNode::get_next() const
{
    return this->next;
}

/**
 * SequenceNode.next setter
 *
 * @param next_value SequenceNode*
 * @return void
 */
void SequenceNode::set_next(SequenceNode* next_value)
{
    this->next = next_value;
    if (next_value != nullptr)
    {
        // Update this node's next node to point to this node
        this->get_next()->prev = this;
    }
}
/**
 * SequenceNode.next getter
 *
 * @return prev Sequence*
 */
SequenceNode* SequenceNode::get_prev() const
{
    return this->prev;
}
/**
 * SequenceNode.prev setter
 *
 * @param prev_value
 * @return void
 */
void SequenceNode::set_prev(SequenceNode* prev_value)
{
    this->prev = prev_value;
    if (prev_value != nullptr)
    {
        // Update this node's previous node to point to this node
        this->get_prev()->next = this;
    }
}

/**
 * What happens when you go sequence[i] = string
 *
 * @param item_value
 * @return updated_this SequenceNode&
 */
SequenceNode& SequenceNode::operator=(const std::string& item_value)
{
    this->set_item(item_value);
    return *this;
}

/**
 * Set SequenceNode.item to item_value
 *
 * @param item_value int
 * @return this SequenceNode&
 */
SequenceNode& SequenceNode::operator=(const int item_value)
{
    this->set_item(item_value);
    return *this;
}
/**
 * Set SequenceNode.item to item_value
 *
 * @param sn SequenceNode&
 * @return updated_this SequenceNode&
 */
SequenceNode& SequenceNode::operator=(const SequenceNode& sn)
{
    this->item = sn.get_item();
    this->next = sn.get_next();
    this->prev = sn.get_prev();
    return *this;
}
/**
 * Boolean comparison for SequenceNodes
 *
 * @param sn SequenceNode*
 * @return are_nodes_equal bool
 */
bool SequenceNode::operator==(const SequenceNode* sn) const
{
    if (sn != nullptr)
    {
        const bool are_items_equal = (this->get_item() == sn->get_item());
        const bool are_next_equal = (this->get_next() == sn->get_next());
        const bool are_prev_equal = (this->get_prev() == sn->get_prev());
        return (are_items_equal && are_next_equal && are_prev_equal);
    }
    else
    {
        return false;
    }
    
}
/**
 * Boolean inequality comparison for SequenceNode
 *
 * @param sn SequenceNode*
 * @return are_nodes_unequal bool
 */
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

/**
 * Friend << function for SequenceNode that outputs node in json format
 *
 * @param os ostream&
 * @param sn SequenceNode
 * @return new_ostream
 */
std::ostream& operator<<(std::ostream& os, const SequenceNode* sn)
{
    if (sn != nullptr)
    {
        os << " {item: \"" << sn->get_item();
        os << "\", next: \"";
        if (sn->get_next() == nullptr)
        {
            os << "nullptr";
        }
        else
        {
            os << sn->get_next()->get_item();
        }
        os << "\", prev: \"";
        if (sn->get_prev() == nullptr)
        {
            os << "nullptr";
        }
        else
        {
            os << sn->get_prev()->get_item();
        }
        os << "\"}";

    }
    else
    {
        os << "nullptr";
    }
    return os;
}