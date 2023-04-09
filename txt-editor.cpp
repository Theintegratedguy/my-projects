#include<iostream> 
#include<windows.h> 
#include<string>
#include<bits/stdc++.h> 
using namespace std; 
#define n 5000
void search(string s){
    string word;
    system("cls");
    cout<<endl<<"_______________________________________________________"<<endl;
    cout<<endl<<"enter the word to find in the text: "; 
    cin.ignore(); 
    getline(cin, word); 
    int count=0;
    size_t pos = s.find(word, 0);
    while(pos != string::npos)
    {
        count++;
        pos = s.find(word, pos+1);
    }
    if(count>0){
        cout<<endl<<"yes, the word is present in the text";
    }    
}

void frequency(string str){
     map<string, int> M;
 
    // String for storing the words
    string word = "";
 
    for (int i = 0; i < str.size(); i++) {
 
        // Check if current character
        // is blank space then it
        // means we have got one word
        if (str[i] == ' ') {
 
            // If the current word
            // is not found then insert
            // current word with frequency 1
            if (M.find(word) == M.end()) {
                M.insert(make_pair(word, 1));
                word = "";
            }
 
            // update the frequency
            else {
                M[word]++;
                word = "";
            }
        }
 
        else
            word += str[i];
    }
 
    // Storing the last word of the string
    if (M.find(word) == M.end())
        M.insert(make_pair(word, 1));
 
    // Update the frequency
    else
        M[word]++;
 
    // Traverse the map
    // to print the  frequency
    for (auto& it : M) {
        cout << it.first << " - "
             << it.second
             << endl;
    }
}


void print_text(string s){
    system("cls"); 
    cout<<endl<<"_______________________________________________________"<<endl;
    cout<<"THE TEXT: "<<endl;
    cout<<s; 
}

void count_sentences(string s){
    system("CLS"); 
    cout<<endl<<"_______________________________________________________"<<endl;
    int i, index; 
    for(i=0; i<s.length(); i++){
        if(s[i]=='.'){
            index++; 
        }
    }
    cout<<endl<<"the number of sentences: "<<index;
}

void count(string s){
    cout<<endl<<"_______________________________________________________"<<endl;
    int i, index_words, index_paragraphs;
    index_words=0; 
    index_paragraphs=0;
    system("cls");
    cout<<endl<<"The number of characters: "<<s.length(); // no. of chars

    for(i=0; i<s.length(); i++){ // no. of words
        if(s[i]==' '){
            index_words++;
        }
    }
    cout<<endl<<"the number of words: "<<index_words+1;

    for(i=0; i<s.length(); i++){ // no. of paragraphs
        if(s[i]=='\n'){
            index_paragraphs++; 
        }
    }
    cout<<endl<<"the number of paragraphs: "<< index_paragraphs; 
}

void convert_into_comp(string s){
    cout<<endl<<"_______________________________________________________"<<endl;
    int i; 
    for(i=0; i<s.length(); i++){
        if(s[i]==' '){
            cout<<endl; 
            continue; 
        }
        cout<<s[i];
    }
}

int main(){
    int choice; 
    string str, response; 
    do{
    system("cls");
    cout<<"\t\t\t\t****************Practical-7****************"<<endl; 
    cout<<"\t\t 1. enter the string"<<endl; 
    cout<<"\t\t 2. search a word/pattern"<<endl; 
    cout<<"\t\t 3. convert into the components"<<endl; 
    cout<<"\t\t 4. find the frequency of each word"<<endl; 
    cout<<"\t\t 5. count the number of sentences"<<endl; 
    cout<<"\t\t 6. count the number of characters, words and paragraphs"<<endl;
    cout<<"\t\t 7. Print the entire text"<<endl; 
    cout<<"\t\t 8. Exit"; 
    cout<<endl<<"enter your choice: ";
    cin>>choice; 
    switch(choice){
        case 1: cout<<endl<<"enter the string: "; 
        cin.ignore(); 
        getline(cin, str); 
        break; 

        case 2: search(str); 
        break; 

        case 3: convert_into_comp(str); 
        break; 

        case 4: frequency(str); 
        break; 

        case 5: count_sentences(str); 
        break; 

        case 6:count(str); 
        break; 

        case 7: print_text(str); 
        break;

        case 8: exit(1);
        break;  

        default: cout<<endl<<"kindly choose a number corresponding to the above options";   
        }
    cout<<endl<<"do you wish to continue??"; 
    cout<<endl<<"your response: "; 
    cin>>response; 
    }
    while(response=="YES"||response=="yes"||response=="Yes"); 
    return 0; 
}