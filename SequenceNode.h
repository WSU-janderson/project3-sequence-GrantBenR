#ifndef SEQUENCE_NODE_H
#define SEQUENCE_NODE_H

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
        SequenceNode(std::string item, SequenceNode* next_value, SequenceNode* prev_value) : item(item), next(next), prev(prev); //constructor for string item
        std::string get_item() const;
        void set_item(std::string item_value);
        void set_item(int item_value);
        SequenceNode* get_next() const;
        void set_next(SequenceNode* next_value);
        SequenceNode* get_prev() const;
        void set_prev(SequenceNode* prev_value);
};

#endif