//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Wizard;
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
    Room = clone_object("/lib/environment/room.c");

    Wizard = clone_object("/lib/realizations/wizard.c");
    Wizard->restore("earl");
    Wizard->addCommands();
    setUsers(({ Wizard }));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Wizard);
    destruct(Room);
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpIsNotGreedy()
{
    ExpectFalse(Wizard->executeCommand("ggoto"), "ggoto");
    ExpectFalse(Wizard->executeCommand("gotor"), "gotor");
}

/////////////////////////////////////////////////////////////////////////////
void CanGoToFileBasedLocation()
{
    ExpectEq(0, environment(Wizard));
    ExpectTrue(Wizard->executeCommand("goto /lib/tests/support/environment/toLocation.c"));
    ExpectEq(load_object("/lib/tests/support/environment/toLocation.c"),
        environment(Wizard));
}

/////////////////////////////////////////////////////////////////////////////
void CanGoToFileBasedLocationInCurrentDirectory()
{
    Wizard->pwd("/lib/tests/support/environment");
    ExpectEq(0, environment(Wizard));
    ExpectTrue(Wizard->executeCommand("goto toLocation.c"));
    ExpectEq(load_object("/lib/tests/support/environment/toLocation.c"),
        environment(Wizard));
}

/////////////////////////////////////////////////////////////////////////////
void CanGoToPlayer()
{
    object player = clone_object("/lib/realizations/player.c");
    player->restore("gorthaur");
    move_object(player, load_object("/lib/tests/support/environment/toLocation.c"));

    ExpectEq(0, environment(Wizard));
    ExpectTrue(Wizard->executeCommand("goto gorthaur"));
    ExpectEq(load_object("/lib/tests/support/environment/toLocation.c"),
        environment(Wizard));
}

/////////////////////////////////////////////////////////////////////////////
void CannotGoToNonexistantPerson()
{
    ExpectFalse(Wizard->executeCommand("goto george"));
}

/////////////////////////////////////////////////////////////////////////////
void CannotGoToNonexistantLocation()
{
    ExpectFalse(Wizard->executeCommand("goto /bad/location.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CannotGoToLocationWithNoReadAccess()
{
    ExpectFalse(Wizard->executeCommand("goto /secure/toEnvironment.c"));
}