Testing_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Testing_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Testing_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_GYARADOS_FIGHT, 0, GyaradosFightIntro
	.2byte 0


GyaradosFightIntro::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Player_1
	waitmovement 0
	applymovement 1, NPC_1
	playse SE_PIN
	waitmovement 0
	waitse
	msgbox NPC_Talk, MSGBOX_AUTOCLOSE
	waitmessage
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Camera_Pan_1
	waitmovement 0
	delay 60
	playmoncry SPECIES_GYARADOS, 0
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 10
	setvar VAR_0x8007, 4
	special ShakeCamera
	waitstate
	waitmoncry
	setweather WEATHER_RAIN_THUNDERSTORM
	doweather
	delay 120
	applymovement OBJ_EVENT_ID_CAMERA, Camera_Pan_2
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_GYARADOS_FIGHT, 1
	releaseall
	end


Gyarados_Turn_Back::
	lock
	applymovement 1, NPC_1
	playse SE_PIN
	waitmovement 0
	msgbox NPC_Talk_2
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, Player_Turn_Back
	waitmovement 0
	release
	end


GyaradosFight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Player_2
	waitmovement 0
	applymovement 2, Gyarados_1
	waitmovement 0
	delay 30
	playmoncry SPECIES_GYARADOS, 0
	special ShakeCamera
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Player_3
	playse SE_LEDGE
	delay 10
	playse SE_LEDGE
	delay 10
	playse SE_LEDGE
	waitmovement 0
	msgbox Player_Talk_1
	waitmessage
	setvar VAR_GYARADOS_FIGHT, 2
	release
	end


Player_1:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	face_up
	step_end

Player_2:
	walk_up
	walk_up
	step_end

Player_3:
	jump_down
	jump_down
	jump_down
	step_end

Player_Turn_Back:
	face_right
	walk_right
	step_end

NPC_1:
	face_down
	emote_exclamation_mark
	step_end

Gyarados_1:
	walk_down
	walk_down
	walk_in_place_fast_down
	step_end

Camera_Pan_1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

Camera_Pan_2:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Player_Talk_1::
	.string "{PLAYER}: {COLOR GREEN}{SHADOW LIGHT_GREEN}(I don’t stand a chance without a \n"
	.string "Pokemon...)$"

NPC_Talk::
	.string "NPC: Thank goodness someone is here! \n"
	.string "There is a Gyarados on a rampage! \p"
	.string "I can’t do anything to help… \p"
	.string "Please, do something!!$"

NPC_Talk_2::
	.string "NPC: Where are you going?! \p"
	.string "Please, help!!!$"
