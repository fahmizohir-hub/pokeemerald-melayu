SootopolisCity_House2_MapScripts::
	.byte 0

SootopolisCity_House2_EventScript_ExpertF::
	lock
	faceplayer
	msgbox SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, SootopolisCity_House2_EventScript_KnowAboutOrbs
	call_if_eq VAR_RESULT, NO, SootopolisCity_House2_EventScript_DontKnowAboutOrbs
	release
	end

SootopolisCity_House2_EventScript_KnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_YesTwoOrbsSideBySide, MSGBOX_DEFAULT
	return

SootopolisCity_House2_EventScript_DontKnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_OughtToVisitAndSee, MSGBOX_DEFAULT
	return

SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs:
	.string "GUNUNG PYRE…\p"
	.string "Di puncaknya ada dua mestika diletak\n"
	.string "bersebelahan. Kamu tahu?$"

SootopolisCity_House2_Text_YesTwoOrbsSideBySide:
	.string "Ya, dua mestika bersebelahan…\p"
	.string "Melihat mereka bersama…\n"
	.string "Entah kenapa, rasa tenang…$"

SootopolisCity_House2_Text_OughtToVisitAndSee:
	.string "Begitukah?\n"
	.string "Mungkin kamu patut pergi tengok…$"

