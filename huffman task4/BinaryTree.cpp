#include "stdafx.h"
#include "BinaryTree.h"
#include <iomanip>

using namespace std;



BinaryTree::BinaryTree()
{
}

BinaryTree::~BinaryTree()
{
	
}

BinaryTreeNode BinaryTree::merge(BinaryTreeNode* node1, BinaryTreeNode* node2)
{
	BinaryTreeNode* child = new BinaryTreeNode;
	child->left = node1;
	child->right = node2;
	child->value = (node1->value + node2->value);
	child->letter = '$';
	return *child;
}

void BinaryTree::printTree(BinaryTreeNode* node, int indent)
{
	if (node == NULL)
		return;
	printTree(node->left, indent + 7);
	
	printTree(node->right, indent + 7);

	if (indent) {
		cout << setw(indent);
	}
	cout << node->value << endl;
}

void BinaryTree::printCodes(BinaryTreeNode * rootNode, string binary)
{
	if (!rootNode) {
		return;
	}
	if (rootNode->left == NULL || rootNode->right == NULL) {
		cout << rootNode->letter << " - Code: " << binary << endl;
	}

	if (rootNode->left != NULL) {
		printCodes(rootNode->left, binary + "0");
	}
	if (rootNode->right != NULL) {
		printCodes(rootNode->right, binary + "1");
	}
}

void BinaryTree::setRootNode(BinaryTreeNode * node)
{
	this->rootNode = node;
}

BinaryTreeNode * BinaryTree::getRootNode()
{
	return this->rootNode;
}

