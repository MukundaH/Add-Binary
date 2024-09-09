char* addBinary(char* a, char* b) {
    char * l, * s;
    int ls, ss, carry=0;
    if(strlen(a)>=strlen(b)){
        l=a; ls=strlen(a);
        s=b; ss=strlen(b);
    }
    else{
        l=b; ls=strlen(b);
        s=a; ss=strlen(a);
    }
    int i=ls-1, j=ss-1;
    while(i>=0){
        int ds;
        if(j<0){
            ds=0;
        }
        else{
            ds=s[j]-48;
        }
        int d=l[i]+ds-48+carry;
        if(d==0){
            l[i]='0';
            carry=0;
        }
        else if(d==1){
            l[i]='1';
            carry=0;
        }
        else if(d==2){
            l[i]='0';
            carry=1;
        }
        else{
            l[i]='1';
            carry=1;
        }
        i--;
        j--;
    }
    if(carry==1){
        char * s = (char*)malloc((ls+2)*sizeof(char));
        s[0]='1';
        for(int i=0; i<ls; i++){
            s[i+1]=l[i];
        }
        s[ls+1]='\0';
        return s;
    }
    return l;
}
