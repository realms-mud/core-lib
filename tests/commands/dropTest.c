//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Player;
object Item;
object Chainmail;
object Weapon;
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

    Chainmail = clone_object("/lib/items/armor.c");
    Chainmail->set("armor type", "chainmail");
    Chainmail->set("name", "chainmail");
    Chainmail->set("equipment locations", Armor);

    Weapon = clone_object("/lib/items/weapon.c");
    Weapon->set("Weapon type", "long sword");
    Weapon->set("aliases", ({ "sword" }));

    move_object(Chainmail, Player);
    move_object(Weapon, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Weapon);
    destruct(Chainmail);
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
    ExpectEq(1, sizeof(all_inventory(Room)));
    ExpectTrue(Player->executeCommand("drop all"));
    ExpectEq(4, sizeof(all_inventory(Room)));
}

/////////////////////////////////////////////////////////////////////////////
void AFlagDropsAllMovableItemsThatMatchId()
{
    ExpectEq(1, sizeof(all_inventory(Room)));
    ExpectTrue(Player->executeCommand("drop -a sword"));
    ExpectEq(3, sizeof(all_inventory(Room)));
    ExpectTrue(present(Weapon, Room));
    ExpectTrue(present(Item, Room));
    ExpectTrue(present(Chainmail, Player));
}

/////////////////////////////////////////////////////////////////////////////
void NoAFlagDropsOnlyTopMovableItemThatMatchesId()
{
    ExpectEq(1, sizeof(all_inventory(Room)));
    ExpectTrue(Player->executeCommand("drop sword"));
    ExpectEq(2, sizeof(all_inventory(Room)));
    ExpectTrue(present(Weapon, Room));
    ExpectTrue(present(Item, Player));
    ExpectTrue(present(Chainmail, Player));
}

/////////////////////////////////////////////////////////////////////////////
void DropDoesNotDropEquippedItemsByDefault()
{
    Item->equip("sword");
    Chainmail->equip("chainmail");

    ExpectEq(1, sizeof(all_inventory(Room)));
    ExpectTrue(Player->executeCommand("drop all"));
    ExpectEq(2, sizeof(all_inventory(Room)));
    ExpectTrue(present(Weapon, Room), "Weapon in room");
    ExpectTrue(present(Item, Player), "Item on player");
    ExpectTrue(present(Chainmail, Player), "Chainmail on player");
}

/////////////////////////////////////////////////////////////////////////////
void DropWithFFlagForcesDropOfEquippedItems()
{
    Item->equip("sword");
    Chainmail->equip("chainmail");

    ExpectEq(1, sizeof(all_inventory(Room)));
    ExpectTrue(Player->executeCommand("drop -f all"));
    ExpectEq(4, sizeof(all_inventory(Room)));
    ExpectTrue(present(Weapon, Room), "Weapon in room");
    ExpectTrue(present(Item, Room), "Item on player");
    ExpectTrue(present(Chainmail, Room), "Chainmail on player");
}

/////////////////////////////////////////////////////////////////////////////
void DropWithFAndAFlagsForcesDropOfEquippedItemsOfProperType()
{
    Item->equip("sword");
    Chainmail->equip("chainmail");

    ExpectEq(1, sizeof(all_inventory(Room)));
    ExpectTrue(Player->executeCommand("drop -a -f sword"));
    ExpectEq(3, sizeof(all_inventory(Room)));
    ExpectTrue(present(Weapon, Room), "Weapon in room");
    ExpectTrue(present(Item, Room), "Item on player");
    ExpectTrue(present(Chainmail, Player), "Chainmail on player");
}

/////////////////////////////////////////////////////////////////////////////
void DropWithAAndFFlagsReversedForcesDropOfEquippedItemsOfProperType()
{
    Item->equip("sword");
    Chainmail->equip("chainmail");

    ExpectEq(1, sizeof(all_inventory(Room)));
    ExpectTrue(Player->executeCommand("drop -f -a sword"));
    ExpectEq(3, sizeof(all_inventory(Room)));
    ExpectTrue(present(Weapon, Room), "Weapon in room");
    ExpectTrue(present(Item, Room), "Item on player");
    ExpectTrue(present(Chainmail, Player), "Chainmail on player");
}