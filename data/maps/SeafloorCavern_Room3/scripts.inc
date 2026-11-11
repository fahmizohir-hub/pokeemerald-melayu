SeafloorCavern_Room3_MapScripts::
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_5, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_Text_ShellyIntro:
	.string "Ahahahaha!\p"
	.string "Macam mana kau boleh sampai sini tanpa\n"
	.string "kapal selam? Hebat betul budak ni!\p"
	.string "Tapi… Aku tak boleh biar\n"
	.string "kau masuk campur di sini.\p"
	.string "Lagipun, aku memang nak balas dendam\n"
	.string "atas apa yang jadi di INSTITUT CUACA…\p"
	.string "Aku nak bagi kau rasa\n"
	.string "sakit sikit! Redha sajalah!$"

SeafloorCavern_Room3_Text_ShellyDefeat:
	.string "Ahahahaha!\p"
	.string "Aduh!$"

SeafloorCavern_Room3_Text_ShellyPostBattle:
	.string "Ahahahaha! Kau memang kuat sangat.\p"
	.string "Sayang betul kau bukan ahli TEAM AQUA.\p"
	.string "Kalau kau salah seorang daripada\n"
	.string "kami, kau boleh nikmati dunia\l"
	.string "hebat yang BOS kami janjikan…$"

SeafloorCavern_Room3_Text_Grunt5Intro:
	.string "Untuk jadikan impian kami nyata, kami\n"
	.string "perlukan kuasa POKéMON.\p"
	.string "Tapi penyibuk macam kau guna kuasa\n"
	.string "POKéMON untuk kacau kami, walaupun\l"
	.string "di tempat macam ni!\p"
	.string "Hidup ni memang tak pernah ikut\n"
	.string "kehendak kami!$"

SeafloorCavern_Room3_Text_Grunt5Defeat:
	.string "Gwah!$"

SeafloorCavern_Room3_Text_Grunt5PostBattle:
	.string "Kau tahu, kami tak berani persoalkan\n"
	.string "niat ketua kami.\p"
	.string "Tapi kau ni, cuma budak hingusan, berani\n"
	.string "lawan BOS kami.\p"
	.string "Mungkin…\n"
	.string "Kau ni memang istimewa…$"

