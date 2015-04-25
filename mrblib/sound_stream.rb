module SFML
  class SoundStream
    # @return [Boolean]
    def stopped?
      get_status == SoundSource::Status::Stopped
    end

    # @return [Boolean]
    def paused?
      get_status == SoundSource::Status::Paused
    end

    # @return [Boolean]
    def playing?
      get_status == SoundSource::Status::Playing
    end
  end
end
