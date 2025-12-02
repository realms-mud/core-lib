//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Wizard;
object ElderWizard;
object Catch;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database.PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess.savePlayerData(database.GetWizardOfLevel("creator"));

    Wizard = clone_object("/lib/realizations/wizard.c");
    Wizard.restore("earl");
    Wizard.Name("fred");
    Wizard.addCommands();
    clone_object("/lib/tests/support/services/catchShadow.c").beginShadow(Wizard);

    dataAccess.savePlayerData(database.GetWizardOfLevel("elder"));

    destruct(dataAccess);
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Catch = clone_object("/lib/tests/support/services/catchShadow.c");

    ElderWizard = clone_object("/lib/realizations/wizard.c");
    ElderWizard.restore("earl");
    ElderWizard.addCommands();
    Catch.beginShadow(ElderWizard);
    setUsers(({ Wizard, ElderWizard }));

    ElderWizard.resetCatchList();
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(ElderWizard);
}

/////////////////////////////////////////////////////////////////////////////
void CannotExecuteAsLowLevelWizard()
{
    ExpectFalse(Wizard.executeCommand("reboot"));
}

/////////////////////////////////////////////////////////////////////////////
void CannotDirectlyCallShutdownGame()
{
    command("patch -t /lib/commands/wizard/reboot.c -f shutdownGame", Wizard);

    ExpectSubStringMatch("You cannot call this method directly", 
        Wizard.caughtMessages());
}

/////////////////////////////////////////////////////////////////////////////
void CanExecuteRebootCommand()
{
    ToggleCallOutBypass();
    ExpectTrue(ElderWizard.executeCommand("reboot"));

    ExpectSubStringMatch("Reboot initiated.*The MUD will reboot in 1 minute 0 seconds.*"
        "The MUD will reboot in 10 seconds", ElderWizard.caughtMessages());
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void CanExecuteRebootCommandWithTime()
{
    ToggleCallOutBypass();
    ExpectTrue(ElderWizard.executeCommand("reboot -t30"));

    ExpectSubStringMatch("The MUD will reboot in 30 seconds", 
        ElderWizard.caughtMessages());
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void CanExecuteRebootCommandWithZeroTime()
{
    ToggleCallOutBypass();
    ExpectTrue(ElderWizard.executeCommand("reboot -t 0"));

    ExpectSubStringMatch("The MUD will reboot in 0 seconds",
        ElderWizard.caughtMessages());
    ToggleCallOutBypass();
}
