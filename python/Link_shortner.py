##import bitly_api
##
##API_USER = 'USERNAME'
##API_KEY = 'API_KEY'
##bitly = bitly_api.Connection(API_USER, API_KEY)
##
##response = bitly.shorten("www.mysite.com")
##
##print(response)
##
###############################################################
##
import bitly_api

BITLY_ACCESS_TOKEN ="ACCESS_TOKEN_HERE"

b = bitly_api.Connection(access_token = BITLY_ACCESS_TOKEN)

response = b.shorten('URL')
print(response)
##
################################################################
##
##from pyshorteners import Shortener
##
##url = 'http://www.godaddy.com'
##shortener = Shortener('Tinyurl')
##shortener = Shortener('Isgd')
##s = (shortener.short(url))
##print ("My long url is {}".format(s))
##
##### expanding
##url = 'http://tinyurl.com/ycus76'
##print ("My long url is {}".format(shortener.expand(url)))
##url = 'http://is.gd/SsaC'
##print ("My long url is {}".format(shortener.expand(s)))
