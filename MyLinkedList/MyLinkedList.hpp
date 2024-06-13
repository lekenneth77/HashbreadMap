#ifndef MY_LINKED_LIST
#define MY_LINKED_LIST

#include <initializer_list>
#include <iterator>
#include <algorithm>
#include <stdexcept>

/*
singly-linked list class
*/
template <typename T>
class MyLinkedList {
private:
    /*
    need to make this protected 
    linked list node
    args:
    next represents a pointer to the next node
    val is the value of the node
    */ 
    struct LinkListNode {
        LinkListNode* next = nullptr;
        T val;

        LinkListNode() = default;
        LinkListNode(LinkListNode* next) : next(next) {}
        LinkListNode(const T& val) : val(val) {}
        LinkListNode(LinkListNode* next, const T& val) : next(next), val(val) {}
        ~LinkListNode() = default;
    };

    //equal operator
    friend bool operator==(const MyLinkedList& lhs, const MyLinkedList& rhs) {
        return std::equal(lhs.begin(), lhs.end(), rhs.begin());
    }

    //not equal operator
    friend bool operator!=(const MyLinkedList& lhs, const MyLinkedList& rhs) {
        return !(lhs == rhs);
    }
    
public:
    //default constructor
    MyLinkedList() {
        head = new LinkListNode();
    }

    //initializer list constructor
    MyLinkedList(std::initializer_list<T> init_list) : MyLinkedList() {
        for (const T& v : init_list) {
            add(v);
        }
    }

    //add function
    //appends a new node to the front of the list
    void add(const T& val) {
        LinkListNode* newNode = new LinkListNode(val);
        newNode->next = head->next;
        head->next = newNode;
    }

    //check if list is empty function
    //returns true if the list is empty or not
    inline bool empty() const {
        return !head->next;
    }

    //front function
    //returns a const reference of the front of the list
    const T& front() const {
        if (empty()) {throw std::out_of_range("Unable to access front"); }
        return head->next->val;
    }

    //pop function
    //removes a node from the front of the list
    void pop() {
        if (empty()) {throw std::out_of_range("List is empty, cannot pop");} //check if list is empty
        LinkListNode* newNext = head->next->next;
        delete head->next;
        head->next = newNext;
    }

    //destructor
    virtual ~MyLinkedList() {
        while (head->next) {
            pop();
        }
        delete head;
    }

    //iterator for this class, i have no plans on making a non const iterator
    class const_iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = const T*;
        using reference = const T&;

        //by standard (and it really makes sense why it's like this), iterators compare by position because well
        //if you wanna check if you have two iterators at the same spot, then yeah
        //checking by value, that's when you wanna use std::equal, which dereferences the iterator...! lol i should've known
        friend bool operator==(const const_iterator& lhs, const const_iterator& rhs) {
            return lhs.curNode == rhs.curNode;
        }

        friend bool operator!=(const const_iterator& lhs, const const_iterator& rhs) {
            return !(lhs == rhs);
        }

        //constructor
        const_iterator(LinkListNode* node) : curNode(node) {} 

        //asterisk operator
        //returns a const reference of the value the iterator is currently at
        //TODO should probably null check...!
        const T& operator* () const {
            return curNode->val;
        }

        //arrow operator
        const T* operator->() const {
            return &(curNode->val);
        }

        const_iterator& operator++() {
            curNode = curNode->next;
            return *this;
        } 

        const_iterator operator++(int) {
            const_iterator temp = *this;
            ++*this;
            return temp;
        }

    private:
        LinkListNode* curNode;
    };

    const_iterator begin() const {
        return const_iterator(head->next);
    }

    const_iterator end() const {
        return const_iterator(nullptr);
    }

private:
    LinkListNode* head;

};


#endif