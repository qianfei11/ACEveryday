#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAX 100
#define ENTRY_ROW 1
#define ENTRY_COL 1
#define EXIT_ROW 8
#define EXIT_COL 8

typedef struct
{
    int row;
    int col;
    int dir;
}element;
typedef struct
{
    short int vert;
    short int horiz;
}offsets;

element stack[MAX];
offsets move[8] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
int top = -1;
char maze[10][10] =
        {
                {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                {'#', '=', '#', '=', '=', '=', '#', '#', '=', '#'},
                {'#', '=', '=', '#', '#', '=', '=', '#', '#', '#'},
                {'#', '#', '=', '=', '=', '#', '#', '=', '=', '#'},
                {'#', '=', '=', '=', '=', '=', '=', '=', '=', '#'},
                {'#', '#', '=', '=', '=', '=', '#', '#', '#', '#'},
                {'#', '#', '#', '=', '=', '=', '=', '=', '=', '#'},
                {'#', '#', '#', '#', '=', '=', '=', '=', '#', '#'},
                {'#', '#', '#', '=', '=', '=', '=', '=', '=', '#'},
                {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
        };
int mark[10][10];

void push(int *top, element a)
{
    ++(*top);
    if(*top <= MAX - 1)
        stack[*top] = a;
    else
    {
        printf("Stack overflow!\n");
        exit(1);
    }
}

element pop(int *top)
{
    if(*top >= 0)
        return stack[(*top)--];
    else
    {
        printf("Stack underflow!\n");
        exit(1);
    }
}

element gettop(int top)
{
    if(top >= 0)
        return stack[top];
    else
    {
        printf("Stack underflow!\n");
        exit(1);
    }
}

void printmaze(char maze[10][10])
{
    for(int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void path()
{
    int row, col, next_row, next_col, dir, found = 0;
    int m[10][10];
    element pos;
    memset(mark, 0, sizeof(mark));
    mark[1][1] = 1;
    top = 0;
    stack[0].row = ENTRY_ROW;
    stack[0].col = ENTRY_COL;
    stack[0].dir = 0;
    printmaze(maze);
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(maze[i][j] == '#')
                m[i][j] = 1;
            else
                m[i][j] = 0;
        }
    }
    while(top > -1 && !found)
    {
        pos = gettop(top);
        row = pos.row;
        col = pos.col;
        dir = pos.dir;
        while(dir < 8 && !found)
        {
            next_row = row + move[dir].vert;
            next_col = col + move[dir].horiz;
            if(next_row == EXIT_ROW && next_col == EXIT_COL)
                found = 1;
            else if(!m[next_row][next_col] && !mark[next_row][next_col])
            {
                mark[next_row][next_col] = 1;
                pos.row = next_row;
                pos.col = next_col;
                pos.dir = ++dir;
                push(&top, pos);
                row = next_row;
                col = next_col;
                dir = 0;
            }
            else
                ++dir;
        }
        if(!found)
            pos = pop(&top);
    }
    if(found == 1)
    {
        printf("The path is:\n");
        for(int i = 0; i <= top; i++)
            printf("%5d:%5d%5d\n", i + 1, stack[i].row, stack[i].col);
        printf("%5d:%5d%5d\n", top + 1, EXIT_ROW, EXIT_COL);
    }
    else
        printf("The maze does not have a path.\n");
}

int main()
{
    path();
    return 0;
}