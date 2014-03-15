#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

class MedianHeap {
public:
    MedianHeap() {}
    void push(int n) {
        if (size() == 0) {
            max.push(n);
            return;
        }
        if (n <= median()) 
            max.push(n);
        else
            min.push(n);

        if (max.size() < min.size()-1) {
            max.push(min.top());
            min.pop();
        }
        else if (min.size() < max.size()-1) {
            min.push(max.top());
            max.pop();
        }
    }
    int size() {
        return min.size() + max.size();
    }
    double median() {
        if (min.size() > max.size()) 
            return min.top();
        else if (min.size() < max.size())
            return max.top();
        else
            return 0.5*(min.top() + max.top());
    }

private:
    priority_queue<int, vector<int>, greater<int> > min;
    priority_queue<int> max;
};

int main()
{
    int X = 0;
    MedianHeap heap;
    while (scanf("%d", &X) == 1) {
        heap.push(X);
        printf("%d\n", (int)heap.median());
    }

    return 0;
}
