VictoryRoad_B2F_MapScripts::
	.byte 0

VictoryRoad_B2F_EventScript_Vito::
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline::
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie::
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix::
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Dianne::
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_Text_VitoIntro:
	.string "Saya berlatih dengan seluruh keluarga\n"
	.string "saya, setiap seorang!\l"
	.string "Saya takkan kalah dengan sesiapa!$"

VictoryRoad_B2F_Text_VitoDefeat:
	.string "Lebih hebat daripada keluarga saya?!\n"
	.string "Mungkinkah?!$"

VictoryRoad_B2F_Text_VitoPostBattle:
	.string "Saya paling hebat dalam keluarga saya.\n"
	.string "Tak pernah saya kalah…\p"
	.string "Saya dah hilang keyakinan…\n"
	.string "Mungkin saya balik saja…$"

VictoryRoad_B2F_Text_OwenIntro:
	.string "Saya dengar ada budak kecil yang hebat\n"
	.string "di sini. Kamu ke orangnya?$"

VictoryRoad_B2F_Text_OwenDefeat:
	.string "Budak kecil ni memang hebat!$"

VictoryRoad_B2F_Text_OwenPostBattle:
	.string "Khabarnya, budak kecil yang hebat tu\n"
	.string "berasal dari BANDAR PETALBURG.$"

VictoryRoad_B2F_Text_CarolineIntro:
	.string "Mesti kamu dah penat sikit.$"

VictoryRoad_B2F_Text_CarolineDefeat:
	.string "Langsung tak nampak penat!$"

VictoryRoad_B2F_Text_CarolinePostBattle:
	.string "JALAN KEMENANGAN dan LIGA POKéMON\n"
	.string "ialah cabaran yang panjang dan berat.\l"
	.string "Hati-hati dengan keletihan!$"

VictoryRoad_B2F_Text_JulieIntro:
	.string "Jangan cepat berpuas hati hanya\n"
	.string "kerana kamu ada banyak LENCANA GIM.\p"
	.string "Akan sentiasa ada orang yang lebih\n"
	.string "hebat daripada kamu!$"

VictoryRoad_B2F_Text_JulieDefeat:
	.string "Kamu lebih hebat daripada saya!$"

VictoryRoad_B2F_Text_JuliePostBattle:
	.string "Tatap LENCANA yang kamu kumpul dan\n"
	.string "ingat JURULATIH yang kamu dah hadapi.$"

VictoryRoad_B2F_Text_FelixIntro:
	.string "Saya dah sampai sejauh ini, tapi\n"
	.string "gemuruh ni buat perut saya sakit…$"

VictoryRoad_B2F_Text_FelixDefeat:
	.string "Aduh…\n"
	.string "Sakitnya…$"

VictoryRoad_B2F_Text_FelixPostBattle:
	.string "Saya tak boleh elak rasa tegang bila\n"
	.string "tahu saya makin hampir ke LIGA POKéMON.\p"
	.string "Saya cuma mampu buat-buat tenang.$"

VictoryRoad_B2F_Text_DianneIntro:
	.string "Golongan elit antara yang elit\n"
	.string "berkumpul di gua ini.\p"
	.string "Macam mana kamu rasa?$"

VictoryRoad_B2F_Text_DianneDefeat:
	.string "Langsung tak gentar!$"

VictoryRoad_B2F_Text_DiannePostBattle:
	.string "Kamu memang berani! Saya suka!\n"
	.string "Teruskan!$"

