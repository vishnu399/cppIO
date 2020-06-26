#ifndef CPPIO_FASTATOI_H
#define CPPIO_FASTATOI_H
namespace fast_atoi {
    static inline int readInteger() {
        struct X {
            bool charMap[256];
            X() {
                for (int i = 48; i <= 57; ++i) charMap[i] = true;
                charMap['-'] = true;
            }
        };
        static X f;
        int v = 0, c;
        bool s = true;
        while(!f.charMap[c = getchar()]);
        if (c == '-') s = false; else if (f.charMap[c]) v = c ^ 48;
        for (; f.charMap[c = getchar()]; v = (v << 1) + (v << 3) + (c ^ 48));
        return s ? v : -v;
    }
}
#endif //CPPIO_FASTATOI_H
