#include "Sequence.h"
#include "SequenceNode.h"
#include <string>
#include <ostream>
#include <exception>

SequenceNode* Sequence::get_at(const size_t position) const
{
    if ((position >= 0) && (position <= this->last_index()))
    {
        SequenceNode* current_node = this->get_head();
        for (size_t i = 0; i < position; ++i)
        {
            if (current_node == nullptr) {
                throw std::out_of_range("Index out of range");
            }
            current_node = current_node->get_next();
        }

        // Assuming get_item() returns std::string&
        return current_node;
    }
    else
    {
        throw std::exception();
    }
}
// Creates an empty sequence (numElts == 0) or a sequence of numElts items
// indexed from 0 ... (numElts - 1).
Sequence::Sequence(size_t sz) : head(nullptr), tail(nullptr), sequence_size(sz)
{
    SequenceNode* next_node;
    this->set_head(new SequenceNode());
    SequenceNode* current_node = this->get_head();
    for (int i = 1; i < this->size(); i++)
    {
        current_node->set_next(new SequenceNode());
        current_node = current_node->get_next();
    }
    this->set_tail(current_node);
}
// Creates a (deep) copy of sequence s
Sequence::Sequence(const Sequence& s) : head(nullptr), tail(nullptr), sequence_size(0)
{
    if (s.size() >= 0)
    {
        *this = s;
    }
    else
    {
        throw std::exception();
    }
}
Sequence::Sequence(const int* int_arr, const int int_arr_size)
{
    if (int_arr_size != 0)
    {
        this->set_head(new SequenceNode(int_arr[0]));
        this->set_tail(new SequenceNode(int_arr[0]));
        for (int i = 1; i < int_arr_size; i++)
        {
            this->push_back(int_arr[i]);
        }
    }
    else
    {
        throw std::exception();
    }

}
void Sequence::set_size(size_t size_value)
{
    if (size_value >= 0)
    {
        this->sequence_size = size_value;
    }
    else
    {
        throw std::exception();
    }
}
void Sequence::set_size(int size_value)
{
    if (size_value >= 0)
    {
        this->sequence_size = static_cast<size_t>(size_value);
    }
    else
    {
        throw std::invalid_argument("Cannot convert negative int to size_t");
    }
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
    if (this->head != nullptr)
    {
        this->head = new SequenceNode(head_value->get_item(), this->get_head()->get_next(), nullptr);
    }
    else
    {
        this->head = new SequenceNode(head_value->get_item(), nullptr, nullptr);
    }
}
// Getter for tail
SequenceNode* Sequence::get_tail() const
{
    return this->tail;
}

// Setter for tail
void Sequence::set_tail(SequenceNode* tail_value)
{
    if (this->tail != nullptr)
    {
        this->tail = new SequenceNode(tail_value->get_item(), nullptr, this->get_tail()->get_prev());
    }
    else
    {
        this->tail = new SequenceNode(tail_value->get_item(), nullptr, nullptr);
    }
}

// Destroys all items in the sequence and release the memory
// associated with the sequence
Sequence::~Sequence()
{
    this->clear();
    delete(this);
}
// The current sequence is released and replaced by a (deep) copy of sequence
// s. A reference to the copied sequence is returned (return *this;).
Sequence& Sequence::operator=(const Sequence& s)
{
    if (s.sequence_size >= 0) 
    {
        this->head = s.head;
        this->tail = s.tail;
        this->sequence_size = s.sequence_size;
        return *this;
    }
    else
    {
        throw std::exception();
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
        SequenceNode* current_node = this->get_head();
        for (size_t i = 0; i < position; ++i)
        {
            if (current_node == nullptr)
            {
                throw std::out_of_range("Index out of range");
            }
            else
            {
                current_node = current_node->get_next();
            }
        }

        // Assuming get_item() returns std::string&
        return current_node->get_item_ref();
    }
    else
    {
        throw std::exception();
    }
}
// The value of string item is append to the sequence.
void Sequence::push_back(std::string item)
{
    SequenceNode* new_node = new SequenceNode(item, nullptr, this->get_tail());
    this->set_size(this->size() + 1);
    // There is no head or tail so we need to set them
    if (this->head == nullptr)
    {
        this->head = new_node;
        this->set_tail(new_node);

    }
    if (this->tail == nullptr)
    {
        this->set_tail(new_node);
    }
    else
    {
        // if tail already existed we have to update it
        this->tail->set_next(new_node);
        new_node->set_prev(this->tail);
        this->set_tail(new_node);
    }
}
// The value of int item is append to the sequence.
void Sequence::push_back(int item)
{
    this->push_back(std::to_string(item));
}
// The item at the end of the sequence is deleted and size of the sequence is
// reduced by one. If sequence was empty, throws an exception
void Sequence::pop_back()
{
    if (!(this->empty())) 
    {
        if (this->get_tail() != nullptr)
        {
            if (this->get_tail()->get_prev() != nullptr)
            {
                this->set_tail(this->get_tail()->get_prev());
                this->set_size(static_cast<int>(this->size()) - 1);
            }
            else
            {
                this->tail = nullptr;
                this->head = nullptr;
                this->set_size(0);
            }
        }

    }
    else
    {
        throw std::exception();
    }
}
// The position satisfies ( position >= 0 && position <= last_index() ). The
// value of item is inserted at position and the size of sequence is increased
// by one. Throws an exceptionif the position is outside the bounds of the
// sequence
void Sequence::insert(size_t position, std::string item)
{
    if ((position >= 0) && (position <= this->last_index())) 
    {
        this->sequence_size = (this->size() + 1);
    }
    else
    {
        throw std::exception();
    }
}
void Sequence::insert(size_t position, int item)
{
    this->insert(position, std::to_string(item));
}
// Returns the first element in the sequence. If the sequence is empty, throw an exception.
std::string Sequence::front() const
{
    if (!(this->empty())) 
    {
        return this->head->get_item();
    }
    else
    {
        throw std::exception();
    }
    
}
// Return the last element in the sequence. If the sequence is empty, throw an exception.
std::string Sequence::back() const
{
    if (this->empty()) 
    {
        throw std::exception();
    }
    return this->tail->get_item();
}
// Return true if the sequence has no elements, otherwise false.
bool Sequence::empty() const
{
    if (this->size() > 0)
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
    SequenceNode* curr_tail = this->get_tail();
    SequenceNode* prev_node = curr_tail->get_prev();
    delete(curr_tail);
    while (prev_node != nullptr)
    {
        curr_tail = prev_node;
        prev_node = curr_tail->get_prev();
        delete(curr_tail);
    }
    this->set_head(nullptr);
    this->set_tail(nullptr);
    this->set_size(0);
}
// The item at position is removed from the sequence, and the memory
// is released. If called with an invalid position throws an exception.
void Sequence::erase(size_t position)
{
    if ((position >= 0) && (position <= this->last_index()))
    {
        // find node_to_erase
        SequenceNode* node_to_erase = this->head;
        SequenceNode* iter_node_next = this->head->get_next();
        while (iter_node_next != nullptr)
        {
            node_to_erase = iter_node_next;
            iter_node_next = node_to_erase->get_next();
        }

        // Get previous and next node of the node being erased
        SequenceNode* erase_node_next = node_to_erase->get_next();
        SequenceNode* erase_node_prev = node_to_erase->get_prev();
        // Connect the two nodes so that the erase doesn't create a gap
        erase_node_next->set_prev(erase_node_prev);
        erase_node_prev->set_next(erase_node_next);
        // Remove old node from memory
        delete(node_to_erase);
        // reduce size
        const size_t current_size = this->size();
        this->set_size(current_size - 1);
    }
    else
    {
        throw std::exception();
    }
}
// The items in the sequence at ( position ... (position + count - 1) ) are
// deleted and their memory released. If called with invalid position and/or
// count throws an exception.
void Sequence::erase(size_t position, size_t count)
{
    const int end_index = static_cast<int>(position + count - 1);

    if ((position <= (this->sequence_size - count - 1)) && (count > 0))
    {
        for (int index = end_index; index >= position; index -= 1)
        {
            const SequenceNode* node_at_index = this->get_at(index);
            delete(node_at_index);
        }
    }
    else
    {
        throw std::exception();
    }
}
int Sequence::last_index() const
{
    return static_cast<int>(this->size() - 1);
}
bool Sequence::operator==(const Sequence* s) const 
{
    if (s != nullptr)
    {
        const bool are_head_equal = (this->get_head() == s->get_head());
        const bool are_tail_equal = (this->get_tail() == s->get_tail());
        const bool are_size_equal = (this->size() == s->size());
        return (are_head_equal && are_tail_equal && are_size_equal);
    }
    else
    {
        return false;  
    } 
}
bool Sequence::operator!=(const Sequence* s) const 
{
    if (s != nullptr)
    {
        const bool are_head_equal = (this->get_head() == s->get_head());
        const bool are_tail_equal = (this->get_tail() == s->get_tail());
        const bool are_size_equal = (this->size() == s->size());
        return !(are_head_equal && are_tail_equal && are_size_equal);
    }
    else
    {
        return true;
    }    
}
// Outputs all elements (ex: <4, 8, 15, 16, 23, 42>) as a string to the output
// stream. This is *not* a method of the Sequence class, but instead it is a
// friend function
std::ostream& operator<<(std::ostream& os, const Sequence& s)
{

    // format: <item, item, item>
    // If item is null print "null"
    os << "<";
    if (s.empty())
    {
        os << "";
    }
    else
    {
        // Initial head cell case
        SequenceNode* current_node = s.get_head();
        SequenceNode* next_node = s.head->get_next();
        if (current_node->get_item().empty())
        {
            os << "null";
        }
        else
        {
            os << current_node->get_item();
        }
        if (next_node != nullptr)
        {
            os << ",";
        }

        // Case for rest of nodes
        while (next_node != nullptr)
        {
            current_node = next_node;
            next_node = current_node->get_next();
            if (current_node->get_item().empty())
            {
                os << "null";
            }
            else
            {
                os << current_node->get_item();
            }
            os << ",";
        }
    }
    os << ">";

    return os;
}
