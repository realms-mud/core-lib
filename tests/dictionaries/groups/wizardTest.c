//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Wizard;

protected nosave int Unknown = 0x8;
protected nosave int None = 0x0;
protected nosave int Owner = 0x1;
protected nosave int Write = 0x2;
protected nosave int Read = 0x4;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database->PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess->savePlayerData(database->GetWizardOfLevel("wizard"));

    destruct(dataAccess);
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Wizard = clone_object("/lib/realizations/wizard.c");
    Wizard->restore("earl");
    setUsers(({ Wizard }));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Wizard);
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanReadFilesInRoot()
{
    ExpectTrue(Wizard->hasReadAccess("/ulmo.debug.log"));
    ExpectTrue(Wizard->hasReadAccess("/doc/regexp"));
    ExpectTrue(Wizard->hasReadAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotWriteFilesInRoot()
{
    ExpectFalse(Wizard->hasWriteAccess("/ulmo.debug.log"));
    ExpectFalse(Wizard->hasWriteAccess("/doc/regexp"));
    ExpectFalse(Wizard->hasWriteAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardIsNotOwnerOfFilesInRoot()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/ulmo.debug.log"));
    ExpectFalse(Wizard->hasOwnershipAccess("/doc/regexp"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotReadFilesInSecure()
{
    ExpectFalse(Wizard->hasReadAccess("/secure"));
    ExpectFalse(Wizard->hasReadAccess("/secure/master.c"));
    ExpectFalse(Wizard->hasReadAccess("/secure/room/board.c"));
    ExpectFalse(Wizard->hasReadAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotWriteFilesInSecure()
{
    ExpectFalse(Wizard->hasWriteAccess("/secure"));
    ExpectFalse(Wizard->hasWriteAccess("/secure/master.c"));
    ExpectFalse(Wizard->hasWriteAccess("/secure/room/board.c"));
    ExpectFalse(Wizard->hasWriteAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardIsNotOwnerOfFilesInSecure()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/secure"));
    ExpectFalse(Wizard->hasOwnershipAccess("/secure/master.c"));
    ExpectFalse(Wizard->hasOwnershipAccess("/secure/room/board.c"));
    ExpectFalse(Wizard->hasOwnershipAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotReadFilesInMail()
{
    ExpectFalse(Wizard->hasReadAccess("/mail"));
    ExpectFalse(Wizard->hasReadAccess("/mail/m/maeglin.o"));
    ExpectFalse(Wizard->hasReadAccess("/mail/b/blah.o"));
    ExpectTrue(Wizard->hasReadAccess("/mail/e/earl.o"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotWriteFilesInMail()
{
    ExpectFalse(Wizard->hasWriteAccess("/mail"));
    ExpectFalse(Wizard->hasWriteAccess("/mail/m/maeglin.o"));
    ExpectFalse(Wizard->hasWriteAccess("/mail/b/blah.o"));
    ExpectTrue(Wizard->hasReadAccess("/mail/e/earl.o"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardIsNotOwnerOfFilesInMail()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/mail"));
    ExpectFalse(Wizard->hasOwnershipAccess("/mail/m/maeglin.o"));
    ExpectFalse(Wizard->hasOwnershipAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void CanReadPlans()
{
    ExpectTrue(Wizard->hasReadAccess("/players/maeglin/.plan"));
    ExpectTrue(Wizard->hasReadAccess("/players/weasel/.plan"));
    ExpectTrue(Wizard->hasReadAccess("/players/earl/.plan"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotReadFilesInBanish()
{
    ExpectFalse(Wizard->hasReadAccess("/banish"));
    ExpectFalse(Wizard->hasReadAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotWriteFilesInBanish()
{
    ExpectFalse(Wizard->hasWriteAccess("/banish"));
    ExpectFalse(Wizard->hasWriteAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardIsNotOwnerOfFilesInBanish()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/banish"));
    ExpectFalse(Wizard->hasOwnershipAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotReadFilesInGodstf()
{
    ExpectFalse(Wizard->hasReadAccess("/godstf"));
    ExpectFalse(Wizard->hasReadAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotWriteFilesInGodstf()
{
    ExpectFalse(Wizard->hasWriteAccess("/godstf"));
    ExpectFalse(Wizard->hasWriteAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardIsNotOwnerOfFilesInGodstf()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/godstf"));
    ExpectFalse(Wizard->hasOwnershipAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanReadFilesInRoom()
{
    ExpectTrue(Wizard->hasReadAccess("/room"));
    ExpectTrue(Wizard->hasReadAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotWriteFilesInRoom()
{
    ExpectFalse(Wizard->hasWriteAccess("/room"));
    ExpectFalse(Wizard->hasWriteAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardIsNotOwnerOfFilesInRoom()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/room"));
    ExpectFalse(Wizard->hasOwnershipAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanReadFilesInLog()
{
    ExpectTrue(Wizard->hasReadAccess("/log/EXPERIENCE"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotWriteFilesInLog()
{
    ExpectFalse(Wizard->hasWriteAccess("/log"));
    ExpectFalse(Wizard->hasWriteAccess("/log/EXPERIENCE"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardIsNotOwnerOfFilesInLog()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/log"));
    ExpectFalse(Wizard->hasOwnershipAccess("/log/EXPERIENCE"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanReadTheirLogs()
{
    ExpectTrue(Wizard->hasReadAccess("/log"));
    ExpectTrue(Wizard->hasReadAccess("/log/earl"));
    ExpectTrue(Wizard->hasReadAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanWriteTheirFilesInLog()
{
    ExpectTrue(Wizard->hasWriteAccess("/log/earl"));
    ExpectTrue(Wizard->hasWriteAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardIsOwnerOfTheirFilesInLog()
{
    ExpectTrue(Wizard->hasOwnershipAccess("/log/earl"));
    ExpectTrue(Wizard->hasOwnershipAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanReadFilesInOpen()
{
    ExpectTrue(Wizard->hasReadAccess("/open"));
    ExpectTrue(Wizard->hasReadAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanWriteFilesInOpen()
{
    ExpectTrue(Wizard->hasWriteAccess("/open"));
    ExpectTrue(Wizard->hasWriteAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardIsNotOwnerOfFilesInOpen()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/open"));
    ExpectFalse(Wizard->hasOwnershipAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotReadFilesInGuild()
{
    ExpectFalse(Wizard->hasReadAccess("/guild"));
    ExpectFalse(Wizard->hasReadAccess("/guild/mage/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotWriteFilesInGuild()
{
    ExpectFalse(Wizard->hasWriteAccess("/guild"));
    ExpectFalse(Wizard->hasWriteAccess("/guild/priest/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardIsNotOwnerOfFilesInGuild()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/guild"));
    ExpectFalse(Wizard->hasOwnershipAccess("/guild/fighter/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanReadFilesInLib()
{
    ExpectTrue(Wizard->hasReadAccess("/lib"));
    ExpectTrue(Wizard->hasReadAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotWriteFilesInLib()
{
    ExpectFalse(Wizard->hasWriteAccess("/lib"));
    ExpectFalse(Wizard->hasWriteAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardIsNotOwnerOfFilesInLib()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/lib"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotReadFilesInLibSecure()
{
    ExpectFalse(Wizard->hasReadAccess("/lib/dictionaries/groups"));
    ExpectFalse(Wizard->hasReadAccess("/lib/tests/dictionaries/groups"));
    ExpectFalse(Wizard->hasReadAccess("/lib/dictionaries/groups/wizard.c"));
    ExpectFalse(Wizard->hasReadAccess("/lib/modules/secure/"));
    ExpectFalse(Wizard->hasReadAccess("/lib/tests/modules/secure/"));
    ExpectFalse(Wizard->hasReadAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotWriteFilesInLibSecure()
{
    ExpectFalse(Wizard->hasWriteAccess("/lib/dictionaries/groups"));
    ExpectFalse(Wizard->hasWriteAccess("/lib/tests/dictionaries/groups"));
    ExpectFalse(Wizard->hasWriteAccess("/lib/dictionaries/groups/wizard.c"));
    ExpectFalse(Wizard->hasWriteAccess("/lib/modules/secure/"));
    ExpectFalse(Wizard->hasWriteAccess("/lib/tests/modules/secure/"));
    ExpectFalse(Wizard->hasWriteAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardIsNotOwnerOfFilesInLibSecure()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/dictionaries/groups"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/tests/dictionaries/groups"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/dictionaries/groups/wizard.c"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/modules/secure/"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/tests/modules/secure/"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanReadFilesInPlayers()
{
    ExpectTrue(Wizard->hasReadAccess("/players"));
    ExpectTrue(Wizard->hasReadAccess("/players/maeglin/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotWriteFilesInPlayers()
{
    ExpectFalse(Wizard->hasWriteAccess("/players"));
    ExpectFalse(Wizard->hasWriteAccess("/players/sonja/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardIsNotOwnerOfFilesInPlayers()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/players"));
    ExpectFalse(Wizard->hasOwnershipAccess("/players/valren/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanReadTheirOwnFiles()
{
    ExpectTrue(Wizard->hasReadAccess("/players/earl"));
    ExpectTrue(Wizard->hasReadAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanWriteTheirOwnFiles()
{
    ExpectTrue(Wizard->hasWriteAccess("/players/earl"));
    ExpectTrue(Wizard->hasWriteAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardIsOwnerOfTheirOwnFiles()
{
    ExpectTrue(Wizard->hasOwnershipAccess("/players/earl"));
    ExpectTrue(Wizard->hasOwnershipAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotReadOtherClosed()
{
    ExpectFalse(Wizard->hasReadAccess("/players/fred/closed"));
    ExpectFalse(Wizard->hasReadAccess("/players/fred/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotWriteOtherClosed()
{
    ExpectFalse(Wizard->hasWriteAccess("/players/fred/closed"));
    ExpectFalse(Wizard->hasWriteAccess("/players/fred/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardIsNotOwnerOfOtherClosed()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/players/fred/closed"));
    ExpectFalse(Wizard->hasOwnershipAccess("/players/fred/closed/blah.c"));
}