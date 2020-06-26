#include <unistd.h>
#include <sys/mman.h>
#include <utility>
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <numeric>

const unsigned int threadsSupported = std::thread::hardware_concurrency();
const char delimiter = '\n';


int size,k;
int ans[8];
char* ptr;
std::vector<std::pair<char*,int>> ps(threadsSupported);
std::vector<std::vector<int>> e(threadsSupported,std::vector<int>());
__attribute__((always_inline))inline char* stdin_ptr()
{
    size = lseek(0, 0,2);
    lseek(0, 0,0);
    return (char*)mmap (0, size, PROT_READ, MAP_SHARED | MAP_POPULATE, STDIN_FILENO, 0);
}
__attribute__((always_inline)) inline int fast_atoi(char*& data){
    int val = 0;
    do{
        val = val*10 + *data++ - '0';
    } while(*data != delimiter);
    ++data;
    return val;
}

void func(int n){
    char * l=ps[n].first;
    char*te=l+ps[n].second;
    int val;
    while (l<te) {
        char* x = l;
        l=(char*)
                rawmemchr(l,delimiter)+1;
        switch (l - x - 1) {
            case 1:
                val = x[0] - 48;
                break;
            case 2:
                val = (x[0] - 48) * 10 + x[1] - 48;
                break;
            case 3:
                val = (x[0] - 48) * 100 + (x[1] - 48) * 10 + x[2] - 48;
                break;
            case 4:
                val = (x[0] - 48) * 1000 + (x[1] - 48) * 100 + (x[2] - 48) * 10 + x[3] - 48;
                break;
            case 5:
                val = (x[0] - 48) * 10000 + (x[1] - 48) * 1000 + (x[2] - 48) * 100 + (x[3] - 48) * 10 + x[4] -
                      48;
                break;
            case 6:
                val = (x[0] - 48) * 100000 + (x[1] - 48) * 10000 + (x[2] - 48) * 1000 + (x[3] - 48) * 100 +
                      (x[4] - 48) * 10 + x[5] - 48;
                break;
            case 7:
                val = (x[0] - 48) * 1000000 + (x[1] - 48) * 100000 + (x[2] - 48) * 10000 + (x[3] - 48) * 1000 +
                      (x[4] - 48) * 100 + (x[5] - 48) * 10 + x[6] - 48;
                break;
            case 8:
                val = (x[0] - 48) * 10000000 + (x[1] - 48) * 1000000 + (x[2] - 48) * 100000 + (x[3] - 48) * 10000 +
                      (x[4] - 48) * 1000 + (x[5] - 48) * 100 + (x[6] - 48) * 10 + x[7] - 48;
                break;
            case 9:
                val = (x[0] - 48) * 100000000 + (x[1] - 48) * 10000000 + (x[2] - 48) * 1000000 + (x[3] - 48) * 100000 +
                      (x[4] - 48) * 10000 + (x[5] - 48) * 1000 + (x[6] - 48) * 100 + (x[7] - 48) * 10 + x[8] - 48;
        }
        e[n].emplace_back(val);
    }
}

void fun(){
    ptr = stdin_ptr();
    if(size>10000000){
        std::thread Threads[std::thread::hardware_concurrency()];
        int ms=size/8;
        ps[0].first=ptr;
        for(int i=1;i<threadsSupported;++i){
            char*x= ptr + i * ms;
            while (*(x++) > 32);
            ps[i].first=x;
            ps[i-1].second=x-ps[i-1].first;
        }
        ps[threadsSupported-1].second=ptr+size-ps[threadsSupported-1].first;
        for (int i=0; i<threadsSupported; i++)
            Threads[i] = std::thread(func,i);
        for (auto & Thread : Threads)
            Thread.join();
    }
    else{
        int cnt(0);
        fast_atoi(ptr);
        k = fast_atoi(ptr);
        while (*ptr)
            if (fast_atoi(ptr) % k == 0)
                ++cnt;
        ans[0]=cnt;
    }
}
