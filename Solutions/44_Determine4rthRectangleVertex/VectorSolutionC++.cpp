#include <iostream>
#include <algorithm>
#include <iomanip>

// minimal distance between two dots (vertices) allowed (due to type features)
#define MY_EPSILON 10E-6

// definition of vertex class 
class vertex {
public:
		// X is x coordinate filed  |  Y is y coordinate field
        double X, Y;
        
        // vertex class constructor with defined fields 
        vertex(double x_, double y_ ) : X(x_), Y( y_){}
        
        // vertex class constructor by default (X = 0, Y = 0)
        vertex() : X(0), Y(0){}
 
 		// defition of + and - operators when used between vertex class objects
        vertex operator + (vertex v){
			return vertex(X + v.X, Y + v.Y); 
		}
        vertex operator - (vertex v){
			return vertex(X - v.X, Y - v.Y); 
		}
        
        // returns dot product of two vertices (x multiplied by x and y multiplied by y)
        double dot( vertex v ){
			return X * v.X + Y * v.Y; 
		}
        
        // returns distance from a vertex to (0.0) (sqrt((x1-x2)^2 + (y1-y2)^2) = (sqrt(x1^2-y1^2)) if x2 = 0 and y2 = 0
        double length(){
			return sqrt(X * X + Y * Y ); 
		}
		
        vertex normalize( bool &bOk ){
        		// stores distance
                double len = length();
                
				bOk = false; 
				
				// if length is more than minimal difference allowed
                if( len > MY_EPSILON ){
					bOk = true; 
					return vertex( X/len, Y/len ); 
				}
				
                return *this;
        }       
};

// defition of << operator for std::ostream & (output format for vertex class objects)
std::ostream & operator << ( std::ostream & s, vertex v ){
		// write (x, y) with 6 digit precision after comma to the output stream
		// when std::cout called for vertex class object
        s << std::setprecision(6) << "(" << v.X << "," << v.Y << ") ";
        	
        return s;
}

// checks wether second vertex (b in this function) is where the right angle is
bool isRighAngle( vertex a, vertex b, vertex c){
     // check wether length of AB and BC is bigger than minimal value
     // which would mean those dots are considered to be in the same place
	 bool bOkAB, bOkBC;
 	 
	 // check wether for (b.x - a.x, b.y - a.y)
	 // distance to (0, 0) is bigger than MY_EPSILON    
     vertex uAB = ( b - a ).normalize( bOkAB );
	 vertex uBC = ( c - b ).normalize( bOkBC );
	 
	 // returns true if both distances are > MY_EPSILON
	 // and their dot product is less than MY_EPSILON
     return bOkAB && bOkBC && fabs(uAB.dot( uBC )) < MY_EPSILON;
}

// returns the answer coordinates of vertex d
// when right angle is at vertex b in context of this function 
bool getLastCoordinateIfRightAngle( vertex a, vertex b, vertex c, vertex & d ){
            if( isRighAngle( a, b, c ) ){
                    d = (a + c) - b;	// answer coordinates
                    return true;
            }
            return false;	// right angle is not at vertex b in context of this function
}
  
 // invokes all 3 variants of permutations for vertices a, b, c
 // one of which will be the answer if vertices a, b, c, d form a rectangle  
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
