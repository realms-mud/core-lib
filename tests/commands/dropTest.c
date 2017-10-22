//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Player;
object Item;
object Room;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Room = clone_object("/lib/environment/room.c");

    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->addCommands();
    Player->Str(10);
    Player->Dex(10);
    Player->Con(10);
    Player->Int(10);
    Player->Wis(10);
    Player->hitPoints(Player->maxHitPoints());

    move_object(Player, Room);

    Item = clone_object("/lib/tests/support/items/testSword.c");
    move_object(Item, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Item);
    destruct(Player);
    destruct(Room);
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpIsNotGreedy()
{
    ExpectFalse(Player->executeCommand("bedropify"), "bedropify");
    ExpectFalse(Player->executeCommand("dropsy"), "dropsy");
}

/////////////////////////////////////////////////////////////////////////////
void DropMovesItemFromPersonToEnvironment()
{
    ExpectEq(1, sizeof(all_inventory(Room)));
    ExpectTrue(Player->executeCommand("drop sword"));
    ExpectEq(2, sizeof(all_inventory(Room)));
}

/////////////////////////////////////////////////////////////////////////////
void DropAllMovesAllMovableItemsFromPersonToEnvironment()
{
    object armor = clone_object("/lib/items/armor.c");
    armor->set("armor type", "chainmail");
    armor->set("equipment locations", Armor);

    move_object(armor, Player);

    ExpectEq(1, sizeof(all_inventory(Room)));
    ExpectTrue(Player->executeCommand("drop all"));
    ExpectEq(3, sizeof(all_inventory(Room)));
}