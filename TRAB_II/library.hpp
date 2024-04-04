#ifndef LIBRAY_HPP
#define LIBRAY_HPP

#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

class ConversionTable
{
public:

    vector< pair< char, char > > m_table;
    size_t m_StudentCode;


    ConversionTable();
    ConversionTable(size_t StudentCode);
    
    ~ConversionTable();
    

};

class Cypher
{
private:
    ConversionTable *m_BaseTable;
public:
    Cypher();
    Cypher(size_t StudentCode);
    
    ~Cypher();

    void RecreateTable(size_t StudentCode);
    void EncryptText(string input);
    void DecryptText(string input);
   

};

#endif