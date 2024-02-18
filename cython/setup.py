# from distutils.core import setup
from setuptools import setup, Extension
from Cython.Build import cythonize

extensions = Extension("matrix", sources=["multiply.pyx"])


setup(
    name='matrix',
    version='0.1',
    description='matrix multiplication',
    ext_modules=cythonize(extensions),
    zip_safe=False,
)
