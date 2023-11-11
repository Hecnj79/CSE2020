// BinarySearchTreeHW.h
// KV, for CSE 2020, Spring 2022, HW4
// A partial implemention of class BinarySearchTree,
// just enough to write the assigned program;
// NEEDS COMPLETIONS FOR HW4

// Student Completer: ___________________    SID:__________________
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <cassert>
#include "Vector.h"
using namespace std;       


template <typename T>
class BinarySearchTree
{
private:
    struct BinaryNode
    {
        T element;
        BinaryNode* left;
        BinaryNode* right;
        BinaryNode* parent;

        BinaryNode(const T& theElement, BinaryNode* lt, BinaryNode* rt,
            BinaryNode* par)
            : element(theElement), left(lt), right(rt), parent(par) { }
    };

 public:

	BinarySearchTree( ) : root(0) {}

    BinarySearchTree( const BinarySearchTree & rhs ) : root( 0 )
    {
        root = clone( rhs.root );
    }
    
    ~BinarySearchTree( )
    {
        makeEmpty( );
    }

    BinarySearchTree & operator=( const BinarySearchTree & rhs )
    {
        BinarySearchTree copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
    //hw3
    void collect_values(Vector<T>& coll)
    {
	collect_values(root, coll);
    }

    bool isEmpty( ) const
    {
        return root == 0;
    }

    void printTree() const
    {
        if( isEmpty( ) )
            cout << "Empty tree" << endl;
        else
            printTree( root);
    }

	void printInternal() const
	{
		if (isEmpty())
			cout << "Empty tree" << endl;
		else
			printInternal(root, 0);
	}
	
    void makeEmpty( )
    {
        makeEmpty( root );
    }

    void insert( const T & x )
    {
	    insert( x, root, root);
    }
    
    int depth() const
    {
        return depth(root);
    }

private:

    BinaryNode *root;

    // internal methods in private:

    void insert( const T & x, BinaryNode * & t, BinaryNode * & par)
    {
	   if( t == 0 )
		{
            t = new BinaryNode( x, 0, 0, par );
		}
        else if( x < t->element )
            insert( x, t->left, t );
        else if( t->element < x )
            insert( x, t->right, t );
        else
            ;  // Duplicate; do nothing
    }
    //hw3
    void collect_values(BinaryNode* t, Vector<T>& vec)
    {
	if(t == nullptr)
	    return;
	if(t->left == nullptr && t->right == nullptr)
	{
	//store value
	vec.push_back(t->element);
	return;
	}
	if(t->left)
	    collect_values(t->left, vec);

	vec.push_back(t->element);

	if(t->right)
	    collect_values(t->right, vec);

	return;
    }

    void makeEmpty( BinaryNode * & t )
    {
        if( t != 0 )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = 0;
    }

    void printTree( BinaryNode *t) const
    {
        if (t == nullptr)
            return;
        
        printTree( t->left);
        cout << t->element << " ";
        printTree( t->right);
        return;
    }

	void printInternal(BinaryNode *t, int offset) const
	{
		for (int i = 1; i <= offset; i++)
			cout << "..";
		if (t == 0)
		{
			cout << "#" << endl;
			return;
		}
		cout << t->element << endl;
		printInternal(t->left, offset + 1);
		printInternal(t->right, offset + 1);
		return;
	}

    BinaryNode * clone( BinaryNode *t ) const
    {
        if( t == 0 )
            return 0;
        else
            return new BinaryNode{ t->element, clone( t->left ), clone( t->right ),
		clone(t->parent) };
    }

    int depth(BinaryNode* t) const
    {
        if (t == nullptr)
            return 0;
        if (t->left == nullptr && t->right == nullptr)
            return 1;
        int ld = depth(t->left);
        int lr = depth(t->right);
        if (ld >= lr)
            return 1 + ld;
        else
            return 1 + lr;
    }
};




#endif
