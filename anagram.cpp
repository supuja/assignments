 #include<iostream>
#include<fstream>
using namespace std;
int main()
{
string s1,s2;
int n1,n2,i,sum1=0,sum2=0;
cout<<"Enter first string\n";
std::getline(cin, s1);
cout<<"Enter second string\n";
std::getline(cin, s2);
n1=s1.length();
n2=s2.length();
for (i = n1-1; i >= 0; --i) {
   if(s1[i] == ' ')
  	s1.erase(i, 1);
}

for (i = n2-1; i >= 0; --i) {
   if(s2[i] == ' ')
  	s2.erase(i, 1);
}
n1=s1.length();
n2=s2.length();
if(n1==n2)
{
  for(i=0;i<n1;i++)
	sum1=sum1+s1[i];
  for(i=0;i<n2;i++)
	sum2=sum2+s2[i];
 if(sum1==sum2)
 {
   cout<<"Both words are anagrams\n";
 }
else
 {
	cout<<"Both words aren't anagrams\n";
 }
}
else
 {
    cout<<"Both words aren't anagrams\n";
 }
return 0;
}
