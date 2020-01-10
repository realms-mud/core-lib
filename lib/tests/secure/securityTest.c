//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include <functionlist.h>

object Security;
object Wizard;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database->PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess->savePlayerData(database->GetWizardOfLevel("elder"));

    destruct(dataAccess);
    destruct(database);

    string *functions = filter(
        functionlist(this_object(), RETURN_FUNCTION_NAME),
        (: sizeof(regexp(({ $1 }), "__inline")) :));

    ignoreList += functions;
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Security = clone_object("/lib/tests/support/master/securityHelper.c");

    Wizard = clone_object("/lib/realizations/wizard.c");
    Wizard->restore("earl");
    setUsers(({ Wizard }));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Security);
    destruct(Wizard);
}

/////////////////////////////////////////////////////////////////////////////
void PriviledgedObjectsCanExecuteWriteFunctions()
{
    string writePath = Security->valid_write("/secure/master.c", "fred", 
        "write_file", load_object("/secure/master.c"));

    ExpectEq("/secure/master.c", writePath);

    writePath = Security->valid_write("/secure/master.c", "fred",
        "write_file", load_object("/lib/modules/secure/persistence.c"));

    ExpectEq("/secure/master.c", writePath);
}

/////////////////////////////////////////////////////////////////////////////
void UnpriviledgedObjectsCannotExecuteWriteFunctions()
{
    string writePath = Security->valid_write("/secure/master.c", "fred",
        "write_file", load_object("/lib/realizations/player.c"));

    ExpectFalse(writePath);
}

/////////////////////////////////////////////////////////////////////////////
void NonInteractiveWizardsHaveNoWriteAccess()
{
    set_this_player(Wizard);

    ExpectEq(0, Security->valid_write("/lpmud.log", "earl",
        "write_file", Wizard));

    ExpectEq(0, Security->valid_write("/players/earl/x.c", "earl",
        "write_file", Wizard));

    ExpectEq(0, Security->valid_write("/lib/modules/secure/persistence.c", "earl",
        "write_file", Wizard));

    ExpectEq(0, Security->valid_write("/secure/master.c", "earl",
        "write_file", Wizard));

    ExpectEq(0, Security->valid_write("/areas/eledhel", "earl",
        "rmdir", Wizard));

    ExpectEq(0, Security->valid_write("/lib/realizations/player.c", "earl",
        "copy_file", Wizard));

    ExpectEq(0, Security->valid_write("/tutorial/temple/fred.c", "earl",
        "write_file", Wizard));

    ExpectEq(0, Security->valid_write("/guilds/stuff.c", "earl",
        "write_file", Wizard));
}

/////////////////////////////////////////////////////////////////////////////
void WizardsHaveAppropriateWriteAccess()
{
    set_this_player(Wizard);
    Security->ToggleInteractive();

    ExpectEq("/lpmud.log", Security->valid_write("/lpmud.log", "earl",
        "write_file", Wizard));

    ExpectEq("/players/earl/x.c", Security->valid_write("/players/earl/x.c", "earl",
        "write_file", Wizard));

    ExpectEq(0, 
        Security->valid_write("/lib/modules/secure/persistence.c", "earl",
        "write_file", Wizard));

    ExpectEq(0, Security->valid_write("/secure/master.c", "earl",
        "write_file", Wizard));

    ExpectEq("/areas/eledhel", Security->valid_write("/areas/eledhel", "earl",
        "rmdir", Wizard));

    ExpectEq(0, 
        Security->valid_write("/lib/realizations/player.c", "earl",
        "copy_file", Wizard));

    ExpectEq("/tutorial/temple/fred.c", 
        Security->valid_write("/tutorial/temple/fred.c", "earl",
        "write_file", Wizard));

    ExpectEq("/guilds/stuff.c", 
        Security->valid_write("/guilds/stuff.c", "earl",
        "write_file", Wizard));
}

/////////////////////////////////////////////////////////////////////////////
void PriviledgedEscalatedObjectsCanOnlyExecuteAuthorizedMethodsInEscaltedDirectories()
{
    ExpectFalse(Security->valid_write("/secure/master.c", "fred",
        "write_file", load_object("/lib/tests/commands/wizard/cpTest.c")));

    ExpectFalse(Security->valid_write("/secure/master.c", "fred",
        "copy_file", load_object("/lib/tests/commands/wizard/cpTest.c")));

    ExpectFalse(Security->valid_write("/players/earl/blah.c", "fred",
        "write_file", load_object("/lib/tests/commands/wizard/cpTest.c")));

    ExpectEq("/players/earl/blah.c", Security->valid_write("/players/earl/blah.c", "fred",
        "copy_file", load_object("/lib/tests/commands/wizard/cpTest.c")));
}
