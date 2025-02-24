#include "SparseMatrix.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

SparseMatrix::SparseMatrix(int num_rows, int num_cols, int capacity)
{
	// TODO:
    terms_ = new MatrixTerm[capacity];
    
    int num_rows_ = num_rows; // 최대 rows 갯수
    int num_cols_ = num_cols; // 최대 columns 갯수
    int capacity_ = capacity;
    int num_terms_ = 0;
    
}

// 복사 생성자 (b를 복사)
SparseMatrix::SparseMatrix(const SparseMatrix& b)
{
	// TODO:
    if(b.capacity_ >0)
    {
        terms_ = new MatrixTerm[b.capacity_];
        
        int num_rows_ = b.num_rows_; // 최대 rows 갯수
        int num_cols_ = b.num_cols_; // 최대 columns 갯수
        int capacity_ = b.capacity_;
        int num_terms_ = 0;
        
        memcpy(terms_,b.terms_,sizeof(MatrixTerm) * num_terms_);
    }
}

SparseMatrix::~SparseMatrix()
{
	// TODO:
    if(terms_) delete[] terms_;
}

void SparseMatrix::SetValue(int row, int col, float value)
{
	if (value == 0.0f) return; // value가 0이 아닌 term만 저장
	// TODO:
    int key = col + num_cols_ * row;
    int i = 0;
    for(; i < capacity_; i++)
    {
        int key_i = terms_[i].col + num_cols_ * terms_[i].row;
        if(key_i == key)
        {
            terms_[i].row = row;
            terms_[i].col = col;
            terms_[i].value = value;
        }
        else if (key_i > i)
            break;
    }
    
    
       

}

float SparseMatrix::GetValue(int row, int col) const // 맨 뒤의 const는 함수 안에서 멤버 변수의 값을 바꾸지 않겠다는 의미
{
	// TODO: key = col + num_cols * row;
	return 0.0f;
}

SparseMatrix SparseMatrix::Transpose()
{
	SparseMatrix temp(num_cols_, num_rows_, capacity_); // num_cols_, num_rows_ 순서 주의

	// TODO:

	return temp;
}

void SparseMatrix::PrintTerms()
{
	for (int i = 0; i < num_terms_; i++)
		cout << "(" << terms_[i].row
		<< ", " << terms_[i].col
		<< ", " << terms_[i].value
		<< ")" << endl;
}

void SparseMatrix::Print()
{
	for (int r = 0; r < num_rows_; r++)
	{
		for (int c = 0; c < num_cols_; c++)
			cout << GetValue(r, c) << " ";
		cout << endl;
	}
}
