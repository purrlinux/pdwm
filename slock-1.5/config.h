/* user and group to drop privileges to */
static const char *user  = "nobody";
static const char *group = "nobody";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "#1f1a1b",     /* after initialization */
	[INPUT] =  "#2f2a2b",   /* during input */
	[FAILED] = "#d63e3e",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;
