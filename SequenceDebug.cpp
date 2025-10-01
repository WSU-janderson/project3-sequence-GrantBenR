/**
 * SequenceDebug.cpp
 * Project 3
 * CS 3100
 *
 * In this file, you will write your tests as you implement Sequence. If you are using CLion, you need to select
 * SequenceDebug from the drop-down menu next to the Build (hammer icon) if it is on SequenceTestHarness
 */
#include <iostream>
#include <ostream>
#include "SequenceTest.h"
#include "SequenceNodeTest.h"
#include "Sequence.h"
#include "SequenceNode.h"

#define IS_TRUE(x) { if (!(x)) std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl; }

int main() 
{
    std::cout << "Starting tests..." << std::endl; 
    SequenceTest* sequenceTester = new SequenceTest();
    SequenceNodeTest* sequenceNodeTester = new SequenceNodeTest();
    IS_TRUE(sequenceTester->TEST_S_Sequence());
    IS_TRUE(sequenceTester->TEST_S_Sequence_size_t());
    IS_TRUE(sequenceTester->TEST_S_Sequence_deepcopy());
    IS_TRUE(sequenceTester->TEST_S_set_size_size_t());
    IS_TRUE(sequenceTester->TEST_S_set_size_int());
    IS_TRUE(sequenceTester->TEST_S_size());
    IS_TRUE(sequenceTester->TEST_S_get_head());
    IS_TRUE(sequenceTester->TEST_S_set_head());
    IS_TRUE(sequenceTester->TEST_S_get_tail());
    IS_TRUE(sequenceTester->TEST_S_set_tail());
    IS_TRUE(sequenceTester->TEST_S_tilde_Sequence());
    IS_TRUE(sequenceTester->TEST_S_operator_equals());
    IS_TRUE(sequenceTester->TEST_S_operator_brackets());
    IS_TRUE(sequenceTester->TEST_S_push_back_string());
    IS_TRUE(sequenceTester->TEST_S_push_back_int());
    IS_TRUE(sequenceTester->TEST_S_pop_back());
    IS_TRUE(sequenceTester->TEST_S_insert_string());
    IS_TRUE(sequenceTester->TEST_S_insert_int());
    IS_TRUE(sequenceTester->TEST_S_front());
    IS_TRUE(sequenceTester->TEST_S_back());
    IS_TRUE(sequenceTester->TEST_S_empty());
    IS_TRUE(sequenceTester->TEST_S_clear());
    IS_TRUE(sequenceTester->TEST_S_erase());
    IS_TRUE(sequenceTester->TEST_S_erase_count());
    IS_TRUE(sequenceTester->TEST_S_last_index());
    IS_TRUE(sequenceTester->TEST_S_operator_ostream());
    IS_TRUE(sequenceNodeTester->TEST_SN_SequenceNode());
    IS_TRUE(sequenceNodeTester->TEST_SN_SequenceNode_string());
    IS_TRUE(sequenceNodeTester->TEST_SN_SequenceNode_int());
    IS_TRUE(sequenceNodeTester->TEST_SN_get_item());
    IS_TRUE(sequenceNodeTester->TEST_SN_set_item_string());
    IS_TRUE(sequenceNodeTester->TEST_SN_set_item_int());
    IS_TRUE(sequenceNodeTester->TEST_SN_get_next());
    IS_TRUE(sequenceNodeTester->TEST_SN_set_next());
    IS_TRUE(sequenceNodeTester->TEST_SN_get_prev());
    IS_TRUE(sequenceNodeTester->TEST_SN_set_prev());
    IS_TRUE(sequenceNodeTester->TEST_SN_operator_equals_string());
    IS_TRUE(sequenceNodeTester->TEST_SN_operator_equals_int());
    IS_TRUE(sequenceNodeTester->TEST_SN_operator_equals_SequenceNode());
    IS_TRUE(sequenceNodeTester->TEST_SN_operator_ostream());

    std::cout << "Your project is ready to go!" << std::endl;

    return 0;
}