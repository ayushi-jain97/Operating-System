# Operating-System
_Tested on Ubuntu 16.04_
 Contains codes to illustrate basic Linux concepts

## Thread Testing
* Illustrates how to use pthreads
* Focuses on drawbacks of using too many threads for a simple application
* Observe running time by varying number of threads and size of matrix

```c++
g++ tooManyThreads.cpp -lpthread
```

## Pipes
* Copying files with the help of pipes
* Formatting strings received from the read end
