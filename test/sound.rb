assert 'SFML::Sound#initialize' do
  snd = SFML::Sound.new
end

assert 'SFML::Sound#initialize with Sound' do
  snd = SFML::Sound.new
  snd2 = SFML::Sound.new(snd)
end

assert 'SFML::Sound#initialize with SoundBuffer' do
  snd = SFML::Sound.new(SFML::SoundBuffer.new)
end
