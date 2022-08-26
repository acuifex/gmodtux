#include "hooks.h"

typedef void (*ReadPixelsFn) (void*, int, int, int, int, unsigned char *, ImageFormat);

// render.capture uses IMAGE_FORMAT_BGRA8888
// also bug in render.capture? it calls context->begin if context is not null but calls the rest of the functions anyway
// data capacity is format_size * width * height
void Hooks::ReadPixels(void* thisptr, int x, int y, int width, int height, unsigned char *data, ImageFormat dstFormat)
{
	cvar->ConsoleDPrintf("\nreadpixels event: x %d, y %d, width %d, height %d, format %d\n",
						 x, y, width, height, dstFormat);
	matRenderContextVMT->GetOriginalMethod<ReadPixelsFn>(11)(thisptr, x, y, width, height, data, dstFormat);
}

