class Solution {
public:
    int addDigits(int num) {
        int acc;
        
        do{    
            acc = 0;
            while(num!=0){
                acc += num%10;
                num/=10;
            }
            num=acc;
        }while(acc>=10);
        
        return acc;
    }
};