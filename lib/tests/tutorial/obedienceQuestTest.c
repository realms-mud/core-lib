//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object StateMachineService;
string QuestPath =
    "/tutorial/temple/stateMachine/obedienceStateMachine.c";

/////////////////////////////////////////////////////////////////////////////
private object getStateMachine()
{
    return StateMachineService->getStateMachine(QuestPath,
        Player->RealName());
}

/////////////////////////////////////////////////////////////////////////////
private void enterRoom(string roomPath)
{
    object room = load_object(roomPath);
    room->enterEnvironment(Player);
}

/////////////////////////////////////////////////////////////////////////////
private void advanceStateMachine(string event)
{
    object sm = getStateMachine();
    sm->receiveEvent(Player, event);
}

/////////////////////////////////////////////////////////////////////////////
private void beginQuest()
{
    enterRoom("/tutorial/temple/environment/rooms/pedestal-1x1.c");
    command("resetEverything", Player);
    command("get rune", Player);
    command("place resistance", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void advanceToFirstTest()
{
    command("2", Player);
    command("1", Player);
    command("2", Player);
    command("1", Player);
    command("2", Player);
    command("1", Player);
    command("2", Player);
    command("1", Player);
    command("1", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void openFirstPassage()
{
    command("press envy", Player);
    command("press envy", Player);
    command("press envy", Player);
    command("press fear", Player);
    command("press fear", Player);
    command("press wrath", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void traverseFirstPassage()
{
    command("e", Player);
    command("s", Player);
    command("e", Player);
    command("e", Player);
    command("s", Player);
    command("w", Player);
    command("s", Player);
    command("e", Player);
    command("e", Player);
    command("n", Player);
    command("n", Player);
    command("n", Player);
    command("e", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void solveMagicSquare()
{
    // Magic square puzzle: each empty cell (initial "E") must be cycled
    // to its solved value. The cycle is E -> Y -> A -> F -> H -> Y -> ...
    // Buttons: W=A1(->Y:1), S=A3(->F:3), A=B1(->F:3), F=B4(->A:2),
    //          N=C1(->H:4), R=C4(->Y:1), P=D1(->A:2), E=D2(->Y:1),
    //          D=D3(->H:4), T=D4(->F:3)
    command("push W", Player);

    command("push S", Player);
    command("push S", Player);
    command("push S", Player);

    command("push A", Player);
    command("push A", Player);
    command("push A", Player);

    command("push F", Player);
    command("push F", Player);

    command("push N", Player);
    command("push N", Player);
    command("push N", Player);
    command("push N", Player);

    command("push R", Player);

    command("push P", Player);
    command("push P", Player);

    command("push E", Player);

    command("push D", Player);
    command("push D", Player);
    command("push D", Player);
    command("push D", Player);

    command("push T", Player);
    command("push T", Player);
    command("push T", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void advanceToSecondTest()
{
    advanceToFirstTest();
    enterRoom("/tutorial/temple/environment/rooms/pedestal-square.c");
    solveMagicSquare();
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "enterRoom", "getStateMachine",
        "advanceStateMachine", "beginQuest", "advanceToFirstTest",
        "solveMagicSquare", "advanceToSecondTest" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    StateMachineService = getService("stateMachine");
    getService("environment");

    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("Gorthaur");
    Player->Str(10);
    Player->Int(10);
    Player->Wis(10);
    Player->Dex(10);
    Player->Con(10);
    Player->Chr(10);
    Player->addSkillPoints(100);
    Player->advanceSkill("mathematics", 5);
    Player->advanceSkill("spellcraft", 5);
    Player->advanceSkill("diplomacy", 5);

    set_this_player(Player);
    Player->addCommands();
    Player->colorConfiguration("none");

    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    ToggleCallOutBypass();
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanEnterPedestalRoomAndGetRune()
{
    enterRoom("/tutorial/temple/environment/rooms/pedestal-1x1.c");

    object room = environment(Player);
    ExpectTrue(objectp(room));

    object rune = present("rune", room);

    ExpectTrue(objectp(rune), "resistance rune is present");
    ExpectEq("resistance", rune->getRuneType());

    command("get rune", Player);
    ExpectTrue(present("rune", Player), "rune is in player inventory");
}

/////////////////////////////////////////////////////////////////////////////
void PickingUpRuneBeginsQuestAndAdvancesToStartingTheTest()
{
    enterRoom("/tutorial/temple/environment/rooms/pedestal-1x1.c");
    command("get rune", Player);

    ExpectEq("starting the test",
        Player->questState(QuestPath));
}

/////////////////////////////////////////////////////////////////////////////
void PlacingResistanceRuneOnWallAdvancesToResistanceRunePlaced()
{
    beginQuest();

    ExpectEq("resistance rune placed",
        Player->questState(QuestPath));
}

/////////////////////////////////////////////////////////////////////////////
void UhrdalenSpawnsAfterResistanceRunePlaced()
{
    beginQuest();

    object sm = getStateMachine();
    object uhrdalen = sm->getUhrdalen();
    ExpectTrue(objectp(uhrdalen), "uhrdalen was spawned");
}

/////////////////////////////////////////////////////////////////////////////
void StartFirstTestAdvancesQuestAndOpensPedestalExit()
{
    beginQuest();
    advanceToFirstTest();

    ExpectEq("first test", Player->questState(QuestPath));

    enterRoom("/tutorial/temple/environment/rooms/pedestal-1x1.c");
    ExpectEq("first test", environment(Player)->currentState());
}

/////////////////////////////////////////////////////////////////////////////
void UhrdalenIsHiddenAfterFirstTestBegins()
{
    beginQuest();

    object sm = getStateMachine();
    object uhrdalen = sm->getUhrdalen();
    ExpectTrue(objectp(uhrdalen), "uhrdalen was spawned");
    ExpectEq(environment(Player), environment(uhrdalen),
        "uhrdalen is in the player room");

    advanceStateMachine("startFirstTest");

    ExpectNotEq(environment(Player), environment(uhrdalen),
        "uhrdalen moved to holding room");
}

/////////////////////////////////////////////////////////////////////////////
void CompletingPedestalPuzzleOpensPassage()
{
    beginQuest();
    advanceToFirstTest();

    object room = environment(Player);
    object pedestal = present("pedestal-hidden", room);
    ExpectTrue(objectp(pedestal), "pedestal is present");

    openFirstPassage();

    ExpectSubStringMatch("allowing safe passage",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanTraverseFirstTestPathToMagicSquareRoom()
{
    beginQuest();
    advanceToFirstTest();

    openFirstPassage();
    traverseFirstPassage();

    ExpectEq("first test", environment(Player)->currentState());
    ExpectEq(load_object("/tutorial/temple/environment/rooms/pedestal-square.c"), 
        environment(Player));

    solveMagicSquare();

    ExpectEq("second test", Player->questState(QuestPath));
}

/*
/////////////////////////////////////////////////////////////////////////////
void CompletingMagicSquareAdvancesToSecondTest()
{
    advanceToSecondTest();

    ExpectEq("second test", Player->questState(QuestPath));
}

/////////////////////////////////////////////////////////////////////////////
void NegationRuneAppearsAfterMagicSquareCompleted()
{
    advanceToSecondTest();

    object rune = present("rune", environment(Player));
    ExpectTrue(objectp(rune), "negation rune appeared");
    ExpectEq("negation", rune->getRuneType());
}

/////////////////////////////////////////////////////////////////////////////
void CanPickUpNegationRuneAfterMagicSquare()
{
    advanceToSecondTest();

    command("get rune", Player);
    ExpectTrue(present("rune", Player), "negation rune picked up");
}

/////////////////////////////////////////////////////////////////////////////
void PedestalPilonHasCorrectStateInSecondTest()
{
    advanceToSecondTest();

    enterRoom("/tutorial/temple/environment/rooms/pedestal-pilon.c");

    object room = environment(Player);
    ExpectEq("second test", room->currentState());
}

/////////////////////////////////////////////////////////////////////////////
void CanPlaceNegationRuneOnWall()
{
    advanceToSecondTest();
    command("get rune", Player);

    enterRoom("/tutorial/temple/environment/rooms/pedestal-1x1.c");

    command("place negation", Player);
    ExpectSubStringMatch("place.*rune of negation",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void QuestStateAdvancesCorrectlyThroughAllEarlyTransitions()
{
    enterRoom("/tutorial/temple/environment/rooms/pedestal-1x1.c");

    ExpectFalse(Player->questState(QuestPath));

    command("get rune", Player);
    ExpectEq("starting the test",
        Player->questState(QuestPath));

    command("place resistance", Player);
    ExpectEq("resistance rune placed",
        Player->questState(QuestPath));

    advanceStateMachine("startFirstTest");
    ExpectEq("first test",
        Player->questState(QuestPath));

    enterRoom("/tutorial/temple/environment/rooms/pedestal-square.c");
    solveMagicSquare();
    ExpectEq("second test",
        Player->questState(QuestPath));
}

/////////////////////////////////////////////////////////////////////////////
void EnvironmentStateMatchesQuestStateAfterEveryTransition()
{
    enterRoom("/tutorial/temple/environment/rooms/pedestal-1x1.c");
    object room = environment(Player);

    command("get rune", Player);
    ExpectEq("starting the test", Player->questState(QuestPath));

    ToggleCallOutBypass();
    command("place resistance", Player);
    ExpectEq("resistance rune placed", room->currentState());

    advanceStateMachine("startFirstTest");
    ExpectEq("first test", room->currentState());
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void StateIsPreservedWhenReEnteringPedestalRoom()
{
    advanceToSecondTest();

    ExpectEq("second test", Player->questState(QuestPath));

    enterRoom("/tutorial/temple/environment/rooms/pedestal-1x1.c");
    ExpectEq("second test", environment(Player)->currentState());
}

/////////////////////////////////////////////////////////////////////////////
void StateIsPreservedWhenReEnteringPilonRoom()
{
    advanceToSecondTest();

    ExpectEq("second test", Player->questState(QuestPath));

    enterRoom("/tutorial/temple/environment/rooms/pedestal-pilon.c");
    ExpectEq("second test", environment(Player)->currentState());
}

/////////////////////////////////////////////////////////////////////////////
void AllRoomsGetCorrectStateFromStateMachine()
{
    advanceToFirstTest();

    enterRoom("/tutorial/temple/environment/rooms/pedestal-1x2.c");
    ExpectEq("first test", environment(Player)->currentState());

    enterRoom("/tutorial/temple/environment/rooms/pedestal-1x5.c");
    ExpectEq("first test", environment(Player)->currentState());

    enterRoom("/tutorial/temple/environment/rooms/pedestal-square.c");
    ExpectEq("first test", environment(Player)->currentState());
}

/////////////////////////////////////////////////////////////////////////////
void SubsequentTestTransitionsUpdateQuestState()
{
    advanceToSecondTest();

    ExpectEq("second test",
        Player->questState(QuestPath));

    advanceStateMachine("startThirdTest");
    ExpectEq("third test",
        Player->questState(QuestPath));

    advanceStateMachine("startFourthTest");
    ExpectEq("fourth test",
        Player->questState(QuestPath));

    advanceStateMachine("startFifthTest");
    ExpectEq("fifth test",
        Player->questState(QuestPath));

    advanceStateMachine("startSixthTest");
    ExpectEq("sixth test",
        Player->questState(QuestPath));

    advanceStateMachine("startSeventhTest");
    ExpectEq("seventh test",
        Player->questState(QuestPath));
}

/////////////////////////////////////////////////////////////////////////////
void QuestCompletionMarksQuestAsComplete()
{
    advanceToSecondTest();

    advanceStateMachine("startThirdTest");
    advanceStateMachine("startFourthTest");
    advanceStateMachine("startFifthTest");
    advanceStateMachine("startSixthTest");
    advanceStateMachine("startSeventhTest");
    advanceStateMachine("questCompleted");

    ExpectEq("quest complete",
        Player->questState(QuestPath));
    ExpectTrue(Player->questIsCompleted(QuestPath));
}

/////////////////////////////////////////////////////////////////////////////
void RoomStateMatchesQuestStateAfterAllTransitions()
{
    advanceToSecondTest();

    advanceStateMachine("startThirdTest");
    advanceStateMachine("startFourthTest");
    advanceStateMachine("startFifthTest");

    enterRoom("/tutorial/temple/environment/rooms/pedestal-1x1.c");
    ExpectEq("fifth test", environment(Player)->currentState());

    enterRoom("/tutorial/temple/environment/rooms/pedestal-2x1.c");
    ExpectEq("fifth test", environment(Player)->currentState());
}

/////////////////////////////////////////////////////////////////////////////
void InitSyncsEnvironmentStateFromPlayerQuestState()
{
    advanceToSecondTest();

    ExpectEq("second test", Player->questState(QuestPath));

    advanceStateMachine("startThirdTest");
    ExpectEq("third test", Player->questState(QuestPath));

    enterRoom("/tutorial/temple/environment/rooms/pedestal-pilon.c");
    ExpectEq("third test", environment(Player)->currentState());
}
*/