#include <math.h>
#include <stdint.h>

#define STBI_NO_SIMD
#define STB_IMAGE_IMPLEMENTATION
#include "https://raw.githubusercontent.com/nothings/stb/master/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "https://raw.githubusercontent.com/nothings/stb/master/stb_image_write.h"

#define COMP 4

uint32_t grayscale(uint32_t pixel)
{
    const uint8_t b = (pixel & 0x00FF0000) >> 8 * 2;
    const uint8_t g = (pixel & 0x0000FF00) >> 8 * 1;
    const uint8_t r = (pixel & 0x000000FF) >> 8 * 0;
    uint8_t max = 0;
    if (max < b)
        max = b;
    if (max < g)
        max = g;
    if (max < r)
        max = r;
    return 0xFF000000 | (max << (8 * 2)) | (max << (8 * 1)) | (max << (8 * 0));
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        assert(argc >= 1);
        fprintf(stderr, "Usage: %s <input> <output>\n", argv[0]);
        fprintf(stderr, "ERROR: No input or output file specified\n");
        exit(1);
    }

    const char *input_filepath = argv[1];
    const char *output_filepath = argv[2];

    int w, h, n;
    uint32_t *pixels = (uint32_t *)stbi_load(input_filepath, &w, &h, &n, COMP);

    printf("File path: %s\n", input_filepath);
    printf("Loaded image with dimensions %dx%d and %d channels\n", w, h, n);

    for (size_t i = 0; i < w * h; i++)
    {
        pixels[i] = grayscale(pixels[i]);
    }

    if (!stbi_write_png(output_filepath, w, h, COMP, pixels, w * COMP))
    {
        fprintf(stderr, "ERROR: Could not write to file %s\n", output_filepath);
        exit(1);
    }

    return 0;
}