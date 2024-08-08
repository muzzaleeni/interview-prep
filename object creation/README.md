## Creating Objects on Stack and Heap

### Stack
- Objects created on the stack are allocated contiguous memory within the function's stack frame.
- The exact location is determined by the compiler.
- For example:
    ```cpp
    MyStruct structOnStack(1, 2.5);
    ```
- This allocates 12 bytes (4 for `int`, 8 for `double`) on the stack inside the `main()` frame.

### Heap
- Objects created on the heap use memory allocated by the operating system's memory manager.
- The memory manager finds a block of memory large enough to hold the object.
- For example:
    ```cpp
    MyStruct* structOnHeap = new MyStruct(3, 4.5);
    delete structOnHeap;
    ```
- This typically allocates 12 bytes for `int a` and `double b`.

### Memory Deallocation
- Stack and heap memory don't actually delete the memory space.
- They make the memory accessible for new allocations.

### Methods
- Methods are not created with object variables.
- They are stored in the code/text segment like other functions.
- When a method is invoked, it creates a new stack frame.