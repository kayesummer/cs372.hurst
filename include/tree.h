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
        Tree() {}   //default constructor
        Tree(Tree const &lft, V value, Tree const &rgt) :   //constructor
            root(Node(v->value, lft->root, rgt->root)) {}
        
        Tree Tree::insert(V x) const  
        {
            if (isEmpty())
            {
                return Tree(Tree(), x, Tree());
            }
            V y = root();
            if(x < y)
            {
                return Tree(left().insert(x), y, right());
            }
            else if (y < x)
            {
                return Tree(left(), y, right().insert(x));
            }
            else
            {
                return *this;   //no duplicates
            }
        }

        bool isEmpty() const 
        {

        }

        V root() const 
        {
            return root;
        }

        Tree &left() const  
        {
            return left;
        }

        Tree &right() const  
        {
            return right;
        }

        bool member(V x) const   
        {
            if (isEmpty())
            {
                return false;
            }
            V y = root();
            if (x < y)
            {
                return left().member(x);
            }
            else if (y < x)
            {
                return right.().member(x);
            }
            else 
            {
                return true;
            }
        }

        bool isLeaf() const 
        {

        }


};