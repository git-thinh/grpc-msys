
	#protoc --proto_path=$(path_proto) --cpp_out=$(path_src) --plugin=protoc-gen-grpc=/c/msys2/App/msys32/mingw64/bin/grpc_cpp_plugin.exe $(notdir $<)
	#protoc --proto_path=$(path_proto) --cpp_out=$(path_src) $(notdir $<)
	
CXX = g++
CPPFLAGS += `pkg-config --cflags protobuf grpc`
CXXFLAGS += -std=c++11

LDFLAGS += -L/usr/local/lib `pkg-config --libs protobuf grpc++`\
           -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed\
           -ldl
		   
path_root 		= ${CURDIR}
path_src		= $(path_root)/src
path_proto		= $(path_root)/proto

vpath %.proto $(path_proto)

all: route_guide.pb.o
	g++ $^ $(CXXFLAGS) -o $@
	
%.pb.cc: %.proto
	protoc -I $(path_proto) --cpp_out=$(path_src) $<
	


