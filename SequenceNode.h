#include <string>
#include <ostream>
class SequenceNode {
    public:
        SequenceNode* next; // ptr to next node
        SequenceNode* prev; // ptr to prev node
        std::string item; // string contents of node
        SequenceNode(); // empty constructor
        SequenceNode(std::string item) : next(nullptr), prev(nullptr), item(item); //constructor with item
};