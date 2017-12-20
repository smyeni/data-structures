// ConsoleApplication_BinarySearchTree.cpp : Defines the entry point for the console application.
//

#include "btree.h"

int main( int argc, char* args[] )
{
	{
		Node tree(100);
		tree.insert(100);
		tree.insert(70);
		tree.insert(30);
		tree.insert(35);
		tree.insert(130);
		tree.insert(89);
		tree.insert(89);
		tree.insert(43);
		tree.insert(0);
		tree.insert(140);
		tree.insert(129);
		tree.insert(120);
		tree.insert(130);
		tree.insert(150);
		tree.insert(144);
		tree.insert(160);
		tree.insert(132);

		//std::cout << "In order listing\n";
		//tree.traverseInOrder( Node::m_pRoot );

		std::cout << "Num null nodes: " << Node::nullNodes << '\n';

		//std::cout << "PRE order listing\n";
		//tree.traversePreOrder( Node::m_pRoot );

		std::cout << "POST order listing\n";
		tree.traversePostOrder( Node::m_pRoot );

		//Search for specific node
		Node *pNode = tree.findNode(100);
		if (pNode)
		{
			std::cout << "Found node [" << *pNode << "]\n";
		}
		else
		{
			std::cout << "Not found\n";
		}

		pNode = nullptr;
		pNode = tree.findNode(89);
		if (pNode)
		{
			std::cout << "Found node [" << *pNode << "]\n";
		}
		else
		{
			std::cout << "Not found\n";
		}

		//Deletion & printout
		double del = 43;
		//tree.deleteNode(43);
		tree.deleteNode(140);
		std::cout << "After deleting [" << del << "]\n";

		//std::cout << "In order listing\n";
		//tree.traverseInOrder(Node::m_pRoot);

		//std::cout << "PRE order listing\n";
		//tree.traversePreOrder(Node::m_pRoot);

		std::cout << "POST order listing\n";
		tree.traversePostOrder(Node::m_pRoot);


		//FindMinimum
		Node *min = tree.findMin(150);
		min = tree.findMin(130);
		min = tree.findMin(100);
		min = tree.findMin(89);
		min = tree.findMin(35);
	}

	return 0;
}



