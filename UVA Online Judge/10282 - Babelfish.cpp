#include <bits/stdc++.h>
using namespace std;

int main()
{
    string word, meaning;
    map<string, string> m;

    while (getline(cin, word), word != "") {
        stringstream ss(word);

        ss >> meaning >> word;

        m[word] = meaning;
    }

    while (cin >> word) {

        if (m.count(word))
            cout << m[word] << "\n";
        else
            cout << "eh\n";
    }
}

/*

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	string key;
	string value;
	int height;

	Node *left;
	Node *right;
};

int getHeight(Node *root){
	return (root ? root->height : 0);
}

int getBalance(Node *root){
	return (root ? getHeight(root->left) - getHeight(root->right) : 0);
}

Node *leftRotate(Node *root){
	Node *r = root->right;
	Node *rl = r->left;

	r->left = root;
	root->right = rl;

	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	r->height = max(getHeight(r->left), getHeight(r->right)) + 1;

	return r;
}

Node *rightRotate(Node *root){
	Node *l = root->left;
	Node *lr = l->right;

	l->right = root;
	root->left = lr;

	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	l->height = max(getHeight(l->left), getHeight(l->right)) + 1;

	return l;
}

Node *push(Node *root, string key, string value){

	if(root == NULL){
		Node *newNode = new Node;

		newNode->key = key;
		newNode->value = value;
		newNode->height = 1;
		newNode->left = NULL;
		newNode->right = NULL;

		return newNode;

	}else if(key < root->key){

		root->left = push(root->left, key, value);

	}else{

		root->right = push(root->right, key, value);

	}

	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

	int balance = getBalance(root);

	if(balance > 1 && key < root->left->key){
		return rightRotate(root);
	}

	if(balance > 1 && key > root->left->key){
		root->left = leftRotate(root->left);

		return rightRotate(root);
	}

	if(balance < -1 && key < root->right->key){
		root->right = rightRotate(root->right);

		return leftRotate(root);
	}

	if(balance < -1 && key > root->right->key){
		return leftRotate(root);
	}

	return root;

}

Node *findLeftMost(Node *root){

	if(root->left)
		return findLeftMost(root->left);

	return root;

}

Node *deleteNode(Node *root, string key){

	if(root == NULL) return NULL;
	
	if(key < root->key){

		root->left = deleteNode(root->left, key);

	}else if(key > root->key){

		root->right = deleteNode(root->right, key);

	}else{

		if(!root->left || !root->right){

			Node *temp = (root->left ? root->left : root->right);

			if(temp){
				*root = *temp;
			}else{
				temp = root;
				root = NULL;
			}

			delete temp;

		}else{

			Node *temp = findLeftMost(root->right);

			root->key = temp->key;
			root->value = temp->value;

			root->right = deleteNode(root->right, temp->key);

		}
	}

	if(root == NULL) return NULL;

	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

	int balance = getBalance(root);

	if(balance > 1 && getBalance(root->left) >= 0){
		return rightRotate(root);
	}

	if(balance > 1 && getBalance(root->left) < 0){
		root->left = leftRotate(root->left);

		return rightRotate(root);
	}

	if(balance < -1 && getBalance(root->right) <= 0){
		return leftRotate(root);
	}

	if(balance < -1 && getBalance(root->right) > 0){
		root->right = rightRotate(root->right);

		return leftRotate(root);
	}

	return root;
}

string find(Node *root, string key){
	if(root == NULL) return "";

	if(key < root->key){

		return find(root->left, key);

	}else if(key > root->key){

		return find(root->right, key);

	}else{

		return root->value;

	}
}

void view(Node *root){
	if(root == NULL) return;

	view(root->left);
	
	printf("%s %s | ", root->key.c_str(), root->value.c_str());
	
	view(root->right);
}

int main(){
	string word, meaning;
	Node *m = NULL;

	while(getline(cin, word), word != ""){
		stringstream ss(word);

		ss >> meaning >> word;

		m = push(m, word, meaning);
	}

	while(cin >> word){
		string ans = find(m, word);

		cout << (ans != "" ? ans : "eh") << "\n";
	}
}


*/