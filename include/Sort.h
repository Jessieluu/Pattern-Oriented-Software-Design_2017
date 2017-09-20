#include <list>
#include "Shapes.h"

class Sort {
  public :static void sortByIncreasingPerimeter(std::list<Shape *> * shapeListPointer);

  public :static void sortByDecreasingPerimeter(std::list<Shape *> * shapeListPointer);

  public :static void sortByIncreasingArea(std::list<Shape *> * shapeListPointer);

  public :static void sortByDecreasingArea(std::list<Shape *> * shapeListPointer);

  public :static void sortByIncreasingCompactness(std::list<Shape *> * shapeListPointer);

};
