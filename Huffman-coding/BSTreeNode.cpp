#include "BSTreeNode.h"

namespace BStree {

	BSTreeNode::BSTreeNode(char k, BSTreeNode* _left, BSTreeNode* _right) {
		value.key = k;
		value.freq = 1;
		left = _left;
		right = _right;
	}

	BSTreeNode::~BSTreeNode() {
		if (left != nullptr)
			delete left;
		if (right != nullptr)
			delete right;
	}

	void Swap(BSTreeNode& node1, BSTreeNode& node2) {
		int tempPri = node2.value.freq;
		char tempC = node2.value.key;
		BSTreeNode* tempL = node2.left;
		BSTreeNode* tempR = node2.right;
		node2.value.freq = node1.value.freq;
		node2.value.key = node1.value.key;
		node2.left = node1.left;
		node2.right = node1.right;
		node1.value.freq = tempPri;
		node1.value.key = tempC;
		node1.left = tempL;
		node1.right = tempR;
	}

}