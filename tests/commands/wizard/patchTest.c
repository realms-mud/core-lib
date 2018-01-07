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
    ExpectFalse(Wizard->executeCommand("ppatch"), "ppatch");
    ExpectFalse(Wizard->executeCommand("patched"), "patched");
}

/////////////////////////////////////////////////////////////////////////////
void PatchWorksForItemInInventory()
{
    object target = clone_object("/lib/items/weapon.c");
    target->set("name", "sword");
    move_object(target, Wizard);
    ExpectEq("sword", target->query("name"));
    ExpectEq(1, Wizard->executeCommand("patch -t sword -f set -v name, bob"));
    ExpectEq("bob", target->query("name"));
    destruct(target);
}

/////////////////////////////////////////////////////////////////////////////
void PatchWorksForItemInIEnvironment()
{
    object target = clone_object("/lib/items/weapon.c");
    target->set("name", "sword");
    move_object(target, Room);
    ExpectEq("sword", target->query("name"));
    ExpectEq(1, Wizard->executeCommand("patch -t sword -f set -v name,bob"));
    ExpectEq("bob", target->query("name"));
    destruct(target);
}

/////////////////////////////////////////////////////////////////////////////
void PatchWorksForItemThatHasNotBeenCloned()
{
    object target = load_object("/lib/items/weapon.c");
    ExpectEq(1, Wizard->executeCommand("patch -t /lib/items/weapon.c -f set -v name,bob"));
    ExpectEq("bob", target->query("name"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteReturnsFalseWhenObjectCannotBeFound()
{
    ExpectEq(0, Wizard->executeCommand("patch -t llama -f set -v name,bob"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteReturnsFalseWhenObjectDoesNotExist()
{
    ExpectEq(0, Wizard->executeCommand("patch -t /lib/badFile.c -f set -v name,bob"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteReturnsFalseWhenFunctionNotSupplied()
{
    ExpectEq(0, Wizard->executeCommand("patch -t /lib/items/weapon.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteReturnsFalseWhenFunctionDoesNotExist()
{
    ExpectEq(0, Wizard->executeCommand("patch -t /lib/items/weapon.c -f blarg"));
}
/////////////////////////////////////////////////////////////////////////////
void ExecuteReturnsTrueWhenFunctionExistsAndNoParamsPassed()
{
    ExpectEq(1, Wizard->executeCommand("patch -t /lib/items/weapon.c -f get"));
}

/////////////////////////////////////////////////////////////////////////////
void PatchWorksForRelativePathItemThatHasNotBeenCloned()
{
    object target = load_object("/lib/items/weapon.c");
    Wizard->pwd("/lib/items");
    ExpectEq(1, Wizard->executeCommand("patch -t weapon.c -f set -v name,bob"));
    ExpectEq("bob", target->query("name"));
}
