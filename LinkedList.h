#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<string>
#include <vector>

using namespace std;

struct node
{
	int num;
	node *next;

}; 



template<class Obj>
class LinkedList{



private:
	Obj obj;
	node num;

	LinkedList *next;


public:
	LinkedList();
	void AddString(Obj a,int num1);
	bool IsElementExist(Obj word2);
	vector<int> intersection(vector<int> q,int i,Obj str);
};


template<class Obj>
LinkedList<Obj>::LinkedList()
{   
	next=NULL;
	num.next=NULL;
}

template<class Obj>
void LinkedList<Obj>::AddString(Obj a,int num1)
{



	if(!IsElementExist(a))// the element isnt in the linked list 
	{

	LinkedList * n = new LinkedList;
	n->num.num=num1;
	n->num.next = nullptr;
	n->obj=a;
	n->next = nullptr;

	LinkedList * ptr = this;

	if (this->next == nullptr)// linked list is empty
	{
		this->next = n;
	}
	else
	{   
		bool check = true;
		
		while(ptr->next != nullptr && check)
		{   

			if( ptr->next != nullptr && a>= ptr->obj && a<=ptr->next->obj)
			{   
				n->next = ptr->next;
				ptr->next = n;
				check = false;
			}
			if (a < ptr->obj)// smaller than first element 
			{
				LinkedList * temp;
				temp = ptr;
				n->next = ptr ;
				ptr = n;
				check = false;
			}
			
			ptr = ptr->next;
			

		
		}
		if(check){
			ptr->next = n;
		}

}

	}

	else
	{
		node *n = new node;
		n->num = num1;
		n->next=nullptr;

		LinkedList * ptr = this;
		
		while (ptr->obj != a)
		{
			ptr = ptr->next;
		}
		
		

		bool check2 = true;
		node *n2 = &ptr->num;

		if(n2==nullptr)
		{
		   n2=n;
		}

		else{

			while(check2 &&  n2 != nullptr)
		{

			if(n2->num == num1) // if the number exist 
			{
				check2=false;
			}

			if(check2 && n2->next != nullptr &&num1>n2->num && num1<n2->next->num)
			{
				n->next = n2->next;
				n2->next = n;
				check2= false;
			}

			if(num1 < n2->num)
			{ 
				
			   n->next = n2->next;
				n2->next = n;
				int temp;
				 temp = n2->num;
				 n2->num = n2->next->num;
				 n2->next->num = temp;
				
					
			 
				
				check2 = false; 
		    }

			if(check2 && num1>n2->num && n2->next == nullptr)
			{
				n2->next=n;
				check2=false;
			}



			if(check2){
			
				n2 = n2->next;
				

		}
		}
	}
	}
}
template<class Obj>
bool LinkedList<Obj>::IsElementExist(Obj word2)// checks the element
	{
		LinkedList *ptr = this ;
		while(ptr->next != nullptr)
		{
			if(ptr->next->obj==word2)
			{
				return true;
			}		
			ptr = ptr->next;
		}

		return false;
	}

template<class Obj>
vector<int>  LinkedList<Obj>::intersection(vector<int> q,int i,Obj str)// returns element of search words document in vector  
{
	vector<int> c;


	LinkedList *ptr = this;

	while(ptr->obj != str)
	{
		ptr = ptr->next;
	}

	if(i==0)// if i = 0 first word or single word documents searching
	{   
		

		node *ptrnum = &ptr->num;
		while(ptrnum !=nullptr)
		{
			c.push_back(ptrnum->num);
			ptrnum=ptrnum->next;

		}

		return c;

	}
	else 
	{   vector<int> p;

	    node *ptrnum = &ptr->num;
		while(ptrnum !=nullptr)
		{
			c.push_back(ptrnum->num);
			ptrnum=ptrnum->next;

		}

		for(int i=0;i<c.size();i++)
		{

			for(int t=0;t<q.size();t++){
			   

				if(c[i]==q[t])
				{
					p.push_back(c[i]);
				}

			}

		}


		return p;
	
	}





}


#endif