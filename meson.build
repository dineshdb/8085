project('8085', 'cpp')

my_inc = include_directories('include')
gtkmmdep = dependency('gtkmm-3.0', required : false)

parserSrc = ['src/parser.cc']
libParser = shared_library('myparser', parserSrc, include_directories:my_inc)

sharedSrc = ['src/microprocessor.cc', 'src/simulator.cc', 'src/memory.cc', 'src/io.cc']
libSimulator = shared_library('my8085sim', sharedSrc, include_directories : my_inc)

src = ['src/main.cc']
executable('8085', src,  include_directories : my_inc, link_with : [libSimulator])

asmSrc = ['src/asm-main.cc']
executable('asm2bin', asmSrc, include_directories : my_inc, link_with : libParser)
