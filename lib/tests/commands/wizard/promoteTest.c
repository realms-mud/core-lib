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

    Wizard2 = clone_object("/lib/realizations/wizard.c");
    Wizard2->restore("earl");
    Wizard2->Name("fred");
    Wizard2->addCommands();
    clone_object("/lib/tests/support/services/catchShadow.c")->beginShadow(Wizard2);

    dataAccess->savePlayerData(database->GetWizardOfLevel("elder"));

    Player = clone_object("/lib/realizations/player.c");
    Player->restore("gorthaur");
    Player->addCommands();
    clone_object("/lib/tests/support/services/catchShadow.c")->beginShadow(Player);

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

    setUsers(({ Wizard, Wizard2, Player }));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Wizard);
    destruct(Wizard2);
    destruct(Player);
}
