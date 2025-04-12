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