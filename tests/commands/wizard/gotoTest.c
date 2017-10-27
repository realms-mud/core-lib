//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Wizard;
object Room;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database->PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess->savePlayerData(database->GetWizardOfLevel("creator"));

    destruct(dataAccess);
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Room = clone_object("/lib/environment/room.c");

    Wizard = clone_object("/lib/realizations/wizard.c");
    Wizard->restore("earl");
    Wizard->addCommands();
    setUsers(({ Wizard }));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Wizard);
    destruct(Room);
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpIsNotGreedy()
{
    ExpectFalse(Wizard->executeCommand("ggoto"), "ggoto");
    ExpectFalse(Wizard->executeCommand("gotor"), "gotor");
}
