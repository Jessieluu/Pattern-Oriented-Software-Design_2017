#ifndef EXP_H
#define EXP_H

#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"

using namespace std;

const double epsilon = 0.00001;
const bool threshold = true;

TEST (Sort, sortByIncreasingPerimeter) {
    Circle cir(2, 7, 11);
    Rectangle rect(3, 8, 12, 21);
    Triangle tri({1, 1}, {3, 1}, {3, 4});

    std::list<Shape *> *shapeListPointer = new list<Shape *>();

    shapeListPointer->push_back(&cir);
    shapeListPointer->push_back(&rect);
    shapeListPointer->push_back(&tri);
    Sort s;
    s.sortByIncreasingPerimeter(shapeListPointer);

    ASSERT_NEAR(8.60555, shapeListPointer->front()->perimeter(), epsilon);
    shapeListPointer->pop_front();
    ASSERT_NEAR(66, shapeListPointer->front()->perimeter(), epsilon);
    shapeListPointer->pop_front();
    ASSERT_NEAR(69.11503, shapeListPointer->front()->perimeter(), epsilon);
    shapeListPointer->pop_front();
    ASSERT_EQ(0, shapeListPointer->size());
}

TEST (Sort, sortByDecreasingPerimeter) {
    Circle cir(2, 7, 11);
    Rectangle rect(3, 8, 12, 21);
    Triangle tri({1, 1}, {3, 1}, {3, 4});

    std::list<Shape *> *shapeListPointer = new list<Shape *>();

    shapeListPointer->push_back(&cir);
    shapeListPointer->push_back(&rect);
    shapeListPointer->push_back(&tri);
    Sort s;
    s.sortByDecreasingPerimeter(shapeListPointer);

    ASSERT_NEAR(69.11503, shapeListPointer->front()->perimeter(), epsilon);
    shapeListPointer->pop_front();
    ASSERT_NEAR(66, shapeListPointer->front()->perimeter(), epsilon);
    shapeListPointer->pop_front();
    ASSERT_NEAR(8.60555, shapeListPointer->front()->perimeter(), epsilon);
    shapeListPointer->pop_front();
    ASSERT_EQ(0, shapeListPointer->size());

}

TEST (Sort, sortByIncreasingArea) {
    Circle cir(2, 7, 11);
    Rectangle rect(3, 8, 12, 21);
    Triangle tri({1, 1}, {3, 1}, {3, 4});

    std::list<Shape *> *shapeListPointer = new list<Shape *>();

    shapeListPointer->push_back(&cir);
    shapeListPointer->push_back(&rect);
    shapeListPointer->push_back(&tri);
    Sort s;
    s.sortByIncreasingArea(shapeListPointer);

    ASSERT_NEAR(3, shapeListPointer->front()->area(), epsilon);
    shapeListPointer->pop_front();
    ASSERT_NEAR(252, shapeListPointer->front()->area(), epsilon);
    shapeListPointer->pop_front();
    ASSERT_NEAR(380.13271, shapeListPointer->front()->area(), epsilon);
    shapeListPointer->pop_front();
    ASSERT_EQ(0, shapeListPointer->size());

}

TEST (Sort, sortByDecreasingArea) {
    Circle cir(2, 7, 11);
    Rectangle rect(3, 8, 12, 21);
    Triangle tri({1, 1}, {3, 1}, {3, 4});

    std::list<Shape *> *shapeListPointer = new list<Shape *>();

    shapeListPointer->push_back(&cir);
    shapeListPointer->push_back(&rect);
    shapeListPointer->push_back(&tri);
    Sort s;
    s.sortByDecreasingArea(shapeListPointer);

    ASSERT_NEAR(380.13271, shapeListPointer->front()->area(), epsilon);
    shapeListPointer->pop_front();
    ASSERT_NEAR(252, shapeListPointer->front()->area(), epsilon);
    shapeListPointer->pop_front();
    ASSERT_NEAR(3, shapeListPointer->front()->area(), epsilon);
    shapeListPointer->pop_front();
    ASSERT_EQ(0, shapeListPointer->size());

}

TEST (Sort, sortByIncreasingCompactness) {
    Circle cir(2, 7, 11);
    Rectangle rect(3, 8, 12, 21);
    Triangle tri({1, 1}, {3, 1}, {3, 4});

    std::list<Shape *> *shapeListPointer = new list<Shape *>();

    shapeListPointer->push_back(&cir);
    shapeListPointer->push_back(&rect);
    shapeListPointer->push_back(&tri);
    Sort s;
    s.sortByIncreasingCompactness(shapeListPointer);

//    cout << shapeListPointer->front()->area() / shapeListPointer->front()->perimeter() << endl;
//    shapeListPointer->pop_front();
//    cout << shapeListPointer->front()->area() / shapeListPointer->front()->perimeter() << endl;
//    shapeListPointer->pop_front();
//    cout << shapeListPointer->front()->area() / shapeListPointer->front()->perimeter() << endl;

    ASSERT_NEAR(0.348612, shapeListPointer->front()->area() / shapeListPointer->front()->perimeter(), epsilon);
    shapeListPointer->pop_front();
    ASSERT_NEAR(3.81818, shapeListPointer->front()->area() / shapeListPointer->front()->perimeter(), epsilon);
    shapeListPointer->pop_front();
    ASSERT_NEAR(5.5, shapeListPointer->front()->area() / shapeListPointer->front()->perimeter(), epsilon);
    shapeListPointer->pop_front();
    ASSERT_EQ(0, shapeListPointer->size());

}

#endif
