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
    dataAccess.savePlayerData(database.GetWizardOfLevel("creator"));

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
void WizardCanReadFilesInRoot()
{
    ExpectTrue(Wizard.hasReadAccess("/ulmo.debug.log"));
    ExpectTrue(Wizard.hasReadAccess("/doc/regexp"));
    ExpectTrue(Wizard.hasReadAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanNotWriteFilesInRoot()
{
    ExpectFalse(Wizard.hasWriteAccess("/ulmo.debug.log"));
    ExpectFalse(Wizard.hasWriteAccess("/doc/regexp"));
    ExpectFalse(Wizard.hasWriteAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardIsNotOwnerOfFilesInRoot()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/ulmo.debug.log"));
    ExpectFalse(Wizard.hasOwnershipAccess("/doc/regexp"));
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanReadFilesInLog()
{
    ExpectTrue(Wizard.hasReadAccess("/log/EXPERIENCE"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanNotWriteFilesInLog()
{
    ExpectFalse(Wizard.hasWriteAccess("/log"));
    ExpectFalse(Wizard.hasWriteAccess("/log/EXPERIENCE"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardIsNotOwnerOfFilesInLog()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/log"));
    ExpectFalse(Wizard.hasOwnershipAccess("/log/EXPERIENCE"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanReadTheirLogs()
{
    ExpectTrue(Wizard.hasReadAccess("/log"));
    ExpectTrue(Wizard.hasReadAccess("/log/earl"));
    ExpectTrue(Wizard.hasReadAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanWriteTheirFilesInLog()
{
    ExpectTrue(Wizard.hasWriteAccess("/log/earl"));
    ExpectTrue(Wizard.hasWriteAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardIsOwnerOfTheirFilesInLog()
{
    ExpectTrue(Wizard.hasOwnershipAccess("/log/earl"));
    ExpectTrue(Wizard.hasOwnershipAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanNotReadFilesInSecure()
{
    ExpectFalse(Wizard.hasReadAccess("/secure"));
    ExpectFalse(Wizard.hasReadAccess("/secure/master.c"));
    ExpectFalse(Wizard.hasReadAccess("/secure/room/board.c"));
    ExpectFalse(Wizard.hasReadAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanNotWriteFilesInSecure()
{
    ExpectFalse(Wizard.hasWriteAccess("/secure"));
    ExpectFalse(Wizard.hasWriteAccess("/secure/master.c"));
    ExpectFalse(Wizard.hasWriteAccess("/secure/room/board.c"));
    ExpectFalse(Wizard.hasWriteAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardIsNotOwnerOfFilesInSecure()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/secure"));
    ExpectFalse(Wizard.hasOwnershipAccess("/secure/master.c"));
    ExpectFalse(Wizard.hasOwnershipAccess("/secure/room/board.c"));
    ExpectFalse(Wizard.hasOwnershipAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanNotReadFilesInMail()
{
    ExpectFalse(Wizard.hasReadAccess("/mail"));
    ExpectFalse(Wizard.hasReadAccess("/mail/m/maeglin.o"));
    ExpectFalse(Wizard.hasReadAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanNotWriteFilesInMail()
{
    ExpectFalse(Wizard.hasWriteAccess("/mail"));
    ExpectFalse(Wizard.hasWriteAccess("/mail/m/maeglin.o"));
    ExpectFalse(Wizard.hasWriteAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardIsNotOwnerOfFilesInMail()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/mail"));
    ExpectFalse(Wizard.hasOwnershipAccess("/mail/m/maeglin.o"));
    ExpectFalse(Wizard.hasOwnershipAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanNotReadFilesInBanish()
{
    ExpectFalse(Wizard.hasReadAccess("/banish"));
    ExpectFalse(Wizard.hasReadAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanNotWriteFilesInBanish()
{
    ExpectFalse(Wizard.hasWriteAccess("/banish"));
    ExpectFalse(Wizard.hasWriteAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardIsNotOwnerOfFilesInBanish()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/banish"));
    ExpectFalse(Wizard.hasOwnershipAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanNotReadFilesInGodstf()
{
    ExpectFalse(Wizard.hasReadAccess("/godstf"));
    ExpectFalse(Wizard.hasReadAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanNotWriteFilesInGodstf()
{
    ExpectFalse(Wizard.hasWriteAccess("/godstf"));
    ExpectFalse(Wizard.hasWriteAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardIsNotOwnerOfFilesInGodstf()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/godstf"));
    ExpectFalse(Wizard.hasOwnershipAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanReadFilesInRoom()
{
    ExpectTrue(Wizard.hasReadAccess("/room"));
    ExpectTrue(Wizard.hasReadAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanNotWriteFilesInRoom()
{
    ExpectFalse(Wizard.hasWriteAccess("/room"));
    ExpectFalse(Wizard.hasWriteAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardIsNotOwnerOfFilesInRoom()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/room"));
    ExpectFalse(Wizard.hasOwnershipAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanReadFilesInOpen()
{
    ExpectTrue(Wizard.hasReadAccess("/open"));
    ExpectTrue(Wizard.hasReadAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanWriteFilesInOpen()
{
    ExpectTrue(Wizard.hasWriteAccess("/open"));
    ExpectTrue(Wizard.hasWriteAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardIsNotOwnerOfFilesInOpen()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/open"));
    ExpectFalse(Wizard.hasOwnershipAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanReadFilesInGuild()
{
    ExpectTrue(Wizard.hasReadAccess("/guilds"));
    ExpectTrue(Wizard.hasReadAccess("/guilds/mage/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanNotWriteFilesInGuild()
{
    ExpectFalse(Wizard.hasWriteAccess("/guilds"));
    ExpectFalse(Wizard.hasWriteAccess("/guilds/priest/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardIsNotOwnerOfFilesInGuild()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/guilds"));
    ExpectFalse(Wizard.hasOwnershipAccess("/guilds/fighter/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanReadFilesInLib()
{
    ExpectTrue(Wizard.hasReadAccess("/lib"));
    ExpectTrue(Wizard.hasReadAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanNotWriteFilesInLib()
{
    ExpectFalse(Wizard.hasWriteAccess("/lib"));
    ExpectFalse(Wizard.hasWriteAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardIsNotOwnerOfFilesInLib()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/lib"));
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanNotReadFilesInLibSecure()
{
    ExpectFalse(Wizard.hasReadAccess("/lib/services/groups"));
    ExpectFalse(Wizard.hasReadAccess("/lib/tests/services/groups"));
    ExpectFalse(Wizard.hasReadAccess("/lib/services/groups/wizard.c"));
    ExpectFalse(Wizard.hasReadAccess("/lib/modules/secure/"));
    ExpectFalse(Wizard.hasReadAccess("/lib/tests/modules/secure/"));
    ExpectFalse(Wizard.hasReadAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanNotWriteFilesInLibSecure()
{
    ExpectFalse(Wizard.hasWriteAccess("/lib/services/groups"));
    ExpectFalse(Wizard.hasWriteAccess("/lib/tests/services/groups"));
    ExpectFalse(Wizard.hasWriteAccess("/lib/services/groups/wizard.c"));
    ExpectFalse(Wizard.hasWriteAccess("/lib/modules/secure/"));
    ExpectFalse(Wizard.hasWriteAccess("/lib/tests/modules/secure/"));
    ExpectFalse(Wizard.hasWriteAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardIsNotOwnerOfFilesInLibSecure()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/services/groups"));
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/tests/services/groups"));
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/services/groups/wizard.c"));
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/modules/secure/"));
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/tests/modules/secure/"));
    ExpectFalse(Wizard.hasOwnershipAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanReadFilesInPlayers()
{
    ExpectTrue(Wizard.hasReadAccess("/players"));
    ExpectTrue(Wizard.hasReadAccess("/players/maeglin/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanNotWriteFilesInPlayers()
{
    ExpectFalse(Wizard.hasWriteAccess("/players"));
    ExpectFalse(Wizard.hasWriteAccess("/players/sonja/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardIsNotOwnerOfFilesInPlayers()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/players"));
    ExpectFalse(Wizard.hasOwnershipAccess("/players/valren/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanReadTheirOwnFiles()
{
    ExpectTrue(Wizard.hasReadAccess("/players/earl"));
    ExpectTrue(Wizard.hasReadAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanWriteTheirOwnFiles()
{
    ExpectTrue(Wizard.hasWriteAccess("/players/earl"));
    ExpectTrue(Wizard.hasWriteAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardIsOwnerOfTheirOwnFiles()
{
    ExpectTrue(Wizard.hasOwnershipAccess("/players/earl"));
    ExpectTrue(Wizard.hasOwnershipAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanNotReadOtherClosed()
{
    ExpectFalse(Wizard.hasReadAccess("/players/fred/closed"));
    ExpectFalse(Wizard.hasReadAccess("/players/fred/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardCanNotWriteOtherClosed()
{
    ExpectFalse(Wizard.hasWriteAccess("/players/fred/closed"));
    ExpectFalse(Wizard.hasWriteAccess("/players/fred/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void WizardIsNotOwnerOfOtherClosed()
{
    ExpectFalse(Wizard.hasOwnershipAccess("/players/fred/closed"));
    ExpectFalse(Wizard.hasOwnershipAccess("/players/fred/closed/blah.c"));
}
