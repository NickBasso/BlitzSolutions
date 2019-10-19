#include <iostream>
#include <algorithm>
#include <iomanip>

#define MY_EPSILON 10E-6

class vertex {
public:
        double X, Y;
        vertex(double x_, double y_ ) :X(x_), Y( y_){}
        vertex():X(0), Y(0){}

        vertex operator +( vertex v ){ return vertex( X + v.X, Y + v.Y ); }
        vertex operator -( vertex v ){ return vertex( X - v.X, Y - v.Y ); }
        double dot( vertex v ){ return X * v.X + Y * v.Y; }
        double length() { return sqrt(X * X + Y * Y ); }
        vertex normalize( bool &bOk ){
                double len = length(); bOk = false; 
                if( len > MY_EPSILON ){  bOk = true; return vertex( X/len, Y/len ); }
                return *this;
        }       
};

std::ostream & operator << ( std::ostream & s, vertex v ){
        s << std::setprecision(6) << "(" << v.X << "," << v.Y << ") ";
        return s;
}

bool isRighAngle( vertex a, vertex b, vertex c){
     bool bOkAB, bOkBC;
     vertex uAB = ( b - a ).normalize( bOkAB ), uBC = ( c - b ).normalize( bOkBC );
     return bOkAB && bOkBC && fabs(uAB.dot( uBC )) < MY_EPSILON;
}

bool getLastCoordinateIfRightAngle( vertex a, vertex b, vertex c, vertex & d ){
            if( isRighAngle( a, b, c ) ){
                    d = (a + c) - b;
                    return true;
            }
            return false;
    }
    
bool getLastCoordinate( vertex a, vertex b, vertex c, vertex &d ){

            if( getLastCoordinateIfRightAngle( a, b, c, d )   //if B is at the right angle
                || getLastCoordinateIfRightAngle( a, c, b, d ) //if C is at the right angle
                || getLastCoordinateIfRightAngle( b, a, c, d ) ) //if A is at the right angle
            {
                    return true;
            }

            //No right angle found.
            return false;
    }       
    
 int main(int argc, char *argv[])
    {
        vertex A(5.0, -4.0), B(3.0, 4.0), C(-9.0, 1.0), D;

        if( getLastCoordinate( A, B, C, D ) ){
            std::cout << "D coordinate " << D << " found from inputs :  " << A << B << C << std::endl;
        }else {
            std::cout << "D coordinate not found for input:  " << A << B << C << std::endl;
        }

        return 0;
    }
