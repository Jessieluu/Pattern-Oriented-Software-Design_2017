//
// Created by Jessie on 2017/9/18.
//
#include <list>
#include "include/Sort.h"

using namespace std;

void Sort::sortByIncreasingPerimeter(list<Shape *> *shapeListPointer) {
    list<Shape *> &shapeList = *shapeListPointer;
    shapeList.sort([](Shape *x, Shape *y) {
        return x->perimeter() < y->perimeter();
    });
}

void Sort::sortByDecreasingPerimeter(list<Shape *> *shapeListPointer) {
    list<Shape *> &shapeList = *shapeListPointer;
    shapeList.sort([](Shape *x, Shape *y) {
        return x->perimeter() > y->perimeter();
    });
}

void Sort::sortByIncreasingArea(list<Shape *> *shapeListPointer) {
    list<Shape *> &shapeList = *shapeListPointer;
    shapeList.sort([](Shape *x, Shape *y) {
        return x->area() < y->area();
    });
}

void Sort::sortByDecreasingArea(std::list<Shape *> *shapeListPointer) {
    list<Shape *> &shapeList = *shapeListPointer;
    shapeList.sort([](Shape *x, Shape *y) {
        return x->area() > y->area();
    });
}

void Sort::sortByIncreasingCompactness(std::list<Shape *> *shapeListPointer) {
    list<Shape *> &shapeList = *shapeListPointer;
    shapeList.sort([](Shape *x, Shape *y) {
        return (x->area() / x->perimeter()) < (y->area() / y->perimeter());
    });
}