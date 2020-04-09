#include "Vector3D.h"

class Matrix3D {

private:

double data[3][3];

public:

Matrix3D(double a, double b, double c, double d, double e, double f, double g, double k, double l) {
    data[0][0] = a;
    data[0][1] = b;
    data[0][2] = c;
    data[1][0] = d;
    data[1][1] = e;
    data[1][2] = f;
    data[2][0] = g;
    data[2][1] = k;
    data[2][2] = l;
}
 
Matrix3D() {
    for (int i = 0; i < 3; i++)
       for (int j = 0; j < 3; j++)
           data[i][j] = 0;
}

~Matrix3D(){}

void setElement (int place_Y, int place_X, double value) {

    data[place_X][place_Y] = value;

}

double getElement (int place_Y, int place_X) {

    return data[place_X][place_Y];

}

double det() {

    return (data[0][0] * (data[1][1] * data[2][2] - data[2][1] * data[1][2]) - data[0][1] * (data[1][0]*data[2][2] - data[1][2]*data[2][0]) + data[0][2] * (data[1][0] * data[2][1] - data[2][0] * data[1][1]));

}

Matrix3D operator* (double value) {

    Matrix3D m1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m1.setElement(i, j, data[i][j] * value);
        }
    }

    return m1;

}

Matrix3D operator+ (Matrix3D m1) {

    Matrix3D m2;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            m2.setElement(i, j, data[i][j] + m1.getElement(i , j));

        }
    }

    return m2;
}

Matrix3D operator- (Matrix3D m1) {

    Matrix3D m2;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            m2.setElement(i, j, data[i][j] - m1.getElement(i , j));

        }
    }

    return m2;
}

Matrix3D operator* (Matrix3D m1) {

    Matrix3D m2(0,0,0,0,0,0,0,0,0);
    double sigma = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                
                sigma += data[i][k] * m1.getElement(k, j);

            }

            m2.setElement(i, j, sigma);

            sigma = 0;

        }
    }

    return m2;

}


};

istream& operator>> (istream& in, Matrix3D &m1) {


    
    double a[3][3];
    
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            
            in >> a[i][j];
            m1.setElement(i, j, a[i][j]);

        }
    }

    return in;

}

Matrix3D operator*(int value, Matrix3D m1) {

    Matrix3D m2(0,0,0,0,0,0,0,0,0);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            m2.setElement(i, j, m1.getElement(i, j) * value);

        }
    }

    return m2;

}

Vector3D operator* (Matrix3D m1, Vector3D v1) {

    Vector3D v2(0, 0, 0);
    double sigma;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            sigma += m1.getElement(i, j) * v1.getCoordinate(i); 

        }

        v2.setCoordinate(sigma, i);
        sigma = 0;

    }

    return v2;

}

ostream& operator<< (ostream& out, Matrix3D m1) {

    for (int i = 0; i < 3; i++) {
        
        for (int j = 0; j < 3; j++) {

            out << m1.getElement(i, j);

        }

        out << endl;
    }

    return out;

}

