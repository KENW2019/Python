
import re

file_handler = open(r'L:\Python\PyForCAN\test.txt','r',encoding = 'utf8')

result = re.search(r'<li.*?active.*?singer="(.*?)">(.*?)</a>',file_handler.read(),re.S)
if None != result:
    print(result.group(1),result.group(2))

file_handler.close
