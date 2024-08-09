### Diamond problem

The diamond problem is a well-known issue in object-oriented programming that occurs when a class inherits from two classes that both inherit from a common base class. This can lead to ambiguity and multiple copies of the base class's members, which can cause unexpected behavior.

``` c++
class A {
    void func();
    // ...
};

class B : public A {
    // ...
};

class C : public A {
    // ...
}; 

class D : public B, public C {
    // ...
}

int main() {
    D obj;
    D.func(); // ambiguity
}
```

When you use multiple inheritance in C++ without virtual inheritance, each derived class gets its own copy of the base class subobject. This means that the derived class object ends up containing multiple instances of the base class, each with its own copy of the base class's methods and data members.

Even if the methods in the base class are identical (i.e., they have the same name and implementation), the compiler treats the methods inherited through different paths as distinct because they belong to different subobjects of the base class.

### Virtual inheritance

``` c++
class A {
    void func();
    // ...
};

class B : virtual public A {
    // ...
};

class C : virtual public A {
    // ...
}; 

class D : public B, public C {
    // ...
}

int main() {
    D obj;
    D.func(); // works fine
}
```

When you use virtual inheritance, you tell the compiler that both B and C should share a single instance of A. This removes the ambiguity because there's only one A subobject in D.

### Specifying the function call
``` c++
class A {
    void func();
    // ...
};

class B : public A {
    // ...
};

class C : public A {
    // ...
}; 

class D : public B, public C {
    // ...
}

int main() {
    D obj;
    D.B::func(); // calling from B
    D.C::func(); // calling from C
}
``` 
