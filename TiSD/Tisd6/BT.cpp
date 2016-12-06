//
// Created by alexey on 05.12.16.
//
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

template<typename T>
struct element{
    T value;
    element<T>*left = NULL;
    element<T>*right = NULL;

    element(T x) {
        value = x;
        left = NULL;
        right = NULL;
    }

};

//Binary tree
template<typename T>
class BT {
private:
    element<T> *head = NULL;

    void operator_copy(element<T> **head, element<T> *tmp);

    void LRootR(element<T> *tmp);

    void LRRoot(element<T> *tmp);

    void RootLR(element<T> *tmp);

    void delete_tree(element<T> *tmp);


    void count_levels(element<T>*tmp, int deep,vector<int>& vector1);
    void print(element<T>* tmp, int deep, bool flag);
    void printer(element<T>*tmp, element<T>*parent, FILE *graph);

    void swap(element<T> *greater, element<T> *smaller);
    element<T>* del(element<T> *tree, T val);
    element<T> *delete_node(element<T> *tree, T val);
    element<T> *the_most_right(element<T> *tree);
    element<T>* lookup(element<T> *tree, T val);

public:
    BT(const BT &obj);
    BT() {
        head = NULL;
        //printable = true;
    }
    BT &operator=(const BT &obj) {
        operator_copy(&head, obj.head);
    }
    void levels() ;
    void insert(T x);
    void printer();

    bool remove2(T x);




    ~BT() {

        delete_tree(head);
        head = NULL;
    }

    void show_as_tree();

    bool find(T x);

    void LeftRootRight() {
        LRootR(head);
        cout << endl;
    }

    void LeftRightRoot() {
        LRRoot(head);
        cout << endl;
    }

    void RootLeftRight() {
        RootLR(head);
        cout << endl;
    }

};


template<typename T>
void BT<T>::operator_copy(element<T> **head, element<T> *tmp) {
    element<T> *a = *head;
    if (tmp) {
        a = new element<T>(tmp->value);
        operator_copy(&a->left, tmp->left);
        operator_copy(&a->right, tmp->right);
    }
}

template<typename T>
void BT<T>::insert(T x) {
    element<T> *new_elem = new element<T>(x);
    element<T> *tmp = head;
    if (!head) {
        head = new_elem;
        return;
    }
    while (1) {
        if (!tmp) {
            tmp = new_elem;
            break;
        }
        if (tmp->value < x) {
            if (tmp->right) {
                tmp = tmp->right;
            } else {
                tmp->right = new_elem;
                break;
            }
        } else {
            if (tmp->left) {
                tmp = tmp->left;
            } else {
                tmp->left = new_elem;
                break;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////


template<typename T>
bool BT<T>::remove2(T x) {
    head=delete_node(head, x);
}

template<typename T>
element<T>* BT<T>::del(element<T> *tree, T val)
{
    if (tree == NULL)
    {

        return tree;
    }
    else if (tree->value== val)
    {
        //puts("AGA");
        if (tree->left == NULL && tree->right == NULL)
        {
            //element<T>(tree);
            //puts("Element deleted!");
            return NULL;
        }
        else if (tree->left == NULL)
        {
            element<T> *tmp = tree->right;
            free(tree);
            //puts("Element deleted!");
            return tmp;
        }
        else if (tree->right == NULL)
        {
            element<T> *tmp = tree->left;
            free(tree);
            //puts("Element deleted!");
            return tmp;
        }
        else
        {
            element<T> *tmp = the_most_right(tree->left);
            //printf("%d\n", tmp->val);
            swap(tree, tmp);
            //puts("Element deleted!");
            return tree;
        }
    }
    else
    {
        //puts("TUTU");
        //printf("root: %d; val: %d\n", tree->val, val);
        element<T> *cur = tree;
        element<T> *dad = NULL;
        while (cur != NULL)
        {
            //printf("cur: %d\n", cur->val);
            if (cur->value== val)
            {
                break;
            }
            else if (cur->value> val)
            {
                dad = cur;
                cur = cur->left;
            }
            else
            {
                dad = cur;
                cur = cur->right;
            }
        }
        if (cur == NULL)
        {
            puts("Could not find the element in tree.");
            return tree;
        }
        if (cur->left == NULL && cur->right == NULL)
        {
            if (dad->value< val)
                dad->right = NULL;
            else
                dad->left = NULL;
            //free_tree(cur);
        }
        else if (cur->left == NULL)
        {
            if (dad->value< val)
                dad->right = cur->right;
            else
                dad->left = cur->right;
            free(cur);
        }
        else if (cur->right == NULL)
        {
            if (dad->value< val)
                dad->right = cur->left;
            else
                dad->left = cur->left;
            free(cur);
        }
        else
        {
            element<T> *tmp = the_most_right(cur->left);
            swap(cur, tmp);
        }
        //puts("Element deleted!");
        return tree;
    }
}

template<typename T>
element<T>* BT<T>::lookup(element<T> *tree, T val)
{
    if (tree == NULL)
        return NULL;

    if (val == tree->value)
        return tree;
    else if (val < tree->value)
        return lookup(tree->left, val);
    else
        return lookup(tree->right, val);
}

template<typename T>
element<T> *BT<T>::delete_node(element<T> *tree, T val)
{
    element<T> *tmp = lookup(tree, val);
    //memory_check(tmp, NULL, "Nothing was found!");

    tree = del(tree, val);
    return tree;
}

template<typename T>
element<T> *BT<T>::the_most_right(element<T> *tree)
{
    if (tree->left == NULL && tree->right == NULL)
        return tree;
    else if (tree == NULL)
        return NULL;
    else if (tree->right == NULL)
        return tree;
    else
        return the_most_right(tree->right);
}
template<typename T>
void BT<T>::swap(element<T> *greater, element<T> *smaller)
{
    int tmp_val = smaller->value;
    del(greater, smaller->value);
    greater->value = tmp_val;
}

///////////////////////////////////////////////////////////////////////////////////



template<typename T>
void BT<T>::delete_tree(element<T> *tmp) {
    if (tmp) {
        delete_tree(tmp->left);
        delete_tree(tmp->right);
        delete tmp;
        tmp = NULL;
    }
}

template<typename T>
BT<T>::BT(const BT &obj) {
   // log("copy");
    if (&obj != this) {
        *this = obj;
    }
}

template<typename T>
void BT<T>::LRootR(element<T> *tmp) {
    if (tmp) {
        LRootR(tmp->left);
        cout << tmp->value << " ";
        LRootR(tmp->right);
    }
}

template<typename T>
void BT<T>::LRRoot(element<T> *tmp) {
    if (tmp) {
        LRootR(tmp->left);
        LRootR(tmp->right);
        cout << tmp->value << " ";
    }
}

template<typename T>
void BT<T>::RootLR(element<T> *tmp) {
    if (tmp) {
        cout << tmp->value << " ";
        LRootR(tmp->left);
        LRootR(tmp->right);
    }
}

template<typename T>
bool BT<T>::find(T x) {
    element<T>*tmp = head;
    int cmp = 0;
    while(1) {
        if(!tmp) {
            return false;
        }
        if(tmp->value== x)
        {
         return true;
        }
        if(tmp->value< x) {
            if(tmp->right) {
                tmp = tmp->right;
            }
            else {
                return false;
            }
        }
        else {
            if(tmp->left) {
                tmp = tmp->left;
            }
            else {
                return false;
            }
        }
    }
}

template <typename T>
void BT<T>::print(element<T>*tmp, int deep, bool flag) {
    if(tmp) {
        for (int i = 0; i < deep - 1; i++) {
            cout << "|    ";
        }
        if (deep >= 1)
            cout << "|----";
        cout << tmp->value << endl;

        flag = false;
        if(tmp->left || tmp->right) { flag = true; }
        print(tmp->left, deep + 1, flag);
        print(tmp->right, deep + 1, flag);
    }
    else if(flag) {
        for (int i = 0; i < deep - 1; i++) {
            cout << "|    ";
        }
        if (deep >= 1)
            cout << "|----";
        cout << "-----" << endl;
    }
}

template<typename T>
void BT<T>::show_as_tree() {
    print(head, 0, true);
}

template <typename T>
void BT<T>::printer() {

    FILE *graph = fopen("/tmp/graph.gv", "w");
    fprintf(graph, "digraph G{\n");
    if(head !=NULL)
        fprintf(graph, "%d\n",head->value);
    printer(head, NULL, graph);
    fprintf(graph, "}");
    fclose(graph);

}


template <typename T>
void BT<T>::printer(element<T>*tmp, element<T>*parent, FILE *graph) {

    if (tmp) {
        if (parent != NULL)
            fprintf(graph, "%d->%d\n",parent->value, tmp->value);
        printer(tmp->left, tmp, graph);
        printer(tmp->right, tmp, graph);
    }
}

template <typename T>
void BT<T>::count_levels(element<T>*tmp, int deep,vector<int>& vector1) {

    if(tmp) {
        if(vector1.size()<=deep)
        {
            vector1.push_back(0);
        }
        vector1[deep]+=1;
        count_levels(tmp->left, deep + 1, vector1);
        count_levels(tmp->right, deep + 1, vector1);
    }
}

template <typename T>
void BT<T>::levels() {
    vector<int> vector1;
    count_levels(head, 0,vector1 );
    for (int i = 0; i <vector1.size() ; ++i) {
        cout<<"На уровне: "<< i<<" "<<vector1[i]<<" вершин(ы)\n";
    }
}