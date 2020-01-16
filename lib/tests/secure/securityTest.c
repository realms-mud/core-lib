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
    object player = load_object("/lib/realizations/player.c");
    set_this_player(player);
    clone_object("/lib/tests/support/services/catchShadow.c")->beginShadow(player);

    string writePath = Security->valid_write("/secure/master.c", "fred",
        "write_file", player);

    ExpectFalse(writePath);
    ExpectEq("Bad file name (master::valid_write): \"/secure/master.c\" "
        "(\"write_file\"), caller lib/realizations/player\n", 
        player->caughtMessage());
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
    Security->ToggleInteractive(Wizard);

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
    object cpTest = load_object("/lib/tests/commands/wizard/cpTest.c");
    set_this_player(cpTest);
    clone_object("/lib/tests/support/services/catchShadow.c")->beginShadow(cpTest);

    ExpectFalse(Security->valid_write("/secure/master.c", "fred",
        "write_file", cpTest));

    ExpectEq("Bad file name (master::valid_write): \"/secure/master.c\" "
        "(\"write_file\"), caller lib/tests/commands/wizard/cpTest\n",
        cpTest->caughtMessage());
    cpTest->resetCatchList();

    ExpectFalse(Security->valid_write("/secure/master.c", "fred",
        "copy_file", cpTest));

    ExpectEq("Bad file name (master::valid_write): \"/secure/master.c\" "
        "(\"copy_file\"), caller lib/tests/commands/wizard/cpTest\n",
        cpTest->caughtMessage());
    cpTest->resetCatchList();

    ExpectFalse(Security->valid_write("/players/earl/blah.c", "fred",
        "write_file", cpTest));

    ExpectEq("Bad file name (master::valid_write): \"/players/earl/blah.c\" "
        "(\"write_file\"), caller lib/tests/commands/wizard/cpTest\n",
        cpTest->caughtMessage());
    cpTest->resetCatchList();

    ExpectFalse(Security->valid_read("/players/earl", "fred",
        "get_dir", cpTest));

    ExpectEq("Bad file name (master::valid_read): \"/players/earl\" "
        "(\"get_dir\"), caller lib/tests/commands/wizard/cpTest\n",
        cpTest->caughtMessage());
    cpTest->resetCatchList();

    ExpectEq("/players/earl/blah.c", Security->valid_write("/players/earl/blah.c", "fred",
        "copy_file", cpTest));

    ExpectEq(0, cpTest->caughtMessage());

    ExpectEq("/players/earl/blah.c", Security->valid_read("/players/earl/blah.c", "fred",
        "file_size", cpTest));

    ExpectEq(0, cpTest->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PriviledgedObjectsCanExecuteReadFunctions()
{
    string readPath = Security->valid_write("/secure/master.c", "fred", 
        "read_file", load_object("/secure/master.c"));

    ExpectEq("/secure/master.c", readPath);

    readPath = Security->valid_read("/secure/master.c", "fred",
        "read_file", load_object("/lib/modules/secure/persistence.c"));

    ExpectEq("/secure/master.c", readPath);
}

/////////////////////////////////////////////////////////////////////////////
void UnpriviledgedObjectsCannotExecuteReadFunctions()
{
    object player = load_object("/lib/realizations/player.c");
    set_this_player(player);
    clone_object("/lib/tests/support/services/catchShadow.c")->beginShadow(player);

    string readPath = Security->valid_read("/secure/master.c", "fred",
        "read_file", player);

    ExpectFalse(readPath);
    ExpectEq("Bad file name (master::valid_read): \"/secure/master.c\" "
        "(\"read_file\"), caller lib/realizations/player\n", 
        player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void NonInteractiveWizardsHaveNoReadAccess()
{
    set_this_player(Wizard);

    ExpectEq(0, Security->valid_read("/lpmud.log", "earl",
        "read_file", Wizard));

    ExpectEq(0, Security->valid_read("/players/earl/x.c", "earl",
        "read_file", Wizard));

    ExpectEq(0, Security->valid_read("/lib/modules/secure/persistence.c", "earl",
        "read_file", Wizard));

    ExpectEq(0, Security->valid_read("/secure/master.c", "earl",
        "read_file", Wizard));

    ExpectEq(0, Security->valid_read("/areas/eledhel", "earl",
        "get_dir", Wizard));

    ExpectEq(0, Security->valid_read("/secure/master.c", "earl",
        "file_size", Wizard));

    ExpectEq(0, Security->valid_read("/tutorial/temple/fred.c", "earl",
        "read_file", Wizard));

    ExpectEq(0, Security->valid_read("/guilds/stuff.c", "earl",
        "read_file", Wizard));
}

/////////////////////////////////////////////////////////////////////////////
void WizardsHaveAppropriateReadAccess()
{
    set_this_player(Wizard);
    Security->ToggleInteractive(Wizard);

    ExpectEq("/lpmud.log", Security->valid_read("/lpmud.log", "earl",
        "read_file", Wizard));

    ExpectEq("/players/earl/x.c", Security->valid_read("/players/earl/x.c", "earl",
        "read_file", Wizard));

    ExpectEq(0, 
        Security->valid_read("/lib/modules/secure/persistence.c", "earl",
        "read_file", Wizard));

    ExpectEq(0, Security->valid_read("/secure/master.c", "earl",
        "read_file", Wizard));

    ExpectEq("/areas/eledhel", Security->valid_read("/areas/eledhel", "earl",
        "get_dir", Wizard));

    ExpectEq("/lib/realizations/player.c", 
        Security->valid_read("/lib/realizations/player.c", "earl",
        "file_size", Wizard));

    ExpectEq("/tutorial/temple/fred.c", 
        Security->valid_read("/tutorial/temple/fred.c", "earl",
        "read_file", Wizard));

    ExpectEq("/guilds/stuff.c", 
        Security->valid_read("/guilds/stuff.c", "earl",
        "read_file", Wizard));
}
