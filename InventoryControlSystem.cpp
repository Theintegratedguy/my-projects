#include<iostream>
#include<iomanip>
#include<windows.h>
#include<string>
#include<fstream>
using namespace std; 

struct part{
    string company_id; 
    string part_id; 
    string name; 
    int mfg[3];
    int exp[3]; 
}; 

class node {
    public: 
    node* prev; 
    part data; 
    node* next; 

    node(part val){
        data=val; 
        prev=NULL; 
        next=NULL; 
    };
}; 

void company_id_as_primary_key(node* &head, string id){
    node* temp=head; 
    while(temp!=NULL){
        if(id==temp->data.company_id){
            cout<<endl<<"this company id already exists. please enter another company id."; 
            cout<<endl<< "enter the company id:"; 
            cin>>temp->data.company_id;
            company_id_as_primary_key(head, id); }
        else temp=temp->next;
    }
}

void part_id_as_primary_key(node* &head, string id){
    node* temp=head; 
    while(temp!=NULL){
        if(id==temp->data.part_id){
            cout<<endl<<"this part id already exists. please enter another part id.";
            cout<<endl<<"enter the part id:"; 
            cin>>temp->data.part_id;  
            part_id_as_primary_key(head, id); }
        else temp=temp->next; 
    }
}

void insert_at_head(node* &head, part val){
    node* n=new node(val); 
    n->next=head; 
    if(head!=NULL){
        head->prev=n;}
    head=n;
}

void insert_at_tail(node* &head, part val){ // function to insert the collected information
    if(head==NULL){
        insert_at_head(head, val); 
        return; }
    node* n=new node(val);
    node* temp=head; 
    while(temp->next!=NULL){
        temp=temp->next; 
    }
    temp->next=n; 
    n->prev=temp; 
}

void getdata(node* &head){ // a function to get the information
    part data; 
    system("CLS"); 
    cout<<"*************ADDING THE DATA TO THE DATABASE**********";
    cout<<endl<<"enter the company ID: ";
    cin>>data.company_id; 
    company_id_as_primary_key(head, data.company_id); 
    cout<<endl<<"enter the part_id: ";
    cin>>data.part_id; 
    part_id_as_primary_key(head, data.part_id);
    cout<<endl<<"enter the name: "; 
    cin.ignore();
    getline(cin, data.name); 
    cout<<endl<<"enter the date of manufacturing:- "; 
    cout<<endl<<"enter the date:"; 
    cin>>data.mfg[0]; 
    cout<<endl<<"enter the month:"; 
    cin>>data.mfg[1]; 
    cout<<endl<<"enter the year"; 
    cin>>data.mfg[2]; 
    cout<<endl<<"enter the date of expiry:-"; 
    cout<<endl<<"enter the date:"; 
    cin>> data.exp[0]; 
    cout<<endl<<"enter the month:";
    cin>>data.exp[1]; 
    cout<<endl<<"enter the year:";
    cin>>data.exp[2]; 
    ofstream myfile("pracitcal3_backup.txt", ios::app);
    myfile<<endl<<"-------------------------------";
    myfile<<endl<<"Company ID: "<<data.company_id;
    myfile<<endl<<"Part ID: "<<data.part_id; 
    myfile<<endl<<"Name: "<<data.name; 
    myfile<<endl<<"date of manufacturing: "<<data.mfg[0]<<"-"<<data.mfg[1]<<"-"<<data.mfg[2];
    myfile<<endl<<"date of expiry:"<<data.exp[0]<<"-"<<data.exp[1]<<"-"<<data.exp[2];
    myfile.close();
    insert_at_tail(head, data); // a function call
}


void display(node* head){
    system("CLS");  
    cout<<"\t\t\t**********DISPLAY THE INFORMATION***************";
    node* temp=head; 
    while(temp!=NULL){
        cout<<endl<<"---------------------------------------------"; 
        cout<<endl<<"Company ID: "<<temp->data.company_id;
        cout<<endl<<"Part ID: "<<temp->data.part_id; 
        cout<<endl<<"Name: "<<temp->data.name; 
        cout<<endl<<"date of manufacturing: "<<temp->data.mfg[0]<<"-"<<temp->data.mfg[1]<<"-"<<temp->data.mfg[2];
        cout<<endl<<"date of expiry:"<<temp->data.exp[0]<<"-"<<temp->data.exp[1]<<"-"<<temp->data.exp[2];
        temp=temp->next;
    }
}

void count_the_no_of_elements(node* &head){
    system("CLS");
    int count=0;
    node* temp=head; 
    cout<<"\t\t\t\t************COUNT THE NUMBER OF ELEMENTS************";
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    cout<<endl<<"the total number of elements we have:"<<count; 
}

void delete_at_head(node* &head){
    node* todelete=head;
    head= head->next; 
    head->prev=NULL; 

    delete todelete;
    cout<<endl<<"congratulations, you have successfully deleted the record"; 
    return; 
}

void delete_the_record(node* &head){
    string val;  
    system("CLS"); 
    node* temp=head;
    cout<<endl<<"\t\t\t****************RECORD DELETION PAGE**************"; 
    cout<<endl<<"enter the company id of the part, which you want to delete:"; 
    cin>>val; 
    if(head->data.company_id==val){
        delete_at_head(head);
        return;
    }
    
    while(temp!=NULL && temp->data.company_id!= val){
        temp=temp->next;  }
    temp->prev->next= temp->next;
    if(temp->next!=NULL){
    temp->next= temp->prev;}
    
    delete temp; 
    cout<<endl<<"congratulations, you have successfully deleted the record"; 
    return; 
}
void generate_a_report(node* &head){
    int choice, i=0, date[3];
    string name; 
    node* temp=head; 
    system("CLS"); 
    cout<<endl<<"\t\t\t****************GENERATE A REPORT******************"; 
    cout<<endl<<"\t\t\t choose one of the following operations to generate a report"; 
    cout<<endl<<"\t\t 1. report based on the name"; 
    cout<<endl<<"\t\t 2. report based on the date of manufacturing"; 
    cout<<endl<<"\t\t 3. report based on the date of expiry"; 
    cout<<endl<<endl<<"enter your choice:"; 
    cin>>choice; 
    switch(choice){
        case 1: 
        cout<<endl<<"------------------------------------";
        cout<<endl<<"enter the name:"; 
        cin.ignore(); 
        getline(cin, name); 
        while(temp!=NULL){ 
            if(temp->data.name== name){
                cout<<endl<<"name:"<<temp->data.name;
                cout<<endl<<"company id:"<<temp->data.company_id;
                cout<<endl<<"-----------------------------------";}
            
            temp=temp->next;}
            break;
        
        case 2: 
        cout<<endl<<"---------------------------------"; 
        cout<<endl<<"enter the date:"; 
        cout<<endl<<"date:"; 
        cin>>date[0];
        cout<<endl<<"month:"; 
        cin>>date[1]; 
        cout<<endl<<"year:";
        cin>>date[2];
        while(temp!=NULL){
            if(temp->data.mfg[0]==date[0] && temp->data.mfg[1]==date[1] && temp->data.mfg[2]==date[2]){
                cout<<endl<<"the part(s) which were manufactured on this date are:"; 
                cout<<endl<<"name:"<<temp->data.name; 
                cout<<endl<<"company id:"<<temp->data.company_id;
                cout<<endl<<"-----------------------------------------------------";
            }
            else {cout<<endl<<"sorry, we do not have any product with this date of manufacturing.";}
        break; 
        
        case 3: 
        cout<<endl<<"---------------------------------"; 
        cout<<endl<<"enter the date:"; 
        cout<<endl<<"date:"; 
        cin>>date[0];
        cout<<endl<<"month:"; 
        cin>>date[1]; 
        cout<<endl<<"year:";
        cin>>date[2];
        while(temp!=NULL){
            if(temp->data.exp[2]<date[2]){
                cout<<endl<<"name:"<<temp->data.name; 
                cout<<endl<<"company id:"<<temp->data.company_id;
                cout<<endl<<"--------------------------------------";}
            else if(temp->data.exp[2]==date[2] && temp->data.exp[1]<date[1]){
                cout<<endl<<"name:"<<temp->data.name; 
                cout<<endl<<"company id:"<<temp->data.company_id; 
                cout<<endl<<"--------------------------------------";}
            else if(temp->data.exp[2]==date[2] && temp->data.exp[1]==date[1] && temp->data.exp[0]<date[0]){
                cout<<endl<<"name:"<<temp->data.name; 
                cout<<endl<<"company id:"<<temp->data.company_id; 
                cout<<endl<<"--------------------------------------";}
            else {cout<<endl<<"there are no parts in the inventory, which are expired"; }
            temp=temp->next; }
            break;
        
        default: cout<<endl<<"choose an option from the above mentioned ones!!"; 
          }
        }
}

void retreive(){
    
}

int main() {
    node* head= NULL; 
    int choice; string response; 
    // the interface/screen: 
    do{
    cout<<endl<<"\t\t\t\t*******************INVENTORY CONTROL PROGRAM**********************";
    cout<<endl<<"\t\t please choose an operation from the list below: "; 
    cout<<endl<<"\t\t\t 1. Add a part to the record"; 
    cout<<endl<<"\t\t\t 2. Delete a part from the record"; 
    cout<<endl<<"\t\t\t 3. count the total number of elements"; 
    cout<<endl<<"\t\t\t 4. generate a report";
    cout<<endl<<"\t\t\t 5. display all the records";
    cout<<endl<<"\t\t\t 6. exit";
    cout<<endl<<"Enter your choice: ";
    cin>>choice; 
    switch(choice){
        case 1: getdata(head); break;
        case 2: delete_the_record(head); break;
        case 3: count_the_no_of_elements(head); break;
        case 4: generate_a_report(head); break;
        case 5: display(head); break; 
        case 6: exit(1);break;
        default: cout<<endl<<"kindly enter a valid number to indicate your choice!!"; 
    } 
    cout<<endl<<"do you want to continue??";
    cin>>response;
   }
  while (response=="yes"||"YES"||"Yes");
}
