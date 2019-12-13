//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    database->PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess->savePlayerData(database->GetWizardOfLevel("admin"));

    destruct(dataAccess);
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
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
    destruct(Wizard);
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpIsNotGreedy()
{
    ExpectFalse(Wizard->executeCommand("htail x y"), "htail");
    ExpectFalse(Wizard->executeCommand("taild x y"), "taild");
}

/////////////////////////////////////////////////////////////////////////////
void TailDisplaysFirstFiveLinesOfFileByDefault()
{
    ExpectTrue(Wizard->executeCommand("tail /brokenFile.c"));

    // This should only display the first five lines plus a blank line
    ExpectEq("{\n  destruct(this_object());\n}\n\nint query_value() { return "
        "money; }\n\nstring query_name() { return \"money\"; }\n", Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TailFailsWhenFileDoesNotExist()
{
    ExpectEq(-1, file_size("/players/earl/x"));
    ExpectFalse(Wizard->executeCommand("tail /players/earl/x"));
    ExpectSubStringMatch("The file '/players/earl/x' does not exist.", 
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TailFailsWhenUserDoesNotHaveReadAccessToSource()
{
    ExpectFalse(Wizard->executeCommand("tail /secure/master.c"));
    ExpectSubStringMatch("You do not have read access to '/secure/master.c'",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TailProperlyHandlesRelativePaths()
{
    copy_file("/brokenFile.c", "/players/earl/x");
    command("cd /players/earl", Wizard);

    ExpectTrue(Wizard->executeCommand("tail x"));
    ExpectEq(8, sizeof(explode(Wizard->caughtMessage(), "\n")));
    rm("/players/earl/x");
}

/////////////////////////////////////////////////////////////////////////////
void TailCanSpecifyNumberOfLinesToView()
{
    ExpectTrue(Wizard->executeCommand("tail -n20 /brokenFile.c"));
    ExpectEq(20, sizeof(explode(Wizard->caughtMessage(), "\n")));
}

/////////////////////////////////////////////////////////////////////////////
void TailCanHaveSpaceBeforeNumberOfLines()
{
    ExpectTrue(Wizard->executeCommand("tail -n 25 /brokenFile.c"));
    ExpectEq(25, sizeof(explode(Wizard->caughtMessage(), "\n")));
}

/////////////////////////////////////////////////////////////////////////////
void TailWillNotExceedTotalLines()
{
    ExpectTrue(Wizard->executeCommand("tail -n 200 /brokenFile.c"));
    ExpectEq(108, sizeof(explode(Wizard->caughtMessage(), "\n")));
}
