SET SOURCE_PATH=%CD%
                                                          
protoc --proto_path=%SOURCE_PATH% --cpp_out=%SOURCE_PATH% --python_out=%SOURCE_PATH% exam_protocol.proto