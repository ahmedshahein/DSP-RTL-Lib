#!/bin/bash
# dsp_rtl_lib.sh
# -------------------------------------------------------------------
# Copyright (C) 2019 Ahmed Shahein
# -------------------------------------------------------------------

# LOCAL COMMANDS FOR TEXT COLORING
color_green_cmd="$(tput setaf 2)"
color_red_cmd="$(tput setaf 1)"
color_yellow_cmd="$(tput setaf 3)"
color_reset_cmd="$(tput sgr0)"

# GITHUB REPOSITORY LINK
git_repository="git@github.com:ahmedshahein/DSP-RTL-Lib.git"

# LOCAL SETUP/CONFIGURATION PARAMETERS
CONFG_CHK=""
CONFG_TOOL=""
CONFG_GIT=""
CONFG_DSN=""
CONFG_PATH=""
CONFG_SIM=""
CONFG_DEMO=""
CONFG_DEV=""

# HELP [EXIT 3]
if [ "$#" = 1 -a "$1" = "-help" -o "$1" = "-h" ]; then
  msg="
       ###############################################################
       This script is developed to facilitate the 
         - downloading
         - checking/setting environment
         - designing module
       of the DSP-RTL-Lib (DRL) by (c) 2019 Ahmed Shahein.
       
       The arguments are:-
       -chk  | -c   : Check the installed tools for the RTL flow.
                      No associated argument with it.
                      The tools are checked in the following order:
                        1. Icarus Verilog
                        2. Verilator
                        3. ModelSim
                        4. N.A. -> EXIT
                      The GTKwave tool is checked as well.
                      Use the -tool|-t to overwrite this check.
       
       -tool | -t   : Setup the tool flow manually.
                      Choose from the following:
                        1. "iverilog"
                        2. "verilator"
                        3. "modelsim"
       
       -git  | -g   : Clone the repository into the current folder.
       
       -design | -d : Design a certain moule from the DRL supported 
                      modules. This option must be accompanied with
                      a parameters file. The parameters file has a
                      dedicated template and naming convention.
                      file_name = <module_name>_<instance_number>.param
                      The <module_name> can be:
                        filt_cicd
                        filt_cici
                        filt_fir
                        filt_mac
                        filt_ppd
                        filt_ppi
                        sgen_cordic
                        sgen_nco
                      The <instance_number> is an indication how many instances
                      do you want to generate from the same module. It starts
                      from 1.
                      P.S. If the .param file is not specified the module is 
		      generated based on the local parameters.
                           The _<instance_number> option is not supported yet.
        
	-path | -p  : Set the path for generating the desired modules.
        
	-sim | -s   : Execute a single simulation run.
                      ./dsp_rtl_lib.sh -s <ARGUMENT_1> <ARGUMENT_2>
                      ARGUMENT_1 == design name, e.g., filt_mac
                      ARGUMENT_2 == test-case number, e.g. 1 - 9
                      ./dsp_rtl_lib.sh -s filt_cici 3
        
	-demo       : Execute the script with the following arguments for a 
                      sample module design of an FIR filter.
                      ./dsp_rtl_lib.sh -g -c -p ./ -d filt_cicd_1.param
        
       -dev | -v    : Start development of a new design. This arrgument
                      requires 3 parameters named -design_name -folder -author.
                      ./dsp_rtl_lib.sh -dev -author \"Ahmed Shahein\" -folder \"filt_ppd_opt\" 
		      -design \"filt_ppd_opt\"
       	
       Exit Status:-
         exit 1: no RTL tool is identified
         exit 2: no arguments provided to the script
         exit 3: exit after printing help message
         exit 4: wrong argument(s) provided to the script
         exit 5: faulty source sub-folder
         exit 6: wrong library folder/path
         exit 7: do not accept arguments -c and -t together
         exit 8: wrong tool chain setup
         exit 9: do not overwrite the previous design
         exit 10: octave does not exist, therefore, no verification is carried out
 
       Example:-
       ./dsp_rtl_lib.sh -chk
       ./dsp_rtl_lib.sh -t "iverilog"
       ./dsp_rtl_lib.sh -git -chk
       ./dsp_rtl_lib.sh -g -t "verilator"
       ./dsp_rtl_lib.sh -p "~/DSP_RTL_MODULES" -d filt_cicd_1.param
       ###############################################################
       "
  echo "$msg"
  exit 3
fi

# COMMAND LINE ARGUMENTS [EXIT 2/4]
if [ $# -eq 0 ]; then
  echo "###$color_red_cmd ERROR$color_reset_cmd  : No arguments provided, add -help|-h for further info."
  exit 2
else
  until [ -z "$1" ]
    do 
      case $1 in
        "-chk" | "-c")
          #shift;
          CONFG_CHK="true";
          ;;                
        "-tool" | "-t")
          shift;
          CONFG_TOOL="true";
          CONFG_CHK="";
          RTL_TOOL=$1;
          ;;
        "-git" | "-g")
          shift;
          CONFG_GIT="true";
          git_path=$1;
          ;;
        "-path" | "-p")
          shift;
          CONFG_PATH="true";
          path=$1;
          ;;
        "-design" | "-d")
          shift;
          CONFG_DSN="true";
          suffix='_[0-9].param';
          file_path=$PWD/$1;
          file_name=$1;          
          dsn_name=$(echo $file_name | sed -e "s/$suffix//");
          DSN_PATH="$PWD/$dsn_name"
          echo $DSN_PATH
          export PRJ_DIR=$DSN_PATH
          export RTL_DIR=${DSN_PATH}/rtl
          export SIM_DIR=${DSN_PATH}/sim
          export incdir="${SIM_DIR}/testbench"
          export VVP_DIR=${DSN_PATH}/vvp
          export VCD_DIR=${DSN_PATH}/vcd
          ;;
        "-sim" | "-s")
          shift;
          dsn_name=$1;
          shift
          tc=$1;
          CONFG_SIM="true";
          DSN_PATH="$PWD/$dsn_name"
          echo $DSN_PATH
          export PRJ_DIR=$DSN_PATH
          export RTL_DIR=${DSN_PATH}/rtl
          export SIM_DIR=${DSN_PATH}/sim
          export incdir="${SIM_DIR}/testbench"
          export VVP_DIR=${DSN_PATH}/vvp
          export VCD_DIR=${DSN_PATH}/vcd          
          ;;  
        "-demo")
          CONFG_DEMO="true";
          #CONFG_GIT=true;
          CONFG_CHK="true";
          #CONFG_PATH=true;
          CONFG_DSN="true";
          ;;
        "-dev" | "-v")
	  shift;
	  until [ -z "$1" ]; do
            case $1 in
              "-design")
              shift;
              MODULE_NAME=$1;
              ;;
              "-author")
              shift;
              AUTHOR=$1;
              ;;   
              "-folder")
              shift;
              FOLDER_NAME=$1;
              ;;      
            esac
            shift
          done
          CONFG_DEV=true;
	  ;;	          
        *)
          echo "###$color_red_cmd ERROR$color_reset_cmd  : Invalid option, please check -h for help."
          exit 4
          ;;
      esac
      shift
    done
fi

# HEADER MESSAGE
echo "######################################################"
echo "### DATE   : `date`"
echo "###$color_green_cmd INFO $color_reset_cmd  : This is environment check up for the"
echo "             DSP-RTL-Lib (DRL) by (c) 2019 Ahmed Shahein."

# CLONING GITHUB REPOSITORY (-g|-git)
if [ ! -z $CONFG_GIT ]
then
  echo "###$color_green_cmd INFO $color_reset_cmd  : Cloning the GitHub repository to $git_path."
  git clone $git_repository
  [ -d DSP-RTL-Lib ] && echo "###$color_green_cmd INFO $color_reset_cmd  : Cloning is successful!"
  cd DSP-RTL-Lib
  echo $PWD
  
  # CHECKING OTAVE INSTALLATION
  OCTAVE_STATUS=$(command -v octave)
  if [ -z $OCTAVE_STATUS ]
  then #OCTAVE
    echo "###$color_yellow_cmd WARNING$color_reset_cmd: GNU Octave is not installed!"
    echo "             Stimuli and Response files will not be generated."
    echo "             RTL verification will not be carried out!!!"
  else
    echo "###$color_green_cmd INFO $color_reset_cmd  : GNU Octave is installed for RTL functional verification!"
  fi
  
  # CHECK LIBRARY PATH [EXIT 6]
  export DRL_DIR=$(basename "$PWD")
  if [ $DRL_DIR != "DSP-RTL-Lib" ]
  then
    echo "### $ERROR  : Wrong directory, please run this script from DSP-RTL-Lib directory."
    exit 6  
  fi
  
  # SOURCE LIBRARY CHECK
  # DRL DESIGNES
  FOLDERS=(
  "filt_cicd" \
  "filt_cici" \
  "filt_fir" \
  "filt_mac" \
  "filt_ppd" \
  "filt_ppi" \
  "sgen_cordic" \
  "sgen_nco" \
  )
  
  # DRL SUBFOLDER STRUCTURE [EXIT 5]
  SUB_FOLDERS=(\
  "rtl" \
  "sim/testcases/stimuli" \
  "sim/testcases/response" \
  "sim/testbench" \
  "octave" \
  "log" \
  )
  
  cd .drl_src_code
  
  for i in "${FOLDERS[@]}"
  do
    for j in "${SUB_FOLDERS[@]}"
    do
      if [[ ! -d $i/$j ]];
      then
        echo $PWD
        echo "###$color_red_cmd ERROR $color_reset_cmd : $i FAILED" 
        echo "             Please check library cloning or download."
        exit 5         
      fi    
    done #SUBFOLDERS
    echo "###$color_green_cmd INFO $color_reset_cmd  : Source library check $i PASSED"
  done #FOLDERS
  cd ..
  
  echo "###$color_green_cmd INFO $color_reset_cmd  : Setup of DSP-RTL-Lib (DRL) is successful."
  echo "######################################################"
  
fi

if [ "$CONFG_DEMO" = "true" ]
then
  path=$PWD
  echo "CURRENT PATH is $path"
  cp .drl_param/filt_cicd_1.param ./
  suffix='_[0-9].param';
  file_path=$PWD/filt_cicd_1.param;
  file_name=filt_cicd_1.param;          
  dsn_name=$(echo $file_name | sed -e "s/$suffix//");
  DSN_PATH="$path/$dsn_name"
  export PRJ_DIR=$DSN_PATH
  export RTL_DIR=${DSN_PATH}/rtl
  export SIM_DIR=${DSN_PATH}/sim
  export incdir="${SIM_DIR}/testbench"
  export VVP_DIR=${DSN_PATH}/vvp
  export VCD_DIR=${DSN_PATH}/vcd
fi

# DO NOT ACCEPT -C AND -T OPTIONS TOGETHER
if [ "$CONFG_CHK" = "true" ] && [ "$CONFG_TOOL" = "true" ]
then
  echo "$color_red_cmd ERROR$color_reset_cmd: Wrong options, use either -c or -t."
  exit 7
fi

# CHECKING RTL FLOW SETUP (-c|-chk) [EXIT 1]
if [ "$CONFG_CHK" = "true" ]
then
  if hash iverilog 2>/dev/null && hash vvp 2>/dev/null 
  then #IVERILOG
    echo "###$color_green_cmd INFO $color_reset_cmd  : Icarus Verilog flow is installed for RTL!"
    RTL_TOOL="iverilog"
  else
    echo "###$color_yellow_cmd WARNING $color_reset_cmd : Icarus Verilog is not installed!"
    echo "           Looking for alternative."
    if hash verilator 2>/dev/null 
    then #VERILATOR
      echo "###$color_green_cmd INFO $color_reset_cmd  : Verilator flow is installed for RTL!"
      RTL_TOOL="verilator"
    else 
      echo "###$color_yellow_cmd WARNING$color_reset_cmd: Verilator is not installed!"
      echo "             Looking for alternative."
      if hash vlog 2>/dev/null && hash vsim 2>/dev/null 
      then #MODELSIM
        echo "###$color_green_cmd INFO $color_reset_cmd  : ModelSim flow is installed for RTL!"
        RTL_TOOL="modelsim"
      else
        echo "###$color_red_cmd ERROR$color_reset_cmd: NO RTL FRONT-END FLOW IS INSTALLED!"
        echo "       Please install either Icarus Verilog or Verilator or ModelSim SE!"
        exit 1
      fi #MODELSIM
    fi #VERILATOR
  fi #IVERILOG 
  
  if ! hash gtkwave 2>/dev/null
  then #GTKWAVE
    echo "###$color_yellow_cmd WARNING$color_reset_cmd: GTKwave is not installed!"
    echo "             Waveforms cannot be viewed."
  else
    echo "###$color_green_cmd INFO $color_reset_cmd  : GTKwave is installed for waveform viewing!"
  fi

fi

#
if [ ! $CONFG_PATH ]
then
  path=./
fi

# Tools configurations
if [ "$CONFG_TOOL" = "true" ]
then
  case $RTL_TOOL  in
    "iverilog")
      #export f=1
      cmd_com="iverilog -y$RTL_DIR        \
        -I$RTL_DIR -I$incdir        \
        -g2012        \
        -o ${VVP_DIR}/${dsn_name}_CNT_.vvp        \
        -DVCD        \
        ${SIM_DIR}/testbench/${dsn_name}_tb.sv"

      cmd_sim="vvp -l ${DSN_PATH}/log/tc_CNT_.log ${VVP_DIR}/${dsn_name}_CNT_.vvp"
      
      echo "###$color_green_cmd INFO $color_reset_cmd  : Icarus Verilog flow is setup."
      ;;
    "verilator")
    #cmd_com="verilator -y rtl --top-module ${dsn_name} ${dsn_name}.v --sc -Wno-fatal"
    ;;
    "modelsim")
    ;;
    *)
      echo "###$color_red_cmd ERROR $color_reset_cmd : Wrong tool setup, please check the -help or"
      echo "             run with -c to check the installed tools."
      exit 8
  esac
else
  cmd_com="iverilog -y$RTL_DIR      \
    -I$RTL_DIR -I$incdir    \
    -g2012  \
    -o ${VVP_DIR}/${dsn_name}_CNT_.vvp      \
    -DVCD   \
    ${SIM_DIR}/testbench/${dsn_name}_tb.sv"

  cmd_sim="vvp -l ${DSN_PATH}/log/tc_CNT_.log ${VVP_DIR}/${dsn_name}_CNT_.vvp"
  
  echo "###$color_green_cmd INFO $color_reset_cmd  : Icarus Verilog flow is the default setup."
fi 

# DESIGN A MODULE BASED ON .PARAM FILE
if [ "$CONFG_DSN" = "true" ]
then
  echo "###$color_green_cmd INFO $color_reset_cmd  : Generating RTL code for $dsn_name with the parameters ..."
  cat $file_name
  
  y_n="y"
  if [ -d "${DSN_PATH}/${dsn_name}" ]
  then
    echo "### WARNING: The chosen path at $DSN_PATH is already available."
    echo              "Do you want to overwrite the current design? [y/n]"
    read y_n
  fi

  if [[ y_n == n ]]
  then
    exit 9
  else
    cp -rf .drl_src_code/${dsn_name}/ ${DSN_PATH}
  fi

  cd $DSN_PATH
  i=0
  while IFS= read -r line; 
  do 
    param=$(echo $line | awk '{print $1}')
    value=$(echo $line | awk '{print $3}')    
    sed -i '/'"${param}"'/{s/[0-9]\+/'"${value}"'/;:a;n;ba}' octave/stimuli.m
    sed -i '/'"${param}"'/{s/[0-9]\+/'"${value}"'/;:a;n;ba}' rtl/${dsn_name}.v
    i=$((i+1))
  done < $file_path
  
  # CHECKING OTAVE INSTALLATION
  OCTAVE_STATUS=$(command -v octave)
  if [ -z $OCTAVE_STATUS ]
  then #OCTAVE
    echo "### $color_yellow_cmd WARNING $color_reset_cmd: No functional verification to be carried out!"
    echo "               GNU Octave is not installed."
    exit 10
  else
    cd octave
    octave --no-gui --silent stimuli.m
    cd ..
  fi
  
  FILES=$(ls ${PRJ_DIR}/sim/testcases/stimuli/stimuli_tc_*.dat)

  mkdir vvp vcd
  
  f=1
  for i in $FILES
  do
    echo "Simulating testcase " $f
    if [ "$dsn_name" = "sgen_nco" ];
    then
      ln -sf ${PRJ_DIR}/sim/testcases/stimuli/defines_$f.sv ${PRJ_DIR}/sim/testbench/defines.sv
      ln -sf ${PRJ_DIR}/sim/testcases/stimuli/nco_cos_rom_$f.v ${PRJ_DIR}/rtl/nco_cos_rom.v
      ln -sf ${PRJ_DIR}/sim/testcases/stimuli/nco_sin_rom_$f.v ${PRJ_DIR}/rtl/nco_sin_rom.v
    else
      ln -sf ${PRJ_DIR}/sim/testcases/stimuli/defines_$f.sv ${PRJ_DIR}/sim/testbench/defines.sv
    fi
    x=${f}
    cmd_com_rtl=$(echo ${cmd_com} | sed "s/CNT_/$x/g")
    cmd_sim_rtl=$(echo ${cmd_sim} | sed "s/CNT_/$x/g")
    eval $cmd_com_rtl
    eval $cmd_sim_rtl
    f=$(($f+1)) 
  done  
  mv *.vcd vcd
fi

# EXECUTE A SINGLE SIMULATION RUN
if [ "$CONFG_SIM" = "true" ] && [ "$OCTAVE_STATUS" != "true" ]
then
  cd $dsn_name
  [ ! -d vvp ] && mkdir vvp
  [ ! -d vcd ] && mkdir vcd
  echo "###### $dsn_name"
  if [ "$dsn_name" = "sgen_nco" ];
  then
    echo "###### I am here ..."
    ln -sf ${PRJ_DIR}/sim/testcases/stimuli/defines_${tc}.sv ${PRJ_DIR}/sim/testbench/defines.sv
    ln -sf ${PRJ_DIR}/sim/testcases/stimuli/nco_cos_rom_${tc}.v ${PRJ_DIR}/rtl/nco_cos_rom.v
    ln -sf ${PRJ_DIR}/sim/testcases/stimuli/nco_sin_rom_${tc}.v ${PRJ_DIR}/rtl/nco_sin_rom.v
  else
    ln -sf ${PRJ_DIR}/sim/testcases/stimuli/defines_${tc}.sv ${PRJ_DIR}/sim/testbench/defines.sv
  fi
  cmd_com_rtl=$(echo ${cmd_com} | sed "s/CNT_/$tc/g")
  cmd_sim_rtl=$(echo ${cmd_sim} | sed "s/CNT_/$tc/g")
  eval $cmd_com_rtl
  eval $cmd_sim_rtl
  gtkwave ${dsn_name}_${tc}.vcd
  cd ..
fi

# Development mode for a new module.
if [ "$CONFG_DEV" = "true" ] 
then
  if [[ -z $MODULE_NAME && -z $AUTHOR && -z $FOLDER_NAME ]];
  then
    echo "###$color_red_cmd ERROR $color_reset_cmd : Wrong number of arrguments for development mode."
    echo "           : The development mode requires 3 dedicated configuration parameters as follow:"
    echo "             ./dsp_rtl_lib.sh -dev -author \"Ahmed Shahein\"" 
    echo "                                   -folder \"filt_ppd_opt\""
    echo "                                   -design \"filt_ppd_opt\""
  else
    echo "###$color_green_cmd INFO $color_reset_cmd  : Development Mode."
    
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

  fi  # Development mode
  
fi
# EOF: dsp_rtl_lib.sh
