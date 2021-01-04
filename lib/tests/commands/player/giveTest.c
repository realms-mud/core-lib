//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Player;
object Receiver;
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

    Receiver = clone_object("/lib/tests/support/services/mockPlayer.c");
    Receiver->Name("frank");
    Receiver->addCommands();
    Receiver->Str(10);
    Receiver->Dex(10);
    Receiver->Con(10);
    Receiver->Int(10);
    Receiver->Wis(10);
    Receiver->hitPoints(Receiver->maxHitPoints());

    move_object(Receiver, Room);

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
    ExpectFalse(Player->executeCommand("begiveify"), "begiveify");
    ExpectFalse(Player->executeCommand("givesy"), "givesy");
}

/////////////////////////////////////////////////////////////////////////////
void CannotGiveWithoutTargetItemOrTargetRecipient()
{
    ExpectFalse(Player->executeCommand("give sword"));
    ExpectFalse(Player->executeCommand("give -a sword"));
    ExpectFalse(Player->executeCommand("give all"));
    ExpectFalse(Player->executeCommand("give -a to frank"));
}

/////////////////////////////////////////////////////////////////////////////
void GiveMovesItemFromPersonToTarget()
{
    ExpectTrue(present(Weapon, Player));
    ExpectFalse(present(Weapon, Receiver));
    ExpectTrue(Player->executeCommand("give sword to frank"));
    ExpectFalse(present(Weapon, Player));
    ExpectTrue(present(Weapon, Receiver));
}

/////////////////////////////////////////////////////////////////////////////
void GiveAllMovesAllMovableItemsFromPersonToTarget()
{
    ExpectEq(3, sizeof(all_inventory(Player)));
    ExpectEq(0, sizeof(all_inventory(Receiver)));
    ExpectTrue(Player->executeCommand("give all to frank"));
    ExpectEq(0, sizeof(all_inventory(Player)));
    ExpectEq(3, sizeof(all_inventory(Receiver)));
}

/////////////////////////////////////////////////////////////////////////////
void AFlagGivesAllMovableItemsThatMatchId()
{
    ExpectEq(3, sizeof(all_inventory(Player)));
    ExpectEq(0, sizeof(all_inventory(Receiver)));
    ExpectTrue(Player->executeCommand("give -a sword to frank"));
    ExpectEq(1, sizeof(all_inventory(Player)));
    ExpectEq(2, sizeof(all_inventory(Receiver)));
    ExpectTrue(present(Weapon, Receiver));
    ExpectTrue(present(Item, Receiver));
    ExpectTrue(present(Chainmail, Player));
}

/////////////////////////////////////////////////////////////////////////////
void NoAFlagGivesOnlyTopMovableItemThatMatchesId()
{
    ExpectEq(3, sizeof(all_inventory(Player)));
    ExpectEq(0, sizeof(all_inventory(Receiver)));
    ExpectTrue(Player->executeCommand("give sword to frank"));
    ExpectEq(2, sizeof(all_inventory(Player)));
    ExpectEq(1, sizeof(all_inventory(Receiver)));
    ExpectTrue(present(Weapon, Receiver));
    ExpectTrue(present(Item, Player));
    ExpectTrue(present(Chainmail, Player));
}

/////////////////////////////////////////////////////////////////////////////
void GiveDoesNotGiveEquippedItemsByDefault()
{
    Item->equip("sword");
    Chainmail->equip("chainmail");

    ExpectEq(3, sizeof(all_inventory(Player)));
    ExpectEq(0, sizeof(all_inventory(Receiver)));
    ExpectTrue(Player->executeCommand("give all to frank"));
    ExpectEq(2, sizeof(all_inventory(Player)));
    ExpectEq(1, sizeof(all_inventory(Receiver)));
    ExpectTrue(present(Weapon, Receiver), "Weapon on frank");
    ExpectTrue(present(Item, Player), "Item on player");
    ExpectTrue(present(Chainmail, Player), "Chainmail on player");
}

/////////////////////////////////////////////////////////////////////////////
void GiveWithFFlagForcesGiveOfEquippedItems()
{
    Item->equip("sword");
    Chainmail->equip("chainmail");

    ExpectEq(3, sizeof(all_inventory(Player)));
    ExpectEq(0, sizeof(all_inventory(Receiver)));
    ExpectTrue(Player->executeCommand("give -f all to frank"));
    ExpectEq(0, sizeof(all_inventory(Player)));
    ExpectEq(3, sizeof(all_inventory(Receiver)));
}

/////////////////////////////////////////////////////////////////////////////
void GiveWithFAndAFlagsForcesGiveOfEquippedItemsOfProperType()
{
    Item->equip("sword");
    Chainmail->equip("chainmail");

    ExpectEq(3, sizeof(all_inventory(Player)));
    ExpectEq(0, sizeof(all_inventory(Receiver)));
    ExpectTrue(Player->executeCommand("give -a -f sword to frank"));
    ExpectEq(1, sizeof(all_inventory(Player)));
    ExpectEq(2, sizeof(all_inventory(Receiver)));
    ExpectTrue(present(Weapon, Receiver), "Weapon on frank");
    ExpectTrue(present(Item, Receiver), "Item on frank");
    ExpectTrue(present(Chainmail, Player), "Chainmail on player");
}

/////////////////////////////////////////////////////////////////////////////
void GiveWithAAndFFlagsReversedForcesGiveOfEquippedItemsOfProperType()
{
    Item->equip("sword");
    Chainmail->equip("chainmail");

    ExpectEq(3, sizeof(all_inventory(Player)));
    ExpectEq(0, sizeof(all_inventory(Receiver)));
    ExpectTrue(Player->executeCommand("give -f -a sword to frank"));
    ExpectEq(1, sizeof(all_inventory(Player)));
    ExpectEq(2, sizeof(all_inventory(Receiver)));
    ExpectTrue(present(Weapon, Receiver), "Weapon on frank");
    ExpectTrue(present(Item, Receiver), "Item on frank");
    ExpectTrue(present(Chainmail, Player), "Chainmail on player");
}

/////////////////////////////////////////////////////////////////////////////
void CannotGiveZeroCoins()
{
    ExpectFalse(Player->executeCommand("give 0 coins to frank"));
    ExpectFalse(Receiver->Money());
    ExpectEq("You cannot give 0 coins.\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotGiveMoreCoinsThanUserHas()
{
    Player->addMoney(100);
    ExpectFalse(Player->executeCommand("give 110 coins to frank"));
    ExpectFalse(Receiver->Money());
    ExpectEq("You cannot give 110 coins.\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanGiveAllCoins()
{
    Player->addMoney(100);
    ExpectTrue(Player->executeCommand("give all money to frank"));
    ExpectEq(100, Receiver->Money());
    ExpectEq("You give Frank money totaling 100 in value.\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanGiveOneCoin()
{
    Player->addMoney(100);
    ExpectTrue(Player->executeCommand("give 1 coin to frank"));
    ExpectEq(99, Player->Money());
    ExpectEq(1, Receiver->Money());
    ExpectEq("You give Frank money totaling 1 in value.\n", Player->caughtMessage());

}

/////////////////////////////////////////////////////////////////////////////
void CanGiveCoin()
{
    Player->addMoney(100);
    ExpectTrue(Player->executeCommand("give coin to frank"));
    ExpectEq(99, Player->Money());
    ExpectEq(1, Receiver->Money());
    ExpectEq("You give Frank money totaling 1 in value.\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanGiveSomeCoins()
{
    Player->addMoney(100);
    ExpectTrue(Player->executeCommand("give 25 coins to frank"));
    ExpectEq(75, Player->Money());
    ExpectEq(25, Receiver->Money());
    ExpectEq("You give Frank money totaling 25 in value.\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanGiveSomeMoney()
{
    Player->addMoney(100);
    ExpectTrue(Player->executeCommand("give 100 money to frank"));
    ExpectEq(0, Player->Money());
    ExpectEq(100, Receiver->Money());
    ExpectEq("You give Frank money totaling 100 in value.\n", Player->caughtMessage());
}
