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
        SequenceNode();// empty constructor
        SequenceNode(std::string item_value);
        SequenceNode(int item_value);
        SequenceNode(std::string item_value, SequenceNode* next_value, SequenceNode* prev_value);
        SequenceNode(int item_value, SequenceNode* next_value, SequenceNode* prev_value);
        std::string get_item() const;
        std::string& get_item_ref();
        void set_item(std::string item_value);
        void set_item(int item_value);
        SequenceNode* get_next() const;
        void set_next(SequenceNode* next_value);
        SequenceNode* get_prev() const;
        void set_prev(SequenceNode* prev_value);
        SequenceNode& operator=(const std::string& item_value);
        SequenceNode& operator=(const int item_value);
        SequenceNode& operator=(const SequenceNode& sn);
        friend std::ostream& operator<<(std::ostream& os, const SequenceNode& s);

};

#endif