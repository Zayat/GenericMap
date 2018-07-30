#include <math.h>

#include "generic_map.h"

// Adapted from the HashHelpers class from the c# reference source.
// source: https://github.com/Microsoft/referencesource/blob/master/mscorlib/system/collections/hashtable.cs (it can be found at the bottom of the file).
// license: https://github.com/Microsoft/referencesource/blob/master/LICENSE.txt

uint32_t primes[] = {
    3,
    7, 
    11, 
    17, 
    23, 
    29, 
    37, 
    47, 
    59, 
    71, 
    89, 
    107, 
    131, 
    163, 
    197, 
    239, 
    293, 
    353, 
    431, 
    521, 
    631, 
    761, 
    919,
    1103, 
    1327, 
    1597, 
    1931, 
    2333, 
    2801, 
    3371, 
    4049, 
    4861, 
    5839, 
    7013, 
    8419, 
    10103, 
    12143, 
    14591,
    17519, 
    21023, 
    25229, 
    30293, 
    36353, 
    43627, 
    52361, 
    62851, 
    75431, 
    90523, 
    108631, 
    130363, 
    156437,
    187751,
    225307, 
    270371, 
    324449, 
    389357, 
    467237,
    560689, 
    672827, 
    807403, 
    968897, 
    1162687, 
    1395263,
    1674319, 
    2009191, 
    2411033, 
    2893249, 
    3471899, 
    4166287, 
    4999559, 
    5999471, 
    7199369
};

static bool isPrime(int candidate) {
    uint32_t limit = (uint32_t)sqrt(candidate);
    for(uint32_t divisor = 3; divisor < limit; divisor += 2) {
        if((candidate % divisor) == 0)
            return false;
    }
    return true;
}

uint32_t getPrime(uint32_t value) {
    for(uint32_t i = 0; i < 71; i++) {
        uint32_t prime = primes[i];
        if(prime >= value)
            return prime;
    }
    for(uint32_t i = 7199371; i < UINT32_MAX; i += 2) {
        if(isPrime(i))
            return i;
    }
    return value;
}