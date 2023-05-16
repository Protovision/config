# define FONT_FAMILY "Terminus"
# define FONT_SIZE "22"

# define COLOR_SCHEME_LIGHT 1
# define COLOR_SCHEME_DARK 2

# define COLOR_SCHEME COLOR_SCHEME_DARK

# if COLOR_SCHEME == COLOR_SCHEME_LIGHT
	# define COLOR_BACKGROUND "#eeeeee"
	# define COLOR_NORMAL "#333333"
	# define COLOR_BRIGHT "#111111"
# elif COLOR_SCHEME == COLOR_SCHEME_DARK
	# define COLOR_BACKGROUND "#111111"
	# define COLOR_NORMAL "#cccccc"
	# define COLOR_BRIGHT "#eeeeee"
# endif

