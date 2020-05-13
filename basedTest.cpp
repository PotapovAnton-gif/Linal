#include "Matrix.h"

int main()
{
    Vector3D A(1, 2, 3);
    Matrix3D C(1, 0, 0, 0, 1, 0, 0, 0, 1);

    Vector3D res = C * A;
    cout << res << endl;

    return 0;
}