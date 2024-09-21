#include "LinkedList.h"

template<typename T>
class MyStack {
private:
    SinglyList m_List;
public:
    MyStack() {
        std::shared_ptr<SinglyList<T>> m_List = std::make_shared<SinglyList<T>>;
    }

    void push(T x) {
        m_List->InsertAtHead(Node<T>(x));
    }

    T pop() {
        Node<T> Head = m_List->RemoveHeadElement();
        return Head->val;
    }

    T top() {
        Node<T> Head = m_List->GetHead();
        return Head->val;
    }

    bool empty() {
        return m_List->IsListEmpty();
    }
};
