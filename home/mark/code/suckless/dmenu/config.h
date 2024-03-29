/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

# include"../config.h"

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	FONT_FAMILY ":pixelsize=" FONT_SIZE
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
static const char *colors[SchemeLast][2] = {
	/*     fg         bg       */
	[SchemeNorm] = { COLOR_NORMAL, COLOR_BACKGROUND },
	[SchemeSel] = { COLOR_BACKGROUND, COLOR_BRIGHT },
	[SchemeOut] = { COLOR_BACKGROUND, COLOR_BRIGHT },
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 64;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";
