#include <iostream>
#include "binarysearchtree.h"

int main() {
    using namespace std;
    int data[] = {6, 2, 7, 4, 9, 3, 4, 8};
    int max = sizeof(data) / 4;
    p_out(data, max);
    Node* root = insertNode(NULL, data[0]);
    for (int i = 0; i<max; i++){
        insertNode(root, data[i]);
    }
    In_order(root);
    int a;
    cout << "\n\n 찾을 수(-9 to END): ";
    cin >> a;
    while(a != -9){
        if (Search(root, a)){
            cout.width(22);
            cout << a << "발견";
        }
        else {cout << "         찾는 자료는 없어요!!!";
        cout << "\n\n 찾을 수(-9 To END): ";
        cin >> a;}
    }
    return 0;
}
