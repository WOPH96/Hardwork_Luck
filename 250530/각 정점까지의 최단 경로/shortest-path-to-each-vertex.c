#include <stdio.h>
#include <stdlib.h>
#define INF 0x7fff0000
#define MAX_N 20001

int n, m, k;

typedef struct _Node
{
    int idx;
    int weight;
    struct _Node* next;
}Node;

Node *head[MAX_N];
int dist[MAX_N];


void make_graph(int from, int to, int weight)
{
    Node *src = (Node*)malloc(sizeof(Node));
    src->idx = to;
    src->weight = weight;
    src->next = head[from];
    head[from] = src;

    Node *dst = (Node*)malloc(sizeof(Node));
    dst->idx = from;
    dst->weight = weight;
    dst->next = head[to];
    head[to] = dst;
}

void print_graph()
{
    for(int i = 1; i<=n; i++)
    {
        Node *cur = head[i];
        printf("%d Node : ",i);
        while(cur)
        {
            printf("[%d %d] ",cur->idx,cur->weight);
            cur = cur->next;
        }
        printf("\n");
    }
}
void print_dist()
{
    // printf("dist : ");
    for(int i =1; i<=n; i++)
    {
        if(dist[i] == INF) printf("-1\n");
        else    printf("%d\n",dist[i]);
    }
    // printf("\n");
}

void free_graph()
{
    for(int i = 1; i<=n; i++)
    {
        Node *cur = head[i];
        // printf("%d Node : ",i);
        while(cur)
        {
            // printf("[%d %d] ",cur->idx,cur->weight);
            Node *temp = cur;
            cur = cur->next;
            free(temp);
        }
        // printf("\n");
    }
}

typedef int(*cmpfp)(Node,Node);

typedef struct 
{
    Node data[MAX_N];
    int size;
    cmpfp cmp;
}Heap;

int cmp_min(Node n1, Node n2)
{
    return n1.weight - n2.weight;
}
void init_heap(Heap *h, cmpfp func)
{
    h->size = 0;
    h->cmp = func;
}

#define ND (Node) 

void swap(Node *n1, Node *n2)
{
    Node temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void push(Heap *h, Node val)
{
    //가장 마지막에 넣고 올리기
    int idx = ++h->size;
    h->data[idx] = val;

    //1보다 크고, 부모-자식 관계 만족하면 스왑진행
    while(idx>1 && h->cmp(h->data[idx],h->data[idx/2])<0)
    {
        swap(&h->data[idx],&h->data[idx/2]);
    }
}

Node pop(Heap *h)
{
    //빈 힙인지 확인
    if(h->size ==0 ) return ND{-1,-1};
    //ret 저장해놓고
    Node ret = h->data[1];
    //맨위값 최하위값으로
    h->data[1] = h->data[h->size--];

    //부모-자식 관계 만족할때까지 루트에서부터 내리기
    int idx = 1; 

    while(1)
    {
        int left_child = idx*2, right_child = idx*2 +1, parent = idx;
        
        if(left_child <= h->size && h->cmp(h->data[left_child],h->data[parent])<0 )
            parent = left_child;
        if(right_child <= h->size && h->cmp(h->data[right_child],h->data[parent])<0 ) 
            parent = right_child;
        if(parent==idx) break; // 부모 관계 역전x

        swap(&h->data[parent],&h->data[idx]); // 자식 자리로 간 부모번지랑 부모 번지 저장한 idx와 스왑
        idx = parent;


    }

    return ret;
}

int main() {
    scanf("%d %d", &n, &m);
    scanf("%d", &k);
    for (int i = 0; i < m; i++) {
        int from,to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        make_graph(from,to,weight);
        
    }
    // Please write your code here.

    // print_graph();



    for(int i = 1; i<=n; i++)
        dist[i] = INF;

    dist[k] = 0;
    // print_dist();   

    Heap min_pq;
    init_heap(&min_pq,cmp_min);

    push(&min_pq,ND{k,0});

    while(min_pq.size != 0)
    {
        Node now = pop(&min_pq);
        if(now.weight < dist[now.idx]) continue; // 이미 최적이면 패스

        Node *cur = head[now.idx]; // 연결지점 탐색
        while(cur) // 더이상 연결지점이 없을때까지 
        {
            int now_dist = dist[now.idx] + cur->weight; // 현재지점까지의 거리 + 연결지점 가중치
            if(now_dist < dist[cur->idx]) //가 기존 연결지점 가중치보다 작다면
            {
                dist[cur->idx] = now_dist;
                push(&min_pq,ND{cur->idx,now_dist});
            }
            cur = cur->next;
        }



    }
    print_dist();  
    // push(&min_pq,ND{6,4});
    // push(&min_pq,ND{3,2});

    // Node now = pop(&min_pq);
    // printf("[%d,%d]\n",now.idx,now.weight);

    // now = pop(&min_pq);
    // printf("[%d,%d]\n",now.idx,now.weight);

    //  now = pop(&min_pq);
    // printf("[%d,%d]\n",now.idx,now.weight);

    //  now = pop(&min_pq);
    // printf("[%d,%d]\n",now.idx,now.weight);



    free_graph();

    return 0;
}