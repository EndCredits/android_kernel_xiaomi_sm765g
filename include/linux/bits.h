/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __LINUX_BITS_H
#define __LINUX_BITS_H

#include <linux/const.h>
#ifdef __GENKSYMS__
#include <vdso/bits.h>
/*
 * Old version of this macro to preserve the CRC signatures of some drm symbols.
 * Crazy but true...
 */
#define BIT_ULL(nr)		(1ULL << (nr))
#define BIT_MASK(nr)		(1UL << ((nr) % BITS_PER_LONG))
#else
#include <asm/bitsperlong.h>

#define BIT(nr)                        (UL(1) << (nr))
#define BIT_ULL(nr)		(ULL(1) << (nr))
#define BIT_MASK(nr)		(UL(1) << ((nr) % BITS_PER_LONG))
#endif
#define BIT_WORD(nr)		((nr) / BITS_PER_LONG)
#define BIT_ULL_MASK(nr)	(ULL(1) << ((nr) % BITS_PER_LONG_LONG))
#define BIT_ULL_WORD(nr)	((nr) / BITS_PER_LONG_LONG)
#define BITS_PER_BYTE		8

/*
 * Create a contiguous bitmask starting at bit position @l and ending at
 * position @h. For example
 * GENMASK_ULL(39, 21) gives us the 64bit vector 0x000000ffffe00000.
 */
#define GENMASK(h, l) \
	(((~UL(0)) - (UL(1) << (l)) + 1) & \
	 (~UL(0) >> (BITS_PER_LONG - 1 - (h))))

#define GENMASK_ULL(h, l) \
	(((~ULL(0)) - (ULL(1) << (l)) + 1) & \
	 (~ULL(0) >> (BITS_PER_LONG_LONG - 1 - (h))))

#endif	/* __LINUX_BITS_H */
