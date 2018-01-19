//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Player;
object Item;
object Room;
object Chainmail;
object Weapon;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Room = clone_object("/lib/tests/support/environment/fakeCombatRoom.c");

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
    move_object(Item, Room);

    Chainmail = clone_object("/lib/items/armor.c");
    Chainmail->set("armor type", "chainmail");
    Chainmail->set("name", "chainmail");
    Chainmail->set("equipment locations", Armor);

    Weapon = clone_object("/lib/items/weapon.c");
    Weapon->set("short", "sword");
    Weapon->set("Weapon type", "long sword");
    Weapon->set("aliases", ({ "sword" }));

    move_object(Chainmail, Room);
    move_object(Weapon, Room);
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
    ExpectFalse(Player->executeCommand("begetify"), "begetify");
    ExpectFalse(Player->executeCommand("getit"), "getit");
    ExpectFalse(Player->executeCommand("pick upper"), "pick upper");
}

/////////////////////////////////////////////////////////////////////////////
void CannotGetLivingObjects()
{
    object bystander = clone_object("/lib/realizations/npc.c");
    bystander->Name("earl");
    move_object(bystander, Room);

    ExpectEq(0, sizeof(all_inventory(Player)));
    ExpectFalse(Player->executeCommand("get earl"));
    ExpectEq(0, sizeof(all_inventory(Player)));

    destruct(bystander);
}

/////////////////////////////////////////////////////////////////////////////
void GetMovesItemFromEnvironmentToPerson()
{
    ExpectEq(0, sizeof(all_inventory(Player)));
    ExpectTrue(Player->executeCommand("get sword"));
    ExpectEq(1, sizeof(all_inventory(Player)));
}

/////////////////////////////////////////////////////////////////////////////
void GetDisplaysCorrectMessage()
{
    object observer = clone_object("/lib/tests/support/services/mockPlayer.c");
    move_object(observer, Room);
    ExpectEq(0, sizeof(all_inventory(Player)));
    ExpectTrue(Player->executeCommand("get sword 2"));
    ExpectEq(1, sizeof(all_inventory(Player)));
    ExpectEq("Bob picks up Sword of Weasels.\n", observer->caughtMessage());
    ExpectEq("You pick up Sword of Weasels.\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PickUpMovesItemFromEnvironmentToPerson()
{
    ExpectEq(0, sizeof(all_inventory(Player)));
    ExpectTrue(Player->executeCommand("pick up sword"));
    ExpectEq(1, sizeof(all_inventory(Player)));
}

/////////////////////////////////////////////////////////////////////////////
void GetAllMovesAllMovableItemsFromPersonToEnvironment()
{
    ExpectEq(0, sizeof(all_inventory(Player)));
    ExpectTrue(Player->executeCommand("get all"));
    ExpectEq(3, sizeof(all_inventory(Player)));
}

/////////////////////////////////////////////////////////////////////////////
void PickUpAllMovesAllMovableItemsFromPersonToEnvironment()
{
    ExpectEq(0, sizeof(all_inventory(Player)));
    ExpectTrue(Player->executeCommand("pick up all"));
    ExpectEq(3, sizeof(all_inventory(Player)));
}

/////////////////////////////////////////////////////////////////////////////
void AFlagGetsAllMovableItemsThatMatchId()
{
    ExpectEq(0, sizeof(all_inventory(Player)));
    ExpectTrue(Player->executeCommand("get -a sword"));
    ExpectEq(2, sizeof(all_inventory(Player)));
    ExpectTrue(present(Weapon, Player));
    ExpectTrue(present(Item, Player));
    ExpectTrue(present(Chainmail, Room));
}

/////////////////////////////////////////////////////////////////////////////
void AFlagPicksUpAllMovableItemsThatMatchId()
{
    ExpectEq(0, sizeof(all_inventory(Player)));
    ExpectTrue(Player->executeCommand("pick up -a sword"));
    ExpectEq(2, sizeof(all_inventory(Player)));
    ExpectTrue(present(Weapon, Player));
    ExpectTrue(present(Item, Player));
    ExpectTrue(present(Chainmail, Room));
}

/////////////////////////////////////////////////////////////////////////////
void NoAFlagGetsOnlyTopMovableItemThatMatchesId()
{
    ExpectEq(0, sizeof(all_inventory(Player)));
    ExpectTrue(Player->executeCommand("get sword"));
    ExpectEq(1, sizeof(all_inventory(Player)));
    ExpectTrue(present(Weapon, Player));
    ExpectTrue(present(Item, Room));
    ExpectTrue(present(Chainmail, Room));
}

/////////////////////////////////////////////////////////////////////////////
void NoAFlagPicksUpOnlyTopMovableItemThatMatchesId()
{
    ExpectEq(0, sizeof(all_inventory(Player)));
    ExpectTrue(Player->executeCommand("pick up sword"));
    ExpectEq(1, sizeof(all_inventory(Player)));
    ExpectTrue(present(Weapon, Player));
    ExpectTrue(present(Item, Room));
    ExpectTrue(present(Chainmail, Room));
}

/////////////////////////////////////////////////////////////////////////////
void CannotPickUpItemsIfMaxCarryExceeded()
{
    Chainmail->set("weight", 50);
    ExpectEq(0, sizeof(all_inventory(Player)));
    ExpectTrue(Player->executeCommand("get chainmail"));
    ExpectEq(0, sizeof(all_inventory(Player)));
    ExpectTrue(present(Weapon, Room));
    ExpectTrue(present(Item, Room));
    ExpectTrue(present(Chainmail, Room));
    ExpectEq("You cannot carry any more weight.\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GetFromLivingFails()
{
    object observer = clone_object("/lib/tests/support/services/mockPlayer.c");
    observer->Name("george");

    move_object(observer, Room);
    move_object(Weapon, observer);

    ExpectFalse(Player->executeCommand("get sword from george"));
}

/////////////////////////////////////////////////////////////////////////////
void CanGetFromEnvironmentalObject()
{
    move_object(Weapon, load_object("/lib/tests/support/environment/fakeChest.c"));
    ExpectEq(0, sizeof(all_inventory(Player)));
    ExpectTrue(Player->executeCommand("get sword from chest"));
    ExpectEq(1, sizeof(all_inventory(Player)));
}

/////////////////////////////////////////////////////////////////////////////
void CanGetFromContainerItems()
{
    object box = clone_object("/lib/tests/support/items/testContainer.c");
    move_object(Weapon, box);
    move_object(box, Room);
    ExpectEq(0, sizeof(all_inventory(Player)));
    ExpectTrue(Player->executeCommand("get sword from box"));
    ExpectEq(1, sizeof(all_inventory(Player)));
    destruct(box);
}

/////////////////////////////////////////////////////////////////////////////
void CanGetFromContainerItemsWhenContainerInInventory()
{
    object box = clone_object("/lib/tests/support/items/testContainer.c");
    move_object(Weapon, box);
    move_object(box, Player);
    ExpectEq(1, sizeof(all_inventory(Player)));
    ExpectTrue(Player->executeCommand("get sword from box"));
    ExpectEq(2, sizeof(all_inventory(Player)));
    destruct(box);
}