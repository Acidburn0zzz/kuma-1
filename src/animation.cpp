#include "animation.h"
#include "window.h"

void Animation::next_frame() {
	frames.push_back(frames.front());
	frames.pop_front();
}

void Animation::prev_frame() {
	frames.push_front(frames.back());
	frames.pop_back();
}

void Animation::render_front(Window &window, Texture &texture, Rect &dest) {
	SDL_RenderCopy(window.get_renderer(), texture.get_sdl_texture(),
		       frames.front().get_sdl_rect(), dest.get_sdl_rect());
}


void Animation::render_front(Window &window, Texture &texture, Rect &dest,
			     double angle) {
	SDL_RenderCopyEx(window.get_renderer(), texture.get_sdl_texture(),
			 frames.front().get_sdl_rect(), dest.get_sdl_rect(),
			 angle, nullptr, SDL_RendererFlip::SDL_FLIP_NONE);
}

void Animation::set_sound(std::string path, unsigned audio_rate) {
	sound = Chunk(path);
	sound_rate = audio_rate;
}

void Animation::play_sound(Mixer &mixer) { mixer.play(sound); }

Animation &Animation::operator=(const Animation &copy) {
	frames = copy.frames;
	sound = copy.sound;
	rate = copy.rate;
	sound_rate = copy.sound_rate;
	return *this;
}
