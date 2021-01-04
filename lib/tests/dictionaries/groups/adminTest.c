//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    dataAccess->savePlayerData(database->GetWizardOfLevel("admin"));

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
void AdminCanReadFilesInRoot()
{
    ExpectTrue(Wizard->hasReadAccess("/ulmo.debug.log"));
    ExpectTrue(Wizard->hasReadAccess("/doc/regexp"));
    ExpectTrue(Wizard->hasReadAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanNotWriteFilesInRoot()
{
    ExpectFalse(Wizard->hasWriteAccess("/ulmo.debug.log"));
    ExpectFalse(Wizard->hasWriteAccess("/doc/regexp"));
    ExpectFalse(Wizard->hasWriteAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminIsNotOwnerOfFilesInRoot()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/ulmo.debug.log"));
    ExpectFalse(Wizard->hasOwnershipAccess("/doc/regexp"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanNotReadFilesInSecure()
{
    ExpectFalse(Wizard->hasReadAccess("/secure"));
    ExpectFalse(Wizard->hasReadAccess("/secure/master.c"));
    ExpectFalse(Wizard->hasReadAccess("/secure/room/board.c"));
    ExpectFalse(Wizard->hasReadAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanNotWriteFilesInSecure()
{
    ExpectFalse(Wizard->hasWriteAccess("/secure"));
    ExpectFalse(Wizard->hasWriteAccess("/secure/master.c"));
    ExpectFalse(Wizard->hasWriteAccess("/secure/room/board.c"));
    ExpectFalse(Wizard->hasWriteAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminIsNotOwnerOfFilesInSecure()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/secure"));
    ExpectFalse(Wizard->hasOwnershipAccess("/secure/master.c"));
    ExpectFalse(Wizard->hasOwnershipAccess("/secure/room/board.c"));
    ExpectFalse(Wizard->hasOwnershipAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanNotReadFilesInMail()
{
    ExpectFalse(Wizard->hasReadAccess("/mail"));
    ExpectFalse(Wizard->hasReadAccess("/mail/m/maeglin.o"));
    ExpectFalse(Wizard->hasReadAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanNotWriteFilesInMail()
{
    ExpectFalse(Wizard->hasWriteAccess("/mail"));
    ExpectFalse(Wizard->hasWriteAccess("/mail/m/maeglin.o"));
    ExpectFalse(Wizard->hasWriteAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminIsNotOwnerOfFilesInMail()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/mail"));
    ExpectFalse(Wizard->hasOwnershipAccess("/mail/m/maeglin.o"));
    ExpectFalse(Wizard->hasOwnershipAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanNotReadFilesInBanish()
{
    ExpectFalse(Wizard->hasReadAccess("/banish"));
    ExpectFalse(Wizard->hasReadAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanNotWriteFilesInBanish()
{
    ExpectFalse(Wizard->hasWriteAccess("/banish"));
    ExpectFalse(Wizard->hasWriteAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminIsNotOwnerOfFilesInBanish()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/banish"));
    ExpectFalse(Wizard->hasOwnershipAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanNotReadFilesInGodstf()
{
    ExpectFalse(Wizard->hasReadAccess("/godstf"));
    ExpectFalse(Wizard->hasReadAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanNotWriteFilesInGodstf()
{
    ExpectFalse(Wizard->hasWriteAccess("/godstf"));
    ExpectFalse(Wizard->hasWriteAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminIsNotOwnerOfFilesInGodstf()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/godstf"));
    ExpectFalse(Wizard->hasOwnershipAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanReadFilesInRoom()
{
    ExpectTrue(Wizard->hasReadAccess("/room"));
    ExpectTrue(Wizard->hasReadAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanWriteFilesInRoom()
{
    ExpectTrue(Wizard->hasWriteAccess("/room"));
    ExpectTrue(Wizard->hasWriteAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminIsNotOwnerOfFilesInRoom()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/room"));
    ExpectFalse(Wizard->hasOwnershipAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanReadFilesInOpen()
{
    ExpectTrue(Wizard->hasReadAccess("/open"));
    ExpectTrue(Wizard->hasReadAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanWriteFilesInOpen()
{
    ExpectTrue(Wizard->hasWriteAccess("/open"));
    ExpectTrue(Wizard->hasWriteAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminIsNotOwnerOfFilesInOpen()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/open"));
    ExpectFalse(Wizard->hasOwnershipAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanReadFilesInGuild()
{
    ExpectTrue(Wizard->hasReadAccess("/guilds"));
    ExpectTrue(Wizard->hasReadAccess("/guilds/mage/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanWriteFilesInGuild()
{
    ExpectTrue(Wizard->hasWriteAccess("/guilds"));
    ExpectTrue(Wizard->hasWriteAccess("/guilds/priest/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminIsNotOwnerOfFilesInGuild()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/guilds"));
    ExpectFalse(Wizard->hasOwnershipAccess("/guilds/fighter/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanReadFilesInLib()
{
    ExpectTrue(Wizard->hasReadAccess("/lib"));
    ExpectTrue(Wizard->hasReadAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanNotWriteFilesInLib()
{
    ExpectFalse(Wizard->hasWriteAccess("/lib"));
    ExpectFalse(Wizard->hasWriteAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminIsNotOwnerOfFilesInLib()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/lib"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanNotReadFilesInLibSecure()
{
    ExpectFalse(Wizard->hasReadAccess("/lib/dictionaries/groups"));
    ExpectFalse(Wizard->hasReadAccess("/lib/tests/dictionaries/groups"));
    ExpectFalse(Wizard->hasReadAccess("/lib/dictionaries/groups/wizard.c"));
    ExpectFalse(Wizard->hasReadAccess("/lib/modules/secure/"));
    ExpectFalse(Wizard->hasReadAccess("/lib/tests/modules/secure/"));
    ExpectFalse(Wizard->hasReadAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanNotWriteFilesInLibSecure()
{
    ExpectFalse(Wizard->hasWriteAccess("/lib/dictionaries/groups"));
    ExpectFalse(Wizard->hasWriteAccess("/lib/tests/dictionaries/groups"));
    ExpectFalse(Wizard->hasWriteAccess("/lib/dictionaries/groups/wizard.c"));
    ExpectFalse(Wizard->hasWriteAccess("/lib/modules/secure/"));
    ExpectFalse(Wizard->hasWriteAccess("/lib/tests/modules/secure/"));
    ExpectFalse(Wizard->hasWriteAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminIsNotOwnerOfFilesInLibSecure()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/dictionaries/groups"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/tests/dictionaries/groups"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/dictionaries/groups/wizard.c"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/modules/secure/"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/tests/modules/secure/"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanReadFilesInPlayers()
{
    ExpectTrue(Wizard->hasReadAccess("/players"));
    ExpectTrue(Wizard->hasReadAccess("/players/maeglin/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanWriteFilesInPlayers()
{
    ExpectTrue(Wizard->hasWriteAccess("/players"));
    ExpectTrue(Wizard->hasWriteAccess("/players/sonja/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminIsNotOwnerOfFilesInPlayers()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/players"));
    ExpectFalse(Wizard->hasOwnershipAccess("/players/valren/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanReadTheirOwnFiles()
{
    ExpectTrue(Wizard->hasReadAccess("/players/earl"));
    ExpectTrue(Wizard->hasReadAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanWriteTheirOwnFiles()
{
    ExpectTrue(Wizard->hasWriteAccess("/players/earl"));
    ExpectTrue(Wizard->hasWriteAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminIsOwnerOfTheirOwnFiles()
{
    ExpectTrue(Wizard->hasOwnershipAccess("/players/earl"));
    ExpectTrue(Wizard->hasOwnershipAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanReadFilesInLog()
{
    ExpectTrue(Wizard->hasReadAccess("/log/EXPERIENCE"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanNotWriteFilesInLog()
{
    ExpectFalse(Wizard->hasWriteAccess("/log"));
    ExpectFalse(Wizard->hasWriteAccess("/log/EXPERIENCE"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminIsNotOwnerOfFilesInLog()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/log"));
    ExpectFalse(Wizard->hasOwnershipAccess("/log/EXPERIENCE"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanReadTheirLogs()
{
    ExpectTrue(Wizard->hasReadAccess("/log"));
    ExpectTrue(Wizard->hasReadAccess("/log/earl"));
    ExpectTrue(Wizard->hasReadAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanWriteTheirFilesInLog()
{
    ExpectTrue(Wizard->hasWriteAccess("/log/earl"));
    ExpectTrue(Wizard->hasWriteAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminIsOwnerOfTheirFilesInLog()
{
    ExpectTrue(Wizard->hasOwnershipAccess("/log/earl"));
    ExpectTrue(Wizard->hasOwnershipAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanNotReadOtherClosed()
{
    ExpectFalse(Wizard->hasReadAccess("/players/fred/closed"));
    ExpectFalse(Wizard->hasReadAccess("/players/fred/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminCanNotWriteOtherClosed()
{
    ExpectFalse(Wizard->hasWriteAccess("/players/fred/closed"));
    ExpectFalse(Wizard->hasWriteAccess("/players/fred/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AdminIsNotOwnerOfOtherClosed()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/players/fred/closed"));
    ExpectFalse(Wizard->hasOwnershipAccess("/players/fred/closed/blah.c"));
}
