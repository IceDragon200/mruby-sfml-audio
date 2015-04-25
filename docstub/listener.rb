module SFML
  # The listener.
  module Listener
    # @param [Float] volume
    def self.set_global_volume(volume)
    end

    # @return [Float]
    def self.get_global_volume
    end

    # @overload set_position(position)
    #   @param [Vector3f] position
    # @overload set_position(x, y, z)
    #   @param [Float] x
    #   @param [Float] y
    #   @param [Float] z
    def self.set_position(*args)
    end

    # @return [Vector3f]
    def self.get_position
    end

    # @overload set_direction(position)
    #   @param [Vector3f] position
    # @overload set_direction(x, y, z)
    #   @param [Float] x
    #   @param [Float] y
    #   @param [Float] z
    def self.set_direction(*args)
    end

    # @return [Vector3f]
    def self.get_direction
    end

    # @overload set_up_vector(position)
    #   @param [Vector3f] position
    # @overload set_up_vector(x, y, z)
    #   @param [Float] x
    #   @param [Float] y
    #   @param [Float] z
    def self.set_up_vector(*args)
    end

    # @return [Vector3f]
    def self.get_up_vector
    end
  end
end
