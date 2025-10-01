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
        ~Sequence();
        Sequence& operator=(const Sequence& s);
        std::string& Sequence::operator[](size_t position);
        void Sequence::push_back(std::string item);
        void Sequence::pop_back();
        void Sequence::insert(size_t position, std::string item);
        std::string Sequence::front() const;
        std::string Sequence::back() const;
        bool Sequence::empty() const;
        size_t Sequence::size() const;
        SequenceNode* Sequence::head() const
        SequenceNode* Sequence::tail() const
        void Sequence::clear();
        void Sequence::erase(size_t position);
        void Sequence::erase(size_t position, size_t count);
        int Sequence::last_index();
        friend ostream& operator<<(ostream& os, const Sequence& s);
};
