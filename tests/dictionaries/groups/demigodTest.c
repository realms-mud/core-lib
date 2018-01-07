//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    dataAccess->savePlayerData(database->GetWizardOfLevel("demigod"));

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
void DemigodCanReadFilesInRoot()
{
    ExpectTrue(Wizard->hasReadAccess("/ulmo.debug.log"));
    ExpectTrue(Wizard->hasReadAccess("/doc/regexp"));
    ExpectTrue(Wizard->hasReadAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanWriteFilesInRoot()
{
    ExpectTrue(Wizard->hasWriteAccess("/ulmo.debug.log"));
    ExpectTrue(Wizard->hasWriteAccess("/doc/regexp"));
    ExpectTrue(Wizard->hasWriteAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodIsNotOwnerOfFilesInRoot()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/ulmo.debug.log"));
    ExpectFalse(Wizard->hasOwnershipAccess("/doc/regexp"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanReadFilesInSecure()
{
    ExpectTrue(Wizard->hasReadAccess("/secure"));
    ExpectTrue(Wizard->hasReadAccess("/secure/master.c"));
    ExpectTrue(Wizard->hasReadAccess("/secure/room/board.c"));
    ExpectTrue(Wizard->hasReadAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanWriteFilesInSecure()
{
    ExpectTrue(Wizard->hasWriteAccess("/secure"));
    ExpectTrue(Wizard->hasWriteAccess("/secure/master.c"));
    ExpectTrue(Wizard->hasWriteAccess("/secure/room/board.c"));
    ExpectTrue(Wizard->hasWriteAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodIsNotOwnerOfFilesInSecure()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/secure"));
    ExpectFalse(Wizard->hasOwnershipAccess("/secure/master.c"));
    ExpectFalse(Wizard->hasOwnershipAccess("/secure/room/board.c"));
    ExpectFalse(Wizard->hasOwnershipAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanReadFilesInMail()
{
    ExpectTrue(Wizard->hasReadAccess("/mail"));
    ExpectTrue(Wizard->hasReadAccess("/mail/m/maeglin.o"));
    ExpectTrue(Wizard->hasReadAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanWriteFilesInMail()
{
    ExpectTrue(Wizard->hasWriteAccess("/mail"));
    ExpectTrue(Wizard->hasWriteAccess("/mail/m/maeglin.o"));
    ExpectTrue(Wizard->hasWriteAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodIsNotOwnerOfFilesInMail()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/mail"));
    ExpectFalse(Wizard->hasOwnershipAccess("/mail/m/maeglin.o"));
    ExpectFalse(Wizard->hasOwnershipAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanReadFilesInBanish()
{
    ExpectTrue(Wizard->hasReadAccess("/banish"));
    ExpectTrue(Wizard->hasReadAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanWriteFilesInBanish()
{
    ExpectTrue(Wizard->hasWriteAccess("/banish"));
    ExpectTrue(Wizard->hasWriteAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodIsNotOwnerOfFilesInBanish()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/banish"));
    ExpectFalse(Wizard->hasOwnershipAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanNotReadFilesInGodstf()
{
    ExpectFalse(Wizard->hasReadAccess("/godstf"));
    ExpectFalse(Wizard->hasReadAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanNotWriteFilesInGodstf()
{
    ExpectFalse(Wizard->hasWriteAccess("/godstf"));
    ExpectFalse(Wizard->hasWriteAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodIsNotOwnerOfFilesInGodstf()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/godstf"));
    ExpectFalse(Wizard->hasOwnershipAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanReadFilesInRoom()
{
    ExpectTrue(Wizard->hasReadAccess("/room"));
    ExpectTrue(Wizard->hasReadAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanWriteFilesInRoom()
{
    ExpectTrue(Wizard->hasWriteAccess("/room"));
    ExpectTrue(Wizard->hasWriteAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodIsNotOwnerOfFilesInRoom()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/room"));
    ExpectFalse(Wizard->hasOwnershipAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanReadFilesInOpen()
{
    ExpectTrue(Wizard->hasReadAccess("/open"));
    ExpectTrue(Wizard->hasReadAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanWriteFilesInOpen()
{
    ExpectTrue(Wizard->hasWriteAccess("/open"));
    ExpectTrue(Wizard->hasWriteAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodIsNotOwnerOfFilesInOpen()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/open"));
    ExpectFalse(Wizard->hasOwnershipAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanReadFilesInGuild()
{
    ExpectTrue(Wizard->hasReadAccess("/guild"));
    ExpectTrue(Wizard->hasReadAccess("/guild/mage/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanWriteFilesInGuild()
{
    ExpectTrue(Wizard->hasWriteAccess("/guild"));
    ExpectTrue(Wizard->hasWriteAccess("/guild/priest/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodIsNotOwnerOfFilesInGuild()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/guild"));
    ExpectFalse(Wizard->hasOwnershipAccess("/guild/fighter/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanReadFilesInLib()
{
    ExpectTrue(Wizard->hasReadAccess("/lib"));
    ExpectTrue(Wizard->hasReadAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanWriteFilesInLib()
{
    ExpectTrue(Wizard->hasWriteAccess("/lib"));
    ExpectTrue(Wizard->hasWriteAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodIsNotOwnerOfFilesInLib()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/lib"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanReadFilesInLibSecure()
{
    ExpectTrue(Wizard->hasReadAccess("/lib/dictionaries/groups"));
    ExpectTrue(Wizard->hasReadAccess("/lib/tests/dictionaries/groups"));
    ExpectTrue(Wizard->hasReadAccess("/lib/dictionaries/groups/wizard.c"));
    ExpectTrue(Wizard->hasReadAccess("/lib/modules/secure/"));
    ExpectTrue(Wizard->hasReadAccess("/lib/tests/modules/secure/"));
    ExpectTrue(Wizard->hasReadAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanWriteFilesInLibSecure()
{
    ExpectTrue(Wizard->hasWriteAccess("/lib/dictionaries/groups"));
    ExpectTrue(Wizard->hasWriteAccess("/lib/tests/dictionaries/groups"));
    ExpectTrue(Wizard->hasWriteAccess("/lib/dictionaries/groups/wizard.c"));
    ExpectTrue(Wizard->hasWriteAccess("/lib/modules/secure/"));
    ExpectTrue(Wizard->hasWriteAccess("/lib/tests/modules/secure/"));
    ExpectTrue(Wizard->hasWriteAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodIsNotOwnerOfFilesInLibSecure()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/dictionaries/groups"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/tests/dictionaries/groups"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/dictionaries/groups/wizard.c"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/modules/secure/"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/tests/modules/secure/"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanReadFilesInPlayers()
{
    ExpectTrue(Wizard->hasReadAccess("/players"));
    ExpectTrue(Wizard->hasReadAccess("/players/maeglin/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanWriteFilesInPlayers()
{
    ExpectTrue(Wizard->hasWriteAccess("/players"));
    ExpectTrue(Wizard->hasWriteAccess("/players/sonja/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodIsNotOwnerOfFilesInPlayers()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/players"));
    ExpectFalse(Wizard->hasOwnershipAccess("/players/valren/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanReadTheirOwnFiles()
{
    ExpectTrue(Wizard->hasReadAccess("/players/earl"));
    ExpectTrue(Wizard->hasReadAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanWriteTheirOwnFiles()
{
    ExpectTrue(Wizard->hasWriteAccess("/players/earl"));
    ExpectTrue(Wizard->hasWriteAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodIsOwnerOfTheirOwnFiles()
{
    ExpectTrue(Wizard->hasOwnershipAccess("/players/earl"));
    ExpectTrue(Wizard->hasOwnershipAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanReadFilesInLog()
{
    ExpectTrue(Wizard->hasReadAccess("/log/EXPERIENCE"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanWriteFilesInLog()
{
    ExpectTrue(Wizard->hasWriteAccess("/log"));
    ExpectTrue(Wizard->hasWriteAccess("/log/EXPERIENCE"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodIsNotOwnerOfFilesInLog()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/log"));
    ExpectFalse(Wizard->hasOwnershipAccess("/log/EXPERIENCE"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanReadTheirLogs()
{
    ExpectTrue(Wizard->hasReadAccess("/log"));
    ExpectTrue(Wizard->hasReadAccess("/log/earl"));
    ExpectTrue(Wizard->hasReadAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanWriteTheirFilesInLog()
{
    ExpectTrue(Wizard->hasWriteAccess("/log/earl"));
    ExpectTrue(Wizard->hasWriteAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodIsOwnerOfTheirFilesInLog()
{
    ExpectTrue(Wizard->hasOwnershipAccess("/log/earl"));
    ExpectTrue(Wizard->hasOwnershipAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanReadOtherClosed()
{
    ExpectTrue(Wizard->hasReadAccess("/players/fred/closed"));
    ExpectTrue(Wizard->hasReadAccess("/players/fred/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodCanWriteOtherClosed()
{
    ExpectTrue(Wizard->hasWriteAccess("/players/fred/closed"));
    ExpectTrue(Wizard->hasWriteAccess("/players/fred/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DemigodIsNotOwnerOfOtherClosed()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/players/fred/closed"));
    ExpectFalse(Wizard->hasOwnershipAccess("/players/fred/closed/blah.c"));
}