Main_Hub_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Main_Hub_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Main_Hub_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_MAIN_GAME, 0, DirectorIntro
	.2byte 0


DirectorIntro::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Main_Hub_Player_1
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MainHub_Camera_1
	waitmovement 0
	applymovement 1, Director_1
	waitmovement 0
	msgbox Director_Talk_1, MSGBOX_AUTOCLOSE
	waitmessage
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Main_Hub_Player_2
	waitmovement 0
	special RemoveCameraObject
	msgbox Director_Talk_2, MSGBOX_AUTOCLOSE
	waitmessage
	closemessage
	fadeoutbgm 1
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 10
	setvar VAR_0x8007, 4
	setweather WEATHER_SANDSTORM
	doweather
	delay 60
	special ShakeCamera
	delay 60
	special ShakeCamera
	delay 60
	setweather WEATHER_RAIN
	doweather
	delay 60
	special ShakeCamera
	delay 60
	special ShakeCamera
	delay 60
	resetweather
	doweather
	playbgm MUS_END, TRUE
	msgbox Director_Talk_3, MSGBOX_AUTOCLOSE
	waitmessage
	closemessage
	setvar VAR_MAIN_GAME, 1
	releaseall
	end


Director_1:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

Main_Hub_Player_1:
	face_up
	step_end

Main_Hub_Player_2:
	walk_up
	walk_up
	walk_up
	step_end

MainHub_Camera_1:
	walk_up
	walk_up
	walk_up
	step_end

Director_Talk_1::
	.string "???: Oh hey there! \p"
	.string "Don’t be shy. \n"
	.string "Come on over here!$"

Director_Talk_2::
	.string "???: I bet you’re wondering where \n"
	.string "you are, huh? \p"
	.string "Well, that isn’t the simplest thing to \n"
	.string "explain, you see… \p"
	.string "I am the Director. \p"
	.string "I have complete control of everything \n"
	.string "that surrounds us. \p"
	.string "Here, let me just show you!$"

Director_Talk_3::
	.string "Director: Well, I think you get the point. \p"
	.string "Anyways… \p"
	.string "This place is a central hub for any \n"
	.string "situation or event that I can dream up! \p"
	.string "Now, your job is to live out these \n"
	.string "events as if they were your own life. \p"
	.string "I bet you’re also wondering why do \n"
	.string "I need you? \p"
	.string "In the same way that you can’t \n"
	.string "influence these environments, \p"
	.string "I cannot interact with them… \p"
	.string "Moving on. \p"
	.string "See those light pads in the corners? \p"
	.string "The one on the LEFT will take you \n"
	.string "to a place I like to call the \p"
	.string "Capture Zone. \p"
	.string "The one on the RIGHT will take \n"
	.string "you to the Item Dispo… \p"
	.string "When you are ready to see what \n"
	.string "I have up for you next, \p"
	.string "come talk to me!$"
