//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    database.PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess.savePlayerData(database.GetWizardOfLevel("owner"));

    destruct(dataAccess);
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Wizard = clone_object("/lib/realizations/wizard.c");
    Wizard.restore("earl");
    setUsers(({ Wizard }));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Wizard);
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanReadFilesInRoot()
{
    ExpectTrue(Wizard.hasReadAccess("/ulmo.debug.log"));
    ExpectTrue(Wizard.hasReadAccess("/doc/regexp"));
    ExpectTrue(Wizard.hasReadAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanWriteFilesInRoot()
{
    ExpectTrue(Wizard.hasWriteAccess("/ulmo.debug.log"));
    ExpectTrue(Wizard.hasWriteAccess("/doc/regexp"));
    ExpectTrue(Wizard.hasWriteAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerIsOwnerOfFilesInRoot()
{
    ExpectTrue(Wizard.hasOwnershipAccess("/ulmo.debug.log"));
    ExpectTrue(Wizard.hasOwnershipAccess("/doc/regexp"));
    ExpectTrue(Wizard.hasOwnershipAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanReadFilesInSecure()
{
    ExpectTrue(Wizard.hasReadAccess("/secure"));
    ExpectTrue(Wizard.hasReadAccess("/secure/master.c"));
    ExpectTrue(Wizard.hasReadAccess("/secure/room/board.c"));
    ExpectTrue(Wizard.hasReadAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanWriteFilesInSecure()
{
    ExpectTrue(Wizard.hasWriteAccess("/secure"));
    ExpectTrue(Wizard.hasWriteAccess("/secure/master.c"));
    ExpectTrue(Wizard.hasWriteAccess("/secure/room/board.c"));
    ExpectTrue(Wizard.hasWriteAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerIsOwnerOfFilesInSecure()
{
    ExpectTrue(Wizard.hasOwnershipAccess("/secure"));
    ExpectTrue(Wizard.hasOwnershipAccess("/secure/master.c"));
    ExpectTrue(Wizard.hasOwnershipAccess("/secure/room/board.c"));
    ExpectTrue(Wizard.hasOwnershipAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanReadFilesInMail()
{
    ExpectTrue(Wizard.hasReadAccess("/mail"));
    ExpectTrue(Wizard.hasReadAccess("/mail/m/maeglin.o"));
    ExpectTrue(Wizard.hasReadAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanWriteFilesInMail()
{
    ExpectTrue(Wizard.hasWriteAccess("/mail"));
    ExpectTrue(Wizard.hasWriteAccess("/mail/m/maeglin.o"));
    ExpectTrue(Wizard.hasWriteAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerIsOwnerOfFilesInMail()
{
    ExpectTrue(Wizard.hasOwnershipAccess("/mail"));
    ExpectTrue(Wizard.hasOwnershipAccess("/mail/m/maeglin.o"));
    ExpectTrue(Wizard.hasOwnershipAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanReadFilesInBanish()
{
    ExpectTrue(Wizard.hasReadAccess("/banish"));
    ExpectTrue(Wizard.hasReadAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanWriteFilesInBanish()
{
    ExpectTrue(Wizard.hasWriteAccess("/banish"));
    ExpectTrue(Wizard.hasWriteAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerIsOwnerOfFilesInBanish()
{
    ExpectTrue(Wizard.hasOwnershipAccess("/banish"));
    ExpectTrue(Wizard.hasOwnershipAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanReadFilesInOwnerstf()
{
    ExpectTrue(Wizard.hasReadAccess("/godstf"));
    ExpectTrue(Wizard.hasReadAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanWriteFilesInOwnerstf()
{
    ExpectTrue(Wizard.hasWriteAccess("/godstf"));
    ExpectTrue(Wizard.hasWriteAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerIsOwnerOfFilesInOwnerstf()
{
    ExpectTrue(Wizard.hasOwnershipAccess("/godstf"));
    ExpectTrue(Wizard.hasOwnershipAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanReadFilesInRoom()
{
    ExpectTrue(Wizard.hasReadAccess("/room"));
    ExpectTrue(Wizard.hasReadAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanWriteFilesInRoom()
{
    ExpectTrue(Wizard.hasWriteAccess("/room"));
    ExpectTrue(Wizard.hasWriteAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerIsOwnerOfFilesInRoom()
{
    ExpectTrue(Wizard.hasOwnershipAccess("/room"));
    ExpectTrue(Wizard.hasOwnershipAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanReadFilesInOpen()
{
    ExpectTrue(Wizard.hasReadAccess("/open"));
    ExpectTrue(Wizard.hasReadAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanWriteFilesInOpen()
{
    ExpectTrue(Wizard.hasWriteAccess("/open"));
    ExpectTrue(Wizard.hasWriteAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerIsOwnerOfFilesInOpen()
{
    ExpectTrue(Wizard.hasOwnershipAccess("/open"));
    ExpectTrue(Wizard.hasOwnershipAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanReadFilesInGuild()
{
    ExpectTrue(Wizard.hasReadAccess("/guilds"));
    ExpectTrue(Wizard.hasReadAccess("/guilds/mage/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanWriteFilesInGuild()
{
    ExpectTrue(Wizard.hasWriteAccess("/guilds"));
    ExpectTrue(Wizard.hasWriteAccess("/guilds/priest/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerIsOwnerOfFilesInGuild()
{
    ExpectTrue(Wizard.hasOwnershipAccess("/guilds"));
    ExpectTrue(Wizard.hasOwnershipAccess("/guilds/fighter/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanReadFilesInLib()
{
    ExpectTrue(Wizard.hasReadAccess("/lib"));
    ExpectTrue(Wizard.hasReadAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanWriteFilesInLib()
{
    ExpectTrue(Wizard.hasWriteAccess("/lib"));
    ExpectTrue(Wizard.hasWriteAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerIsOwnerOfFilesInLib()
{
    ExpectTrue(Wizard.hasOwnershipAccess("/lib"));
    ExpectTrue(Wizard.hasOwnershipAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanReadFilesInLibSecure()
{
    ExpectTrue(Wizard.hasReadAccess("/lib/dictionaries/groups"));
    ExpectTrue(Wizard.hasReadAccess("/lib/tests/dictionaries/groups"));
    ExpectTrue(Wizard.hasReadAccess("/lib/dictionaries/groups/wizard.c"));
    ExpectTrue(Wizard.hasReadAccess("/lib/modules/secure/"));
    ExpectTrue(Wizard.hasReadAccess("/lib/tests/modules/secure/"));
    ExpectTrue(Wizard.hasReadAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanWriteFilesInLibSecure()
{
    ExpectTrue(Wizard.hasWriteAccess("/lib/dictionaries/groups"));
    ExpectTrue(Wizard.hasWriteAccess("/lib/tests/dictionaries/groups"));
    ExpectTrue(Wizard.hasWriteAccess("/lib/dictionaries/groups/wizard.c"));
    ExpectTrue(Wizard.hasWriteAccess("/lib/modules/secure/"));
    ExpectTrue(Wizard.hasWriteAccess("/lib/tests/modules/secure/"));
    ExpectTrue(Wizard.hasWriteAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerIsOwnerOfFilesInLibSecure()
{
    ExpectTrue(Wizard.hasOwnershipAccess("/lib/dictionaries/groups"));
    ExpectTrue(Wizard.hasOwnershipAccess("/lib/tests/dictionaries/groups"));
    ExpectTrue(Wizard.hasOwnershipAccess("/lib/dictionaries/groups/wizard.c"));
    ExpectTrue(Wizard.hasOwnershipAccess("/lib/modules/secure/"));
    ExpectTrue(Wizard.hasOwnershipAccess("/lib/tests/modules/secure/"));
    ExpectTrue(Wizard.hasOwnershipAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanReadFilesInPlayers()
{
    ExpectTrue(Wizard.hasReadAccess("/players"));
    ExpectTrue(Wizard.hasReadAccess("/players/maeglin/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanWriteFilesInPlayers()
{
    ExpectTrue(Wizard.hasWriteAccess("/players"));
    ExpectTrue(Wizard.hasWriteAccess("/players/sonja/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerIsOwnerOfFilesInPlayers()
{
    ExpectTrue(Wizard.hasOwnershipAccess("/players"));
    ExpectTrue(Wizard.hasOwnershipAccess("/players/valren/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanReadTheirOwnFiles()
{
    ExpectTrue(Wizard.hasReadAccess("/players/earl"));
    ExpectTrue(Wizard.hasReadAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanWriteTheirOwnFiles()
{
    ExpectTrue(Wizard.hasWriteAccess("/players/earl"));
    ExpectTrue(Wizard.hasWriteAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerIsOwnerOfTheirOwnFiles()
{
    ExpectTrue(Wizard.hasOwnershipAccess("/players/earl"));
    ExpectTrue(Wizard.hasOwnershipAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanReadFilesInLog()
{
    ExpectTrue(Wizard.hasReadAccess("/log/EXPERIENCE"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanWriteFilesInLog()
{
    ExpectTrue(Wizard.hasWriteAccess("/log"));
    ExpectTrue(Wizard.hasWriteAccess("/log/EXPERIENCE"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerIsOwnerOfFilesInLog()
{
    ExpectTrue(Wizard.hasOwnershipAccess("/log"));
    ExpectTrue(Wizard.hasOwnershipAccess("/log/EXPERIENCE"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanReadTheirLogs()
{
    ExpectTrue(Wizard.hasReadAccess("/log"));
    ExpectTrue(Wizard.hasReadAccess("/log/earl"));
    ExpectTrue(Wizard.hasReadAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanWriteTheirFilesInLog()
{
    ExpectTrue(Wizard.hasWriteAccess("/log/earl"));
    ExpectTrue(Wizard.hasWriteAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerIsOwnerOfTheirFilesInLog()
{
    ExpectTrue(Wizard.hasOwnershipAccess("/log/earl"));
    ExpectTrue(Wizard.hasOwnershipAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanReadOtherClosed()
{
    ExpectTrue(Wizard.hasReadAccess("/players/fred/closed"));
    ExpectTrue(Wizard.hasReadAccess("/players/fred/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerCanWriteOtherClosed()
{
    ExpectTrue(Wizard.hasWriteAccess("/players/fred/closed"));
    ExpectTrue(Wizard.hasWriteAccess("/players/fred/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OwnerIsOwnerOfOtherClosed()
{
    ExpectTrue(Wizard.hasOwnershipAccess("/players/fred/closed"));
    ExpectTrue(Wizard.hasOwnershipAccess("/players/fred/closed/blah.c"));
}
