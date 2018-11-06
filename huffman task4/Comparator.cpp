
#include "stdafx.h"
#include "Comparator.h"

bool Comparator::operator()(BinaryTreeNode* node1, BinaryTreeNode* node2) {
	return node1->value > node2->value;
}

