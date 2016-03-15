from distutils.core import setup, Extension

module = Extension('mendel',
                   include_dirs=['.'],
                   extra_compile_args=['-std=c++14'],
                   sources = ['mendel_module.cpp', 'mendel_cwrapper.cpp'])

setup(name = 'mendel',
       version = '1.0',
       description = 'Mendel package',
       ext_modules = [module])
