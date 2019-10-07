from google_images_download import google_images_download  # importing the library

response = google_images_download.googleimagesdownload()  # class instantiation

keys = [
    'amazon hyderabad office',
    'infosys mysore campus',
    'tokyo shibuya crossing'

]

filter_keys = ','.join(map(str, keys))

arguments = {
    "keywords": filter_keys,
    "limit": 1,
    "print_urls": True,
    'output_directory': '../data/image_url',
    'no_download': True
}  # creating list of arguments

paths = response.download(arguments)  # passing the arguments to the function
# print(paths)   #printing absolute paths of the downloaded images
