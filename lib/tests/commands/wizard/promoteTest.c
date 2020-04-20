//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Wizard;
object Wizard2;
object Player;
object Catch;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database->PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess->savePlayerData(database->GetWizardOfLevel("creator"));
    dataAccess->savePlayerData(database->Gorthaur());

    dataAccess->savePlayerData(database->GetWizardOfLevel("creator", "fred"));
    dataAccess->savePlayerData(database->GetWizardOfLevel("elder"));

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

    Wizard2 = clone_object("/lib/realizations/wizard.c");
    Wizard2->restore("fred");
    Wizard2->addCommands();
    clone_object("/lib/tests/support/services/catchShadow.c")->beginShadow(Wizard2);

    Player = clone_object("/lib/realizations/player.c");
    Player->restore("gorthaur");
    Player->addCommands();

    setUsers(({ Wizard, Wizard2, Player }));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Wizard);
    destruct(Wizard2);
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void PromoteFailsIfWizardNotAppropriateLevel()
{
    command("promote gorthaur", Wizard2);
    ExpectEq("What?\n", Wizard2->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PromoteOfPlayerWithNoLevelReturnsApprenticeWizard()
{
    command("promote gorthaur", Wizard);

    object newWizard = findPlayer("gorthaur");
    ExpectEq("apprentice", newWizard->wizardLevel());
}

/////////////////////////////////////////////////////////////////////////////
void PromoteOfPlayerToSpecificLevelCorrectlySetsLevel()
{
    command("promote gorthaur to senior", Wizard);

    object newWizard = findPlayer("gorthaur");
    ExpectEq("senior", newWizard->wizardLevel());
}

/////////////////////////////////////////////////////////////////////////////
void CanPromoteWizardToANewLevel()
{
    command("promote fred to admin", Wizard);

    object newWizard = findPlayer("fred");
    ExpectEq("admin", newWizard->wizardLevel());
}
