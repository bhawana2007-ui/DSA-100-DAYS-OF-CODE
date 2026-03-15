#include <stdio.h>
#include <string.h>

int d[100], f = -1, r = -1;

void push_front(int x){
    if(f==-1) f=r=0;
    else f--;
    d[f]=x;
}

void push_back(int x){
    if(f==-1) f=r=0;
    else r++;
    d[r]=x;
}

void pop_front(){
    if(f==-1) printf("-1\n");
    else if(f==r) f=r=-1;
    else f++;
}

void pop_back(){
    if(f==-1) printf("-1\n");
    else if(f==r) f=r=-1;
    else r--;
}

int main(){
    int n,x;
    char op[20];
    scanf("%d",&n);

    while(n--){
        scanf("%s",op);

        if(strcmp(op,"push_front")==0){
            scanf("%d",&x);
            push_front(x);
        }
        else if(strcmp(op,"push_back")==0){
            scanf("%d",&x);
            push_back(x);
        }
        else if(strcmp(op,"pop_front")==0) pop_front();
        else if(strcmp(op,"pop_back")==0) pop_back();
        else if(strcmp(op,"front")==0) printf("%d\n", (f==-1)?-1:d[f]);
        else if(strcmp(op,"back")==0) printf("%d\n", (f==-1)?-1:d[r]);
        else if(strcmp(op,"size")==0) printf("%d\n", (f==-1)?0:r-f+1);
        else if(strcmp(op,"empty")==0) printf("%d\n", (f==-1));
    }

    return 0;
}