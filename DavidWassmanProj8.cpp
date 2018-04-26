#include <iostream>
#include <vector>

using namespace std;

class ItemSet {
	public:
		ItemSet();
		void add(int d);
		void remove(int d);
		void output() const;
		int size() const;
		bool contains(int d);
		int *to_array() const;
	private:
		struct Set {
			int data;
			Set *link;
		};
		Set *head;
		
};

int main() 
{
	int count;
	ItemSet a;
	
	a.add(1);
	a.add(2);
	a.add(3);
	a.add(4);
	a.add(5);
	
	
	for(int i = 0; i < a.size(); i++){
		cout << a.to_array()[i] << endl;
	}
	
	int *t;
	
	t = a.to_array();
	
	
	
	
	
	return 0;
}

ItemSet::ItemSet()  {
	head->link = NULL;
}

void ItemSet::add(int d) {
	bool bAdd = true;
	
	Set *iter;
	for(iter = head; iter != NULL; iter = iter->link) {
		if(iter->data == d) {
			bAdd = false;
			}
	}
	if(bAdd){
		Set *temp;
	
		temp = new Set;
	
		temp->data = d;
		temp->link = head;
		head = temp;
	}
}


void ItemSet::remove(int d) {
	Set *iter;
		
	if(head->data == d){
		Set *temp = head;
		head = head->link;
		delete temp;
	}else{
		for( iter = head; iter != NULL; iter = iter->link){
			if(iter->link->data == d){
				break;
			}
		}
		
		Set *temp = iter->link;
		iter->link = temp->link;
		delete temp;
	}
}

void ItemSet::output() const {
	for(Set *iter = head; iter != NULL; iter = iter->link){
		cout << iter->data << endl;
	}
}

int ItemSet::size() const {
	int count = 0;
	Set *iter;
	for(iter = head; iter != NULL; iter = iter->link) {
		count++;
	}
	
	return count;
}

bool ItemSet::contains(int d){
	
	for(Set *iter = head; iter != NULL; iter = iter->link) {
		if(iter->data == d){
			return true;
		}
	}
	
	return false;
}

int *ItemSet::to_array() const {
	int count = size();
	
	if(count > 0){
		int* copy = new int[count];
		Set *iter = head;
		
		for(int i = 0; i < count; i++){
			copy[i] = iter->data;
			iter = iter->link;
		}
		return copy;
	}
	
	return NULL;
	
	
}
