#include <iostream>
using namespace std;
#define MaxSize 100
/* 栈的基本操作 */
typedef struct stack {
    int data[MaxSize];
    int top;
} Stack;

/* 初始化 InitStack(&S) */
void init(Stack* S) {
    S->top = -1;
}
/* 判空 Empty(S) */
void ifEmpty(Stack S) {
    if (S.top == -1) {
        cout << "栈为空" << endl;
    } else {
        cout << "栈非空" << endl;
    }
}
/* 进栈 Push(&S, x) */
void Push(Stack& S, int x) {
    if (S.top == MaxSize - 1) {
        cout << "栈满" << endl;
        return;
    }
    S.data[++S.top] = x;
}
/* 出栈 Pop(&S, &x) */
void Pop(Stack& S, int& x) {
    if (S.top == -1) {
        cout << "栈为空" << endl;
    }
    x = S.data[S.top--];
}
/* 读栈顶元素 GetTop(S) */
void GetTop(Stack S) {
    if (S.top == -1) {
        cout << "栈为空" << endl;
        return;
    }
    cout << "栈顶元素为:" << S.data[S.top]<<endl;
}
/* 遍历栈 PrintStack(&S) */
void PrintStack(Stack& S) {
    if (S.top == -1) {
        cout << "栈为空" << endl;
    }
    int i = S.top;
    while (i > -1) {
        cout << S.data[i] << " ";
        i--;
    }
    cout<<endl;
}
/* 销毁栈 DestroyStack(&S) */
void DestroyStack(Stack& S) {
    S.top = -1;
}
int main() {
    Stack s;
    init(&s);
    ifEmpty(s);
    for (int i = 0; i < 5; i++) {
        Push(s, i);
    }
    ifEmpty(s);
    GetTop(s);
    PrintStack(s);
    int x;
    Pop(s,x);
    cout<<x<<endl;
    DestroyStack(s);
    ifEmpty(s);

}