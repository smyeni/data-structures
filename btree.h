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
				delete m_pLeft;
				//m_pLeft = nullptr;
			}

			if (m_pRight)
			{
				delete m_pRight;
				//m_pRight = nullptr;
			}
		}

		//------------------------------------------------------------------------//

		Node *findInsertionPoint( int data )
		{
			Node *parentNode = nullptr;
			Node *currentNode = m_pRoot;

			while ( currentNode )
			{
				parentNode = currentNode;

				//Advance current node (leave parent behind)
				if ( data < currentNode->m_data ) 
				{
					currentNode = currentNode->m_pLeft;
				}
				else if ( data > currentNode->m_data )
				{
					currentNode = currentNode->m_pRight;
				}
				else
				//Reject duplicate
				{
					currentNode = nullptr; 
					parentNode = nullptr;
				}
			};

			return parentNode;
		}

		//------------------------------------------------------------------------//

		void insert( int data )
		{
			Node* pNode = new Node(data);

			if ( m_pRoot == nullptr )
			{
				m_pRoot = pNode;
				return;
			}

			//search for parent node
			Node *parentNode = findInsertionPoint( data );

			if ( !parentNode )
			{
				std::cout << "Duplicate insert: [" << data << "]\n";
				return;
			}

			//attach new node to identified parent node
			if (data > parentNode->m_data) 
			{
				parentNode->m_pRight = pNode;	
			}
			if (data < parentNode->m_data) 
			{
				parentNode->m_pLeft = pNode;	
			}

			return;
		} //insert()

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

