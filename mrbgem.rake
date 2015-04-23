MRuby::Gem::Specification.new('mruby-sfml-audio') do |spec|
  spec.license = 'MIT'
  spec.authors = ['Corey Powell']
  spec.version = '2.2.0.0'
  spec.summary = 'SFML Audio binding'
  spec.description = 'SFML Audio binding'
  spec.homepage = 'https://github.com/IceDragon200/mruby-sfml-audio'

  spec.add_dependency 'mruby-sfml-system', github: 'IceDragon200/mruby-sfml-system'
end
