
import re

file_can_tx_signals_gen = open(r'Y:\Python\CANGen_Appl\can_tx_signals_gen.h','r')
file_signal_list = open(r'Y:\Python\PyForCAN\signal_list.txt','a')



search_cnt = 0


for line in file_can_tx_signals_gen.readlines():  
    #result = re.search('SIGNALID_.*?_Tx',line)
    result = re.search(r'SIGNALID_([A-Za-z0-9]+?_\w+?)_oICC_.*?_Tx',line)
    if None != result:
        #print(result.group(1))
        search_cnt += 1
        #print(search_cnt)
        #print(result.span())
        file_signal_list.write(r'(TpCANApp_w_TxCanSigIf)Rte_Write_Pp_TxSignal_' + \
                result.group(1) + '_De'+ result.group(1) + ',' + 'sizeof(Dt'+ result.group(1) + \
                         ')' + ',' +'\n')
file_signal_list.close()



file_CanApplication = open(r'Y:\Python\CANApp\CanApplication.c','r')
lines = []
for line2 in file_CanApplication.readlines():
    lines.append(line2)
file_CanApplication.close()

#print(lines)
'''
for line3 in lines:
    print(line3)
'''
line_cnt = 0
line_cnt_forw = 0
for line3 in lines:    
    result2 = re.search(r'static const TsCANApp_h_TxCanSigIf CtCANApp_h_TxCanSigIf',line3)
    if None != result2:
        print(lines[line_cnt])
        line_cnt += 2
        result3 = re.search(r'};',lines[line_cnt])
        while None == result3:
            print(lines[line_cnt])
            del lines[line_cnt]
            result3 = re.search(r'};',lines[line_cnt])
        line_cnt_forw = line_cnt
        break
    else:
        line_cnt += 1

print(line_cnt_forw)



file_signal_list = open(r'Y:\Python\PyForCAN\signal_list.txt','r')
line_cnt_fordefine = 0
for line_x in file_signal_list.readlines():
    insert_str = '    '+line_x
    lines.insert(line_cnt_forw,insert_str)
    line_cnt_fordefine += 1
file_signal_list.close()
print(line_cnt_fordefine)


line_cnt_again = 0
for line5 in lines:
    line_cnt_again += 1
    result3 = re.search(r'static const TsCANApp_h_TxCanSigIf CtCANApp_h_TxCanSigIf',line5)
    if None != result3:
        break
    else:
        pass
        

print(line_cnt_again)


temp_str = r'#define CeCANApp_w_TxCanSigIfTabSize' + ' ' + str(line_cnt_fordefine) + 'u' + '\n'
print(temp_str)
line_cnt_again -= 1
lines.insert(line_cnt_again,temp_str)

print(line_cnt_again)


lines[line_cnt_again+1] = r'static const TsCANApp_h_TxCanSigIf CtCANApp_h_TxCanSigIf[CeCANApp_w_TxCanSigIfTabSize] =' + '\n'



str_test = ''.join(lines)
file_CanApplication = open(r'Y:\Python\CANApp\CanApplication.c','w')
file_CanApplication.write(str_test)
file_CanApplication.close()


file_can_tx_signals_gen.close()

