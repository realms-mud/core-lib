//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    Group = clone_object("/lib/tests/support/dictionaries/groups/mockGroup.c");

    Wizard = clone_object("/lib/realizations/wizard.c");
    setUsers(({ Wizard }));

    setCustomGroups(({ Group->group() }));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Wizard);
    destruct(Group);
    setCustomGroups(({}));
}

/////////////////////////////////////////////////////////////////////////////
void InitCallsApplyGroupDetails()
{
    destruct(Group);
    Group = clone_object("/lib/tests/support/dictionaries/groups/mockGroup.c");
    ExpectTrue(Group->ApplyWasCalled(), "called");
}

/////////////////////////////////////////////////////////////////////////////
void GroupReturnsUnqualifiedNameOfGroupFile()
{
    destruct(Group);
    Group = clone_object("/lib/dictionaries/groups/baseGroup.c");
    ExpectEq("baseGroup", Group->group());
}

/////////////////////////////////////////////////////////////////////////////
void GroupsInIncorrectLocationWillNotReturnValidGroup()
{
    destruct(Group);
    Group = clone_object("/lib/tests/support/groupInInvalidLocation.c");

    ExpectEq(0, Group->group());
}

/////////////////////////////////////////////////////////////////////////////
void SetNameModifiesTheGroupName()
{
    ExpectEq(0, Group->name());
    Group->testSetName("Test Group");
    ExpectEq("Test Group", Group->name());
}

/////////////////////////////////////////////////////////////////////////////
void IsMemberOfReturnsFalseForNonInteractiveUsers()
{
    destruct(Group);
    Group = clone_object("/lib/dictionaries/groups/apprentice.c");

    setUsers(({  }));
    ExpectFalse(Group->isMemberOf(Wizard));
}

/////////////////////////////////////////////////////////////////////////////
void IsMemberOfReturnsTrueIfWizardInteractiveAndInGroup()
{
    destruct(Group);
    Group = clone_object("/lib/dictionaries/groups/apprentice.c");
    setCustomGroups(({ Group->group() }));

    ExpectTrue(Group->isMemberOf(Wizard));
}

/////////////////////////////////////////////////////////////////////////////
void IsMemberOfReturnsFalseIfWizardNotInGroup()
{
    destruct(Group);
    Group = clone_object("/lib/dictionaries/groups/god.c");

    ExpectFalse(Group->isMemberOf(Wizard));
}

/////////////////////////////////////////////////////////////////////////////
void IsMemberOfReturnsFalseIfObjectNotAWizard()
{
    destruct(Group);
    Group = clone_object("/lib/dictionaries/groups/player.c");

    object user = clone_object("/lib/realizations/player.c");
    setUsers(({ user, Wizard }));
    ExpectFalse(Group->isMemberOf(user));
}

/////////////////////////////////////////////////////////////////////////////
void HasReadAccessReturnsFalseIfPermissionNotSet()
{
    ExpectFalse(Group->hasReadAccess(Wizard, "/secure/master.c"));
}

/////////////////////////////////////////////////////////////////////////////
void HasReadAccessReturnsTrueForSpecificallySetPermission()
{
    Group->testAddPermission("/secure/master.c", Read);
    ExpectTrue(Group->hasReadAccess(Wizard, "/secure/master.c"));
}

/////////////////////////////////////////////////////////////////////////////
void HasReadAccessReturnsTrueForDirectoryPermission()
{
    Group->testAddPermission("/secure", Read);
    ExpectTrue(Group->hasReadAccess(Wizard, "/secure/master.c"));
}

/////////////////////////////////////////////////////////////////////////////
void HasReadAccessReturnsTrueForRecursedDirectoryPermission()
{
    Group->testAddPermission("/secure", Read);
    ExpectTrue(Group->hasReadAccess(Wizard, "/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void HasReadAccessReturnsCorrectlyIfRecursivePermissionRemoved()
{
    Group->testAddPermission("/secure", Read);
    Group->testAddPermission("/secure/player", None);
    ExpectFalse(Group->hasReadAccess(Wizard, "/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void HasReadAccessReturnsCorrectlyForANYDirective()
{
    Group->testAddPermission("/guild", Read);
    Group->testAddPermission("/guild/$ANY/stuff", None);
    ExpectFalse(Group->hasReadAccess(Wizard, "/guild/something/stuff/x.c"));
    ExpectFalse(Group->hasReadAccess(Wizard, "/guild/weasel/stuff/x.c"));
    ExpectTrue(Group->hasReadAccess(Wizard, "/guild/something/blarg/x.c"));
}

/////////////////////////////////////////////////////////////////////////////
void HasReadAccessReturnsCorrectlyForUSERDirective()
{
    Group->testAddPermission("/players/$USER", Read);
    ExpectFalse(Group->hasReadAccess(Wizard, "/players/earl/thing.c"));
    Wizard->Name("earl");
    ExpectTrue(Group->hasReadAccess(Wizard, "/players/earl/thing.c"));
    ExpectFalse(Group->hasReadAccess(Wizard, "/players/fred/thing.c"));
}

/////////////////////////////////////////////////////////////////////////////
void HasWriteAccessReturnsFalseIfPermissionNotSet()
{
    ExpectFalse(Group->hasWriteAccess(Wizard, "/secure/master.c"));
}

/////////////////////////////////////////////////////////////////////////////
void HasWriteAccessReturnsTrueForSpecificallySetPermission()
{
    Group->testAddPermission("/secure/master.c", Write);
    ExpectTrue(Group->hasWriteAccess(Wizard, "/secure/master.c"));
}

/////////////////////////////////////////////////////////////////////////////
void HasWriteAccessReturnsTrueForDirectoryPermission()
{
    Group->testAddPermission("/secure", Write);
    ExpectTrue(Group->hasWriteAccess(Wizard, "/secure/master.c"));
}

/////////////////////////////////////////////////////////////////////////////
void HasWriteAccessReturnsTrueForRecursedDirectoryPermission()
{
    Group->testAddPermission("/secure", Write);
    ExpectTrue(Group->hasWriteAccess(Wizard, "/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void HasWriteAccessReturnsCorrectlyIfRecursivePermissionRemoved()
{
    Group->testAddPermission("/secure", Write);
    Group->testAddPermission("/secure/player", None);
    ExpectFalse(Group->hasWriteAccess(Wizard, "/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void HasWriteAccessReturnsCorrectlyForANYDirective()
{
    Group->testAddPermission("/guild", Write);
    Group->testAddPermission("/guild/$ANY/stuff", None);
    ExpectFalse(Group->hasWriteAccess(Wizard, "/guild/something/stuff/x.c"));
    ExpectFalse(Group->hasWriteAccess(Wizard, "/guild/weasel/stuff/x.c"));
    ExpectTrue(Group->hasWriteAccess(Wizard, "/guild/something/blarg/x.c"));
}

/////////////////////////////////////////////////////////////////////////////
void HasWriteAccessReturnsCorrectlyForUSERDirective()
{
    Group->testAddPermission("/players/$USER", Write);
    ExpectFalse(Group->hasWriteAccess(Wizard, "/players/earl/thing.c"));
    Wizard->Name("earl");
    ExpectTrue(Group->hasWriteAccess(Wizard, "/players/earl/thing.c"));
    ExpectFalse(Group->hasWriteAccess(Wizard, "/players/fred/thing.c"));
}

/////////////////////////////////////////////////////////////////////////////
void HasOwnershipAccessReturnsFalseIfPermissionNotSet()
{
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/secure/master.c"));
}

/////////////////////////////////////////////////////////////////////////////
void HasOwnershipAccessReturnsTrueForSpecificallySetPermission()
{
    Group->testAddPermission("/secure/master.c", Read | Write | Owner);
    ExpectTrue(Group->hasOwnershipAccess(Wizard, "/secure/master.c"));
}

/////////////////////////////////////////////////////////////////////////////
void HasOwnershipAccessReturnsTrueForDirectoryPermission()
{
    Group->testAddPermission("/secure", Read | Write | Owner);
    ExpectTrue(Group->hasOwnershipAccess(Wizard, "/secure/master.c"));
}

/////////////////////////////////////////////////////////////////////////////
void HasOwnershipAccessReturnsTrueForRecursedDirectoryPermission()
{
    Group->testAddPermission("/secure", Read | Write | Owner);
    ExpectTrue(Group->hasOwnershipAccess(Wizard, "/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void HasOwnershipAccessReturnsCorrectlyIfRecursivePermissionRemoved()
{
    Group->testAddPermission("/secure", Read | Write | Owner);
    Group->testAddPermission("/secure/player", None);
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/secure/player/files/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void HasOwnershipAccessReturnsCorrectlyForANYDirective()
{
    Group->testAddPermission("/guild", Read | Write | Owner);
    Group->testAddPermission("/guild/$ANY/stuff", None);
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/guild/something/stuff/x.c"));
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/guild/weasel/stuff/x.c"));
    ExpectTrue(Group->hasOwnershipAccess(Wizard, "/guild/something/blarg/x.c"));
}

/////////////////////////////////////////////////////////////////////////////
void HasOwnershipAccessReturnsCorrectlyForUSERDirective()
{
    Group->testAddPermission("/players/$USER", Read | Write | Owner);
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/players/earl/thing.c"));
    Wizard->Name("earl");
    ExpectTrue(Group->hasOwnershipAccess(Wizard, "/players/earl/thing.c"));
    ExpectFalse(Group->hasOwnershipAccess(Wizard, "/players/fred/thing.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CanTraverseRelativePaths()
{
    string testFile = "/secure/player/./././../../secure/../secure/player/player.c";

    ExpectFalse(Group->hasWriteAccess(Wizard, testFile));
    Group->testAddPermission("/secure/player/player.c", Write);

    ExpectTrue(Group->hasWriteAccess(Wizard, testFile));
}
