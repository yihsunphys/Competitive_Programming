class MyLinkedList {
    private:
        struct ListNode{
            int val;
            ListNode* next;
            ListNode(int val): val(val), next(nullptr){}
            ListNode(int val, ListNode* next): val(val), next(next){}
        };
        int _size = 0;
        ListNode* dummy; 
    public:
        MyLinkedList() {
            dummy = new ListNode(0);
        }
        
        int get(int index) {
            if(index > (_size-1) || index < 0) return -1;
            ListNode* cur = dummy->next;
            while(index--){
                cur = cur->next;
            }
            return cur->val;
        }
        
        void addAtHead(int val) {
            ListNode* newhead = new ListNode(val);
            newhead->next = dummy->next;
            dummy->next = newhead;
            _size++;
        }
        
        void addAtTail(int val) {
            ListNode* newtail = new ListNode(val);
            ListNode* cur = dummy;
            while(cur->next){
                cur = cur->next;
            }
            cur->next = newtail;
            _size++;
        }
        
        void addAtIndex(int index, int val) {
            if(index>_size) return;
            if(index<0) index = 0;
            ListNode* cur = dummy;
            while(index--){
                cur = cur->next;
            }
            ListNode* tmp = new ListNode(val, cur->next);
            cur->next = tmp;
            _size++;
        }
        
        void deleteAtIndex(int index) {
            if(index>=_size || index<0) return;
            ListNode* cur = dummy;
            while(index--){
                cur = cur->next;
            }
            ListNode* tmp = cur->next;
            cur->next = tmp->next;
            delete(tmp);
            _size--;
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