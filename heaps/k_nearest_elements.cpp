#include <queue> 
#include <vector> 
#include <iostream> 
#include <cmath>


//Class to store point coordinates and distance from the reference point
class Point{
    public: 
        int x_; 
        int y_;
        double dist_;

    Point(){};
    //Constructor 
    Point(int x, int y){
        x_ = x; 
        y_ = y;
        dist_ = -1;
    }
};

//Custom comparator to compare Point objects based on their dist_ property
class PointComparator{

    public:
        bool operator()(Point a, Point b){
            return a.dist_ < b.dist_;
        }
};

// Class to find K closest points to the reference point
class FindkClosesetPoints{

    public:
        int k_; 
        std::priority_queue<Point, std::vector<Point>, PointComparator> pq_; 
        std::vector<Point> coordinates_;
        Point reference_point_;

        FindkClosesetPoints(int k, std::vector<Point> coordinates, Point reference_point){
            k_ = k;
            coordinates_ = coordinates;
            reference_point_ = reference_point;
        }

        //Compute Euclidean distance 
        double computeEucDist(Point &a, Point &b){
            return sqrt(pow((b.x_ - a.x_),2) + pow((b.y_ - a.y_),2));
        }

        // Update the points' distance from the refrence points
        void computeDistances(){
            for (Point &p: coordinates_){
                p.dist_ = computeEucDist(p, reference_point_);
            }
        }

        //Print the points 
        void printkClosestPoints(){
            findKClosestElements();
            std::cout << "The K closest points are: " << std::endl;
            while(!pq_.empty()){
                std::cout << "(" << pq_.top().x_ << ", " << pq_.top().y_ << ") ,"; 
                pq_.pop();
            }
            std::cout << std::endl;
        }

        

        private:
        
            void findKClosestElements(){
                computeDistances();
                for (int i=0; i<k_; i++){
                    // Push the first k elements into the heap
                    pq_.push(coordinates_[i]);
                }

                for (int i=k_; i<coordinates_.size(); i++){
                    if(coordinates_[i].dist_ < pq_.top().dist_){
                        pq_.pop();
                        pq_.push(coordinates_[i]);
                    }
                }
            }

};

int main(){

    std::vector<Point> points = {{1,5},{2,3},{5,7},{11,0}, {1,1},{99,99},{99,98}};
    Point referencePoint = {100,100};
    int k = 3;

    FindkClosesetPoints f(k, points, referencePoint);
    f.printkClosestPoints();   
}