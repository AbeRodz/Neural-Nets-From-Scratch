



class Matrix{

    public:
        Matrix(int rows, int cols);
        
        ~Matrix();

        int rows(void) const { return ROWS;}
        int cols(void) const {return COLS;}
        void setMatrix(int r, int c) ;
        double getValueAt(int r, int c) const ;
        void print(const Matrix& m);
        Matrix addMatrix( const Matrix& m, const Matrix& n);
        Matrix scalarMultiplication(double n);
        Matrix dotProduct(const Matrix& m, const Matrix& n);

    private:
    const int ROWS;
    const int COLS;
    double* vals;

    double& at(int r, int c) const
    {
        return vals[COLS* r + c];
    }
};