#include <iostream>
#include <stack>
using namespace std;

struct Node
{
	int data;
	Node* lchild;
	Node* rchild;
	Node()
	{
		data = 0;
		lchild = nullptr;
		rchild = nullptr;
	}
	Node(int val)
	{
		data = val;
		lchild = nullptr;
		rchild = nullptr;
	}
};

class BinarySearchTree
{
	private:
		Node *root;
		stack<Node*> st;
		
	public:
		BinarySearchTree() { root = NULL; }
		Node* getRootNode() { return root; }
		Node* create_node(int val)
		{
			Node *newnode = new Node(val);
			return newnode;
		}
		void insert(int val)
		{
			Node *newnode = new Node(val);
			if(root == NULL)
			{
				root = newnode;
				cout << "Value Inserted." << endl;
				return;
			}
			Node *temp = root;
			while(temp != NULL)
			{
				if(newnode->data < temp->data) {
					if(temp->lchild == nullptr) {
						temp->lchild = newnode;
						break;
					}
					temp = temp->lchild;
				}else {
					if(temp->rchild == nullptr) {
						temp->rchild = newnode;
						break;
					}	
					temp = temp->rchild;
				}
			}
			cout << "Value Inserted" << endl;
			return;
		}
		int getLongestPath(Node *parent)
		{
			if(parent == NULL)
				return 0;
			return max(getLongestPath(parent->lchild), getLongestPath(parent->rchild))+1;
		}
		int getmin()
		{
			if(root == NULL)
				return 0;
			Node* temp = root;
			while(temp->lchild != nullptr)
				temp = temp->lchild;
			return temp->data;
		}
		void inorder()
		{
			if (root == NULL) {
				cout << "Tree is empty." << endl;
				return;
        	}
			Node *current = root;
			while(current != nullptr || !st.empty())
			{
				if(current != nullptr) {
					st.push(current);
					current = current->lchild;
				} else {	
					current = st.top();
					st.pop();
					cout << current->data << " ";
					current = current->rchild;
				}
			}
		}
		void search(int val)
		{
			Node* temp = root;
			while(temp != NULL)
			{
				if(temp->data == val)
				{
					cout << "Value Found." << endl;
					return;
				}
				if(val < temp->data) temp = temp->lchild;
				else temp = temp->rchild;
			}
			cout << "Value Not Found" << endl;
		}
		void swap(Node* parent)
		{
			if(parent == nullptr)
				return;
			Node *temp2 = parent->lchild;
			parent->lchild = parent->rchild;
			parent->rchild = temp2;
			swap(parent->rchild);
			swap(parent->lchild);
		}
		
};

int main()
{
	BinarySearchTree bst;
	
	int ch = 0;
	int val;
    do
    {
        cout << "\n1. Insert Data." << endl;
        cout << "2. Longest Path." << endl;
        cout << "3. Get Minimum" << endl;
		cout << "4. Swap Nodes." << endl;
        cout << "5. Search a Value." << endl;
        cout << "6. Display Data." << endl;
        cout << "0. Exit." << endl;
        cout << "Enter Your Choice : ";
        cin >> ch;
        switch(ch)
        {
            case 1: cout << "Enter Value : ";
					cin >> val;
					bst.insert(val);
                    break;
			case 2: cout << "Number of nodes in Longest Path = " << bst.getLongestPath(bst.getRootNode()) << endl;
                    break;
            case 3: cout << "Minimum Value in tree = " << bst.getmin() << endl;
                    break;
			case 4: bst.swap(bst.getRootNode());
					cout << "Nodes Swapped." << endl;
					break;
			case 5: cout << "Enter value to search : ";
					cin >> val;
					bst.search(val);
					break;
            case 6: bst.inorder();
					break;
            case 0: exit(0);

            default:cout << "Invalid Choice.";
        }
    } while (ch != 0);

	return 0;
}