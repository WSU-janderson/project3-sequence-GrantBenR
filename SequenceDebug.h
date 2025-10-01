#ifndef SEQUENCE_DEBUG_H
#define SEQUENCE_DEBUG_H

#include <string>
#include <ostream>
#include "Sequence.h"
#include "SequenceNode.h"
class Sequence 
{
    private:

    public:
        bool TEST_Sequence();
        bool TEST_Sequence_size_t();
        bool TEST_Sequence_deepcopy();
        bool TEST_set_size_size_t();
        bool TEST_set_size_int();
        bool TEST_size();
        bool TEST_get_head();
        bool TEST_set_head();
        bool TEST_get_tail();
        bool TEST_set_tail();
        bool TEST_tilde_Sequence();
        bool TEST_operator_equals();
        bool TEST_operator_brackets();
        bool TEST_push_back_string();
        bool TEST_push_back_int();
        bool TEST_pop_back();
        bool TEST_insert_string();
        bool TEST_insert_int();
        bool TEST_front();
        bool TEST_back();
        bool TEST_empty();
        bool TEST_clear();
        bool TEST_erase();
        bool TEST_erase_count();
        bool TEST_last_index();
        bool TEST_operator_ostream();
};
#endif