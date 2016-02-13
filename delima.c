#include<stdio.h>
#include<string.h>

void numToWords (int num) {
    //variables to be used
    int placement=1000000;
    int res, temp, n;
    int p = placement;
    //if special case of number passed is equal to 0
    if (num == 0) {
        printf("zero");
        return;
    }
    //if number passed is invalid
    if (num > 1000000 || num < 0) {
        printf("\nInvalid number to worded number input!");
        printf("\nnumToWords function ");
        return;
    }
    //mainloop for parsing digit per digit
    while(placement > 0){
        //configurations per loop
        res = num/placement;
        p = placement;
        n=num;
        //condition if placement is in tens digit of 3 every digits(from right to left)
        if  (p == 10 || p == 10000) {
            switch (res) { //tens digits
                case 0: break;
                case 1:     //special case of tens from ten to nineteen
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
        else { //ones or hundreds digits
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
        //configuration if placement is to be printed
        temp = num-n;
        placement = p/10;
        
        if (res > 0) {//condition of reconfigurating current number being parsed
            n = n - (res * (p));
            temp = num - n;
        }
        if ( (temp != 0 && res!=0)  || res!= 0) {//condition for printing placement
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

int wordsToNum (char *s) {
    //wordsToNum objectives
    //detect if there is an uppercase reject : parse
    //parse per token -> create a temp int to accumulate until placement arrives
    //if placement arrives or end of string(null) add acc + tempint : next word
    //if string is erroneous this returns a value of -1
    
    //variables to be used
    char *t; 
    int num=0, temp=0, i=0;
    
    //checking for uppercase letters ? reject input : parse
    for(i=0;i<strlen(s);i++){
        if((int)s[i] >=65 && (int)s[i] <=90 ){ 
            printf("Invalid input! function wordsToNum only accepts lowercased values");
            return;
        }
    }
    //checking for empty string
    if(strlen(s) == 0){
        return;
    }
    //checking for special case zero string
    else if ((strcmp(s,"zero"))==0) {
        printf("0");
        return 0;
    }
    //main loop of wordsToNum
    while( (t = strsep(&s," ")) != NULL ) {
        //catch case for ones digits
        if ((strcmp(t,"one"))==0) {
            temp = temp + 1;
        }
        else if ((strcmp(t,"two"))==0) {
            temp = temp + 2;
        }
        else if ((strcmp(t,"three"))==0) {
            temp = temp + 3;
        }
        else if ((strcmp(t,"four"))==0) {
            temp = temp + 4;
        }
        else if ((strcmp(t,"five"))==0) {
            temp = temp + 5;
        }
        else if ((strcmp(t,"six"))==0) {
            temp = temp + 6;
        }
        else if ((strcmp(t,"seven"))==0) {
            temp = temp + 7;
        }
        else if ((strcmp(t,"eight"))==0) {
            temp = temp + 8;
        }
        else if ((strcmp(t,"nine"))==0) {
            temp = temp + 9;
        }
        //catch case for special tens case
        else if ((strcmp(t,"ten"))==0) {
            temp = temp + 10;
        }
        else if ((strcmp(t,"eleven"))==0) {
            temp = temp + 11;
        }
        else if ((strcmp(t,"twelve"))==0) {
            temp = temp + 12;
        }
        else if ((strcmp(t,"thirteen"))==0) {
            temp = temp + 13;
        }
        else if ((strcmp(t,"fourteen"))==0) {
            temp = temp + 14;
        }
        else if ((strcmp(t,"fifteen"))==0) {
            temp = temp + 15;
        }
        else if ((strcmp(t,"sixteen"))==0) {
            temp = temp + 16;
        }
        else if ((strcmp(t,"seventeen"))==0) {
            temp = temp + 17;
        }
        else if ((strcmp(t,"eighteen"))==0) {
            temp = temp + 18;
        }
        else if ((strcmp(t,"nineteen"))==0) {
            temp = temp + 19;
        }
        //catch case for tens digits
        else if ((strcmp(t,"twenty"))==0) {
            temp = temp + 20;
        }
        else if ((strcmp(t,"thirty"))==0) {
            temp = temp + 30;
        }
        else if ((strcmp(t,"forty"))==0) {
            temp = temp + 40;
        }
        else if ((strcmp(t,"fifty"))==0) {
            temp = temp + 50;
        }
        else if ((strcmp(t,"sixty"))==0) {
            temp = temp + 60;
        }
        else if ((strcmp(t,"seventy"))==0) {
            temp = temp + 70;
        }
        else if ((strcmp(t,"eighty"))==0) {
            temp = temp + 80;
        }
        else if ((strcmp(t,"ninety"))==0) {
            temp = temp + 90;
        }
        //catch case for digit placements
        //this accumulates the current result 
        //to num and resets temp variable to 0
        else if ((strcmp(t,"hundred"))==0) {
            num  = num + (temp * 100);
            temp = 0;
        }
        else if ((strcmp(t,"thousand"))==0) {
            num  = (num*1000) + (temp * 1000);
            temp = 0;
        }
        else if ((strcmp(t,"million"))==0) {
            num  = num + (temp * 1000000);
            temp = 0;
        }
        else {
            printf("Invalid input! Please check string spelling");
            return -1;
        }
        //condition if string given wants to parse worded number above 1 million
        if (num > 1000000) {
            printf("Invalid input! wordsToNum only accepts zero to 1 million");    
        }
    }
    //final evaluation of num
    num = num + temp;
    //returning of resulting value
    return num;
}

char *wordsToCurrency(char *num, char *currency ) { 
    //wordsToCurrency     
    //functions with 2 arguments arg1:worded number string
    //arg2: currency string
    //variables to be used
    char *s = strdup(currency);
    char *t = strdup("");
    int number = wordsToNum(num);
    
    if (number < 0) {//condition if returned number is invalid
       printf("Invalid number string for currency!");
       return t;
    }
    //concatenation of currency and parsed worded number to integer 
    sprintf(t,"%s%i",s,number);
    return t;
}


