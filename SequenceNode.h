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
        SequenceNode(std::string item) : next(nullptr), prev(nullptr), item(item); //constructor with item
        std::string SequenceNode::item() const;
        SequenceNode* SequenceNode::next() const;
        SequenceNode* SequenceNode::prev() const;
};