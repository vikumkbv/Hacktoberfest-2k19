# Check internet connection 

import urllib.request as urllib2


def check_network():
    try:
        urllib2.urlopen("http://google.com", timeout=2)
        return True
    except urllib2.URLError:
        return False

print( 'connected' if check_network() else 'no internet!' )