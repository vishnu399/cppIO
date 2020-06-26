#ifndef CPPIO_FASTERIO_H
#define CPPIO_FASTERIO_H
namespace faster_atoi {
    static char inputString[1024], *stdinDataEnd = inputString + 1024;
    static const char *stdinPos = stdinDataEnd;

    struct __X {
        bool charMap[256]{}, charMapString[256]{}, eofReached = false, s = true;

        __X() {
            for (int i = 48; i < 58; charMap[i++] = true);
            charMap[45] = charMapString[32] = charMapString[10] = charMapString[13] = charMapString[9] = 1;
        }

        __attribute__((always_inline))inline void __readAhead() {
            size_t remainingChar = stdinDataEnd - stdinPos;
            if (remainingChar < 24) {
                memcpy(inputString, stdinPos, remainingChar);
                size_t sz = fread(inputString + remainingChar, 1, 1024 - remainingChar, stdin);
                stdinPos = inputString;
                stdinDataEnd = inputString + remainingChar + sz;
                if (stdinDataEnd != inputString + 1024)
                    *stdinDataEnd = 0;
            }
            if (stdinPos == stdinDataEnd)
                eofReached = true;
        }

        __attribute__((always_inline))inline char __nextChar() {
            if (!(stdinDataEnd - stdinPos))
                __readAhead();
            return *(stdinPos++);
        }

        __attribute__((always_inline))inline __X &operator,(char &x) {
            if (!eofReached)
                for (x = __nextChar(); !eofReached && charMapString[x]; x = __nextChar());
            return *this;
        }

        __attribute__((always_inline))inline __X &operator,(char *x) {
            if (!eofReached) {
                char _t = __nextChar();
                for (; !eofReached && charMapString[_t]; _t = __nextChar());
                if (_t)
                    for (; _t && !charMapString[_t]; _t = __nextChar())
                        *x++ = _t;
                *x = 0;
            }
            return *this;
        }

        __attribute__((always_inline))inline __X &operator,(std::string &x) {
            x = "";
            if (!eofReached) {
                char _t = __nextChar();
                for (; !eofReached && charMapString[_t]; _t = __nextChar());
                if (_t)
                    for (; _t && !charMapString[_t]; _t = __nextChar())
                        x += _t;
            }
            return *this;
        }

        template<class T>
        __attribute__((always_inline))inline __X &operator,(T &x) {
            if (!eofReached) {
                x = s = false;
                __readAhead();
                while (!charMap[*stdinPos])__readAhead(), ++stdinPos;
                if (*stdinPos == '-')s = 1; else x = (*stdinPos & 15);
                ++stdinPos;
                while (charMap[*stdinPos])x = (x << 1) + (x << 3) + (*(stdinPos++) & 15);
                if (s)x = -x;
            }
            return *this;
        }
    } in;
}
#endif //CPPIO_FASTERIO_H
