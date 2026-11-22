class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;

        Node(int x) {
            val = x;
            next = NULL;
        }
    };

    Node* head;
public:
    MyLinkedList() {
        head=NULL;
    }
    
    int get(int index) {
        Node* temp=head;
        while(index>0 && temp!=NULL){
            temp=temp->next;
            index--;
        }
        if(temp==NULL) return -1;
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node *newNode=new Node(val);
        newNode->next=head;
        head=newNode;
    }
    
    void addAtTail(int val) {
        Node *newNode=new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0) return;
        if(index==0){
            addAtHead(val);
            return;
        }
        Node* temp = head;
        for (int i = 0; i < index - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr)
            return;
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || head == nullptr)
            return;
        if (index == 0) {
            Node* del = head;
            head = head->next;
            delete del;
            return;
        }
        Node* temp = head;
        for (int i = 0; i < index - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr)
            return;
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna