# Run `python scrapURLs.py` for a standalone URL scraper.
# Import `get_links` function if integrating into another program.


from urllib.parse import urlparse
import re
import requests


def get_html(url):    
    try:    
        html = requests.get(url)    
    except Exception as e:    
        print(e)    
        return ""    
    return html.content.decode('latin-1')  

def get_links(url):
    html = get_html(url)    
    parsed = urlparse(url)    
    base = f"{parsed.scheme}://{parsed.netloc}"    
    links = re.findall('''<a\s+(?:[^>]*?\s+)?href="([^"]*)"''', html)    
    for i, link in enumerate(links): 
        if not urlparse(link).netloc:    
            link_with_base = base + link    
            links[i] = link_with_base  
        elif link.startswith("//"):
            scheme = f"{parsed.scheme}:"
            link_with_base = scheme + link    
            links[i] = link_with_base

    return set(filter(lambda x: 'mailto' not in x, links))    

def main():
    print("Get a list of website links scrapped from a given web page. Enter q to exit.")
    print("An example website is https://www.google.com/")
    url = input("Enter the page you would like to scrap links from: ")
    links = get_links(url)
    for link in links:
        print(link)

    return set(filter(lambda x: 'mailto' not in x, links))

if __name__ == '__main__':
    main()
