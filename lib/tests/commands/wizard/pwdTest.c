//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Wizard;

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
    Wizard = clone_object("/lib/realizations/wizard.c");
    Wizard.restore("earl");
    Wizard.addCommands();
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
    ExpectFalse(Wizard.executeCommand("ppwd"), "ppwd");
    ExpectFalse(Wizard.executeCommand("pwdd"), "pwdd");
}

/////////////////////////////////////////////////////////////////////////////
void PwdShowsCurrentWorkingDirctory()
{
    ExpectTrue(Wizard.executeCommand("pwd"));
    ExpectEq("/players/earl", Wizard.pwd());
}

/////////////////////////////////////////////////////////////////////////////
void PwdReflectsChangesToDirectory()
{
    ExpectTrue(Wizard.executeCommand("cd /lib/tests/support"));
    ExpectTrue(Wizard.executeCommand("pwd"));
    ExpectEq("/lib/tests/support", Wizard.pwd());
}