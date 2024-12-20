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
    dataAccess.savePlayerData(database.GetWizardOfLevel("elder"));

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
void ElderCanReadFilesInRoot()
{
    ExpectTrue(Wizard.hasReadAccess("/ulmo.debug.log"));
    ExpectTrue(Wizard.hasReadAccess("/doc/regexp"));
    ExpectTrue(Wizard.hasReadAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanWriteFilesInRoot()
{
    ExpectTrue(Wizard.hasWriteAccess("/ulmo.debug.log"));
    ExpectTrue(Wizard.hasWriteAccess("/doc/regexp"));
    ExpectFalse(Wizard.hasWriteAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderIsNotOwnerOfFilesInRoot()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/ulmo.debug.log"));
    ExpectFalse(Wizard.hasOwnershipAccess("/doc/regexp"));
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanNotReadFilesInSecure()
{
    ExpectFalse(Wizard.hasReadAccess("/secure"));
    ExpectFalse(Wizard.hasReadAccess("/secure/master.c"));
    ExpectFalse(Wizard.hasReadAccess("/secure/room/board.c"));
    ExpectFalse(Wizard.hasReadAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanNotWriteFilesInSecure()
{
    ExpectFalse(Wizard.hasWriteAccess("/secure"));
    ExpectFalse(Wizard.hasWriteAccess("/secure/master.c"));
    ExpectFalse(Wizard.hasWriteAccess("/secure/room/board.c"));
    ExpectFalse(Wizard.hasWriteAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderIsNotOwnerOfFilesInSecure()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/secure"));
    ExpectFalse(Wizard.hasOwnershipAccess("/secure/master.c"));
    ExpectFalse(Wizard.hasOwnershipAccess("/secure/room/board.c"));
    ExpectFalse(Wizard.hasOwnershipAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanReadFilesInMail()
{
    ExpectTrue(Wizard.hasReadAccess("/mail"));
    ExpectTrue(Wizard.hasReadAccess("/mail/m/maeglin.o"));
    ExpectTrue(Wizard.hasReadAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanNotWriteFilesInMail()
{
    ExpectFalse(Wizard.hasWriteAccess("/mail"));
    ExpectFalse(Wizard.hasWriteAccess("/mail/m/maeglin.o"));
    ExpectFalse(Wizard.hasWriteAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderIsNotOwnerOfFilesInMail()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/mail"));
    ExpectFalse(Wizard.hasOwnershipAccess("/mail/m/maeglin.o"));
    ExpectFalse(Wizard.hasOwnershipAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanReadFilesInBanish()
{
    ExpectTrue(Wizard.hasReadAccess("/banish"));
    ExpectTrue(Wizard.hasReadAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanWriteFilesInBanish()
{
    ExpectTrue(Wizard.hasWriteAccess("/banish"));
    ExpectTrue(Wizard.hasWriteAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderIsNotOwnerOfFilesInBanish()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/banish"));
    ExpectFalse(Wizard.hasOwnershipAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanNotReadFilesInGodstf()
{
    ExpectFalse(Wizard.hasReadAccess("/godstf"));
    ExpectFalse(Wizard.hasReadAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanNotWriteFilesInGodstf()
{
    ExpectFalse(Wizard.hasWriteAccess("/godstf"));
    ExpectFalse(Wizard.hasWriteAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderIsNotOwnerOfFilesInGodstf()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/godstf"));
    ExpectFalse(Wizard.hasOwnershipAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanReadFilesInRoom()
{
    ExpectTrue(Wizard.hasReadAccess("/room"));
    ExpectTrue(Wizard.hasReadAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanWriteFilesInRoom()
{
    ExpectTrue(Wizard.hasWriteAccess("/room"));
    ExpectTrue(Wizard.hasWriteAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderIsNotOwnerOfFilesInRoom()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/room"));
    ExpectFalse(Wizard.hasOwnershipAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanReadFilesInOpen()
{
    ExpectTrue(Wizard.hasReadAccess("/open"));
    ExpectTrue(Wizard.hasReadAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanWriteFilesInOpen()
{
    ExpectTrue(Wizard.hasWriteAccess("/open"));
    ExpectTrue(Wizard.hasWriteAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderIsNotOwnerOfFilesInOpen()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/open"));
    ExpectFalse(Wizard.hasOwnershipAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanReadFilesInGuild()
{
    ExpectTrue(Wizard.hasReadAccess("/guilds"));
    ExpectTrue(Wizard.hasReadAccess("/guilds/mage/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanWriteFilesInGuild()
{
    ExpectTrue(Wizard.hasWriteAccess("/guilds"));
    ExpectTrue(Wizard.hasWriteAccess("/guilds/priest/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderIsNotOwnerOfFilesInGuild()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/guilds"));
    ExpectFalse(Wizard.hasOwnershipAccess("/guilds/fighter/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanReadFilesInLib()
{
    ExpectTrue(Wizard.hasReadAccess("/lib"));
    ExpectTrue(Wizard.hasReadAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanNotWriteFilesInLib()
{
    ExpectFalse(Wizard.hasWriteAccess("/lib"));
    ExpectFalse(Wizard.hasWriteAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderIsNotOwnerOfFilesInLib()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/lib"));
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanNotReadFilesInLibSecure()
{
    ExpectFalse(Wizard.hasReadAccess("/lib/dictionaries/groups"));
    ExpectFalse(Wizard.hasReadAccess("/lib/tests/dictionaries/groups"));
    ExpectFalse(Wizard.hasReadAccess("/lib/dictionaries/groups/wizard.c"));
    ExpectFalse(Wizard.hasReadAccess("/lib/modules/secure/"));
    ExpectFalse(Wizard.hasReadAccess("/lib/tests/modules/secure/"));
    ExpectFalse(Wizard.hasReadAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanNotWriteFilesInLibSecure()
{
    ExpectFalse(Wizard.hasWriteAccess("/lib/dictionaries/groups"));
    ExpectFalse(Wizard.hasWriteAccess("/lib/tests/dictionaries/groups"));
    ExpectFalse(Wizard.hasWriteAccess("/lib/dictionaries/groups/wizard.c"));
    ExpectFalse(Wizard.hasWriteAccess("/lib/modules/secure/"));
    ExpectFalse(Wizard.hasWriteAccess("/lib/tests/modules/secure/"));
    ExpectFalse(Wizard.hasWriteAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderIsNotOwnerOfFilesInLibSecure()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/dictionaries/groups"));
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/tests/dictionaries/groups"));
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/dictionaries/groups/wizard.c"));
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/modules/secure/"));
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/tests/modules/secure/"));
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanReadFilesInPlayers()
{
    ExpectTrue(Wizard.hasReadAccess("/players"));
    ExpectTrue(Wizard.hasReadAccess("/players/maeglin/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanWriteFilesInPlayers()
{
    ExpectTrue(Wizard.hasWriteAccess("/players"));
    ExpectTrue(Wizard.hasWriteAccess("/players/sonja/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderIsNotOwnerOfFilesInPlayers()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/players"));
    ExpectFalse(Wizard.hasOwnershipAccess("/players/valren/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanReadTheirOwnFiles()
{
    ExpectTrue(Wizard.hasReadAccess("/players/earl"));
    ExpectTrue(Wizard.hasReadAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanWriteTheirOwnFiles()
{
    ExpectTrue(Wizard.hasWriteAccess("/players/earl"));
    ExpectTrue(Wizard.hasWriteAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderIsOwnerOfTheirOwnFiles()
{
    ExpectTrue(Wizard.hasOwnershipAccess("/players/earl"));
    ExpectTrue(Wizard.hasOwnershipAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanReadFilesInLog()
{
    ExpectTrue(Wizard.hasReadAccess("/log/EXPERIENCE"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanNotWriteFilesInLog()
{
    ExpectFalse(Wizard.hasWriteAccess("/log"));
    ExpectFalse(Wizard.hasWriteAccess("/log/EXPERIENCE"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderIsNotOwnerOfFilesInLog()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/log"));
    ExpectFalse(Wizard.hasOwnershipAccess("/log/EXPERIENCE"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanReadTheirLogs()
{
    ExpectTrue(Wizard.hasReadAccess("/log"));
    ExpectTrue(Wizard.hasReadAccess("/log/earl"));
    ExpectTrue(Wizard.hasReadAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanWriteTheirFilesInLog()
{
    ExpectTrue(Wizard.hasWriteAccess("/log/earl"));
    ExpectTrue(Wizard.hasWriteAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderIsOwnerOfTheirFilesInLog()
{
    ExpectTrue(Wizard.hasOwnershipAccess("/log/earl"));
    ExpectTrue(Wizard.hasOwnershipAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanNotReadOtherClosed()
{
    ExpectFalse(Wizard.hasReadAccess("/players/fred/closed"));
    ExpectFalse(Wizard.hasReadAccess("/players/fred/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderCanNotWriteOtherClosed()
{
    ExpectFalse(Wizard.hasWriteAccess("/players/fred/closed"));
    ExpectFalse(Wizard.hasWriteAccess("/players/fred/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ElderIsNotOwnerOfOtherClosed()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/players/fred/closed"));
    ExpectFalse(Wizard.hasOwnershipAccess("/players/fred/closed/blah.c"));
}
