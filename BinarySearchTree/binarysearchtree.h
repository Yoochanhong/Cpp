//
// Created by 유찬홍 on 2022/10/19.
//

#ifndef BINARYSEARCHTREE_BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_BINARYSEARCHTREE_H

#include <iostream>
using namespace std;

typedef struct _node{
    int item;
    struct _node* l_Link;
    struct _node* r_Link;
} Node;

Node *insertNode(Node* p, int tmp) {
    Node *newNode = new Node;

    if (p == NULL) {
        newNode->item = tmp;
        newNode->l_Link = NULL;
        newNode->r_Link = NULL;
        return newNode;
    }
    else if (tmp < p->item) p->l_Link = insertNode(p->l_Link, tmp);
    else if (tmp > p->item) p->r_Link = insertNode(p->r_Link, tmp);

    return p;
}


void p_out(int* p, int max){
    for(int i = 0; i<max; i++){
        cout.width(3);
        cout << *(p + i);
        cout << "\n\n";
    }
}

void In_order(Node* p){
    if (p){
        In_order(p->l_Link);
        cout.width(3);
        cout << p->item;
        In_order(p->r_Link);
    }
}
Node *Search(Node* p, int tmp){
    if (p == NULL) return NULL;
    if (tmp == p->item) return p;
    else if (tmp < p->item) return Search(p->l_Link, tmp);
    else return Search(p->r_Link, tmp);
}

#endif //BINARYSEARCHTREE_BINARYSEARCHTREE_H
