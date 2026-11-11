RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "Yo, apa khabar?\p"
	.string "Dengar sini, kawan! Kamu nak\n"
	.string "jadi JUARA?\p"
	.string "Saya ni bukan JURULATIH, tapi saya\n"
	.string "boleh beri nasihat supaya kamu menang.\p"
	.string "Kalau macam tu, setuju! Kita sama-sama\n"
	.string "sasarkan KEJUARAAN POKéMON!\p"
	.string "Tugas kamu sebagai JURULATIH ialah\n"
	.string "kumpul LENCANA GIM, betul tak?\p"
	.string "Tapi KETUA GIM bukannya\n"
	.string "mudah dikalahkan!\p"
	.string "Sebab tulah saya ada! Saya sedia beri\n"
	.string "nasihat pakar!\p"
	.string "ROXANNE, KETUA GIM ni, guna POKéMON\n"
	.string "jenis BATU.\p"
	.string "Jenis BATU sangat tahan lasak, tapi ia\n"
	.string "tak tahan move jenis AIR dan\l"
	.string "jenis RUMPUT.\p"
	.string "Kalau dah kalahkan KETUA GIM nanti,\n"
	.string "datang jumpa saya.\p"
	.string "Okey, ayuh, buat yang terbaik!$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "Wah! Kemenangan yang memukau! Sorakan\n"
	.string "saya mesti berkesan!\p"
	.string "Bagus! Periksa KAD JURULATIH kamu.\p"
	.string "LENCANA BATU yang kamu dapat patutnya\n"
	.string "dah direkodkan di situ.\p"
	.string "Maksudnya…\p"
	.string "Kamu dah naik anak tangga pertama ke\n"
	.string "arah KEJUARAAN!\p"
	.string "Mesti rasa hebat, kan!$"

RustboroCity_Gym_Text_JoshIntro:
	.string "Jangan pandang rendah JURULATIH GIM\n"
	.string "macam kami! Biar saya tunjuk kenapa\l"
	.string "kami lebih hebat!$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "Kamu terlalu hebat untuk saya…$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "Kamu belum tengok lagi kuasa dahsyat\n"
	.string "jenis BATU!$"

RustboroCity_Gym_Text_TommyIntro:
	.string "Kalau tak boleh kalahkan saya, kamu tak\n"
	.string "ada peluang lawan ROXANNE!$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "Wah! Kamu ada potensi!$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "ROXANNE berkali-kali ganda lebih kuat\n"
	.string "daripada saya.\p"
	.string "Baik kamu berwaspada!$"

RustboroCity_Gym_Text_MarcIntro:
	.string "Memanglah kita di tengah bandar, tapi\n"
	.string "peduli apa?\p"
	.string "POKéMON BATU saya perlukan ruang\n"
	.string "untuk mengamuk!$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "Aduh, aduhai! Pencabar kita ni memang\n"
	.string "garang!$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "Saya memang kagum dengan KETUA kami.\p"
	.string "Muda-muda lagi dia dah bijak pilih\n"
	.string "jenis BATU.$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "Helo, saya ROXANNE, KETUA GIM\n"
	.string "POKéMON RUSTBORO.\p"
	.string "Saya jadi KETUA GIM supaya dapat\n"
	.string "praktikkan dalam pertarungan apa yang\l"
	.string "saya belajar di SEKOLAH\l"
	.string "JURULATIH POKéMON.\p"
	.string "Sudi tak kamu tunjukkan cara kamu\n"
	.string "bertarung, dan POKéMON apa yang\l"
	.string "kamu guna?$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "Jadi… Saya kalah…\p"
	.string "Nampaknya masih banyak lagi yang perlu\n"
	.string "saya pelajari…\p"
	.string "Saya faham.\p"
	.string "Peraturan LIGA POKéMON menyatakan\n"
	.string "JURULATIH mesti diberi ini kalau mereka\l"
	.string "kalahkan KETUA GIM.\p"
	.string "Sila terima LENCANA BATU rasmi LIGA\n"
	.string "POKéMON.$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER} menerima LENCANA BATU\n"
	.string "daripada ROXANNE.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "LENCANA BATU meningkatkan kuasa\n"
	.string "SERANGAN POKéMON kamu.\p"
	.string "Dengan lencana ni, POKéMON kamu juga\n"
	.string "boleh guna HM POTONGAN di\l"
	.string "luar pertarungan.\p"
	.string "Ambillah ini juga.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "MESIN TEKNIKAL itu, TM39, mengandungi\n"
	.string "KUBUR BATU.\p"
	.string "Move ni jatuhkan batu ke atas lawan,\n"
	.string "dan turunkan KELAJUANnya sekali.\p"
	.string "TM akan terus ajar move tu kepada\n"
	.string "POKéMON sebaik saja diguna.\p"
	.string "Ingat, TM hanya boleh diguna sekali,\n"
	.string "jadi fikir dulu sebelum guna.$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "Kamu kuat, jadi kamu patut cabar KETUA\n"
	.string "GIM yang lain.\p"
	.string "Bila bertarung dengan ramai JURULATIH,\n"
	.string "kamu akan belajar banyak perkara.$"

RustboroCity_Gym_Text_GymStatue:
	.string "GIM POKéMON BANDAR RUSTBORO$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "GIM POKéMON BANDAR RUSTBORO\p"
	.string "JURULATIH DIIKTIRAF ROXANNE:\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "… … … … … … … … … … … Bip!\p"
	.string "ROXANNE: Oh, helo, {PLAYER}? Ini ROXANNE\n"
	.string "dari BANDAR RUSTBORO.\p"
	.string "Saya dengar daripada BRAWLY,\n"
	.string "kedudukan kamu dalam kalangan\l"
	.string "JURULATIH naik dengan pantas sekali.\p"
	.string "Saya tak nak percaya yang saya tak\n"
	.string "mampu kalahkan kamu.\p"
	.string "Saya janji, saya akan perkukuh GIM saya\n"
	.string "supaya kamu boleh cabar kami lagi.\p"
	.string "Saya harap kamu pun tak sabar\n"
	.string "macam saya!\p"
	.string "… … … … … … … … … … … Klik!$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "KETUA GIM ROXANNE didaftarkan\n"
	.string "dalam POKéNAV.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "ROXANNE: Gembira sungguh dapat jumpa\n"
	.string "kamu lagi. Saya ROXANNE, KETUA GIM\l"
	.string "di sini.\p"
	.string "Saya pasti kita berdua dah lalui banyak\n"
	.string "pertarungan sejak kita jumpa dulu.\p"
	.string "Saya nak lihat sejauh mana kita dah\n"
	.string "maju. Mari bertarung!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "Grr… Saya kalah lagi…$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string "ROXANNE: Masih banyak yang perlu saya\n"
	.string "pelajari tentang pertarungan POKéMON.\p"
	.string "Sebab itulah saya makin\n"
	.string "suka bertarung!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "ROXANNE: Gembira sungguh dapat jumpa\n"
	.string "kamu lagi. Saya ROXANNE, KETUA GIM\l"
	.string "di sini.\p"
	.string "Saya pasti kita berdua dah lalui banyak\n"
	.string "pertarungan sejak kita jumpa dulu.\p"
	.string "Saya nak lihat sejauh mana kita\n"
	.string "dah maju…\p"
	.string "Oh, tidak… Kamu cuma bawa\n"
	.string "satu POKéMON?\p"
	.string "Sila datang semula dengan\n"
	.string "sekurang-kurangnya satu lagi POKéMON.$"
