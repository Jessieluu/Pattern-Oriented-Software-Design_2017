#include <gtest/gtest.h>
#include "utSort.h"

int main( int argc , char **argv )
{
    testing :: InitGoogleTest( &argc , argv ) ;
    return RUN_ALL_TESTS( ) ;
//    list<int> *l = new list<int>;
//    l->push_back(1);
//    l->push_back(2);
//    l->push_back(3);
//
//
//
//    std::cout <<  l->front() << std::endl; //得到最前面的元素
//    l->pop_front(); //得到後刪除掉 if you need
//
//    std::cout << l->back()<< std::endl;  //得到最後一個元素
//    l->pop_back(); //得到後刪除 if you need
//    std::cout << l->size()<< std::endl;  //因為有刪除，所以 size 變成 1
}
