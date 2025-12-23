#include <stdio.h>

int n;
int a[100][100];
int vi[100];
int q[100];
int front = -1, rear = -1;

void ins(int o)
{
    q[++rear] = o;
}

int del()
{
    return q[++front];
}

void bfs(int start)
{
    int i, v;

    vi[start] = 1;
    ins(start);

    while (front != rear)
    {
        v = del();
        printf("%d ", v);

        for (i = 0; i < n; i++)
        {
            if (a[v][i] == 1 && vi[i] == 0)
            {
                vi[i] = 1;
                ins(i);
            }
        }
    }
}

int main()
{
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int i, j;

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        vi[i] = 0;
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    int start;
    printf("Enter start node: ");
    scanf("%d", &start);

    bfs(start);

    return 0;
}
