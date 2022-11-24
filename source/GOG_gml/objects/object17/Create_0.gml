
var filename = "myGOGfile.txt"
var str = "Hello World"
var size = string_length(str)+1
var buffer = buffer_create(size,buffer_fixed,1)

show_debug_message(buffer)
buffer_write(buffer,buffer_string,str)
show_debug_message(buffer_get_size(buffer))
GOG_Storage_FileWrite(filename,buffer)


var buff = GOG_Storage_FileRead(filename)
show_debug_message("Storage Read: " + buffer_read(buff,buffer_string))
GOG_Storage_FileShare()

//GOG_Storage_
GOG_Storage_FileShare(filename)
