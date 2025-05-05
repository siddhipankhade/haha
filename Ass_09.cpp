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
	int height;
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
		height = 1;
	}
};

class BinarySearchTree
{
	public:
		Node *root;
		BinarySearchTree() { root = NULL; }

		int getHeight(Node* node) {  return node == nullptr ? 0 : node->height;  }
		int getBalanceFactor(Node* node) {  return (node == nullptr) ? 0 : getHeight(node->lchild) - getHeight(node->rchild);  }

		Node* insert(Node* node, char keyy[], char mean[])
		{
			if(node == NULL) {
				node = new Node(keyy, mean);
				return node;
			}
			if(strcmp(keyy, node->keyword) < 0)
				node->lchild = insert(node->lchild, keyy, mean);
			else if(strcmp(keyy, node->keyword) > 0)
				node->rchild = insert(node->rchild, keyy, mean);
			else{
				cout << "Duplicate Found..." << endl;
				return node;
			}

			node->height = 1 + max(getHeight(node->lchild), getHeight(node->rchild));
			
			int balance = getBalanceFactor(node);
			
			if(balance > 1 && strcmp(keyy, node->lchild->keyword) < 0)
				return rotateRight(node);

			if(balance < -1 && strcmp(keyy, node->rchild->keyword) > 0)
				return rotateLeft(node);
			
			if(balance > 1 && strcmp(keyy, node->lchild->keyword) > 0) {
				node->lchild = rotateLeft(node->lchild);
            	return rotateRight(node);
			}
			
			if(balance < -1 && strcmp(keyy, node->rchild->keyword) < 0) {
				node->rchild = rotateRight(node->rchild);
            	return rotateLeft(node);
			}
			
			return node;
		}
		void inorder(Node* node) {
			if (node == nullptr) return;
			inorder(node->lchild);
			cout << node->keyword << " : " << node->meaning << " : " << node->height << endl;
			inorder(node->rchild);
		}
		void modify(char keyy[], char new_meaning[])
		{
			Node* temp = root;
			while(temp != NULL)
			{
				if(strcmp(keyy, temp->keyword) == 0) break;

				if(strcmp(keyy, temp->keyword) > 0) temp = temp->rchild;
				else temp = temp->lchild;
			}
			if(temp != NULL){
				strcpy(temp->meaning, new_meaning);
				cout << "Node Updated" << endl;
			}else{
				cout << "Node not found.." << endl;
			}
		}
		
		Node *deleteNode(Node *node, char keyy[])
		{
			if(node == nullptr){
				cout << "Not Found." << endl;
				return node;
			}
			if (strcmp(keyy, node->keyword) < 0)
				node->lchild = deleteNode(node->lchild, keyy);
			else if (strcmp(keyy, node->keyword) > 0)
				node->rchild = deleteNode(node->rchild, keyy);
			else {
				if(node->lchild == nullptr || node->rchild == nullptr)
				{
					Node* temp = node->lchild ? node->lchild : node->rchild;
					delete node;
					return temp;
				}
				Node* temp = node->rchild;
				while (temp->lchild)
					temp = temp->lchild;
				strcpy(node->keyword, temp->keyword);
				strcpy(node->meaning, temp->meaning);
				node->rchild = deleteNode(node->rchild, temp->keyword);
			}
		
			node->height = 1 + max(getHeight(node->lchild), getHeight(node->rchild));
			int balance = getBalanceFactor(node);
			
			if(balance > 1 && strcmp(keyy, node->lchild->keyword) < 0)
				return rotateRight(node);

			if(balance < -1 && strcmp(keyy, node->rchild->keyword) > 0)
				return rotateLeft(node);
			
			if(balance > 1 && strcmp(keyy, node->lchild->keyword) > 0) {
				node->lchild = rotateLeft(node->lchild);
            	return rotateRight(node);
			}
			
			if(balance < -1 && strcmp(keyy, node->rchild->keyword) < 0) {
				node->rchild = rotateRight(node->rchild);
            	return rotateLeft(node);
			}
			
			return node;
		}
		
		Node* getPredecessor(Node *roott)
		{
			while(roott->rchild != nullptr)
				roott = roott->rchild;
			return roott;
		}
		
		Node* rotateRight(Node* roott)
		{
			Node *center = roott->lchild;
			Node *temp = center->rchild;

			center->rchild = roott;
			roott->lchild = temp;

			roott->height = max(getHeight(roott->lchild),	 getHeight(roott->rchild)) + 1;
        	center->height = max(getHeight(center->lchild), getHeight(center->rchild)) + 1;
        	
			return center; 
		}
		
		Node* rotateLeft(Node* roott)
		{
			Node *center = roott->rchild;
			Node *temp = center->lchild;

			center->lchild = roott;
			roott->rchild = temp;

			roott->height = max(getHeight(roott->lchild),	 getHeight(roott->rchild)) + 1;
        	center->height = max(getHeight(center->lchild), getHeight(center->rchild)) + 1;
        	
			return center; 
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
        cout << "2. Display Data." << endl;
        cout << "3. Modify Data." << endl;
		cout << "4. Delete Data." << endl;
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
					bst.root = bst.insert(bst.root, keyy, meaning);
                    bst.inorder(bst.root);
					break;
			case 2: bst.inorder(bst.root);
					break;
			case 3: cout << "Enter Keyword     : ";
					cin.getline(keyy, 20);
					cout << "Enter New Meaning : ";
					cin.getline(new_meaning, 40);
					bst.modify(keyy, new_meaning);
					bst.inorder(bst.root);
					break;
			case 4: cout << "Enter key to delete : ";
					cin.getline(keyy, 20);
					bst.deleteNode(bst.root, keyy);
					bst.inorder(bst.root);
					break;
            case 0: exit(0);

            default:cout << "Invalid Choice.";
            		break;
        }
    } while (ch != 0);

	return 0;
}