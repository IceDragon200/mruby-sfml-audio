module SFML
  # Streamed music played from an audio file.
  class Music < SoundStream
    def initialize
    end

    # @param [String] filename
    # @return [self]
    def open_from_file(filename)
    end

    # @return [SFML::Time]
    def get_duration
    end

    alias :duration :get_duration
  end
end
