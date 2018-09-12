//Lucas Fulmer


//To be used in conjunction with Node.h and BSTree<DATATYPE, KEYTYPE>.cpp
//If you modify this, please add your name and list any changes that you made
#ifndef BSTREEINT_H
#define BSTREEINT_H
#include <iostream>
#include <vector>
#include "Node.h"
#include "actor.h"
#include "picture.h"
using namespace std;

// Binary Search Tree class
template <typename DATATYPE, typename KEYTYPE>
class BSTree {
private:
    Node<DATATYPE, KEYTYPE> * root;
    void addNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * leaf, DATATYPE& data);
    Node<DATATYPE, KEYTYPE> * deleteNode(Node<DATATYPE, KEYTYPE> * node, KEYTYPE key);
    void freeNode(Node<DATATYPE, KEYTYPE> * leaf);
	void printInorder(Node<DATATYPE, KEYTYPE> * node);
	Node<DATATYPE, KEYTYPE> * findNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * node);
	
	//added by Lucas Fulmer
	void fillPicVector(vector<Picture>& _vec, Node<DATATYPE, KEYTYPE> * node);//These two functions are for the sake of resorting/and refining searches
	void fillActorVector(vector<Actor>& _vec, Node<DATATYPE, KEYTYPE> * node);//Using a vector for these two procedures keeps the complexity at O(n)
	void writePicturesToFile(Node<DATATYPE, KEYTYPE> * node, ostream& _out);
	void writeActorsToFile(Node<DATATYPE, KEYTYPE> * node, ostream& _out);
public:
    BSTree<DATATYPE, KEYTYPE>();
    ~BSTree<DATATYPE, KEYTYPE>();
    Node<DATATYPE, KEYTYPE> * Root() { return root; }
    void setRoot(Node<DATATYPE, KEYTYPE> * _root) {root = _root;}
    void addNode(KEYTYPE key, DATATYPE &data);
	Node<DATATYPE, KEYTYPE> * findNode(KEYTYPE key);
	void printInorder();
	void print(ostream & out, const DATATYPE & data);
    void deleteNode(KEYTYPE key);
	Node<DATATYPE, KEYTYPE> * min(Node<DATATYPE, KEYTYPE> * node);
	Node<DATATYPE, KEYTYPE> * max(Node<DATATYPE, KEYTYPE> * node);
	
	//functions below added by Lucas Fulmer
	void readInActorfile();
	void readInPicturefile();
	void fillPicVector(vector<Picture>& _vec);
	void fillActorVector(vector<Actor>& _vec);
	void clearTree();//This function is used if the tree is being resorted.
	void writePicturesToFile();
	void modifyPicNode(KEYTYPE key, Picture _picture);
	void modifyActorNode(KEYTYPE key, Actor _actor);
	void writeActorsToFile();
};
#endif  //BST