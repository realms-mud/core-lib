//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Group;
object Wizard;

protected nosave int Unknown = 0x8;
protected nosave int None = 0x0;
protected nosave int Owner = 0x1;
protected nosave int Write = 0x2;
protected nosave int Read = 0x4;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Group = clone_object("/lib/dictionaries/groups/apprentice.c");
    Group->init();

    Wizard = clone_object("/lib/realizations/wizard.c");
    Wizard->Name("Earl");
    setUsers(({ Wizard }));

    setCustomGroups(({ Group->group() }));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Wizard);
    destruct(Group);
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanReadFilesInRoot()
{
    ExpectTrue(Group->hasReadAccess(Wizard, "/ulmo.debug.log"));
    ExpectTrue(Group->hasReadAccess(Wizard, "/doc/regexp"));
    ExpectTrue(Group->hasReadAccess(Wizard, "/open/example.c"));
    ExpectTrue(Group->hasReadAccess(Wizard, "/room/room.c"));
    ExpectTrue(Group->hasReadAccess(Wizard, "/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotWriteFilesInRoot()
{
    ExpectFalse(Group->hasWriteAccess(Wizard, "/ulmo.debug.log"));
    ExpectFalse(Group->hasWriteAccess(Wizard, "/doc/regexp"));
    ExpectFalse(Group->hasWriteAccess(Wizard, "/open/example.c"));
    ExpectFalse(Group->hasWriteAccess(Wizard, "/room/room.c"));
    ExpectFalse(Group->hasWriteAccess(Wizard, "/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeIsNotOwnerOfFilesInRoot()
{
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/ulmo.debug.log"));
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/doc/regexp"));
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/open/example.c"));
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/room/room.c"));
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotReadFilesInSecure()
{
    ExpectFalse(Group->hasReadAccess(Wizard, "/secure"));
    ExpectFalse(Group->hasReadAccess(Wizard, "/secure/master.c"));
    ExpectFalse(Group->hasReadAccess(Wizard, "/secure/room/board.c"));
    ExpectFalse(Group->hasReadAccess(Wizard, "/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotWriteFilesInSecure()
{
    ExpectFalse(Group->hasWriteAccess(Wizard, "/secure"));
    ExpectFalse(Group->hasWriteAccess(Wizard, "/secure/master.c"));
    ExpectFalse(Group->hasWriteAccess(Wizard, "/secure/room/board.c"));
    ExpectFalse(Group->hasWriteAccess(Wizard, "/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeIsNotOwnerOfFilesInSecure()
{
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/secure"));
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/secure/master.c"));
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/secure/room/board.c"));
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotReadFilesInMail()
{
    ExpectFalse(Group->hasReadAccess(Wizard, "/mail"));
    ExpectFalse(Group->hasReadAccess(Wizard, "/mail/m/maeglin.o"));
    ExpectFalse(Group->hasReadAccess(Wizard, "/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotWriteFilesInMail()
{
    ExpectFalse(Group->hasWriteAccess(Wizard, "/mail"));
    ExpectFalse(Group->hasWriteAccess(Wizard, "/mail/m/maeglin.o"));
    ExpectFalse(Group->hasWriteAccess(Wizard, "/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeIsNotOwnerOfFilesInMail()
{
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/mail"));
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/mail/m/maeglin.o"));
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotReadFilesInBanish()
{
    ExpectFalse(Group->hasReadAccess(Wizard, "/banish"));
    ExpectFalse(Group->hasReadAccess(Wizard, "/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotWriteFilesInBanish()
{
    ExpectFalse(Group->hasWriteAccess(Wizard, "/banish"));
    ExpectFalse(Group->hasWriteAccess(Wizard, "/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeIsNotOwnerOfFilesInBanish()
{
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/banish"));
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotReadFilesInGodstf()
{
    ExpectFalse(Group->hasReadAccess(Wizard, "/godstf"));
    ExpectFalse(Group->hasReadAccess(Wizard, "/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotWriteFilesInGodstf()
{
    ExpectFalse(Group->hasWriteAccess(Wizard, "/godstf"));
    ExpectFalse(Group->hasWriteAccess(Wizard, "/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeIsNotOwnerOfFilesInGodstf()
{
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/godstf"));
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotReadFilesInGuild()
{
    ExpectFalse(Group->hasReadAccess(Wizard, "/guild"));
    ExpectFalse(Group->hasReadAccess(Wizard, "/guild/mage/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotWriteFilesInGuild()
{
    ExpectFalse(Group->hasWriteAccess(Wizard, "/guild"));
    ExpectFalse(Group->hasWriteAccess(Wizard, "/guild/priest/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeIsNotOwnerOfFilesInGuild()
{
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/guild"));
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/guild/fighter/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotReadFilesInPlayers()
{
    ExpectFalse(Group->hasReadAccess(Wizard, "/players"));
    ExpectFalse(Group->hasReadAccess(Wizard, "/players/maeglin/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanNotWriteFilesInPlayers()
{
    ExpectFalse(Group->hasWriteAccess(Wizard, "/players"));
    ExpectFalse(Group->hasWriteAccess(Wizard, "/players/sonja/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeIsNotOwnerOfFilesInPlayers()
{
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/players"));
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/players/valren/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanReadTheirOwnFiles()
{
    ExpectTrue(Group->hasReadAccess(Wizard, "/players/earl"));
    ExpectTrue(Group->hasReadAccess(Wizard, "/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeCanWriteTheirOwnFiles()
{
    ExpectTrue(Group->hasWriteAccess(Wizard, "/players/earl"));
    ExpectTrue(Group->hasWriteAccess(Wizard, "/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApprenticeIsOwnerOfTheirOwnFiles()
{
    ExpectTrue(Group->hasOwnershipAccess(Wizard, "/players/earl"));
    ExpectTrue(Group->hasOwnershipAccess(Wizard, "/players/earl/closed/blah.c"));
}
