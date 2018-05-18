/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>


int Answer;

int mat[501][501];
int N, M;           //N 대학수 M 도로수
int a,b,w;

#define MAX 500
int * no;



typedef struct node {
    struct node* next;
    int value;
    int weight;
} node;

struct priority_queue {
    int x, cost;
} pq[MAX*2], tmp;

int pq_t;
void add(node** head, int value, int weight);
void pq_pop();
void pq_push(int x, int cost);

int N, M, u, v, d, S;
node *head[MAX];
int* Dijkstra(int start) {
    int *dist = (int*)malloc(sizeof(int)*(N+1));
    for (int i = 1; i <= N; i++) {
        dist[i] = -1;
    }
    // first : dist , second : vertex_pos
    dist[start] = 0;
    pq_push(start, dist[start]);
    while (pq[1].x!=0) {
        int here = pq[1].x;
        int heredist = pq[1].cost;
        pq_pop();
        if (heredist > dist[here]) continue;
        node *current_node = head[here];
        for (; current_node; current_node=current_node->next) {
            int there = current_node->value;
            int nextdist = heredist + current_node->weight;
            if (dist[there] == -1 || dist[there] > nextdist) { //최단 거리 갱신
                dist[there] = nextdist;
                pq_push(there, nextdist);
            }
        }
    }
    return dist;
}


int main(void) {
    int T, test_case;

/*
 * 첫 줄에 정점의 개수 N과 간선의 개수 M, 그리고 시작 정점 S가 주어집니다.
다음 M줄에 간선의 관계 시작정점 u와 도착정점 v 그리고 간선 가중치 w가 주어집니다.
 *
 */
    setbuf(stdout, NULL);

    scanf("%d", &T);
    for(test_case = 0; test_case < T; test_case++) {

//        for(int i=0; i<501; i++){
//            memset(mat[i], -1, sizeof(int)* 501);
//        }

//        no = (int*)malloc(sizeof(int)*N);


//        scanf("%d %d", &N, &M);
        scanf("%d %d", &N, &M);
        for(int i=0;i<M;i++){
//            scanf("%d %d %d", &a,&b,&w);
//            mat[a-1][b-1]=w;
//            mat[b-1][a-1]=w;

            scanf("%d %d %d", &u, &v, &d);
            add(&head[u], v, d);
        }

        int *dist = Dijkstra(1);
        for (int i = 1; i <= N; i++) {
            printf("%d\n", dist[i]);
        }

        printf("Case #%d\n", test_case+1);
        printf("%d\n", Answer);
        free(no);

    }

    return 0;//Your program should return 0 on normal termination.
}





void add(node** head, int value, int weight) {
    node* new_node = (node *)malloc(sizeof(node));
    new_node->value = value;
    new_node->weight = weight;
    if (!(*head)) {
        new_node->next = NULL;
        (*head) = new_node;
    } else {
        new_node->next = (*head);
        (*head) = new_node;
    }
    return;
}

void pq_pop() {
    pq[1] = pq[pq_t--];
    for (int s = 1;;) {
        int e = s * 2;
        if (e > pq_t) return;
        if (e + 1 <= pq_t && pq[e].cost > pq[e + 1].cost) e++;
        if (pq[s].cost > pq[e].cost) {
            tmp = pq[s];
            pq[s] = pq[e];
            pq[e] = tmp;
            s = e;
        } else break;
    }
}

void pq_push(int x, int cost) {
    pq[++pq_t].cost = cost;
    pq[pq_t].x = x;
    for (int i = pq_t; i > 1; i /= 2) {
        if (cost < pq[i / 2].cost) pq[i] = pq[i / 2];
        else {
            pq[i].x = x;
            pq[i].cost = cost;
            return;
        }
    }
    pq[1].x = x;
    pq[1].cost = cost;
}