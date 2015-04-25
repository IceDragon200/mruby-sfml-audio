module SFML
  # Abstract base class for streamed audio sources
  class SoundStream < SoundSource
    # @return [self]
    def play
    end

    # @return [self]
    def pause
    end

    # @return [self]
    def stop
    end

    # @return [Integer]
    def get_channel_count
    end

    # @return [Integer]
    def get_sample_rate
    end

    # @return [SoundSource::Status]
    def get_status
    end

    # @param [SFML::Time] time
    # @return [self]
    def set_playing_offset(time)
    end

    # @return [SFMLTime]
    def get_playing_offset
    end

    # @param [Boolean] bool
    # @return [self]
    def set_loop(bool)
    end

    # @return [Boolean]
    def get_loop
    end

    alias :channel_count :get_channel_count
    alias :sample_rate :get_sample_rate
    alias :status :get_status
    alias :playing_offset= :set_playing_offset
    alias :playing_offset :get_playing_offset
    alias :loop= :set_loop
    alias :loop? :get_loop
  end
end
