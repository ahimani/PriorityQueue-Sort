// a4.cpp

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : Asim Himani
// St.# : 301276136
// Email: ahimani@sfu.ca
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////

#include <algorithm>    // std::sort
#include <iostream>     // std::cout
#include <cstdlib>      // rand()
#include <cassert>      // assert()
#include <ctime>        // srand()
#include "a4.h"         // Priority_queue

using namespace std;

int main() {
    // comparisons for STL sort
    long long comparison = 0;
    
    // to randomize the vector every time the program is run
    srand(time(0));
    
    // Instantiate a vector of n elements
    //int n = 10000;
    for(int j = 5000; j <= 100000; j += 5000) {
        vector<int> v(j);
        
        // Insert random elements into the vector
        for(int i = 0; i < v.size(); i++) {
            v[i] = rand() % 100000;
        }
        // Sort the vector using Selection sort based on an unordered vector
        cout << "For n = " << v.size() << "\n";
        cout << "1> Number of Comparisons done by PQ_unordered based Selection Sort:\n";
        pq_sort<PQ_unordered>(v);
        for(int i = 1; i < v.size(); i++) {
            assert(v[i-1] <= v[i]);
        }
        
        // Insert random elements into the vector
        for(int i = 0; i < v.size(); i++) {
            v[i] = rand() % 100000;
        }
        // Sort the vector using Insertion sort based on a sorted vector
        cout << "2> Number of Comparisons done by PQ_ordered based Insertion Sort:\n";
        pq_sort<PQ_ordered>(v);
        for(int i = 1; i < v.size(); i++) {
            assert(v[i-1] <= v[i]);
        }
        
        // Insert random elements into the vector
        for(int i = 0; i < v.size(); i++) {
            v[i] = rand() % 100000;
        }
        // Sort the vector using Heapsort based on a heap
        cout << "3> Number of Comparisons done by PQ_heap based Heap Sort:\n";
        pq_sort<PQ_heap>(v);
        for(int i = 1; i < v.size(); i++) {
            assert(v[i-1] <= v[i]);
        }
        
        //Insert random elements into the vector
        for(int i = 0; i < v.size(); i++) {
            v[i] = rand() % 100000;
        }
        // Sort the vector using STL std::sort
        sort(v.begin(), v.end(), [&comparison](int x, int y) {
            comparison++;
            return x < y;
        });
        for(int i = 1; i < v.size(); i++) {
            assert(v[i-1] <= v[i]);
        }
        cout << "4> Number of Comparisons done by STL Sort:\n";
        cout << comparison << "\n\n";
        
    }
    return 0;
}


