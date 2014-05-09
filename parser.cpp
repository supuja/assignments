#include<cstdlib>
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class hash {
private:
static const int tablesize=40;
struct counter{
int count;
counter* next1;
};         

struct item{
string name;
struct counter;
item* next;
};
item* HashTable[tablesize];
public:
hash();
int Hash(string key);
void AddItem(string name);
int NumberOfItemsInIndex(int index);
void PrintTable();
void PrintItemsInIndex(int index);
void Find(string name);
};

hash::hash(){
for(int i=0;i<tablesize;i++){
HashTable[i]=new item;
HashTable[i]->name="empty";
HashTable[i]->next=NULL;

}
}

void hash::AddItem(string name,int position){
int index=Hash(name);
if(HashTable[index]->name=="empty"){
HashTable[index]->name=name;
counter* v;
item* n=new item;
n->v->count=position;
n->v->next=NULL;

}
else {
counter* v;
item* Ptr=HashTable[index];
item* n=new item;
n->name=name;
n->v->count=position;
n->next=NULL;
n->v->next=NULL;
while(Ptr->next!=NULL){
Ptr=Ptr->next;
}
Ptr->next=n;
}
}

int hash::NumberOfItemsInIndex(int index){
int count=0;
if(HashTable[index]->name=="empty"){
return count;
}
else {
count++;
item* Ptr=HashTable[index];
while(Ptr->next!=NULL){
count++;
Ptr=Ptr->next;
}

}
return count;
}

void hash::PrintTable(){
int number;
for(int i=0;i<tablesize;i++){
number=NumberOfItemsInIndex(i);
cout<<"----------------\n";
cout<<"index="<<i<<endl;
cout<<HashTable[i]->name<<endl;
cout<<"no of items="<<number<<endl;
cout<<"----------------\n";
}
}
void hash::PrintItemsInIndex(int index){
item* Ptr=HashTable[index];
if(Ptr->name=="empty"){
cout<<"index="<<index<<"is empty";
}
else {
cout<<"index"<<index<<"contains the following items\n";
while(Ptr!=NULL){
cout<<"------------\n";
cout<<Ptr->name<<endl;
cout<<"------------\n";
Ptr=Ptr->next;

}
}

}
int hash::Hash(string key)
{
int hash=0;
int index;
//index=key.length();
for(int i=0;i<key.length();i++){
hash=(hash+(int)key[i])*17;//modify the program
}

index=hash%tablesize;
return index;
}
void hash::Find(string name){
int index=Hash(name); //where it is in table
bool foundName=false;
string Name;

item* Ptr=HashTable[index];
while(Ptr!=NULL){
if(Ptr->name==name){
foundName=true;
Name=Ptr->name;


}
Ptr=Ptr->next;
}
if(foundName==true){
cout<<Name<<"is located in index number"<<index<<"in the table"<<endl;
}
else {cout<<Name<<"not found\n";}
}

int main() {

hash Hashy;
string name="";
int lines=1,lines1=1,c=1;
ifstream myfilei;
myfilei.open ("2.txt");
if (myfilei.is_open()) {
while (!myfilei.eof())  
    {   c++;
        getline(myfilei, name); 
        Hashy.AddItem(name,c);

        lines1++;  
     }
}
//Hashy.AddItem("kruthika");
//Hashy.AddItem("pooja");
//Hashy.AddItem("priyanka");
//Hashy.PrintTable();
//Hashy.PrintItemsInIndex(35);


/*ifstream myfileo;
myfileo.open ("1.txt");
if (myfileo.is_open()) {
while (!myfileo.eof())  
    {
        getline(myfileo, name); 
       
//cout<<"search for";
//cin>>name;
Hashy.Find(name);

        lines++;  
     }
}*/
return 0;
}

