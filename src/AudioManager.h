#include <SFML/Audio.hpp>

class AudioManager
{
public:
	AudioManager();

	void SetAudio(bool value);

private:
	sf::SoundBuffer _buffer;
};