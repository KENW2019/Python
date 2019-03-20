
import re

file_handler = open(r'D:\A_Projects\N60\A -- sw module\can COM\Elina\genarated code for N60\for master base on V3.1 DBC\V14\ioc\check_can_tx_signals_gen.txt','r')

line_list = []

for line in file_handler.readlines():
    line_list.append(line)

file_handler.close()

'''
for line in line_list:
    print(line)
print(line_list)
'''

'''
line_count = 0
for line in line_list:
    search_result = re.search(r'(SIGNALID.*?_Tx)',line)
    print(search_result.group(1))
    line_count += 1
print(line_count)
'''

finderror = 0
dup_count = 0
line_count = 0
for line in line_list:
    search_result = re.search(r'(SIGNALID.*?_Tx)',line)
    for line2 in line_list:
        search_result2 = re.search(search_result.group(),line2)
        if None != search_result2:
            dup_count += 1
    if dup_count >= 2:
        finderror = 1
        print('Error is found with string :\n\t%s' % line)
        #print(line)
        break
    else:
        dup_count = 0
        line_count += 1
if 0 == finderror:
    print('Pass check with line number:  %d' % line_count)



