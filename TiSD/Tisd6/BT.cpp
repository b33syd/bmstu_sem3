//
// Created by alexey on 05.12.16.
//
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#define ANSI_COLOR_RESET   "\x1b[0m"
#define KRED  "\x1B[31m"
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

    void remove(element<T> *prev, element<T> *tmp);
    void count_levels(element<T>*tmp, int deep,vector<int>& vector1);
    void print(element<T>* tmp, int deep, bool flag, char c = '\0');
    void printer(element<T>*tmp, element<T>*parent, FILE *graph);

public:
    BT(const BT &obj);

    BT() {
        head = NULL;
        //printable = true;
    }

    //int find_letter(char c);

    BT &operator=(const BT &obj) {
        operator_copy(&head, obj.head);
    }
    void levels() ;
    void insert(T x);
    void printer();
    bool remove(T x);

    ~BT() {
        //log("~");
        delete_tree(head);
        head = NULL;
    }
    //void show(char c = '\0');
    void show_as_tree(char c = '\0');

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

template<typename T>
void BT<T>::remove(element<T> *prev, element<T> *tmp) {
    element<T> *b = NULL;
    int flag = 0;
    if ((!tmp->left) && (!tmp->right)) {
        b = NULL;
        flag = 1;
    }
    if (tmp->left && !tmp->right) {
        b = tmp->left;
        flag = 1;
    }
    if (!tmp->left && tmp->right) {
        b = tmp->right;
        flag = 1;
    }
    if (flag) {
        if (prev == NULL || prev == tmp) {
            head = b;
        }
        if (prev->left == tmp) {
            prev->left = b;
        } else if (prev->right == tmp) {
            prev->right = b;
        }
        delete tmp;
        return;
    }
    element<T> *a = tmp->right;
    element<T> *new_elem = tmp;
    while (a) {

        if (a->left) {
            new_elem = a;
            a = a->left;
        } else {
            break;
        }
    }
    tmp->value = a->value;
    if (new_elem->left == a) {
        new_elem->left = a->right;
    } else {
        new_elem->right = a->right;
    }
    delete a;
}

template<typename T>
bool BT<T>::remove(T x) {
    element<T>*tmp = head;
    element<T>*prev = NULL;
    int cmp = 0;
    while (1) {
        if (!tmp) {
            return false;
        }
        if (x == tmp->value) {
            remove(prev, tmp);
            return true;
        }
        prev = tmp;
        if (cmp < x) {
            if (tmp->right) {
                tmp = tmp->right;
            } else {
                return false;
            }
        } else {
            if (tmp->left) {

                tmp = tmp->left;
            } else {
                return false;
            }
        }
    }

}

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
void BT<T>::print(element<T>*tmp, int deep, bool flag, char c) {
    if(tmp) {
        for (int i = 0; i < deep - 1; i++) {
            cout << "|    ";
        }
        if (deep >= 1)
            cout << "|----";
        if(c && tmp->value == c) {
            printf(KRED);
        }
        cout << tmp->value << endl;
        printf(ANSI_COLOR_RESET);
        flag = false;
        if(tmp->left || tmp->right) { flag = true; }
        print(tmp->left, deep + 1, flag, c);
        print(tmp->right, deep + 1, flag, c);
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
void BT<T>::show_as_tree(char c) {
    print(head, 0, true, c);
}

template <typename T>
void BT<T>::printer() {

    FILE *graph = fopen("/tmp/graph.gv", "w");
    fprintf(graph, "digraph G{\n");
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