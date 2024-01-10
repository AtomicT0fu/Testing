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
	closemessage
	fadeoutbgm 1
	playbgm MUS_NONE, TRUE
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


GyaradosTurnBack::
	lock
	applymovement 1, NPC_1
	playse SE_PIN
	waitmovement 0
	msgbox NPC_Talk_2, MSGBOX_AUTOCLOSE
	waitmessage
	closemessage
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
	playmoncry SPECIES_GYARADOS, 2
	special ShakeCamera
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Player_3
	playse SE_LEDGE
	delay 10
	playse SE_LEDGE
	delay 10
	playse SE_LEDGE
	waitmovement 0
	msgbox Player_Talk_1, MSGBOX_AUTOCLOSE
	waitmessage
	closemessage
	addobject 3, MAP_TESTING
	applymovement 3, Raichu_1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Player_4
	playse SE_PIN
	waitse
	waitmovement 0
	call RaichuJoinTeam
	applymovement OBJ_EVENT_ID_PLAYER, Player_2
	waitmovement 0
	delay 30
	playse SE_BALL_THROW
	addobject 5
	waitse
	delay 60
	playse SE_BALL_OPEN
	addobject 6
	removeobject 5
	waitse
	delay 30
	playmoncry SPECIES_RAICHU, 0
	waitmoncry
	delay 20
	playmoncry SPECIES_GYARADOS, 2
	special ShakeCamera
	waitstate
	setwildbattle SPECIES_GYARADOS, 50, ITEM_NONE
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq GyaradosFight_2
GyaradosFight_1:
	waitmessage
	setmetatile 21, 18, 0x0C3, TRUE
	setmetatile 22, 18, 0x0B1, TRUE
	setmetatile 23, 18, 0x0B1, TRUE
	setmetatile 24, 18, 0x0B1, TRUE
	setmetatile 25, 18, 0x0C4, TRUE
	setmetatile 21, 19, 0x0B8, TRUE
	setmetatile 22, 19, 0x0A1, TRUE
	setmetatile 23, 19, 0x0A1, TRUE
	setmetatile 24, 19, 0x0A1, TRUE
	setmetatile 25, 19, 0x0BA, TRUE
	setmetatile 21, 20, 0x0B8, TRUE
	setmetatile 22, 20, 0x0A1, TRUE
	setmetatile 23, 20, 0x0A1, TRUE
	setmetatile 24, 20, 0x0A1, TRUE
	setmetatile 25, 20, 0x0BA, TRUE
	setmetatile 21, 21, 0x0B8, TRUE
	setmetatile 22, 21, 0x0A1, TRUE
	setmetatile 23, 21, 0x0A1, TRUE
	setmetatile 24, 21, 0x0A1, TRUE
	setmetatile 25, 21, 0x0BA, TRUE
	setmetatile 22, 22, 0x099, FALSE
	setmetatile 23, 22, 0x099, FALSE
	setmetatile 24, 22, 0x099, FALSE
	delay 90
	addobject 5
	playse SE_BALL
	waitse
	delay 30
	playse SE_RG_BALL_CLICK
	removeobject 6
	waitse
	delay 30
	removeobject 5
	playse SE_RG_BAG_POCKET
	waitse
	setvar VAR_GYARADOS_FIGHT, 2
	setflag FLAG_HIDE_GYARADOS
	fadedefaultbgm
	releaseall
	end

GyaradosFight_2:
	call GyaradosExit
	goto GyaradosFight_1


GyaradosExit::
	resetweather
	doweather
	applymovement 2, Gyarados_2
	delay 90
	applymovement 2, Gyarados_3
	delay 90
	applymovement 2, Gyarados_4
	delay 90
	applymovement 2, Gyarados_5
	waitmovement 0
	delay 60
	playmoncry SPECIES_GYARADOS, 11
	waitmoncry
	playse SE_M_DIVE
	hideobjectat 2, MAP_TESTING
	delay 30
	msgbox GyaradosDive, MSGBOX_AUTOCLOSE
	closemessage
	return


GyaradosFightOutro::
	lockall
	applymovement 1, NPC_2
	waitmovement 0
	msgbox NPC_Talk_3, MSGBOX_AUTOCLOSE
	waitmessage
	closemessage
	applymovement 1, NPC_3
	waitmovement 0
	removeobject 1
	setmetatile 6, 9, 0x1E4, TRUE
	setmetatile 7, 9, 0x1E5, TRUE
	setmetatile 6, 12, 0x001, FALSE
	setmetatile 6, 13, 0x001, FALSE
	setmetatile 7, 12, 0x001, FALSE
	setmetatile 7, 13, 0x001, FALSE
	setmetatile 6, 10, 0x001, FALSE
	setmetatile 6, 11, 0x001, FALSE
	setmetatile 7, 10, 0x001, FALSE
	setmetatile 7, 11, 0x001, FALSE
	setmetatile 8, 9, 0x001, FALSE
	setmetatile 9, 9, 0x001, FALSE
	setmetatile 8, 10, 0x001, FALSE
	setmetatile 9, 10, 0x001, FALSE
	setmetatile 8, 11, 0x1CE, FALSE
	setmetatile 9, 11, 0x1CF, FALSE
	setvar VAR_GYARADOS_FIGHT, 3
	setflag FLAG_HIDE_NPC_1
	releaseall
	end


RaichuJoinTeam::
	msgbox Raichu_Join_Team, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq RaichuJoinTeam_2
	msgbox Raichu_Refusal
	waitmessage
	waitbuttonpress
	setflag FLAG_SYS_POKEMON_GET
	playse SE_BALL_THROW
	addobject 4, MAP_TESTING
	delay 30
	removeobject 3, MAP_TESTING
	playse SE_RG_BALL_CLICK
	waitse
	playfanfare MUS_OBTAIN_BADGE
	msgbox Raichu_Obtained, MSGBOX_AUTOCLOSE
	givemon SPECIES_RAICHU, 75, ITEM_FOCUS_SASH
	waitmessage
	waitfanfare
	closemessage
	playse SE_RG_BAG_POCKET
	removeobject 4, MAP_TESTING
RaichuJoinTeam_1:
	return

RaichuJoinTeam_2:
	setflag FLAG_SYS_POKEMON_GET
	playse SE_BALL_THROW
	addobject 4, MAP_TESTING
	delay 30
	removeobject 3, MAP_TESTING
	playse SE_RG_BALL_CLICK
	waitse
	playfanfare MUS_OBTAIN_BADGE
	msgbox Raichu_Obtained, MSGBOX_AUTOCLOSE
	givemon SPECIES_RAICHU, 75, ITEM_FOCUS_SASH
	waitmessage
	waitfanfare
	closemessage
	playse SE_RG_BAG_POCKET
	removeobject 4, MAP_TESTING
	goto RaichuJoinTeam_1


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

Player_4:
	emote_exclamation_mark
	face_left
	step_end

Player_Turn_Back:
	face_right
	walk_right
	step_end

NPC_1:
	face_down
	emote_exclamation_mark
	step_end

NPC_2:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	step_end

NPC_3:
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Gyarados_1:
	walk_down
	walk_down
	walk_in_place_fast_down
	step_end

Gyarados_2:
	walk_slow_up
	step_end

Gyarados_3:
	face_left
	step_end

Gyarados_4:
	face_right
	step_end

Gyarados_5:
	face_down
	step_end

Raichu_1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fast_right
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
	.string "Please, do something!! \p$"

NPC_Talk_2::
	.string "NPC: Where are you going?! \p"
	.string "Please, help!!!$"

NPC_Talk_3::
	.string "NPC: Wow! \p"
	.string "Simply amazing! \p"
	.string "I cannot believe you took down that \n"
	.string "beast with such ease. \p"
	.string "Thank you, traveler.$"

Raichu_Join_Team::
	.string "This Raichu seems to want to help you fight \n"
	.string "Gyarados. \p"
	.string "Will you let Raichu join you?$"

Raichu_Obtained::
	.string "Raichu joined your team!$"

Raichu_Refusal::
	.string "But the look in its eyes is so determined…$"

GyaradosDive::
	.string "The Gyarados dove back into the deep…$"
