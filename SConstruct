"""The compilation script for this project using SCons."""
from os import environ


VariantDir('build/src', 'src', duplicate=0)
flags = ['-O3', '-march=native', '-std=c++14']


env = Environment(
    ENV = environ,
    CXX = 'clang++',
    CPPFLAGS = ['-Wno-unused-value'],
    CXXFLAGS = flags,
    LINKFLAGS = flags,
    CPPPATH = ['#src/include'],
)


# Compile the shared library for the Python interface
env.SharedLibrary('build/_nes_env.so', Glob('build/*/*.cpp') + Glob('build/*/*/*.cpp'))
