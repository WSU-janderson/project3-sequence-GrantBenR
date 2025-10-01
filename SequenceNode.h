#include <string>
#include <ostream>
class SequenceNode 
{
    private:
        SequenceNode* next; // ptr to next node
        SequenceNode* prev; // ptr to prev node
        std::string item; // string contents of node
    public:
        SequenceNode(); // empty constructor
        SequenceNode(std::string item, SequenceNode* next_value, SequenceNode* prev_value) : item(item), next(next), prev(prev); //constructor with item
        std::string item() const;
        void item(std::string item_value)
        SequenceNode* next() const;
        void next(SequenceNode* next_value)
        SequenceNode* prev() const;
        void prev(SequenceNode* prev_value)
};