#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

class Point{
	public:
		double x, y;
		
	Point(){
		
	}	
	Point(double _x, double _y){
		x = _x;
		y = _y;
	}
	
	double calc_distance(double x1, double y1, double x2, double y2){
		return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	}
	double calc_distance(Point a, Point b){
		return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	}
	double calc_distance(Point *a, Point *b){
		return sqrt((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y));
	}
	double calc_distance(Point a){
		return sqrt((x - a.x) * (x - a.x) + (y - a.y) * (y - a.y));
	}
	double calc_distance(Point *a){
		return sqrt((x - a->x) * (x - a->x) + (y - a->y) * (y - a->y));
	}
};

int main(){
	freopen("input.txt", "r", stdin);
	
	int n;
	cin >> n;
	
	Point *pts = new Point[n];
	
	cout.precision(15);
	
	for(int i = 0; i < n; i++){
		double x, y;
		cin >> x >> y;
		pts[i] = Point(x, y);
		//cin >> pts[i].x >> pts[i].y; 
		cout << pts[i].x << " " << pts[i].y << "\n";
	}
	cout << "\n\n";
	
	double min_dist = 10e9; // 1e9 = 10^9 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i != j){
				double dis = pts[i].calc_distance(&pts[j]);
					cout << dis << "\n";
				if(dis < min_dist)
					min_dist = dis;
			}
		}
	}
	
	cout << "\n\nThe minimal distance between two points is: " << min_dist;
	
	delete[] pts;
	return 0;
}

// Algo complexity -> O(n^2)
