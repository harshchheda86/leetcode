#pragma once
#include <cstdint>
#include <iostream>

template<typename T>
class SinglyList;

template<typename T>
class Node
{
    friend class SinglyList<T>;
private:
    T data;
    Node* next;

public:
    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

template <typename T>
class SinglyList
{
private:
    Node<T>* Head;
    Node<T>* Tail;

    bool IsListEmpty() const
    {
        return Head == nullptr && Tail == nullptr;
    }

    void PrintNode(Node<T>* node) const
    {
        std::cout << node->data;
    }

public:
    SinglyList()
    {
        Head = Tail = nullptr;
    }

    void InsertAtTail(Node<T>* node)
    {
        if (!node) return;

        if (IsListEmpty())
        {
            Head = node;
            Tail = node;
            node->next = nullptr;

            return;
        }

        Tail->next = node;
        Tail = node;
        Tail->next = nullptr;
    }

    void InsertAtHead(Node<T>* node)
    {
        if (!node) return;

        if (IsListEmpty())
        {
            Head = node;
            Tail = node;
            node->next = nullptr;

            return;
        }

        node->next = Head;
        Head = node;
    }

    Node<T> RemoveHeadElement()
    {
        Node<T> Head = Head->next;

        return Head;
    }

    Node<T> GetHead()
    {
        return Head;
    }

    bool IsListEmpty()
    {
        return Head == nullptr;
    }

    void RemoveElement(Node<T>* node)
    {
        if (!node) return;

        if (node == Head)
        {
            Head = node->next;
            return;
        }

        Node<T>* next = this->Head->next;
        Node<T>* prev = Head;

        while (next)
        {
            if (next == node)
            {
                prev->next = node->next;
            }
            prev = next;
            next = next->next;
        }
    }

    void PrintList()
    {
        Node<T>* head = this->Head;

        while (head != nullptr)
        {
            std::cout << head->data << "->";
            head = head->next;
        }
        std::cout << "null" << std::endl;
    }
};