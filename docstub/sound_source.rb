module SFML
  class SoundSource < AlResource
    # Whether the sound is stopped, paused or currently playing.
    module Status
      # @return [Integer]
      Stopped = 0
      # @return [Integer]
      Paused  = 1
      # @return [Integer]
      Playing = 2
    end

    # @param [Float] pitch
    # @return [self]
    def set_pitch(pitch)
    end

    # @param [Float] volume
    # @return [self]
    def set_volume(volume)
    end

    # @overload set_position(position)
    #   @param [Vector3f] position
    # @overload set_position(x, y, z)
    #   @param [Float] x
    #   @param [Float] y
    #   @param [Float] z
    # @return [self]
    def set_position(*args)
    end

    # @param [Boolean] bool
    # @return [self]
    def set_relative_to_listener(bool)
    end

    # @param [Float] distance
    # @return [self]
    def set_min_distance(distance)
    end

    # @param [Float] attenuation
    # @return [self]
    def set_attenuation(attenuation)
    end

    # @return [Float]
    def get_pitch
    end

    # @return [Float]
    def get_volume
    end

    # @return [Vector3f]
    def get_position
    end

    # @return [Boolean]
    def is_relative_to_listener
    end

    # @return [Float]
    def get_min_distance
    end

    # @return [Float]
    def get_attenuation
    end

    alias :pitch= :set_pitch
    alias :volume= :set_volume
    alias :position= :set_position
    alias :relative_to_listener= :set_relative_to_listener
    alias :min_distance= :set_min_distance
    alias :attenuation= :set_attenuation
    alias :pitch :get_pitch
    alias :volume :get_volume
    alias :position :get_position
    alias :relative_to_listener? :is_relative_to_listener
    alias :min_distance :get_min_distance
    alias :attenuation :get_attenuation
  end
end
