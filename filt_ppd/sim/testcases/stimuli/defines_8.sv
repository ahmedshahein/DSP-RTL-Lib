`define DIV(N, D) (N%D==0) ? (N/D) : (N/D+1)

`define P_INP_DATA_W 	10
`define P_DECIMATION 	8
`define P_COEFF_L 	17
`define P_COEFF_W 	8
`define P_TF_DF 	0
`define P_COMM_R_OUP 	1
`define P_COMM_CCW_CW 	1
`define P_MUL_CCW_CW 	0
`define P_COMM_PHA 	5
`define P_OUP_W     	(`P_INP_DATA_W+`P_COEFF_W+`P_DECIMATION+(`DIV(`P_COEFF_L,`P_DECIMATION)))

`define TESTCASE	8

`define NULL 	0