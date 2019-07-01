import sys

def dprint(*args, **kwargs):
    if not __debug__:
        print(*args, **kwargs, file=sys.stderr)
