//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    dataAccess.savePlayerData(database.GetWizardOfLevel("apprentice"));

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
void ApprenticeCanReadFilesInRoot()
{
    ExpectTrue(Wizard.hasReadAccess("/ulmo.debug.log"));
    ExpectTrue(Wizard.hasReadAccess("/doc/regexp"));
    ExpectTrue(Wizard.hasReadAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CanReadPlans()
{
    ExpectTrue(Wizard.hasReadAccess("/players/maeglin/.plan"));
    ExpectTrue(Wizard.hasReadAccess("/players/weasel/.plan"));
    ExpectTrue(Wizard.hasReadAccess("/players/earl/.plan"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotWriteFilesInRoot()
{
    ExpectFalse(Wizard.hasWriteAccess("/ulmo.debug.log"));
    ExpectFalse(Wizard.hasWriteAccess("/doc/regexp"));
    ExpectFalse(Wizard.hasWriteAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeIsNotOwnerOfFilesInRoot()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/ulmo.debug.log"));
    ExpectFalse(Wizard.hasOwnershipAccess("/doc/regexp"));
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotReadFilesInLog()
{
    ExpectFalse(Wizard.hasReadAccess("/log/EXPERIENCE"));
    ExpectFalse(Wizard.hasReadAccess("/log/earl"));
    ExpectFalse(Wizard.hasReadAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotWriteFilesInLog()
{
    ExpectFalse(Wizard.hasWriteAccess("/log/EXPERIENCE"));
    ExpectFalse(Wizard.hasWriteAccess("/log/earl"));
    ExpectFalse(Wizard.hasWriteAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeIsNotOwnerOfFilesInLog()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/log/EXPERIENCE"));
    ExpectFalse(Wizard.hasOwnershipAccess("/log/earl"));
    ExpectFalse(Wizard.hasOwnershipAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotReadFilesInSecure()
{
    ExpectFalse(Wizard.hasReadAccess("/secure"));
    ExpectFalse(Wizard.hasReadAccess("/secure/master.c"));
    ExpectFalse(Wizard.hasReadAccess("/secure/room/board.c"));
    ExpectFalse(Wizard.hasReadAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotWriteFilesInSecure()
{
    ExpectFalse(Wizard.hasWriteAccess("/secure"));
    ExpectFalse(Wizard.hasWriteAccess("/secure/master.c"));
    ExpectFalse(Wizard.hasWriteAccess("/secure/room/board.c"));
    ExpectFalse(Wizard.hasWriteAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeIsNotOwnerOfFilesInSecure()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/secure"));
    ExpectFalse(Wizard.hasOwnershipAccess("/secure/master.c"));
    ExpectFalse(Wizard.hasOwnershipAccess("/secure/room/board.c"));
    ExpectFalse(Wizard.hasOwnershipAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotReadFilesInMail()
{
    ExpectFalse(Wizard.hasReadAccess("/mail"));
    ExpectFalse(Wizard.hasReadAccess("/mail/m/maeglin.o"));
    ExpectFalse(Wizard.hasReadAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotWriteFilesInMail()
{
    ExpectFalse(Wizard.hasWriteAccess("/mail"));
    ExpectFalse(Wizard.hasWriteAccess("/mail/m/maeglin.o"));
    ExpectFalse(Wizard.hasWriteAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeIsNotOwnerOfFilesInMail()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/mail"));
    ExpectFalse(Wizard.hasOwnershipAccess("/mail/m/maeglin.o"));
    ExpectFalse(Wizard.hasOwnershipAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotReadFilesInBanish()
{
    ExpectFalse(Wizard.hasReadAccess("/banish"));
    ExpectFalse(Wizard.hasReadAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotWriteFilesInBanish()
{
    ExpectFalse(Wizard.hasWriteAccess("/banish"));
    ExpectFalse(Wizard.hasWriteAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeIsNotOwnerOfFilesInBanish()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/banish"));
    ExpectFalse(Wizard.hasOwnershipAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotReadFilesInGodstf()
{
    ExpectFalse(Wizard.hasReadAccess("/godstf"));
    ExpectFalse(Wizard.hasReadAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotWriteFilesInGodstf()
{
    ExpectFalse(Wizard.hasWriteAccess("/godstf"));
    ExpectFalse(Wizard.hasWriteAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeIsNotOwnerOfFilesInGodstf()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/godstf"));
    ExpectFalse(Wizard.hasOwnershipAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanReadFilesInRoom()
{
    ExpectTrue(Wizard.hasReadAccess("/room"));
    ExpectTrue(Wizard.hasReadAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotWriteFilesInRoom()
{
    ExpectFalse(Wizard.hasWriteAccess("/room"));
    ExpectFalse(Wizard.hasWriteAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeIsNotOwnerOfFilesInRoom()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/room"));
    ExpectFalse(Wizard.hasOwnershipAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanReadFilesInOpen()
{
    ExpectTrue(Wizard.hasReadAccess("/open"));
    ExpectTrue(Wizard.hasReadAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotWriteFilesInOpen()
{
    ExpectFalse(Wizard.hasWriteAccess("/open"));
    ExpectFalse(Wizard.hasWriteAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeIsNotOwnerOfFilesInOpen()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/open"));
    ExpectFalse(Wizard.hasOwnershipAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotReadFilesInGuild()
{
    ExpectFalse(Wizard.hasReadAccess("/guilds"));
    ExpectFalse(Wizard.hasReadAccess("/guilds/mage/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotWriteFilesInGuild()
{
    ExpectFalse(Wizard.hasWriteAccess("/guilds"));
    ExpectFalse(Wizard.hasWriteAccess("/guilds/priest/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeIsNotOwnerOfFilesInGuild()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/guilds"));
    ExpectFalse(Wizard.hasOwnershipAccess("/guilds/fighter/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanReadFilesInLib()
{
    ExpectTrue(Wizard.hasReadAccess("/lib"));
    ExpectTrue(Wizard.hasReadAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotWriteFilesInLib()
{
    ExpectFalse(Wizard.hasWriteAccess("/lib"));
    ExpectFalse(Wizard.hasWriteAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeIsNotOwnerOfFilesInLib()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/lib"));
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotReadFilesInLibSecure()
{
    ExpectFalse(Wizard.hasReadAccess("/lib/dictionaries/groups"));
    ExpectFalse(Wizard.hasReadAccess("/lib/tests/dictionaries/groups"));
    ExpectFalse(Wizard.hasReadAccess("/lib/dictionaries/groups/wizard.c"));
    ExpectFalse(Wizard.hasReadAccess("/lib/modules/secure/"));
    ExpectFalse(Wizard.hasReadAccess("/lib/tests/modules/secure/"));
    ExpectFalse(Wizard.hasReadAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotWriteFilesInLibSecure()
{
    ExpectFalse(Wizard.hasWriteAccess("/lib/dictionaries/groups"));
    ExpectFalse(Wizard.hasWriteAccess("/lib/tests/dictionaries/groups"));
    ExpectFalse(Wizard.hasWriteAccess("/lib/dictionaries/groups/wizard.c"));
    ExpectFalse(Wizard.hasWriteAccess("/lib/modules/secure/"));
    ExpectFalse(Wizard.hasWriteAccess("/lib/tests/modules/secure/"));
    ExpectFalse(Wizard.hasWriteAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeIsNotOwnerOfFilesInLibSecure()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/dictionaries/groups"));
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/tests/dictionaries/groups"));
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/dictionaries/groups/wizard.c"));
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/modules/secure/"));
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/tests/modules/secure/"));
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotReadFilesInPlayers()
{
    ExpectFalse(Wizard.hasReadAccess("/players"));
    ExpectFalse(Wizard.hasReadAccess("/players/maeglin/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotWriteFilesInPlayers()
{
    ExpectFalse(Wizard.hasWriteAccess("/players"));
    ExpectFalse(Wizard.hasWriteAccess("/players/sonja/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeIsNotOwnerOfFilesInPlayers()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/players"));
    ExpectFalse(Wizard.hasOwnershipAccess("/players/valren/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanReadTheirOwnFiles()
{
    ExpectTrue(Wizard.hasReadAccess("/players/earl"));
    ExpectTrue(Wizard.hasReadAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanWriteTheirOwnFiles()
{
    ExpectTrue(Wizard.hasWriteAccess("/players/earl"));
    ExpectTrue(Wizard.hasWriteAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeIsOwnerOfTheirOwnFiles()
{
    ExpectTrue(Wizard.hasOwnershipAccess("/players/earl"));
    ExpectTrue(Wizard.hasOwnershipAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotReadOtherClosed()
{
    ExpectFalse(Wizard.hasReadAccess("/players/fred/closed"));
    ExpectFalse(Wizard.hasReadAccess("/players/fred/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotWriteOtherClosed()
{
    ExpectFalse(Wizard.hasWriteAccess("/players/fred/closed"));
    ExpectFalse(Wizard.hasWriteAccess("/players/fred/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeIsNotOwnerOfOtherClosed()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/players/fred/closed"));
    ExpectFalse(Wizard.hasOwnershipAccess("/players/fred/closed/blah.c"));
}
