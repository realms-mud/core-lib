//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Player;
string *Slots = ({ "Primary Weapon", "Equipped Offhand", "Worn Armor", "Worn Helmet",
    "Worn Gloves", "Worn Boots", "Worn Cloak", "Worn Amulet", "Worn Belt",
    "Worn Arm Greaves", "Worn Leg Greaves", "Worn Bracers", "Worn First Ring",
    "Worn Second Ring" });

/////////////////////////////////////////////////////////////////////////////
void BuildInventory()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("short", "Sword of Blah");
    weapon.set("weapon type", "long sword");
    weapon.set("bonus attack", 5);
    weapon.set("bonus damage", 5);
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Player);
    weapon.equip("blah");
    mapping items = (["Primary Weapon":(["type":"35;1", "data" : "Sword of Blah"])]);

    move_object(clone_object("/lib/instances/items/potions/healing.c"), Player);
    move_object(clone_object("/lib/instances/items/potions/healing.c"), Player);
    move_object(clone_object("/lib/instances/items/potions/healing.c"), Player);
    move_object(clone_object("/lib/instances/items/potions/healing.c"), Player);
    move_object(clone_object("/lib/instances/items/potions/healing.c"), Player);
    move_object(clone_object("/lib/instances/items/potions/healing.c"), Player);
    move_object(clone_object("/lib/instances/items/potions/healing.c"), Player);
    move_object(clone_object("/lib/instances/items/potions/healing.c"), Player);

    move_object(clone_object("/lib/instances/items/potions/mana.c"), Player);
    move_object(clone_object("/lib/instances/items/instruments/strings/lute.c"), Player);

    object equipment = clone_object("/lib/instances/items/armor/accessories/amulet.c");
    move_object(equipment, Player);
    equipment.equip("amulet");

    for (int i = 0; i < 7; i++)
    {
        equipment = clone_object("/lib/instances/items/armor/accessories/ring.c");
        equipment.set("craftsmanship", 200);
        equipment.set("short", "A big claw thingy with a long name");
        move_object(equipment, Player);
    }

    equipment = clone_object("/lib/instances/items/armor/accessories/ring.c");
    equipment.set("bonus spirit", 1);
    equipment.set("short", "The land-loving mother-pigeon of all things");
    move_object(equipment, Player);

    equipment = clone_object("/lib/instances/items/armor/accessories/ring.c");
    equipment.set("short", "Even more stuff");
    move_object(equipment, Player);

    equipment = clone_object("/lib/instances/items/armor/accessories/ring.c");
    equipment.set("craftsmanship", 200);
    equipment.set("short", "Ring of Really Long Names");
    move_object(equipment, Player);
    equipment.equip("ring");

    equipment = clone_object("/lib/instances/items/armor/accessories/ring.c");
    equipment.set("craftsmanship", 20);
    equipment.set("short", "Ring of Shorter Names");
    move_object(equipment, Player);
    equipment.equip("second ring");

    equipment = clone_object("/lib/instances/items/armor/accessories/ring.c");
    equipment.set("short", "Cabbage");
    move_object(equipment, Player);

    equipment = clone_object("/lib/instances/items/armor/medium-armor/chainmail.c");
    equipment.set("bonus soak", 1);
    equipment.set("short", "Chainmail of Chains");
    move_object(equipment, Player);
    equipment.equip("armor");
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "BuildInventory" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("bob");
    Player.addCommands();
    move_object(Player, "/lib/tests/support/environment/fakeEnvironment.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void CanExecuteInventoryCommand()
{
    ExpectTrue(Player.executeCommand("inventory"));
}

/////////////////////////////////////////////////////////////////////////////
void CanExecuteInvenCommand()
{
    ExpectTrue(Player.executeCommand("inven"));
}

/////////////////////////////////////////////////////////////////////////////
void CanExecuteICommand()
{
    ExpectTrue(Player.executeCommand("i"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpIsNotGreedy()
{
    ExpectFalse(Player.executeCommand("invent"));
    ExpectFalse(Player.executeCommand("in"));
    ExpectFalse(Player.executeCommand("inventoryy"));
    ExpectFalse(Player.executeCommand("hi"));
    ExpectFalse(Player.executeCommand("sgjdfsdfginvent"));
    ExpectFalse(Player.executeCommand("blarginventory"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpFailsIfInvalidFlagsPassed()
{
    ExpectFalse(Player.executeCommand("inventory -t bob"));
}

/////////////////////////////////////////////////////////////////////////////
void InventoryShowsSparselyPopulatedList()
{
    Player.colorConfiguration("none");

    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("short", "Sword of Blah");
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Player);
    weapon.equip("blah");
    mapping items = (["Primary Weapon":(["type":"37;1", "data" : "Sword of Blah"])]);

    object armor = clone_object("/lib/items/armor");
    armor.set("name", "blarg");
    armor.set("short", "Equipment of equippedness");
    armor.set("equipment locations", Gloves | Armor | ArmGreaves | LegGreaves | Boots);
    move_object(armor, Player);
    armor.equip("blarg");
    items["Worn Armor"] = (["type":"37;1", "data" : "Equipment of equippedness"]);
    items["Worn Gloves"] = (["type":"37;1", "data" : "Equipment of equippedness"]);
    items["Worn Boots"] = (["type":"37;1", "data" : "Equipment of equippedness"]);
    items["Worn Arm Greaves"] = (["type":"37;1", "data" : "Equipment of equippedness"]);
    items["Worn Leg Greaves"] = (["type":"37;1", "data" : "Equipment of equippedness"]);

    armor = clone_object("/lib/items/armor");
    armor.set("name", "f");
    armor.set("short", "Some junk");
    armor.set("equipment locations", Gloves | Armor | ArmGreaves | LegGreaves | Boots);
    move_object(armor, Player);
    string *unequipped = ({ "Some junk" });

    ExpectTrue(Player.executeCommand("inventory"));
    ExpectEq("+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Wielded Weapons +=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| Primary Weapon: Sword of Blah         Offhand Weapon: nothing               |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Worn Items +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| Armor:          Equipment of equi...  Helmet:         nothing               |\n"
        "| Gloves:         Equipment of equi...  Boots:          Equipment of equi...  |\n"
        "| Cloak:          nothing               Amulet:         nothing               |\n"
        "| Belt:           nothing               Bracers:        nothing               |\n"
        "| Arm Greaves:    Equipment of equi...  Leg Greaves:    Equipment of equi...  |\n"
        "| First Ring:     nothing               Second Ring:    nothing               |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Miscellaneous Items +=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| Some junk                                                                   |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Money +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| You currently have 0 in cash on hand.                                       |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+  +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n", 
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void InventoryShowsWellCraftedItemsInGreen()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("short", "Sword of Blah");
    weapon.set("weapon type", "long sword");
    weapon.set("craftsmanship", 20);
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Player);
    weapon.equip("blah");
    mapping items = (["Primary Weapon":(["type":"32", "data" : "Sword of Blah"])]);

    ExpectTrue(Player.executeCommand("inventory"));
    ExpectSubStringMatch("32mSword of Blah",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void InventoryShowsMasterworkItemsInBoldGreen()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("short", "Sword of Blah");
    weapon.set("weapon type", "long sword");
    weapon.set("craftsmanship", 50);
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Player);
    weapon.equip("blah");
    mapping items = (["Primary Weapon":(["type":"32;1", "data" : "Sword of Blah"])]);

    ExpectTrue(Player.executeCommand("inventory"));
    ExpectSubStringMatch("32;1mSword of Blah",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void InventoryShowsMagicItemsInMagenta()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("short", "Sword of Blah");
    weapon.set("weapon type", "long sword");
    weapon.set("bonus attack", 1);
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Player);
    weapon.equip("blah");
    mapping items = (["Primary Weapon":(["type":"35", "data" : "Sword of Blah"])]);

    ExpectTrue(Player.executeCommand("inventory"));
    ExpectSubStringMatch("35mSword of Blah",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void InventoryShowsPowerfulMagicItemsInBoldMagenta()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("short", "Sword of Blah");
    weapon.set("weapon type", "long sword");
    weapon.set("bonus attack", 5);
    weapon.set("bonus damage", 5);
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Player);
    weapon.equip("blah");
    mapping items = (["Primary Weapon":(["type":"35;1", "data" : "Sword of Blah"])]);

    ExpectTrue(Player.executeCommand("inventory"));
    ExpectSubStringMatch("35;1mSword of Blah",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanExecuteVerboseInventory()
{
    Player.colorConfiguration("none");
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("short", "Sword of Blah");
    weapon.set("weapon type", "long sword");
    weapon.set("bonus attack", 5);
    weapon.set("bonus damage", 5);
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Player);
    weapon.equip("blah");
    mapping items = (["Primary Weapon":(["type":"35;1", "data" : "Sword of Blah"])]);

    ExpectTrue(Player.executeCommand("inventory -v"));
    ExpectEq("+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Wielded Weapons +=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| Primary Weapon: Sword of Blah         Offhand Weapon: nothing               |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Worn Items +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| Armor:          nothing               Helmet:         nothing               |\n"
        "| Gloves:         nothing               Boots:          nothing               |\n"
        "| Cloak:          nothing               Amulet:         nothing               |\n"
        "| Belt:           nothing               Bracers:        nothing               |\n"
        "| Arm Greaves:    nothing               Leg Greaves:    nothing               |\n"
        "| First Ring:     nothing               Second Ring:    nothing               |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Money +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| You currently have 0 in cash on hand.                                       |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+  +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n",
        Player.caughtMessage());

}

/////////////////////////////////////////////////////////////////////////////
void InventoryShowsCorrectAmountOfMoney()
{
    Player.colorConfiguration("none");
    Player.addMoney(123456);
    ExpectTrue(Player.executeCommand("inventory"));
    ExpectSubStringMatch("123456", Player.caughtMessage());
    ExpectEq("+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Money +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| You currently have 123456 in cash on hand.                                  |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+  +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void InventoryShowsDeckedOutCorrectlyWithNoColor()
{
    Player.colorConfiguration("none");
    BuildInventory();

    ExpectTrue(Player.executeCommand("inventory"));
    ExpectEq("+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Wielded Weapons +=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| Primary Weapon: Sword of Blah         Offhand Weapon: nothing               |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Worn Items +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| Armor:          Chainmail of Chains   Helmet:         nothing               |\n"
        "| Gloves:         nothing               Boots:          nothing               |\n"
        "| Cloak:          nothing               Amulet:         Amulet                |\n"
        "| Belt:           nothing               Bracers:        nothing               |\n"
        "| Arm Greaves:    nothing               Leg Greaves:    nothing               |\n"
        "| First Ring:     Ring of Really Lo...  Second Ring:    Ring of Shorter N...  |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Miscellaneous Items +=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| Cabbage                  Even more stuff          The land-loving mothe...  |\n"
        "| [7] A big claw thingy... Lute                     Mana Potion               |\n"
        "| [8] Healing Potion                                                          |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Money +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| You currently have 0 in cash on hand.                                       |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+  +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n", 
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void InventoryShowsDeckedOutCorrectlyWithColor()
{
    Player.colorConfiguration("3-bit");
    BuildInventory();

    ExpectTrue(Player.executeCommand("inventory"));
    ExpectEq("\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Wielded Weapons +=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;31m|\x1b[0m \x1b[0;36mPrimary Weapon: \x1b[0m\x1b[0;35;1mSword of Blah        \x1b[0m \x1b[0;36mOffhand Weapon: \x1b[0m\x1b[0;30;1mnothing              \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Worn Items +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;31m|\x1b[0m \x1b[0;36mArmor:          \x1b[0m\x1b[0;35mChainmail of Chains  \x1b[0m \x1b[0;36mHelmet:         \x1b[0m\x1b[0;30;1mnothing              \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m \x1b[0;36mGloves:         \x1b[0m\x1b[0;30;1mnothing              \x1b[0m \x1b[0;36mBoots:          \x1b[0m\x1b[0;30;1mnothing              \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m \x1b[0;36mCloak:          \x1b[0m\x1b[0;30;1mnothing              \x1b[0m \x1b[0;36mAmulet:         \x1b[0m\x1b[0;37;1mAmulet               \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m \x1b[0;36mBelt:           \x1b[0m\x1b[0;30;1mnothing              \x1b[0m \x1b[0;36mBracers:        \x1b[0m\x1b[0;30;1mnothing              \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m \x1b[0;36mArm Greaves:    \x1b[0m\x1b[0;30;1mnothing              \x1b[0m \x1b[0;36mLeg Greaves:    \x1b[0m\x1b[0;30;1mnothing              \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m \x1b[0;36mFirst Ring:     \x1b[0m\x1b[0;32;1mRing of Really Lo... \x1b[0m \x1b[0;36mSecond Ring:    \x1b[0m\x1b[0;32mRing of Shorter N... \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Miscellaneous Items +=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;31m|\x1b[0m \x1b[0;37;1mCabbage                  \x1b[0m\x1b[0;37;1mEven more stuff          \x1b[0m\x1b[0;35mThe land-loving mothe... \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m \x1b[0;32;1m[7] A big claw thingy... \x1b[0m\x1b[0;37;1mLute                     \x1b[0m\x1b[0;37;1mMana Potion              \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m \x1b[0;37;1m[8] Healing Potion       \x1b[0m                                                   \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Money +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;31m|\x1b[0m \x1b[0;36mYou currently have \x1b[0m\x1b[0;33m0\x1b[0m\x1b[0;36m in cash on hand.                                      \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+  +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m",
        Player.caughtMessage());
}
