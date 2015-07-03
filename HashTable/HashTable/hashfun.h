#ifndef C_HASHFUN_H
#define C_HASHFUN_H

extern "C" unsigned int BKDRHash(char *str);    //注:写成extern "C" BKDRHash(char *str); 也可以
extern "C" unsigned int SDBMHash(char *str);

#endif
