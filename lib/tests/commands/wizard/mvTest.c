//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Wizard;
object Catch;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database.PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess.savePlayerData(database.GetWizardOfLevel("admin"));

    destruct(dataAccess);
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Catch = clone_object("/lib/tests/support/services/catchShadow.c");

    Wizard = clone_object("/lib/realizations/wizard.c");
    Wizard.restore("earl");
    Wizard.addCommands();
    Catch.beginShadow(Wizard);

    setUsers(({ Wizard }));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Wizard);
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpIsNotGreedy()
{
    ExpectFalse(Wizard.executeCommand("mmv x y"), "mmv");
    ExpectFalse(Wizard.executeCommand("mvv x y"), "mvv");
}

/////////////////////////////////////////////////////////////////////////////
void MvMovesFileToCorrectLocation()
{
    copy_file("/players/earl/blah", "/players/earl/x");
    ExpectEq(0, file_size("/players/earl/x"));
    ExpectEq(-1, file_size("/players/earl/y"));
    ExpectTrue(Wizard.executeCommand("mv /players/earl/x /players/earl/y"));
    ExpectEq(-1, file_size("/players/earl/x"));
    ExpectEq(0, file_size("/players/earl/y"));
    rm("/players/earl/y");
}

/////////////////////////////////////////////////////////////////////////////
void MvFailsWhenFileDoesNotExist()
{
    ExpectEq(-1, file_size("/players/earl/x"));
    ExpectEq(-1, file_size("/players/earl/y"));
    ExpectFalse(Wizard.executeCommand("mv /players/earl/x /players/earl/y"));
    ExpectSubStringMatch("The file '/players/earl/x' does not exist.", 
        Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MvFailsWhenUserDoesNotHaveWriteAccessToSource()
{
    ExpectFalse(Wizard.executeCommand("mv /secure/master.c /players/earl/y"));
    ExpectSubStringMatch("You do not have write access to both '/secure/master.c' and '/players/earl/y'",
        Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MvFailsWhenUserDoesNotHaveWriteAccessToDestination()
{
    copy_file("/players/earl/blah", "/players/earl/x");
    ExpectFalse(Wizard.executeCommand("mv /players/earl/x /secure/y"));
    ExpectSubStringMatch("You do not have write access to both '/players/earl/x' and '/secure/y'",
        Wizard.caughtMessage());
    rm("/players/earl/x");
}

/////////////////////////////////////////////////////////////////////////////
void MvProperlyHandlesRelativePaths()
{
    copy_file("/players/earl/blah", "/players/earl/x");
    command("cd /players/earl", Wizard);

    ExpectEq(0, file_size("/players/earl/x"));
    ExpectEq(-1, file_size("/players/earl/y"));
    ExpectTrue(Wizard.executeCommand("mv x y"));
    ExpectEq(-1, file_size("/players/earl/x"));
    ExpectEq(0, file_size("/players/earl/y"));
    rm("/players/earl/y");
}
