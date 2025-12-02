//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Wizard;
object DataAccess;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database.PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess.savePlayerData(database.GetWizardOfLevel("elder", "earl"));
    dataAccess.savePlayerData(database.GetWizardOfLevel("wizard", "fred"));

    destruct(dataAccess);
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Wizard = clone_object("/lib/realizations/wizard.c");
    Wizard.restore("earl");
    Wizard.addCommands();
    Wizard.colorConfiguration("none");
    object Catch = clone_object("/lib/tests/support/services/catchShadow.c");
    Catch.beginShadow(Wizard);

    set_this_player(Wizard);

    DataAccess =
        clone_object("/lib/modules/secure/dataServices/settingsDataService.c");

    setUsers(({ Wizard }));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    string *roles = m_indices(DataAccess.availableRoles());
    if (sizeof(roles))
    {
        foreach(string role in roles)
        {
            DataAccess.removeRoleFromPlayer(Wizard, role);
        }
    }

    destruct(Wizard);
}

/////////////////////////////////////////////////////////////////////////////
void EmptyRoleListDisplaysCorrectly()
{
    ExpectTrue(Wizard.executeCommand("role -l"));
    ExpectEq("No roles have been created.\n", Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void RoleListDisplaysCorrectly()
{
    ExpectTrue(DataAccess.addRole("Head of Awesomeness", "leadership"));
    ExpectTrue(DataAccess.addRole("Lackey", "liason"));
    ExpectTrue(DataAccess.addRole("Fred's stuff", "area"));
    ExpectTrue(DataAccess.addRole("Lib stuff", "development"));

    ExpectTrue(Wizard.executeCommand("role -l"));
    ExpectEq("\nRole Type      Name of the Role                                      Granter LVL\n"
        "Area           Fred's stuff                                          Wizard\n"
        "Leadership     Head of Awesomeness                                   Elder\n"
        "Liason         Lackey                                                Senior\n"
        "Development    Lib stuff                                             Admin\n",
        Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddInvalidRole()
{
    ExpectTrue(DataAccess.addRole("Head of Awesomeness", "leadership"));

    ExpectEq("", Wizard.displayRoles());
    ExpectTrue(Wizard.executeCommand("role -t earl -a Blarg"));
    ExpectEq("The 'Blarg' role is not available. If the role is what you "
        "intended to use,\nyou will first need to add it using the "
        "'create-role' command.\n",
        Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddRoleToInvalidTarget()
{
    ExpectTrue(DataAccess.addRole("Head of Awesomeness", "leadership"));
    ExpectTrue(DataAccess.addRole("Lackey", "liason"));
    ExpectTrue(DataAccess.addRole("Fred's stuff", "area"));
    ExpectTrue(DataAccess.addRole("Lib stuff", "development"));

    ExpectTrue(Wizard.executeCommand("role -t fred -a Head of Awesomeness"));
    ExpectEq("", Wizard.displayRoles());
    ExpectEq("The target does not appear to exist.\n",
        Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddRoleWhenNotOfSufficientLevel()
{
    ExpectTrue(DataAccess.addRole("Head of Awesomeness", "leadership"));
    ExpectTrue(DataAccess.addRole("Lackey", "liason"));
    ExpectTrue(DataAccess.addRole("Fred's stuff", "area"));
    ExpectTrue(DataAccess.addRole("Lib stuff", "development"));
    Wizard.restore("fred");
    Wizard.colorConfiguration("none");

    ExpectEq("", Wizard.displayRoles());
    ExpectTrue(Wizard.executeCommand("role -t fred -a Head of Awesomeness"));
    ExpectEq("Failed to add the 'Head of Awesomeness' role to Fred.\n",
        Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotRemoveRoleWhenNotOfSufficientLevel()
{
    ExpectTrue(DataAccess.addRole("Head of Awesomeness", "leadership"));
    ExpectTrue(DataAccess.addRole("Lackey", "liason"));
    ExpectTrue(DataAccess.addRole("Fred's stuff", "area"));
    ExpectTrue(DataAccess.addRole("Lib stuff", "development"));

    object fred = clone_object("/lib/realizations/wizard.c");
    fred.restore("fred");
    fred.colorConfiguration("none");
    object catchShadow = clone_object("/lib/tests/support/services/catchShadow.c");
    catchShadow.beginShadow(fred);

    DataAccess =
        clone_object("/lib/modules/secure/dataServices/settingsDataService.c");

    setUsers(({ Wizard, fred }));

    ExpectEq("", Wizard.displayRoles());
    ExpectTrue(Wizard.executeCommand("role -t earl -a Head of Awesomeness"));
    ExpectEq("He has the following roles ->\n"
        "    Head of Awesomeness\n",
        Wizard.displayRoles());

    set_this_player(fred);
    ExpectTrue(fred.executeCommand("role -t earl -r Head of Awesomeness"));
    set_this_player(Wizard);

    ExpectEq("Failed to remove the 'Head of Awesomeness' role from Earl.\n",
        fred.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanAddRole()
{
    ExpectTrue(DataAccess.addRole("Head of Awesomeness", "leadership"));
    ExpectTrue(DataAccess.addRole("Lackey", "liason"));
    ExpectTrue(DataAccess.addRole("Fred's stuff", "area"));
    ExpectTrue(DataAccess.addRole("Lib stuff", "development"));

    ExpectEq("", Wizard.displayRoles());
    ExpectTrue(Wizard.executeCommand("role -t earl -a Head of Awesomeness"));
    ExpectEq("He has the following roles ->\n"
        "    Head of Awesomeness\n",
        Wizard.displayRoles());
    ExpectEq("The 'Head of Awesomeness' role was added to Earl.\n",
        Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanRemoveRole()
{
    ExpectTrue(DataAccess.addRole("Head of Awesomeness", "leadership"));
    ExpectTrue(DataAccess.addRole("Lackey", "liason"));
    ExpectTrue(DataAccess.addRole("Fred's stuff", "area"));
    ExpectTrue(DataAccess.addRole("Lib stuff", "development"));
    ExpectTrue(Wizard.addRole("Head of Awesomeness"));

    ExpectEq("He has the following roles ->\n"
        "    Head of Awesomeness\n",
        Wizard.displayRoles());

    ExpectTrue(Wizard.executeCommand("role -t earl -r Head of Awesomeness"));
    ExpectEq("", Wizard.displayRoles());
    ExpectEq("The 'Head of Awesomeness' role was removed from Earl.\n",
        Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotCreateAlreadyExistingRole()
{
    ExpectTrue(DataAccess.addRole("Head of Awesomeness", "leadership"));
    ExpectTrue(DataAccess.addRole("Lackey", "liason"));
    ExpectTrue(DataAccess.addRole("Fred's stuff", "area"));
    ExpectTrue(DataAccess.addRole("Lib stuff", "development"));

    mapping roles = ([ 
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
        ]), ]);

    ExpectEq(roles, availableRoles());

    ExpectTrue(Wizard.executeCommand("create-role -t liason -r Lackey"));
    ExpectEq("The 'Lackey' role already exists.\n",
        Wizard.caughtMessage());

    ExpectEq(roles, availableRoles());
}

/////////////////////////////////////////////////////////////////////////////
void MustSupplyRoleAndTypeToCreateRole()
{
    ExpectTrue(DataAccess.addRole("Head of Awesomeness", "leadership"));
    ExpectTrue(DataAccess.addRole("Lackey", "liason"));
    ExpectTrue(DataAccess.addRole("Fred's stuff", "area"));
    ExpectTrue(DataAccess.addRole("Lib stuff", "development"));

    mapping roles = ([ 
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
        ]), ]);
    
    ExpectEq(roles, availableRoles());

    ExpectTrue(Wizard.executeCommand("create-role -r Blarg"));
    ExpectEq("Both the -t and -r flags must be specified.\n",
        Wizard.caughtMessage());

    Wizard.resetCatchList();

    ExpectTrue(Wizard.executeCommand("create-role -t area"));
    ExpectEq("Both the -t and -r flags must be specified.\n",
        Wizard.caughtMessage());

    ExpectEq(roles, availableRoles());
}

/////////////////////////////////////////////////////////////////////////////
void CanCreateRole()
{
    ExpectTrue(DataAccess.addRole("Head of Awesomeness", "leadership"));
    ExpectTrue(DataAccess.addRole("Lackey", "liason"));
    ExpectTrue(DataAccess.addRole("Fred's stuff", "area"));
    ExpectTrue(DataAccess.addRole("Lib stuff", "development"));

    mapping roles = ([ 
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
        ]), ]);
    ExpectEq(roles, availableRoles());

    ExpectTrue(Wizard.executeCommand("create-role -t area -r Area of areaness"));
    ExpectEq("The 'Area of areaness' role was created.\n",
        Wizard.caughtMessage());
    
    roles["Area of areaness"] = ([
        "add level": "wizard",
        "type": "area",
    ]);

    ExpectEq(roles, availableRoles());
}
