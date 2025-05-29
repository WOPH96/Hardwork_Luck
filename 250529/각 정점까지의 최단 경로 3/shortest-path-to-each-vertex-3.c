#include <stdio.h>

int graph[101][101];

#define MAX_HEAP_SIZE 1001
#define ND (Node)

typedef struct
{
    int idx,dist;
}Node;

typedef int(*Cmpfp)(Node,Node);

typedef struct
{
    Node data[MAX_HEAP_SIZE];
    int size;
    Cmpfp cmp;
}Heap;

int min_cmp(Node n1, Node n2)
{
    return n1.dist - n2.dist;
}

int max_cmp(Node n1, Node n2)
{
    return n2.dist - n1.dist;
}

void heap_init(Heap *h, Cmpfp cmp) {
    h->size = 0;
    h->cmp = cmp;
}

void swap(Node *a, Node *b)
{
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void push(Heap *h, Node data)
{
    int idx = ++h->size;
    h->data[idx] = data;

    // heap이 한개이상 있고, 부모랑 비교했을 때 내가 더 (크or작)다면 change
    while(idx>1 && h->cmp(h->data[idx], h->data[idx/2])<0) 
    {
        swap(&h->data[idx/2],&h->data[idx]);
    }
}

Node pop(Heap *h)
{
    if(h->size == 0) return (Node){-1,-1};
    Node ret = h->data[1]; // root
    h->data[1] = h->data[h->size--]; //root를 마지막 원소로 대치

    int idx = 1; // root부터 내려가면서 change

    // 부모가 두 자식보다 크or작 만족하면 스탑 
    while(1)
    {
        int left = idx*2, right = idx*2+1, parent = idx;
        if(left <= h->size && h->cmp(h->data[left],h->data[parent])<0) //left가 parent보다 만족한다면 찬탈
            parent = left;
        if(right <= h->size && h->cmp(h->data[right],h->data[parent])<0)
            parent = right;
        if(parent == idx) // 바뀌지 않았을때 끝 
            break;
        
        swap(&h->data[parent],&h->data[idx]); // 부모 자식 체인지
        idx = parent;
    }


    return ret;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int i, x, y, z;
    for(i = 0; i < m; i++) {
        scanf("%d %d %d", &x, &y, &z);
        graph[x][y] = z;
    }
    
    // Please write your code here.

    Heap min_pq;
    heap_init(&min_pq,min_cmp);

    // push(&min_pq, ND{1,2});
    // push(&min_pq, ND{2,3});
    // push(&min_pq, ND{4,1});
    
    // Node now = pop(&min_pq);
    // printf("pop[%d,%d]",now.idx,now.dist);
    int dist[101] ={0};
    // for(int i = 1; i<=n; i++)
    // {
    for(int j =1; j<=n; j++)
    {
        // printf("%d ",graph[i][j]);
        dist[j] = 0x7fff0000;
    }
        // printf("\n");
    // }

    dist[1] = 0; 

    push(&min_pq,ND{1,0}); //pq삽입

    while(min_pq.size != 0)
    {
        //가장 거리가 작은 노드 꺼내기 
        Node now = pop(&min_pq);

        //그 노드에서 인접한 노드들 돌기
        for(int j = 1 ; j<=n; j++)
        {
            // 인접 노드가 있는 경우 가중치가 0이 아님.
            // now노드 -> j노드로 가는 거리(가중치)
            if(graph[now.idx][j])
            {
                
                int now_dist = dist[now.idx] + graph[now.idx][j]; 
                // printf("now_dist : %d %d\n",now_dist);
                if(now_dist < dist[j] )
                {
                    dist[j] = now_dist;
                    push(&min_pq,ND{j,now_dist});
                }
                //인접 노드 거리가 현재 거리 테이블보다 낮으면 갱신하고, pq삽입
            }
        }

    }

    for(int j =2; j<=n; j++)
    {
        printf("%d\n",dist[j]);
    }

    

    
    return 0;
}