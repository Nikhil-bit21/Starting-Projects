#include<iostream>
#include<math.h>
#include <string>
#include <vector>
#include <algorithm>
#include<map>
using namespace std;

class Trienode{
public:

    bool isterminal = false;
    Trienode* Children[26] = {};
    //vector<string> Contacts;
    map<string , string> Contacts;
};

class Trie{
private:
    Trienode* root;

public:
    Trie(){
        root = new Trienode();
    }

    void Insert(const string& word , const string& contact , const string& phnNo){
        Trienode* curr = root;

        for(char c : word){
            int index = c - 'a';
            if(!curr->Children[index]){
                curr->Children[index] = new Trienode();
            }
            curr = curr->Children[index];
        }
        curr->isterminal = true;
        //curr->Contacts.push_back(contact);
        curr->Contacts[phnNo] = contact;
    }

    vector<pair <string, string> > Search(const string& str){
        Trienode* curr = root;
        for(char c : str){
            int index = c - 'a';
            if(!curr->Children[index]){
                return vector<pair <string, string> >();
            }
            curr = curr->Children[index];
        }

        vector<pair <string,string> > contacts;
        for(const auto& [phone,name]:curr->Contacts){
            //contacts.push_back({name,phone});
            contacts.push_back(make_pair(name, phone));
        }
        return contacts;
    }

    bool Remove(const string& str , const pair<string, string>& contact){
        Trienode* curr = root;
        for(char c: str){
            int index = c-'a';
            if(!curr->Children[index]){
                return false;
            }
            curr = curr->Children[index];
        }
        // auto it = find(curr->Contacts.begin(),curr->Contacts.end() , contact);
        auto it = curr->Contacts.find(contact.second);
        if(it != curr->Contacts.end() && it->second == contact.first){
            curr->Contacts.erase(it);
            return true;
        }
        return false;
    }
};

int main(){

    Trie trie;
    cout<<endl;
    cout<<"Welcome to Gojo's Contact app! *.*";

    while(true){
        cout<<"Enter Option according to what to want to do. *.*"<<endl;
        cout<<"Enter 1 : To Add Contact"<<endl;
        cout<<"Enter 2 : To Search Contact"<<endl;
        cout<<"Enter 3 : To Delete Contact"<<endl;
        cout<<"Enter 4 : To Exit"<<endl;
        
        int option;
        cin>>option;
        cin.ignore();

        if(option == 1){
            cout<<endl;
            cout<<"Enter Name of the Contact :"<<endl;
            string name;
            getline(cin , name);

            cout<<endl;
            cout<<"Enter Phone Number of Contact"<<endl;
            string PhnNo;
            getline(cin , PhnNo);

            for(int i=1;i<=name.length();i++){
                string word = name.substr(0,i);
                // trie.Insert(word,name);
                trie.Insert(word,name,PhnNo);
            }
            cout<<endl;
            cout<<"Contact added successfully. *.*"<<endl;
        }else if(option == 2){
            cout<<endl;
            cout<<"Enter Word You want to Search :"<<endl;
            string word ;
            getline(cin , word);
            vector<pair <string,string> > collection = trie.Search(word);
            
            if(collection.empty()){
                cout<<endl;
                cout<<"No Contacts found. *.*"<<endl;
            }else{
                cout<<endl;
                cout<<"Contacts with given word are :"<<endl;
                cout<<endl;
                for(const auto& c : collection){
                    cout<<c.first<<"|"<<c.second<<endl;
                }
                cout<<endl;
            }
        }else if(option == 3){
            cout<<endl;
            cout<<"Enter Word You want to Search for Deleting:"<<endl;
            string word ;
            getline(cin , word);
            vector<pair <string,string> > collection = trie.Search(word);
            
            if(collection.empty()){
                cout<<endl;
                cout<<"No Contacts found. *.*"<<endl;
            }else{
                cout<<endl;
                cout<<"Contacts with given word are :"<<endl;
                cout<<endl;
                for(int i=0;i<collection.size();i++){
                    cout<<i+1<<". "<<collection[i].first<<"|"<<collection[i].second<<endl;
            }
            cout<<endl;
            cout<<"Enter Contact Number Which you want to Delete :"<<endl;
            int num;
            cin>>num;
            cin.ignore();

            if(num>=1 && num <=collection.size()){
                pair<string,string> remove= collection[num-1];
                bool flag = trie.Remove(word,remove);

                if(flag){
                    cout<<endl;
                    cout<<"Contact deleted successfully. *.*"<<endl;
                }else{
                    cout<<endl;
                    cout << "Failed to delete contact. *.*"<<endl;
                }
            }else{
                cout<<endl;
                cout<<"Invalid contact number. *.*"<<endl;
            }
        }
    }else if(option == 4){
        break;
    }else{
        cout<<endl;
        cout<<"Invalid Option! this feature is not available right now. *.*"<<endl;
        break;
    }
}
    
    return 0;
}