#!/usr/bin/env python3

with open('/home/k/share/Python/test.c', 'w') as f:
	#print(f.read())
	#for line in f.readlines():
		#print(line.strip())
	f.write('static const TsCANApp_h_TxCanSigIf CtCANApp_h_TxCanSigIf[2u] =\n')


with open('/home/k/share/Python/test.c', 'a') as f:
	#print(f.read())
	#for line in f.readlines():
		#print(line.strip())
	#f.write('static const TsCANApp_h_TxCanSigIf CtCANApp_h_TxCanSigIf[2u] =')
	f.write('{\n')

with open('/home/k/share/Python/test.c', 'a') as f:
	#print(f.read())
	#for line in f.readlines():
		#print(line.strip())
	#f.write('static const TsCANApp_h_TxCanSigIf CtCANApp_h_TxCanSigIf[2u] =')
	f.write('\t(TpCANApp_w_TxCanSigIf)Rte_Write_Pp_TxSignal_EHU_BeepSrcSet_DeEHU_BeepSrcSet, CeCANApp_u_TxCanSigSize_OneByte,\n')
	