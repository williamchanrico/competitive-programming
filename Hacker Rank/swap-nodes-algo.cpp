#include <bits/stdc++.h>
using namespace std;

struct Node {
public:
    int key;
    int height;
    struct Node* left;
    struct Node* right;
};

void swap_every_h(struct Node* root, int H)
{
    if (root == NULL)
        return;

    if ((root->height) % H == 0) {
        swap(root->left, root->right);
    }

    swap_every_h(root->left, H);
    swap_every_h(root->right, H);
}

void print_in_order(struct Node* root)
{
    if (root == NULL)
        return;

    print_in_order(root->left);
    printf("%d ", root->key);
    print_in_order(root->right);
}

void free_binary_tree(struct Node* root)
{
    if (root == NULL)
        return;
    free_binary_tree(root->left);
    free_binary_tree(root->right);
    free(root);
}

struct Node* create_node(int key, int height, struct Node* left, struct Node* right)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->height = height;
    node->left = left;
    node->right = right;
    return node;
}

int main()
{
    int N;

    scanf("%d", &N);

    int A, B;

    struct Node* root = create_node(1, 1, NULL, NULL);

    struct Node* m[1025] = {};
    m[1] = root;

    for (int a = 1; a <= N; a++) {
        scanf("%d %d", &A, &B);
        assert(m[a] != NULL);

        if (A != -1) {
            struct Node* left_child = create_node(A, m[a]->height + 1, NULL, NULL);

            m[a]->left = left_child;
            m[A] = left_child;
        }
        if (B != -1) {
            struct Node* right_child = create_node(B, m[a]->height + 1, NULL, NULL);

            m[a]->right = right_child;
            m[B] = right_child;
        }
    }

    int K;

    scanf("%d", &K);
    while (K--) {
        int H;
        scanf("%d", &H);

        swap_every_h(m[1], H);
        print_in_order(m[1]);
        printf("\n");
    }

    free_binary_tree(m[1]);
}
