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
        SequenceNode::SequenceNode() : next(nullptr), prev(nullptr) {};// empty constructor
        SequenceNode::SequenceNode(std::string item_value) : next(nullptr), prev(nullptr) {};
        SequenceNode::SequenceNode(int item_value) : next(nullptr), prev(nullptr) {};
        std::string get_item() const;
        void set_item(std::string item_value);
        void set_item(int item_value);
        SequenceNode* get_next() const;
        void set_next(SequenceNode* next_value);
        SequenceNode* get_prev() const;
        void set_prev(SequenceNode* prev_value);
        SequenceNode& operator=(const std::string item_value);
        SequenceNode& operator=(const int item_value);
        SequenceNode& operator=(const SequenceNode& sn);


};

#endif