#ifndef DS_MATRIX_H
#define DS_MATRIX_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Matrix 
{
    public:
        // constructor
        Matrix(string remark = "", unsigned int rows = 1, unsigned int cols = 1);
        // copy constructor
        Matrix(const Matrix& other);
        ~Matrix();
        void set_dimensions(unsigned int, unsigned int);
        unsigned int get_rows() const { return rows; }
        unsigned int get_cols() const { return cols; }
        void initialize();
        Matrix multiply(const Matrix&) const;
        // copy assignment operator
        Matrix& operator=(const Matrix& other);
        void output() const;
    private:
        unsigned rows;
        unsigned cols;
        string remark;
        double **matrix;
        void create_matrix(unsigned int, unsigned int);
};

Matrix::Matrix(string remark, unsigned int rows, unsigned int cols)
{
    this->remark = remark;
    create_matrix(rows, cols);
}

Matrix::Matrix(const Matrix& other)
{
    rows = other.rows;
    cols = other.cols;
    remark = other.remark;
    create_matrix(rows, cols);
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) { return *this; }

    if (rows > other.rows) 
    {
        if (cols > other.cols) 
        {
            for (int i = 0; i < other.rows; i++)
                for (int j = 0; j < other.cols; j++) 
                    matrix[i][j] = other.matrix[i][j];
        }
        else 
        {
            for (int i = 0; i < other.rows; i++)
                for (int j = 0; j < cols; j++) 
                    matrix[i][j] = other.matrix[i][j];
        }
    }
    else 
    {
        if (cols > other.cols)
        {
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < other.cols; j++)
                    matrix[i][j] = other.matrix[i][j];
        }
        else 
        {
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    matrix[i][j] = other.matrix[i][j];
        }
    }
    return *this;
}

Matrix::~Matrix() 
{
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
}

void Matrix::set_dimensions(unsigned int rows, unsigned int cols)
{
    if (rows < 0 && cols < 0) 
        throw "Number of rows or columns should be > 1";

    this->rows = rows;
    this->cols = cols;
}


void Matrix::create_matrix(unsigned int rows, unsigned int cols)
{
    set_dimensions(rows, cols);

    matrix = new double * [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double [cols];
    }
}

void Matrix::initialize()
{
    cout << "enter the (" << rows << " x "
        << cols  << ") " << remark << " : \n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}


void Matrix::output() const
{
    cout << "Matrix " << remark << " : \n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j > 0 && j < cols) { cout << ", "; }
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

Matrix Matrix::multiply(const Matrix& x) const
{
    Matrix result("product", rows, cols);

    if (cols != x.rows) 
        throw "Multiplication is not possible.";

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < x.cols; j++) {
            result.matrix[i][j] = 0.0;
            for (int k = 0; k < cols; k++) 
                result.matrix[i][j] = result.matrix[i][j] + matrix[i][k] * x.matrix[k][j];
        }
    return result;
}

#endif 
