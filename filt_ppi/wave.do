onerror {resume}
quietly virtual signal -install /mul_add_tb/dut { /mul_add_tb/dut/w_sum[104:84]} reg0_add4
quietly virtual signal -install /mul_add_tb/dut { /mul_add_tb/dut/w_sum[94:76]} add4_reg0
quietly virtual signal -install /mul_add_tb/dut { /mul_add_tb/dut/w_reg[20:0]} reg0
quietly WaveActivateNextPane {} 0
add wave -noupdate /mul_add_tb/dut/gp_idata_width
add wave -noupdate /mul_add_tb/dut/gp_decimation_factor
add wave -noupdate /mul_add_tb/dut/gp_coeff_length
add wave -noupdate /mul_add_tb/dut/gp_coeff_width
add wave -noupdate /mul_add_tb/dut/gp_tf_df
add wave -noupdate /mul_add_tb/dut/gp_ccw
add wave -noupdate /mul_add_tb/dut/gp_odata_width
add wave -noupdate /mul_add_tb/dut/c_coeff_2
add wave -noupdate /mul_add_tb/dut/c_col
add wave -noupdate /mul_add_tb/dut/c_row_x_col
add wave -noupdate /mul_add_tb/dut/c_mul_out_width
add wave -noupdate /mul_add_tb/dut/c_sum_out_width
add wave -noupdate /mul_add_tb/dut/c_reg_out_width
add wave -noupdate /mul_add_tb/dut/c_mul_filler
add wave -noupdate /mul_add_tb/dut/c_commutator_width
add wave -noupdate /mul_add_tb/dut/i_rst_an
add wave -noupdate /mul_add_tb/dut/i_ena
add wave -noupdate /mul_add_tb/dut/i_clk
add wave -noupdate /mul_add_tb/dut/i_data
add wave -noupdate /mul_add_tb/dut/o_data
add wave -noupdate /mul_add_tb/dut/c_coeff
add wave -noupdate -radix decimal /mul_add_tb/dut/w_mul
add wave -noupdate -radix decimal /mul_add_tb/dut/add4_reg0
add wave -noupdate /mul_add_tb/dut/w_sum
add wave -noupdate -radix decimal /mul_add_tb/dut/reg0
add wave -noupdate /mul_add_tb/dut/w_reg
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {197 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 259
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 0
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ns
update
WaveRestoreZoom {0 ps} {1050 ps}
