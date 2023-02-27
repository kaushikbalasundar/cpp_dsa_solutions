#include <iostream>

class Point{
    
    public: 
        int x_;
        int y_;

        Point() = default;
        Point (int x, int y){
            x_ = x;
            y_ = y;
        }

        // Overload the + operator 
        Point operator + (Point p){
            Point new_pt; 
            new_pt.x_ = x_ + p.x_; 
            new_pt.y_ = y_ + p.y_;
            return new_pt;
        }
        // Overload the == operator 
            bool operator == (Point p){
                return x_ == p.x_ && y_ == p.y_; 
            }

};

int main(){
    Point p1 = Point(5,10);
    Point p2 = Point(6,10);
    Point new_pt = p1 + p2; 

    std::cout << "x: " << new_pt.x_ << ", y: " << new_pt.y_ << std::endl;
    if(p1 == p2){
        std::cout << "Equal!" << std::endl;
    }
    else{
        std::cout << "Not equal!" << std::endl;
    }
}