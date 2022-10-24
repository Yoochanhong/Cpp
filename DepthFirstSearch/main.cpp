#include <iostream>

using namespace std;


#define MX 10
#define FALSE 0
#define TRUE 1

typedef int element;

typedef struct _node {
    element dat;
    struct _node *Link;
} Node;

typedef struct GraphType {
    int n;
    int visited[MX];
    Node *adjList_H[MX];
} GraphType;

enum {
    A, B, C, D, E, F, G, H, I, J
};
Node *StackTop = NULL;
int V1, SU1;

int isEmpty();

void push(element item);

element pop();

void createGraph(GraphType *g);

void insertVertex(GraphType *g, int u);

void insertEdge(GraphType *g, int u, int v);

void printGraph(GraphType *g);

void DFS_adjList(GraphType *g, int v);

int main() {
    int a;
    element vert[] = {A, B, C, D, E, F, G};
    int in1[] = {A, A, B, B, B, C, C, D, D, E, E, E, F, G, G, G};
    int out1[] = {G, E, C, B, F, E, A, D, A, C, B, A, B, A};
    V1 = sizeof(vert) / sizeof(element);
    SU1 = sizeof(in1) / sizeof(element);

    GraphType *G1 = new GraphType;
    createGraph(G1);

    for (a = 0; a < V1; a++) {
        insertVertex(G1, a);
    }

    for (a = 0; a < SU1; a++) {
        insertEdge(G1, in1[a], out1[a]);
    }

    cout << "\n\n G1의 인접리스트";
    printGraph(G1);

    cout << "\n\n 깊이 우선 탐색 >>";
    DFS_adjList(G1, 0);
    return 0;
}

void push(element item) {
    Node *Tmp = new Node;
    Tmp->dat = item;
    Tmp->Link = StackTop;
    StackTop = Tmp;
}

element pop() {
    element item;
    Node *Tmp = StackTop;

    if (isEmpty()) {
        cout << "\n\n Stack is Empty V!!\n";
        return 0;
    } else {
        item = Tmp->dat;
        StackTop = Tmp->Link;
        free(Tmp);
        return item;
    }
}

void createGraph(GraphType *g) {
    g->n = 0;
    for (int v = 0; v < V1; v++) {
        g->visited[v] = 0;
        g->adjList_H[v] = NULL;
    }
}

void insertVertex(GraphType *g, int v) {
    if ((g->n) + 1 > V1) {
        cout << "\n 그래프 정점의 개수를 초과하였습니다";
        return;
    }
    g->n++;
}

void insertEdge(GraphType *g, int u, int v) {
    Node *GNode = new Node;
    if (u >= g->n || v >= g->n) {
        cout << "\n 그래프에 없는 정점입니다";
        return;
    }
    GNode->dat = v;
    GNode->Link = g->adjList_H[u];
    g->adjList_H[u] = GNode;
}

int isEmpty() {
    if (StackTop == NULL) return 1;
    else return 0;
}

void printGraph(GraphType *g) {
    int a;
    Node *p;

    for (a = 0; a < g->n; a++) {
        printf("\n 정점 %c의ㅣ 인접 리스트 : %c", a + 65, a + 65);
        p = g->adjList_H[a];
        while (p) {
            printf(" -> %c", p->dat + 65);
            p = p->Link;
        }
    }
}

void DFS_adjList(GraphType *g, int v) {
    Node *w;
    StackTop = NULL;
    push(v);
    g->visited[v] = TRUE;
    printf(" %c", v + 65);

    while (!isEmpty()) {
        w = g->adjList_H[v];
        while (w) {
            if (!g->visited[w->dat]) {
                push(w->dat);
                g->visited[w->dat] = TRUE;
                printf("%c", w->dat + 65);
                v = w->dat;
                w = g->adjList_H[v];
            } else {
                w = w->Link;
            }
        }
        v = pop();
    }
}


