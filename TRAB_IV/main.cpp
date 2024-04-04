#include "library.hpp"
#include "account.hpp"


int main()
{
    
    Client c1("joao");
    Client c2("maria","engenheira",1100);

    Client *c3 = new Client("fernando", "professor", 1500);

    

   
    Account Acc2(&c1, 1000);
    Account Acc3(&c1, 2000);
    Account Acc4(&c2, 3000);
    Account Acc5(c3, 4000);

    Saccount Acc6(c3, 5000);
    Saccount Acc7(&c2, 7000);

     
     cout << Acc2.getInformation()<< endl;
     cout << Acc3.getInformation()<< endl;
     cout << Acc4.getInformation()<< endl;
     cout << Acc5.getInformation()<< endl;





  
    delete c3;
    return 0;
}