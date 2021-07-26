#pragma once


#include "BSTree.h"


using namespace std;
using namespace BStree;

namespace HuffTree {

	typedef struct {
		int priority;
		char data;
		
	}pairHeap;

	class Heap
	{
	private:
		BSTreeNode** data;
		int maxSize;
		int heapSize;
		int allocated;
		static int Left(int node) { return (2 * node + 1); }
		static int Right(int node) { return 2 * node + 2; }
		static int Parent(int node) { return (node - 1) / 2; }
		void FixHeap(int node);
		void Insert(BSTreeNode* node);
		void BuildHeap(BSTreeNode** A, int n);
	public:
		Heap(BSTreeNode** A, int n);
		Heap(BSTree& tree);
		~Heap();

		BSTreeNode* DeleteMin();
		BSTreeNode* MakeHuffmanTree();
		BSTreeNode* Min() { return data[0]; }
		bool IsEmpty() { return heapSize == 0; }
		
	};
	
	
}