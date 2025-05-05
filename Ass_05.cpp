#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

struct Node
{
	char keyword[20];
	char meaning[40];
	Node* lchild;
	Node* rchild;
	Node()
	{
		strcpy(keyword, "");
		strcpy(meaning, "");
		lchild = nullptr;
		rchild = nullptr;
	}
	Node(char keyy[], char mean[])
	{
		strcpy(keyword, keyy);
		strcpy(meaning, mean);
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
		
		void insert(char keyy[], char mean[])
		{
			Node *newnode = new Node(keyy, mean);
			if(root == NULL)
			{
				root = newnode;
				cout << "KeyWord Inserted." << endl;
				return;
			}
			Node *temp = root;
			while(temp != NULL)
			{
				if(strcmp(newnode->keyword, temp->keyword) < 0) {
					if(temp->lchild != nullptr) 
						temp = temp->lchild;
					else {
						temp->lchild = newnode;
						cout << "Value Inserted" << endl;
						return;
					}
				}else {
					if(temp->rchild != nullptr)
						temp = temp->rchild;
					else {
						temp->rchild = newnode;
						cout << "Value Inserted" << endl;
						return;
					}
				}
			}
		}
		
		Node* search(char keyy[])
		{
			Node* temp = root;
			int comparisons = 0;
			while(temp != NULL)
			{
				if(strcmp(keyy, temp->keyword) == 0)
				{
					cout << "Keyword Found." << endl;
					cout << "Comparsons  =  " << comparisons << endl;
					return temp;
				}
				if(strcmp(keyy, temp->keyword) > 0)
					temp = temp->rchild;
				else
					temp = temp->lchild;
				comparisons++;
			}
			cout << "Keyword Not Found" << endl;
			return NULL;
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
					cout << current->keyword << " : " << current->meaning << endl;
					current = current->rchild;
				}
			}
		}
		void display_descending(Node *root)
		{
			if(root == NULL)
				return;
			display_descending(root->rchild);
			cout << root->keyword << " : " << root->meaning << endl;
			display_descending(root->lchild);
		}
		
		void modify(char keyy[], char new_meaning[])
		{
			 Node *found = search(keyy);
			 if(found != NULL)
			 	strcpy(found->meaning, new_meaning);
			cout << "Node Updated" << endl;
		}
		
		void delete_key(char keyy[])
		{
			Node* search_node = root;
			Node* parent = NULL;
			Node* successor = NULL;
			Node* successor_parent;
			bool isleft = false;
			search_node = search(keyy);
			parent = getParent(search_node, isleft);
			if(search_node == NULL)
			{
				cout << "No such node." << endl;
				return;
			}
			
			//condition for leaf node deletion
			if(search_node->lchild == nullptr && search_node->rchild == nullptr) {
				if(search_node == root)
					root = NULL;
				else if(isleft)
					parent->lchild = nullptr;
				else
					parent->rchild = nullptr;
			
			}
			//condition for deleting node with 2 children.
			else if(search_node->lchild != nullptr && search_node->rchild != nullptr) {
				successor = getSuccessor(search_node->rchild);
				successor_parent = getParent(successor, isleft);

				strcpy(search_node->keyword, successor->keyword);
        		strcpy(search_node->meaning, successor->meaning);

				if(successor_parent == search_node) // if only one child in right of successor as left is null
					search_node->rchild = successor->rchild;
				else
					successor_parent->lchild = successor->rchild; //else assign right to successor_parent as it can be null or child
				
				search_node = successor;
			}
			// below 2 are condition for node with only either left or right child
			else if(search_node->lchild != nullptr) {
				if(search_node == root)
					root = search_node->lchild;
				else if(isleft)
					parent->lchild = search_node->lchild;
				else
					parent->rchild = search_node->lchild;
			
			}else {
				if(search_node == root)
					root = search_node->rchild;
				else if(isleft)
					parent->lchild = search_node->rchild;
				else
					parent->rchild = search_node->rchild;
			}

			delete search_node;
			cout << "Node Deleted." << endl;	
			
		}
		Node* getParent(Node *children, bool &lch)
		{
			Node* temp = root;
			Node* parent = NULL;
			while(temp != children)
			{
				parent = temp;
				if(strcmp(children->keyword, temp->keyword) > 0)
				{
					temp = temp->rchild;
					lch = false;
				}	
				else{
					temp = temp->lchild;
					lch = true;
				}
			}
			return parent;
		}
		Node* getSuccessor(Node *roott) //search right subtree
		{
			while(roott->lchild != nullptr)
				roott = roott->lchild;
			return roott;
		}
};

int main()
{
	BinarySearchTree bst;
	Node *tmp;
	char keyy[20], meaning[40], new_meaning[20];
	int ch = 0;
	int val;
    do
    {
        cout << "\n1. Insert Data." << endl;
        cout << "2. Search a Value." << endl;
        cout << "3. Display Data." << endl;
        cout << "4. Modify Data." << endl;
		cout << "5. Delete Data." << endl;
        cout << "0. Exit." << endl;
        cout << "Enter Your Choice : ";
        cin >> ch;
		cin.ignore();
        switch(ch)
        {
            case 1: cout << "Enter Keyword : ";
					cin.getline(keyy, 20);
					cout << "Enter Meaning : ";
					cin.getline(meaning, 40);
					bst.insert(keyy, meaning);
                    break;
			case 2: cout << "Enter key to search : ";
					cin.getline(keyy, 20);
					bst.search(keyy);
					break;
            case 3: bst.inorder();//bst.display(bst.getRootNode());
					break;
			case 4: cout << "Enter Keyword     : ";
					cin.getline(keyy, 20);
					cout << "Enter New Meaning : ";
					cin.getline(new_meaning, 40);
					bst.modify(keyy, new_meaning);
					break;
			case 5: cout << "Enter key to search : ";
					cin.getline(keyy, 20);
					bst.delete_key(keyy);
					break;
            case 0: exit(0);

            default:cout << "Invalid Choice.";
            		break;
        }
    } while (ch != 0);

	return 0;
}