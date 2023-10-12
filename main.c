#include <math.h>

#define STBI_NO_SIMD
#define STB_IMAGE_IMPLEMENTATION
#define HTTP_INCLUDE
#ifdef HTTP_INCLUDE
#include "https://raw.githubusercontent.com/nothings/stb/master/stb_image.h"
#else
#include "./stb_image.h"
#endif

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        assert(argc >= 1);
        fprintf(stderr, "Usage: %s <image-file>\n", argv[0]);
        fprintf(stderr, "ERROR: No input file specified\n");
        exit(1);
    }

    const char *input_filepath = argv[1];

    int x, y, n;
    unsigned char *pixels = stbi_load(input_filepath, &x, &y, &n, 0);

    printf("File path: %s\n", input_filepath);
    printf("Loaded image with dimensions %dx%d and %d channels\n", x, y, n);

    return 0;
}