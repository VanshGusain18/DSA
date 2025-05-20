// Brute Approch

class Node
{
public:
    int key;
    int val;
    Node *prev;
    Node *next;

    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
public:
    int size = 0, cap = 0;
    Node *dummyhead = new Node(-1, -1);
    Node *dummytail = new Node(-1, -1);

    LRUCache(int capacity)
    {
        cap = capacity;
        dummyhead->next = dummytail;
        dummytail->prev = dummyhead;
    }

    int get(int key)
    {
        Node *temp = dummyhead->next;
        while (temp != dummytail)
        {
            if (temp->key == key)
                break;
            temp = temp->next;
        }

        if (temp == dummytail)
        {
            return -1;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            temp->next = dummytail;
            temp->prev = dummytail->prev;
            dummytail->prev->next = temp;
            dummytail->prev = temp;

            return temp->val;
        }
    }

    void put(int key, int value)
    {
        Node *temp = dummyhead->next;
        while (temp != dummytail)
        {
            if (temp->key == key)
                break;
            temp = temp->next;
        }

        if (temp == dummytail)
        {
            if (size < cap)
            {
                size++;
            }
            else
            {
                Node *nex = dummyhead->next;
                dummyhead->next = nex->next;
                nex->next->prev = dummyhead;
                delete nex;
            }

            Node *newNode = new Node(key, value);
            newNode->next = dummytail;
            newNode->prev = dummytail->prev;
            dummytail->prev->next = newNode;
            dummytail->prev = newNode;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            temp->val = value;

            temp->next = dummytail;
            temp->prev = dummytail->prev;
            dummytail->prev->next = temp;
            dummytail->prev = temp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// Optimal Approch

#include <unordered_map>
using namespace std;

class Node
{
public:
    int key;
    int val;
    Node *prev;
    Node *next;

    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
public:
    int size = 0, cap = 0;
    Node *dummyhead;
    Node *dummytail;
    unordered_map<int, Node *> cache;

    LRUCache(int capacity)
    {
        cap = capacity;
        dummyhead = new Node(-1, -1);
        dummytail = new Node(-1, -1);
        dummyhead->next = dummytail;
        dummytail->prev = dummyhead;
    }

    void removeNode(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertToTail(Node *node)
    {
        node->prev = dummytail->prev;
        node->next = dummytail;
        dummytail->prev->next = node;
        dummytail->prev = node;
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end())
            return -1;

        Node *node = cache[key];
        removeNode(node);
        insertToTail(node);
        return node->val;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            Node *node = cache[key];
            node->val = value;
            removeNode(node);
            insertToTail(node);
        }
        else
        {
            if (size == cap)
            {
                Node *lru = dummyhead->next;
                cache.erase(lru->key);
                removeNode(lru);
                delete lru;
                size--;
            }

            Node *newNode = new Node(key, value);
            cache[key] = newNode;
            insertToTail(newNode);
            size++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */