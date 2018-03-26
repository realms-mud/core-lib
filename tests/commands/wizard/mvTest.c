//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    ExpectFalse(Wizard->executeCommand("mmv x y"), "mmv");
    ExpectFalse(Wizard->executeCommand("mvv x y"), "mvv");
}

/////////////////////////////////////////////////////////////////////////////
void MvMovesFileToCorrectLocation()
{
    copy_file("/players/earl/blah", "/players/earl/x");
    ExpectEq(0, file_size("/players/earl/x"));
    ExpectEq(-1, file_size("/players/earl/y"));
    ExpectTrue(Wizard->executeCommand("mv /players/earl/x /players/earl/y"));
    ExpectEq(-1, file_size("/players/earl/x"));
    ExpectEq(0, file_size("/players/earl/y"));
    rm("/players/earl/y");
}
