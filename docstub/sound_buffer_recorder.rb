module SFML
  # Specialized SoundRecorder which stores the captured
  # audio data into a sound buffer
  class SoundBufferRecorder < SoundRecorder
    def initialize
    end

    # @return [SoundBuffer]
    def get_buffer
    end

    alias :buffer :get_buffer
  end
end
