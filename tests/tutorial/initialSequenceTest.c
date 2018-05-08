//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Intro;
object Room;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database->PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess->savePlayerData(database->Gorthaur());

    destruct(dataAccess);
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    ToggleCallOutBypass();
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("Gorthaur");
    Player->restore();
    Player->addCommands();

    Room = load_object("/lib/tutorial/rooms/battleScene.c");
    move_object(Player, Room);

    Intro = clone_object("/lib/tutorial/stateMachines/introStateMachine.c");
    Intro->registerEvent(Player);
    Intro->beginIntroduction(Player);

    Player->characterState(find_object("/lib/tutorial/characters/galadhel/galadhel.c"),
        "first conversation");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Room);
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

/////////////////////////////////////////////////////////////////////////////
void CanRespondToBerenarFirstConversationNotDead()
{
    Player->resetCatchList();
    command("2", Player);
    ExpectSubStringMatch("The rumor of my demise",
        Player->caughtMessages()[0]);
    ExpectSubStringMatch("You have my apologies, Gorthaur. Nay, stay down",
        Player->caughtMessages()[1]);
}

/////////////////////////////////////////////////////////////////////////////
void CanRespondToBerenarFirstConversationSayNothing()
{
    Player->resetCatchList();
    command("1", Player);
    /*ExpectEq("The rumor of my demise",
        Player->caughtMessages());// [0]);
    ExpectSubStringMatch("You have my apologies, Gorthaur. Nay, stay down",
        Player->caughtMessages()[1]);*/
}
