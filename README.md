What is this project about?

Fract'ol is about creating graphically beautiful fractals with C. So what fractals mean? Fractals are complex geometric shapes that exhibit self-similar patterns at different scales. They are generated through mathematical equations and iterative processes.

The following sets are presented in the scope of this project with its real rendered images:

- MANDELBROT SET equation: F(z) = z^2 + c. Here, z represents a complex number, and c is a constant complex number (usually representing the initial point in the complex plane).

<img width="1393" alt="Screen Shot 2024-05-14 at 3 24 00 PM" src="https://github.com/hienptx/42_fractol/assets/147611378/439064de-493c-4912-8a01-26bf5df2aa34">

- JULIA SET is closely related to Mandelbrot set, which set under surtain conditions. For example, to turn Mandelbrot to Julia, the value of c (start position) is defined beforehand.

<img width="1199" alt="Screen Shot 2024-05-15 at 6 27 31 PM" src="https://github.com/hienptx/42_fractol/assets/147611378/5407a632-eae0-48a3-856e-c8a24f09d010">

<img width="1193" alt="Screen Shot 2024-05-15 at 6 29 08 PM" src="https://github.com/hienptx/42_fractol/assets/147611378/da89a42c-d439-4a38-be2b-db184f4eb72d">

- BURNING SHIP is as well as the next variation of Mandelbrot set. Instead of squaring the complex number and adding the initial point (as in the Mandelbrot set), the Burning Ship fractal squares the absolute values of the real and imaginary parts separately and then adds the initial point.

<img width="1194" alt="Screen Shot 2024-05-15 at 6 34 16 PM" src="https://github.com/hienptx/42_fractol/assets/147611378/e3277a54-f730-4fb6-ab9a-c0a78c3377c2">


This project utilizes an existed graphic-library named MLX42 (Repo: https://github.com/codam-coding-college/MLX42.git).

Resource links:

- To theoretical explaination of plotting mandelbrot set: https://toddthomas.space/2020/12/14/render-the-mandelbrot-set-in-higher-resolution.html
- Mandelbrot plottling online program: https://www.desmos.com/calculator/x2lwsvuqw7
- To different presentation of Julia sets: https://en.wikipedia.org/wiki/Julia_set
