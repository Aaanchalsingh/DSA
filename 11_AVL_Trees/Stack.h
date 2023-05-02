class Stack
{
public:
    int size;
    int top;
    node **s;
    Stack()
    {
        size = 12;
        top = -1;
        s = new node *[size];
    }
    void push(node *x)
    {
        if (top >= size)
        {
            cout << "STACK OVERFLOW\n";
        }
        else
        {
            top++;
            s[top] = x;
        }
    }
    node *pop()
    {
        if (top == -1)
        {
            cout << "STACK UNDERFLOW\n";
        }
        else
        {
            node *n = s[top];
            top--;
            return n;
        }
    }
    node *stacktop()
    {
        Stack *p;
        if ((p->top > (p->size - 1)) || (p->top == -1))
        {
            return NULL;
        }
        else
            return p->s[p->top];
    }
    int isempty_Stack()
    {
        if (top == -1)
            return 1;
        else
            return 0;
    }
} s;
