#pragma once

#include <cassert>
#include <stdint.h>

template<typename T>
class SinglyLinkedList
{
public:
	struct Node
	{
		T item = T();
		Node* next = nullptr;
	};

	SinglyLinkedList()
	{
	}

	SinglyLinkedList(const SinglyLinkedList& list)
	{
		// TODO: 연결 리스트 복사
        Node* current = list.first_;
        while (current) {
            PushBack(current->item);
            current = current->next;
        }

	}

	~SinglyLinkedList()
	{
		Clear();
	}

	void Clear() // 모두 지워야(delete) 합니다.
	{
		// TODO: 모두 삭제
        while(!IsEmpty())
        {
            PopFront();
        }
	}

	bool IsEmpty()
	{
		return first_ == nullptr;
	}

	int Size()
	{
		int size = 0;

		// TODO: size를 하나하나 세어서 반환
        Node* current = first_;
        while(current)
        {
            size += 1;
            current = current->next;
        }

		return size;
	}

	T Front()
	{
		assert(first_);

        return first_->item; // TODO: 수정
	}

	T Back()
	{
		assert(first_);
        
        Node* current = first_;
        while(current->next)
        {
            current = current->next;
        }

		return current->item; // TODO: 수정
	}

	Node* Find(T item)
	{
		// TODO: item이 동일한 노드 포인터 반환
        Node* current = first_;
        while(current->item != item)
        {
            current = current->next;
        }

		return current;
	}

	void InsertBack(Node* node, T item)
	{
		// TODO:
        Node* new_one = new Node;
        new_one->item = item;
        
        Node* temp = nullptr;
        temp = node->next;
        
        node->next = new_one;
        new_one->next = temp;
	}

	void Remove(Node* n)
	{
		assert(first_);

		// 하나 앞의 노드를 찾아야 합니다.
		// TODO:
        Node* current = first_;
        while(current->next != n)
        {
            current = current->next;
        }
        current->next = n->next;
        delete n;
	}

	void PushFront(T item)
	{
		// first_가 nullptr인 경우와 아닌 경우 나눠서 생각해보기 (결국은 두 경우를 하나로 합칠 수 있음)

		// 새로운 노드 만들기
		// TODO:
        Node* current = new Node;
        
        current->item = item;
        current->next = first_;
		// 연결 관계 정리
		// TODO:
        first_ = current;
        
	}

	void PushBack(T item)
	{
		if (first_)
		{
			// TODO:
            Node* add = new Node;
            add->item = item;
            add->next = nullptr;
            
            Node* current = first_;
            while (current->next) {
                current = current->next;
            }
            current->next = add;
		}
		else
		{
			// TODO:
            PushFront(item);
		}
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

		// TODO: 메모리 삭제
        Node* temp = first_;
        first_ = first_->next;
        
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

		// TODO: 메모리 삭제
        Node* current = first_;
        Node* temp = new Node;
        if(!current->next)
        {
            delete first_;
            first_ = nullptr;
        }
        else
        {
            while (current->next->next) {
                current = current->next;
            }
            temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
	}

	void Reverse()
	{
		// TODO:
        Node* current = first_;
        Node* temp = nullptr;
        while (current->next) {
            first_ = current->next;
            current->next = temp;
            temp = current;
            current = first_;
        }
        current->next = temp;
	}

	void SetPrintDebug(bool flag)
	{
		print_debug_ = flag;
	}

	void Print()
	{
		using namespace std;

		Node* current = first_;

		if (IsEmpty())
			cout << "Empty" << endl;
		else
		{
			cout << "Size = " << Size() << " ";

			while (current)
			{
				if (print_debug_)
				{
					//cout << "[" << current << ", " << current->item << ", " << current->next << "]";

					// 주소를 짧은 정수로 출력 (앞 부분은 대부분 동일하기때문에 뒷부분만 출력)
					cout << "[" << reinterpret_cast<uintptr_t>(current) % 100000 << ", "
						<< current->item << ", "
						<< reinterpret_cast<uintptr_t>(current->next) % 100000 << "]";
				}
				else
				{
					cout << current->item;
				}

				if (current->next)
					cout << " -> ";
				else
					cout << " -> NULL";

				current = current->next;
			}
			cout << endl;
		}
	}

protected:
	Node* first_ = nullptr;
	bool print_debug_ = false;
};
