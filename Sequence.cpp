#include "Sequence.h"
#include "SequenceNode.h"
#include <string>
#include <ostream>
#include <exception>

// Creates an empty sequence (numElts == 0) or a sequence of numElts items
// indexed from 0 ... (numElts - 1).
Sequence::Sequence(size_t sz = 0) : size(sz), head(nullptr), tail(nullptr)
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
    if (s.size < 0) 
    {
        throw exception();
    }
    else
    {
        this->size = s.size;
        this->head = s.head;
        this->tail = s.tail; 
    }
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
    if (s.size >= 0) 
    {
        this->size = s.size;
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
// The value of item is append to the sequence.
void Sequence::push_back(std::string item)
{
    SequenceNode* new_node = new SequenceNode(nullptr, this->tail, item);
    this->tail->next() = &new_node;
    this->tail = &new_node;
    return;
}
// The item at the end of the sequence is deleted and size of the sequence is
// reduced by one. If sequence was empty, throws an exception
void Sequence::pop_back()
{
    if (!(this->empty())) 
    {
        
        int current_size = this->size;
        this->size = (current_size - 1);

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
        int current_size = this->size;
        this->size = (current_size + 1);
    }
    else
    {
        throw exception();
    }
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
    if (this->size > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
// Return the number of elements in the sequence.
size_t Sequence::size() const
{
    return this->size;
}
// Return the head* of the sequence
SequenceNode* Sequence::head() const
{
    return this->head;
}
// Return the tail* of the sequence
SequenceNode* Sequence::tail() const
{
    return this->tail;
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
    this->size = 0;
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
        int current_size = this->size;
        this->size -= 1;
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

    if ((position <= (this->size - count - 1)) && (count > 0))
    {
        for (index = 0; index < this->size; index++)
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
    return (this->size - 1);
}
// Outputs all elements (ex: <4, 8, 15, 16, 23, 42>) as a string to the output
// stream. This is *not* a method of the Sequence class, but instead it is a
// friend function
friend ostream& operator<<(std::ostream& os, const Sequence& s)
{
    SequenceNode* current_node;
    SequenceNode* next_node;
    
    // format: <item, item, item>
    // If item is null print "null"
    os << "<";
    
    // Initial head cell case
    current_node = s.head;
    NextNode = s.head->next();
    if (current_node->item().isEmpty())
    {
        os << "null";
    }
    else
    {
        os << current_node->item();
    }
    if (NexNode != nullptr)
    {
        os << ",";
    }

    // Case for rest of nodes
    while (NextNode != nullptr)
    {
        current_node = &NextNode;
        NextNode = current_node->next();
        if (current_node->item().isEmpty())
        {
            os << "null";
        }
        else
        {
            os << current_node->item();
        }
        os << ",";
    }
    os << ">";

    return os;
}