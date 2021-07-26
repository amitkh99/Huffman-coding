#pragma once
#include <iostream>


using namespace std;

namespace BStree {

	typedef struct {
		char key;
		int freq;
	}pair;

	class BSTreeNode
	{

	private:
		pair value;
		BSTreeNode* left;
		BSTreeNode* right;

		
	public:
		BSTreeNode(char k = 0, BSTreeNode* _left = nullptr, BSTreeNode* _right = nullptr);
		~BSTreeNode();
		
		BSTreeNode* getLeft() { return left; }
		BSTreeNode* getRight() { return right; }
		char getKey() { return value.key; }
		int getfreq() { return value.freq; };
		void setLeft(BSTreeNode* node) { left = node; }
		void setRight(BSTreeNode* node) { right = node; }
		void setFrequency(int num) { value.freq = num; }

		friend class BSTree;
		
		friend void Swap(BSTreeNode& node1, BSTreeNode& node2);
	};

	

}