



class Matrix{

    public:
        Matrix(int rows, int cols);
        
        ~Matrix();

        float& operator()(int r, int c);
        float operator()(int r, int c) const;

        int rows(void) const { return ROWS;}
        int cols(void) const {return COLS;}
        
        void setMatrix(int r, int c);
        void setMatrixRandom(void);
        float getValueAt(int r, int c) const;
        void setValueAt(int r, int c, float val);
        void print(const Matrix& m);

        Matrix addMatrix(const Matrix& m);
        Matrix operator+(const Matrix& m);

        Matrix substractMatrix( const Matrix& m, const Matrix& n);
        Matrix scalarMultiplication(float n);
        Matrix dotProduct(const Matrix& m, const Matrix& n);
        Matrix transpose();
        

    private:
    const int ROWS;
    const int COLS;
    float* vals;

    inline float& at(int r, int c) const
    {
        return vals[COLS * r + c];
    }


};

float& Matrix::operator()(int r, int c){
return at(r,c);
}
float Matrix::operator()(int r, int c) const{
return at(r,c);
}