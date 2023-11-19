
#define UP(x) (x >> 16)      // 16 upper bits
#define LO(x) (x & 0xFFFF)   // 16 lower bits

/**
 * Given:
 *  x = x1 * 2^16 + x0
 *  y = y1 * 2^16 + y0
 * Compute:
 *  z = x * y
 * Return:
 *  z[1]: 32 upper bits
 *  z[0]: 32 lower bits
*/
void mult32(unsigned int *z, unsigned int x, unsigned int y) {
	unsigned int x1 = UP(x);
	unsigned int x0 = LO(x);
	unsigned int y1 = UP(y);
	unsigned int y0 = LO(y);

    unsigned int t;
    // z = z3 * 2^48 + z2 * 2^32 + z1 * 2^16 + z0
    // z[1] = z3 * 2^16 + z2 
    // z[0] = z1 * 2^16 + z0
    unsigned int z3, z2, z1, z0; 
    t = x0 * y0;
    z0 = LO(t);
    
    z1 = UP(t);
    t = x0 * y1 + z1;
    z1 = LO(t);
    z2 = UP(t);

    t = x1 * y0 + z1;
    z1 = LO(t);
    z2 = UP(t) + z2;
    t = x1 * y1 + z2;
    // z2 = LO(t);
    // z3 = UP(t);
    
    z[1] = t;
    // z[1] = (z3 << 16) | z2;
    z[0] = (z1 << 16) | z0;
}
