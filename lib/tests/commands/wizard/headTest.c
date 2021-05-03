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
    ExpectFalse(Wizard.executeCommand("hhead x y"), "hhead");
    ExpectFalse(Wizard.executeCommand("headd x y"), "headd");
}

/////////////////////////////////////////////////////////////////////////////
void HeadDisplaysFirstFiveLinesOfFileByDefault()
{
    ExpectTrue(Wizard.executeCommand("head /brokenFile.c"));

    // This should only display the first five lines plus a blank line
    ExpectEq(6, sizeof(explode(Wizard.caughtMessage(), "\n")));
}

/////////////////////////////////////////////////////////////////////////////
void HeadFailsWhenFileDoesNotExist()
{
    ExpectEq(-1, file_size("/players/earl/x"));
    ExpectFalse(Wizard.executeCommand("head /players/earl/x"));
    ExpectSubStringMatch("The file '/players/earl/x' does not exist.", 
        Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HeadFailsWhenUserDoesNotHaveReadAccessToSource()
{
    ExpectFalse(Wizard.executeCommand("head /secure/master.c"));
    ExpectSubStringMatch("You do not have read access to '/secure/master.c'",
        Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HeadProperlyHandlesRelativePaths()
{
    copy_file("/brokenFile.c", "/players/earl/x");
    command("cd /players/earl", Wizard);

    ExpectTrue(Wizard.executeCommand("head x"));
    ExpectEq(6, sizeof(explode(Wizard.caughtMessage(), "\n")));
    rm("/players/earl/x");
}

/////////////////////////////////////////////////////////////////////////////
void HeadCanSpecifyNumberOfLinesToView()
{
    ExpectTrue(Wizard.executeCommand("head -n20 /brokenFile.c"));

    // Will also include a blank line
    ExpectEq(21, sizeof(explode(Wizard.caughtMessage(), "\n")));
}

/////////////////////////////////////////////////////////////////////////////
void HeadCanHaveSpaceBeforeNumberOfLines()
{
    ExpectTrue(Wizard.executeCommand("head -n 25 /brokenFile.c"));

    // Will also include a blank line
    ExpectEq(26, sizeof(explode(Wizard.caughtMessage(), "\n")));
}

/////////////////////////////////////////////////////////////////////////////
void HeadWillNotExceedTotalLines()
{
    ExpectTrue(Wizard.executeCommand("head -n 200 /brokenFile.c"));

    ExpectEq(108, sizeof(explode(Wizard.caughtMessage(), "\n")));
}
