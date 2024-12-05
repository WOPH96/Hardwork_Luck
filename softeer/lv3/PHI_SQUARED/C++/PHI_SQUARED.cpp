#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *prev;
    Node *next;
};

template <typename T>
using pNode = Node<T> *;

template <typename T>
struct List
{
    pNode<T> head;
    pNode<T> tail;

    List()
    {
        head = new Node<T>{};
        tail = new Node<T>{};
        head->next = tail;
        tail->prev = head;
    }
    ~List()
    {
        delete head;
        delete tail;
    }
    pNode<T> begin()
    {
        return this->head->next;
    }
    pNode<T> end()
    {
        return this->tail;
    }
    pNode<T> last()
    {
        return end()->prev;
    }
    bool empty()
    {
        return (begin() == end());
    }
    void insert(pNode<T> x, T val)
    {
        pNode<T> node = new Node<T>{val, x->prev, x};
        x->prev->next = node;
        x->prev = node;
    }
    void push_back(T val)
    {
        insert(end(), val);
    }
    pNode<T> erase()
    {
    }
};

template <typename T>
using pList = List<T> *;

struct Data
{
    int idx;
    int size;
};

int main(int argc, char **argv)
{
    List<Data> bacteria;

    bacteria.push_back({1, 2});

    cout << bacteria.begin()->data.size << endl;
    cout << bacteria.empty() << endl;

    return 0;
}