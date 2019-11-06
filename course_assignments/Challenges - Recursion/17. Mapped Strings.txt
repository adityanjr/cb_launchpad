#include <iostream>
#include<cstring>
using namespace std;
char mapping[][27]={"", "A", "B", "C", "D", "E", 
        "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", 
        "S", "T", "U", "V", "W", "X", "Y", "Z"}; 
void change(string str,string output,int count){
    int strlen=str.length();
    if(count == strlen){
        cout<<output<<endl;
        return;
    }
    if(str[count]!='0'){
        int num=str[count]-'0';
        string ch = mapping[num];
        change(str,output+ch,count+1);
    }
    if(count<strlen-1){
        int num2=str[count]-'0';
        int num3=str[count+1]-'0';
        int num4=(num2*10)+(num3);
        if(num4<=26){
            string ch1 = mapping[num4];
            change(str,output+ch1,count+2);
        }
    }     
}
int main() {
  string str;
  cin>>str;
  change(str,"",0);
}

--------------------------------------------------------------

#include<iostream>
#include<cstring>
using namespace std;
void print(char* input,char* output,int i,int j,int length){
    if(input[i]=='\0'){
        output[j]='\0';
        cout<<output<<endl;
        return;
    }
    int sdigit=input[i]-'0';
    int ddigit;
    if(i+1<length){
    ddigit=(input[i]-'0')*10+(input[i+1]-'0');
    }
    else
        ddigit=sdigit;

    output[j]=sdigit+64;
    print(input,output,i+1,j+1,length);
    if(ddigit>9 && ddigit<=26){
        output[j] = ddigit+64;
        print(input,output,i+2,j+1,length);
    }
}
int main() {
    char input[10];
    char output[10];
    cin>>input;
    int len = strlen(input);
    print(input,output,0,0,len);
	return 0;
}