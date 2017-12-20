#include <iostream>

class Node
{
	public:
		Node( double data ) 
			: m_data(data)
			, m_pLeft(nullptr)
			, m_pRight(nullptr)
		{
			if ( !Node::m_pRoot )
			{
				Node::m_pRoot = this;
			}
		}

		//-----------------------------------------------------------------------//

		~Node() 
		{
			if (m_pLeft)
			{
				//delete m_pLeft;
				m_pLeft = nullptr;
			}

			if (m_pRight)
			{
				//delete m_pRight;
				m_pRight = nullptr;
			}
		}

		//------------------------------------------------------------------------//

		Node *findNode( int data )
		{
			Node *currentNode = m_pRoot;

			while ( currentNode )
			{
				if ( data == currentNode->m_data )
				//Found!
				{
					break;
				}

				//Advance current node ( left or right )
				if ( data < currentNode->m_data ) 
				{
					currentNode = currentNode->m_pLeft;
				}
				else if ( data > currentNode->m_data )
				{
					currentNode = currentNode->m_pRight;
				}
			};

			return currentNode;
		}

		//------------------------------------------------------------------------//

		Node *findMin( int data )
		{
			Node *currentNode = findNode(data);

			while ( currentNode )
			{
				if ( !currentNode->m_pLeft )
				{
					break;
					//return currentNode;
				}

				currentNode = currentNode->m_pLeft;
				//currentNode = findMin( currentNode->m_pLeft->m_data );
			};

			return currentNode;
		}

		//------------------------------------------------------------------------//

		Node *findParent( int data )
		{
			Node *parentNode = nullptr;
			Node *childNode = m_pRoot;

			while ( childNode )
			{
				parentNode = childNode;

				//Advance current node (leave parent behind)
				if ( data < childNode->m_data ) 
				{
					childNode = childNode->m_pLeft;
				}
				else if ( data > childNode->m_data )
				{
					childNode = childNode->m_pRight;
				}
				else
				//Reject duplicate
				{
					//childNode = nullptr; 
					parentNode = nullptr;
					break;
				}

				//check child's data
				if ( childNode && (data == childNode->m_data) )
				{
					break;
				}
			};

			return parentNode;
		}

		//------------------------------------------------------------------------//

		bool insert( int data )
		{
			Node* pNode = new Node(data);

			if ( m_pRoot == nullptr )
			{
				m_pRoot = pNode;
				return false;
			}

			//search for parent node
			Node *duplicate = findNode( data );
			if ( duplicate )
			{
				std::cout << "Duplicate insert: [" << data << "]\n";
				return false;
			}

			//attach new node to identified parent node
			Node *parentNode = findParent( data );
			if (data > parentNode->m_data) 
			{
				parentNode->m_pRight = pNode;	
			}
			if (data < parentNode->m_data) 
			{
				parentNode->m_pLeft = pNode;	
			}

			return true;
		} //insert()

		//------------------------------------------------------------------------//

		bool deleteNode( int data )
		{
			if ( m_pRoot == nullptr )
			{
				return false;
			}

			Node* toDelete = nullptr;

			//search for parent node
			Node *parent = findParent( data );

			if ( !parent )
			{
				std::cout << "Not found: [" << data << "]\n";
				return false;
			}

			//Deletion
			if (data > parent->m_data) 
			{
				toDelete = parent->m_pRight;	
			}
			else if (data < parent->m_data) 
			{
				toDelete = parent->m_pLeft;	
			}

			if ( (toDelete->m_pLeft == nullptr) && (toDelete->m_pRight == nullptr) ) 
			//Deleting a Leaf node
			{
				delete toDelete;

				//avoid dangling pointer - set parent's child pointer to null
				if (data > parent->m_data) 
				{
					parent->m_pRight = nullptr;	
				}
				else if (data < parent->m_data) 
				{
					parent->m_pLeft = nullptr;	
				}
			}
			else if ( (toDelete->m_pLeft == nullptr) && toDelete->m_pRight ) 
			{
				parent->m_pRight = toDelete->m_pRight;	
				delete toDelete;
			}
			else if ( (toDelete->m_pRight == nullptr) && toDelete->m_pLeft ) 
			{
				parent->m_pLeft = toDelete->m_pLeft;	
				delete toDelete;
			}
			else
			{
				//Find min (right side) child, copy its value into outgoing node, delete child
				Node *pMin = findMin( toDelete->m_pRight->m_data );
				int temp = pMin->m_data; //save this for after deletion
				bool isOK = deleteNode( pMin->m_data );
				toDelete->m_data = temp; //do this last to avoid duplicates in tree
			}

			return true;
		} //delete()


		//-----------------------------------------------------------------------//

		void traverseInOrder( Node* node )
		{
			if ( !node )
			{
				nullNodes++;
				return;
			}

			//Visit children
			traverseInOrder( node->m_pLeft );
			std::cout << ++count << ". " << node->m_data << '\n';
			traverseInOrder( node->m_pRight );
		}

		//-----------------------------------------------------------------------//

		void traversePostOrder( Node* node )
		{
			if ( !node )
			{
				nullNodes++;
				return;
			}

			//Visit children
			traversePostOrder( node->m_pLeft );
			traversePostOrder( node->m_pRight );
			std::cout << ++count << ". " << node->m_data << '\n';
		}

		//-----------------------------------------------------------------------//

		void traversePreOrder( Node* node )
		{
			if ( !node )
			{
				nullNodes++;
				return;
			}

			std::cout << ++count << ". " << node->m_data << '\n';

			//Visit children
			traversePreOrder( node->m_pLeft );
			traversePreOrder( node->m_pRight );
		}

		//-----------------------------------------------------------------------//

		double GetData() const
		{
			return m_data;
		}

		//-----------------------------------------------------------------------//

		friend std::ostream& operator<<( std::ostream& os, const Node &node )
		{
			os << node.GetData();
			return os;
		}

		//-----------------------------------------------------------------------//

	private:
		double m_data;
		Node *m_pLeft;
		Node *m_pRight;

	public:
		static Node* m_pRoot;
		static int nullNodes;
		static int count;
};

//Static initialization
Node* Node::m_pRoot = nullptr;
int Node::nullNodes = 0;
int Node::count = 0;

