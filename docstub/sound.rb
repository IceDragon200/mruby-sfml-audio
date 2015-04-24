module SFML
  class Sound < SoundSource
    # @overload initialize
    # @overload initialize(sound)
    #   @param [Sound] sound
    # @overload initialize(sound_buffer)
    #   @param [SoundBuffer] sound_buffer
    def initialize(*o)
    end

    # @param [Sound] other
    # @return [self]
    def initialize_copy(other)
    end

    # @return [self]
    def play
    end

    # @return [self]
    def pause
    end

    # @return [self]
    def stop
    end

    # @param [SoundBuffer] buffer
    # @return [self]
    def set_buffer(buffer)
    end

    # @param [Boolean] bool
    # @return [self]
    def set_loop(bool)
    end

    # @param [SFML::Time] time
    def set_playing_offset(time)
    end

    # @return [SoundBuffer]
    def get_buffer
    end

    # @return [Boolean]
    def get_loop
    end

    # @return [SFML::Time]
    def get_playing_offset
    end

    # @return [SoundSource::Status]
    def get_status
    end

    alias :buffer= :set_buffer
    alias :loop= :set_loop
    alias :playing_offset= :set_playing_offset
    alias :buffer :get_buffer
    alias :loop? :get_loop
    alias :playing_offset :get_playing_offset
    alias :status :get_status
  end
end
