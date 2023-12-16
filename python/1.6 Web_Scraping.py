# What is Web Scraping? 
# Web scraping is a computer software technique of extracting information from websites.
# Beautiful Soup is a Python library for pulling data out of HTML and XML files.
# It works with your favorite parser to provide idiomatic ways of navigating, searching, and modifying the parse tree.
# It commonly saves programmers hours or days of work.
# Web Scraping with Beautiful Soup

import requests
import bs4 #BeautifulSoup4 A Python library for pulling data out of HTML and XML files.


res=requests.get("http://www.example.com")
# print(type(res))
# print(res.text)

soup = bs4.BeautifulSoup(res.text,'lxml')
print(type(soup))
# print(soup)
title_tag=soup.select('title')
print(title_tag)
#Search by ID or Class Name soup.select('#id') or soup.select('.class')
print(soup.select('p'))
print(title_tag[0].getText())
