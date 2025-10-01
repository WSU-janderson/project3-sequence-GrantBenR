#ifndef SEQUENCE_TEST_H
#define SEQUENCE_TEST_H

#include <string>
#include <ostream>
#include "Sequence.h"
#include "SequenceNode.h"
class SequenceTest
{
    private:

    public:
        bool TEST_S_Sequence_size_t();
        bool TEST_S_Sequence_deepcopy();
        bool TEST_S_set_size_size_t();
        bool TEST_S_set_size_int();
        bool TEST_S_size();
        bool TEST_S_get_head();
        bool TEST_S_set_head();
        bool TEST_S_get_tail();
        bool TEST_S_set_tail();
        bool TEST_S_tilde_Sequence();
        bool TEST_S_operator_equals();
        bool TEST_S_operator_brackets();
        bool TEST_S_push_back_string();
        bool TEST_S_push_back_int();
        bool TEST_S_pop_back();
        bool TEST_S_insert_string();
        bool TEST_S_insert_int();
        bool TEST_S_front();
        bool TEST_S_back();
        bool TEST_S_empty();
        bool TEST_S_clear();
        bool TEST_S_erase();
        bool TEST_S_erase_count();
        bool TEST_S_last_index();
        bool TEST_S_operator_ostream();
};
#endif