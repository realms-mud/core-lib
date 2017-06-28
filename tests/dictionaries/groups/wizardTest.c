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
    Group = clone_object("/lib/dictionaries/groups/wizard.c");
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
void TrainingWizardCanReadFilesInOpen()
{
    ExpectTrue(Group->hasReadAccess(Wizard, "/open"));
    ExpectTrue(Group->hasReadAccess(Wizard, "/open/example.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanWriteFilesInOpen()
{
    ExpectTrue(Group->hasWriteAccess(Wizard, "/open"));
    ExpectTrue(Group->hasWriteAccess(Wizard, "/open/example.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotReadFilesInSecure()
{
    ExpectFalse(Group->hasReadAccess(Wizard, "/secure"));
    ExpectFalse(Group->hasReadAccess(Wizard, "/secure/master.c"));
    ExpectFalse(Group->hasReadAccess(Wizard, "/secure/room/board.c"));
    ExpectFalse(Group->hasReadAccess(Wizard, "/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotWriteFilesInSecure()
{
    ExpectFalse(Group->hasWriteAccess(Wizard, "/secure"));
    ExpectFalse(Group->hasWriteAccess(Wizard, "/secure/master.c"));
    ExpectFalse(Group->hasWriteAccess(Wizard, "/secure/room/board.c"));
    ExpectFalse(Group->hasWriteAccess(Wizard, "/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardIsNotOwnerOfFilesInSecure()
{
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/secure"));
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/secure/master.c"));
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/secure/room/board.c"));
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotReadFilesInMail()
{
    ExpectFalse(Group->hasReadAccess(Wizard, "/mail"));
    ExpectFalse(Group->hasReadAccess(Wizard, "/mail/m/maeglin.o"));
    ExpectFalse(Group->hasReadAccess(Wizard, "/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotWriteFilesInMail()
{
    ExpectFalse(Group->hasWriteAccess(Wizard, "/mail"));
    ExpectFalse(Group->hasWriteAccess(Wizard, "/mail/m/maeglin.o"));
    ExpectFalse(Group->hasWriteAccess(Wizard, "/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardIsNotOwnerOfFilesInMail()
{
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/mail"));
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/mail/m/maeglin.o"));
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/mail/b/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotReadFilesInBanish()
{
    ExpectFalse(Group->hasReadAccess(Wizard, "/banish"));
    ExpectFalse(Group->hasReadAccess(Wizard, "/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotWriteFilesInBanish()
{
    ExpectFalse(Group->hasWriteAccess(Wizard, "/banish"));
    ExpectFalse(Group->hasWriteAccess(Wizard, "/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardIsNotOwnerOfFilesInBanish()
{
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/banish"));
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/banish/blah.o"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotReadFilesInGodstf()
{
    ExpectFalse(Group->hasReadAccess(Wizard, "/godstf"));
    ExpectFalse(Group->hasReadAccess(Wizard, "/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotWriteFilesInGodstf()
{
    ExpectFalse(Group->hasWriteAccess(Wizard, "/godstf"));
    ExpectFalse(Group->hasWriteAccess(Wizard, "/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardIsNotOwnerOfFilesInGodstf()
{
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/godstf"));
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/godstf/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotReadFilesInGuild()
{
    ExpectFalse(Group->hasReadAccess(Wizard, "/guild"));
    ExpectFalse(Group->hasReadAccess(Wizard, "/guild/mage/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotWriteFilesInGuild()
{
    ExpectFalse(Group->hasWriteAccess(Wizard, "/guild"));
    ExpectFalse(Group->hasWriteAccess(Wizard, "/guild/priest/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardIsNotOwnerOfFilesInGuild()
{
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/guild"));
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/guild/fighter/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanReadFilesInPlayers()
{
    ExpectTrue(Group->hasReadAccess(Wizard, "/players"));
    ExpectTrue(Group->hasReadAccess(Wizard, "/players/maeglin/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotWriteFilesInPlayers()
{
    ExpectFalse(Group->hasWriteAccess(Wizard, "/players"));
    ExpectFalse(Group->hasWriteAccess(Wizard, "/players/sonja/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardIsNotOwnerOfFilesInPlayers()
{
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/players"));
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/players/valren/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotReadFilesInOtherClosedDirectories()
{
    ExpectFalse(Group->hasReadAccess(Wizard, "/players/maeglin/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanNotWriteFilesInOtherClosedDirectories()
{
    ExpectFalse(Group->hasWriteAccess(Wizard, "/players/sonja/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardIsOwnerNotOfOtherClosedDirectories()
{
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/players/valren/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanReadTheirOwnClosedFiles()
{
    ExpectTrue(Group->hasReadAccess(Wizard, "/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardCanWriteTheirOwnClosedFiles()
{
    ExpectTrue(Group->hasWriteAccess(Wizard, "/players/earl/closed/blah.c"));
}

/////////////////////////////////////////////////////////////////////////////
void TrainingWizardIsOwnerOfTheirOwnClosedFiles()
{
    ExpectTrue(Group->hasOwnershipAccess(Wizard, "/players/earl/closed/blah.c"));
}