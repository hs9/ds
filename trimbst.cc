#include <iostream>
#include <vector>
using namespace std;

typedef struct node {
    int d;
    struct node *l;
    struct node *r;
}Node;

Node *get_node(int n){
    Node * t = new Node;
    t->d = n;
    t->l = NULL;
    t->r = NULL;
    return t;
}

Node *make_bst(vector<Node *> &v, int l, int r){
    if (l > r)
        return NULL;

    int m = (l+r)/2;
    Node *root = v[m];
    root->l = make_bst(v, l, m-1);
    root->r = make_bst(v, m+1, r);
    return root;
}

void inorder(Node *t, vector<Node *> &v){
    if (!t)
        return;
    inorder(t->l, v);
    v.push_back(t);
    inorder(t->r, v);
}

void print_nodes(vector<Node *> &v){
    for (int i=0; i<v.size(); i++){
        cout << v[i]->d << '\t';
    }
    cout << endl;
}

Node * trim(Node *t, int _min, int _max){
    if (!t)
        return NULL;

    vector<Node *> v;
    inorder(t, v);
    // remove the unnecessary items from v
    vector<Node *>::iterator iter = v.begin();

    //vector erase returns the next iterator after delete
    while (iter != v.end()){
        if ((*iter)->d < _min || (*iter)->d > _max){
            cout << "deleting " << (*iter)->d << endl;
            delete (*iter);
            iter = v.erase(iter);
        }
        else
            ++iter;
    }
    return make_bst(v, 0, v.size()-1);
}

void print_preorder(Node *t)
{
    if (!t)
        return;
    cout << t->d << '\t';
    print_preorder(t->l);
    print_preorder(t->r);
}

void release_tree(Node *t)
{
    if (!t)
        return;
    release_tree(t->l);
    release_tree(t->r);
    delete t;
}
int minval(Node *t)
{
    while (t)
        t = t->l;
    return t->d;
}

Node *remove(Node *t, int n)
{
    if (!t)
        return NULL;
    if (n > t->d){
        // the node is on the right side
        t->r = remove(t->r, n);
    } else if ( n < t->d) {
        // the node is on the left side
        t->l = remove(t->l, n);
    } else {
        // this is the node to remove
        if (t->l == NULL && t->r == NULL){
            // this is a lead node, just delete
            delete t;
            return NULL;
        } else if (t->l == NULL) {
            // return the right child
            Node * rc = t->r;
            delete t;
            return rc;
        } else if (t->r == NULL) {
            // return the left child
            Node *lc = t->l;
            delete t;
            return lc;
        } else {
            // it has both children. Copy the min node from right side
            t->d = minval(t->r);
            // now delete the min node
            t->r = remove(t->r, t->d);
        }
    }
    return t;
}

Node *trim_tree_by_remove(Node *t, int _min, int _max){
    if (!t)
        return NULL;
    // fix the children first
    t->l = trim_tree_by_remove(t->l, _min, _max);
    t->r = trim_tree_by_remove(t->r, _min, _max);
    // fix root now
    if (t->d < _min){
        Node *rc = t->r;
        delete t;
        return rc;
    } else if (t->d > _max) {
        Node *lc = t->l;
        delete t;
        return lc;
    }
    return t;
}

int main()
{
    Node *tree = get_node(10);
    tree->l = get_node(5);
    tree->r = get_node(15);
    tree->l->l = get_node(2);
    tree->l->r = get_node(7);
    tree->r->l = get_node(12);
    tree->r->r = get_node(20);
    //tree = trim(tree, 12, 13);
    tree = trim_tree_by_remove(tree, 9, 10);
    print_preorder(tree);
    release_tree(tree);
}
