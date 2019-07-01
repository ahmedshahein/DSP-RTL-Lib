#!/bin/bash
#./setup_project.sh -d fir_mac -f dsp_filt_mac -a "Ahmed Shahein"
until [ -z "$1" ]; do
  case $1 in
    "-d"|"-design")
    shift;
    MODULE_NAME=$1;
    ;;
    "-a"|"-author")
    shift;
    AUTHOR=$1;
    ;;   
    "-f"|"-folder")
    shift;
    FOLDER_NAME=$1;
    ;;      
  esac
    shift
done

function create_rtl_file () {
cat <<EOF >$MODULE_NAME.v
// -------------------------------------------------------------------
// Copyright (C) 2019 $AUTHOR
// -------------------------------------------------------------------
//
// -------------------------------------------------------------------
module $MODULE_NAME #(
  parameter gp_inp_width   = 8,  // ROM address bit-width
  parameter gp_oup_width   = 16
) (
  input  wire                           i_rst_an,
  input  wire                           i_ena,
  input  wire                           i_clk,
  input  wire        [gp_inp_width-1:0] i_data,
  output wire signed [gp_oup_width-1:0] o_data
);
// -------------------------------------------------------------------
  // CONSTANT DECLARATION
  localparam c_rom_depth = ;
  // REGISTER DECLARATION
  reg        [gp_xxx-1:0] r_xxx;
  // WIRE DECLARATION
  wire signed [c_xxx-1:0] w_xxx;
// -------------------------------------------------------------------
  \`include "xxx.v"
// -------------------------------------------------------------------
  always @(posedge i_clk or negedge i_rst_an)
    begin: p_<xxx>
      if (!i_rst_an)
        begin
	  
	end
      else if (i_ena)
        begin
	  
	end
    end
  
  assign w_xxx = w_xxx + w_xxx>>2;
   
  always @(*)
    begin: p_<xxx>
      case (xxx)
        0:
	default:
      endcase
    end
        
endmodule
EOF
}

function create_testbench () {
cat <<EOF >${MODULE_NAME}_tb.sv
// -------------------------------------------------------------------
// Copyright (C) 2019 $AUTHOR
// -------------------------------------------------------------------
\`timescale 1ns/1ps
\`include "defines.sv"
// -------------------------------------------------------------------
module $MODULE_NAME\_tb;
  time CLK_PERIOD = 50;
  
  reg       i_rst_an;
  reg       i_ena;
  reg       i_clk;
  reg       s_clk;
  
  reg [\`P_INP_DATA_W-1:0] i_data;
  wire                 rdy;
  wire signed [\`P_OUP_DATA_W-1:0] oup_data;
  reg                             data_ready;
  integer error_count=0;
  // READ-IN MATLAB STIMULI FILE  
  reg [8*64:1]                    filename_mat_inp;
  integer                         fid_mat_inp;
  integer                         status_mat_inp;  
  // READ-IN MATLAB RESPONSE FILE
  reg [8*64:1]                    filename_mat_oup;
  integer                         fid_mat_oup;
  integer                         status_mat_oup;
  reg signed [\`P_OUP_DATA_W-1:0]       o_data_mat;
// -------------------------------------------------------------------    
  initial
    begin
           i_rst_an = 1AMPb1;
      #170 i_rst_an = 1AMPb0;
      #205 i_rst_an = 1AMPb1;
    end
  
  initial
    begin
           i_ena = 1AMPb0;
      #400 i_ena = 1AMPb1;
    end
  
  initial i_clk = 1AMPb0;
  always i_clk = #(CLK_PERIOD) ~i_clk;
  
  initial assign s_clk = dut.w_sclk;
  initial
    begin: TEXTIO_READ_IN
      \$display("### INFO: RTL Simulation of FIR Filter.");
      \$display("### Testcase %d", \`TESTCASE);
      \$write("### ");
      \$system(\$sformatf("date"));
      \$sformat(filename_mat_inp,"%s%0d%s","./sim/testcases/stimuli/stimuli_tc_",\`TESTCASE,"_mat.dat");
      \$sformat(filename_mat_oup,"%s%0d%s","./sim/testcases/response/response_tc_",\`TESTCASE,"_mat.dat");
      \$display("%s",filename_mat_inp);
      fid_mat_inp = \$fopen(filename_mat_inp, "r");
      fid_mat_oup = \$fopen(filename_mat_oup, "r");
      if ((fid_mat_inp == \`NULL)||(fid_mat_oup == \`NULL)) begin
        \$display("data_file handle was NULL");
        \$finish;
      end
      
      @(posedge data_ready) 
        begin 
	  \$fclose(fid_mat_inp); 
	  \$fclose(fid_mat_oup); 

	  if (error_count>0)
            \$display("### INFO: Testcase FAILED");
          else
            \$display("### INFO: Testcase PASSED");
	    
  	  \$finish; 
	end
    end
    
  always @(posedge i_clk)
    begin: MATLAB_STIMULI
      if (i_rst_an && i_ena)
        status_mat_inp = \$fscanf(fid_mat_inp,"%d\n", i_data);
      else
        i_data = AMPd0;
	
      if (\$feof(fid_mat_inp)) begin
        data_ready = 1AMPb1;
      end
    end
  
  always @(negedge s_clk)
    begin: MATLAB_RESPONSE
      if (i_rst_an && i_ena)
        status_mat_oup = \$fscanf(fid_mat_oup,"%d\n", o_data_mat);
    end

  always @(negedge s_clk)
    begin
      if (i_rst_an && i_ena)
        assert (oup_data == o_data_mat) 
	else
	  begin 
	    \$error("### RTL = %d, MAT = %d", oup_data, o_data_mat); error_count<= error_count + 1;
	  end
    end
      
  $MODULE_NAME #(
    .gp_inp_width  	   (),
    .gp_oup_width  	   ()
  ) dut (
    .i_rst_an (i_rst_an),
    .i_ena    (i_ena),
    .i_clk    (i_clk),
    .i_data   (),
    .o_data   (oup_data)
  );
    
endmodule
EOF
sed -i "s/AMPb/'b/g" $MODULE_NAME\_tb.sv
}

echo "########################################################################################"
echo "### INFO: Setting up project environment for module $MODULE_NAME at folder $FOLDER_NAME"

if [ ! -z "$FOLDER_NAME" ]; then
  if [ ! -d $FOLDER_NAME ]; then
    mkdir $FOLDER_NAME
    cd $FOLDER_NAME
    if [ ! -d rtl ]; then
      mkdir -p rtl
    fi
    
    if [ ! -d sim ]; then
      mkdir -p sim/testbench sim/testcases/stimuli sim/testcases/response
    fi
    
    if [ ! -d octave ]; then
      mkdir -p octave
    fi
    
    if [ ! -d log ]; then
      mkdir -p log
    fi
    cd ../
  else
    echo "### WARNING: Folder $FOLDER_NAME already exists"
  fi
else
  if [ ! -d rtl ]; then
    mkdir -p rtl
  fi
  
  if [ ! -d sim ]; then
    mkdir -p sim/testbench sim/testcases/stimuli sim/testcases/response
  fi
  
  if [ ! -d octave ]; then
    mkdir -p octave
  fi
  
  if [ ! -d log ]; then
    mkdir -p log
  fi
fi


if [ -z "$(ls -A $FOLDER_NAME/rtl)" ]; then
  cd $FOLDER_NAME/rtl
  echo -e "### INFO: Creating RTL file \e[1m\e[3m$MODULE_NAME.v\e[0m\e[0m at \e[1m\e[3m$FOLDER_NAME/rtl\e[0m\e[0m"
  create_rtl_file
  cd ../../
else
  echo "### WARNING: RTL file already exists"
fi

if [ -z "$(ls -A $FOLDER_NAME/sim/testbench)" ]; then
  cd $FOLDER_NAME/sim/testbench
  echo -e "### INFO: Creating test-bench file \e[1m\e[3m${MODULE_NAME}_tb.v\e[0m\e[0m at \e[1m\e[3m$FOLDER_NAME/sim/testbench\e[0m\e[0m"
  create_testbench
  cd ../../../
else
  echo "### WARNING: Test-bench file already exists"
fi

echo "########################################################################################"
