//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    dataAccess.savePlayerData(database.GetWizardOfLevel("admin"));

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
    ExpectFalse(Wizard.executeCommand("ccd"), "ccd");
    ExpectFalse(Wizard.executeCommand("cdd"), "cdd");
}

/////////////////////////////////////////////////////////////////////////////
void CdChangesCurrentDirectory()
{
    ExpectTrue(Wizard.executeCommand("cd /lib/tests/support"));
    ExpectEq("/lib/tests/support", Wizard.pwd());
}

/////////////////////////////////////////////////////////////////////////////
void CannotCdToDirectoryiesWhenUserHasNoReadAccess()
{
    ExpectFalse(Wizard.executeCommand("cd /secure"));
}

/////////////////////////////////////////////////////////////////////////////
void CannotCdToDirectoryThatDoesNotExist()
{
    ExpectFalse(Wizard.executeCommand("cd /blarg"));
}

/////////////////////////////////////////////////////////////////////////////
void CdWithoutArgumentsSetsPwdToHomeDirectory()
{
    ExpectTrue(Wizard.executeCommand("cd"));
    ExpectEq("/players/earl", Wizard.pwd());
}

/////////////////////////////////////////////////////////////////////////////
void CanCdIntoRelativeDirectory()
{
    ExpectTrue(Wizard.executeCommand("cd /lib"));
    ExpectTrue(Wizard.executeCommand("cd tests"));
    ExpectEq("/lib/tests", Wizard.pwd());
}

/////////////////////////////////////////////////////////////////////////////
void TildeIsPlayerHomeDirectory()
{
    ExpectTrue(Wizard.executeCommand("cd /lib"));
    ExpectTrue(Wizard.executeCommand("cd ~"));
    ExpectEq("/players/earl", Wizard.pwd());
}

/////////////////////////////////////////////////////////////////////////////
void TildeWithOtherUserGoesToTheirHomeDirectory()
{
    ExpectTrue(Wizard.executeCommand("cd ~maeglin"));
    ExpectEq("/players/maeglin", Wizard.pwd());
}