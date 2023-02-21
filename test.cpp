//////////#include <iostream>
//////////#include <unordered_set>
//////////
//////////struct Node {
//////////    int data;
//////////    Node* prev;
//////////    Node* next;
//////////
//////////    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
//////////};
//////////
//////////class DoublyLinkedList {
//////////public:
//////////    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
//////////
//////////    void insert(int value) {
//////////        Node* node = new Node(value);
//////////        if (head == nullptr) {
//////////            head = node;
//////////            tail = node;
//////////        } else {
//////////            tail->next = node;
//////////            node->prev = tail;
//////////            tail = node;
//////////        }
//////////    }
//////////
//////////    DoublyLinkedList Union(DoublyLinkedList& other) {
//////////        std::unordered_set<int> seen;
//////////        DoublyLinkedList result;
//////////
//////////        Node* node = head;
//////////        while (node != nullptr) {
//////////            if (seen.find(node->data) == seen.end()) {
//////////                result.insert(node->data);
//////////                seen.insert(node->data);
//////////            }
//////////            node = node->next;
//////////        }
//////////
//////////        node = other.head;
//////////        while (node != nullptr) {
//////////            if (seen.find(node->data) == seen.end()) {
//////////                result.insert(node->data);
//////////                seen.insert(node->data);
//////////            }
//////////            node = node->next;
//////////        }
//////////
//////////        return result;
//////////    }
//////////
//////////    void print() {
//////////        Node* node = head;
//////////        while (node != nullptr) {
//////////            std::cout << node->data << " ";
//////////            node = node->next;
//////////        }
//////////        std::cout << std::endl;
//////////    }
//////////
//////////private:
//////////    Node* head;
//////////    Node* tail;
//////////};
//////////
//////////int main() {
//////////    DoublyLinkedList list1;
//////////    list1.insert(1);
//////////    list1.insert(2);
//////////    list1.insert(3);
//////////    std::cout << "List 1: ";
//////////    list1.print();
//////////
//////////    DoublyLinkedList list2;
//////////    list2.insert(3);
//////////    list2.insert(4);
//////////    list2.insert(5);
//////////    std::cout << "List 2: ";
//////////    list2.print();
//////////
//////////    DoublyLinkedList unionList = list1.Union(list2);
//////////    std::cout << "Union: ";
//////////    unionList.print();
//////////
//////////    return 0;
//////////}
////////
////////
//////////using sorting tech check cycle
////////#include <iostream>
////////
////////struct Node {
////////    int data;
////////    Node* next;
////////
////////    Node(int value) : data(value), next(nullptr) {}
////////};
////////
////////bool has_cycle(Node* head) {
////////    if (head == nullptr) {
////////        return false;
////////    }
////////    Node* slow = head;
////////    Node* fast = head->next;
////////    while (fast != nullptr && fast->next != nullptr) {
////////        if (slow == fast) {
////////            return true;
////////        }
////////        slow = slow->next;
////////        fast = fast->next->next;
////////    }
////////    return false;
////////}
////////
////////int main() {
////////    Node* head = new Node(1);
////////    Node* second = new Node(2);
////////    Node* third = new Node(3);
////////    Node* fourth = new Node(4);
////////    Node* fifth = new Node(5);
////////
////////    head->next = second;
////////    second->next = third;
////////    third->next = fourth;
////////    fourth->next = fifth;
////////
////////    std::cout << "Has cycle? " << (has_cycle(head) ? "yes" : "no") << std::endl;
////////
////////    fifth->next = third;
////////
////////    std::cout << "Has cycle? " << (has_cycle(head) ? "yes" : "no") << std::endl;
////////
////////    return 0;
////////}
////////
//////
////////is balanced
//////#include <iostream>
//////#include <stack>
//////#include <string>
//////
//////bool is_balanced(const std::string& str) {
//////    std::stack<char> stack;
//////
//////    for (char c : str) {
//////        switch (c) {
//////            case '(':
//////            case '{':
//////            case '[':
//////                stack.push(c);
//////                break;
//////            case ')':
//////                if (stack.empty() || stack.top() != '(')
//////                    return false;
//////                stack.pop();
//////                break;
//////            case '}':
//////                if (stack.empty() || stack.top() != '{')
//////                    return false;
//////                stack.pop();
//////                break;
//////            case ']':
//////                if (stack.empty() || stack.top() != '[')
//////                    return false;
//////                stack.pop();
//////                break;
//////            default:
//////                // ignore other characters
//////                break;
//////        }
//////    }
//////
//////    return stack.empty();
//////}
//////
//////int main() {
//////    std::string str1 = "{(2 + 3) * [4 - 2]}";
//////    std::string str2 = "{(2 + 3) * [4 - 2])}";
//////    std::string str3 = "2 + 3 * 4";
//////
//////    std::cout << str1 << " is " << (is_balanced(str1) ? "balanced" : "not balanced") << std::endl;
//////    std::cout << str2 << " is " << (is_balanced(str2) ? "balanced" : "not balanced") << std::endl;
//////    std::cout << str3 << " is " << (is_balanced(str3) ? "balanced" : "not balanced") << std::endl;
//////
//////    return 0;
//////}
//////
////
////// double ll concatenate
////#include <iostream>
////
////class Node {
////public:
////    int data;
////    Node* next;
////    Node* prev;
////
////    Node(int data) {
////        this->data = data;
////        this->next = nullptr;
////        this->prev = nullptr;
////    }
////};
////
////class DoublyLinkedList {
////public:
////    Node* head;
////    Node* tail;
////    int size;
////
////    DoublyLinkedList() {
////        head = nullptr;
////        tail = nullptr;
////        size = 0;
////    }
////
////    void insertAtTail(int data) {
////        Node* newNode = new Node(data);
////        if (head == nullptr) {
////            head = newNode;
////        }
////        else {
////            tail->next = newNode;
////            newNode->prev = tail;
////        }
////        tail = newNode;
////        size++;
////    }
////
////    void concatenate(DoublyLinkedList list) {
////        if (list.head != nullptr) {
////            if (head == nullptr) {
////                head = list.head;
////            }
////            else {
////                tail->next = list.head;
////                list.head->prev = tail;
////            }
////            tail = list.tail;
////            size += list.size;
////        }
////    }
////
////    void print() {
////        Node* current = head;
////        while (current != nullptr) {
////            std::cout << current->data << " ";
////            current = current->next;
////        }
////        std::cout << std::endl;
////    }
////};
////
////int main() {
////    DoublyLinkedList list1, list2;
////
////    list1.insertAtTail(1);
////    list1.insertAtTail(2);
////    list1.insertAtTail(3);
////    list1.print();  // Output: 1 2 3
////
////    list2.insertAtTail(4);
////    list2.insertAtTail(5);
////    list2.insertAtTail(6);
////    list2.print();  // Output: 4 5 6
////
////    list1.concatenate(list2);
////    list1.print();  // Output: 1 2 3 4 5 6
////
////    return 0;
////}
//
////instersection 
//#include <iostream>
//#include <unordered_set>
//
//class Node {
//public:
//    int data;
//    Node* next;
//
//    Node(int data) {
//        this->data = data;
//        this->next = nullptr;
//    }
//};
//
//class CircularLinkedList {
//public:
//    Node* tail;
//
//    CircularLinkedList() {
//        tail = nullptr;
//    }
//
//    void insertAtTail(int data) {
//        Node* newNode = new Node(data);
//        if (tail == nullptr) {
//            tail = newNode;
//            tail->next = tail;
//        }
//        else {
//            newNode->next = tail->next;
//            tail->next = newNode;
//            tail = newNode;
//        }
//    }
//
//    bool intersect(CircularLinkedList list) {
//        std::unordered_set<Node*> set;
//        Node* current = tail->next;
//        while (current != tail) {
//            set.insert(current);
//            current = current->next;
//        }
//        set.insert(tail);
//        current = list.tail->next;
//        while (current != list.tail) {
//            if (set.find(current) != set.end()) {
//                return true;
//            }
//            current = current->next;
//        }
//        if (set.find(list.tail) != set.end()) {
//            return true;
//        }
//        return false;
//    }
//
//    void print() {
//        if (tail == nullptr) {
//            return;
//        }
//        Node* current = tail->next;
//        while (current != tail) {
//            std::cout << current->data << " ";
//            current = current->next;
//        }
//        std::cout << current->data << std::endl;
//    }
//};
//
//int main() {
//    CircularLinkedList list1, list2;
//
//    list1.insertAtTail(1);
//    list1.insertAtTail(2);
//    list1.insertAtTail(3);
//    list1.insertAtTail(4);
//    list1.insertAtTail(5);
//
//    list2.insertAtTail(6);
//    list2.insertAtTail(7);
//    list2.insertAtTail(8);
//    list2.insertAtTail(9);
//    list2.insertAtTail(10);
//
//    std::cout << "List 1: ";
//    list1.print();  // Output: 1 2 3 4 5
//
//    std::cout << "List 2: ";
//    list2.print();  // Output: 6 7 8 9 10
//
//    list2.tail->next = list1.tail->next->next->next;
//
//    if (list1.intersect(list2)) {
//        std::cout << "The lists intersect." << std::endl;
//    }
//    else {
//        std::cout << "The lists do not intersect." << std::endl;
//    }
//
//    return 0;
//}
//

