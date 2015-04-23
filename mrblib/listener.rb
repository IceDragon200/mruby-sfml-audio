module SFML
  module Listener
    class << self
      alias :global_volume= :set_global_volume
      alias :global_volume :get_global_volume
      alias :position= :set_position
      alias :position :get_position
      alias :direction= :set_direction
      alias :direction :get_direction
      alias :up_vector= :set_up_vector
      alias :up_vector :get_up_vector
    end
  end
end
