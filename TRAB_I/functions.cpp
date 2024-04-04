#include "libray.hpp"

bool openfiles(string filename, vector<pair<string,vector<string> > > &fileList)
{
    ifstream filereader;
    filereader.open(filename);
    if(filereader.is_open())
    {
        pair<string,vector<string> > tmp;
        tmp.first = filename;
        string word;
        while(getline(filereader , word))
        {
           tmp.second.push_back(word);
            cout << word << endl; 
        }
        filereader.close();
        fileList.push_back(tmp);
        return true;
    }
    else 
    {
        return false; 
    } 
}
bool searchsubstring (const vector<pair<string,vector<string> > > &fileList)
{
    bool search = false;
    cout << "Enter the substring to search: ";
    string subword;
    cin >> subword;
    cout << endl;
    for(size_t i=0 ;i<fileList.size();i++)
    {
        for(size_t j=0; j<fileList.at(i).second.size(); j++)
        {
            if(fileList.at(i).second.at(j).find(subword)!= string::npos)
            {
                cout << "Substring has found: file--> " << fileList.at(i).first << " string--> " << fileList.at(i).second.at(j)<< endl;
                search = true; 
            }
        }
                
    }
    return search;
}
bool removesubtrings (vector<pair<string,vector<string> > > &fileList)
{
    bool firstremove = false;
        cout << "Enter the substring to remove: ";
        string subword;
        cin >> subword;
        cout << endl;
        for(size_t i=0 ;i<fileList.size();i++)
        {
            for(size_t j=0; j<fileList.at(i).second.size(); j++)
            {
                if(fileList.at(i).second.at(j).find(subword)!= string::npos)
                {
                    cout << "Substring has found and remove: file--> " << fileList.at(i).first << " string--> " << fileList.at(i).second.at(j)<< endl;
                    fileList.at(i).second.erase(fileList.at(i).second.begin()+j); 
                    j--;      
                    firstremove = true; 
                }
            }
                    
        }
        return firstremove;
}
bool removerepeated (vector<pair<string,vector<string> > > &fileList)
{
    bool firstremove = false;
    for(size_t i=0; i< fileList.size(); i++)
            {
                for(size_t j=0;j<fileList.at(i).second.size();j++)
                {
                    string word = fileList.at(i).second.at(j);
                    for(size_t it = i; it<fileList.size();it++)
                    {
                        for(size_t jt=0;jt<fileList.at(it).second.size();jt++)
                        {
                            if(fileList.at(it).second.at(jt).find(word)!=string::npos && (it != i || jt != j))
                            {
                                cout << "String duplicated removed : file--> " << fileList.at(it).first << " string--> " << fileList.at(it).second.at(jt)<< endl;
                                fileList.at(it).second.erase(fileList.at(it).second.begin()+jt);
                                jt--;
                                firstremove = true;
                            }
                        }
                    }
                    
                }
            }
    
    return firstremove;

}

void stats (const vector<pair<string,vector<string> > > &fileList)
{
    for(size_t i=0; i<fileList.size(); i++)
    {
        cout<< "the file --> " << fileList.at(i).first << " has " << fileList.at(i).second.size()<< " words "<< endl;
    }

}

bool save ( vector<pair<string,vector<string> > > &fileList)
{
    ofstream filewriter("concatenation.txt");
    if(filewriter.is_open())
    {
        for(size_t i=0; i<fileList.size(); i++)
        {
            filewriter << "FILE --> "<< fileList.at(i).first << endl << endl;
            for(size_t j=0; j<fileList.at(i).second.size(); j++)
            {
                filewriter << j <<" --> "<< fileList.at(i).second.at(j) << endl << endl;
            }

        }
        filewriter.close();
    }
    else
    { 
        cout << "ERROR, CANNOT SAVE THE DATA FILE"<< endl;
        return false;
    }
    return true;
}
