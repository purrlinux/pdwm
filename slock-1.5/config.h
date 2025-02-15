/* user and group to drop privileges to */
static const char *user  = "nobody";
static const char *group = "nogroup";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "#1f1a1b",     /* after initialization */
	[INPUT] =  "#ffb0cb",   /* during input */
	[FAILED] = "#d63e3e",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;
