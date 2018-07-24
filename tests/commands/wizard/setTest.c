//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Wizard;
object Catch;

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
    Catch = clone_object("/lib/tests/support/services/catchShadow.c");

    Wizard = clone_object("/lib/realizations/wizard.c");
    Wizard->restore("earl");
    Wizard->addCommands();
    Catch->beginShadow(Wizard);
    setUsers(({ Wizard }));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Catch);
    destruct(Wizard);
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpIsNotGreedy()
{
    ExpectFalse(Wizard->executeCommand("sset"), "sset");
    ExpectFalse(Wizard->executeCommand("sett"), "sett");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetMessageInWithMessageIn()
{
    ExpectTrue(Wizard->executeCommand("set -p message in -v transblargifies"));
    ExpectEq("transblargifies", Wizard->MessageIn());
    ExpectEq("You have set your 'message in' to 'transblargifies'.\n", 
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetMessageInWithMsgIn()
{
    ExpectTrue(Wizard->executeCommand("set -p msgin -v blah"));
    ExpectEq("blah", Wizard->MessageIn());
    ExpectEq("You have set your 'msgin' to 'blah'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetMessageOutWithMessageOut()
{
    ExpectTrue(Wizard->executeCommand("set -p message out -v transblargifies"));
    ExpectEq("transblargifies", Wizard->MessageOut());
    ExpectEq("You have set your 'message out' to 'transblargifies'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetMessageOutWithMsgOut()
{
    ExpectTrue(Wizard->executeCommand("set -p msgout -v blah"));
    ExpectEq("blah", Wizard->MessageOut());
    ExpectEq("You have set your 'msgout' to 'blah'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetMagicalMessageInWithMagicalMessageIn()
{
    ExpectTrue(Wizard->executeCommand("set -p magical message in -v transblargifies"));
    ExpectEq("transblargifies", Wizard->MagicalMessageIn());
    ExpectEq("You have set your 'magical message in' to 'transblargifies'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetMagicalMessageInWithMMsgIn()
{
    ExpectTrue(Wizard->executeCommand("set -p mmsgin -v blah"));
    ExpectEq("blah", Wizard->MagicalMessageIn());
    ExpectEq("You have set your 'mmsgin' to 'blah'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetMagicalMessageOutWithMagicalMessageOut()
{
    ExpectTrue(Wizard->executeCommand("set -p magical message out -v transblargifies"));
    ExpectEq("transblargifies", Wizard->MagicalMessageOut());
    ExpectEq("You have set your 'magical message out' to 'transblargifies'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetMagicalMessageOutWithMMsgOut()
{
    ExpectTrue(Wizard->executeCommand("set -p mmsgout -v blah"));
    ExpectEq("blah", Wizard->MagicalMessageOut());
    ExpectEq("You have set your 'mmsgout' to 'blah'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetHomeWithMessageHome()
{
    ExpectTrue(Wizard->executeCommand("set -p message home -v transblargifies"));
    ExpectEq("transblargifies", Wizard->MessageHome());
    ExpectEq("You have set your 'message home' to 'transblargifies'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetHomeWithHomeMessage()
{
    ExpectTrue(Wizard->executeCommand("set -p home message -v transblargifies"));
    ExpectEq("transblargifies", Wizard->MessageHome());
    ExpectEq("You have set your 'home message' to 'transblargifies'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetCloneWithMessageClone()
{
    ExpectTrue(Wizard->executeCommand("set -p message clone -v transblargifies"));
    ExpectEq("transblargifies", Wizard->MessageClone());
    ExpectEq("You have set your 'message clone' to 'transblargifies'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetCloneWithCloneMessage()
{
    ExpectTrue(Wizard->executeCommand("set -p clone message -v transblargifies"));
    ExpectEq("transblargifies", Wizard->MessageClone());
    ExpectEq("You have set your 'clone message' to 'transblargifies'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetTitle()
{
    ExpectTrue(Wizard->executeCommand("set -p title -v transblargifying"));
    ExpectEq("transblargifying", Wizard->Title());
    ExpectEq("You have set your 'title' to 'transblargifying'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetPretitle()
{
    ExpectTrue(Wizard->executeCommand("set -p pretitle -v transblargifying"));
    ExpectEq("transblargifying", Wizard->Pretitle());
    ExpectEq("You have set your 'pretitle' to 'transblargifying'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetShort()
{
    ExpectTrue(Wizard->executeCommand("set -p short -v transblargifying"));
    ExpectEq("transblargifying", Wizard->short());
    ExpectEq("You have set your 'short' to 'transblargifying'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetShortDescription()
{
    ExpectTrue(Wizard->executeCommand("set -p short description -v transblargifying"));
    ExpectEq("transblargifying", Wizard->short());
    ExpectEq("You have set your 'short description' to 'transblargifying'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetLongDescription()
{
    ExpectTrue(Wizard->executeCommand("set -p long description -v transblargifying"));
    ExpectEq("transblargifying", Wizard->description());
    ExpectEq("You have set your 'long description' to 'transblargifying'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetDescription()
{
    ExpectTrue(Wizard->executeCommand("set -p description -v transblargifying"));
    ExpectEq("transblargifying", Wizard->description());
    ExpectEq("You have set your 'description' to 'transblargifying'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanNotSetInvalidParameter()
{
    ExpectFalse(Wizard->executeCommand("set -p blarg -v transblargifying"));
}

/////////////////////////////////////////////////////////////////////////////
void CanNotSetWithoutValue()
{
    ExpectFalse(Wizard->executeCommand("set -p blarg"));
}

/////////////////////////////////////////////////////////////////////////////
void CanReverseParameters()
{
    ExpectTrue(Wizard->executeCommand("set -v transblargifying -p description"));
    ExpectEq("transblargifying", Wizard->description());
    ExpectEq("You have set your 'description' to 'transblargifying'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanUseDashesWhenParametersReversed()
{
    ExpectTrue(Wizard->executeCommand("set -v transblargifying-blah and blah -p description"));
    ExpectEq("transblargifying-blah and blah", Wizard->description());
    ExpectEq("You have set your 'description' to 'transblargifying-blah and blah'.\n",
        Wizard->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanUseDashesInValue()
{
    ExpectTrue(Wizard->executeCommand("set -p description -v transblargifying-blah and blah"));
    ExpectEq("transblargifying-blah and blah", Wizard->description());
    ExpectEq("You have set your 'description' to 'transblargifying-blah and blah'.\n",
        Wizard->caughtMessage());
}
