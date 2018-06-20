#include <iostream>
#include <string>
using namespace std;

class Person {
private:
  int Year[100];
  int count;
  string FirstName[100];
  string LastName[100];

public:  
Person(){
	count=0;
	for(int i=0;i<100;i++){
		Year[i]=0;
		FirstName[i]="Incognito";
		LastName[i]="Incognito";
		}
	}
  // добавить факт изменения имени на first_name в год year
  void ChangeFirstName(int year,string first_name) {
	  int n=1;
	  for(int i=0;i<100;i++){
		  if(Year[i]==year){
			  FirstName[i]=first_name;
			  n=0;
			  break;
			  }
		  }		
	  if(n){
		  Year[count]=year;
		  FirstName[count]=first_name;
	      count++;
		  }  
  }
  // добавить факт изменения фамилии на last_name в год year
  void ChangeLastName(int year,string last_name) {
	  int n=1;
	  for(int i=0;i<100;i++){
		  if(Year[i]==year){
			  LastName[i]=last_name;
			  n=0;
			  break;
			  }
		  }		
	  if(n){
		  Year[count]=year;
		  LastName[count]=last_name;
	      count++;
		  }
  }
  //отсортировать массивы года и имя с фамилией по году
  void sort(){
	  int m=0,c,flag=0;
	  string A;
	  while(Year[m]!=0)
		  m++;
	  for(int j=0;j<m-1;j++){
		  flag=1;
		  for(int i=0;i<m-1;i++){
			  if(Year[i]>Year[i+1]){
				  c=Year[i];
				  Year[i]=Year[i+1];
				  Year[i+1]=c;
				  A=LastName[i];
				  LastName[i]=LastName[i+1];
				  LastName[i+1]=A;
				  A=FirstName[i];
				  FirstName[i]=FirstName[i+1];
				  FirstName[i+1]=A;
				  flag=0;
				  }
			  }
		   if(flag==1) break;
		  }		  
	  for(int j,i=0;i<m;i++){
		  if(FirstName[i]!="Incognito"){
			  j=i+1;
			  while(FirstName[j]=="Incognito"&&j<m){
				  FirstName[j]=FirstName[i];
				  j++;
				  }
			  }
		   if(LastName[i]!="Incognito"){
			  j=i+1;
			  while(LastName[j]=="Incognito"&&j<m){
				  LastName[j]=LastName[i];
				  j++;
				  }
			  }  
		  }
	}  
    
  // получить имя и фамилию по состоянию на конец года year
  string GetFullName(int year) {
	   string A=" with unknown first_name";
	   string B=" with unknown last_name";
	   string C="Incognito";
	   sort();
	   string H;
	   int m=0,n=1;
	   while(Year[m]!=0){
		   m++;
		   }
	   for(int i=0;i<m;i++){
		   if(Year[i]==year&&LastName[i]!="Incognito"&&FirstName[i]!="Incognito"){
			   return FirstName[i]+LastName[i];
			   n=0;
			   }  
		   if(Year[i]==year&&LastName[i]!="Incognito"&&FirstName[i]=="Incognito"){
			   return LastName[i]+A;
			   n=0;
			   }  
		   if(Year[i]==year&&LastName[i]=="Incognito"&&FirstName[i]!="Incognito"){
			   return FirstName[i]+B;
			   n=0;
			   }  	  
		   }
	   if(n){
		   if(Year[0]>year) return C;
		   for(int i=0;i<m;i++){
			    if(Year[i]<year){
					if(LastName[i]!="Incognito"&&FirstName[i]!="Incognito"){
						H=FirstName[i]+LastName[i];
						}  
					if(LastName[i]!="Incognito"&&FirstName[i]=="Incognito"){
						H=LastName[i]+A;
						}  
					if(LastName[i]=="Incognito"&&FirstName[i]!="Incognito"){
						H=FirstName[i]+B;
						}  	 
					}		 
				}
		   return H;
		   }
	   }

};

int main(){
	Person person;
	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1964}) {
		cout << person.GetFullName(year) << endl;
	}
  
	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1970}) {
		cout << person.GetFullName(year) << endl;
	}
  
	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}
	
	return 0;
	}


 
  
