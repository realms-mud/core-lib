//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    ExpectFalse(Wizard.executeCommand("cclone"), "cclone");
    ExpectFalse(Wizard.executeCommand("cloned"), "cloned");
}

/////////////////////////////////////////////////////////////////////////////
void CloneOfExistingItemPlacesItInInventory()
{
    ExpectEq(0, sizeof(all_inventory(Wizard)));
    ExpectEq(1, Wizard.executeCommand("clone /lib/items/weapon.c"));
    ExpectEq(1, sizeof(all_inventory(Wizard)));
    ExpectEq("/lib/items/weapon.c", program_name(all_inventory(Wizard)[0]));
    destruct(all_inventory(Wizard)[0]);
}

/////////////////////////////////////////////////////////////////////////////
void CloneOfNonGettableItemPlacesItInEnvironment()
{
    ExpectEq(1, sizeof(all_inventory(environment(Wizard))));
    ExpectEq(1, Wizard.executeCommand("clone /lib/realizations/npc.c"));
    ExpectEq(2, sizeof(all_inventory(environment(Wizard))));
    ExpectEq("/lib/realizations/npc.c", 
        program_name(all_inventory(environment(Wizard))[0]));
    destruct(all_inventory(environment(Wizard))[0]);
}

/////////////////////////////////////////////////////////////////////////////
void CloneOfNonexistantFileReturnsFalse()
{
    ExpectEq(0, Wizard.executeCommand("clone /lib/include/inventory"));
}

/////////////////////////////////////////////////////////////////////////////
void CloneOfDirectoryReturnsFalse()
{
    ExpectEq(0, Wizard.executeCommand("clone /lib/modules"));
}

/////////////////////////////////////////////////////////////////////////////
void CloneOfFileWithSyntaxErrorsDoesNotClone()
{
    ExpectEq(0, Wizard.executeCommand("clone /lib/brokenFile.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CloneHandlesRelativePaths()
{
    Wizard.pwd("/lib/items");
    ExpectEq(1, Wizard.executeCommand("clone weapon.c"));
    ExpectEq("/lib/items/weapon.c", program_name(all_inventory(Wizard)[0]));
    destruct(all_inventory(Wizard)[0]);
}

/////////////////////////////////////////////////////////////////////////////
void CloneCanCloneValidObjectsWhenDotCMissing()
{
    Wizard.pwd("/lib/items");
    ExpectEq(1, Wizard.executeCommand("clone weapon"));
    ExpectEq("/lib/items/weapon.c", program_name(all_inventory(Wizard)[0]));
    destruct(all_inventory(Wizard)[0]);
}

/////////////////////////////////////////////////////////////////////////////
void CloneCanNotCloneInValidObjectsWhenDotCMissing()
{
    Wizard.pwd("/lib/items");
    ExpectEq(0, Wizard.executeCommand("clone badFile"));
}
