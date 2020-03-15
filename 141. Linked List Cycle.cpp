class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* first = head, * second = head;
        
        while(second && second->next){
            first = first->next;
            second = second->next->next;
            if(first == second) return true;
        }
        return false;
        
    }
};





class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """    
        # sol1, my two pointer catch
        # cur = head
        # if cur:
        #     fly = cur.next
        # while cur and fly:
        #     if fly is cur:
        #         return True
        #     else:
        #         cur = cur.next
        #         if fly.next is None:
        #             return False
        #         fly = fly.next.next       
        # return False       
        
        # sol1.1, use try
        # https://leetcode.com/problems/linked-list-cycle/discuss/44494/Except-ionally-fast-Python
#         try:
#             slow = head
#             fast = head.next
#             while slow is not fast:
#                 slow = slow.next
#                 fast = fast.next.next
#             return True
#         except:
#             return False
            
    
        # sol2, from sol, my hash table!
        # this solution can get the position
        cur = head
        table = {}
        # pos = 0
        while cur:
            if cur in table.keys():
                return True #table[cur]
            else:
                table[cur] = True
                # table[cur] = pos
                cur = cur.next
                # pos += 1
        return False
        
