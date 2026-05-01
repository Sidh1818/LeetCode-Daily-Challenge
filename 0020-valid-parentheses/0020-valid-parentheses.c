int leng(char *s){
    int count =0;
    for(int i=0;s[i]!='\0';i++)
        count++;

    return count;
}

bool isValid(char* s) {
    int n = leng(s);
    char stack[n];
    int top = -1;
    for(int i=0;s[i]!='\0';i++){
        char ch = s[i];
        if(ch=='('||ch=='{'||ch=='[')
            stack[++top]=ch;
        else{
            if(top==-1)
                return false;

            char topchar = stack[top--];
            if((ch == ')'&&topchar!='(')||
                (ch=='}'&&topchar!='{')||
                (ch==']'&&topchar!='[')){
                    return false;
                } 
        }
    }
    return top==-1;
}