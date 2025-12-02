//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object DataAccess;
object Database;
object GrantingWizard;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    Database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    Database.PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess.savePlayerData(Database.GetWizardOfLevel("owner", "earl"));

    dataAccess.savePlayerData(Database.GetWizardOfLevel("wizard", "fred"));
    destruct(dataAccess);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    DataAccess = 
        clone_object("/lib/modules/secure/dataServices/settingsDataService.c");

    GrantingWizard = clone_object("/lib/realizations/wizard.c");
    GrantingWizard.restore("earl");
    object Catch = clone_object("/lib/tests/support/services/catchShadow.c");
    Catch.beginShadow(GrantingWizard);

    set_this_player(GrantingWizard);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(GrantingWizard);
    destruct(DataAccess);
}

/////////////////////////////////////////////////////////////////////////////
void CanAddRoleToPlayer()
{
    ExpectTrue(DataAccess.addRole("Head of Awesomeness", "development"));

    object grantee = clone_object("/lib/realizations/wizard.c");
    grantee.restore("fred");
    GrantingWizard.colorConfiguration("none");

    ExpectTrue(grantee.addRole("Head of Awesomeness"));

    ExpectEq("He has the following roles ->\n"
        "    Head of Awesomeness\n", 
        grantee.displayRoles());

    destruct(grantee);
    grantee = clone_object("/lib/realizations/wizard.c");
    grantee.restore("fred");

    ExpectEq("He has the following roles ->\n"
        "    Head of Awesomeness\n",
        grantee.displayRoles());
}

/////////////////////////////////////////////////////////////////////////////
void CanRemoveRoleFromPlayer()
{
    ExpectTrue(DataAccess.addRole("Head of Awesomeness", "development"));

    object grantee = clone_object("/lib/realizations/wizard.c");
    grantee.restore("fred");
    GrantingWizard.colorConfiguration("none");

    ExpectTrue(grantee.addRole("Head of Awesomeness"));

    ExpectEq("He has the following roles ->\n"
        "    Head of Awesomeness\n",
        grantee.displayRoles());

    ExpectTrue(grantee.removeRole("Head of Awesomeness"), "removing");
    ExpectEq("", grantee.displayRoles());

    destruct(grantee);
    grantee = clone_object("/lib/realizations/wizard.c");
    grantee.restore("fred");

    ExpectEq("", grantee.displayRoles());
}

/////////////////////////////////////////////////////////////////////////////
void CanGetAvailableRoles()
{
    ExpectTrue(DataAccess.addRole("Head of Awesomeness", "leadership"));
    ExpectTrue(DataAccess.addRole("Lackey", "liason"));
    ExpectTrue(DataAccess.addRole("Fred's stuff", "area"));
    ExpectTrue(DataAccess.addRole("Lib stuff", "development"));

    ExpectEq(([ 
        "Fred's stuff": ([ 
            "add level": "wizard", 
            "type": "area", 
        ]), 
        "Head of Awesomeness": ([ 
            "add level": "elder", 
            "type": "leadership", 
        ]), 
        "Lackey": ([ 
            "add level": "senior", 
            "type": "liason", 
        ]), 
        "Lib stuff": ([ 
            "add level": "admin", 
            "type": "development", 
        ]), ]), DataAccess.availableRoles());
}
