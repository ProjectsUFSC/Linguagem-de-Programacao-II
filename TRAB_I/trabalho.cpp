#include "libray.hpp"

int main()
{
    vector<pair<string,vector<string> > > fileList;
    int c=0; 
    while(c!=6)
    {
        cout << "---------------------------------------"<< endl;
        cout << "FILE MANIPULATOR HACK "<< endl << endl;
        cout << "Select an option:"<< endl;
        cout << "1. OPEN A FILE..."<< endl;
        cout << "2. SEARCH FOR SUBSTRING..."<< endl;
        cout << "3. REMOVE WORDS CONTAINING A SUBSTRINGS"<< endl;
        cout << "4. REMOVE ALL REPEATED WORDS"<< endl;
        cout << "5. SHOW STATISTICS"<< endl;
        cout << "6. EXIT "<< endl;
        cout << "---------------------------------------"<< endl;
        cout << endl << "Option seltected: "<< endl;

        cin>>c;

        switch (c)
        {
            case 1:
            {            
                string file;
                cout << "Enter with a file to open: " ; 
                cin >> file;
                cout << endl;
               if(openfiles(file, fileList)==false)
               {
                    cout << "ERROR, CANNOT OPEN YOUR FILE"<< endl;
               } 

                continue;
            }

            case 2:
            {        
                if(searchsubstring(fileList)==false)
                {
                    cout << "Subword not found, try again with other subword "<< endl;
                }

                continue;
            
            }
               
            case 3:
            {
                if(removesubtrings(fileList)==false)
                {
                    cout << "Subword not found, try again with other subword "<< endl;
                }

                continue;
            }

            case 4:
            {           
               if(removerepeated(fileList)== false)
               {
                cout<< "Not found repeated words"<< endl;
               }
                continue;
            }

            case 5:
            {
                stats(fileList);
                continue;
            }

            case 6:
            {
                save(fileList);
                break; 
            }      
        }
    }
    return 0;
}
