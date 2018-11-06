#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct BinaryTreeNode {
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	int value;
	char letter;
};


class BinaryTree {
public:
	BinaryTree();
	~BinaryTree();
	BinaryTreeNode merge(BinaryTreeNode* node1, BinaryTreeNode* node2);
	void printTree(BinaryTreeNode* node, int indent = 0);
	void printCodes(BinaryTreeNode* rootNode, string binary);
	void setRootNode(BinaryTreeNode* node);
	BinaryTreeNode* getRootNode();
private:
	BinaryTreeNode* rootNode;

};