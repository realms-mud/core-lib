//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    ExpectFalse(Wizard.executeCommand("rmv x y"), "rmv");
    ExpectFalse(Wizard.executeCommand("rrm x y"), "rrm");
}

/////////////////////////////////////////////////////////////////////////////
void RmRemovesFile()
{
    copy_file("/players/earl/blah", "/players/earl/x");
    ExpectEq(0, file_size("/players/earl/x"));
    ExpectTrue(Wizard.executeCommand("rm /players/earl/x"));
    ExpectEq(-1, file_size("/players/earl/x"));
}

/////////////////////////////////////////////////////////////////////////////
void RmFailsWhenFileDoesNotExist()
{
    ExpectEq(-1, file_size("/players/earl/x"));
    ExpectFalse(Wizard.executeCommand("rm /players/earl/x"));
    ExpectSubStringMatch("The file '/players/earl/x' does not exist.", 
        Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void RmFailsWhenUserDoesNotHaveWriteAccessToSource()
{
    ExpectFalse(Wizard.executeCommand("rm /secure/master.c"));
    ExpectSubStringMatch("You do not have write access to '/secure/master.c'",
        Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void RmProperlyHandlesRelativePaths()
{
    copy_file("/players/earl/blah", "/players/earl/x");
    command("cd /players/earl", Wizard);

    ExpectEq(0, file_size("/players/earl/x"));
    ExpectTrue(Wizard.executeCommand("rm x"));
    ExpectEq(-1, file_size("/players/earl/x"));
}

/////////////////////////////////////////////////////////////////////////////
void RmCanRecursivelyDelete()
{
    mkdir("/players/earl/blarg");
    mkdir("/players/earl/blarg/b");
    mkdir("/players/earl/blarg/b/b");
    mkdir("/players/earl/blarg/b/a");
    copy_file("/players/earl/blah", "/players/earl/blarg/x");
    copy_file("/players/earl/blah", "/players/earl/blarg/b/x");
    copy_file("/players/earl/blah", "/players/earl/blarg/b/b/x");
    copy_file("/players/earl/blah", "/players/earl/blarg/b/a/x");
    command("cd /players/earl", Wizard);

    ExpectEq(-2, file_size("/players/earl/blarg"));
    ExpectEq(-2, file_size("/players/earl/blarg/b"));
    ExpectEq(-2, file_size("/players/earl/blarg/b/b"));
    ExpectEq(-2, file_size("/players/earl/blarg/b/a"));
    ExpectEq(0, file_size("/players/earl/blarg/x"));
    ExpectEq(0, file_size("/players/earl/blarg/b/x"));
    ExpectEq(0, file_size("/players/earl/blarg/b/b/x"));
    ExpectEq(0, file_size("/players/earl/blarg/b/a/x"));
    ExpectTrue(Wizard.executeCommand("rm -r blarg"));
    ExpectEq(-1, file_size("/players/earl/blarg"));
    ExpectEq(-1, file_size("/players/earl/blarg/b"));
    ExpectEq(-1, file_size("/players/earl/blarg/b/b"));
    ExpectEq(-1, file_size("/players/earl/blarg/b/a"));
    ExpectEq(-1, file_size("/players/earl/blarg/x"));
    ExpectEq(-1, file_size("/players/earl/blarg/b/x"));
    ExpectEq(-1, file_size("/players/earl/blarg/b/b/x"));
    ExpectEq(-1, file_size("/players/earl/blarg/b/a/x"));
}
