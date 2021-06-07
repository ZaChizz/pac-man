#include "Point.h"

Point::Point(int x, int y): x(x), y(y) {}

Point::Point(const Point& point) {
    this->x = point.x;
    this->y = point.y;
}

Point::~Point() {}

int Point::getX() const {
    return this->x;
}

int Point::getY() const {
    return this->y;
}

void Point::setX(int x) {
    this->x = x;
}

void Point::setY(int y) {
    this->y = y;
}

void Point::increaseX() {
    this->x += 1;
}

void Point::increaseY() {
    this->y += 1;
}

void Point::decreaseX() {
    this->x -= 1;   
}

void Point::decreaseY() {
    this->y -= 1;   
}

bool Point::operator==(const Point& other) const {
    return this->x == other.x && this->y == other.y;
}

bool Point::operator!=(const Point& other) const {
    return !((*this) == other);
}

double Point::distance(const Point& other) const {
    return hypot(this->x - other.x, this->y - other.y);
}

std::ostream& operator<<(std::ostream& out, const Point& p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}
