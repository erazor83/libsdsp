/*
 * Copyright (C) 2013 Alexander Krause <alexander.krause@ed-solutions.de>
 */


#ifndef _SDSP_PRIVATE_H_
#define _SDSP_PRIVATE_H_

#ifndef _MSC_VER
# include <stdint.h>
# include <sys/time.h>
#else
# include "stdint.h"
# include <time.h>
typedef int ssize_t;
#endif
#include <sys/types.h>

#include "sdsp.h"

typedef struct _sdsp_display_calls {
		
	int (*init) (sdsp_t *ctx);
	int (*detect) (sdsp_t *ctx);
	int (*invert) (sdsp_t *ctx);
	int (*test) (sdsp_t *ctx);
	
	int (*clear) (sdsp_t *ctx);
	int (*set_pixel) (sdsp_t *ctx);
	
	int (*buffer_draw) (sdsp_t *ctx);
	int (*buffer_clear) (sdsp_t *ctx);

	
} sdsp_display_calls_t;

struct _sdsp {
	uint8_t width;
	uint8_t height;
	const char* type_name;
	uint16_t features;


	int8_t (*free) (sdsp_t *ctx);
	/* Socket or file descriptor */
	bool debug;
	void *display_data;
	void *display_calls;
};

//void _sdsp_init_common(sdsp_t *ctx);
void sdsp_free(sdsp_t *ctx);

void _sdsp_print_debug(sdsp_t *ctx, const char *txt);

#ifndef HAVE_STRLCPY
size_t strlcpy(char *dest, const char *src, size_t dest_size);
#endif


#endif  /* _SDSP_PRIVATE_H_ */