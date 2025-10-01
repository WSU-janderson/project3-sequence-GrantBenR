#include "Sequence.h"
#include "SequenceNode.h"
#include <string>
#include <ostream>
#include <exception>

// Creates an empty sequence (numElts == 0) or a sequence of numElts items
// indexed from 0 ... (numElts - 1).
Sequence::Sequence(size_t sz = 0) : sequence_size(sz), head(nullptr), tail(nullptr)
{
    if (sz < 0) 
    {
        throw exception();
    }
    else if (sz == 0)
    {
        return;
    }
    else
    {
        SequenceNode* current_node;
        SequenceNode* next_node;

        current_node = new SequenceNode(nullptr,nullptr,"");
        next_node = new SequenceNode(nullptr,current_node,"");
        current_node->next() = &next_node;
        
        this->head = &current_node;
        for (i = 0; i < (sz - 1); i++)
        {
            current_node = new SequenceNode(nullptr,next_node,"");
            next_node = new SequenceNode(nullptr,current_node,"");
            current_node->next() = &next_node;
            this->tail = &next_node;
        }
        return;
    }
    
    
}
// Creates a (deep) copy of sequence s
Sequence::Sequence(const Sequence& s)
{
    if (s.sequence_size < 0) 
    {
        throw exception();
    }
    else
    {
        this->sequence_size = s.sequence_size;
        this->head = s.head;
        this->tail = s.tail; 
    }
    return;
}

// Getter for size
size_t Sequence::size() const
{
    return this->sequence_size;
}
// Getter for head
SequenceNode* Sequence::get_head() const
{
    return this->head;
}
// Setter for head
void Sequence::set_head(SequenceNode* head_value)
{
    this->head = head_value;
    return;
}
// Getter for tail
SequenceNode* Sequence::get_tail() const
{
    return this->tail;
}
// Setter for tail
void Sequence::set_tail(SequenceNode* tail_value)
{
    this->tail = turn_value;
    return;
}

// Destroys all items in the sequence and release the memory
// associated with the sequence
Sequence::~Sequence()
{
    this->clear();
    delete(this);
    return;
}
// The current sequence is released and replaced by a (deep) copy of sequence
// s. A reference to the copied sequence is returned (return *this;).
Sequence& Sequence::operator=(const Sequence& s)
{
    if (s.sequence_size >= 0) 
    {
        this->sequence_size = s.sequence_size;
        this->head = s.head;
        this->tail = s.tail;
        return *this;
    }
    else
    {
        throw exception();
        return nullptr;
    }
    
}
// The position satisfies ( position >= 0 && position <= last_index() ).
// The return value is a reference to the item at index position in the
// sequence. Throws an exception if the position is outside the bounds
// of the sequence
std::string& Sequence::operator[](size_t position)
{
    if ((position >= 0) && (position <= this->last_index())) 
    {
        SequenceNode* current_node;
        SequenceNode* next_node;
        int index = 0;

        current_node = this->head;
        NextNode = this->head->next();
        while (NextNode != nullptr)
        {
            current_node = &NextNode;
            NextNode = current_node->next();
            index += 1;
        } 
    }
    else
    {
        throw exception();
    }
    return;
}
// The value of string item is append to the sequence.
void Sequence::push_back(std::string item)
{
    SequenceNode* new_node = new SequenceNode(nullptr, this->tail, item);
    this->tail->next() = &new_node;
    this->tail = &new_node;
    return;
}
// The value of int item is append to the sequence.
void Sequence::push_back(int item)
{
    this->push_back(static_cast<std::string>(item))
    return;
}
// The item at the end of the sequence is deleted and size of the sequence is
// reduced by one. If sequence was empty, throws an exception
void Sequence::pop_back()
{
    if (!(this->empty())) 
    {
        
        int current_size = this->sequence_size;
        this->sequence_size = (current_size - 1);

        SequenceNode* new_tail = this->tail->prev();
        delete(this->tail);
        this->tail = &new_tail;
    }
    else
    {
        throw exception();
    }
    return;
}
// The position satisfies ( position >= 0 && position <= last_index() ). The
// value of item is inserted at position and the size of sequence is increased
// by one. Throws an exceptionif the position is outside the bounds of the
// sequence
void Sequence::insert(size_t position, std::string item)
{
    if ((position >= 0) && (position <= this->last_index())) 
    {
        int current_size = this->sequence_size;
        this->sequence_size = (current_size + 1);
    }
    else
    {
        throw exception();
    }
    return;
}
void Sequence::insert(size_t position, int item)
{
    this->insert(static_cast<std::string>(item))
    return;
}
// Returns the first element in the sequence. If the sequence is empty, throw an exception.
std::string Sequence::front() const
{
    if (!(this->empty())) 
    {
        return this->head->item();
    }
    else
    {
        throw exception();
        return "";
    }
    
}
// Return the last element in the sequence. If the sequence is empty, throw an exception.
std::string Sequence::back() const
{
    if (this->empty()) 
    {
        throw exception();
    }
    return this->tail->item();
}
// Return true if the sequence has no elements, otherwise false.
bool Sequence::empty() const
{
    if (this->sequence_size > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
// All items in the sequence are deleted and the memory associated with the
// sequence is released, resetting the sequence to an empty state that can have
// items re-inserted.
void Sequence::clear()
{
    SequenceNode* curr_tail;
    SequenceNode* prev_node;

    curr_tail = this->tail;
    prev_node = curr_tail->prev();
    delete(curr_tail);
    while (prev_node != nullptr)
    {
        curr_tail = &prev_node;
        prev_node = curr_tail->prev();
        delete(curr_tail)
    }
    this->head = nullptr;
    this->tail = nullptr;
    this->sequence_size = 0;
    return;
}
// The item at position is removed from the sequence, and the memory
// is released. If called with an invalid position throws an exception.
void Sequence::erase(size_t position)
{
    if ((position >= 0) && (position <= this->last_index())) 
    {
        SequenceNode* node_to_erase = this[position];
        // Get previous and next node of the node being erased
        SequenceNode* node_next = node_to_erase->next();
        SequenceNode* node_prev = node_to_erase->prev();
        // Connect the two nodes so that the erase doesn't create a gap
        node_next->prev()() = &node_prev;
        node_prev->next()() = &node_next;
        // Remove old node from memory
        delete(node_to_erase);
        // reduce size
        int current_size = this->sequence_size;
        this->sequence_size -= 1;
    }
    else
    {
        throw exception();
    }
    return;
}
// The items in the sequence at ( position ... (position + count - 1) ) are
// deleted and their memory released. If called with invalid position and/or
// count throws an exception.
void Sequence::erase(size_t position, size_t count)
{
    int end_index = (position + count - 1);
    SequenceNode* current_node_to_erase;

    if ((position <= (this->sequence_size - count - 1)) && (count > 0))
    {
        for (index = 0; index < this->sequence_size; index++)
        {
            current_node = this->head;
            NextNode = this->head->next();
            if ((index >= position) && (index < end_index))
            {
                delete(current_node);
            }
        }
    }
    else
    {
        throw exception();
    }
    return;
}
int Sequence::last_index()
{
    return (this->sequence_size - 1);
}
// Outputs all elements (ex: <4, 8, 15, 16, 23, 42>) as a string to the output
// stream. This is *not* a method of the Sequence class, but instead it is a
// friend function
friend std::ostream& operator<<(std::ostream& os, const Sequence& s)
{
    SequenceNode* current_node;
    SequenceNode* next_node;
    
    // format: <item, item, item>
    // If item is null print "null"
    os << "<";
    
    // Initial head cell case
    current_node = s.head;
    NextNode = s.head->get_next();
    if (current_node->get_item().isEmpty())
    {
        os << "null";
    }
    else
    {
        os << current_node->get_item();
    }
    if (NexNode != nullptr)
    {
        os << ",";
    }

    // Case for rest of nodes
    while (NextNode != nullptr)
    {
        current_node = &NextNode;
        NextNode = current_node->get_next();
        if (current_node->item().isEmpty())
        {
            os << "null";
        }
        else
        {
            os << current_node->get_item();
        }
        os << ",";
    }
    os << ">";

    return os;
}