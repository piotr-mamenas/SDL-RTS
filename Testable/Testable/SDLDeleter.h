#include <memory>
#include <SDL.h>

namespace sdl2 {
	struct SDLDeleter {
		void operator()(SDL_Surface* surfacePtr) { if (surfacePtr) SDL_FreeSurface(surfacePtr); }
		void operator()(SDL_Texture* texturePtr) { if (texturePtr) SDL_DestroyTexture(texturePtr); }
		void operator()(SDL_Renderer* rendererPtr) { if (rendererPtr) SDL_DestroyRenderer(rendererPtr); }
		void operator()(SDL_Window* windowPtr) { if (windowPtr) SDL_DestroyWindow(windowPtr); }
	};

	template<class T, class D = std::default_delete<T>>
	struct sdl2_shared_ptr : public std::shared_ptr<T>
	{
		explicit sdl2_shared_ptr(T* t = nullptr)
			: std::shared_ptr<T>(t, D()) {}

		void reset(T* t = nullptr) {
			std::shared_ptr<T>::reset(t, D());
		}
	};

	using SurfacePtr = std::unique_ptr<SDL_Surface, SDLDeleter>;
	using TexturePtr = std::unique_ptr<SDL_Texture, SDLDeleter>;
	using RendererPtr = std::unique_ptr<SDL_Texture, SDLDeleter>;
	using WindowPtr = std::unique_ptr<SDL_Window, SDLDeleter>;

	using SurfaceSharedPtr = sdl2_shared_ptr<SDL_Surface, SDLDeleter>;
	using TextureSharedPtr = sdl2_shared_ptr<SDL_Texture, SDLDeleter>;
	using RendererSharedPtr = sdl2_shared_ptr<SDL_Renderer, SDLDeleter>;
	using WindowSharedPtr = sdl2_shared_ptr<SDL_Window, SDLDeleter>;
}