//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Wizard;
object Catch;
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

    Catch = clone_object("/lib/tests/support/services/catchShadow.c");
    Wizard = clone_object("/lib/realizations/wizard.c");
    Wizard->restore("earl");
    Wizard->addCommands();
    Catch->beginShadow(Wizard);

    setUsers(({ Wizard }));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Catch);
    destruct(Wizard);
    destruct(Room);
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpIsNotGreedy()
{
    ExpectFalse(Wizard->executeCommand("gshow"), "gshow");
    ExpectFalse(Wizard->executeCommand("showr"), "showr");
}

/////////////////////////////////////////////////////////////////////////////
void CanShowFileBasedLocation()
{
    ExpectTrue(Wizard->executeCommand("show /lib/tests/support/environment/toLocation.c"));
    ExpectSubStringMatch("lib/tests/support/environment/toLocation", Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanShowFileBasedLocationInCurrentDirectory()
{
    Wizard->pwd("/lib/tests/support/environment");
    ExpectTrue(Wizard->executeCommand("show toLocation.c"));
    ExpectSubStringMatch("lib/tests/support/environment/toLocation", Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanShowFileBasedLocationWithoutDotCInCurrentDirectory()
{
    Wizard->pwd("/lib/tests/support/environment");
    ExpectTrue(Wizard->executeCommand("show toLocation"));
    ExpectSubStringMatch("lib/tests/support/environment/toLocation", Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanShowEnvironmentWithItems()
{
    object player = clone_object("/lib/realizations/player.c");
    player->restore("gorthaur");
    move_object(player, load_object("/lib/tests/support/environment/toLocation.c"));
    setUsers(({ Wizard, player }));

    ExpectTrue(Wizard->executeCommand("show /lib/tests/support/environment/toLocation.c"));
    ExpectSubStringMatch("lib/tests/support/environment/toLocation.*lib/realizations/player#.*gorthaur",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanShowPlayer()
{
    object player = clone_object("/lib/realizations/player.c");
    player->restore("gorthaur");
    move_object(player, load_object("/lib/tests/support/environment/toLocation.c"));
    setUsers(({ Wizard, player }));

    ExpectTrue(Wizard->executeCommand("show gorthaur"));
    ExpectSubStringMatch("lib/realizations/player#.*gorthaur.*lib/tests/support/environment/toLocation", 
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanShowPresentObject()
{
    object item = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    move_object(Wizard, load_object("/lib/tests/support/environment/toLocation.c"));
    move_object(item, load_object("/lib/tests/support/environment/toLocation.c"));

    ExpectTrue(Wizard->executeCommand("show sword"));
    ExpectSubStringMatch("lib/instances/items/weapons/swords/long-sword#.*Long sword.*lib/tests/support/environment/toLocation",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanShowPresentObjectWithNestedItems()
{
    object player = clone_object("/lib/realizations/player.c");
    player->restore("gorthaur");
    move_object(player, load_object("/lib/tests/support/environment/toLocation.c"));
    setUsers(({ Wizard, player }));

    object subItem = clone_object("/lib/instances/items/armor/clothing/robes.c");
    move_object(subItem, player);
    subItem = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    move_object(subItem, player);
    subItem = clone_object("/lib/instances/items/armor/accessories/ring.c");
    move_object(subItem, player);

    ExpectTrue(Wizard->executeCommand("show gorthaur"));
    ExpectSubStringMatch("lib/realizations/player#.*gorthaur.*lib/tests/support/environment/toLocation.*ring.*lib/instances/items/weapons/swords/long-sword#.*Long sword.*robes",
        Wizard->caughtMessage());
}
/////////////////////////////////////////////////////////////////////////////
void CannotShowNonexistantPerson()
{
    ExpectFalse(Wizard->executeCommand("show george"));
}

/////////////////////////////////////////////////////////////////////////////
void CannotShowNonexistantLocation()
{
    ExpectFalse(Wizard->executeCommand("show /bad/location.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CannotShowLocationWithNoReadAccess()
{
    ExpectFalse(Wizard->executeCommand("show /secure/toEnvironment.c"));
}
