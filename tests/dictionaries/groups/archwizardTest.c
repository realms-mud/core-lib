//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    dataAccess->savePlayerData(database->GetWizardOfLevel("archwizard"));

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
void ArchwizardCanReadFilesInRoot()
{
    ExpectTrue(Wizard->hasReadAccess("/ulmo.debug.log"));
    ExpectTrue(Wizard->hasReadAccess("/doc/regexp"));
    ExpectTrue(Wizard->hasReadAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanWriteFilesInRoot()
{
    ExpectTrue(Wizard->hasWriteAccess("/ulmo.debug.log"));
    ExpectTrue(Wizard->hasWriteAccess("/doc/regexp"));
    ExpectTrue(Wizard->hasWriteAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardIsNotOwnerOfFilesInRoot()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/ulmo.debug.log"));
    ExpectFalse(Wizard->hasOwnershipAccess("/doc/regexp"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanNotReadFilesInSecure()
{
    ExpectFalse(Wizard->hasReadAccess("/secure"));
    ExpectFalse(Wizard->hasReadAccess("/secure/master.c"));
    ExpectFalse(Wizard->hasReadAccess("/secure/room/board.c"));
    ExpectFalse(Wizard->hasReadAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanNotWriteFilesInSecure()
{
    ExpectFalse(Wizard->hasWriteAccess("/secure"));
    ExpectFalse(Wizard->hasWriteAccess("/secure/master.c"));
    ExpectFalse(Wizard->hasWriteAccess("/secure/room/board.c"));
    ExpectFalse(Wizard->hasWriteAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardIsNotOwnerOfFilesInSecure()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/secure"));
    ExpectFalse(Wizard->hasOwnershipAccess("/secure/master.c"));
    ExpectFalse(Wizard->hasOwnershipAccess("/secure/room/board.c"));
    ExpectFalse(Wizard->hasOwnershipAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanReadFilesInMail()
{
    ExpectTrue(Wizard->hasReadAccess("/mail"));
    ExpectTrue(Wizard->hasReadAccess("/mail/m/maeglin.o"));
    ExpectTrue(Wizard->hasReadAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanWriteFilesInMail()
{
    ExpectTrue(Wizard->hasWriteAccess("/mail"));
    ExpectTrue(Wizard->hasWriteAccess("/mail/m/maeglin.o"));
    ExpectTrue(Wizard->hasWriteAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardIsNotOwnerOfFilesInMail()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/mail"));
    ExpectFalse(Wizard->hasOwnershipAccess("/mail/m/maeglin.o"));
    ExpectFalse(Wizard->hasOwnershipAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanReadFilesInBanish()
{
    ExpectTrue(Wizard->hasReadAccess("/banish"));
    ExpectTrue(Wizard->hasReadAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanWriteFilesInBanish()
{
    ExpectTrue(Wizard->hasWriteAccess("/banish"));
    ExpectTrue(Wizard->hasWriteAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardIsNotOwnerOfFilesInBanish()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/banish"));
    ExpectFalse(Wizard->hasOwnershipAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanNotReadFilesInGodstf()
{
    ExpectFalse(Wizard->hasReadAccess("/godstf"));
    ExpectFalse(Wizard->hasReadAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanNotWriteFilesInGodstf()
{
    ExpectFalse(Wizard->hasWriteAccess("/godstf"));
    ExpectFalse(Wizard->hasWriteAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardIsNotOwnerOfFilesInGodstf()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/godstf"));
    ExpectFalse(Wizard->hasOwnershipAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanReadFilesInRoom()
{
    ExpectTrue(Wizard->hasReadAccess("/room"));
    ExpectTrue(Wizard->hasReadAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanWriteFilesInRoom()
{
    ExpectTrue(Wizard->hasWriteAccess("/room"));
    ExpectTrue(Wizard->hasWriteAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardIsNotOwnerOfFilesInRoom()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/room"));
    ExpectFalse(Wizard->hasOwnershipAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanReadFilesInOpen()
{
    ExpectTrue(Wizard->hasReadAccess("/open"));
    ExpectTrue(Wizard->hasReadAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanWriteFilesInOpen()
{
    ExpectTrue(Wizard->hasWriteAccess("/open"));
    ExpectTrue(Wizard->hasWriteAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardIsNotOwnerOfFilesInOpen()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/open"));
    ExpectFalse(Wizard->hasOwnershipAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanReadFilesInGuild()
{
    ExpectTrue(Wizard->hasReadAccess("/guild"));
    ExpectTrue(Wizard->hasReadAccess("/guild/mage/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanWriteFilesInGuild()
{
    ExpectTrue(Wizard->hasWriteAccess("/guild"));
    ExpectTrue(Wizard->hasWriteAccess("/guild/priest/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardIsNotOwnerOfFilesInGuild()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/guild"));
    ExpectFalse(Wizard->hasOwnershipAccess("/guild/fighter/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanReadFilesInLib()
{
    ExpectTrue(Wizard->hasReadAccess("/lib"));
    ExpectTrue(Wizard->hasReadAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanWriteFilesInLib()
{
    ExpectTrue(Wizard->hasWriteAccess("/lib"));
    ExpectTrue(Wizard->hasWriteAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardIsNotOwnerOfFilesInLib()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/lib"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanNotReadFilesInLibSecure()
{
    ExpectFalse(Wizard->hasReadAccess("/lib/dictionaries/groups"));
    ExpectFalse(Wizard->hasReadAccess("/lib/tests/dictionaries/groups"));
    ExpectFalse(Wizard->hasReadAccess("/lib/dictionaries/groups/wizard.c"));
    ExpectFalse(Wizard->hasReadAccess("/lib/modules/secure/"));
    ExpectFalse(Wizard->hasReadAccess("/lib/tests/modules/secure/"));
    ExpectFalse(Wizard->hasReadAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanNotWriteFilesInLibSecure()
{
    ExpectFalse(Wizard->hasWriteAccess("/lib/dictionaries/groups"));
    ExpectFalse(Wizard->hasWriteAccess("/lib/tests/dictionaries/groups"));
    ExpectFalse(Wizard->hasWriteAccess("/lib/dictionaries/groups/wizard.c"));
    ExpectFalse(Wizard->hasWriteAccess("/lib/modules/secure/"));
    ExpectFalse(Wizard->hasWriteAccess("/lib/tests/modules/secure/"));
    ExpectFalse(Wizard->hasWriteAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardIsNotOwnerOfFilesInLibSecure()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/dictionaries/groups"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/tests/dictionaries/groups"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/dictionaries/groups/wizard.c"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/modules/secure/"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/tests/modules/secure/"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanReadFilesInPlayers()
{
    ExpectTrue(Wizard->hasReadAccess("/players"));
    ExpectTrue(Wizard->hasReadAccess("/players/maeglin/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanWriteFilesInPlayers()
{
    ExpectTrue(Wizard->hasWriteAccess("/players"));
    ExpectTrue(Wizard->hasWriteAccess("/players/sonja/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardIsNotOwnerOfFilesInPlayers()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/players"));
    ExpectFalse(Wizard->hasOwnershipAccess("/players/valren/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanReadTheirOwnFiles()
{
    ExpectTrue(Wizard->hasReadAccess("/players/earl"));
    ExpectTrue(Wizard->hasReadAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanWriteTheirOwnFiles()
{
    ExpectTrue(Wizard->hasWriteAccess("/players/earl"));
    ExpectTrue(Wizard->hasWriteAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardIsOwnerOfTheirOwnFiles()
{
    ExpectTrue(Wizard->hasOwnershipAccess("/players/earl"));
    ExpectTrue(Wizard->hasOwnershipAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanReadFilesInLog()
{
    ExpectTrue(Wizard->hasReadAccess("/log/EXPERIENCE"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanWriteFilesInLog()
{
    ExpectTrue(Wizard->hasWriteAccess("/log"));
    ExpectTrue(Wizard->hasWriteAccess("/log/EXPERIENCE"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardIsNotOwnerOfFilesInLog()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/log"));
    ExpectFalse(Wizard->hasOwnershipAccess("/log/EXPERIENCE"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanReadTheirLogs()
{
    ExpectTrue(Wizard->hasReadAccess("/log"));
    ExpectTrue(Wizard->hasReadAccess("/log/earl"));
    ExpectTrue(Wizard->hasReadAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanWriteTheirFilesInLog()
{
    ExpectTrue(Wizard->hasWriteAccess("/log/earl"));
    ExpectTrue(Wizard->hasWriteAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardIsOwnerOfTheirFilesInLog()
{
    ExpectTrue(Wizard->hasOwnershipAccess("/log/earl"));
    ExpectTrue(Wizard->hasOwnershipAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanReadOtherClosed()
{
    ExpectTrue(Wizard->hasReadAccess("/players/fred/closed"));
    ExpectTrue(Wizard->hasReadAccess("/players/fred/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardCanWriteOtherClosed()
{
    ExpectTrue(Wizard->hasWriteAccess("/players/fred/closed"));
    ExpectTrue(Wizard->hasWriteAccess("/players/fred/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ArchwizardIsNotOwnerOfOtherClosed()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/players/fred/closed"));
    ExpectFalse(Wizard->hasOwnershipAccess("/players/fred/closed/blah.c"));
}