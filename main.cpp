#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

void setColor(int color){
 cout << "\033[" << color << "m";
}

 struct Contact
 {
    string name;
    string phone;
    string email;
 };

 void saveContacts(vector<Contact>&contacts){
  ofstream file("contacts.txt");
    for(const auto& Contact : contacts){
        file<<Contact.name<<" "<<Contact.phone<<" "<<Contact.email<<endl;
    }
    file.close();
  cout<<"Contacts saved to file successfully!\n";
  }

  void loadContacts(vector<Contact>&contacts){
  ifstream file("contacts.txt");
  Contact contact;
    while(file>>contact.name>>contact.phone>>contact.email){
        contacts.push_back(contact);
    }
    file.close();
  }
 
 

int main(){
    vector<Contact>contacts;
     loadContacts(contacts);

    int choice;
    do{
    cout<<"\n1. Add Contact \n2. View Contact\n3. Edit Contact\n4. Delete Contact\n5. Save & Exit"<<endl;
    cout<<"Enter Your Choice: ";
    cin>>choice;

         if(choice==1){
           Contact newContact;
           cout<<"Enter Name: ";
           cin.ignore();
           getline(cin , newContact.name);
           cout<<"Enter PhoneNo: ";
           getline(cin, newContact.phone);
           cout<<"Enter Email: ";
           getline(cin, newContact.email);
           contacts.push_back(newContact);
           cout<<"Contact added Successfully!\n";
         }

         else if(choice==2){
            cout<<"\nContacts:\n";
            for(const auto& Contact : contacts){
                 cout << "Name: " << Contact.name << ", Phone: " << Contact.phone << ", Email: " << Contact.email << endl;
            }
         }

         else if(choice==3){
             string name;
             cout<<"Enter the name of the contact to edit: ";
             cin>> name;
             bool found= false;
             for(auto& Contact : contacts){
                if(Contact.name==name){
                    cout<<"Enter new phone: ";
                    cin>>Contact.phone;
                    cout<<"Enter new Email: ";
                    cin>>Contact.email;
                    cout<<"Contact updated successfully!\n";
                    found =true;
                    break;
                }
             }
             cout<<"Contact not Found!\n";
         }

         else if(choice==4){
            string name;
            cout<<"Enter the name of the contact you want to delete: ";
            cin>>name;
            bool deleted=false;
            for(auto i=contacts.begin(); i!=contacts.end(); i++){
                  if(i->name==name){
                    contacts.erase(i);
                    deleted=true;
                    break;
                  }
            }
            if(!deleted){
            cout<<"Contact not found!\n";
            }
         }

         else if(choice==5){
            saveContacts(contacts);
            cout<<"Contact saved. Exiting...\n";
         }
         else{
            cout<<"Invalid choice. Please try again.\n";
         }
    }while (choice!=5);
    
   
  
}