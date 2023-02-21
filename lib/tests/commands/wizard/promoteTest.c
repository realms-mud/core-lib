//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Wizard;
object Wizard2;
object Player;
object Catch;
mapping Gorthaur;
object DataAccess;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    object Database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    Database.PrepDatabase();

    DataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    DataAccess.savePlayerData(Database.GetWizardOfLevel("creator"));
    Gorthaur = Database.Gorthaur();
    Gorthaur["wizard level"] = "player";

    DataAccess.savePlayerData(Database.GetWizardOfLevel("creator", "fred"));
    DataAccess.savePlayerData(Database.GetWizardOfLevel("elder"));

    destruct(Database);
}

/////////////////////////////////////////////////////////////////////////////
void TearDown()
{
    destruct(DataAccess);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Catch = clone_object("/lib/tests/support/services/catchShadow.c");

    Wizard = clone_object("/lib/realizations/wizard.c");
    Wizard.restore("earl");
    Wizard.addCommands();
    Catch.beginShadow(Wizard);

    Wizard2 = clone_object("/lib/realizations/wizard.c");
    Wizard2.restore("fred");
    Wizard2.addCommands();
    clone_object("/lib/tests/support/services/catchShadow.c").beginShadow(Wizard2);

    Player = clone_object("/lib/realizations/player.c");
    DataAccess.savePlayerData(Gorthaur);
    Player.restore("gorthaur");
    Player.addCommands();

    setUsers(({ Wizard, Wizard2, Player }));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    set_this_player(Wizard);
    demoteWizardToPlayer("gorthaur");
    destruct(Wizard);
    destruct(Wizard2);
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void PromoteFailsIfWizardNotAppropriateLevel()
{
    command("promote gorthaur", Wizard2);
    ExpectEq("What?\n", Wizard2.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PromoteOfPlayerWithNoLevelReturnsApprenticeWizard()
{
    command("promote gorthaur", Wizard);

    object newWizard = findPlayer("gorthaur");
    ExpectEq("apprentice", newWizard.wizardLevel());

    ExpectEq("You promote Gorthaur to apprentice.\n", 
        Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PromoteOfPlayerToSpecificLevelCorrectlySetsLevel()
{
    command("promote gorthaur to senior", Wizard);

    object newWizard = findPlayer("gorthaur");
    ExpectEq("senior", newWizard.wizardLevel());

    ExpectEq("You promote Gorthaur to senior.\n", Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PromoteOfWizardToSpecificLevelCorrectlySetsLevel()
{
    command("promote fred to senior", Wizard);
    ExpectEq("senior", Wizard2.wizardLevel());

    ExpectEq("You promote Fred to senior.\n", Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotPromoteToALowerLevel()
{
    command("promote fred to wizard", Wizard);
    ExpectEq("senior", Wizard2.wizardLevel());
    ExpectEq("Fred is already a wizard or higher. Use demote instead if "
        "this is intended.\n", Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotPromoteToAnInvalidLevel()
{
    command("promote fred to lizard", Wizard);
    ExpectEq("senior", Wizard2.wizardLevel());
    ExpectEq("Lizard is not a valid wizard level.\n", Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DemoteOfWizardToSpecificLevelCorrectlySetsLevel()
{
    command("demote fred to wizard", Wizard);
    ExpectEq("wizard", Wizard2.wizardLevel());

    ExpectEq("You demote Fred to wizard.\n", Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DemoteOfWizardToSpecificLevelThatIsHigherFails()
{
    command("demote fred to admin", Wizard);
    ExpectEq("wizard", Wizard2.wizardLevel());

    ExpectEq("Fred is already a lower wizard level than admin.\n"
        "If this was intended, use promote instead.\n", 
        Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DemoteOfWizardToWithoutParameterDemotesToPlayer()
{
    command("demote fred", Wizard);

    object newPlayer = findPlayer("fred");
    ExpectEq(-1, member(inherit_list(newPlayer),
        "/lib/realizations/wizard.c"));

    ExpectEq("You demote Fred to player.\n", Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DemoteOfWizardToPlayerDemotesToPlayer()
{
    command("promote fred", Wizard);
    command("demote fred to player", Wizard);

    object newPlayer = findPlayer("fred");
    ExpectEq(-1, member(inherit_list(newPlayer),
        "/lib/realizations/wizard.c"));

    ExpectEq("You demote Fred to player.\n", Wizard.caughtMessage());
}
