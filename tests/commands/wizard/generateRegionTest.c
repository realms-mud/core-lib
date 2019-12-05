//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Wizard;

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
    Wizard = clone_object("/lib/realizations/wizard.c");
    Wizard->restore("earl");
    Wizard->addCommands();

    clone_object("/lib/tests/support/services/catchShadow.c")->beginShadow(Wizard);

    setUsers(({ Wizard }));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Wizard);
}

/////////////////////////////////////////////////////////////////////////////
void WarningDisplayedIfNameNotSupplied()
{
    ExpectTrue(Wizard->executeCommand("generate region"));
    ExpectSubStringMatch("The region name must be specified", 
        Wizard->caughtMessages());
}

/////////////////////////////////////////////////////////////////////////////
void WarningDisplayedIfPathNotSupplied()
{
    ExpectTrue(Wizard->executeCommand("generate region"));
    ExpectSubStringMatch("The save location.*must be specified",
        Wizard->caughtMessages());
}

/////////////////////////////////////////////////////////////////////////////
void WarningDisplayedIfPathNotWriteable()
{
    ExpectTrue(Wizard->executeCommand("generate region -n blah -p /secure"));
    ExpectSubStringMatch("You do not have write access",
        Wizard->caughtMessages());
}

/////////////////////////////////////////////////////////////////////////////
void WarningDisplayedIfPathDoesNotExits()
{
    ExpectTrue(Wizard->executeCommand("generate region -n blah -p /blarf"));
    ExpectSubStringMatch("The directory specified with the.*flag does not",
        Wizard->caughtMessages());
}

/////////////////////////////////////////////////////////////////////////////
void WarningDisplayedIfInvalidTypeSet()
{
    ExpectTrue(Wizard->executeCommand("generate region -n blah -p "
        "/players/earl -t llama"));
    ExpectSubStringMatch("The region type must be a valid region type",
        Wizard->caughtMessages());
}

/////////////////////////////////////////////////////////////////////////////
void WarningDisplayedIfInvalidDimensionSet()
{
    ExpectTrue(Wizard->executeCommand("generate region -n blah -p "
        "/players/earl -x 3"));
    ExpectSubStringMatch("The x and y dimensions must be between 5-25",
        Wizard->caughtMessages());

    ExpectTrue(Wizard->executeCommand("generate region -n blah -p "
        "/players/earl -x 32"));
    ExpectSubStringMatch("The x and y dimensions must be between 5-25",
        Wizard->caughtMessages());

    ExpectTrue(Wizard->executeCommand("generate region -n blah -p "
        "/players/earl -y 3"));
    ExpectSubStringMatch("The x and y dimensions must be between 5-25",
        Wizard->caughtMessages());

    ExpectTrue(Wizard->executeCommand("generate region -n blah -p "
        "/players/earl -y 26"));
    ExpectSubStringMatch("The x and y dimensions must be between 5-25",
        Wizard->caughtMessages());
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectTypeWithQuotes()
{
    ExpectTrue(Wizard->executeCommand("generate region -n blah -p "
        "/players/earl -t \"keeper's temple\""));
    ExpectSubStringMatch("Type 'C' to create, 'R' to generate a different "
        "region, or anything", Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WarningDisplayedIfInvalidSettlementChanceSet()
{
    ExpectTrue(Wizard->executeCommand("generate region -n blah -p "
        "/players/earl -x 5 -y 5 -s 120"));
    ExpectSubStringMatch("The settlement chance must be in the range of 0",
        Wizard->caughtMessages());
}

/////////////////////////////////////////////////////////////////////////////
void WarningDisplayedIfInvalidLevelSet()
{
    ExpectTrue(Wizard->executeCommand("generate region -n blah -p "
        "/players/earl -x 5 -y 5 -l 0"));
    ExpectSubStringMatch("The level must be in the range of 1 to 200",
        Wizard->caughtMessages());
}

/////////////////////////////////////////////////////////////////////////////
void WarningDisplayedIfInvalidRoomNumber()
{
    ExpectTrue(Wizard->executeCommand("generate region -n blah -p "
        "/players/earl -x 5 -y 5 -r 100"));
    ExpectSubStringMatch("The room count.*must be in the range of 5 to 15",
        Wizard->caughtMessages());
}

/////////////////////////////////////////////////////////////////////////////
void PromptedToGenerateRegionWhenAllParametersValid()
{
    ExpectTrue(Wizard->executeCommand("generate region -n george -p "
        "/players/earl -x 5 -y 5 -t forest -s 100 -direction east -de "
        "/players/maeglin/shop.c -l 40 -r 15"));
    ExpectSubStringMatch("Type 'C' to create, 'R' to generate a different "
        "region, or anything", Wizard->caughtMessage());
}
