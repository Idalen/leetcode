class Solution {
public:
    
    int compute(string substring){
        int signal = 1;
        int sum = 0, num=0;
        int count, begin;
        

        for(int i=0; i<substring.size(); i++){
            if(substring[i]==' ')
                continue;
            if(substring[i]=='('){
                count = 1;
                begin = i+1;
                do{
                    i++;
                    if (substring[i] == '(') count++;
                    if (substring[i] == ')') count--;
                }while(count != 0);
                sum += signal*compute(substring.substr(begin,i-begin));
            }
            else if(substring[i]=='-')
                signal = -1;
            else if(substring[i]=='+')
                signal = 1;
            else{
                num *= 10;
                num += (((int) substring[i]) - 48); 
                if(substring[i+1] < '0' || substring[i+1]>'9'){
                    sum += signal*num;
                    num = 0;
                }
            }

            
                
        }
        return sum;
    }


    int calculate(string s) {
        return compute(s);
    }
};