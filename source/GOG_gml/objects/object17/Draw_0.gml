
draw_text(100,100,GOG_Storage_GetFileCount())
draw_text(100,130,GOG_Storage_GetDownloadedSharedFileCount())

if(GOG_Storage_GetDownloadedSharedFileCount())
{
	draw_text(100,160,GOG_Storage_GetDownloadedSharedFileByIndex(0))
}
