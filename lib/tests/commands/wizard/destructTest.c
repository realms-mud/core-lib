//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    database.PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess.savePlayerData(database.GetWizardOfLevel("creator"));

    destruct(dataAccess);
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Room = clone_object("/lib/environment/environment.c");

    Wizard = clone_object("/lib/realizations/wizard.c");
    Wizard.restore("earl");
    Wizard.addCommands();

    move_object(Wizard, Room);
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
    ExpectFalse(Wizard.executeCommand("cdest"), "cdest");
    ExpectFalse(Wizard.executeCommand("destr"), "destr");
}

/////////////////////////////////////////////////////////////////////////////
void DestructOfExistingItemRemovesItFromInventory()
{
    object item = 
        clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    move_object(item, Wizard);

    ExpectEq(1, sizeof(all_inventory(Wizard)));
    ExpectEq("/lib/instances/items/weapons/swords/long-sword.c", 
        program_name(all_inventory(Wizard)[0]));
    ExpectEq(1, Wizard.executeCommand("destruct sword"));
    ExpectEq(0, sizeof(all_inventory(Wizard)));
}

/////////////////////////////////////////////////////////////////////////////
void DestructOfExistingItemRemovesItFromEnvironment()
{
    object item =
        clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    move_object(item, Room);

    ExpectEq(2, sizeof(all_inventory(Room)));
    ExpectEq(1, Wizard.executeCommand("unmake sword"));
    ExpectEq(1, sizeof(all_inventory(Room)));
}

/////////////////////////////////////////////////////////////////////////////
void DestructOfEnvironmentMovesCharacterBack()
{
    object item =
        clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    move_object(item, "/lib/environment/environment.c");
    move_object(Wizard, "/lib/environment/environment.c");

    ExpectEq(({ Wizard, item }), all_inventory(load_object("/lib/environment/environment.c")));
    ExpectEq(1, Wizard.executeCommand("dest /lib/environment/environment.c"));
    
    ExpectEq("/lib/environment/environment.c", environment(Wizard));
    ExpectEq(({ Wizard }), all_inventory(load_object("/lib/environment/environment.c")));
}
