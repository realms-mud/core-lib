//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    Room = clone_object("/lib/environment/environment.c");

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

/////////////////////////////////////////////////////////////////////////////
void CannotDropZeroCoins()
{
    ExpectFalse(Player->executeCommand("drop 0 coins"));
    ExpectFalse(present_clone("lib/items/money.c", Room));
    ExpectEq("You cannot drop 0 coins.\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotDropMoreCoinsThanUserHas()
{
    Player->addMoney(100);
    ExpectFalse(Player->executeCommand("drop 110 coins"));
    ExpectFalse(present_clone("lib/items/money.c", Room));
    ExpectEq("You cannot drop 110 coins.\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanDropAllCoins()
{
    Player->addMoney(100);
    ExpectTrue(Player->executeCommand("drop all money"));
    ExpectTrue(present_clone("lib/items/money.c", Room));
    ExpectEq(100, present_clone("lib/items/money.c", Room)->query("value"));
    ExpectEq("You drop money.\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanDropOneCoin()
{
    Player->addMoney(100);
    ExpectTrue(Player->executeCommand("drop 1 coin"));
    ExpectTrue(present_clone("lib/items/money.c", Room));
    ExpectEq(1, present_clone("lib/items/money.c", Room)->query("value"));
    ExpectEq("You drop money.\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanDropCoin()
{
    Player->addMoney(100);
    ExpectTrue(Player->executeCommand("drop coin"));
    ExpectTrue(present_clone("lib/items/money.c", Room));
    ExpectEq(1, present_clone("lib/items/money.c", Room)->query("value"));
    ExpectEq("You drop money.\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanDropSomeCoins()
{
    Player->addMoney(100);
    ExpectTrue(Player->executeCommand("drop 25 coins"), "a");
    ExpectTrue(present_clone("lib/items/money.c", Room), "b");
    ExpectEq(25, present_clone("lib/items/money.c", Room)->query("value"));
    ExpectEq("You drop money.\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanDropSomeMoney()
{
    Player->addMoney(100);
    ExpectTrue(Player->executeCommand("drop 100 money"));
    ExpectTrue(present_clone("lib/items/money.c", Room));
    ExpectEq(100, present_clone("lib/items/money.c", Room)->query("value"));
    ExpectEq("You drop money.\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlayersCannotDropItemsWithoutDropMethod()
{
	object player2 = clone_object("/lib/tests/support/services/mockPlayer.c");
	Player->Name("fred");

	move_object(player2, Player);
	ExpectFalse(Player->executeCommand("drop fred"));
	ExpectFalse(present(player2, Room));

	destruct(player2);
}

/////////////////////////////////////////////////////////////////////////////
void WizardsCanDropItemsWithoutDropMethod()
{
	object player2 = clone_object("/lib/tests/support/services/mockWizard.c");
	Player->Name("fred");

	move_object(player2, Room);
	move_object(Player, player2);

	ExpectTrue(player2->executeCommand("drop fred"));
	ExpectTrue(present(Player, Room));

	destruct(player2);
}

/////////////////////////////////////////////////////////////////////////////
void WizardsCanDropItemsById()
{
	object player2 = clone_object("/lib/tests/support/services/mockWizard.c");
	Player->Name("fred");

	move_object(player2, Room);
	move_object(Player, player2);

	ExpectTrue(player2->executeCommand("drop " + object_name(Player)));
	ExpectTrue(present(Player, Room));

	destruct(player2);
}
