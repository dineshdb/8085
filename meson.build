project('8085', 'cpp')

my_inc = include_directories('include')

gtkmmdep = dependency('gtkmm-3.0')

src = ['src/main.cc']
executable('8085', src,  include_directories : my_inc, dependencies : gtkmmdep)
