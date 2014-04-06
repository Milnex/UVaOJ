#include <cstdio>
#include <cctype>
#include <stack>
using namespace std;

char PRIORITY[256] = {0};
void init (){
    PRIORITY['+'] = 1;
    PRIORITY['-'] = 1;
    PRIORITY['*'] = 2;
    PRIORITY['/'] = 2;
}

int main()
{
    init();
    int n;
    for (scanf("%d", &n), getchar(), getchar(); n; n--) {
        stack<char> ops;
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
            if (isdigit(c))
                putchar(c);
            else if (c == '(')
                ops.push(c);
            else if (c == ')') {
                for (; !ops.empty() && ops.top() != '('; ops.pop())
                    putchar(ops.top());
                ops.pop();
            }
            else {
                for (; !ops.empty() && PRIORITY[c] <= PRIORITY[ops.top()]; ops.pop())
                    putchar(ops.top());
                ops.push(c);
            }
            getchar();
        }
        for (; !ops.empty(); ops.pop())
            putchar(ops.top());
        putchar('\n');
        if (c == '\n')
            putchar(c);
    }
    return 0;
}