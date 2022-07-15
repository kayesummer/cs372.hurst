//
// File:    tree.h
// Author: Kaylee Hurst & Your Glorious Instructor 
// Purpose:
// Implement ADT tree
//

#include <memory>

template<typename V>
class Tree
{
    private:
        struct Node
        {
            Node(V v, shared_ptr<Node> & l, shared_ptr<Node>Node & r):
                value(v), left(l), right(r) {}
            V value;
            shared_ptr<Node> left; 
            shared_ptr<Node> right;
        };
        explicit Tree(shared_ptr<Node> & node): root(node) {}
        shared_ptr<Node> root;
    public:
        Tree() {}
        Tree(Tree const &lft, V value, Tree const &rgt) :
            root(Node(val, lft->root, rgt->root)) {}
        bool isEmpty() const;
        V root() const; 
        Tree &left() const;


};