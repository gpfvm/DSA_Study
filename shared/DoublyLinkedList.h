#pragma once

#include <cassert>
#include <stdint.h>
#include <algorithm>

template<typename T>
class DoublyLinkedList
{
public:
	struct Node
	{
		T item = T();

		Node* left = nullptr;
		Node* right = nullptr;

		// 참고: prev/next가 아니라 left/right
	};

	DoublyLinkedList()
	{
	}

	~DoublyLinkedList()
	{
		Clear();
	}

	void Clear() // 모두 지워야(delete) 합니다.
	{
		// TODO:
        while(first_)
            PopFront();
	}

	bool IsEmpty()
	{
		return first_ == nullptr; // TODO:
	}

	int Size()
	{
		int size = 0;

		// TODO:
        Node* current = first_;
        while (current) {
            current = current->right;
            size += 1;
        }

		return size;
	}

	void Print()
	{
		using namespace std;

		Node* current = first_;

		if (IsEmpty())
			cout << "Empty" << endl;
		else
		{
			cout << "Size = " << Size() << endl;

			cout << " Forward: ";
			// TODO:
            
            while(true)
            {
                cout << current->item;
                
                if(!current->right)
                    break;
                current = current->right;
            }
            cout << endl;

			cout << "Backward: ";
            
			// TODO:
            while(true)
            {
                cout << current->item;
                
                if(!current->left)
                    break;
                current = current->left;
            }
			cout << endl;
		}
	}

	Node* Find(T item)
	{
		// TODO:
        
        Node* current = first_;
        while (current)
        {
            if(current->item == item)
                return current;
            
            current = current->right;
        }
        return current;
	}

	void InsertBack(Node* node, T item)
	{
		if (IsEmpty())
		{
			PushBack(item);
		}
		else
		{
			// TODO:
            Node* new_node = new Node;
            new_node->item = item;
            
            Node* temp = nullptr;
            temp = node->right;
            node->right = new_node;
            new_node->left = node;
            new_node->right = temp;
            temp->left = new_node;
		}
	}

	void PushFront(T item)
	{
		// TODO:
        Node* new_node = new Node;
        new_node->item = item;
        
        new_node->right = first_;
        if(first_)
            first_->left = new_node;
        first_ = new_node;
        new_node->left = nullptr;

	}

	void PushBack(T item)
	{
		// TODO:
        if(first_)
        {
            Node* current = first_;
            while (current->right)
                current = current->right;
            
            Node* new_node = new Node;
            new_node->item = item;
            new_node->left = current;
            current->right = new_node;
        }
        else
            PushFront(item);
        
	}

	void PopFront()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopFront()" << endl;
			return;
		}

		assert(first_);

		// TODO:
        Node* temp = first_;
        first_ = first_->right;
        if (first_)
            first_->left = nullptr;
        delete temp;
	}

	void PopBack()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopBack()" << endl;
			return;
		}

		// 맨 뒤에서 하나 앞의 노드를 찾아야 합니다.

		assert(first_);

		// TODO:
        using namespace std;
        Node* current = first_;
        
        if(current->right)
        {
            while (current->right->right)
                current = current->right;
            
            Node* temp = current->right;
            current->right = nullptr;
            delete temp;
        }
        else
        {
            delete first_;
            first_ = nullptr;
        }
        
       
	}

	void Reverse()
    {
        // TODO:
        if(IsEmpty())
            return;
        else
        {
            Node* prev = nullptr;
            Node* current = first_;
            
            while(current)
            {
                prev = current;
                
                current = current->right;
                
                std::swap(prev->left,prev->right);
            }
            first_ = prev;
        }
	}

	T Front()
	{
		assert(first_);

		//TODO:
        return first_->item;

	}

	T Back()
	{
		assert(first_);

		 // TODO:
        Node* current = first_;
        while (current->right)
            current = current->right;
        return current->item;
	}

protected:
	Node* first_ = nullptr;
};
