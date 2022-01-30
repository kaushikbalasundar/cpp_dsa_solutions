#include<iostream>
#include<cstring> 
using namespace std; 

void replace_space(char *str){

    int spaces = 0;
    for(int i=0; i!='\0'; i++){

        if(str[i] == ' '){
            spaces++;
        }

    }
    int idx = strlen(str) + 2*spaces;
}

int main(){

    char input[10000];
    cin.getline(input,1000);
    replace_space(input);
    return 0;
}