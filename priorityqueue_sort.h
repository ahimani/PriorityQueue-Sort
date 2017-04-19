// priorityqueue_sort.h

#include "cmpt_error.h"
#include <vector>

using namespace std;



class PQ_unordered {
private:
    vector<int> vect;
    
public:
    long long count = 0;
    
    // Pre-condition:
    //    none
    // Post-condition:
    //    returns the number of elements in the Priority_queue
    int size() const {
        return vect.size();
    }
    
    // Pre-condition:
    //    none
    // Post-condition:
    //    returns true if Priority_queue is empty, false otherwise
    bool empty() const {
        return vect.empty();
    }
    
    // Pre-condition:
    //    none
    // Post-condition:
    //    Priority_queue contains x as the last element
    void insert(int x) {
        vect.push_back(x);
    }
    
    // Pre-condition:
    //    none
    // Post-condition:
    //    Pops and returns the minimum element in the Priority_queue
    int removeMin() {
        int minIndex = 0;
        for(int i = 0; i < vect.size(); i++) {
            count += 2;
            if(vect[i] < vect[minIndex]) {
                minIndex = i;
            }
        }
        int minElem = vect[minIndex];
        vect[minIndex] = vect.back();
        vect.pop_back();
        return minElem;
    }
    
}; // class PQ_undordered


class PQ_ordered {
private:
    vector<int> vect;
    
public:
    long long count = 0;
    
    // Pre-condition:
    //    none
    // Post-condition:
    //    returns the number of elements in the Priority_queue
    int size() const {
        return vect.size();
    }
    
    // Pre-condition:
    //    none
    // Post-condition:
    //    returns true if Priority_queue is empty, false otherwise
    bool empty() const {
        return vect.empty();
    }
    
    // Pre-condition:
    //    none
    // Post-condition:
    //    Priority_queue contains x as the last element
    void insert(int x) {
        if(empty()) {
            vect.push_back(x);
            return;
        }
        for(int i = 0; i < vect.size(); i++) {
            if(vect[i] < x) {
                vect.insert(vect.begin() + i, x);
                return;
            }
            count += 2;
        }
        vect.push_back(x);
        return;
    }
    
    // Pre-condition:
    //    none
    // Post-condition:
    //    Pops and returns the minimum element in the Priority_queue
    int removeMin() {
        int ret = vect.back();
        vect.pop_back();
        return ret;
    }
    
}; // class PQ_ordordered


class PQ_heap {
private:
    vector<int> compTree;
    
public:
	long long count = 0;

    // Pre-condition:
    //    none
    // Post-condition:
    //    returns the index of the last element
    int lastIndex() const {
        return compTree.size()-1;
    }
    
    // Pre-condition:
    //    none
    // Post-condition:
    //    returns true if Priority_queue is empty, false otherwise
    bool empty() const {
        return compTree.empty();
    }
    
    // Pre-condition:
    //    index > 0 && index < compTree.size()
    // Post-condition:
    //    returns the index of the parent
    int parent(int index) {
        return index/2;
    }
    
    // Pre-condition:
    //    index > 0 && index < compTree.size()
    // Post-condition:
    //    returns the index of the left child
    int leftIndex(int index) {
        return 2*index;
    }
    
    // Pre-condition:
    //    index > 0 && index < compTree.size()
    // Post-condition:
    //    returns the index of the right child
    int rightIndex(int index) {
        return 2*index + 1;
    }

    // Pre-condition:
    //    i,j > 0 && i,j < compTree.size()
    // Post-condition:
    //    swaps the values at indices i and j
    void swap(int i, int j) {
        int val = compTree[i];
        compTree[i] = compTree[j];
        compTree[j] = val;
        return; 
    }
    
    // Pre-condition:
    //    none
    // Post-condition:
    //    Priority_queue contains x as the last element
    void insert(int x) {
        if(compTree.empty()) {
            compTree.push_back(0);
            compTree.push_back(x);
            return;
        }
        compTree.push_back(x);
        int childIndex = lastIndex();
        while(childIndex != 0) {
        	int parIndex = parent(childIndex);
        	if(x > compTree[parIndex]) {
        		break;
        	}
        	swap(childIndex, parIndex);
        	childIndex = parIndex;
        }
        return;
    }
    
    // Pre-condition:
    //    none
    // Post-condition:
    //    Pops and returns the minimum element in the Priority_queue
    int removeMin() {
        count++;
    	if(lastIndex() == 1) {
    		int ret = compTree.back();
    		compTree.pop_back();
    		return ret;
    	}
    	int currIndex = 1;
    	swap(currIndex, lastIndex());
        int ret = compTree.back();
        compTree.pop_back();
        while(leftIndex(currIndex) <= lastIndex()) {
            count += 4;
        	int child = leftIndex(currIndex);
        	if(rightIndex(currIndex) <= lastIndex() && compTree[rightIndex(currIndex)] < compTree[child]) {
        		child = rightIndex(currIndex);
        	}
        	if(compTree[child] <= compTree[currIndex]) {
        		swap(child, currIndex);
        		currIndex = child;
        	}
        	else break;
        }
        return ret;
    }
}; // class PQ_heap



template<class PQ>
void pq_sort(vector<int>& v) {
    PQ pq;
    for(int x : v) {
        pq.insert(x);
    }
    v.clear();
    while (!pq.empty()) {
        pq.count++;
        v.push_back(pq.removeMin());
    }
    cout << pq.count << "\n";
}

