
import os
j = os.system('/usr/bin/python setup.py install --prefix=/usr/local/cdat ;  1>LOG.rebuild')
if j:
    print 'Compilation failed'
    raise SystemExit, 1

