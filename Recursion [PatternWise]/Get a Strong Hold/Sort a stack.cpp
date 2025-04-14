// Iterative approach

void SortedStack ::sort()
{
    // Your code here
    stack<int> temp;

    while (!s.empty())
    {
        int curr = s.top();
        s.pop();

        while (!temp.empty() && temp.top() < curr)
        {
            s.push(temp.top());
            temp.pop();
        }

        temp.push(curr);
    }

    while (!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
}

// Recursive Approch

void insertInSortedStack(stack<int> &s, int element)
{
    if (s.empty() || s.top() <= element)
    {
        s.push(element);
        return;
    }
    int temp = s.top();
    s.pop();
    insertInSortedStack(s, element);
    s.push(temp);
}

void SortedStack::sort()
{
    if (s.empty())
        return;
    int tp = s.top();
    s.pop();
    sort();
    insertInSortedStack(s, tp);
}