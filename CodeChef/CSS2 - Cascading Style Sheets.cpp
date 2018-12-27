#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main()
{
    int N, M;
    map<pii, pii> m;

    scanf("%d %d", &N, &M);

    int id, attr, val, priority;

    while (N--) {
        scanf("%d %d %d %d", &id, &attr, &val, &priority);

        pii u = make_pair(id, attr);

        if (m.count(u)) {

            if (m[u].second <= priority) {
                m[u].first = val;
                m[u].second = priority;
            }

        } else {

            m[u] = make_pair(val, priority);
        }
    }

    while (M--) {
        scanf("%d %d", &id, &attr);

        printf("%d\n", m[make_pair(id, attr)].first);
    }
}

/*

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

class Node{
public:
	pii key;
	pii value;
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

Node *push(Node *root, pii key, pii value){

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

Node *deleteNode(Node *root, pii key){

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

pii find(Node *root, pii key){
	if(root == NULL) return make_pair(-1, -1);

	if(key < root->key){

		return find(root->left, key);

	}else if(key > root->key){

		return find(root->right, key);

	}else{

		return root->value;

	}
}

int main(){
	int N, M;
	Node *m = NULL;

	scanf("%d %d", &N, &M);

	int id, attr, val, priority;

	while(N--){
		scanf("%d %d %d %d", &id, &attr, &val, &priority);

		pii u = make_pair(id, attr);

		pii v = find(m, u);

		if(!(v.first == -1) && !(v.second == -1)){

			if(v.second <= priority){
				v.first = val;
				v.second = priority;
			}

			m = deleteNode(m, u);
			m = push(m, u, v);

		}else{

			m = push(m, u, make_pair(val, priority));

		}
	}

	while(M--){
		scanf("%d %d", &id, &attr);

		printf("%d\n", find(m, make_pair(id, attr)).first);
	}
}


*/