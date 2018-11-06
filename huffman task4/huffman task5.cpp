#include <iostream>
#include "stdafx.h"
#include "SymbolFreq.h"
#include <queue>
#include "BinaryTree.h"
#include "Comparator.h"

int main()
{
	SymbolFreq* freq = new SymbolFreq;

	freq->setFilePath("ToCompress.txt");
	freq->readFile(freq->getFilePath());
	freq->countLetters();
	vector<BinaryTreeNode*> nodes = freq->loadFrequencies();
	

	BinaryTree* tree = new BinaryTree;
	priority_queue<BinaryTreeNode*, vector<BinaryTreeNode*>, Comparator>* queue = new priority_queue<BinaryTreeNode*, vector<BinaryTreeNode*>, Comparator>();

	for (std::vector<BinaryTreeNode*>::size_type i = 0; i != nodes.size(); i++) {
		queue->push(nodes[i]);
	}

	
	while (!queue->empty()) {
		BinaryTreeNode* fNode = new BinaryTreeNode;
		BinaryTreeNode* sNode = new BinaryTreeNode;
		BinaryTreeNode* child = new BinaryTreeNode;

		fNode = queue->top(); //Take node from top of queue with highest frequency.
		//cout << "Letter(" << fNode->letter << ") Freq(" << fNode->value << ")" << endl;
		queue->pop(); //remove node from queue.


		//Problem is last child is popped and not pointing to anything
		if (queue->empty()) {
			tree->setRootNode(fNode);
			tree->printTree(fNode);
			tree->printCodes(fNode, "");
			break;
		}

		sNode = queue->top();
		//cout << "Letter(" << sNode->letter << ") Freq(" << sNode->value << ")" << endl;
		queue->pop();

		*child = tree->merge(fNode, sNode);
		queue->push(child);

	}
	
	
	delete queue;
	delete freq;
	delete tree;

	system("PAUSE");
	return 0;
}

