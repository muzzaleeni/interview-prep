Structs in C++ originate from C, where they were used to group variables into a user-defined type, but they couldn't contain functions since C lacked object-oriented features like methods. 

In C++, structs are often used for "classes with no methods," reflecting their traditional use in C. However, aside from defaulting to public access, structs and classes are essentially the same in C++.

Class
``` c++
#include <string>

class Animal {
    std::string type;

    void eat();
    void walk();
    void run();
    // ...
};
```

Struct
```c++
struct Point {
    int x;
    int y;
    // no functionality
};
```
