#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#define size 32

using namespace std;

struct prio_array{
    char sign;
    int pref;
};

typedef struct prio_array pr_arr;


int top = -1;
int post_count = 0;

char st[size];



int priority_checker(pr_arr arr[], char stTop, char b){
    int topVal, scVal;
    for(int i=0; i<6; i++){
        if(arr[i].sign == stTop){
            topVal = arr[i].pref;
        }
        if(arr[i].sign == b){
            scVal = arr[i].pref;
        }
    }
    if(topVal < scVal){
        return 0;
    }
    else{
        return 1;
    }

}


void update_stack(pr_arr arr[], char post[], char scEle){
    printf("\nScanned Element\t stack top\n");
    printf("%c\t\t %c", scEle, st[top]);
    
    if((scEle >= 65 && scEle <= 90) || (scEle >=97 && scEle <=122) || (scEle >=48 && scEle <=57)){
        post[post_count++] = scEle;
    }
    else if(scEle == '('){
        st[++top] = scEle;
    }
    else if(scEle == ')'){
        char topElement = st[top];
        while(topElement != '('){
            printf("\nScanned Element\t stack top\n");
            printf("%c\t\t %c", scEle, st[top]);
            post[post_count++] = st[top--];
            topElement = st[top];
        }
        top--;
    }
    else{
        int isGreater = priority_checker(arr, st[top], scEle);
        while(isGreater){
            printf("\nScanned Element\t stack top\n");
            printf("%c\t\t %c", scEle, st[top]);
            post[post_count++] = st[top--];
            isGreater = priority_checker(arr, st[top], scEle);
        }
        st[++top] = scEle;

    }
}



int main(){
    int n;
    char infix[50], postfix[50];
    pr_arr p_arr[6];
    p_arr[0].sign = '(';
    p_arr[0].pref = 0;
    p_arr[1].sign = '+';
    p_arr[1].pref = 1;
    p_arr[2].sign = '-';
    p_arr[2].pref = 1;
    p_arr[3].sign = '*';
    p_arr[3].pref = 2;
    p_arr[4].sign = '/';
    p_arr[4].pref = 2;
    p_arr[5].sign = '^';
    p_arr[5].pref = 3;

    printf("\n\n..Welcome to Infix to Postfix conversion program...\n\n");
    while(1){
        int choice;
        printf("What to do? conversion(1) exit(2): ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Type the whole infix expression: ");
                scanf("%s", infix);
                n = strlen(infix);
                for(int i=0; i<n; i++){
                    update_stack(p_arr, postfix, infix[i]);
                }
                postfix[post_count] = '\0';
                printf("\nThe equivalent postfix expressin is: ");
                puts(postfix);
                break;
            case 2:
                printf("Thank you.");
                exit(0);
        }
    }
}
