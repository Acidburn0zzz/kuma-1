#ifndef _TEXT_H_
#define _TEXT_H_

#include <SDL_ttf.h>
#include <iostream>
#include <stdint.h>
#include <string>
#include <tuple>

#include "SDL_pixels.h"
#include "drawable.h"
#include "exception.h"
#include "posable.h"
#include "rect.h"
#include "sdl_smart_ptr.h"
#include "texture.h"
#include "util.h"
#include "window.h"

namespace kuma {
	class Timer;
	class Window;

	class Text : public AnimatedDrawable, Posable {
	public:
		Text();
		Text(const std::string &path, const int size);
		Text(const std::string &path, const int size, Window &window, int col_width, int x,
		     int y);
		void open_font(const std::string &path, const int size);
		void set_color(const uint8_t R, const uint8_t G, const uint8_t B, const uint8_t A);
		void set_text(const std::string &text, Window &window);
		std::string get_text() const;
		void set_text_from_int(int num);
		void set_text_from_float(float num);
		void set(Window &window, int col_width);
		void set_position(int x, int y);
		void generate_texture(Window &window);
		void draw(Window &window, const Timer &timer);
		bool is_changed();
		Rect &get_rect();
		Rect rect;
		Texture texture;

	private:
		int column_width = 0;
		std::string inner_text;
		SDL_Color font_color;
		SharedTextPtr font;
		SharedSurfacePtr temp_surface;
	};
}

#endif // _TEXT_H_
