    void filterChars(char *a,int no){
    /// a = "abc" no = 5 -- Output should ac.
    
    int i=0;
    while(no>0){
        (no&1)?cout<<a[i]:cout<<"";
        i++;
        no = no>>1;
    }
    cout<<endl;
    
}
void generateSubsets(char *a){
    //Generate a range of numbers from 0 to 2^n -1
    int n = strlen(a);
    int range = (1<<n) - 1;
    
    for(int i=0;i<=range;i++){
        filterChars(a,i);
    }
    
}

int main(){
    char a[] = "abc";
    generateSubsets(a);

return 0;
}
