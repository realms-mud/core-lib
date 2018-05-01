//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Intro;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    ToggleCallOutBypass();
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("Frank");
    Player->Gender(1);
    Player->addCommands();

    move_object(Player, "/lib/tutorial/rooms/battleScene.c");

    Intro = clone_object("/lib/tutorial/stateMachines/introStateMachine.c");
    Intro->registerEvent(Player);
    Intro->beginIntroduction(Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void InitialConversationCorrectlyFired()
{
    ExpectEq(7, sizeof(Player->caughtMessages()));
    ExpectSubStringMatch("On a long campaign, sometimes routine is", 
        Player->caughtMessages()[0]);
    ExpectSubStringMatch("Basil, your company commander, imparted these words",
        Player->caughtMessages()[1]);
    ExpectSubStringMatch("Basil was an expert in crushing hope too",
        Player->caughtMessages()[2]);
    ExpectSubStringMatch("Get up, damn it!",
        Player->caughtMessages()[3]);
    ExpectSubStringMatch("By the gods, Galadhel, I can't find the words",
        Player->caughtMessages()[4]);
    ExpectSubStringMatch("Say nothing",
        Player->caughtMessages()[5]);
    ExpectSubStringMatch("I'm not dead yet",
        Player->caughtMessages()[6]);
}
