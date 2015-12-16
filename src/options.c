#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

#if HAVE_CONFIG_H
#include "config.h"
#endif

#include "options.h"

void print_version()
{
	printf("PACKAGE NAME: '%s'\n", PACKAGE_NAME);
	printf("PACKAGE TARNAME: '%s'\n", PACKAGE_TARNAME);
	printf("PACKAGE VERSION: '%s'\n", PACKAGE_VERSION);
	printf("PACKAGE STRING: '%s'\n", PACKAGE_STRING);
	printf("PACKAGE BUGREPORT: '%s'\n", PACKAGE_BUGREPORT);
	printf("PACKAGE_URL: '%s'\n", PACKAGE_URL);
	printf("CHANGESET: '%s'\n", CHANGESET);
}

static struct option opts[] = {
	{"help", no_argument, 0, 'h'},

	{"argument-requiered", required_argument, 0, 'a'},
	{"no-argument", no_argument, 0, 'n'},
	{"optional", optional_argument, 0, 'o'},

	{0, 0, 0, 0}
};

void print_usage(char * bin)
{
	int i;
	printf("usage:\n");
	printf("\t%s", bin);
	for (i = 0; i < (sizeof(opts)/sizeof(opts[0]) -1); i++) {
		printf(" [--%s", opts[i].name);
		if (opts[i].has_arg == required_argument)
			printf(" %s", opts[i].name);
		if (opts[i].has_arg == optional_argument)
			printf(" [%s]", opts[i].name);
		printf("]");
	}
	printf("\n");
}

int parse_opts(int argc, char **argv)
{
	int index, opt;
	while ((opt = getopt_long(argc, argv, "hvH:W:", opts, &index)) != -1) {
		switch (opt) {
		case 'a':
			break;
		case 'n':
			break;
		case 'o':
			break;
		case '?':
			break;
		case 'h':
		default:
			print_usage(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	return 0;
}
