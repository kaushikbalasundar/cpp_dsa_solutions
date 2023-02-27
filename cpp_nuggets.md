# C++ Nuggets 

### Const Reference Parameter 

I first came to know of this when I was asked about it during an interview with Tesla. Essentially, when you pass a large amount of data into a function, you would need to do so by reference (**&**) to avoid the data from being copied over, and having the **const** keyword prevents the data from being modified by that function. Use this when you're absolutely sure that the data you're passing does not need to be modified by that function. 

```C++ 
void some_function(const & some_large_array){
	
	// Do something with the large array
	return;
}
```

### Operator Overloading

This is a basic feature that C++ programmers need to be aware of - essential for working with structs and classes. The idea is that you take an existing operator and overload it to perform a different functionality. Knowing the syntax for this at your fingertips is key. 

```c++
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

```

