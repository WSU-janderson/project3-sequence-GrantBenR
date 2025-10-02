#include <iostream>
#include <ostream>
#include <string>
#include "SequenceTest.h"
#include "Sequence.h"
#include "SequenceNode.h"

SequenceTest::SequenceTest() {}

bool SequenceTest::TEST_S_Sequence_size_t()
{
    std::cout << "- - Sequence::Sequence(size_t) - - " << std::endl;
    Sequence* test_sequence = new Sequence(5);
    std::cout << "HEAD: " << *(test_sequence->get_head()) << std::endl;
    std::cout << "TAIL: " << *(test_sequence->get_tail()) << std::endl;
    std::cout << "SIZE: " << test_sequence->size() << std::endl;
    return true;
}
bool SequenceTest::TEST_S_Sequence_deepcopy()
{
    std::cout << "- - Sequence::Sequence(const Sequence& s) - - " << std::endl;
    Sequence* test_sequence_1 = new Sequence(5);
    Sequence* test_sequence_2 = new Sequence(*test_sequence_1);
    std::cout << "Original head: " << *(test_sequence_1->get_head()) << std::endl;
    std::cout << "Original tail: " << *(test_sequence_1->get_tail()) << std::endl;
    std::cout << "Original size: " << test_sequence_1->size() << std::endl;
    std::cout << "Copy head: " << *(test_sequence_2->get_head()) << std::endl;
    std::cout << "Copy tail: " << *(test_sequence_2->get_tail()) << std::endl;
    std::cout << "Copy size: " << test_sequence_2->size() << std::endl;
    return true;
}
bool SequenceTest::TEST_S_set_size_size_t()
{
    std::cout << "- - Sequence::set_size(size_t) - - " << std::endl;
    Sequence* test_sequence = new Sequence();
    std::cout << "In size: " << test_sequence->size() << std::endl;
    test_sequence->set_size(static_cast<size_t>(5));
    std::cout << "Out size: " << test_sequence->size() << std::endl;
    return true;
}
bool SequenceTest::TEST_S_set_size_int()
{
    std::cout << "- - Sequence::set_size(int) - - " << std::endl;
    Sequence* test_sequence = new Sequence();
    std::cout << "In size: " << test_sequence->size() << std::endl;
    test_sequence->set_size(static_cast<int>(5));
    std::cout << "Out size: " << test_sequence->size() << std::endl;
    return true;
}
bool SequenceTest::TEST_S_size()
{
    std::cout << "- - Sequence::size() - - " << std::endl;
    Sequence* test_sequence = new Sequence(5);
    std::cout << "Size: " << test_sequence->size() << std::endl;
    return true;
}
bool SequenceTest::TEST_S_get_head()
{
    std::cout << "- - Sequence::get_head() - - " << std::endl;
    Sequence* test_sequence = new Sequence(5);
    std::cout << "Head: " << test_sequence->get_head() << std::endl;
    return true;
}
bool SequenceTest::TEST_S_set_head()
{
    std::cout << "- - Sequence::set_head() - - " << std::endl;
    Sequence* test_sequence = new Sequence(5);
    SequenceNode* new_head = new SequenceNode("New Head");
    test_sequence->set_head(new_head);
    std::cout << "Head: " << test_sequence->get_head() << std::endl;
    return true;
}
bool SequenceTest::TEST_S_get_tail()
{
    std::cout << "- - Sequence::get_tail() - - " << std::endl;
    Sequence* test_sequence = new Sequence(5);
    std::cout << "Tail: " << test_sequence->get_tail() << std::endl;
    return true;
}
bool SequenceTest::TEST_S_set_tail()
{
    std::cout << "- - Sequence::set_tail() - - " << std::endl;
    Sequence* test_sequence = new Sequence(5);
    SequenceNode* new_tail = new SequenceNode("New Tail");
    test_sequence->set_tail(new_tail);
    std::cout << "Tail: " << test_sequence->get_tail() << std::endl;
    return true;
}
bool SequenceTest::TEST_S_tilde_Sequence()
{
    std::cout << "- - Sequence::~Sequence() - - " << std::endl;
    Sequence* test_sequence = new Sequence(5);
    return true;
}
bool SequenceTest::TEST_S_operator_equals()
{
    std::cout << "- - Sequence::operator=(const Sequence& s) - - " << std::endl;
    Sequence* test_sequence = new Sequence(5);
    Sequence* test_sequence_copy = new Sequence(*test_sequence);
    std::cout << "Original head: " << test_sequence->get_head() << std::endl;
    std::cout << "Original tail: " << test_sequence->get_tail() << std::endl;
    std::cout << "Original size: " << test_sequence->size() << std::endl;
    std::cout << "Copy head: " << test_sequence_copy->get_head() << std::endl;
    std::cout << "Copy tail: " << test_sequence_copy->get_tail() << std::endl;
    std::cout << "Copy size: " << test_sequence_copy->size() << std::endl;
    return true;
}
bool SequenceTest::TEST_S_operator_brackets()
{
    std::cout << "- - Sequence::operator[](size_t position) - - " << std::endl;
    Sequence* test_sequence = new Sequence(5);
    for (size_t i = 0; i < 5; i++) {
        (*test_sequence)[i] = std::to_string((i + 1) * 100);
    }
    for (size_t i = 0; i < 5; i++) {
        std::cout << "Element " << i << ": " << (*test_sequence)[i] << std::endl;
    }
    return true;
}
bool SequenceTest::TEST_S_push_back_string()
{
    std::cout << "- - Sequence::push_back(std::string value) - - " << std::endl;
    Sequence* test_sequence = new Sequence(0);
    for (int i = 0; i < 5; i++) {
        test_sequence->push_back(std::to_string(i));
    }
    std::cout << "Sequence after push_back: " << *test_sequence << std::endl;
    return true;
}
bool SequenceTest::TEST_S_push_back_int()
{
    std::cout << "- - Sequence::push_back(int value) - - " << std::endl;
    Sequence* test_sequence = new Sequence(0);
    for (int i = 0; i < 5; i++) {
        test_sequence->push_back(i);
    }
    std::cout << "Sequence after push_back: " << *test_sequence << std::endl;
    return true;
}
bool SequenceTest::TEST_S_pop_back()
{
    std::cout << "- - Sequence::pop_back() - - " << std::endl;
    Sequence* test_sequence = new Sequence(5);
    std::cout << "Sequence before pop_back: " << *test_sequence << std::endl;
    test_sequence->pop_back();
    std::cout << "Sequence after pop_back: " << *test_sequence << std::endl;
    return true;
}
bool SequenceTest::TEST_S_insert_string()
{
    std::cout << "- - Sequence::insert(size_t position, const std::string& value) - - " << std::endl;
    Sequence* test_sequence = new Sequence(0);
    test_sequence->push_back("First");
    test_sequence->push_back("Second");
    test_sequence->push_back("Third");
    std::cout << "Sequence before insert: " << *test_sequence << std::endl;
    test_sequence->insert(1, "Inserted");
    std::cout << "Sequence after insert: " << *test_sequence << std::endl;
    return true;
}
bool SequenceTest::TEST_S_insert_int()
{
    std::cout << "- - Sequence::insert(size_t position, int value) - - " << std::endl;
    Sequence* test_sequence = new Sequence(0);
    for (int i = 0; i < 5; i++) {
        test_sequence->push_back(i);
    }
    std::cout << "Sequence before insert: " << *test_sequence << std::endl;
    test_sequence->insert(2, 250);
    std::cout << "Sequence after insert: " << *test_sequence << std::endl;
    return true;
}
bool SequenceTest::TEST_S_front()
{
    std::cout << "- - Sequence::front() - - " << std::endl;
    Sequence* test_sequence = new Sequence(0);
    for (int i = 0; i < 5; i++) {
        test_sequence->push_back(i);
    }
    std::cout << "Front element: " << test_sequence->front() << std::endl;
    return true;
}
bool SequenceTest::TEST_S_back()
{
    std::cout << "- - Sequence::back() - - " << std::endl;
    Sequence* test_sequence = new Sequence(0);
    for (int i = 0; i < 5; i++) {
        test_sequence->push_back(i);
    }
    std::cout << "Back element: " << test_sequence->back() << std::endl;
    return true;

}
bool SequenceTest::TEST_S_empty()
{
    std::cout << "- - Sequence::empty() - - " << std::endl;
    Sequence* test_sequence = new Sequence(0);
    std::cout << "Is sequence empty? " << (test_sequence->empty() ? "Yes" : "No") << std::endl;
    test_sequence->push_back(1);
    std::cout << "Is sequence empty after push_back? " << (test_sequence->empty() ? "Yes" : "No") << std::endl;
    return true;
}
bool SequenceTest::TEST_S_clear()
{
    std::cout << "- - Sequence::clear() - - " << std::endl;
    Sequence* test_sequence = new Sequence(0);
    for (int i = 0; i < 5; i++) {
        test_sequence->push_back(i);
    }
    std::cout << "Sequence before clear: " << *test_sequence << std::endl;
    test_sequence->clear();
    std::cout << "Sequence after clear: " << *test_sequence << std::endl;
    return true;
}
bool SequenceTest::TEST_S_erase()
{
    std::cout << "- - Sequence::erase(size_t position) - - " << std::endl;
    Sequence* test_sequence = new Sequence(0);
    for (int i = 0; i < 5; i++) {
        test_sequence->push_back(i);
    }
    std::cout << "Sequence before erase: " << *test_sequence << std::endl;
    test_sequence->erase(2);
    std::cout << "Sequence after erase: " << *test_sequence << std::endl;
    return true;
}
bool SequenceTest::TEST_S_erase_count()
{
    std::cout << "- - Sequence::erase(size_t position) - - " << std::endl;
    Sequence* test_sequence = new Sequence(0);
    for (int i = 0; i < 5; i++) {
        test_sequence->push_back(i);
    }
    std::cout << "Sequence before erase: " << *test_sequence << std::endl;
    test_sequence->erase(2);
    std::cout << "Sequence after erase: " << *test_sequence << std::endl;
    return true;
}
bool SequenceTest::TEST_S_last_index()
{
    std::cout << "- - Sequence::last_index() - - " << std::endl;
    Sequence* test_sequence = new Sequence(0);
    for (int i = 0; i < 5; i++) {
        test_sequence->push_back(i);
    }
    std::cout << "Last index: " << test_sequence->last_index() << std::endl;
    return true;
}
bool SequenceTest::TEST_S_operator_ostream()
{
    std::cout << "- - Sequence::operator<<(std::ostream& os, const Sequence& seq) - - " << std::endl;
    Sequence* test_sequence = new Sequence(0);
    for (int i = 0; i < 5; i++) {
        test_sequence->push_back(i);
    }
    std::cout << "Sequence contents: " << *test_sequence << std::endl;
    return true;
}