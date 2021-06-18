from distutils.core import setup, Extension

def main():
    setup(name="aws",
          version="1.0.0",
          description="Python interface for C library",
          author="<your name>",
          author_email="your_email@gmail.com",
          ext_modules=[Extension("input_stream", ["input_stream.c"])])

if __name__ == "__main__":
    main()