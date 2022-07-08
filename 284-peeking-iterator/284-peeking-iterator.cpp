
class PeekingIterator : public Iterator {
public:
    ListNode* head= new ListNode(0);
    ListNode* curr=head;
	
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        for(auto Iterator: nums){
            curr->next=new ListNode(Iterator);
            curr=curr->next;
        }
        head=head->next;    
	}
	
	int peek() {
        return head->val;
	}

	int next() {
	   int x=head->val;
        head=head->next;
        return x;
	}
	
	bool hasNext() const {
	    return head;
	}
};