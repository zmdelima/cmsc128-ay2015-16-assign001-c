#include<stdio.h>
void numToWords (int num);
void printAdj (int res);
void printPlacement(int p);
void tenToTwenty(int num);

int main(){
    numToWords(1000712);
    return 0;
}

void numToWords (int num) {
    int placement=1000000;
    int old_placement = placement;
    int res;
    while (placement != 0) {
        res = num / old_placement;
        /*switch (res) {
            case 0:break;
            case 1: placement = checkTens(placement,res);
                    printPlacement(old_placement);
                    break;
            case 2: placement = checkTens(placement,res);
                    printPlacement(old_placement);
                    break;
            case 3: placement = checkTens(placement,res);
                    printPlacement(old_placement);
                    break;
            case 4: placement = checkTens(placement,res);
                    printPlacement(old_placement);
                    break;
            case 5: placement = checkTens(placement,res);
                    printPlacement(old_placement);
                    break;
            case 6: placement = checkTens(placement,res);
                    printPlacement(old_placement);
                    break;
            case 7: placement = checkTens(placement,res);
                    printPlacement(old_placement);
                    break;
            case 8: placement = checkTens(placement,res);
                    printPlacement(old_placement);
                    break;
            case 9: placement = checkTens(placement,res);
                    printPlacement(old_placement);
                    break;
            default:printf("Input error! res");
                    break;
        }*/
        printf("res = %i-------->",res);
        placement = checkTens(placement, res, &num);
        if (res != 0)printPlacement(old_placement);
        printf("\nplacement = %i +++++ num = %i\n",placement,num);
        num = num - ( res  * old_placement);
        old_placement = placement;
        
    }       
}

int checkTens (int placement, int res, int num) {
    int temp = num;
    if (placement == 10 || placement == 10000){
        switch (res) {
            case 0: break;
            case 1: 
                    printf("tempb4 = %i",temp);
                    printf("\n\ntemp = %i\n\n", (temp / (placement/100)));
                    //tenToTwenty(temp);
                    return (placement/100);
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
    }
    placement = placement/10;
    return placement;   
}


void printAdj (int res) {
    switch (res){
        case 0: break;
        case 1: printf(" one");
                break;
        case 2: printf(" two");
                break;
        case 3: printf(" three");
                break;
        case 4: printf(" four");
                break;
        case 5: printf(" five");
                break;
        case 6: printf(" six");
                break;
        case 7: printf(" seven");
                break;
        case 8: printf(" eight");
                break;
        case 9: printf(" nine");
                break;
        default: printf("Input Error! adj"); 
                break;       
    }
}


void printPlacement (int p) {
    switch (p){
        case 0: break;
        case 100:   printf(" hundred");
                break;
        case 1000: printf(" thousand");
                break;
        case 100000: printf(" hundred");
                break;
        case 1000000: printf(" million");
                break;
        default:break;
    }
}

void tenToTwenty (int num) {
    switch (num){
        case 0: printf(" ten");
                break;
        case 1: printf(" eleven");
                break;
        case 2: printf(" twelve");
                break;
        case 3: printf(" thirteen");
                break;
        case 4: printf(" fourteen");
                break;
        case 5: printf(" fifteen");
                break;
        case 6: printf(" sixteen");
                break;
        case 7: printf(" seventeen");
                break;
        case 8: printf(" eighteen");
                break;
        case 9: printf(" nineteen");
                break;   
    }
}
