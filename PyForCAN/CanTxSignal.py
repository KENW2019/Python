
import re

file_can_tx_signals_gen = open(r'L:\Python\CANGen_Appl\can_tx_signals_gen.h','r')
file_signal_list = open(r'L:\Python\PyForCAN\signal_list.txt','a')


search_cnt = 0

'''
	SIGNALID_EHU_BeepSrcSet_oICC_0x44_oIBUS_94c0ca5d_Tx,
	SIGNALID_EHU_FaderSet_oICC_0x44_oIBUS_0d76e871_Tx,
	SIGNALID_EHU_HiFrqAudioSet_oICC_0x44_oIBUS_61e5095f_Tx,
	SIGNALID_EHU_LeRiBalSet_oICC_0x44_oIBUS_26906d71_Tx,
'''

for line in file_can_tx_signals_gen.readlines():  
    #result = re.search('SIGNALID_.*?_Tx',line)
    result = re.search(r'SIGNALID_([A-Za-z0-9]+?_\w+?)_oICC_.*?_Tx',line)
    if None != result:
        print(result.group(1))
        search_cnt += 1
        print(search_cnt)
        #print(result.span())
        file_signal_list.write(result.group(1) + '\n')


file_can_tx_signals_gen.close()