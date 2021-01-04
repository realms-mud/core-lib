//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Door;
object User;
object Observer;
object Dictionary;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Dictionary = load_object("/lib/dictionaries/environmentDictionary.c");
    Dictionary->setYear(1);
    Dictionary->setDay(92);
    Dictionary->timeOfDay("noon");

    Door = clone_object("/lib/environment/doors/door.c");

    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User->Name("Bob");
    User->Gender("male");
    User->Str(20);
    User->Dex(20);
    User->Con(20);
    User->Int(20);
    User->Wis(20);

    move_object(User, this_object());

    Observer = clone_object("/lib/tests/support/services/mockPlayer.c");
    Observer->Name("Henrietta");
    Observer->Gender("female");
    move_object(Observer, this_object());
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(User);
    destruct(Observer);
    destruct(Door);
    destruct(Dictionary);
}

/////////////////////////////////////////////////////////////////////////////
void TypeReturnsDoor()
{
    ExpectEq("door", Door->Type());
}

/////////////////////////////////////////////////////////////////////////////
void DoorsWithoutLocksCannotBeLocked()
{
    ExpectFalse(Door->isLocked());
    Door->lock(User);
    ExpectFalse(Door->isLocked());
    ExpectSubStringMatch("You try to lock the door but notice that it has no lock", 
        User->caughtMessage());
    ExpectSubStringMatch("Bob tries to lock the door but notices that it has no lock", 
        Observer->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DoorsWithoutLocksCannotBeUnlocked()
{
    ExpectFalse(Door->isLocked());
    Door->unlock(User);
    ExpectFalse(Door->isLocked());
    ExpectSubStringMatch("You try to unlock the door but notice that it has no lock",
        User->caughtMessage());
    ExpectSubStringMatch("Bob tries to unlock the door but notices that it has no lock",
        Observer->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LockedDoorsCannotBeUnlockedWithoutKey()
{
    Door->setKey("/lib/items/key.c");

    ExpectTrue(Door->isLocked());
    Door->unlock(User);
    ExpectTrue(Door->isLocked());
    ExpectSubStringMatch("You try to unlock the door but do not have the key",
        User->caughtMessage());
    ExpectSubStringMatch("Bob tries to unlock the door but does not have the key",
        Observer->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void UnlockedDoorsCannotBeLockedWithoutKey()
{
    Door->setKey("/lib/items/key.c", 1);

    ExpectFalse(Door->isLocked());
    Door->lock(User);
    ExpectFalse(Door->isLocked());
    ExpectSubStringMatch("You try to lock the door but do not have the key",
        User->caughtMessage());
    ExpectSubStringMatch("Bob tries to lock the door but does not have the key",
        Observer->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LockedDoorsCanBeUnlocked()
{
    Door->setKey("/lib/items/key.c");
    move_object(clone_object("/lib/items/key.c"), User);

    ExpectTrue(Door->isLocked());
    Door->unlock(User);
    ExpectFalse(Door->isLocked());

    ExpectSubStringMatch("You unlock the door",
        User->caughtMessage());
    ExpectSubStringMatch("Bob unlocks the door",
        Observer->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void UnlockedDoorsCanBeLocked()
{
    Door->setKey("/lib/items/key.c", 1);
    move_object(clone_object("/lib/items/key.c"), User);

    ExpectFalse(Door->isLocked());
    Door->lock(User);
    ExpectTrue(Door->isLocked());

    ExpectSubStringMatch("You lock the door",
        User->caughtMessage());
    ExpectSubStringMatch("Bob locks the door",
        Observer->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LockedMessageDisplayed()
{
    Door->displayLockedMessage(User);
    ExpectSubStringMatch("You try to go through the door, but it is locked",
        User->caughtMessage());
    ExpectSubStringMatch("Bob tries to go through the door, but it is locked",
        Observer->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MoveMessageDisplayed()
{
    Door->displayMoveMessage(User, "north");
    ExpectSubStringMatch("You go through the door to the north",
        User->caughtMessage());
    ExpectSubStringMatch("Bob goes through the door to the north",
        Observer->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CloseMessageDisplayed()
{
    Door->displayCloseMessage(User);
    ExpectSubStringMatch("The door closes",
        User->caughtMessage());
    ExpectSubStringMatch("The door closes",
        Observer->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DoorLocksAtProperTime()
{
    Door->setKey("/lib/items/key.c", 1);
    Door->setWhenLockActive("default", "midnight");
    Door->setWhenLockActive("stuff", "noon");

    ExpectFalse(Door->isLocked());

    Door->currentState("stuff");
    ExpectTrue(Door->isLocked());

    Dictionary->timeOfDay("midnight");
    ExpectFalse(Door->isLocked());

    Door->currentState("default");
    ExpectTrue(Door->isLocked());

    Dictionary->timeOfDay("morning");
    ExpectFalse(Door->isLocked());
}

/////////////////////////////////////////////////////////////////////////////
void DoorDoesNotLockOnTimeIfManipulated()
{
    Door->setKey("/lib/items/key.c");
    move_object(clone_object("/lib/items/key.c"), User);

    Door->setWhenLockActive("default", "midnight");

    ExpectTrue(Door->isLocked());
    Door->unlock(User);

    Dictionary->timeOfDay("midnight");
    ExpectFalse(Door->isLocked());
}

/////////////////////////////////////////////////////////////////////////////
void DoorDoesNotUnlockOnTimeIfManipulated()
{
    Door->setKey("/lib/items/key.c", 1);
    move_object(clone_object("/lib/items/key.c"), User);

    Door->setWhenLockActive("default", "midnight");

    ExpectFalse(Door->isLocked());
    Door->lock(User);
    ExpectTrue(Door->isLocked());

    Dictionary->timeOfDay("midnight");
    ExpectTrue(Door->isLocked());

    Dictionary->timeOfDay("morning");
    ExpectTrue(Door->isLocked());
}

/////////////////////////////////////////////////////////////////////////////
void CannotPickLockIfDoorNotLocked()
{
    Door->setKey("/lib/items/key.c", 1);
    ExpectFalse(Door->isLocked());

    Door->pickLock(User);
    ExpectFalse(Door->isLocked());
    ExpectSubStringMatch("You try to pick the lock of an already-unlocked door",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotPickLockIfSkillTooLowForDoor()
{
    Door->setKey("/lib/items/key.c");
    ExpectTrue(Door->isLocked());

    Door->pickLock(User);
    ExpectTrue(Door->isLocked());
    ExpectSubStringMatch("You try to pick the door's lock but fail",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanPickLock()
{
    User->addSkillPoints(100);
    User->advanceSkill("open lock", 10);

    ExpectEq(10, User->getSkill("open lock"));
    Door->setKey("/lib/items/key.c");
    ExpectTrue(Door->isLocked());

    Door->pickLock(User);
    ExpectFalse(Door->isLocked());
    ExpectSubStringMatch("You pick the lock on the door",
        User->caughtMessage());
    ExpectSubStringMatch("Bob picks the lock on the door",
        Observer->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanDestroyDoorThatIsBreakable()
{
}

/////////////////////////////////////////////////////////////////////////////
void CannotDamageDoorThatIsUnbreakable()
{
}
