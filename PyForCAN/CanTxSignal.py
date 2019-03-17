
import re

file_can_tx_signals_gen = open(r'Y:\Python\CANGen_Appl\can_tx_signals_gen.h','r')
file_signal_list = open(r'Y:\Python\PyForCAN\signal_list.txt','a')


search_cnt = 0


for line in file_can_tx_signals_gen.readlines():  
    #result = re.search('SIGNALID_.*?_Tx',line)
    result = re.search(r'SIGNALID_([A-Za-z0-9]+?_\w+?)_oICC_.*?_Tx',line)
    if None != result:
        print(result.group(1))
        search_cnt += 1
        print(search_cnt)
        #print(result.span())
        file_signal_list.write(r'(TpCANApp_w_TxCanSigIf)Rte_Write_Pp_TxSignal_' + \
                result.group(1) + '_De'+ result.group(1) + ',' + 'sizeof(Dt'+ result.group(1) + \
                         ')' + ',' +'\n')


file_can_tx_signals_gen.close()