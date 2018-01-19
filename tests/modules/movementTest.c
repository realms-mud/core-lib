//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Movement;
object FromPlace;
object ToPlace;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Movement = clone_object("/lib/tests/support/services/mockPlayer");
    Movement->Name("Bob");
    Movement->reset();

    FromPlace = load_object("/lib/tests/support/environment/fromLocation.c");
    FromPlace->toggleLight();
    move_object(Movement, FromPlace);

    ToPlace = load_object("/lib/tests/support/environment/toLocation.c");
    ToPlace->toggleLight();
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Movement);
    destruct(FromPlace);
    destruct(ToPlace);
}

/////////////////////////////////////////////////////////////////////////////
void CanMoveUserFromOneEnvironmentToAnother()
{
    ExpectTrue(present(Movement, FromPlace), "currently in from place");
    ExpectTrue(Movement->move(program_name(ToPlace)), "move called");
    ExpectTrue(present(Movement, ToPlace), "moved to to place");
    ExpectEq("This is the long description.\n",
        Movement->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SpellActionIsSetWhenMoveOccurs()
{
    ExpectFalse(Movement->spellAction());
    ExpectTrue(Movement->move(program_name(ToPlace)), "move called");
    ExpectEq(1, Movement->spellAction());
}

/////////////////////////////////////////////////////////////////////////////
void ObserverSeesMagicalMessageOutWhenObjectLeaves()
{
    object observer = clone_object("/lib/tests/support/services/mockPlayer");
    move_object(observer, FromPlace);

    ExpectTrue(Movement->move(program_name(ToPlace)), "move called");
    ExpectEq("Bob vanishes in a puff of smoke.\n", observer->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ObserverSeesMessageOutWhenObjectLeaves()
{
    object observer = clone_object("/lib/tests/support/services/mockPlayer");
    move_object(observer, FromPlace);

    ExpectTrue(Movement->move(program_name(ToPlace), "north"), "move called");
    ExpectEq("Bob leaves north.\n", observer->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ObserverSeesNothingWhenInvisibleObjectLeaves()
{
    object observer = clone_object("/lib/tests/support/services/mockPlayer");
    move_object(observer, FromPlace);

    Movement->Invisibility(1);
    ExpectTrue(Movement->move(program_name(ToPlace), "north"), "move called");
    ExpectFalse(observer->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ObserverSeesNothingWhenItIsDarkAndObjectLeaves()
{
    object observer = clone_object("/lib/tests/support/services/mockPlayer");
    move_object(observer, FromPlace);

    FromPlace->toggleLight();
    ExpectTrue(Movement->move(program_name(ToPlace), "north"), "move called");
    ExpectFalse(observer->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ObserverSeesMagicalMessageInWhenObjectArrives()
{
    object observer = clone_object("/lib/tests/support/services/mockPlayer");
    move_object(observer, ToPlace);

    ExpectTrue(Movement->move(program_name(ToPlace)), "move called");
    ExpectEq("Bob appears in a puff of smoke.\n", observer->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ObserverSeesMessageInWhenObjectArrives()
{
    object observer = clone_object("/lib/tests/support/services/mockPlayer");
    move_object(observer, ToPlace);

    ExpectTrue(Movement->move(program_name(ToPlace), "north"), "move called");
    ExpectEq("Bob arrives.\n", observer->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ObserverSeesNothingWhenInvisibleObjectArrives()
{
    object observer = clone_object("/lib/tests/support/services/mockPlayer");
    move_object(observer, ToPlace);

    Movement->Invisibility(1);
    ExpectTrue(Movement->move(program_name(ToPlace), "north"), "move called");
    ExpectFalse(observer->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ObserverSeesNothingWhenItIsDarkAndObjectArrives()
{
    object observer = clone_object("/lib/tests/support/services/mockPlayer");
    move_object(observer, ToPlace);

    ToPlace->toggleLight();
    ExpectTrue(Movement->move(program_name(ToPlace), "north"), "move called");
    ExpectFalse(observer->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MoveIsPreventedWhenAllowFromIsProhibited()
{
    ToPlace->toggleAllowFrom();
    ExpectFalse(Movement->move(program_name(ToPlace), "north"), "move called");
}

/////////////////////////////////////////////////////////////////////////////
void MoveIsPreventedWhenAllowToIsProhibited()
{
    FromPlace->toggleAllowTo();
    ExpectFalse(Movement->move(program_name(ToPlace), "north"), "move called");
}