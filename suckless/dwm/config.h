/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 1;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Terminus:style=Regular:pixelsize=23:antialias=true" };
static const char dmenufont[]       = "Terminus:style=Regular:pixelsize=23:antialias=true";
#define MONOCOLOR_BACKGROUND "#111111" /*"#151000"*/
#define MONOCOLOR_NORMAL "#aaaaaa" /*"#906030"*/
#define MONOCOLOR_BRIGHT "#eeeeee" /*"#c06030"*/
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { MONOCOLOR_NORMAL, MONOCOLOR_BACKGROUND, MONOCOLOR_NORMAL}, 
	[SchemeSel]  = { MONOCOLOR_BACKGROUND, MONOCOLOR_NORMAL, MONOCOLOR_NORMAL}
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "T",      tile },    /* first entry is default */
	{ "F",      NULL },    /* no layout function means floating behavior */
	{ "M",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/bash", "-c", cmd, NULL } }

static const char cmd_vol_up[] = "pactl set-sink-volume 0 +10%";
static const char cmd_vol_dn[] = "pactl set-sink-volume 0 -10%";
static const char cmd_vol_mute[] = "pactl set-sink-mute 0 toggle";
static const char cmd_mic_mute[] = "pactl set-source-mute 1 toggle";
static const char cmd_brightness_up[] = "brightnessctl s 10%+";
static const char cmd_brightness_dn[] = "brightnessctl s 10%-";
static const char cmd_project_toggle[] = 
	"if [ `xrandr --listactivemonitors | awk '$1 == \"Monitors:\" { print $2; }'` = '1' ];"
	" then"
	"  xrandr --output HDMI-1 --auto --scale-from 1920x1080;"
	"  pactl set-card-profile 0 output:hdmi-stereo+input:analog-stereo;"
	" else"
	"  xrandr --output HDMI-1 --off;"
	"  pactl set-card-profile 0 output:analog-stereo+input:analog-stereo;"
	" fi";
static const char cmd_wifi_toggle[] = 
	"if [ `connmanctl state | awk '$1 == \"OfflineMode\" { print $3; }'` = 'False' ];"
	" then connmanctl enable offline;"
	" else connmanctl disable offline;"
	"fi";
static const char cmd_bt_toggle[] =
	"if [ `bluetoothctl show | awk '$1 == \"Powered:\" { print $2; }'` = 'yes' ];"
	" then bluetoothctl power off;"
	" else bluetoothctl power on;"
	"fi";

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
	"dmenu_run", "-m", dmenumon, 
	"-fn", dmenufont,
	"-nb", MONOCOLOR_BACKGROUND,
	"-nf", MONOCOLOR_NORMAL,
	"-sb", MONOCOLOR_NORMAL,
	"-sf", MONOCOLOR_BACKGROUND,
	NULL
};

/*static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };*/
static const char *termcmd[]  = { "st", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ 0, XF86XK_MonBrightnessDown, spawn, SHCMD(cmd_brightness_dn) },
	{ 0, XF86XK_MonBrightnessUp, spawn, SHCMD(cmd_brightness_up) },
	{ 0, XF86XK_AudioMute, spawn, SHCMD(cmd_vol_mute) },
	{ 0, XF86XK_AudioLowerVolume, spawn, SHCMD(cmd_vol_dn) },
	{ 0, XF86XK_AudioRaiseVolume, spawn, SHCMD(cmd_vol_up) },
	{ 0, XF86XK_AudioMicMute , spawn, SHCMD(cmd_mic_mute) },
	{ 0, XF86XK_WLAN, spawn, SHCMD(cmd_wifi_toggle) },
	{ 0, XF86XK_Bluetooth, spawn, SHCMD(cmd_bt_toggle) },
	{ 0, XF86XK_Display, spawn, SHCMD(cmd_project_toggle) }
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

