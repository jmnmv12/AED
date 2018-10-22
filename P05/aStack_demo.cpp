//
// Tomás Oliveira e Silva, AED, October 2014, September 2015
//
// matched-parenthesis verification
//

#include <iostream>
#include "aStack.h"
#include <string.h>


using std::cout; //namespace, vai so buscar o cout
using std::cerr;
using std::endl;

int check_parenthesis(const char *s)// string termina em /0, const nao vai funcionar, nao pode alterado
{
  aStack<int> pilha(10+(int)strlen(s));// a stack tem que ser no minimo 10
  for(int i=0;i<(int)strlen(s);i++){
    //cout << s[i]<< endl;
    if(s[i]=='('){
      pilha.push(i);
    }else if (s[i]==')'){
      if(pilha.is_empty()){
        cout<<"unmatched at position "<< i<< endl;
        return -1;
      }  
        // so verificamos se e empty pq se nao estiver empty vai ter la um '(', pq so guarda '('
      cout<<"'(' at position "<< pilha.pop() <<" and ')' at position "<< i <<endl; //pop retorna posição e retira da piha
      
    }
  }
   if(!pilha.is_empty())
    cout << "unmatched at position " << pilha.top() << endl;  
  return !pilha.is_empty();// temos que retornar ao contrario pq retorna 1 quando esta empty
}

int main(int argc,char **argv)
{
  if(argc == 1)
  {
    cerr << "usage: " << argv[0] << " [arguments...]" << endl;
    cerr << "example: " << argv[0] << " 'abc(def)ghi' 'x)(y'" << endl;
    return 1;
  }
  for(int i = 1;i < argc;i++)
  {
    cout << argv[i] << endl;
    if(check_parenthesis(argv[i]) == 0)
      cout << "  good" << endl;
    else
      cout << "  bad" << endl;// Se retorna -1 show bad
  }
  return 0;
}
