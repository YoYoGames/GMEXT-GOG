
draw_set_valign(fa_top)
draw_set_halign(fa_left)
draw_text(100,130,"IsOverlayVisible: " + string(GOG_Utils_IsOverlayVisible()))
draw_text(100,160,"OverlayState: " + string(GOG_Utils_GetOverlayState()))
draw_text(100,190,"GetGogServicesConnectionState: " + string(GOG_Utils_GetGogServicesConnectionState()))
GOG_Utils_GetNotification()

