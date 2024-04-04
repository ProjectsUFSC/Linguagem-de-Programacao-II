#include "library.hpp"

int main()
{
    cout<<"- WELCOME TO THE CHYPER POO -"<<endl; 
    cout<<"Firstly write your student code to start -> ";
    size_t code;    cin>>code;       cout<<endl;
    Cypher ReferenceTable(code);
    
    size_t c=1;
    while(c!=0)
    {
        cout<<"------- CYPHER POO -------" <<endl;
        cout<<"Select an option: "<<endl;
        cout<<"1 -> Remake the cypher table"<<endl;
        cout<<"2 -> Encrypt Text."<<endl;
        cout<<"3 -> Decrypt Text."<<endl;
        cout<<"0 -> Exit"<<endl;
        cout<<"option selected -> ";
        cin >> c;       cout<<endl;
        
        
        switch (c)
        {

        case 0:
        {
            break;
        }    
        case 1:
        {
            size_t code= 0;
            cout << "Enter with the new student code -> ";
            cin>>code;      cout<<endl;
            ReferenceTable.RecreateTable(code);
            
           continue;
        }
        case 2:
        {
            string input;
            cout<<"Write the text you want encrypt: "<<endl;
            getline(cin>>ws, input);
            ReferenceTable.EncryptText(input);

            continue;
        }
        case 3:
        {
            string input;
            cout<<"Write the text you want decrypt: "<<endl;
            getline(cin>>ws, input);
            ReferenceTable.DecryptText(input);

            continue;
        }

        }
    }



    return 0;
}

