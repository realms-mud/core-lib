//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Character;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Character = clone_object("/lib/realizations/player");
    Character->Name("Bob");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Character);
}

/////////////////////////////////////////////////////////////////////////////
void IntoxicatedSetsIntoxicationLevel()
{
    ExpectEq(0, Character->Intoxicated());
    ExpectEq(10, Character->Intoxicated(10));
}

/////////////////////////////////////////////////////////////////////////////
void IntoxicatedFiresOnIntoxicationCHangedEventWhenValueChanges()
{
    object subscriber = clone_object("/lib/tests/support/events/mockEventSubscriber");
    Character->registerEvent(subscriber);

    string expected = "*event handler: onIntoxicationChanged called, caller: lib/realizations/player.c";

    ExpectEq(0, Character->Intoxicated());

    string err = catch (Character->Intoxicated(10));
    ExpectEq(expected, err, "onIntoxicationChanged called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void AddIntoxicationWithoutValueReturnsFalse()
{
    ExpectFalse(Character->addIntoxication());
}

/////////////////////////////////////////////////////////////////////////////
void AddIntoxicationCanAddToIntoxValue()
{
    ExpectEq(0, Character->Intoxicated());
    ExpectTrue(Character->addIntoxication(10));
    ExpectEq(10, Character->Intoxicated());
}

/////////////////////////////////////////////////////////////////////////////
void AddIntoxicationCanRemoveFromIntoxValue()
{
    ExpectEq(10, Character->Intoxicated(10));
    ExpectTrue(Character->addIntoxication(-5));
    ExpectEq(5, Character->Intoxicated());
}

/////////////////////////////////////////////////////////////////////////////
void AddIntoxicationFiresOnIntoxicationChangedEvent()
{
    object subscriber = clone_object("/lib/tests/support/events/mockEventSubscriber");
    Character->registerEvent(subscriber);

    string expected = "*event handler: onIntoxicationChanged called, caller: lib/realizations/player.c";

    string err = catch (Character->addIntoxication(10));
    ExpectEq(expected, err, "onIntoxicationChanged called on subscriber");
}