// ConsoleApplication_BinarySearchTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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
		std::cout << "Num null nodes: " << Node::nullNodes << '\n';

		std::cout << "In order listing\n";
		tree.traverseInOrder( Node::m_pRoot );

		std::cout << "PRE order listing\n";
		tree.traversePreOrder( Node::m_pRoot );

		std::cout << "POST order listing\n";
		tree.traversePostOrder( Node::m_pRoot );
	}

	return 0;
}


