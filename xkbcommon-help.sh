source_dir=$1
pkgconfig_path=$2
prefix=$3
include=$4
m4_path=$5
bison_path=$6
export PKG_CONFIG_PATH="${pkgconfig_path}"
export PATH="${PATH}:${5}:${bison_path}"
export M4="m4-1.4.18/bin"
export CPP_INCLUDE_PATH="${C_INCLUDE_PATH}:${include}"
cd ${source_dir}/ && ./configure --disable-silent-rules --disable-maintainer-mode --prefix=${prefix} && make -j4 install 
