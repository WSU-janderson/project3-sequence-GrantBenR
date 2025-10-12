#include "Sequence.h"
#include "SequenceNode.h"
#include <string>
#include <ostream>
#include <exception>
#include <utility>

/**
 * Gets SequenceNode* at Sequence[position]
 *
 * @param position size_t
 * @return node_at_position SequenceNode*
 */
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
        throw std::runtime_error("get_at - Index out of range");
    }
}
/**
 * Creates an empty sequence (numElts == 0) or a sequence of numElts items indexed from 0 ... (numElts - 1).
 *
 * @param sz
 * @return void
 */
Sequence::Sequence(size_t sz) : head(nullptr), tail(nullptr)
{
    SequenceNode* first_node = new SequenceNode("");
    this->set_size(1);
    this->head = first_node;
    this->tail = first_node;
    for (int i = 1; i < sz; i++)
    {
        this->push_back("");
    }
}
//
/**
 * Creates a (deep) copy of sequence s
 *
 * @param s Sequence&
 * @return void
 */
Sequence::Sequence(const Sequence& s) : head(nullptr), tail(nullptr), sequence_size(0)
{
    if (s.size() >= 0)
    {
        *this = s;
    }
    else
    {
        throw std::runtime_error("Sequence(Sequence&) - Deepcopy Sequence is empty");
    }
}
/**
 * Creates a sequence from an array of integers int_arr of size int_arr_size
 *
 * @param int_arr
 * @param int_arr_size
 * @return void
 */
Sequence::Sequence(const int* int_arr, const int int_arr_size)
{
    if (int_arr_size != 0)
    {
        SequenceNode* first_node = new SequenceNode("");
        this->head = first_node;
        this->tail = first_node;
        for (int i = 1; i < int_arr_size; i++)
        {
            this->push_back(int_arr[i]);
        }
    }
    else
    {
        throw std::runtime_error("Sequence(int_arr,int_arr_size) - arr is empty");
    }

}

/**
 * Setter for size_t sequence_size
 *
 * @param size_value
 * @return void
 */
void Sequence::set_size(const size_t size_value)
{
    if (size_value >= 0)
    {
        this->sequence_size = size_value;
    }
    else
    {
        throw std::runtime_error("set_size(size_t) - size is invalid");
    }
}

/**
 * Setter for size_t sequence_size (int)
 *
 * @param size_value
 * @return void
 */
void Sequence::set_size(const int size_value)
{
    if (size_value >= 0)
    {
        this->sequence_size = static_cast<size_t>(size_value);
    }
    else
    {
        throw std::runtime_error("set_size(int) - size is invalid");
    }
}


/**
 * Getter for size_t sequence_size
 *
 * @return sequence_size size_t
 */
size_t Sequence::size() const
{
    return this->sequence_size;
}
/**
 * Getter for head
 *
 * @return head SequenceNode*
 */
SequenceNode* Sequence::get_head() const
{
    return this->head;
}

/**
 * Setter for head of Sequence
 *
 * @param head_value SequenceNode*
 * @return void
 */
void Sequence::set_head(SequenceNode* head_value)
{
    this->head = head_value;
}

/**
 * Getter for tail
 *
 * @return tail Sequence*
 */
SequenceNode* Sequence::get_tail() const
{
    return this->tail;
}


/**
 * Setter for tail
 *
 * @param tail_value SequenceNode*
 * @return void
 */
void Sequence::set_tail(SequenceNode* tail_value)
{
    this->tail = tail_value;
}

/**
 * Destroys all items in the sequence and release the memory associated with the sequence
 * @return void
 */
Sequence::~Sequence()
{
    this->clear();
}
/**
 * The current sequence is released and replaced by a (deep) copy of sequences.
 * A reference to the copied sequence is returned (return *this;).
 *
 * @param s Sequence&
 * @return updated_sequence Sequence&
 */
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
        throw std::runtime_error("Sequence::operator=(const Sequence&) - Invalid Size");
    }
    
}
/**
 * The position satisfies ( position >= 0 && position <= last_index() ).
 * The return value is a reference to the item at index position in the
 * sequence. Throws an exception if the position is outside the bounds
 * of the sequence
 *
 * @param position size_t
 * @return item string&
 */
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
        throw std::runtime_error("Sequence::operator[] - Index out of range");
    }
}

/**
 * The value of string item is append to the sequence.
 *
 * @param item std::string
 * @return void
 */
void Sequence::push_back(std::string item)
{
    SequenceNode* new_node = new SequenceNode(std::move(item));
    const size_t init_size = this->size();
    this->set_size(init_size + 1);
    // CASE 0: EMPTY LIST
    if (init_size == 0)
    {
        //Set head to new node
        this->set_head(new_node);
        //Set tail to new node
        this->set_tail(new_node);
        //Link head and tail nodes
        this->get_head()->set_next(this->get_tail());
        this->get_tail()->set_prev(this->get_head());
    } // CASE 1: LIST HAS 1 ITEM, IDENTICAL HEAD AND TAIL
    else if (init_size == 1)
    {
        //Set tail to new node
        this->set_tail(new_node);
        //Link two nodes
        if (this->get_head() != nullptr)
        {
            this->get_head()->set_next(this->get_tail());
            this->get_head()->set_prev(nullptr);
        }
        else
        {
            throw std::runtime_error("Sequence::push_back - Head is nullptr");
        }
        this->get_tail()->set_prev(this->get_head());
    } // CASE 2: LIST IS NORMAL, 2+ ITEMS
    else
    {
        //Set tail to new item
        this->get_tail()->set_next(new_node);
        new_node->set_prev(this->get_tail());
        this->set_tail(new_node);
    }
}

/**
 * The value of int item is append to the sequence.
 *
 * @param item int
 * @return void
 */
void Sequence::push_back(int item)
{
    this->push_back(std::to_string(item));
}
/**
 * The item at the end of the sequence is deleted and size of the sequence is
 * reduced by one. If sequence was empty, throws an exception
 * @return void
 */
void Sequence::pop_back()
{
    const size_t init_size = this->size();
    if (!(this->empty())) 
    {
        if (init_size == 1)
        {
            this->set_head(nullptr);
            this->set_tail(nullptr);
        }
        else if (init_size == 2)
        {
            // New tail is next to last element
            SequenceNode* new_tail = this->get_tail()->get_prev();
            this->set_tail(new_tail);
            //If there is only one item, the head and tail should be the same item and should self reference
            new_tail->set_next(new_tail);
        }
        else
        {
            // New tail is next to last element
            SequenceNode* new_tail = this->get_tail()->get_prev();
            this->set_tail(new_tail);
            //New tail should not reference old tail
            new_tail->set_next(nullptr);
        }
        this->set_size(init_size - 1);
    }
    else
    {
        throw std::runtime_error("Sequence::push_back - Sequence is empty");
    }
}
/**
 * The position satisfies ( position >= 0 && position <= last_index() ). The
 * value of item is inserted at position and the size of sequence is increased
 * by one. Throws an exceptionif the position is outside the bounds of the
 * sequence
 *
 * @param position size_t
 * @param item std::string
 */
void Sequence::insert(size_t position, std::string item)
{
    //size_t is always >= zero, so no comparison needed for that
    if (position <= this->last_index())
    {
        SequenceNode* old_node_at_pos = this->get_at(position);
        if (old_node_at_pos != nullptr)
        {
            // SequenceNode* new_node_at_pos = new SequenceNode(std::move(item), );
            // new_node_at_pos->set_next(old_node_at_pos);
            if (position == 0)
            {
                SequenceNode* new_node_at_pos = new SequenceNode(std::move(item), old_node_at_pos, nullptr);
                this->set_head(new_node_at_pos);
                old_node_at_pos->set_prev(new_node_at_pos);
            }
            else
            {
                SequenceNode* new_node_at_pos = new SequenceNode(std::move(item), old_node_at_pos, old_node_at_pos->get_prev());
                old_node_at_pos->get_prev()->set_next(new_node_at_pos);
                old_node_at_pos->set_prev(new_node_at_pos);
            }
            this->set_size(this->size() + 1);
        }
        else
        {
            throw std::runtime_error("Sequence::insert(int) - invalid index for old node");
        }
    }
    else
    {
        throw std::runtime_error("insert - invalid index");
    }
}

/**
 * The position satisfies ( position >= 0 && position <= last_index() ). The
 * value of item is inserted at position and the size of sequence is increased
 * by one. Throws an exceptionif the position is outside the bounds of the
 * sequence
 *
 * @param position size_t
 * @param item int
 * @return void
 */
void Sequence::insert(size_t position, int item)
{
    this->insert(position, std::to_string(item));
}

/**
 * Returns the first element in the sequence. If the sequence is empty, throw an exception.
 *
 * @return front_item std::string
 */
std::string Sequence::front() const
{
    if (!(this->empty())) 
    {
        return this->get_head()->get_item();
    }
    else
    {
        throw std::runtime_error("Sequence::front() - Sequence is empty");
    }
    
}
/**
 * Return the last element in the sequence. If the sequence is empty, throw an exception.
 *
 * @return back_item std::string
 */
std::string Sequence::back() const
{
    if (this->empty()) 
    {
        throw std::runtime_error("Sequence::back() - Sequence is empty");
    }
    return this->get_tail()->get_item();
}
/**
 * Return true if the sequence has no elements, otherwise false.
 *
 * @return is_empty bool
 */
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

/**
 * All items in the sequence are deleted and the memory associated with the
 * sequence is released, resetting the sequence to an empty state that can have
 * items re-inserted.
 * @return void
 */
void Sequence::clear()
{
    if (this->size() == 1)
    {
        // Head and tail are same object if size = 1
        this->set_head(nullptr);
        this->set_tail(nullptr);
        this->set_size(0);
    }
    else if (this->size() > 1)
    {
        SequenceNode* curr_tail = this->get_tail();
        SequenceNode* prev_node = curr_tail->get_prev();
        while (prev_node != nullptr)
        {
            curr_tail = prev_node;
            prev_node = curr_tail->get_prev();
        }
        this->set_head(nullptr);
        this->set_tail(nullptr);
        this->set_size(0);
    }
    // else
    // {
    //     throw std::runtime_error("Sequence::clear - Sequence is empty");
    // }
}

/**
 * The item at position is removed from the sequence, and the memory
 * is released. If called with an invalid position throws an exception.
 *
 * @param position size_t
 * @return void
 */
void Sequence::erase(size_t position)
{
    if (!this->empty())
    {
        if (position <= this->last_index())
        {
            if (position == 0)
            {
                if (this->size() == 1)
                {
                    SequenceNode* node_to_erase = this->get_head();
                    // delete(node_to_erase);
                    this->set_head(nullptr);
                    this->set_tail(nullptr);
                }
                else
                {
                    SequenceNode* node_to_erase = this->get_head();
                    SequenceNode* erase_node_next = node_to_erase->get_next();
                    this->set_head(erase_node_next);
                    erase_node_next->set_prev(nullptr);
                    // delete(node_to_erase);
                }
            }
            else if (position == this->last_index())
            {
                if (this->size() <= 1)
                {
                    this->head = nullptr;
                    this->tail = nullptr;
                }
                else
                {
                    SequenceNode* node_to_erase = this->get_tail();
                    this->set_tail(node_to_erase->get_prev());
                    this->get_tail()->set_next(nullptr);
                }

            }
            else
            {
                // find node_to_erase
                SequenceNode* node_to_erase = this->get_at(position);
                // Get previous and next node of the node being erased
                SequenceNode* erase_node_next = node_to_erase->get_next();
                SequenceNode* erase_node_prev = node_to_erase->get_prev();
                // Connect the two nodes so that the erase doesn't create a gap
                erase_node_next->set_prev(erase_node_prev);
                erase_node_prev->set_next(erase_node_next);
                // Remove old node from memory
                // delete(node_to_erase);
            }
            // reduce size
            const size_t current_size = this->size();
            this->set_size(current_size - 1);
        }
        else
        {
            throw std::runtime_error("Sequence::erase() - Invalid index");
        }
    }
    else
    {
        throw std::runtime_error("Sequence::erase() - Empty Sequence");
    }
}

/**
 * The items in the sequence at ( position ... (position + count - 1) ) are
 * deleted and their memory released. If called with invalid position and/or
 * count throws an exception.
 *
 * @param position size_t
 * @param count size_t
 * @return void
 */
void Sequence::erase(size_t position, size_t count)
{
    const int end_of_range = static_cast<int>(position + count - 1);

    if ((position <= (this->size() - count - 1)) && (count > 0))
    {
        for (int index = end_of_range; index >= position; index -= 1)
        {
            this->erase(index);
        }
    }
    else
    {
        throw std::runtime_error("Sequence::erase() - Invalid index");
    }
}
/**
 * Gets the last integer index in the sequence from its size
 *
 * @return last_index int
 */
int Sequence::last_index() const
{
    return static_cast<int>(this->size() - 1);
}

/**
 * Compare current Sequence to Sequence*
 *
 * @param s Sequence*
 * @return are_sequences_equal bool
 */
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

/**
 * Compare if sequences are unequal
 *
 * @param s Sequence*
 * @return are_sequences_unequal bool
 */
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
/**
 * Outputs all elements (ex: <4, 8, 15, 16, 23, 42>) as a string to the output
 * stream. This is *not* a method of the Sequence class, but instead it is a
 * friend function
 *
 * @param os std::ostream&
 * @param s Sequence&
 * @return new_ostream std::ostream&
 */
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
        SequenceNode* next_node = current_node->get_next();
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
            if (next_node != nullptr)
            {
                os << ",";
            }
        }
    }
    os << ">";

    return os;
}
