#include <iostream>
using namespace std;

#define MX 10
#define FALSE 0
#define TRUE 1

typedef int element;

typedef struct _node {
    element dat;
    struct _node* Link;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} LQueType;

typedef struct GraphType{
    int n;
    int visited[MX];
    Node* adjList_H[MX];
} GraphType;

LQueType* createLinkedQue();
int is_empty(LQueType* LQ);
void EnQue(LQueType* LQ, element item);
element DeQue(LQueType* LQ);
void createGraph(GraphType* g);
void insertVertex(GraphType* g, int v);
void insertEdge(GraphType* g, int u, int v);
void printGraph(GraphType* g);
void DFS_adjList(GraphType* g, int v);

enum { A, B, C, D, E, F, G, H, I, J };
int V1, SU1; //V1-그래프의 정점수(벌텍스), SU1-그래프의 간선수(엣지수)

int main()
{
    int a;
    element vert[] = { A, B, C, D, E, F, G };
    int in1[]   = { A, A, A, A, B, B, B, C, C, D, E, E, F, G };
    int out1[]  = { G, E, C, B, F, E, A, D, A, C, B, A, B, A };
    V1 = sizeof(vert) / sizeof(element);
    SU1 = sizeof(in1) / sizeof(element);

    GraphType* G1 = new GraphType;
    createGraph(G1);

    for (a = 0; a < V1; a++) {
        insertVertex(G1, a);
    }

    for(a = 0; a < SU1; a++) {
        insertEdge(G1, in1[a], out1[a]);
    }

    cout << "\n\n G1의 인접리스트"; printGraph(G1);
    cout << "\n\n 깊이 우선 탐색 >>"; DFS_adjList(G1, B);
    cout << "\n\n";
}

LQueType* createLinkedQue() {
    LQueType* LQ = new LQueType;
    LQ->front = NULL;
    LQ->rear = NULL;

    return LQ;
}

int isEmpty(LQueType* LQ) {
    if (LQ->front == NULL)
        return 1;
    else
        return 0;
}

void EnQue(LQueType* LQ, element item) {
    Node* NewNode = new Node;
    NewNode->dat = item;
    NewNode->Link = NULL;

    if (isEmpty(LQ)) {
        LQ->front = NewNode;
        LQ->rear = NewNode;
    }
    else {
        LQ->rear->Link = NewNode;
        LQ->rear = NewNode;
    }
}

element DeQue(LQueType* LQ) {
    Node* old = LQ->front;
    element item;

    if (isEmpty(LQ)) {
        cout << "\n\n The Que is Empty!\n";
    }
    else {
        item = old->dat;
        LQ->front = LQ->front->Link;
        if (LQ->front = NULL)
            LQ->rear = NULL;
        free(old);
    }
    return item;
}

void createGraph(GraphType* g) {
    g->n = 0;

    for (int v = 0; v < V1; v++) {
        g->visited[v] = 0;
        g->adjList_H[v] = NULL;
    }
}

void insertVertex(GraphType* g, int v) {
    if ((g->n) + 1 > V1) {
        cout << "\n 그래프 정점의 개수를 초과하였습니다.";
        return;
    }
    g->n++;
}

void insertEdge(GraphType* g, int u, int v) {
    Node* GNode = new Node;
    if (u >= g->n || v >= g->n) {
        cout << "\n 그래프에 없는 정점입니다";
        return;
    }

    GNode->dat = v;
    GNode->Link = g->adjList_H[u];
    g->adjList_H[u] = GNode;
}

void printGraph(GraphType* g) {
    int a;
    char t;
    Node* p;

    for (a = 0; a < g->n; a++) {
        t = a + 65;
        cout << "\n 정점 " << t << "의 인접 리스트 : " << t;
        p = g->adjList_H[a];
        while (p) {
            t = p->dat+65;
            cout << " -> " << t;
            p = p->Link;
        }
    }
}

void DFS_adjList(GraphType* g, int v) {
    Node* w;
    char ch;
    LQueType* Q = createLinkedQue();

    g->visited[v] = TRUE;
    ch = v + 65;
    cout << " " << ch;
    EnQue(Q, v);

    while (!isEmpty(Q)) {
        v = DeQue(Q);
        for (w = g->adjList_H[v]; w; w= w->Link)
        {
            if(!g->visited[w->dat]) {
                g->visited[w->dat] = TRUE;
                ch = w->dat + 65;
                cout << " " << ch;
                EnQue(Q, w->dat);
            }
        }
    }
}