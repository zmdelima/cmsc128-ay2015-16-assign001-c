#include<stdio.h>
void numToWords (int num);
void printAdj (int res);
void printPlacement(int p);
void tenToTwenty(int num);

int main(){
    //numToWords(1019715);
    return 0;
}

void numToWords (int num) {
    int placement=1000000;
    int res;
    while(placement > 0){
        res = num/placement;
        num = checkTens(num, res, &placement);
    }     
}

int checkTens(int num, int res, int* p) {
    int temp;
    int placement = *p;
    if  (placement == 10 || placement == 10000) {
        switch (res) {
            case 0: break;
            case 1: 
                        temp = (num / (placement/10)) - (res * 10);
                        tenToTwenty(temp);
                        num = num - ((num/(placement/10)) * (placement/10)); 
                        res = temp;
                        if (res > 0) {
                            printPlacement(placement/10);
                        }
                        *p = placement/10;
                        return num;
                        break;
            case 2: printf(" twenty");
                        break;
            case 3: printf(" thirty");
                        break;
            case 4: printf(" forty");
                        break;
            case 5: printf(" fifty"); 
                        break;
            case 6: printf(" sixty"); 
                        break;
            case 7: printf(" seventy"); 
                        break;
            case 8: printf(" eighty");
                        break;
            case 9: printf(" ninety");
                        break;
            default: printf("Error input! tens");
                        break;
        }
    }
    else {
        printAdj(res);
        if (res > 0) {
            printPlacement(placement);
        }
    }
    
    num = num - (res * (placement));
    *p = placement/10;
    return num;
}

void printAdj (int res) {
    switch (res){
        case 0: break;
        case 1: printf(" one"); break;
        case 2: printf(" two"); break;
        case 3: printf(" three"); break;
        case 4: printf(" four"); break;
        case 5: printf(" five"); break;
        case 6: printf(" six"); break;
        case 7: printf(" seven"); break;
        case 8: printf(" eight"); break;
        case 9: printf(" nine"); break;    
    }
}

void printPlacement (int p) {
    switch (p){
        case 0: break;
        case 100: printf(" hundred"); break;
        case 1000: printf(" thousand"); break;
        case 100000: printf(" hundred"); break;
        case 1000000: printf(" million"); break;
        default: break;
    }
}

void tenToTwenty (int num) {
    switch (num){
        case 0: printf(" ten"); break;
        case 1: printf(" eleven"); break;
        case 2: printf(" twelve"); break;
        case 3: printf(" thirteen"); break;
        case 4: printf(" fourteen"); break;
        case 5: printf(" fifteen"); break;
        case 6: printf(" sixteen"); break;
        case 7: printf(" seventeen"); break;
        case 8: printf(" eighteen"); break;
        case 9: printf(" nineteen"); break;   
    }
}
