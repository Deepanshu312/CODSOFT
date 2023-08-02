      // ***WORD COUNT***
/* Develop a program that counts the number of words in a given
text file. Prompt the user to enter the file name and display the
total word count. */

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
 ifstream fin("fname.txt"); //opening text file
 int word=1; //will not count first word so initial value is 1
 char ch;
 fin.seekg(0,ios::beg); //bring position of file pointer to beginning of file
 
 while(fin)
 {
  fin.get(ch);
  if(ch==' '||ch=='\n')
   word++;
 } 
 
 cout<<"\nWords="<<word<<"\n";
 fin.close(); //closing file
 
 return 0;
}