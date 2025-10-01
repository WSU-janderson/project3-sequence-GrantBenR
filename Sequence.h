#include <string>
#include <ostream>
#include "SequenceNode.h"
class Sequence 
{
    private:
        SequenceNode* head; // ptr to first node
        SequenceNode* tail; // ptr to last node
        size_t size; // number of items in the sequence
    public:
        Sequence(size_t sz = 0);
        Sequence(const Sequence& s);
        size_t size() const;
        void size(size_t size_value)
        SequenceNode* head() const
        void head(SequenceNode* head_value)
        SequenceNode* tail() const
        void tail(SequenceNode* tail_value)
        ~Sequence();
        Sequence& operator=(const Sequence& s);
        std::string& operator[](size_t position);
        void push_back(std::string item);
        void pop_back();
        void insert(size_t position, std::string item);
        std::string front() const;
        std::string back() const;
        bool empty() const;
        void clear();
        void erase(size_t position);
        void erase(size_t position, size_t count);
        int last_index();
        friend ostream& operator<<(ostream& os, const Sequence& s);
};
