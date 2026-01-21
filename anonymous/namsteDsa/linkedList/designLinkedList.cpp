class MyLinkedList {

    // Node structure for singly linked list
    struct Node {
        int val;        // data
        Node* next;     // pointer to next node

        // Constructor: value only
        Node(int v) {
            val = v;
            next = nullptr;
        }

        // Constructor: value + next pointer
        Node(int v, Node* n) {
            val = v;
            next = n;
        }
    };

    Node* front;   // head of list
    Node* tail;    // last node
    int size;      // number of nodes

    // Returns pointer to node at given index (assumes index is valid)
    Node* getNodeAt(int index) {
        Node* curr = front;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr;
    }

public:

    // Constructor: initialize empty list
    MyLinkedList() {
        front = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Destructor: free all nodes (avoid memory leak)
    ~MyLinkedList() {
        Node* curr = front;
        while (curr) {
            Node* tmp = curr;
            curr = curr->next;
            delete tmp;
        }
    }

    // Get value at index
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        return getNodeAt(index)->val;
    }

    // Insert at head
    void addAtHead(int val) {
        Node* node = new Node(val, front);
        front = node;

        // If list was empty, tail also points here
        if (size == 0) {
            tail = node;
        }

        size++;
    }

    // Insert at tail
    void addAtTail(int val) {
        Node* node = new Node(val);

        if (size == 0) {
            front = tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }

        size++;
    }

    // Insert at index
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;

        if (index == 0) {
            addAtHead(val);
        }
        else if (index == size) {
            addAtTail(val);
        }
        else {
            Node* prev = getNodeAt(index - 1);
            Node* node = new Node(val, prev->next);
            prev->next = node;
            size++;
        }
    }

    // Delete node at index
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        if (index == 0) {
            Node* tmp = front;
            front = front->next;
            delete tmp;

            // If list becomes empty
            if (size == 1) {
                tail = nullptr;
            }
        }
        else {
            Node* prev = getNodeAt(index - 1);
            Node* delNode = prev->next;

            prev->next = delNode->next;

            // If deleting last node
            if (delNode == tail) {
                tail = prev;
            }

            delete delNode;
        }

        size--;
    }
};
