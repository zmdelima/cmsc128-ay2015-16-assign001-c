#include<stdio.h>
void numToWords(int num);

int main(){
    numToWords(811013);
}

void numToWords (int num) {
    int placement=1000000;
    int res, temp, n;
    int p = placement;
    
    if (num == 0) {
        printf("zero");
        return;
    }
    if (num > 1000000 || num < 0) {
        printf("\nInvalid input!");
        return;
    }
    
    while(placement > 0){
        res = num/placement;
        p = placement;
        n=num;
        if  (p == 10 || p == 10000) {
            switch (res) {
                case 0: break;
                case 1:     
                            temp = (n / (p/10)) - (res * 10);
                            switch (temp){
                                case 0: printf(" ten"); break;
                                case 1: printf(" eleven"); break;
                                case 2: printf(" twelve"); break;
                                case 3: printf(" thirteen"); break;
                                case 4: printf(" fourteen"); break;
                                case 5: printf(" fifteen"); break;
                                case 6: printf(" sixteen"); break;
                                case 7: printf(" seventeen"); break;
                                case 8: printf(" eighteen"); break;
                                case 9: printf(" nineteen");   
                            }
                            n = n - ((n/(p/10)) * (p/10)); 
                            res = temp;
                            placement = p/10;
                            if (res > 0) {
                                n = n - (res * (p));
                                temp = num - n;
                            }
                            if ( (temp != 0 && res!=0)  || res!= 0) {
                                switch (p){
                                    case 0: break;
                                    case 100: printf(" hundred"); break;
                                    case 1000: printf(" thousand"); break;
                                    case 100000: printf(" hundred"); break;
                                    case 1000000: printf(" million");
                                }
                            }
                            continue;
                            break;
                case 2: printf(" twenty");break;
                case 3: printf(" thirty");break;
                case 4: printf(" forty");break;
                case 5: printf(" fifty");break;
                case 6: printf(" sixty");break;
                case 7: printf(" seventy");break;
                case 8: printf(" eighty");break;
                case 9: printf(" ninety");break;
                default: break;
            }
        }
        else {
            switch (res) {
                case 0: break;
                case 1: printf(" one"); break;
                case 2: printf(" two"); break;
                case 3: printf(" three"); break;
                case 4: printf(" four"); break;
                case 5: printf(" five"); break;
                case 6: printf(" six"); break;
                case 7: printf(" seven"); break;
                case 8: printf(" eight"); break;
                case 9: printf(" nine");   
            }
        }
        
        temp = num-n;
        placement = p/10;
        
        if (res > 0) {
            n = n - (res * (p));
            temp = num - n;
        }
        if ( (temp != 0 && res!=0)  || res!= 0) {
            switch (p){
                case 0: break;
                case 100: printf(" hundred"); break;
                case 1000: printf(" thousand"); break;
                case 100000: printf(" hundred"); break;
                case 1000000: printf(" million");
            }
        }
        
        num = n;
    }
    printf("\n");     
}
