#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <iterator>

#include "sort.h"

int main(int argc, const char** argv)
{
    int array1[10]={2,34,5,12,32,7,0,44,76,98};
    int array2[10]={2,34,5,12,32,7,0,44,76,98};
    std::vector<float> vector1={1.2,4.5,7.5,1.3,5.4,9.6};
    std::vector<float> vector2={1.2,4.5,7.5,1.3,5.4,9.6};
    //test heap sort with int array
    heap_sort<int*>sortint;
    sortint.sort(array1+0,10);
    std::make_heap(array2+0,array2+10);
    std::sort_heap(array2+0,array2+10);
    std::cout<<"my heap sort: ";
    for(int v:array1) std::cout<<v<<" ";
    std::cout<<std::endl;
    std::cout<<"default heap sort: ";
    for(int v2:array2) std::cout<<v2<<" ";
    std::cout<<std::endl;
    //test heap sort with float vector
    heap_sort<std::vector<float>::iterator>sortvector;
    sortvector.sort(vector1.begin(),10);
    std::make_heap(vector2.begin(),vector2.end());
    std::sort_heap(vector2.begin(),vector2.end());
    std::cout<<"my heap sort: ";
    for(auto v:vector1) std::cout<<v<<" ";
    std::cout<<std::endl;
    std::cout<<"default heap sort: ";
    for(std::vector<float>::iterator v2=vector2.begin();v2<vector2.end();v2++) std::cout<<*(v2)<<" ";
    std::cout<<std::endl;
    //test changing typename Comparetype from std::less(default) to std::greater 
    heap_sort<int*,std::greater<int>>sortint_max;
    sortint_max.sort(array1+0,10);
    std::cout<<"my heap sort(max): ";
    for(int v:array1) std::cout<<v<<" ";
    std::cout<<std::endl;

    system("pause");
}