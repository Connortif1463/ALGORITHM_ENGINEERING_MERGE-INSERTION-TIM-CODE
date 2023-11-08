#include <iostream>
#include <ctime>
#include <cstdlib>
#include "multimap_operations.h"

using namespace std;

int main() {
    Insert("A", 1);
    Insert("A", 3);
    Insert("A", 2);
    Insert("B", 2);
    
    std::clock_t start_time = std::clock();
    Insert("B", 5);
    std::clock_t tot_time = std::clock() - start_time;
    std::cout << "INSERT Time: " << ((double) tot_time) / (double) CLOCKS_PER_SEC << " seconds " << std::endl; // INSERT Time: 1.1e-05 seconds

    start_time = std::clock();
    bool foundA3 = Search("A", 3);
    tot_time = std::clock() - start_time;
    std::cout << "SEARCH Time: " << ((double) tot_time) / (double) CLOCKS_PER_SEC << " seconds " << std::endl; // SEARCH Time: 4e-06 seconds
    
    start_time = std::clock();
    bool foundB2 = Search("B", 2);
    tot_time = std::clock() - start_time;
    std::cout << "SEARCH Time: " << ((double) tot_time) / (double) CLOCKS_PER_SEC << " seconds " << std::endl; // SEARCH Time: 2e-06 seconds

//    if (foundA3) {
//        std::cout << "Found A 3" << std::endl;
//    } else {
//        std::cout << "Not Found A 3" << std::endl;
//    }

//    if (foundB2) {
//        std::cout << "Found B 2" << std::endl;
//    } else {
//        std::cout << "Not Found B 2" << std::endl;
//    }

    start_time = std::clock();
    bool deletedA1 = Delete("A", 1);
    tot_time = std::clock() - start_time;
    std::cout << "DELETE Time: " << ((double) tot_time) / (double) CLOCKS_PER_SEC << " seconds " << std::endl; // DELETE Time: 4e-06 seconds

//    if (deletedA1) {
//        std::cout << "Deleted A 1" << std::endl;
//    } else {
//        std::cout << "Not Found A 1 for deletion" << std::endl;
//    }

    start_time = std::clock();
    int minA = Min("A");
    tot_time = std::clock() - start_time;
    std::cout << "MIN Time: " << ((double) tot_time) / (double) CLOCKS_PER_SEC << " seconds " << std::endl; // MIN Time: 3e-06 seconds
    
    int maxA = Max("A");
    int minB = Min("B");
    
    start_time = std::clock();
    int maxB = Max("B");
    tot_time = std::clock() - start_time;
    std::cout << "MAX Time: " << ((double) tot_time) / (double) CLOCKS_PER_SEC << " seconds " << std::endl; // MAX Time: 4e-06 seconds

//    std::cout << "Min for A: " << minA << std::endl;
//    std::cout << "Max for A: " << maxA << std::endl;
//    std::cout << "Min for B: " << minB << std::endl;
//    std::cout << "Max for B: " << maxB << std::endl;

    int value = 2;
    start_time = std::clock();
    bool nextA2 = Next("A", value);
    tot_time = std::clock() - start_time;
    std::cout << "NEXT Time: " << ((double) tot_time) / (double) CLOCKS_PER_SEC << " seconds " << std::endl; // NEXT Time: 2e-06 seconds

//    if (nextA2) {
//        std::cout << "Next for A " << value << " found." << std::endl;
//    } else {
//        std::cout << "Next for A " << value << " not found." << std::endl;
//    }

    value = 5;
    start_time = std::clock();
    bool nextB5 = Next("B", value);
    tot_time = std::clock() - start_time;
    std::cout << "NEXT Time: " << ((double) tot_time) / (double) CLOCKS_PER_SEC << " seconds " << std::endl; // NEXT Time: 3e-06 seconds

//    if (nextB5) {
//        std::cout << "Next for B " << value << " found." << std::endl;
//    } else {
//        std::cout << "Next for B " << value << " not found." << std::endl;
//    }
    
    value = 3;
    start_time = std::clock();
    bool prevA3 = Prev("A", value);
    tot_time = std::clock() - start_time;
    std::cout << "PREV Time: " << ((double) tot_time) / (double) CLOCKS_PER_SEC << " seconds " << std::endl; // PREV Time: 2e-06 seconds

//    if (prevA3) {
//        std::cout << "Prev for A " << value << " found." << std::endl;
//    } else {
//        std::cout << "Prev for A " << value << " not found." << std::endl;
//    }

    return 0;
}
