module SFML
  class SoundRecorder
    class << self
      alias :available_devices :get_available_devices
      alias :default_device :get_default_device
    end
  end
end
