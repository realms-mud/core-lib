//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    Movement.Name("Bob");
    Movement.Str(10);
    Movement.Int(10);
    Movement.Wis(10);
    Movement.Con(10);
    Movement.Dex(10);
    Movement.Chr(10);
    Movement.hitPoints(Movement.maxHitPoints());
    Movement.addCommands();
    Movement.create();

    FromPlace = load_object("/lib/tests/support/environment/fromLocation.c");
    FromPlace.toggleLight();
    move_object(Movement, FromPlace);

    ToPlace = load_object("/lib/tests/support/environment/toLocation.c");
    ToPlace.toggleLight();
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
    ExpectTrue(Movement.move(program_name(ToPlace)), "move called");
    ExpectTrue(present(Movement, ToPlace), "moved to to place");
    ExpectEq(1, Movement.countObservations(([ "type": "movement.leave" ])));
    ExpectEq(1, Movement.countObservations(([ "type": "movement.enter" ])));
    ExpectTrue(Movement.hasObservation(([
        "type": "movement.leave",
        "location": program_name(FromPlace),
        "subject": program_name(ToPlace)
    ])));
    ExpectTrue(Movement.hasObservation(([
        "type": "movement.enter",
        "location": program_name(ToPlace),
        "subject": program_name(FromPlace),
        "from": program_name(FromPlace),
        "to": program_name(ToPlace)
    ])));
    ExpectEq("This is the long description.\n",
        Movement.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SuccessfulEscapeRecordsFleeAndEndsBothSides()
{
    FromPlace.addTestExit("north", program_name(ToPlace));
    efun::set_this_player(Movement);
    FromPlace.init();
    object foe = clone_object("/lib/realizations/monster.c");
    foe.Name("Pursuer");
    move_object(foe, FromPlace);
    ExpectTrue(Movement.registerAttacker(foe));
    ExpectTrue(foe.registerAttacker(Movement));
    Movement.runAway();
    ExpectTrue(environment(Movement) == ToPlace);
    ExpectEq(1, Movement.countObservations(([ "type":"combat.fled" ])));
    ExpectEq(1, Movement.countObservations(([ "type":"combat.ended" ])));
    ExpectEq(1, foe.countObservations(([ "type":"combat.ended" ])));
    ExpectFalse(foe.isInCombatWith(Movement));
    destruct(foe);
}

/////////////////////////////////////////////////////////////////////////////
void BlockedEscapeDoesNotRecordFleeOrEndCombat()
{
    FromPlace.addTestExit("north", program_name(ToPlace));
    efun::set_this_player(Movement);
    FromPlace.init();
    FromPlace.toggleAllowTo();
    object foe = clone_object("/lib/realizations/monster.c");
    foe.Name("Pursuer");
    move_object(foe, FromPlace);
    ExpectTrue(Movement.registerAttacker(foe));
    Movement.runAway();
    ExpectTrue(environment(Movement) == FromPlace);
    ExpectEq(0, Movement.countObservations(([ "type":"combat.fled" ])));
    ExpectEq(0, Movement.countObservations(([ "type":"combat.ended" ])));
    ExpectTrue(Movement.isInCombatWith(foe));
    destruct(foe);
}

/////////////////////////////////////////////////////////////////////////////
void MovementCapturesActualSourceAndDestinationRegions()
{
    object sourceRegion = clone_object("/lib/environment/region.c");
    object destinationRegion = clone_object("/lib/environment/region.c");
    sourceRegion->setRegionName("Source region");
    destinationRegion->setRegionName("Destination region");
    FromPlace->setRegion(sourceRegion);
    ToPlace->setRegion(destinationRegion);
    ExpectTrue(Movement.move(program_name(ToPlace), "north"));
    mapping *left = Movement.queryObservations(([ "type": "movement.leave" ]));
    mapping *entered = Movement.queryObservations(([
        "type": "movement.enter"
    ]));
    ExpectEq("Source region", left[0]["context"]["region name"]);
    ExpectEq("Destination region", entered[0]["context"]["region name"]);
    ExpectEq(program_name(sourceRegion), left[0]["context"]["region"]);
    ExpectEq(program_name(destinationRegion), entered[0]["context"]["region"]);
    ExpectEq("north", entered[0]["context"]["direction"]);
    destruct(sourceRegion);
    destruct(destinationRegion);
}

/////////////////////////////////////////////////////////////////////////////
void SpellActionIsSetWhenMoveOccursDuringCombat()
{
    object target = clone_object("/lib/realizations/monster.c");
    target.Name("fred");
    target.SetUpPersonaOfLevel("swordsman", 1);
    move_object(target, FromPlace);

    Movement.attack(target);
    target.heart_beat();
    ExpectFalse(Movement.spellAction());
    ExpectTrue(Movement.move(program_name(ToPlace)), "move called");
    ExpectTrue(Movement.spellAction());
}

/////////////////////////////////////////////////////////////////////////////
void SpellActionIsNotSetWhenMoveOccursWhenNotInCombat()
{
    ExpectFalse(Movement.spellAction());
    ExpectTrue(Movement.move(program_name(ToPlace)), "move called");
    ExpectFalse(Movement.spellAction());
}

/////////////////////////////////////////////////////////////////////////////
void ObserverSeesMagicalMessageOutWhenObjectLeaves()
{
    object observer = clone_object("/lib/tests/support/services/mockPlayer");
    move_object(observer, FromPlace);

    ExpectTrue(Movement.move(program_name(ToPlace)), "move called");
    ExpectEq("Bob vanishes in a puff of smoke.\n", observer.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ObserverSeesMessageOutWhenObjectLeaves()
{
    object observer = clone_object("/lib/tests/support/services/mockPlayer");
    move_object(observer, FromPlace);

    ExpectTrue(Movement.move(program_name(ToPlace), "north"), "move called");
    ExpectEq("Bob leaves north.\n", observer.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ObserverSeesNothingWhenInvisibleObjectLeaves()
{
    object observer = clone_object("/lib/tests/support/services/mockPlayer");
    move_object(observer, FromPlace);

    Movement.Invisibility(1);
    ExpectTrue(Movement.move(program_name(ToPlace), "north"), "move called");
    ExpectFalse(observer.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ObserverSeesNothingWhenItIsDarkAndObjectLeaves()
{
    object observer = clone_object("/lib/tests/support/services/mockPlayer");
    move_object(observer, FromPlace);

    FromPlace.toggleLight();
    ExpectTrue(Movement.move(program_name(ToPlace), "north"), "move called");
    ExpectFalse(observer.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ObserverSeesMagicalMessageInWhenObjectArrives()
{
    object observer = clone_object("/lib/tests/support/services/mockPlayer");
    move_object(observer, ToPlace);

    ExpectTrue(Movement.move(program_name(ToPlace)), "move called");
    ExpectEq("Bob appears in a puff of smoke.\n", observer.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ObserverSeesMessageInWhenObjectArrives()
{
    object observer = clone_object("/lib/tests/support/services/mockPlayer");
    move_object(observer, ToPlace);

    ExpectTrue(Movement.move(program_name(ToPlace), "north"), "move called");
    ExpectEq("Bob arrives.\n", observer.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ObserverSeesNothingWhenInvisibleObjectArrives()
{
    object observer = clone_object("/lib/tests/support/services/mockPlayer");
    move_object(observer, ToPlace);

    Movement.Invisibility(1);
    ExpectTrue(Movement.move(program_name(ToPlace), "north"), "move called");
    ExpectFalse(observer.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ObserverSeesNothingWhenItIsDarkAndObjectArrives()
{
    object observer = clone_object("/lib/tests/support/services/mockPlayer");
    move_object(observer, ToPlace);

    ToPlace.toggleLight();
    ExpectTrue(Movement.move(program_name(ToPlace), "north"), "move called");
    ExpectFalse(observer.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MoveIsPreventedWhenAllowFromIsProhibited()
{
    ToPlace.toggleAllowFrom();
    ExpectFalse(Movement.move(program_name(ToPlace), "north"), "move called");
    ExpectFalse(Movement.hasObservation(([ "type": "movement" ])));
}

/////////////////////////////////////////////////////////////////////////////
void MoveIsPreventedWhenAllowToIsProhibited()
{
    FromPlace.toggleAllowTo();
    ExpectFalse(Movement.move(program_name(ToPlace), "north"), "move called");
    ExpectFalse(Movement.hasObservation(([ "type": "movement" ])));
}

/////////////////////////////////////////////////////////////////////////////
void MovingIntoClonedEnvironmentCreatesClone()
{
    object Service = getService("environment");
    Service.timeOfDay("noon");

    object initialRoom = load_object("/lib/tests/support/environment/clonedRoom.c");

    ExpectTrue(Movement.move("/lib/tests/support/environment/clonedRoom.c"), "move called");

    ExpectTrue(clonep(environment(Movement)));
    ExpectEq(initialRoom.environmentName(),
        environment(Movement).environmentName());
    ExpectSubStringMatch("deciduous forest.*There are two obvious exits: south, west",
        Movement.caughtMessage());

    destruct(initialRoom);
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyMovesFromCloneToClone()
{
    object Service = getService("environment");
    Service.timeOfDay("noon");

    object initialRoom = load_object("/lib/tests/support/environment/clonedRoom.c");

    ExpectTrue(Movement.move("/lib/tests/support/environment/clonedRoom.c"), "move called");
    ExpectTrue(clonep(environment(Movement)));
    command("west", Movement);

    ExpectTrue(clonep(environment(Movement)));
    ExpectEq("/lib/tests/support/environment/secondClonedRoom",
        environment(Movement).environmentName());

    ExpectSubStringMatch("deciduous forest.*There is one obvious exit: east",
        Movement.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyMovesFromCloneToNotClonedRoom()
{
    object Service = getService("environment");
    Service.timeOfDay("noon");

    object initialRoom = load_object("/lib/tests/support/environment/clonedRoom.c");

    ExpectTrue(Movement.move("/lib/tests/support/environment/clonedRoom.c"), "move called");
    ExpectTrue(clonep(environment(Movement)));
    command("south", Movement);

    ExpectFalse(clonep(environment(Movement)));
    ExpectEq("/lib/tests/support/environment/notClonedRoom",
        environment(Movement).environmentName());

    ExpectSubStringMatch("deciduous forest.*There is one obvious exit: north",
        Movement.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyMovesFromNotClonedToCloneRoom()
{
    object Service = getService("environment");
    Service.timeOfDay("noon");

    object initialRoom = load_object("/lib/tests/support/environment/notClonedRoom.c");

    ExpectTrue(Movement.move("/lib/tests/support/environment/notClonedRoom.c"), "move called");
    ExpectFalse(clonep(environment(Movement)));

    command("north", Movement);

    ExpectTrue(clonep(environment(Movement)));
    ExpectEq("/lib/tests/support/environment/clonedRoom",
        environment(Movement).environmentName());

    ExpectSubStringMatch("deciduous forest.*There are two obvious exits: south, west",
        Movement.caughtMessage());
}
