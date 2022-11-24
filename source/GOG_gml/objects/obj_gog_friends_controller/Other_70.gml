
switch(async_load[?"type"])
{
	case "GOG_Friends_RequestUserInformation":
		
		var init_struct = {userID : async_load[?"userID"]}
		instance_create_depth(100+count*200,300,depth,Obj_GOG_Friend,init_struct)
		
		count ++
		
	break
}
