//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Wizard;
object Player;
object Room;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database->PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess->savePlayerData(database->GetWizardOfLevel("creator"));

    destruct(dataAccess);
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Room = clone_object("/lib/environment/environment.c");

    Wizard = clone_object("/lib/realizations/wizard.c");
    Wizard->restore("earl");
    Wizard->addCommands();

    Player = clone_object("/lib/realizations/player.c");
    Player->restore("gorthaur");
    move_object(Wizard, load_object("/lib/tests/support/environment/toLocation.c"));

    setUsers(({ Wizard, Player }));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Wizard);
    destruct(Room);
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpIsNotGreedy()
{
    ExpectFalse(Wizard->executeCommand("transportt"), "transportt");
    ExpectFalse(Wizard->executeCommand("ttransport"), "ttransport");
    ExpectFalse(Wizard->executeCommand("ttran"), "ttrans");
    ExpectFalse(Wizard->executeCommand("transp"), "ttransp");
}

/////////////////////////////////////////////////////////////////////////////
void CanTransPlayer()
{
    ExpectEq(0, environment(Player));
    ExpectTrue(Wizard->executeCommand("trans gorthaur"));
    ExpectEq(load_object("/lib/tests/support/environment/toLocation.c"),
        environment(Player));
}

/////////////////////////////////////////////////////////////////////////////
void CanTransportPlayer()
{
    ExpectEq(0, environment(Player));
    ExpectTrue(Wizard->executeCommand("transport gorthaur"));
    ExpectEq(load_object("/lib/tests/support/environment/toLocation.c"),
        environment(Player));
}

/////////////////////////////////////////////////////////////////////////////
void CannotTransportNonexistantPerson()
{
    ExpectFalse(Wizard->executeCommand("transport george"));
}
