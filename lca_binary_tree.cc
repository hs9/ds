#include <iostream>
//#include <pair>

using namespace std;

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}Node;


pair<int, Node *> lca_helper(Node *tree, int a, int b)
{
    if (!tree){
        cout << "hit leaf" << endl;
        return {0, NULL};
    }
    cout << "going left from " << tree->data << endl; 
    pair <int, Node *> left_result = lca_helper(tree->left, a, b);
    if (left_result.first == 2)
        return left_result;

    cout << "going right from " << tree->data << endl; 
    pair <int, Node *> right_result = lca_helper(tree->right, a, b);
    if (right_result.first == 2)
        return right_result;

    int found_cnt = left_result.first + right_result.first + \
                    (tree->data == a || tree->data == b);
    cout << "at " << tree->data << ", found count " << found_cnt << endl;
    return {found_cnt, found_cnt == 2 ? tree : NULL};
}

Node *lca(Node *tree, int a, int b)
{
    pair<int, Node *> res = lca_helper(tree, a, b);
    return res.second;
}

Node *get_node(int d)
{
    Node *new_node = new Node;
    new_node->data = d;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

int main()
{
    Node *tree = get_node(10);
    tree->left = get_node(20);
    tree->right = get_node(30);
    tree->left->left = get_node(50);
    tree->left->right = get_node(60);
    tree->right->left = get_node(70);
    tree->right->right = get_node(80);

    Node *found_lca = lca(tree, 50, 60);
    if (!found_lca){
        cout << "lca not found" << endl;
        return -1;
    }
    cout << found_lca->data << endl;
    return 0;
}

/* output */
/*
➜  mycode git:(master) ✗ g++ lca_binary_tree.cc -std=c++11
➜  mycode git:(master) ✗ ./a.out
going left from 10
going left from 20
going left from 50
hit leaf
going right from 50
hit leaf
at 50, found count 1
going right from 20
going left from 60
hit leaf
going right from 60
hit leaf
at 60, found count 1
at 20, found count 2
20
*/
