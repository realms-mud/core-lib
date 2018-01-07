//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;

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

    // Yes, yes, I know... this makes me a bad person. Still, the intent -
    // testing player permissions is correct. What this does not test is
    // that the valid check stuff goes to this group by default.
    dataAccess->savePlayerData(database->GetWizardOfLevel("player"));

    destruct(dataAccess);
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/realizations/wizard.c");
    Player->restore("earl");
    setUsers(({ Player }));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanNotReadFilesInRoot()
{
    ExpectFalse(Player->hasReadAccess("/ulmo.debug.log"));
    ExpectTrue(Player->hasReadAccess("/doc/regexp"));
    ExpectFalse(Player->hasReadAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanReadPlans()
{
    ExpectTrue(Player->hasReadAccess("/players/maeglin/.plan"));
    ExpectTrue(Player->hasReadAccess("/players/weasel/.plan"));
    ExpectTrue(Player->hasReadAccess("/players/earl/.plan"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanNotWriteFilesInRoot()
{
    ExpectFalse(Player->hasWriteAccess("/ulmo.debug.log"));
    ExpectFalse(Player->hasWriteAccess("/doc/regexp"));
    ExpectFalse(Player->hasWriteAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerIsNotOwnerOfFilesInRoot()
{
    ExpectFalse(Player->hasOwnershipAccess("/ulmo.debug.log"));
    ExpectFalse(Player->hasOwnershipAccess("/doc/regexp"));
    ExpectFalse(Player->hasOwnershipAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanNotReadFilesInLog()
{
    ExpectFalse(Player->hasReadAccess("/log/EXPERIENCE"));
    ExpectFalse(Player->hasReadAccess("/log/earl"));
    ExpectFalse(Player->hasReadAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanNotWriteFilesInLog()
{
    ExpectFalse(Player->hasWriteAccess("/log/EXPERIENCE"));
    ExpectFalse(Player->hasWriteAccess("/log/earl"));
    ExpectFalse(Player->hasWriteAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerIsNotOwnerOfFilesInLog()
{
    ExpectFalse(Player->hasOwnershipAccess("/log/EXPERIENCE"));
    ExpectFalse(Player->hasOwnershipAccess("/log/earl"));
    ExpectFalse(Player->hasOwnershipAccess("/log/earl.rep"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanNotReadFilesInSecure()
{
    ExpectFalse(Player->hasReadAccess("/secure"));
    ExpectFalse(Player->hasReadAccess("/secure/master.c"));
    ExpectFalse(Player->hasReadAccess("/secure/room/board.c"));
    ExpectFalse(Player->hasReadAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanNotWriteFilesInSecure()
{
    ExpectFalse(Player->hasWriteAccess("/secure"));
    ExpectFalse(Player->hasWriteAccess("/secure/master.c"));
    ExpectFalse(Player->hasWriteAccess("/secure/room/board.c"));
    ExpectFalse(Player->hasWriteAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerIsNotOwnerOfFilesInSecure()
{
    ExpectFalse(Player->hasOwnershipAccess("/secure"));
    ExpectFalse(Player->hasOwnershipAccess("/secure/master.c"));
    ExpectFalse(Player->hasOwnershipAccess("/secure/room/board.c"));
    ExpectFalse(Player->hasOwnershipAccess("/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanNotReadFilesInMail()
{
    ExpectFalse(Player->hasReadAccess("/mail"));
    ExpectFalse(Player->hasReadAccess("/mail/m/maeglin.o"));
    ExpectFalse(Player->hasReadAccess("/mail/b/blah.o"));
    ExpectTrue(Player->hasReadAccess("/mail/e/earl.o"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanNotWriteFilesInMail()
{
    ExpectFalse(Player->hasWriteAccess("/mail"));
    ExpectFalse(Player->hasWriteAccess("/mail/m/maeglin.o"));
    ExpectFalse(Player->hasWriteAccess("/mail/b/blah.o"));
    ExpectTrue(Player->hasWriteAccess("/mail/e/earl.o"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerIsNotOwnerOfFilesInMail()
{
    ExpectFalse(Player->hasOwnershipAccess("/mail"));
    ExpectFalse(Player->hasOwnershipAccess("/mail/m/maeglin.o"));
    ExpectFalse(Player->hasOwnershipAccess("/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanNotReadFilesInBanish()
{
    ExpectFalse(Player->hasReadAccess("/banish"));
    ExpectFalse(Player->hasReadAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanNotWriteFilesInBanish()
{
    ExpectFalse(Player->hasWriteAccess("/banish"));
    ExpectFalse(Player->hasWriteAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerIsNotOwnerOfFilesInBanish()
{
    ExpectFalse(Player->hasOwnershipAccess("/banish"));
    ExpectFalse(Player->hasOwnershipAccess("/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanNotReadFilesInGodstf()
{
    ExpectFalse(Player->hasReadAccess("/godstf"));
    ExpectFalse(Player->hasReadAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanNotWriteFilesInGodstf()
{
    ExpectFalse(Player->hasWriteAccess("/godstf"));
    ExpectFalse(Player->hasWriteAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerIsNotOwnerOfFilesInGodstf()
{
    ExpectFalse(Player->hasOwnershipAccess("/godstf"));
    ExpectFalse(Player->hasOwnershipAccess("/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanNotReadFilesInRoom()
{
    ExpectFalse(Player->hasReadAccess("/room"));
    ExpectFalse(Player->hasReadAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanNotWriteFilesInRoom()
{
    ExpectFalse(Player->hasWriteAccess("/room"));
    ExpectFalse(Player->hasWriteAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerIsNotOwnerOfFilesInRoom()
{
    ExpectFalse(Player->hasOwnershipAccess("/room"));
    ExpectFalse(Player->hasOwnershipAccess("/room/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanNotReadFilesInOpen()
{
    ExpectFalse(Player->hasReadAccess("/open"));
    ExpectFalse(Player->hasReadAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanNotWriteFilesInOpen()
{
    ExpectFalse(Player->hasWriteAccess("/open"));
    ExpectFalse(Player->hasWriteAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerIsNotOwnerOfFilesInOpen()
{
    ExpectFalse(Player->hasOwnershipAccess("/open"));
    ExpectFalse(Player->hasOwnershipAccess("/open/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanNotReadFilesInGuild()
{
    ExpectFalse(Player->hasReadAccess("/guild"));
    ExpectFalse(Player->hasReadAccess("/guild/mage/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanNotWriteFilesInGuild()
{
    ExpectFalse(Player->hasWriteAccess("/guild"));
    ExpectFalse(Player->hasWriteAccess("/guild/priest/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerIsNotOwnerOfFilesInGuild()
{
    ExpectFalse(Player->hasOwnershipAccess("/guild"));
    ExpectFalse(Player->hasOwnershipAccess("/guild/fighter/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanNotReadFilesInLib()
{
    ExpectFalse(Player->hasReadAccess("/lib"));
    ExpectFalse(Player->hasReadAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanNotWriteFilesInLib()
{
    ExpectFalse(Player->hasWriteAccess("/lib"));
    ExpectFalse(Player->hasWriteAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerIsNotOwnerOfFilesInLib()
{
    ExpectFalse(Player->hasOwnershipAccess("/lib"));
    ExpectFalse(Player->hasOwnershipAccess("/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanNotReadFilesInLibSecure()
{
    ExpectFalse(Player->hasReadAccess("/lib/dictionaries/groups"));
    ExpectFalse(Player->hasReadAccess("/lib/tests/dictionaries/groups"));
    ExpectFalse(Player->hasReadAccess("/lib/dictionaries/groups/wizard.c"));
    ExpectFalse(Player->hasReadAccess("/lib/modules/secure/"));
    ExpectFalse(Player->hasReadAccess("/lib/tests/modules/secure/"));
    ExpectFalse(Player->hasReadAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanNotWriteFilesInLibSecure()
{
    ExpectFalse(Player->hasWriteAccess("/lib/dictionaries/groups"));
    ExpectFalse(Player->hasWriteAccess("/lib/tests/dictionaries/groups"));
    ExpectFalse(Player->hasWriteAccess("/lib/dictionaries/groups/wizard.c"));
    ExpectFalse(Player->hasWriteAccess("/lib/modules/secure/"));
    ExpectFalse(Player->hasWriteAccess("/lib/tests/modules/secure/"));
    ExpectFalse(Player->hasWriteAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerIsNotOwnerOfFilesInLibSecure()
{
    ExpectFalse(Player->hasOwnershipAccess("/lib/dictionaries/groups"));
    ExpectFalse(Player->hasOwnershipAccess("/lib/tests/dictionaries/groups"));
    ExpectFalse(Player->hasOwnershipAccess("/lib/dictionaries/groups/wizard.c"));
    ExpectFalse(Player->hasOwnershipAccess("/lib/modules/secure/"));
    ExpectFalse(Player->hasOwnershipAccess("/lib/tests/modules/secure/"));
    ExpectFalse(Player->hasOwnershipAccess("/lib/modules/secure/combat.h"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanNotReadFilesInPlayers()
{
    ExpectFalse(Player->hasReadAccess("/players"));
    ExpectFalse(Player->hasReadAccess("/players/maeglin/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanNotWriteFilesInPlayers()
{
    ExpectFalse(Player->hasWriteAccess("/players"));
    ExpectFalse(Player->hasWriteAccess("/players/sonja/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerIsNotOwnerOfFilesInPlayers()
{
    ExpectFalse(Player->hasOwnershipAccess("/players"));
    ExpectFalse(Player->hasOwnershipAccess("/players/valren/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanNotReadTheirOwnFiles()
{
    ExpectFalse(Player->hasReadAccess("/players/earl"));
    ExpectFalse(Player->hasReadAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanWriteTheirOwnFiles()
{
    ExpectFalse(Player->hasWriteAccess("/players/earl"));
    ExpectFalse(Player->hasWriteAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerIsOwnerOfTheirOwnFiles()
{
    ExpectFalse(Player->hasOwnershipAccess("/players/earl"));
    ExpectFalse(Player->hasOwnershipAccess("/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanNotReadOtherClosed()
{
    ExpectFalse(Player->hasReadAccess("/players/fred/closed"));
    ExpectFalse(Player->hasReadAccess("/players/fred/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanNotWriteOtherClosed()
{
    ExpectFalse(Player->hasWriteAccess("/players/fred/closed"));
    ExpectFalse(Player->hasWriteAccess("/players/fred/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerIsNotOwnerOfOtherClosed()
{
    ExpectFalse(Player->hasOwnershipAccess("/players/fred/closed"));
    ExpectFalse(Player->hasOwnershipAccess("/players/fred/closed/blah.c"));
}