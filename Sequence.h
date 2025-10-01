#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <string>
#include <ostream>
#include "SequenceNode.h"
class Sequence 
{
    private:
        SequenceNode* head; // ptr to first node
        SequenceNode* tail; // ptr to last node
        size_t sequence_size; // number of items in the sequence
    public:
        Sequence(size_t sz = 0);
        Sequence(const Sequence& s);
        size_t size() const;
        SequenceNode* get_head() const;
        void set_head(SequenceNode* head_value);
        SequenceNode* get_tail() const;
        void set_tail(SequenceNode* tail_value);
        ~Sequence();
        Sequence& operator=(const Sequence& s);
        std::string& operator[](size_t position);
        void push_back(std::string item);
        void push_back(int item);
        void pop_back();
        void insert(size_t position, std::string item);
        void insert(size_t position, int item);
        std::string front() const;
        std::string back() const;
        bool empty() const;
        void clear();
        void erase(size_t position);
        void erase(size_t position, size_t count);
        int last_index();
        friend std::ostream& operator<<(std::ostream& os, const Sequence& s);
};
#endif
