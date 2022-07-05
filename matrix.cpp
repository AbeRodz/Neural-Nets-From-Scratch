#include "matrix.hpp"
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <chrono>
#include <stdlib.h>


#define N 2048

Matrix::Matrix(int rows, int cols):
ROWS(rows), COLS(cols)
{
    vals = new float[ROWS*COLS];
}

void Matrix::setMatrix(int r, int c) 
{
    float n;
    for(int r = 0; r< ROWS; ++r ){
        for(int c = 0; c< COLS;++c){
            std::cout<< "enter value "<< "row: "<< r << "col: "<< c<< std::endl;
            std::cin >> n;
            //n = rand();
                at(r,c) = n;
         }

    }
}

void Matrix::setMatrixRandom(void){
    float n;
    for(int r = 0; r< ROWS; ++r ){
        for(int c = 0; c< COLS;++c){
            n = (rand()%100);
                at(r,c) = n;
         }

    }
}

float Matrix::getValueAt(int r, int c) const 
{
    if (r < 0 or r >= ROWS or c<0 or c>= COLS){
        throw std::out_of_range("Matrix out of range");
    }
    return at(r,c);
}

void Matrix::setValueAt(int r, int c, float val) {
        if (r < 0 or r >= ROWS or c<0 or c>= COLS){
        throw std::out_of_range("Matrix out of range");
    }
    at(r,c) = val;
}



Matrix Matrix::addMatrix(const Matrix& m){
    if (ROWS != m.rows()  or COLS!= m.cols() )
        {
            throw std::out_of_range("Matrices are not of the same dimension");
        }
    Matrix ret(ROWS, COLS);
    for(int i = 0; i< ROWS * COLS; ++i ){
        ret.vals[i] = vals[i] + m.vals[i];
                
        }
        return ret;
    }
Matrix Matrix::operator+(const Matrix& m){
        return addMatrix(m);
}

Matrix Matrix::substractMatrix( const Matrix& m, const Matrix& n){
    if (m.rows() != n.rows() or m.cols() != n.cols())
        {
            throw std::out_of_range("Matrices are not of the same dimension");
        }
    Matrix ret(m.rows(), m.cols());
    for(int i = 0; i< m.rows() * m.cols(); ++i ){
        ret.vals[i] = vals[i] - m.vals[i];
                
        }
        return ret;
}

Matrix Matrix::scalarMultiplication(float n)
{
    Matrix ret(ROWS, COLS);
    for(int i = 0; i< ROWS* COLS; ++i){
        
        ret.vals[i] = vals[i]*n;
        vals[i] = ret.vals[i];
    }
    return ret;
}

Matrix Matrix::dotProduct(const Matrix& m, const Matrix& n)
{
     if (m.rows() != n.cols() or m.cols() != n.rows())
        {
            throw std::out_of_range("Matrices are not of the same dimension");
        }
    Matrix ret(ROWS, n.cols());
    for(int i = 0; i< ROWS; ++i ){
        for(int j = 0; j< COLS; ++j){
            ret(i,j) = 0.0;
            for(int k=0; k< COLS; ++k){
              ret(i,j) += m(i,k)*n(k,j);  
             
                }
            }
             //vals[i] = ret.vals[i];
        }
        return ret;
}    

void Matrix::print(const Matrix& m){

    for(int r = 0; r< m.rows(); ++r ){
        for(int c = 0; c<m.cols();++c){
            std::cout << (c >0 ? " ":"") << std::setw(4);
            std::cout << m.getValueAt(r,c);
         }
         std::cout << std::endl;
    }
}

Matrix::~Matrix()
{
    delete[] vals;
}

int main(){
    
    Matrix m1(N,N);
    m1.setMatrixRandom();
    //int N = m1.rows()*m1.cols();
    double gflop = (2.0*N*N*N)*1e-9;
    Matrix *m2 = new Matrix(m1);

    //m1.scalarMultiplication(0.5);
    //m1.dotProduct(m1,*m2);
    
    //m1.dotProduct(m1,*m2);
    m1.print(m1);
    //m1.print(*m2);

    Matrix m3(N,N);
    m3.setMatrixRandom();
    m1.print(m3);
    auto start = std::chrono::steady_clock::now();
    Matrix m4 = m1.addMatrix(m3);
    //m1.print(m4);
    auto stop = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = (stop-start);
    std::cout << "total duration: " << diff.count()<<std::endl;
    
    std::cout << "GFLOP/S: " << gflop/diff.count();

}