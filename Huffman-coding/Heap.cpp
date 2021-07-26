#include "Heap.h"



namespace HuffTree {
	

	Heap::Heap(BSTreeNode** A, int n) {
		BuildHeap(A, n);
	}
	Heap::Heap(BSTree& tree) {

		int size = tree.getSize();
		BSTreeNode** arr = new BSTreeNode * [size];
		allocated = 1;
		tree.makeArrFromTree(tree.getRoot(), arr);
		BuildHeap(arr, size);
	}

	Heap::~Heap() {
		if (allocated)
			delete[] data;
		data = nullptr;
	}

	void Heap::BuildHeap(BSTreeNode** A, int n) {
		heapSize = maxSize = n;
		data = A;
		allocated = 0;
		int i;
		for (i = n / 2 - 1; i >= 0; i--) {
			FixHeap(i);
		}
	}

	void Heap::FixHeap(int node) {
		int min = node;
		int left = Left(node);
		int right = Right(node);

		if (left < heapSize && (data[left]->getfreq() < data[min]->getfreq())) {
			min=left;
		}
		if (right < heapSize && (data[right]->getfreq() < data[min]->getfreq())) {
			min=right;
		}
		if (min != node) {
			Swap(*data[node], *data[min]);
			FixHeap(min);
		}
	}

	BSTreeNode* Heap::DeleteMin() {
		if (heapSize < 1) {
			cout << "input invalid" << endl;
			exit(1);
		}
		BSTreeNode* min = data[0];
		heapSize--;
		data[0] = data[heapSize];
		data[heapSize] = nullptr;
		FixHeap(0);
		return min;
	}

	//creates a Hoffman tree from array and returns the root
	BSTreeNode* Heap::MakeHuffmanTree() {
		
		int i;
		int freq;
		int size = heapSize;
		for (i = 1; i < size; i++) {
			BSTreeNode* node = new BSTreeNode;
			node->setLeft(DeleteMin());

			node->setRight(DeleteMin());

			freq = ((node->getLeft()->getfreq())+ (node->getRight()->getfreq()));

			node->setFrequency(freq);

			Insert(node);
			
		}
		
		return DeleteMin();
	}

	void Heap::Insert(BSTreeNode* node) {
		if (heapSize == maxSize) {//handle error!!!!
			cout << "error" << endl;
			exit(1);
		}
		int i = heapSize;
		heapSize++;
		while ((i > 0) && ((data[Parent(i)]->getfreq()) > (node->getfreq()))) {
			data[i] = data[Parent(i)];
			i = Parent(i);
		}
		data[i] = node;
	}

}

