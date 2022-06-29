#include "matrix.hpp"
#include <iostream>
#include <stdexcept>
#include <iomanip>

Matrix::Matrix(int rows, int cols):
ROWS(rows), COLS(cols)
{
    vals = new double[ROWS*COLS];
}

void Matrix::setMatrix(int r, int c) 
{
    int n;
    for(int r = 0; r< ROWS; ++r ){
        for(int c = 0; c< COLS;++c){
            std::cout<< "enter value "<< "row: "<< r << "col: "<< c<< std::endl;
            std::cin >> n;
                at(r,c) = n;
         }

    }
}

double Matrix::getValueAt(int r, int c) const 
{
    if (r < 0 or r >= ROWS or c<0 or c>= COLS){
        throw std::out_of_range("Matrix out of range");
    }
    return at(r,c);
}

Matrix Matrix::addMatrix(const Matrix& m, const Matrix& n)
{
        if (m.rows() != n.rows() or m.cols() != n.cols())
        {
            throw std::out_of_range("Matrices are not of the same dimension");
        }
    Matrix ret(m.rows(), m.cols());
    for(int i = 0; i< m.rows() * m.cols(); ++i ){
        ret.vals[i] = vals[i] + m.vals[i];
                
        }
        return ret;
    }

Matrix Matrix::scalarMultiplication(double n)
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
    Matrix ret(m.rows(), m.cols());
    for(int i = 0; i< m.rows() * m.cols(); ++i ){
        ret.vals[i] = vals[i] + m.vals[i];
                
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

    Matrix m1(2,2);
    m1.setMatrix(m1.rows(), m1.cols());
    Matrix *m2 = new Matrix(m1);
    //Matrix m4 = m1.addMatrix(*m2, m1);
    m1.scalarMultiplication(0.5);
    m1.dotProduct(m1,*m2);
    m1.print(m1);

}