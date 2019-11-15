//sol1.1, imporved from my sol1, 9ch O(n+G) O(G)

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> s(G.begin(), G.end());
        int count = 0;

        while(head){
        	if(s.count(head->val) > 0 && (head->next == NULL || s.count(head->next->val) == 0)) count++;
        	head = head->next;
        }
        return count;
    }
};





//sol1, my O(n+G) O(G)

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> s;
        for(int val:G) s.insert(val);
    
        int count = 0; bool inside = false;

        while(head){
        	if(!inside){
        		if( s.count(head->val) > 0){
        			count++;
        			inside = true;
        		}
        	}
        	else{
        		if(s.count(head->val) == 0) inside = false;
        	}
        	head = head->next;
        }
        return count;
    }
};
