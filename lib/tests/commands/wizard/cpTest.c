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
    ExpectFalse(Wizard.executeCommand("ccp x y"), "ccp");
    ExpectFalse(Wizard.executeCommand("cpp x y"), "cpp");
}

/////////////////////////////////////////////////////////////////////////////
void CpMovesFileToCorrectLocation()
{
    ExpectEq(0, file_size("/players/earl/blah"));
    ExpectEq(-1, file_size("/players/earl/y"));
    ExpectTrue(Wizard.executeCommand("cp /players/earl/blah /players/earl/y"));
    ExpectEq(0, file_size("/players/earl/blah"));
    ExpectEq(0, file_size("/players/earl/y"));
    rm("/players/earl/y");
}

/////////////////////////////////////////////////////////////////////////////
void CpFailsWhenFileDoesNotExist()
{
    ExpectEq(-1, file_size("/players/earl/x"));
    ExpectEq(-1, file_size("/players/earl/y"));
    ExpectFalse(Wizard.executeCommand("cp /players/earl/x /players/earl/y"));
    ExpectSubStringMatch("The file '/players/earl/x' does not exist.", 
        Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CpFailsWhenUserDoesNotHaveReadAccessToSource()
{
    ExpectFalse(Wizard.executeCommand("cp /secure/master.c /players/earl/y"));
    ExpectSubStringMatch("You do not have read access to '/secure/master.c'",
        Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CpFailsWhenUserDoesNotHaveWriteAccessToDestination()
{
    ExpectFalse(Wizard.executeCommand("cp /players/earl/blah /secure/y"));
    ExpectSubStringMatch("You do not have write access to '/secure/y'",
        Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CpProperlyHandlesRelativePaths()
{
    command("cd /players/earl", Wizard);

    ExpectEq(0, file_size("/players/earl/blah"));
    ExpectEq(-1, file_size("/players/earl/y"));
    ExpectTrue(Wizard.executeCommand("cp blah y"));
    ExpectEq(0, file_size("/players/earl/blah"));
    ExpectEq(0, file_size("/players/earl/y"));
    rm("/players/earl/y");
}
