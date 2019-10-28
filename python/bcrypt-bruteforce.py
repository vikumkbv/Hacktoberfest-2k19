#!/usr/bin/pthon2
import  bcrypt
import sys

if (len(sys.argv)) < 2:
        print 'wrong arg, try this : pthon2 mytools.py myworslist.txt'
        sys.exit()
else:
        afterHash = raw_input('What bcrypt hash ur will be compare ? : ')
        if len(afterHash) < 60:
                sys.exit()
        else:
                with open(sys.argv[1], 'r') as getMyworList:
                        for x in getMyworList:
                                passw = x.strip()
                                if bcrypt.checkpw(passw, afterHash):
                                        print '[+] Hash Matching with : ',passw
                                        salt = bcrypt.gensalt();
                                        hashed = bcrypt.hashpw(passw, salt)
                                        print '[+] Your hash : ',afterHash,'\n[+] Same hash : ',hashed
                                else:
                                        print 'not matching : ',passw