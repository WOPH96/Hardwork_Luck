#include <stdio.h>

#define GRID_SIZE 20
#define STACK_SIZE 20

// int grid[20][20];
int moves[101];
int n, m;

typedef struct
{
    int size;
    int stack[STACK_SIZE];
    // int max_val; // max_heap 썼으면 쉬웠을텐데 
}Stack;

typedef struct
{
    int y,x;
}Pos;

Stack grid[20][20];
Pos pos_nums[401];

void init_stack()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0;j<n;j++)
        {
            grid[i][j].size = 0;
            // grid[i][j].max_val = -1;
        }
    }
}

void push(Stack *s,int val){
    
    s->stack[s->size++] = val;
    // printf("size = %d\n",grid[now.y][now.x].size);
}

int pop(Stack *s)
{
    if(s->size == 0) 
        return -1;
    return s->stack[--s->size];
}

int max_in_stack(Stack *s)
{
    if(s->size > 0)
    {
        int max_val = -1;
        for(int i =0; i < s->size; i++)
        {
            if(max_val < s->stack[i])
                max_val = s->stack[i];
        }
        return max_val;
    }
    else
        return -1;
}

void show()
{
    for(int i =0; i<n;i++)
    {
        for(int j =0; j<n; j++)
        {
            int size = grid[i][j].size;
            if(size == 0)
                printf("None");
            else
            {
                for(int s = size-1; s>=0; s--)
                {
                    printf("%d ",grid[i][j].stack[s]);
                }
            }
            printf("\n");
        }
    }
    printf("\n");
}
#define is_valid(y,x) (0<=y && y<n && 0<=x && x<n)
void do_move(int num)
{
    int dy[] = {0,0,1,-1,1,1,-1,-1};
    int dx[] = {1,-1,0,0,1,-1,1,-1};

    Pos now = pos_nums[num];
    int max_val = -1;
    Pos max_pos;

    for(int i =0; i<8; i++)
    {
        int ny = now.y+dy[i], nx = now.x+dx[i];
        if(is_valid(ny,nx) && max_in_stack(&grid[ny][nx]) > max_val)
        {
            max_val = max_in_stack(&grid[ny][nx]);
            max_pos = (Pos){ny,nx};
        }
    }

    if(max_val != -1)
    {
        // printf("num %d pos_nums[%d,%d] max_pos [%d,%d]\n",
        //         num,pos_nums[num].y,pos_nums[num].x,
        //         max_pos.y,max_pos.x);
        
        //빼기
        Stack temp;
        temp.size = 0;
        int temp_val;
        while(grid[now.y][now.x].size >0 && 
                (temp_val = pop(&grid[now.y][now.x])) != num) // num이 나올때까지 뽑음
        {
            push(&temp,temp_val); 
        }
        push(&temp,temp_val);
        // printf("temp_val %d\n",temp_val);

        //옮겨담기
        while(temp.size >0 )
             // num이 나올때까지 뽑음
        {
            int stacked_num = pop(&temp);
            pos_nums[stacked_num] = max_pos;
            push(&grid[max_pos.y][max_pos.x],stacked_num);
        }
    }

}

int main(void) {
    init_stack();
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int val;
            scanf("%d", &val);
            push(&grid[i][j],val);
            // push(&grid[i][j],100);
            // push(&grid[i][j],123);
            pos_nums[val] = (Pos){i,j};
        }
    }
    
    for (int i = 0; i < m; i++)
        scanf("%d", &moves[i]);
    
    // Please write your code here.
    for (int i = 0; i < m; i++)
    {
        do_move(moves[i]);
        // break;
        
    }
    show();
    
    return 0;
}