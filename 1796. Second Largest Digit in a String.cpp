class Solution {
public:
    int secondHighest(string s) {
        int largest = -1, secondlargest = -1;
        for(char c:s){
            if(isdigit(c)){
                if( c - '0' > largest){
                    secondlargest = largest;
                    largest = c - '0';
                }
                else if(c - '0' > secondlargest && c - '0' < largest){
                    secondlargest = c - '0';
                }
            }
        }
        return secondlargest;
    }
};
