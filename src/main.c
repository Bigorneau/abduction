#include <unistd.h>

#include <SDL2/SDL.h>

#if HAVE_CONFIG_H
#include "config.h"
#endif

#include "options.h"

int main(int argc, char **argv)
{
	print_version();
	if (parse_opts(argc, argv) < 0)
		return -1;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("%s: SDL_Init failed, '%s'\n", __FUNCTION__, SDL_GetError());
		return -1;
	}
	SDL_Window *window = SDL_CreateWindow(PACKAGE_NAME, 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		printf("woops\n");
	}
	sleep(10);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
