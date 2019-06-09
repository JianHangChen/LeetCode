class Solution {
public:
    /*
     * @param nums: an integer array
     * @return: the first node of linked list
     */
     
    //test: nums = []
    ListNode * toLinkedList(vector<int> &nums) {
        ListNode* head = NULL, *cur;
        
        int n = nums.size();
        
        if(n == 0){ return head;}
        
        head = new ListNode(nums[0]);
        
        cur = head;
        for(int i = 1; i < n; i++){
            cur->next = new ListNode(nums[i]);
            cur = cur->next;
        }
        return head;
        
    }
};
