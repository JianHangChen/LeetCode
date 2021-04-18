/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */


//!!! sol2, O(logn), O(1)
// complaxity analysis:
// how to compare r* 2 vs r*10 expanding
// expand:          -> O(log2(n)) > O(log10(n))   overshooting: 2n, 10n
// binary search:   -> O(log2(2n))< O(log2(10n))
// overall log2 - log10 = log2(n) + log2(2n) - log10(n) - log2(10n)
// = log2(5n) - log10(n) = log2(5) + log2(n) - log10(n) > 0 when n->INF, so 10 times expand is better

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int l = 0, r = 1;
        // expand:
        while(reader.get(r) < target){//!!! use target will be better
            r *= 2;
        }
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(reader.get(mid) == target) return mid;
            else if(reader.get(mid) < target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;

    }
};

//sol1, my, very bad solution!!!
// class Solution {
// public:
//     int OUT_OF_BOUND = 2147483647;
//     int search(const ArrayReader& reader, int target) {
//         int l = 0, r = INT_MAX;
//         while(l <= r){
//             int mid = l + (r - l) / 2;
//             if(reader.get(mid) == target) return mid;
//             else if(reader.get(mid) < target){
//                 l = mid + 1;
//             }
//             else{
//                 r = mid - 1;
//             }
//         }
            
//         return -1;// target not exist
//     }
// };
