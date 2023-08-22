# define BATCH_SHELL "/bin/dash"
# define INTERACTIVE_SHELL "/bin/yash"
# define FONT_FAMILY "Terminus"
# define FONT_SIZE "24"

# define COLOR_SCHEME_LIGHT 1
# define COLOR_SCHEME_DARK 2
# define COLOR_SCHEME_MATRIX 3

# define COLOR_SCHEME COLOR_SCHEME_MATRIX

# if COLOR_SCHEME == COLOR_SCHEME_LIGHT
	# define COLOR_BACKGROUND "#eeeeee"
	# define COLOR_NORMAL "#333333"
	# define COLOR_BRIGHT "#111111"
# elif COLOR_SCHEME == COLOR_SCHEME_DARK
	# define COLOR_BACKGROUND "#111111"
	# define COLOR_NORMAL "#cccccc"
	# define COLOR_BRIGHT "#eeeeee"
# elif COLOR_SCHEME == COLOR_SCHEME_MATRIX
	# define COLOR_BACKGROUND "#000000"
	# define COLOR_NORMAL "#33bb77"
	# define COLOR_BRIGHT "#77ffbb"
# endif

