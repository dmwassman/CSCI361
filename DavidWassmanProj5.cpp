#include <iostream>
#include "CSCI361Proj5.h"

using namespace std;
using namespace FHSULINKEDLIST;

namespace std
{
	size_t list_length(Node* head_ptr){
		size_t index = 0;
		Node* here = head_ptr;

		if(here == NULL)
		{
			return 0;
		}
		else
		{
			while(here->link != NULL)
			{
				index++;
				here = here->link;
			}

			return index;
		}
	}

	void list_head_insert(Node*& head_ptr, const Node::Item& entry)
	{
		Node* temp_ptr;
		temp_ptr = new Node;

		temp_ptr->data = entry;

		temp_ptr->link = head_ptr;
		head_ptr = temp_ptr;
	}

	void list_insert(Node* previous_ptr, const Node::Item& entry)
	{
		Node* temp_ptr;
		temp_ptr = new Node;

		temp_ptr->data = entry;

		temp_ptr->link = previous_ptr->link;
		previous_ptr->link = temp_ptr;
	
	}

	Node* list_search(Node* head_ptr, const Node::Item& target)
	{
	
		Node* here = head_ptr;

		if(here == NULL)
		{
			return NULL;
		}
		else
		{
			while(here->data != target && here->link != NULL)
			{
				here = here->link;
			}

			if(here->data == target)
			{
				return here;
			}
			else
			{
				return NULL;
			}
		}
	}

	Node* list_locate(Node* head_ptr, size_t position)
	{
		size_t count = 0;

		for(Node* here = head_ptr; here != NULL; here = here->link)
		{
			count++;
			if(count == position)
			{
				return here;
			}
		}

		return NULL;
	}

	void list_head_remove(Node*& head_ptr)
	{
		
		Node* temp_ptr = head_ptr;

		head_ptr = head_ptr->link;
		delete temp_ptr;

	}

	void list_remove(Node* previous_ptr)
	{
		
		Node* temp_ptr = previous_ptr->link;
		previous_ptr->link = temp_ptr->link;
		delete temp_ptr;
		
	}

	void list_clear(Node*& head_ptr)
	{
		
		while(head_ptr != NULL)
		{
			Node* temp_ptr = head_ptr;
			head_ptr = head_ptr->link;
			delete temp_ptr;
		}
		
	}

	void list_copy(Node* source_ptr, Node*& head_ptr)
	{
		
		Node* temp_ptr = source_ptr;
		while(temp_ptr != NULL)
		{
			head_ptr->data = temp_ptr->data;
			head_ptr->link = temp_ptr->link;
			temp_ptr = temp_ptr->link;
		}
		
	}

	size_t list_occurrences(Node* head_ptr, const Node::Item& target)
	{
		
		size_t count = 0;
		
		for(Node* temp_ptr = head_ptr; temp_ptr != NULL; temp_ptr = temp_ptr->link)
		{
			if(temp_ptr->data == target)
			{
				count++;
			}
		}
		
		return count;
	}

	void list_tail_attach(Node*& head_ptr, const Node::Item& entry)
	{
		
		Node* temp_ptr;
		temp_ptr = new Node;
			
		temp_ptr->data = entry;
		temp_ptr->link = NULL;
			
		if(head_ptr == NULL)
		{
			head_ptr = temp_ptr;
		}
		else
		{
			Node* last_ptr;
			for(last_ptr = head_ptr; last_ptr->link != NULL; last_ptr = last_ptr->link)
			{}
			
			last_ptr->link = temp_ptr;
		}
		
	}

	void list_tail_remove(Node*& head_ptr)
	{
		
		if(head_ptr->link == NULL)
		{
			head_ptr = NULL;
		}
		else
		{
			Node* last_ptr;
			Node* temp_ptr;
			for(last_ptr = head_ptr; last_ptr->link->link != NULL; last_ptr = last_ptr->link)
			{}
			
			temp_ptr = last_ptr->link;
			last_ptr->link = NULL;
			
			delete temp_ptr;
		}
		
	}
	
	Node* list_copy_front(Node* source_ptr, size_t n)
	{
		
		Node* return_ptr;
		return_ptr = new Node;
		
		for(Node* temp_ptr = source_ptr; temp_ptr != NULL; temp_ptr = temp_ptr->link)
		{
			return_ptr->data = temp_ptr->data;
			return_ptr->link = temp_ptr->link;
		}
		
		
		return return_ptr;
	}
}