#include "library.hpp"

ConversionTable::ConversionTable()
{
}
ConversionTable::ConversionTable(size_t StudentCode)
{
    cout << "table created" << endl;
    vector< pair<char,char > > table;
    size_t parameter=0;
    size_t base = StudentCode;
    while(base > 0)
    {
        parameter += base%10;
        base /= 10;
    }
    for(size_t i=0; i<256; i++)
    {
        pair<char,char> p;
        p.first = i;
        p.second = p.first + (2*parameter);
        table.push_back(p);
    }
    m_table = table;
    m_StudentCode = StudentCode;  
}
ConversionTable::~ConversionTable()
{
    cout << "this table was destroyed"<< endl;
}

Cypher::Cypher()
{
    m_BaseTable = NULL;
}
Cypher::Cypher(size_t StudentCode)
{
    m_BaseTable = new ConversionTable(StudentCode);
}

Cypher::~Cypher()
{
    cout << "destructor called" << endl;
    delete m_BaseTable;
}
void Cypher::RecreateTable(size_t StudentCode)
{

    vector< pair<char,char > > table;
    size_t parameter=0;
    size_t base = StudentCode;
    while(base > 0)
    {
        parameter += base%10;
        base /= 10;
    }
    for(size_t i=0; i<256; i++)
    {
        pair<char,char> p;
        p.first = i;
        p.second = p.first + (2*parameter);
        table.push_back(p);
    }
    m_BaseTable->m_table = table;
    m_BaseTable->m_StudentCode = StudentCode;  
    
}
void Cypher::EncryptText(string input)
{
    string result;

    for(size_t i=0; i<input.length(); i++)
    {
        char chi = input.at(i);
        char cho = m_BaseTable->m_table.at(chi).second;  
        result += cho;
    }
   cout<<result<<endl;
}
void Cypher::DecryptText(string input)
{
    string result;

    for(size_t i=0; i<input.length(); i++)
    {
        char chi = input.at(i); 

        for(size_t j=0; j<m_BaseTable->m_table.size(); j++)
        {
            if(chi == m_BaseTable->m_table.at(j).second)
            {
                result += m_BaseTable->m_table.at(j).first;
                break;
            }
        }
    }
    cout<<result<<endl;
}
