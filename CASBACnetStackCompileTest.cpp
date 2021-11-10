
// CAS BACnet Stack - Compiler test 
// Last updated: 2021-Nov-10
// 
// See readme for more information: https://github.com/chipkin/CompilerTestCASBACnetStack 
// 
// CAS BACnet Stack: https://store.chipkin.com/services/stacks/bacnet-stack 
// 
// This project is used to test a compiler to ensure that it supports the prerequisites for the CAS BACnet Stack. 
// The CAS BACnet Stack has a requirement for C++ C99 and standard template library (STL) 
// https://en.wikipedia.org/wiki/Standard_Template_Library 
// 
// Within the STL the CAS BACnet Stack uses the following libary features. These features must be supported by 
// the compiler 
//   std::string, std::nothrow, std::vector, std::map, std::stringstream, std::swap, std::list, std::set, 
//   std::pair, std::copy, std::ostringstream, std::queue, std::ostream, std::reverse
// 



// ToDo: Update this function to support output the results of a test. 
// If your system supports a console you probably can leave this as is. 
#include <iostream>
void AssertTrue(const char* name, const bool statment) {
    if (statment) {
        std::cout << "Test: " << name << " = OK\n";
    }
    else {
        std::cout << "Test: " << name << " = FAIL\n";
    }
}


// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------

// std::string
// https://www.cplusplus.com/reference/string/string/operator=/
#include <string>
bool test_std_string() {
    std::string str1, str2, str3;
    str1 = "Test string: ";   // c-string
    str2 = 'x';               // single character
    str3 = str1 + str2;       // string
    return (str3.compare("Test string: x") == 0);
}

// std::nothrow
// https://www.cplusplus.com/reference/new/nothrow/
#include <new>          // std::nothrow
bool test_std_nothrow() {
    char* p = new (std::nothrow) char[1048576];
    if (!p) { // null pointers are implicitly converted to false
        return false; 
    } else {
        delete[] p;
        return true; 
    }
}

// std::vector
// https://www.cplusplus.com/reference/vector/vector/size/ 
#include <vector>
bool test_std_vector() {
    std::vector<int> myints;
    if (myints.size() != 0) {
        return false; 
    }

    for (int i = 0; i < 10; i++) myints.push_back(i);
    if (myints.size() != 10) {
        return false;
    }
    myints.insert(myints.end(), 10, 100);
    if (myints.size() != 20) {
        return false;
    }

    myints.pop_back();
    if (myints.size() != 19) {
        return false;
    }

    return true;
}

// std::map
// https://www.cplusplus.com/reference/map/map/operator[]/ 
#include <map>
bool test_std_map() {
    
    std::map<char, std::string> mymap;

    mymap['a'] = "an element";
    mymap['b'] = "another element";
    mymap['c'] = mymap['b'];

    if (mymap['a'].compare( "an element") != 0) {
        return false; 
    }
    if (mymap['b'].compare("another element") != 0) {
        return false;
    }
    if (mymap['c'].compare("another element") != 0) {
        return false;
    }
    if (mymap['d'].compare("") != 0) {
        return false;
    }    
    if (mymap.size() != 4) {
        return false; 
    }

    return true; 
}


// std::swap
// https://www.cplusplus.com/reference/utility/swap/?kw=swap 
#include <utility>      // std::swap
bool test_std_swap() {

    int x = 10, y = 20;              // x:10 y:20
    std::swap(x, y);                 // x:20 y:10

    int foo[4];                      // foo: ?  ?  ?  ?
    int bar[] = { 10,20,30,40 };     // foo: ?  ?  ?  ?    bar: 10 20 30 40
    std::swap(foo, bar);             // foo: 10 20 30 40   bar: ?  ?  ?  ?

    if (foo[0] != 10) {
        return false; 
    }
    if (foo[1] != 20) {
        return false;
    }
    if (foo[2] != 30) {
        return false;
    }
    if (foo[3] != 40) {
        return false;
    }

    return true; 
}

// std::list
// https://www.cplusplus.com/reference/list/list/push_front/
#include <list>
bool test_std_list() {
    std::list<int> mylist(2, 100);         // two ints with a value of 100
    mylist.push_front(200);
    mylist.push_front(300);

    if (mylist.size() != 4) {
        return false; 
    }

    return true;
}

// std::set
// https://www.cplusplus.com/reference/set/set/size/ 
#include <set>
bool test_std_set() {
    std::set<int> myints;
    if (myints.size() != 0) {
        return false; 
    }

    for (int i = 0; i < 10; ++i) myints.insert(i);
    if (myints.size() != 10) {
        return false;
    }

    myints.insert(100);
    if (myints.size() != 11) {
        return false;
    }

    myints.erase(5);
    if (myints.size() != 10) {
        return false;
    }

    return true;
}

// std::pair
// https://www.cplusplus.com/reference/utility/make_pair/
#include <utility>      // std::pair
bool test_std_pair() {
    std::pair <int, int> foo;
    std::pair <int, int> bar;

    foo = std::make_pair(10, 20);
    bar = std::make_pair(10.5, 'A'); // ok: implicit conversion from pair<double,char>

    if (foo.first != 10 || foo.second != 20) {
        return false;
    }
    if (bar.first != 10 || bar.second != 65) {
        return false;
    }
    return true;
}

// std::copy
// https://www.cplusplus.com/reference/algorithm/copy/?kw=copy
#include <algorithm>    // std::copy
#include <vector>       // std::vector
bool test_std_copy() {
    int myints[] = { 10,20,30,40,50,60,70 };
    std::vector<int> myvector(7);
    std::copy(myints, myints + 7, myvector.begin());

    if (myvector.size() != 7) {
        return false; 
    }

    if (myvector[0] != 10) {
        return false;
    }

    return true;
}

// std::queue
// https://www.cplusplus.com/reference/queue/queue/size/
#include <queue>          // std::queue
bool test_std_queue() {
    std::queue<int> myints;
    if (myints.size() != 0) {
        return false;
    }    

    for (int i = 0; i < 5; i++) myints.push(i);
    if (myints.size() != 5) {
        return false;
    }

    myints.pop();
    if (myints.size() != 4) {
        return false;
    }

    return true;
}

// std::reverse
// https://www.cplusplus.com/reference/algorithm/reverse/
#include <algorithm>    // std::reverse
#include <vector>       // std::vector
bool test_std_reverse() {
    std::vector<int> myvector;

    // set some values:
    for (int i = 1; i < 10; ++i) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9
    std::reverse(myvector.begin(), myvector.end());       // 9 8 7 6 5 4 3 2 1

    if (myvector[0] != 9 || myvector[5] != 4) {
        return false; 
    }

    return true; 
}


// C++ Plymorphism
// https://www.tutorialspoint.com/cplusplus/cpp_polymorphism.htm

class Shape {
public: 
    virtual uint8_t GetCornerCount() = 0;
};

class Square : public Shape {
public:
    uint8_t GetCornerCount() { return 4; }
};

class Triangle : public Shape {
public:
    uint8_t GetCornerCount() { return 3; }
};

bool test_cpp_polymorphism() {
    Square sq;
    if (sq.GetCornerCount() != 4) {
        return false; 
    }

    Triangle tri;
    if (tri.GetCornerCount() != 3) {
        return false;
    }

    Shape* sha = NULL; 

    sha = &sq; 
    if (sha->GetCornerCount() != 4) {
        return false;
    }

    sha = &tri;
    if (sha->GetCornerCount() != 3) {
        return false;
    }

    return true;
}




int main()
{
    AssertTrue("test_std_string", test_std_string());
    AssertTrue("test_std_nothrow", test_std_nothrow());
    AssertTrue("test_std_vector", test_std_vector());
    AssertTrue("test_std_map", test_std_map());
    AssertTrue("test_std_swap", test_std_swap());
    AssertTrue("test_std_list", test_std_list());
    AssertTrue("test_std_set", test_std_set());
    AssertTrue("test_std_pair", test_std_pair());
    AssertTrue("test_std_copy", test_std_copy());
    AssertTrue("test_std_queue", test_std_queue());
    AssertTrue("test_std_reverse", test_std_reverse());
    AssertTrue("test_cpp_polymorphism", test_cpp_polymorphism());
}
