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
    ExpectFalse(Wizard->executeCommand("ccat x y"), "ccat");
    ExpectFalse(Wizard->executeCommand("catt x y"), "catt");
}

/////////////////////////////////////////////////////////////////////////////
void CatDisplaysFile()
{
    ExpectTrue(Wizard->executeCommand("cat /brokenFile.c"));

    // Broken file is 108 lines long
    ExpectEq(108, sizeof(explode(Wizard->caughtMessage(), "\n")));
}

/////////////////////////////////////////////////////////////////////////////
void CatFailsWhenFileDoesNotExist()
{
    ExpectEq(-1, file_size("/players/earl/x"));
    ExpectFalse(Wizard->executeCommand("cat /players/earl/x"));
    ExpectSubStringMatch("The file '/players/earl/x' does not exist.", 
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CatFailsWhenUserDoesNotHaveReadAccessToSource()
{
    ExpectFalse(Wizard->executeCommand("cat /secure/master.c"));
    ExpectSubStringMatch("You do not have read access to '/secure/master.c'",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CatProperlyHandlesRelativePaths()
{
    copy_file("/brokenFile.c", "/players/earl/x");
    command("cd /players/earl", Wizard);

    ExpectTrue(Wizard->executeCommand("cat x"));
    ExpectEq(108, sizeof(explode(Wizard->caughtMessage(), "\n")));
    rm("/players/earl/x");
}

/////////////////////////////////////////////////////////////////////////////
void CatCanSpecifyNumberOfLinesToView()
{
    ExpectTrue(Wizard->executeCommand("cat -n20 /brokenFile.c"));

    // Will also include a blank line
    ExpectEq(21, sizeof(explode(Wizard->caughtMessage(), "\n")));
}

/////////////////////////////////////////////////////////////////////////////
void CatCanHaveSpaceBeforeNumberOfLines()
{
    ExpectTrue(Wizard->executeCommand("cat -n 25 /brokenFile.c"));

    // Will also include a blank line
    ExpectEq(26, sizeof(explode(Wizard->caughtMessage(), "\n")));
}

/////////////////////////////////////////////////////////////////////////////
void CatWillNotExceedTotalLines()
{
    ExpectTrue(Wizard->executeCommand("cat -n 200 /brokenFile.c"));

    ExpectEq(108, sizeof(explode(Wizard->caughtMessage(), "\n")));
}
