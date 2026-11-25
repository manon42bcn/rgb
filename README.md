# RGB Library #
```
@@@@@@@@@@@@@@@@@@@@@@@@@@@                          %@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@           @@@@@          %@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@*                 @@@@@@      @@@@@@@@@@@@@@@     %@@@                 @@@@@@
@@@*                   @@@@    @@@@@@@@@@@@@@@@@@@   %@@@                   @@@@
@@@*      @@@@@@@       @@@   @@@@@@@      *@@@@@@@  %@@@      @@@@@@@#      @@@
@@@*      @@@@@@@@       @@  /@@@@@@         @@@@@@# %@@@      @@@@@@@@@      @@
@@@*      @@@@@@@@@      @@  /@@@@@@         @@@@@@# %@@@      @@@@@@@@@      @@
@@@*      @@@@@@@@@      @@  /@@@@@@                 %@@@      @@@@@@@@@      @@
@@@*      @@@@@@@@      @@@  /@@@@@@                 %@@@      @@@@@@@       @@@
@@@*      @@@@@@       @@@@  /@@@@@@   @@@@@@@@@@@@  %@@@                  @@@@@
@@@*                 @@@@@@  /@@@@@@   #@@@@@@@@@@@# %@@@                  @@@@@
@@@*               @@@@@@@@  /@@@@@@   #@@@@@@@@@@@# %@@@      @@@@@@@       @@@
@@@*      @@@@      @@@@@@@  /@@@@@@         @@@@@@# %@@@      @@@@@@@@@      @@
@@@*      @@@@@      @@@@@@  /@@@@@@         @@@@@@# %@@@      @@@@@@@@@      @@
@@@*      @@@@@@      @@@@@  /@@@@@@         @@@@@@# %@@@      @@@@@@@@@      @@
@@@*      @@@@@@@      @@@@  /@@@@@@         @@@@@@# %@@@      @@@@@@@@#      @@
@@@*      @@@@@@@@      @@@   @@@@@@@&      @@@@@@@  %@@@      @@@@@@&       @@@
@@@*      @@@@@@@@       @@    @@@@@@@@@@@@@@@@@@@   %@@@                   @@@@
@@@*      @@@@@@@@@      (@      @@@@@@@@@@@@@@@     %@@@                @@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@           @@@@@          %@@@@@@@@@@@@@@@@@@@@@@@@@@


```

This is a C library designed to provide various operations for RGB color manipulation. It supports a variety of arithmetic and utility operations to help developers easily manage and process RGB colors.

Some useful resources to understand this library:
* https://en.wikipedia.org/wiki/RGB_color_model *
* http://www.easyrgb.com/en/math.php *
* https://en.wikipedia.org/wiki/Phong_reflection_model *

## Functions ##
### Arithmetic Operations ###
- `ft_rgb_dot(t_rgb color, double alpha):` Multiplies the components (R, G, B) of an RGB color by a scalar value, alpha.
- `ft_rgb_add(t_rgb ca, t_rgb cb):` Adds the RGB components of two colors together.
- `ft_rgb_light(t_rgb color, double rgb[3]):` Adjusts an RGB color based on a lighting array. This function multiplies the RGB components by the values in the lighting array.
- `ft_rgb_diff(t_rgb ca, t_rgb cb):` Calculates the difference between two RGB colors. If the sum of squared differences exceeds a threshold, it returns true.

### Utilities ###
- `ft_rgb_avg(t_rgb ca, t_rgb cb):` Computes the average of two RGB colors.
- `ft_rgb_balance(t_rgb *rgb):` Balances an array of four RGB colors, computing their average.
- `ft_invert_color(t_rgb original):` Invert a given color.
- `ft_rgb_get(t_rgb color[3])`: Return t_rgb color from RGB color.

### Interpolation ###

- `ft_rgb_lerp_linear(start, end, factor)` blends packed sRGB colors in
  linear light.
- `ft_rgb_lerp_oklab(start, end, factor)` blends the same colors in
  the perceptual [Oklab space](https://bottosson.github.io/posts/oklab/).

A factor of 0 returns the first color, and 1 returns the second.
For example, at 0.5, the linear-light midpoint of black and white is
`0xBCBCBC`, and the Oklab midpoint is `0x636363`.

## Usage ##

Run `make` to build `librgb.a`. Include `inc/rgb.h` and link with
`librgb.a -lm` when using the interpolation functions.