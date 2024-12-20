//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Wizard;
object Wizard2;
object Catch;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database.PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess.savePlayerData(database.GetWizardOfLevel("creator"));

    Wizard2 = clone_object("/lib/realizations/wizard.c");
    Wizard2.restore("earl");
    Wizard2.Name("fred");
    Wizard2.addCommands();
    clone_object("/lib/tests/support/services/catchShadow.c").beginShadow(Wizard2);

    dataAccess.savePlayerData(database.GetWizardOfLevel("elder"));

    destruct(dataAccess);
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Catch = clone_object("/lib/tests/support/services/catchShadow.c");

    Wizard = clone_object("/lib/realizations/wizard.c");
    Wizard.restore("earl");
    Wizard.addCommands();
    Catch.beginShadow(Wizard);
    setUsers(({ Wizard, Wizard2 }));

    Wizard2.resetCatchList();
    object channels = load_object("/lib/dictionaries/channelDictionary.c");
    channels.registerUser(Wizard);
    channels.registerUser(Wizard2);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Wizard);
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpIsNotGreedy()
{
    ExpectFalse(Wizard.executeCommand("whiz"), "whiz");
    ExpectFalse(Wizard.executeCommand("hizz"), "hizz");
}

/////////////////////////////////////////////////////////////////////////////
void CanSendMessageOnHizLine()
{
    ExpectTrue(Wizard.executeCommand("hiz Hi"));
    ExpectSubStringMatch("Hiz Earl.*Hi", Wizard.caughtMessage());
    ExpectEq(0, Wizard2.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanNotSendEmptyMessageOnHizLine()
{
    ExpectFalse(Wizard.executeCommand("hiz"));
    ExpectEq(0, Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanNotSendMessageOnHizIfNotOfProperLevel()
{
    ExpectFalse(Wizard2.executeCommand("hiz Hi"));
    ExpectEq(0, Wizard.caughtMessage());
}

