#include "STACK.h"
#include <stdio.h>

ceng CENG[SIZE];
//数据入栈
void push_stack(stack *p, int number)
{
    p->arr[p->head] = number;
    p->head++;
}

//初始化栈1
void init_stack1(stack *p)
{
    p->head = 0;
    push_stack(p, 1);
    push_stack(p, 2);
    push_stack(p, 3);
    push_stack(p, 4);
    push_stack(p, 5);
    push_stack(p, 6);
    push_stack(p, 7);
    push_stack(p, 8);
}
//初始化栈2 3
void init_stack2_3(stack *p1, stack *p2)
{
    p1->head = 0;
    p1->arr[p1->head] = 0;
    p2->head = 0;
    p2->arr[p2->head] = 0;
}
//弹出栈顶元素
int pop_stack(stack *p)
{
    p->head--;
    return p->arr[p->head];
}
//访问栈顶元素
int top_stack(stack *p)
{
    return p->arr[p->head - 1];
}
//比较两个栈顶元素的大小
int sizecmp_stack(stack *p1, stack *p2)
{
    if (p1->arr[p1->head - 1] > p2->arr[p2->head - 1])
        return 1;
    else if (p1->arr[p1->head - 1] < p2->arr[p2->head - 1])
        return -1;
    else
        return 0;
}

//测出栈的高度
int high_stack(stack *p)
{
    return p->head;
}

//是否为空栈
int empty_stack(stack *p)
{
    return p->head == 0;
}

//是否栈满
int full_stack(stack *p)
{
    return p->head == SIZE;
}

//初始化层1
void init_ceng1(ceng *p)
{
    p->number = 1;
    p->row = SIZE - 1;
    p->col = 0;
}

//初始化层2
void init_ceng2(ceng *p)
{
    p->number = 2;
    p->row = SIZE - 2;
    p->col = 0;
}

//初始化层3
void init_ceng3(ceng *p)
{
    p->number = 3;
    p->row = SIZE - 3;
    p->col = 0;
}

//初始化层4
void init_ceng4(ceng *p)
{
    p->number = 4;
    p->row = SIZE - 4;
    p->col = 0;
}
//初始化层5
void init_ceng5(ceng *p)
{
    p->number = 5;
    p->row = SIZE - 5;
    p->col = 0;
}
//初始化层6
void init_ceng6(ceng *p)
{
    p->number = 6;
    p->row = SIZE - 6;
    p->col = 0;
}
//初始化层7
void init_ceng7(ceng *p)
{
    p->number = 7;
    p->row = SIZE - 7;
    p->col = 0;
}
//初始化层8
void init_ceng8(ceng *p)
{
    p->number = 8;
    p->row = SIZE - 8;
    p->col = 0;
}
//移动层
void move_ceng(int level, int *nrow, int *ncol, stack *p1, stack *p2, stack *p3, int stdec)
{
    stack *arr[3];
    arr[0] = p1;
    arr[1] = p2;
    arr[2] = p3;
    *nrow = level - 1 - high_stack(arr[stdec]);
    *ncol = stdec;
}

//显示图片
void show_map(void)
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (CENG[0].row == i && CENG[0].col == j)
            {
                printf("  |    1    |  ");
            }
            else if (CENG[1].row == i && CENG[1].col == j)
            {
                printf("  |   2   |  ");
            }
            else if (CENG[2].row == i && CENG[2].col == j)
            {
                printf("   |   3   |   ");
            }
            else if (CENG[3].row == i && CENG[3].col == j)
            {
                printf("   |  4  |   ");
            }
            else if (CENG[4].row == i && CENG[4].col == j)
            {
                printf("    |  5  |    ");
            }
            else if (CENG[5].row == i && CENG[5].col == j)
            {
                printf("    | 6 |    ");
            }
            else if (CENG[6].row == i && CENG[6].col == j)
            {
                printf("     | 7 |     ");
            }
            else if (CENG[7].row == i && CENG[7].col == j)
            {
                printf("     |8|     ");
            }
            else
                printf("            ");
        }
        printf("\n");
    }
    printf("=====================================================================\n");
}

int main()
{
    int res = 1, dec = 1;
    char con;
    int newrow;
    int newcol;
    int step = 0;
    int level = 0;
    while (1)
    {
        if (level == 0)
        {
            do
            {
                printf("请输入游戏等级:\n");
                scanf("%d", &level);
                if (level <= 0 || level > 8)
                    printf("等级范围错误，重新输入\n");
            } while (level <= 0 || level > 8);
        }
        level = 8;
        newrow = 0, newcol = 0;
        stack STACK[3];
        //初始化3个栈
        init_stack1(&STACK[0]);
        init_stack2_3(&STACK[1], &STACK[2]);
        //初始化8个层
        init_ceng1(&CENG[0]);
        init_ceng2(&CENG[1]);
        init_ceng3(&CENG[2]);
        init_ceng4(&CENG[3]);
        init_ceng5(&CENG[4]);
        init_ceng6(&CENG[5]);
        init_ceng7(&CENG[6]);
        init_ceng8(&CENG[7]);
        while (1)
        {
            //打印画面
            switch (level)
            {
            case 1:
                show_map();
                break;
            case 2:
                show_map();
                break;
            case 3:
                show_map();
                break;
            case 4:
                show_map();
                break;
            case 5:
                show_map();
                break;
            case 6:
                show_map();
                break;
            case 7:
                show_map();
                break;
            case 8:
                show_map();
                break;
            }
            while (1)
            {
                // printf("游戏等级为:%d\n",level);
                // printf("源栈最高层是%d ......\n",top_stack(&STACK[res]));
                printf("   一号的高度%d ", STACK[0].head);
                printf("      二号的高度%d ", STACK[1].head);
                printf("     三号的高度%d\n", STACK[2].head);
                printf("\n已经走的步数为 %d \n", step);
                //选择源 目标
                scanf("%d", &res);
                scanf("%d", &dec);
                res--;
                dec--;
                if (!(res >= 0 && res < 3 && dec >= 0 && dec < 3)) /*||(empty_stack(&STACK[res]))*/
                {
                    printf("\n\n输入范围超出\n");
                }
                else if (empty_stack(&STACK[res]) == 1)
                {
                    printf("%d\n", STACK[0].head);
                    printf("\n\n源栈空\n");
                }
                else if (sizecmp_stack(&STACK[res], &STACK[dec]) < 0)
                {
                    printf("\n\n大块的不能放在小块的上面\n");
                }
                else
                {
                    if (dec != res)
                    {
                        printf("\n\n\n正在移动层块....\n");
                        step++;
                        move_ceng(level, &newrow, &newcol, &STACK[0], &STACK[1], &STACK[2], dec);
                        CENG[top_stack(&STACK[res]) - 1].row = newrow;
                        CENG[top_stack(&STACK[res]) - 1].col = newcol;
                        push_stack(&STACK[dec], pop_stack(&STACK[res]));
                        break;
                    }
                    else
                    {
                        printf("\n\n\n放轻松\n");
                    }
                    break;
                }
                show_map();
            }

            if (full_stack(STACK + 1) == 1 || full_stack(STACK + 2) == 1)
            {
                printf("完成了汉诺塔!\n");
                level++;
                break;
            }
        }
        show_map();
        printf("是否继续游戏?继续请输入y,否则按其它键\n");
        scanf("%*[^\n]");
        scanf("%*c");
        scanf("%c", &con);
        if (con != 'y')
            break;
    }
    return 0;
}