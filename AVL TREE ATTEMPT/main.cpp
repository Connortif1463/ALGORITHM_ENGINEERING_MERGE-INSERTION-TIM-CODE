//#include <iostream>
//#include <ctime>
//#include <cstdlib>
//#include "AVLTree.h"
//
//int main() {
//    AVLTree avl;
//
//    // Add entries to the dictionary
//
////    std::clock_t start_time = std::clock();
//    
//    avl.insert(1, "One");
//
////    std::clock_t tot_time = std::clock() - start_time; // INSERT1 Time: 7e-06 seconds
////    std::cout << "INSERT1 Time: " << ((double) tot_time) / (double) CLOCKS_PER_SEC << " seconds " << std::endl;
//
//    avl.insert(2, "Two");
//    avl.insert(3, "Three");
//    avl.insert(4, "Four");
//    avl.insert(5, "Five");
//
//    std::cout << "AVL Tree:" << std::endl;
//    avl.display();
//
//    int key = 3;
//
////    std::clock_t start_time = std::clock();
//
//    std::string result = avl.search(key);
//
////    std::clock_t tot_time = std::clock() - start_time; // SEARCH Time: 3e-06 seconds
////    std::cout << "SEARCH Time: " << ((double) tot_time) / (double) CLOCKS_PER_SEC << " seconds " << std::endl;
//
//    std::cout << "Search for key " << key << ": " << result << std::endl;
//
//    std::clock_t start_time = std::clock();
//
//    int deleteKey = 2;
//    avl.deleteNode(deleteKey);
//
//    std::clock_t tot_time = std::clock() - start_time; //
//    std::cout << "DELETE Time: " << ((double) tot_time) / (double) CLOCKS_PER_SEC << " seconds " << std::endl;
//
//    std::cout << "Deleted key " << deleteKey << ":" << std::endl;
//    avl.display();
//
//    int index = 4;
//    result = avl.index(index);
//    std::cout << "Value at index " << index << ": " << result << std::endl;
//
//    std::cout << "Min key: " << avl.min() << std::endl;
//    std::cout << "Max key: " << avl.max() << std::endl;
//
//    int prevKey = 3;
//    result = avl.prev(prevKey);
//    std::cout << "Predecessor of key " << prevKey << ": " << result << std::endl;
//
//    int nextKey = 3;
//    result = avl.next(nextKey);
//    std::cout << "Successor of key " << nextKey << ": " << result << std::endl;
//
//    return 0;
//}

#include "avl_tree.h"
#include <iostream>

int main() {
    AVLTree avl;

    //    std::clock_t start_time = std::clock();
    avl.insert(1, "One");
    //    std::clock_t tot_time = std::clock() - start_time;
    //    std::cout << "INSERT1 Time: " << ((double) tot_time) / (double) CLOCKS_PER_SEC << " seconds " << std::endl; // INSERT1 Time: 7e-06 seconds
    
    avl.insert(2, "Two");
    avl.insert(3, "Three");
    avl.insert(4, "Four");
    avl.insert(5, "Five");

    int key = 3;
    //    std::clock_t start_time = std::clock();
    std::string result = avl.search(key);
    //    std::clock_t tot_time = std::clock() - start_time;
    //    std::cout << "SEARCH Time: " << ((double) tot_time) / (double) CLOCKS_PER_SEC << " seconds " << std::endl; // SEARCH Time: 3e-06 seconds

    int deleteKey = 2;
//    std::clock_t start_time = std::clock();
    avl.deleteNode(deleteKey);
//    std::clock_t tot_time = std::clock() - start_time;
//    std::cout << "DELETE Time: " << ((double) tot_time) / (double) CLOCKS_PER_SEC << " seconds " << std::endl; // DELETE Time: 9e-06 seconds

    int index = 4;
//    std::clock_t start_time = std::clock();
    result = avl.index(index);
//    std::clock_t tot_time = std::clock() - start_time;
//    std::cout << "INDEX Time: " << ((double) tot_time) / (double) CLOCKS_PER_SEC << " seconds " << std::endl; // INDEX Time: 6e-06 seconds

    int prevKey = 3;
//    std::clock_t start_time = std::clock();
    result = avl.prev(prevKey);
//    std::clock_t tot_time = std::clock() - start_time;
//    std::cout << "PREV Time: " << ((double) tot_time) / (double) CLOCKS_PER_SEC << " seconds " << std::endl; // PREV Time: 9e-06 seconds

    int nextKey = 3;
//    std::clock_t start_time = std::clock();
    result = avl.next(nextKey);
//    std::clock_t tot_time = std::clock() - start_time;
//    std::cout << "NEXT Time: " << ((double) tot_time) / (double) CLOCKS_PER_SEC << " seconds " << std::endl; // NEXT Time: 4e-06 seconds

    return 0;
}
