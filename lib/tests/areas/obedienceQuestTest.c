//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object StateMachineService;
string QuestPath =
    "/areas/tol-dhurath/state-machine/obedience-quest.c";

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
private void traverseFirstUhrdalenConversation()
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
private void traverseSecondUhrdalenConversation()
{
    command("1", Player);
    command("1", Player);
    command("1", Player);
    command("1", Player);
    command("1", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void traverseThirdUhrdalenConversation()
{
    command("1", Player);
    command("1", Player);
    command("1", Player);
    command("1", Player);
    command("1", Player);
    command("1", Player);
    command("1", Player);
    command("1", Player);
    command("1", Player);
    command("1", Player);
    command("1", Player);
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
private void openSecondPassage()
{
    command("press envy", Player);
    command("press fear", Player);
    command("press sorrow", Player);
    command("press wrath", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void openThirdPassage()
{
    command("press envy", Player);
    command("press envy", Player);
    command("press envy", Player);
    command("press envy", Player);
    command("press fear", Player);
    command("press fear", Player);
    command("press fear", Player);
    command("press fear", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void traverseSecondPassage()
{
    command("s", Player);
    command("e", Player);
    command("s", Player);
    command("e", Player);
    command("s", Player);
    command("s", Player);
    command("e", Player);
    command("n", Player);
    command("n", Player);
    command("n", Player);
    command("e", Player);
    command("e", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void traverseThirdPassage()
{
    command("e", Player);
    command("s", Player);
    command("s", Player);
    command("e", Player);
    command("n", Player);
    command("n", Player);
    command("e", Player);
    command("s", Player);
    command("s", Player);
    command("s", Player);
    command("w", Player);
    command("s", Player);
    command("e", Player);
    command("e", Player);
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
private void solveVisionQuest()
{
    command("order m 4", Player);
    command("order r 1", Player);
    command("order q 6", Player);
    command("order w 3", Player);
    command("order k 2", Player);
    command("order p 5", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void solveCrucibleQuest()
{
    command("touch flame", Player);
    command("touch flame", Player);
    command("touch flame", Player);
    command("touch frost", Player);
    command("touch frost", Player);
    command("touch frost", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void traverseFourthUhrdalenConversation()
{
    command("1", Player);
    command("1", Player);
    command("1", Player);
    command("1", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void openFourthPassage()
{
    command("press envy", Player);
    command("press fear", Player);
    command("press sorrow", Player);
    command("press wrath", Player);
    command("press envy", Player);
    command("press fear", Player);
    command("press sorrow", Player);
    command("press wrath", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void traverseFourthPassage()
{
    command("e", Player);
    command("e", Player);
    command("e", Player);
    command("s", Player);
    command("w", Player);
    command("s", Player);
    command("w", Player);
    command("s", Player);
    command("e", Player);
    command("e", Player);
    command("e", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void solveMirrorQuest()
{
    command("ignore shadow", Player);
    command("ignore shadow", Player);
    command("ignore shadow", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void traverseFifthUhrdalenConversation()
{
    command("1", Player);
    command("1", Player);
    command("1", Player);
    command("1", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void openFifthPassage()
{
    command("press sorrow", Player);
    command("press wrath", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void traverseFifthPassage()
{
    command("e", Player);
    command("s", Player);
    command("s", Player);
    command("e", Player);
    command("s", Player);
    command("w", Player);
    command("w", Player);
    command("s", Player);
    command("e", Player);
    command("e", Player);
    command("e", Player);
    command("n", Player);
    command("n", Player);
    command("n", Player);
    command("e", Player);
    command("s", Player);
    command("s", Player);
    command("e", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void solveDreamQuest()
{
    command("touch pool", Player);
    command("n", Player);
    command("accept", Player);
    command("n", Player);
    command("obey", Player);
    command("n", Player);
    command("submit", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void traverseSixthUhrdalenConversation()
{
    command("1", Player);
    command("1", Player);
    command("1", Player);
    command("1", Player);
    command("1", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void openSixthPassage()
{
    command("press envy", Player);
    command("press fear", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void traverseSixthPassage()
{
    command("s", Player);
    command("e", Player);
    command("n", Player);
    command("e", Player);
    command("s", Player);
    command("s", Player);
    command("s", Player);
    command("w", Player);
    command("s", Player);
    command("e", Player);
    command("e", Player);
    command("n", Player);
    command("n", Player);
    command("n", Player);
    command("e", Player);
    command("s", Player);
    command("s", Player);
    command("s", Player);
    command("e", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void solveGauntletQuest()
{
    command("begin gauntlet", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void openSeventhPassage()
{
    command("press fear", Player);
    command("press fear", Player);
    command("press fear", Player);
    command("press wrath", Player);
    command("press wrath", Player);
    command("press envy", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void traverseSeventhPassage()
{
    command("s", Player);
    command("s", Player);
    command("s", Player);
    command("s", Player);
    command("e", Player);
    command("e", Player);
    command("n", Player);
    command("w", Player);
    command("n", Player);
    command("e", Player);
    command("e", Player);
    command("n", Player);
    command("n", Player);
    command("e", Player);
    command("s", Player);
    command("s", Player);
    command("s", Player);
    command("s", Player);
    command("s", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void solveSealQuest()
{
    command("cut blade", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void traverseSeilyndriaConversation()
{
    command("1", Player);
    command("1", Player);
    command("1", Player);
    command("1", Player);
    command("1", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void traverseFinalUhrdalenConversation()
{
    command("1", Player);
    command("2", Player);
    command("1", Player);
    command("1", Player);
    command("1", Player);
    command("1", Player);
    command("1", Player);
}

/////////////////////////////////////////////////////////////////////////////
private int isInState(string state)
{
    return (Player->questState(QuestPath) == state) && 
        (environment(Player)->currentState() == state);
}

/////////////////////////////////////////////////////////////////////////////
private int runeAppeared(string runeType)
{
    object rune = present(sprintf("rune of %s", runeType), environment(Player));
    return objectp(rune) && rune->getRuneType() == runeType;
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "enterRoom", "getStateMachine", "traverseFirstPassage",
        "isInState", "openFirstPassage", "solveMagicSquare",
        "traverseFirstUhrdalenConversation", "runeAppeared",
        "traverseSecondUhrdalenConversation",
        "traverseThirdUhrdalenConversation",
        "traverseFourthUhrdalenConversation",
        "traverseFifthUhrdalenConversation",
        "traverseSixthUhrdalenConversation",
        "traverseFinalUhrdalenConversation",
        "openSecondPassage", "traverseSecondPassage", "solveVisionQuest",
        "openThirdPassage", "traverseThirdPassage", "solveCrucibleQuest",
        "openFourthPassage", "traverseFourthPassage", "solveMirrorQuest",
        "openFifthPassage", "traverseFifthPassage", "solveDreamQuest",
        "openSixthPassage", "traverseSixthPassage", "solveGauntletQuest",
        "openSeventhPassage", "traverseSeventhPassage",
        "solveSealQuest", "traverseSeilyndriaConversation",
        "executeFirstChallenge", "executeSecondChallenge",
        "executeThirdChallenge", "executeFourthChallenge",
        "executeFifthChallenge", "executeSixthChallenge",
        "executeFinalChallenge", "executeSealChallenge" });
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
    Player->joinGuild("background");

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
private void executeFirstChallenge()
{
    ExpectTrue(runeAppeared("resistance"),
        "resistance rune appeared in the room");

    command("get rune", Player);

    ExpectTrue(isInState("starting the test"),
        "player is in starting the test state");

    command("place resistance", Player);

    ExpectTrue(isInState("resistance rune placed"),
        "player is in resistance rune placed state");

    object stateMachine = getStateMachine();
    object uhrdalen = stateMachine->getUhrdalen();

    ExpectTrue(objectp(uhrdalen), "uhrdalen was spawned");
    ExpectEq(environment(Player), environment(uhrdalen),
        "uhrdalen is in the player room");

    traverseFirstUhrdalenConversation();

    ExpectNotEq(environment(Player), environment(uhrdalen),
        "uhrdalen moved to holding room");

    ExpectTrue(isInState("first test"), "player is in first test state");

    openFirstPassage();

    ExpectSubStringMatch("allowing safe passage",
        implode(Player->caughtMessages(), "\n"));

    traverseFirstPassage();

    ExpectTrue(isInState("first test"),
        "player is still in first test state");

    ExpectEq(load_object("/areas/tol-dhurath/temple-interior/pedestal-square.c"),
        environment(Player));

    solveMagicSquare();

    ExpectTrue(runeAppeared("negation"),
        "negation rune appeared in the room after solving magic square");

    ExpectTrue(isInState("second test"),
        "player is in second test state");

    command("get rune", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void executeSecondChallenge()
{
    command("e", Player);

    object stateMachine = getStateMachine();
    object uhrdalen = stateMachine->getUhrdalen();

    ExpectEq(environment(Player), environment(uhrdalen),
        "uhrdalen is in the player room");
    traverseSecondUhrdalenConversation();

    ExpectNotEq(environment(Player), environment(uhrdalen),
        "uhrdalen moved to holding room");

    openSecondPassage();

    ExpectSubStringMatch("allowing safe passage",
        implode(Player->caughtMessages(), "\n"));
    traverseSecondPassage();

    ExpectEq(load_object("/areas/tol-dhurath/temple-interior/pedestal-pilon.c"),
        environment(Player));

    solveVisionQuest();
    ExpectTrue(runeAppeared("strength"),
        "strength rune appeared in the room after solving echoes");
    ExpectTrue(runeAppeared("weakness"),
        "weakness rune appeared in the room after solving echoes");

    ExpectTrue(isInState("third test"),
        "player is in third test state");

    command("get all", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void executeThirdChallenge()
{
    object stateMachine = getStateMachine();
    object uhrdalen = stateMachine->getUhrdalen();

    command("e", Player);

    ExpectEq(environment(Player), environment(uhrdalen),
        "uhrdalen is in the player room after echo pool");

    traverseThirdUhrdalenConversation();

    ExpectNotEq(environment(Player), environment(uhrdalen),
        "uhrdalen moved to holding room after third conversation");

    openThirdPassage();

    ExpectSubStringMatch("allowing safe passage",
        implode(Player->caughtMessages(), "\n"));

    traverseThirdPassage();

    ExpectEq(load_object("/areas/tol-dhurath/temple-interior/chamber-of-sacrifice.c"),
        environment(Player));

    solveCrucibleQuest();
    ExpectTrue(runeAppeared("flame"),
        "flame rune appeared in the room after solving crucible");
    ExpectTrue(runeAppeared("frost"),
        "frost rune appeared in the room after solving crucible");

    ExpectTrue(isInState("fourth test"),
        "player is in fourth test state");

    command("get all", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void executeFourthChallenge()
{
    object stateMachine = getStateMachine();
    object uhrdalen = stateMachine->getUhrdalen();

    command("e", Player);

    ExpectEq(environment(Player), environment(uhrdalen),
        "uhrdalen is in the player room after crucible");

    traverseFourthUhrdalenConversation();

    ExpectNotEq(environment(Player), environment(uhrdalen),
        "uhrdalen moved to holding room after fourth conversation");

    openFourthPassage();

    ExpectSubStringMatch("allowing safe passage",
        implode(Player->caughtMessages(), "\n"));

    traverseFourthPassage();

    ExpectEq(load_object("/areas/tol-dhurath/temple-interior/shadow-mirror-chamber.c"),
        environment(Player));

    solveMirrorQuest();
    ExpectTrue(runeAppeared("fear"),
        "fear rune appeared in the room after solving mirror");
    ExpectTrue(runeAppeared("doom"),
        "doom rune appeared in the room after solving mirror");

    ExpectTrue(isInState("fifth test"),
        "player is in fifth test state");

    command("get all", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void executeFifthChallenge()
{
    object stateMachine = getStateMachine();
    object uhrdalen = stateMachine->getUhrdalen();

    command("e", Player);

    ExpectEq(environment(Player), environment(uhrdalen),
        "uhrdalen is in the player room after mirror");

    traverseFifthUhrdalenConversation();

    ExpectNotEq(environment(Player), environment(uhrdalen),
        "uhrdalen moved to holding room after fifth conversation");

    openFifthPassage();

    ExpectSubStringMatch("allowing safe passage",
        implode(Player->caughtMessages(), "\n"));

    traverseFifthPassage();

    ExpectEq(load_object("/areas/tol-dhurath/temple-interior/dream-chamber.c"),
        environment(Player));

    solveDreamQuest();
    ExpectTrue(runeAppeared("wisdom"),
        "wisdom rune appeared in the room after solving dream");
    ExpectTrue(runeAppeared("endurance"),
        "endurance rune appeared in the room after solving dream");

    ExpectTrue(isInState("sixth test"),
        "player is in sixth test state");

    command("get all", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void executeSixthChallenge()
{
    object stateMachine = getStateMachine();
    object uhrdalen = stateMachine->getUhrdalen();

    command("e", Player);

    ExpectEq(environment(Player), environment(uhrdalen),
        "uhrdalen is in the player room after dream");

    traverseSixthUhrdalenConversation();

    ExpectNotEq(environment(Player), environment(uhrdalen),
        "uhrdalen moved to holding room after sixth conversation");

    openSixthPassage();

    ExpectSubStringMatch("allowing safe passage",
        implode(Player->caughtMessages(), "\n"));

    traverseSixthPassage();

    ExpectEq(load_object("/areas/tol-dhurath/temple-interior/chamber-of-targets.c"),
        environment(Player));

    solveGauntletQuest();
    ExpectTrue(runeAppeared("death"),
        "death rune appeared in the room after solving gauntlet");

    ExpectTrue(isInState("seventh test"),
        "player is in seventh test state");

    command("get all", Player);
}

/////////////////////////////////////////////////////////////////////////////
private void executeFinalChallenge()
{
    object stateMachine = getStateMachine();
    object uhrdalen = stateMachine->getUhrdalen();

    command("e", Player);

    ExpectEq(environment(Player), environment(uhrdalen),
        "uhrdalen is in the player room for final conversation");

    traverseFinalUhrdalenConversation();

    ExpectNotEq(environment(Player), environment(uhrdalen),
        "uhrdalen moved to holding room after final conversation");

    ExpectTrue(present("envy", Player),
        "player has the rune of envy in inventory");

    ExpectFalse(Player->questIsCompleted(QuestPath),
        "quest is not completed");

    command("place negation", Player);
    command("place strength", Player);
    command("place weakness", Player);
    command("place flame", Player);
    command("place frost", Player);
    command("place fear", Player);
    command("place doom", Player);
    command("place wisdom", Player);
    command("place endurance", Player);
    command("place death", Player);
    command("place envy", Player);

    ExpectTrue(isInState("poem complete"),
        "player is in poem complete state after placing all runes");

    ExpectFalse(Player->questIsCompleted(QuestPath),
        "quest is not completed after placing all runes");
}

/////////////////////////////////////////////////////////////////////////////
private void executeSealChallenge()
{
    openSeventhPassage();

    ExpectSubStringMatch("allowing safe passage",
        implode(Player->caughtMessages(), "\n"));

    traverseSeventhPassage();

    ExpectEq(load_object("/areas/tol-dhurath/temple-interior/chamber-of-kings.c"),
        environment(Player));

    solveSealQuest();

    traverseSeilyndriaConversation();

    ExpectTrue(Player->questIsCompleted(QuestPath),
        "quest is completed");
}

/////////////////////////////////////////////////////////////////////////////
void CanCompleteObedienceQuest()
{
    enterRoom("/areas/tol-dhurath/temple-interior/pedestal-1x1.c");
    command("resetEverything", Player);

    executeFirstChallenge();

    executeSecondChallenge();

    executeThirdChallenge();

    executeFourthChallenge();

    executeFifthChallenge();

    executeSixthChallenge();

    executeFinalChallenge();

    executeSealChallenge();
    ExpectEq(1000, Player->effectiveExperience());
}
