//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Room;
object AttackingOwner;
object AttackingUnit;
object DefendingOwner;
object DefendingUnit;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    AttackingOwner = clone_object("/lib/tests/support/services/mockPlayer.c");
    AttackingOwner->Name("fred");
    AttackingUnit = clone_object("/lib/tests/support/tactical-combat/testKnight.c");
    AttackingUnit->set("unit leader", "fred");

    DefendingOwner = clone_object("/lib/tests/support/services/mockPlayer.c");
    DefendingOwner->Name("earl");
    DefendingUnit = clone_object("/lib/tests/support/tactical-combat/testArcher.c");
    DefendingUnit->set("unit leader", "earl");

    Room = clone_object("/lib/environment/environment.c");
    move_object(AttackingOwner, Room);
    move_object(AttackingUnit, Room);
    move_object(DefendingOwner, Room);
    move_object(DefendingUnit, Room);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(AttackingOwner);
    destruct(AttackingUnit);
    destruct(DefendingOwner);
    destruct(DefendingUnit);
    destruct(Room);
}

/////////////////////////////////////////////////////////////////////////////
void CanAttackUnit()
{
    ExpectEq("10", AttackingUnit->query("troop count"));
    ExpectEq("10", DefendingUnit->query("troop count"));
    AttackingUnit->attackUnit("archers");
    ExpectEq("2", AttackingUnit->query("troop count"));
    ExpectEq("2", DefendingUnit->query("troop count"));
}
