#ifndef chapter5_h
#define chapter5_h

// time: O(n) space: O(n)
int copy_inside(unsigned int n, unsigned int m, unsigned int i, unsigned int j) {
    
    // compute length of m
    unsigned int c, v = m;
    for (c = 0; v; c++) v &= (v - 1);
    
    if (c > (j - i + 1)) return -1;
    if (i > j) return -1;
    if (i == j) return n;
    
    unsigned int filter = 0;
    for (int k = i; k <= j; k++) filter |= (0x1 << k);
    
    n &= ~filter;
    n |= (m << i);
    
    return n;
}

///////////////

// time: O(1) space: O(n) - 5 instructions
unsigned int swap_bits(unsigned int x) {
    return ((x & 0xAAAA) >> 0x1) | ((x & 0x5555) << 0x1);
}

///////////////

// time: O(n) space: O(1)

#endif
