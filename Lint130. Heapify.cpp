
//!!! sol2, my shiftdown, O(n), O(1), iteratively
class Solution {
public:
    void heapify(vector<int> &A) {
        int n = A.size();
        for(int i = n/2 - 1; i >= 0; i--){
            shiftDown(i, A);
        }
    }
    void shiftDown(int i, vector<int>& A){
        int n = A.size();

        while(i < n){
            int left = i * 2 + 1, right = i * 2 + 2;
            if(left >= n) return;
            if(right == n || right < n && A[left] < A[right]){
                if(A[i] <= A[left]) return;
                swap(A[i], A[left]);
                i = left;
            }
            else{
                if(A[i] <= A[right]) return;
                swap(A[i], A[right]);
                i = right;
            }
        }
    }
};

//!!sol1, my shift down, O(n), O(logn)
class Solution {
public:
    void heapify(vector<int> &A) {
        int n = A.size();
        
        for(int i = n - 1; i >= 0; i--){
            shiftDown(i, A);
        }
    }
    void shiftDown(int i, vector<int>& A){
        int n = A.size();
        int left = i * 2 + 1, right = i * 2 + 2;
        if(left >= n) return;
        
        if(right == n || right < n && A[left] < A[right]){
            if(A[i] <= A[left]) return;
            swap(A[i], A[left]);
            shiftDown(left, A);
        }
        else{
            if(A[i] <= A[right]) return;
            swap(A[i], A[right]);
            shiftDown(right, A);
        }
    }
};





class Solution:
    """
    @param: A: Given an integer array
    @return: nothing
    """
    # sol2: siftdown O(n)

    
    def heapify(self, A):
        length = len(A)
        father = (length-2)//2
        for i in range(father,-1,-1):
            self.siftdown(A,i)
    def siftdown(self, A, i):
        
        smallest = i
        while i >= 0:
            leftchild = 2 * i + 1
            rightchild = 2 * i + 2
            if leftchild < len(A) and A[smallest] > A[leftchild]:
                smallest = leftchild
            if rightchild < len(A) and A[smallest] > A[rightchild]:
                smallest = rightchild
            if smallest == i:
                break
            else:
                temp = A[smallest]
                A[smallest] = A[i]
                A[i] = temp
                i = smallest


    
    # # sol1: siftup  O(nlogn)
    # def heapify(self, A):
    #     # write your code here
    #     length = len(A)
    #     for index in range(length):
    #         self.siftup(A,index)
    #     # print(A)

    # def siftup(self,A, index):
    #     child = index
    #     father = (child-1)//2
    #     while child != 0 and A[father] > A[child]:
    #         temp = A[father]
    #         A[father] = A[child]
    #         A[child] = temp
    #         child = father
    #         father = (child-1)//2
            
            
    # # sol3: just fun
    # def heapify(self, A):
    #     import heapq
    #     heapq.heapify(A)
