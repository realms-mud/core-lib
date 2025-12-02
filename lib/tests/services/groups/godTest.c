//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    dataAccess.savePlayerData(database.GetWizardOfLevel("god"));

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
void GodCanReadFilesInRoot()
{
    ExpectTrue(Wizard.hasReadAccess("/ulmo.debug.log"));
    ExpectTrue(Wizard.hasReadAccess("/doc/regexp"));
    ExpectTrue(Wizard.hasReadAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanWriteFilesInRoot()
{
    ExpectTrue(Wizard.hasWriteAccess("/ulmo.debug.log"));
    ExpectTrue(Wizard.hasWriteAccess("/doc/regexp"));
    ExpectTrue(Wizard.hasWriteAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodIsNotOwnerOfFilesInRoot()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/ulmo.debug.log"));
    ExpectFalse(Wizard.hasOwnershipAccess("/doc/regexp"));
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanReadFilesInSecure()
{
    ExpectTrue(Wizard.hasReadAccess("/secure"));
    ExpectTrue(Wizard.hasReadAccess("/secure/master.c"));
    ExpectTrue(Wizard.hasReadAccess("/secure/room/board.c"));
    ExpectTrue(Wizard.hasReadAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanWriteFilesInSecure()
{
    ExpectTrue(Wizard.hasWriteAccess("/secure"));
    ExpectTrue(Wizard.hasWriteAccess("/secure/master.c"));
    ExpectTrue(Wizard.hasWriteAccess("/secure/room/board.c"));
    ExpectTrue(Wizard.hasWriteAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodIsNotOwnerOfFilesInSecure()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/secure"));
    ExpectFalse(Wizard.hasOwnershipAccess("/secure/master.c"));
    ExpectFalse(Wizard.hasOwnershipAccess("/secure/room/board.c"));
    ExpectFalse(Wizard.hasOwnershipAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanReadFilesInMail()
{
    ExpectTrue(Wizard.hasReadAccess("/mail"));
    ExpectTrue(Wizard.hasReadAccess("/mail/m/maeglin.o"));
    ExpectTrue(Wizard.hasReadAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanWriteFilesInMail()
{
    ExpectTrue(Wizard.hasWriteAccess("/mail"));
    ExpectTrue(Wizard.hasWriteAccess("/mail/m/maeglin.o"));
    ExpectTrue(Wizard.hasWriteAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void GodIsNotOwnerOfFilesInMail()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/mail"));
    ExpectFalse(Wizard.hasOwnershipAccess("/mail/m/maeglin.o"));
    ExpectFalse(Wizard.hasOwnershipAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanReadFilesInBanish()
{
    ExpectTrue(Wizard.hasReadAccess("/banish"));
    ExpectTrue(Wizard.hasReadAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanWriteFilesInBanish()
{
    ExpectTrue(Wizard.hasWriteAccess("/banish"));
    ExpectTrue(Wizard.hasWriteAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void GodIsNotOwnerOfFilesInBanish()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/banish"));
    ExpectFalse(Wizard.hasOwnershipAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanReadFilesInGodstf()
{
    ExpectTrue(Wizard.hasReadAccess("/godstf"));
    ExpectTrue(Wizard.hasReadAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanWriteFilesInGodstf()
{
    ExpectTrue(Wizard.hasWriteAccess("/godstf"));
    ExpectTrue(Wizard.hasWriteAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodIsNotOwnerOfFilesInGodstf()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/godstf"));
    ExpectFalse(Wizard.hasOwnershipAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanReadFilesInRoom()
{
    ExpectTrue(Wizard.hasReadAccess("/room"));
    ExpectTrue(Wizard.hasReadAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanWriteFilesInRoom()
{
    ExpectTrue(Wizard.hasWriteAccess("/room"));
    ExpectTrue(Wizard.hasWriteAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodIsNotOwnerOfFilesInRoom()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/room"));
    ExpectFalse(Wizard.hasOwnershipAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanReadFilesInOpen()
{
    ExpectTrue(Wizard.hasReadAccess("/open"));
    ExpectTrue(Wizard.hasReadAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanWriteFilesInOpen()
{
    ExpectTrue(Wizard.hasWriteAccess("/open"));
    ExpectTrue(Wizard.hasWriteAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodIsNotOwnerOfFilesInOpen()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/open"));
    ExpectFalse(Wizard.hasOwnershipAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanReadFilesInGuild()
{
    ExpectTrue(Wizard.hasReadAccess("/guilds"));
    ExpectTrue(Wizard.hasReadAccess("/guilds/mage/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanWriteFilesInGuild()
{
    ExpectTrue(Wizard.hasWriteAccess("/guilds"));
    ExpectTrue(Wizard.hasWriteAccess("/guilds/priest/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodIsNotOwnerOfFilesInGuild()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/guilds"));
    ExpectFalse(Wizard.hasOwnershipAccess("/guilds/fighter/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanReadFilesInLib()
{
    ExpectTrue(Wizard.hasReadAccess("/lib"));
    ExpectTrue(Wizard.hasReadAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanWriteFilesInLib()
{
    ExpectTrue(Wizard.hasWriteAccess("/lib"));
    ExpectTrue(Wizard.hasWriteAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodIsNotOwnerOfFilesInLib()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/lib"));
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanReadFilesInLibSecure()
{
    ExpectTrue(Wizard.hasReadAccess("/lib/services/groups"));
    ExpectTrue(Wizard.hasReadAccess("/lib/tests/services/groups"));
    ExpectTrue(Wizard.hasReadAccess("/lib/services/groups/wizard.c"));
    ExpectTrue(Wizard.hasReadAccess("/lib/modules/secure/"));
    ExpectTrue(Wizard.hasReadAccess("/lib/tests/modules/secure/"));
    ExpectTrue(Wizard.hasReadAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanWriteFilesInLibSecure()
{
    ExpectTrue(Wizard.hasWriteAccess("/lib/services/groups"));
    ExpectTrue(Wizard.hasWriteAccess("/lib/tests/services/groups"));
    ExpectTrue(Wizard.hasWriteAccess("/lib/services/groups/wizard.c"));
    ExpectTrue(Wizard.hasWriteAccess("/lib/modules/secure/"));
    ExpectTrue(Wizard.hasWriteAccess("/lib/tests/modules/secure/"));
    ExpectTrue(Wizard.hasWriteAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void GodIsNotOwnerOfFilesInLibSecure()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/services/groups"));
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/tests/services/groups"));
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/services/groups/wizard.c"));
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/modules/secure/"));
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/tests/modules/secure/"));
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanReadFilesInPlayers()
{
    ExpectTrue(Wizard.hasReadAccess("/players"));
    ExpectTrue(Wizard.hasReadAccess("/players/maeglin/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanWriteFilesInPlayers()
{
    ExpectTrue(Wizard.hasWriteAccess("/players"));
    ExpectTrue(Wizard.hasWriteAccess("/players/sonja/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodIsNotOwnerOfFilesInPlayers()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/players"));
    ExpectFalse(Wizard.hasOwnershipAccess("/players/valren/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanReadTheirOwnFiles()
{
    ExpectTrue(Wizard.hasReadAccess("/players/earl"));
    ExpectTrue(Wizard.hasReadAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanWriteTheirOwnFiles()
{
    ExpectTrue(Wizard.hasWriteAccess("/players/earl"));
    ExpectTrue(Wizard.hasWriteAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodIsOwnerOfTheirOwnFiles()
{
    ExpectTrue(Wizard.hasOwnershipAccess("/players/earl"));
    ExpectTrue(Wizard.hasOwnershipAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanReadFilesInLog()
{
    ExpectTrue(Wizard.hasReadAccess("/log/EXPERIENCE"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanWriteFilesInLog()
{
    ExpectTrue(Wizard.hasWriteAccess("/log"));
    ExpectTrue(Wizard.hasWriteAccess("/log/EXPERIENCE"));
}

/////////////////////////////////////////////////////////////////////////////
void GodIsNotOwnerOfFilesInLog()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/log"));
    ExpectFalse(Wizard.hasOwnershipAccess("/log/EXPERIENCE"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanReadTheirLogs()
{
    ExpectTrue(Wizard.hasReadAccess("/log"));
    ExpectTrue(Wizard.hasReadAccess("/log/earl"));
    ExpectTrue(Wizard.hasReadAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanWriteTheirFilesInLog()
{
    ExpectTrue(Wizard.hasWriteAccess("/log/earl"));
    ExpectTrue(Wizard.hasWriteAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void GodIsOwnerOfTheirFilesInLog()
{
    ExpectTrue(Wizard.hasOwnershipAccess("/log/earl"));
    ExpectTrue(Wizard.hasOwnershipAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanReadOtherClosed()
{
    ExpectTrue(Wizard.hasReadAccess("/players/fred/closed"));
    ExpectTrue(Wizard.hasReadAccess("/players/fred/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodCanWriteOtherClosed()
{
    ExpectTrue(Wizard.hasWriteAccess("/players/fred/closed"));
    ExpectTrue(Wizard.hasWriteAccess("/players/fred/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void GodIsNotOwnerOfOtherClosed()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/players/fred/closed"));
    ExpectFalse(Wizard.hasOwnershipAccess("/players/fred/closed/blah.c"));
}
