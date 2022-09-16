#include <stdio.h>

//Program to check for balanced parenthesis in an expression.
int main(){
    char exp[50];
    int i = 0, x = 0;
    printf("\nEnter expression: ");
    scanf("%s",exp);

    while(exp[i] != '\0'){
        if(exp[i] == '('){
            x++;
        }
        else if(exp[i] == ')'){
            x--;
            if(x<0){
                break;
            }
        }
        i++;
    }

    if(x==0){
        printf("Expression is balanced");
    }
    else{
        printf("Expression is unbalanced");
    }
    return 0;
}