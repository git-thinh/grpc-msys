clear
PATH=/mingw64/bin:$PATH
MIN_LIB=/mingw64/lib
MIN_BIN=/mingw64/bin
MIN_INCLUDE=/mingw64/include
PREFIX=x86_64-w64-mingw32
export C=$PREFIX-gcc.exe
export CC=$PREFIX-gcc.exe
export CXX=$PREFIX-g++.exe
export CPP=$PREFIX-cpp.exe
export RANLIB=$PREFIX-gcc-ranlib.exe
export CXXCPP=$PREFIX-cpp.exe
export AR=$PREFIX-ar.exe
export NM=$PREFIX-nm.exe
export DLLTOOL=$PREFIX-dlltool.exe
export DLLWRAP=$PREFIX-dllwrap.exe
export LD=$PREFIX-ld.exe
export OBJCOPY=$PREFIX-objcopy.exe
export OBJDUMP=$PREFIX-objdump.exe
export PKGCONFIG=$PREFIX-pkg-config.exe
echo
gcc -v
echo
PATH_ROOT=$(pwd)
PATH_SRC=$(pwd)/src
PATH_PROTO=$(pwd)/proto
PATH_OBJ=$(pwd)/obj
echo PATH_ROOT: $PATH_ROOT
echo ----------------------------------------------------

rm test_protobuf.exe
rm $PATH_SRC/*
rm $PATH_ROOT/bin/*.exe

#///////////////////////////////////////////////////////////////////////////////

# protoc \
	# --proto_path=$PATH_PROTO \
	# --grpc_out=$PATH_SRC \
	# --plugin=protoc-gen-grpc=$MIN_BIN/grpc_cpp_plugin.exe \
	# addressbook.proto
	
# protoc \
	# --proto_path=$PATH_PROTO \
	# --cpp_out=$PATH_SRC \
	# addressbook.proto
	
# g++ -I$PATH_SRC -Wall \
	# test_protobuf.cpp $PATH_SRC/addressbook.pb.cc \
	# -lprotobuf -pthread -static-libgcc -static-libstdc++ -std=c++11 \
	# -o ./test_protobuf.exe

#///////////////////////////////////////////////////////////////////////////////
#-mwin32 -D_WIN32_WINNT=0x600	for win32

protoc \
	--proto_path=$PATH_PROTO \
	--grpc_out=$PATH_SRC/ \
	--plugin=protoc-gen-grpc=$MIN_BIN/grpc_cpp_plugin.exe \
	route_guide.proto
	
protoc \
	--proto_path=$PATH_PROTO \
	--cpp_out=$PATH_SRC/ \
	route_guide.proto

g++ -I$PATH_SRC -Wall -D_WIN32_WINNT=0x600 \
	route_guide_server.cc helper.cc \
	$PATH_SRC/route_guide.pb.cc $PATH_SRC/route_guide.grpc.pb.cc \
	-lprotobuf -lgrpc++ -pthread -static-libgcc -static-libstdc++ -std=c++11 \
	-o ./bin/route_server.exe
	
g++ -I$PATH_SRC -Wall -D_WIN32_WINNT=0x600 \
	route_guide_client.cc helper.cc \
	$PATH_SRC/route_guide.pb.cc $PATH_SRC/route_guide.grpc.pb.cc \
	-lprotobuf -lgrpc++ -pthread -static-libgcc -static-libstdc++ -std=c++11 \
	-o ./bin/route_client.exe
#///////////////////////////////////////////////////////////////////////////////


	
# g++ -I$PATH_SRC -Wall route_guide_server.cc helper.cc $PATH_SRC/route_guide.pb.cc $PATH_SRC/route_guide.grpc.pb.cc -lprotobuf -lprotobuf -pthread -static-libgcc -static-libstdc++ -std=c++11 -o ./route_guide_server.exe

# g++ \
	# route_guide.pb.o route_guide.grpc.pb.o route_guide_client.o helper.o \
		# -L/usr/local/lib `pkg-config --libs protobuf grpc++`\
        # -lgrpc++_reflection\
        # -ldl







# g++ -I"C:/C++/protobuf/protobuf.3.5.1-gcc-7.2.0-sjlj/include" -L"C:/C++/protobuf/protobuf.3.5.1-gcc-7.2.0-sjlj/lib" main.cpp addressbook.pb.cc -lprotobuf -pthread -static-libgcc -std=c++11
# g++ main.cpp addressbook.pb.cc -lprotobuf -pthread -static-libgcc -std=c++11
# g++ main.cpp addressbook.pb.cc -lprotobuf -pthread -static-libgcc -std=c++11 -o app.exe
# g++ main.cpp addressbook.pb.cc -lprotobuf -pthread -static-libgcc -static-libstdc++ -std=c++11 -o app.exe

# g++ -Wall main.cpp addressbook.pb.cc -lprotobuf -pthread -static-libgcc -static-libstdc++ -std=c++11 -o app.exe

# g++ -Wall main.cpp addressbook.pb.cc -pthread -static-libgcc -static-libstdc++ -std=c++11 $MIN_LIB/libprotobuf.dll.a -o app.exe
# g++ -Wall main.cpp addressbook.pb.cc -lprotobuf -pthread -static-libgcc -static-libstdc++ -std=c++11 $MIN_BIN/libprotobuf.dll $MIN_BIN/libwinpthread-1.dll -o app.exe





# @echo off
# CLS
# SET "ECHO_TITLE=-----"
# ::----------------------------------------------------------
# SET "PATH_ROOT=%CD%\"
# ECHO %ECHO_TITLE%PATH_ROOT=%PATH_ROOT%

# SET "PATH_PROTOC=%PATH_ROOT%bin\protoc.exe"
# ECHO %ECHO_TITLE%PATH_PROTOC=%PATH_PROTOC%

# %PATH_PROTOC% -I=%PATH_ROOT% --cpp_out=%PATH_ROOT% %PATH_ROOT%addressbook.proto

# SET "PATH_LIB=%PATH_ROOT%lib\"
# ECHO %ECHO_TITLE%PATH_LIB=%PATH_LIB%

# SET "PATH_INCLUDE=%PATH_ROOT%include\"
# ECHO %ECHO_TITLE%PATH_INCLUDE=%PATH_INCLUDE%

# g++ -I"%PATH_ROOT%" -I"%PATH_INCLUDE%" -L"%PATH_LIB%" test_protobuf.cpp addressbook.pb.cc -l"protobuf.dll" -pthread -static-libgcc -std=c++11

# CALL a.exe

# ::protoc -I=./ --cpp_out=./ addressbook.proto
# ::g++ -I"C:/C++/protobuf/protobuf.3.5.1-gcc-7.2.0-sjlj/include" -L"C:/C++/protobuf/protobuf.3.5.1-gcc-7.2.0-sjlj/lib" main.cpp addressbook.pb.cc -lprotobuf -pthread -static-libgcc -std=c++11

echo
echo
echo --------------
echo BUILD COMPLETE
echo
