#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

class Point {
    private:
        int x;
        int y;

    public:
        Point(int x=0, int y=0);
        Point(const Point& point);
        ~Point();

        int getX() const;
        int getY() const;

        void setX(int x);
        void setY(int y);

        void increaseX();
        void increaseY();
        void decreaseX();
        void decreaseY();
        
        bool operator==(const Point& other) const;
        bool operator!=(const Point& other) const;

        double distance(const Point& other) const;
        
        friend std::ostream& operator<<(std::ostream& out, const Point& p);
};

std::ostream& operator<<(std::ostream& out, const Point& p);

#endif // POINT_H
