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
    dataAccess->savePlayerData(database->GetWizardOfLevel("sage"));

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
void SageCanReadFilesInRoot()
{
    ExpectTrue(Wizard->hasReadAccess("/ulmo.debug.log"));
    ExpectTrue(Wizard->hasReadAccess("/doc/regexp"));
    ExpectTrue(Wizard->hasReadAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanWriteFilesInRoot()
{
    ExpectTrue(Wizard->hasWriteAccess("/ulmo.debug.log"));
    ExpectTrue(Wizard->hasWriteAccess("/doc/regexp"));
    ExpectFalse(Wizard->hasWriteAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageIsNotOwnerOfFilesInRoot()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/ulmo.debug.log"));
    ExpectFalse(Wizard->hasOwnershipAccess("/doc/regexp"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanNotReadFilesInSecure()
{
    ExpectFalse(Wizard->hasReadAccess("/secure"));
    ExpectFalse(Wizard->hasReadAccess("/secure/master.c"));
    ExpectFalse(Wizard->hasReadAccess("/secure/room/board.c"));
    ExpectFalse(Wizard->hasReadAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanNotWriteFilesInSecure()
{
    ExpectFalse(Wizard->hasWriteAccess("/secure"));
    ExpectFalse(Wizard->hasWriteAccess("/secure/master.c"));
    ExpectFalse(Wizard->hasWriteAccess("/secure/room/board.c"));
    ExpectFalse(Wizard->hasWriteAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageIsNotOwnerOfFilesInSecure()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/secure"));
    ExpectFalse(Wizard->hasOwnershipAccess("/secure/master.c"));
    ExpectFalse(Wizard->hasOwnershipAccess("/secure/room/board.c"));
    ExpectFalse(Wizard->hasOwnershipAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanReadFilesInMail()
{
    ExpectTrue(Wizard->hasReadAccess("/mail"));
    ExpectTrue(Wizard->hasReadAccess("/mail/m/maeglin.o"));
    ExpectTrue(Wizard->hasReadAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanWriteFilesInMail()
{
    ExpectTrue(Wizard->hasWriteAccess("/mail"));
    ExpectTrue(Wizard->hasWriteAccess("/mail/m/maeglin.o"));
    ExpectTrue(Wizard->hasWriteAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void SageIsNotOwnerOfFilesInMail()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/mail"));
    ExpectFalse(Wizard->hasOwnershipAccess("/mail/m/maeglin.o"));
    ExpectFalse(Wizard->hasOwnershipAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanReadFilesInBanish()
{
    ExpectTrue(Wizard->hasReadAccess("/banish"));
    ExpectTrue(Wizard->hasReadAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanWriteFilesInBanish()
{
    ExpectTrue(Wizard->hasWriteAccess("/banish"));
    ExpectTrue(Wizard->hasWriteAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void SageIsNotOwnerOfFilesInBanish()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/banish"));
    ExpectFalse(Wizard->hasOwnershipAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanNotReadFilesInGodstf()
{
    ExpectFalse(Wizard->hasReadAccess("/godstf"));
    ExpectFalse(Wizard->hasReadAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanNotWriteFilesInGodstf()
{
    ExpectFalse(Wizard->hasWriteAccess("/godstf"));
    ExpectFalse(Wizard->hasWriteAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageIsNotOwnerOfFilesInGodstf()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/godstf"));
    ExpectFalse(Wizard->hasOwnershipAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanReadFilesInRoom()
{
    ExpectTrue(Wizard->hasReadAccess("/room"));
    ExpectTrue(Wizard->hasReadAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanWriteFilesInRoom()
{
    ExpectTrue(Wizard->hasWriteAccess("/room"));
    ExpectTrue(Wizard->hasWriteAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageIsNotOwnerOfFilesInRoom()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/room"));
    ExpectFalse(Wizard->hasOwnershipAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanReadFilesInOpen()
{
    ExpectTrue(Wizard->hasReadAccess("/open"));
    ExpectTrue(Wizard->hasReadAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanWriteFilesInOpen()
{
    ExpectTrue(Wizard->hasWriteAccess("/open"));
    ExpectTrue(Wizard->hasWriteAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageIsNotOwnerOfFilesInOpen()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/open"));
    ExpectFalse(Wizard->hasOwnershipAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanReadFilesInGuild()
{
    ExpectTrue(Wizard->hasReadAccess("/guild"));
    ExpectTrue(Wizard->hasReadAccess("/guild/mage/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanWriteFilesInGuild()
{
    ExpectTrue(Wizard->hasWriteAccess("/guild"));
    ExpectTrue(Wizard->hasWriteAccess("/guild/priest/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageIsNotOwnerOfFilesInGuild()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/guild"));
    ExpectFalse(Wizard->hasOwnershipAccess("/guild/fighter/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanReadFilesInLib()
{
    ExpectTrue(Wizard->hasReadAccess("/lib"));
    ExpectTrue(Wizard->hasReadAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanNotWriteFilesInLib()
{
    ExpectFalse(Wizard->hasWriteAccess("/lib"));
    ExpectFalse(Wizard->hasWriteAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageIsNotOwnerOfFilesInLib()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/lib"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanNotReadFilesInLibSecure()
{
    ExpectFalse(Wizard->hasReadAccess("/lib/dictionaries/groups"));
    ExpectFalse(Wizard->hasReadAccess("/lib/tests/dictionaries/groups"));
    ExpectFalse(Wizard->hasReadAccess("/lib/dictionaries/groups/wizard.c"));
    ExpectFalse(Wizard->hasReadAccess("/lib/modules/secure/"));
    ExpectFalse(Wizard->hasReadAccess("/lib/tests/modules/secure/"));
    ExpectFalse(Wizard->hasReadAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanNotWriteFilesInLibSecure()
{
    ExpectFalse(Wizard->hasWriteAccess("/lib/dictionaries/groups"));
    ExpectFalse(Wizard->hasWriteAccess("/lib/tests/dictionaries/groups"));
    ExpectFalse(Wizard->hasWriteAccess("/lib/dictionaries/groups/wizard.c"));
    ExpectFalse(Wizard->hasWriteAccess("/lib/modules/secure/"));
    ExpectFalse(Wizard->hasWriteAccess("/lib/tests/modules/secure/"));
    ExpectFalse(Wizard->hasWriteAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void SageIsNotOwnerOfFilesInLibSecure()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/dictionaries/groups"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/tests/dictionaries/groups"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/dictionaries/groups/wizard.c"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/modules/secure/"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/tests/modules/secure/"));
    ExpectFalse(Wizard->hasOwnershipAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanReadFilesInPlayers()
{
    ExpectTrue(Wizard->hasReadAccess("/players"));
    ExpectTrue(Wizard->hasReadAccess("/players/maeglin/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanWriteFilesInPlayers()
{
    ExpectTrue(Wizard->hasWriteAccess("/players"));
    ExpectTrue(Wizard->hasWriteAccess("/players/sonja/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageIsNotOwnerOfFilesInPlayers()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/players"));
    ExpectFalse(Wizard->hasOwnershipAccess("/players/valren/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanReadTheirOwnFiles()
{
    ExpectTrue(Wizard->hasReadAccess("/players/earl"));
    ExpectTrue(Wizard->hasReadAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanWriteTheirOwnFiles()
{
    ExpectTrue(Wizard->hasWriteAccess("/players/earl"));
    ExpectTrue(Wizard->hasWriteAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageIsOwnerOfTheirOwnFiles()
{
    ExpectTrue(Wizard->hasOwnershipAccess("/players/earl"));
    ExpectTrue(Wizard->hasOwnershipAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanReadFilesInLog()
{
    ExpectTrue(Wizard->hasReadAccess("/log/EXPERIENCE"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanNotWriteFilesInLog()
{
    ExpectFalse(Wizard->hasWriteAccess("/log"));
    ExpectFalse(Wizard->hasWriteAccess("/log/EXPERIENCE"));
}

/////////////////////////////////////////////////////////////////////////////
void SageIsNotOwnerOfFilesInLog()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/log"));
    ExpectFalse(Wizard->hasOwnershipAccess("/log/EXPERIENCE"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanReadTheirLogs()
{
    ExpectTrue(Wizard->hasReadAccess("/log"));
    ExpectTrue(Wizard->hasReadAccess("/log/earl"));
    ExpectTrue(Wizard->hasReadAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanWriteTheirFilesInLog()
{
    ExpectTrue(Wizard->hasWriteAccess("/log/earl"));
    ExpectTrue(Wizard->hasWriteAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void SageIsOwnerOfTheirFilesInLog()
{
    ExpectTrue(Wizard->hasOwnershipAccess("/log/earl"));
    ExpectTrue(Wizard->hasOwnershipAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanReadOtherClosed()
{
    ExpectTrue(Wizard->hasReadAccess("/players/fred/closed"));
    ExpectTrue(Wizard->hasReadAccess("/players/fred/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageCanNotWriteOtherClosed()
{
    ExpectFalse(Wizard->hasWriteAccess("/players/fred/closed"));
    ExpectFalse(Wizard->hasWriteAccess("/players/fred/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SageIsNotOwnerOfOtherClosed()
{
    ExpectFalse(Wizard->hasOwnershipAccess("/players/fred/closed"));
    ExpectFalse(Wizard->hasOwnershipAccess("/players/fred/closed/blah.c"));
}
