module SFML
  # Abstract base class for capturing sound data
  class SoundRecorder < AlResource
    # @param [Integer] sample_rate
    # @return [self]
    def start(sample_rate)
    end

    # @return [self]
    def stop
    end

    # @return [Integer]
    def get_sample_rate
    end

    # @param [String] device
    # @return [Boolean]
    def set_device(device)
    end

    # Returns the name of the device being used by this SoundRecorder
    #
    # @return [String]
    def get_device
    end

    alias :sample_rate :get_sample_rate
    alias :device= :set_device
    alias :device :get_device
  end
end
