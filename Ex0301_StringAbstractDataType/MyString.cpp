#include "MyString.h"

using namespace std;

// 비어 있는 MyString() 생성
MyString::MyString()
{
	str_ = nullptr;
	size_ = 0;
}

// 맨 뒤에 널 캐릭터'\0'가 들어 있는 문자열로부터 초기화
MyString::MyString(const char* init)
{
	// 크기(size_) 결정
    size_ = 0;
    while (init[size_] != '\0')
        size_ ++;
        
	// 메모리 할당
    str_ = new char[size_];
	// 데이터 복사
    for (int i = 0; i < size_; i++)
        str_[i] = init[i];
}

// MyString의 다른 instance로부터 초기화
MyString::MyString(const MyString& str)
{
    // 기본 복사 생성자는 포인터 주소만 복사하기 때문에
    // 소멸시 오류 발생
    // 여기서는 새로 메모리를 할당 받아서 복사
    size_ = str.size_;
    str_ = new char[size_];
    
    for (int i = 0; i < size_; i++)
        str_[i] = str.str_[i];
   
}

MyString::~MyString()
{
	// 메모리 해제
    size_ = 0;
    if(str_)
        delete [] str_;
}

bool MyString::IsEmpty()
{
	return Length() == 0;
}

bool MyString::IsEqual(const MyString& str) // 편의상 참조& 사용
{
	// 힌트: str.str_, str.size_ 가능
    
    if (str.size_ == size_)
    {
        int str_i = 0;
        int i = 0;
        
        for (; i < size_; i++)
        {
            if (str_i == size_ -1)
                return true;
            
            if(str_[i] == str.str_[str_i])
                str_i++;
        }
        
        
    }
	return false;
}

int MyString::Length()
{
	return size_;
}

void MyString::Resize(int new_size)
{
	// 메모리 재할당과 원래 갖고 있던 내용 복사
}

// 인덱스 start위치의 글자부터 num개의 글자로 새로운 문자열 만들기
MyString MyString::Substr(int start, int num)
{
	// 복사할 인덱스: start, start + 1, ... , start + num - 1
	// assert(start + num - 1 < this->size_); // 문제를 단순하게 만들기 위해 가정

	MyString temp;

	// TODO:

	return temp;
}

MyString MyString::Concat(MyString app_str)
{
	MyString temp;

	// TODO: 

	return temp;
}

MyString MyString::Insert(MyString t, int start)
{
	assert(start >= 0);
	assert(start <= this->size_);

	MyString temp;

	// TODO:

	return temp;
}

int MyString::Find(MyString pat)
{
	//TODO:
    int start = 0;
    int count = 0;
    
    while (start <= size_ - pat.size_)
    {
        
        for (int i = 0; i < pat.size_; i++)
        {
            if(str_[start+i] == pat.str_[i])
                count++;
            else
                count = 0;
        }
        
        if(count != pat.size_)
        {
            start++;
            count = 0;
        }
        else
            return start;
            
    }
    return -1;
}

void MyString::Print()
{
	for (int i = 0; i < size_; i++)
		cout << str_[i];
	cout << endl;
}

