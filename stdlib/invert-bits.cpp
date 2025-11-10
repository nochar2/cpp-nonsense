#include <cstdio>
#include <cstdint>
#include <tuple>
#include <ranges>
#include <cassert>

// -- std::ranges::views::enumerate works too

uint32_t invert_bits(uint32_t input, bool debug=false)
{
    const uint32_t masks[5] = { 0xffff0000, 0xff00ff00, 0xf0f0f0f0, 0xcccccccc, 0xaaaaaaaa };
    for (auto [i, l_mask] : std::views::enumerate(masks)) {
        uint32_t r_mask = ~l_mask;
        uint32_t shift = 1 << (4 - i);
        input = ((input & l_mask) >> shift) | ((input & r_mask) << shift);

        if (debug) printf("flip #%d:  0x%2$x %2$032b\n", i, input);
    }
    return input;
}

int main(void) {
    uint32_t a = 0x12345678;

    printf("normal:   0x%1$x %1$032b\n", a);
    printf("inverted: 0x%1$x %1$032b\n", invert_bits(a, true));

    assert (invert_bits(invert_bits(a)) == a);

    return 0;
}
