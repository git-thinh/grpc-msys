template < class t>
void tprotobufserializer::serializeimplementation(const t& protobuf, std::vector<char>& buffer)
{
	int buflength = protobuf.bytesize() + google::protobuf::io::codedoutputstream::varintsize32(protobuf.bytesize());
	buffer.resize(buflength);
	google::protobuf::io::arrayoutputstream arrayoutput(&buffer[0], buflength);
	google::protobuf::io::codedoutputstream codedoutput(&arrayoutput);
	codedoutput.writevarint32(protobuf.bytesize());
	protobuf.serializetocodedstream(&codedoutput);
}

template < class t>
bool tprotobufserializer::deserializeimplementation(std::vector<char>& buffer, t& protobuf)
{
	bool deserialized = false;
	google::protobuf::io::arrayinputstream arrayinput(&buffer[0], buffer.size());
	google::protobuf::io::codedinputstream codedinput(&arrayinput);
	unsigned int object_size;
	bool header_readed = codedinput.readvarint32(&object_size);
	if (header_readed && object_size > 0) {
		if (buffer.size() >= codedinput.currentposition() + object_size) {
			google::protobuf::io::codedinputstream::limit limit = codedinput.pushlimit(object_size);
			if (protobuf.parsefromcodedstream(&codedinput)) {
				std::vector<char>::iterator = buffer.begin();
				std::advance(it, codedinput.currentposition());
				std::move(it, buffer.end(), buffer.begin());
				buffer.resize(buffer.size() - codedinput.currentposition());
				deserialized = true;
			}
			else {
				throw tprotobufserializerpayloadexception();
			}
			codedinput.poplimit(limit);
		}
	}
	else {
		//varint32 used in header @ 5 bytes long,        
		//if given buffer 5 bytes or more long , header still cannot decoded - raise exception         
		if (buffer.size() >= 5) {
			throw tprotobufserializerheaderexception();
		}
	}
	return deserialized;
}