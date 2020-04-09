#include <iostream>
using namespace std;

class Vector3D {

private:

double coordinate[3];


public:

Vector3D(double x, double y, double z) {
     coordinate[0] = x;
     coordinate[1] = y;
     coordinate[2] = z;
}

Vector3D() {
    for (int i = 0; i < 3; i++)
    coordinate[i] = 0;
}
~Vector3D() {
    
}

void setCoordinate(double value, int i) {

    coordinate[i] = value;

}

Vector3D operator+ (Vector3D &v3) {
    Vector3D v2(coordinate[0] + v3.getCoordinate(0), coordinate[1] + v3.getCoordinate(1), coordinate[2] + v3.getCoordinate(2));
    return v2;
}

Vector3D operator- (Vector3D &v3) {

    Vector3D v2(coordinate[0] - v3.getCoordinate(0), coordinate[1] - v3.getCoordinate(1), coordinate[2] - v3.getCoordinate(2));
    return v2;

}

Vector3D operator* (double lbd) {

    Vector3D v2(coordinate[0] * lbd, coordinate[1] * lbd, coordinate[2] * lbd);
    return v2;

}

Vector3D operator* (Vector3D &v3) {

    Vector3D v2(coordinate[0] * v3.coordinate[0], coordinate[1] * v3.coordinate[1], coordinate[2] * v3.coordinate[2]);
    return v2;
}



double getCoordinate(int i) {
    if (i >= 2 && i <= 0){
        return 0;
    }
    return coordinate[i];
}

};
Vector3D operator* (int lbd, Vector3D v1) {


    Vector3D v2(v1.getCoordinate(0) * lbd, v1.getCoordinate(1) * lbd, v1.getCoordinate(2) * lbd);
    return v2;

}

istream& operator>> (istream &in, Vector3D &v1) {
    
    double x; double y; double z;
    
    in >> x >> y >> z;
    cout << x << endl;


    v1.setCoordinate(x, 0);
    cout << v1.getCoordinate(0) << endl;
    v1.setCoordinate(y, 1);
    v1.setCoordinate(z, 2);
    
    return in;

}

ostream& operator<< (ostream &ou, Vector3D v1) {
    
    ou << "(" << v1.getCoordinate(0) << ", " << v1.getCoordinate(1) << ", " << v1.getCoordinate(2) << ")";

    return ou;

}
