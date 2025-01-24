when eval, git clone the minilibx first then make

valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt
valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./fractol mandelbrot
valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./fractol julia -0.37 0.6 // 0.285 -0.01
valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./fractol burning_ship 

norminette helper.c mandelbrot.c julia.c fractol.h fractol.c burning.c
