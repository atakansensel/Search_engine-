/* LOOP ADDED ONLY*/ 


#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "LinkedList.h"

using namespace std;



int main(){
	ifstream file;
	LinkedList<string>list1;
	int doc;
	string word;
	string line;


	file.open("docdb3.txt"); 

	while(getline(file,line))// read file lines 
	{
	
		istringstream data(line);
		data >> word;
		data >> doc;
		list1.AddString(word,doc);

		}
	file.close();

	
	int num_search;
	
	string search;


	while(cin>>num_search) 
	{ 
	bool flag = true;

	if(!(num_search == 0)){
	string *arr=new string[num_search];
	vector<int> arr2;

	for(int i = 0; i<num_search;i++)
	{
		cin >> search;
		arr[i]=search;

		if(flag && list1.IsElementExist(search))
		{
			
			arr2 = list1.intersection(arr2,i,search);


		}
		else 
		{

		  flag = false;
		
		}


	
	}

	  
  for (int i =0;i<num_search;i++)
  {
			cout<<arr[i]<<" " ;
			
	
  }

  if(!flag)
  {
    cout << " 0";
  }
  else
  {
	  cout << arr2.size() << " ";
			for(int k= 0; k< arr2.size();k++){
			cout << arr2[k]<<" ";
			}
  
  }
		 

	}
	else {
		break;
	}
	}
    cin.ignore();
	cin.get();

return 0;
}