//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Player;
object Environment;
object Dictionary;

string *Slots = ({ "Primary Weapon", "Equipped Offhand", "Worn Armor", "Worn Helmet",
    "Worn Gloves", "Worn Boots", "Worn Cloak", "Worn Amulet", "Worn Belt",
    "Worn Arm Greaves", "Worn Leg Greaves", "Worn Bracers", "Worn First Ring",
    "Worn Second Ring" });

/////////////////////////////////////////////////////////////////////////////
string PrepPlayerWithInventory()
{
    Player.Race("elf");
    Player.Gender("male");
    Player.hitPoints(Player.maxHitPoints());
    Player.colorConfiguration("none");

    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("short", "Sword of Blah");
    weapon.set("user description", "##UserName## has a shiny blah!");
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

    return "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Wielded Weapons +=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
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
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+  +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n";
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "BuildInventoryString", "PrepPlayerWithInventory" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("bob");
    Player.addCommands();
    Player.Str(10);
    Player.Dex(10);
    Player.Con(10);
    Player.Int(10);
    Player.Wis(10);
    Player.hitPoints(30);
    Player.colorConfiguration("none");

    Dictionary = load_object("/lib/dictionaries/environmentDictionary.c");
    Dictionary.setYear(1);
    Dictionary.setDay(92);
    Dictionary.timeOfDay("noon");

    Environment = clone_object("/lib/tests/support/environment/testEnvironment.c");
    Environment.testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment.testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    move_object(Player, Environment);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Environment);
    destruct(Dictionary);
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpIsNotGreedy()
{
    ExpectFalse(Player.executeCommand("exam"));
    ExpectFalse(Player.executeCommand("lo"));
    ExpectFalse(Player.executeCommand("lookat"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpFailsIfInvalidFlagsPassed()
{
    ExpectFalse(Player.executeCommand("look -t bob"));
}

/////////////////////////////////////////////////////////////////////////////
void LookAtLivingShowsInventory()
{
    string expectedInventory = PrepPlayerWithInventory();

    ExpectTrue(Player.executeCommand("look at bob"));
    ExpectEq("Bob the title-less (male)"
        " (elf)\nHe is in good shape.\n"
        "Bob has a shiny blah!\n    Carrying:\n" + 
        expectedInventory, Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LookAtLivingWithBriefDoesNotShowInventory()
{
    PrepPlayerWithInventory();

    ExpectTrue(Player.executeCommand("look -b at bob"));
    ExpectEq("Bob the title-less (male)"
        " (elf)\nHe is in good shape.\n"
        "Bob has a shiny blah!\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LookInLivingShowsInventory()
{
    string expectedInventory = PrepPlayerWithInventory();

    ExpectTrue(Player.executeCommand("look in bob"));
    ExpectEq("Bob the title-less (male)"
        " (elf)\nHe is in good shape.\n"
        "Bob has a shiny blah!\n    Carrying:\n" +
        expectedInventory, Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LookInLivingWithBriefDoesNotShowInventory()
{
    PrepPlayerWithInventory();

    ExpectTrue(Player.executeCommand("look -b in bob"));
    ExpectEq("Bob the title-less (male)"
        " (elf)\nHe is in good shape.\n"
        "Bob has a shiny blah!\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LAtLivingShowsInventory()
{
    string expectedInventory = PrepPlayerWithInventory();

    ExpectTrue(Player.executeCommand("l at bob"));
    ExpectEq("Bob the title-less (male)"
        " (elf)\nHe is in good shape.\n"
        "Bob has a shiny blah!\n    Carrying:\n" +
        expectedInventory, Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LAtLivingWithBriefDoesNotShowInventory()
{
    PrepPlayerWithInventory();

    ExpectTrue(Player.executeCommand("l -b at bob"));
    ExpectEq("Bob the title-less (male)"
        " (elf)\nHe is in good shape.\n"
        "Bob has a shiny blah!\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LInLivingShowsInventory()
{
    string expectedInventory = PrepPlayerWithInventory();

    ExpectTrue(Player.executeCommand("l in bob"));
    ExpectEq("Bob the title-less (male)"
        " (elf)\nHe is in good shape.\n"
        "Bob has a shiny blah!\n    Carrying:\n" +
        expectedInventory, Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LInLivingWithBriefDoesNotShowInventory()
{
    PrepPlayerWithInventory();

    ExpectTrue(Player.executeCommand("l -b in bob"));
    ExpectEq("Bob the title-less (male)"
        " (elf)\nHe is in good shape.\n"
        "Bob has a shiny blah!\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ExaLivingShowsInventory()
{
    string expectedInventory = PrepPlayerWithInventory();

    ExpectTrue(Player.executeCommand("exa bob"));
    ExpectEq("Bob the title-less (male)"
        " (elf)\nHe is in good shape.\n"
        "Bob has a shiny blah!\n    Carrying:\n" +
        expectedInventory, Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ExaLivingWithBriefDoesNotShowInventory()
{
    PrepPlayerWithInventory();

    ExpectTrue(Player.executeCommand("exa -b bob"));
    ExpectEq("Bob the title-less (male)"
        " (elf)\nHe is in good shape.\n"
        "Bob has a shiny blah!\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ExamineLivingShowsInventory()
{
    string expectedInventory = PrepPlayerWithInventory();

    ExpectTrue(Player.executeCommand("examine bob"));
    ExpectEq("Bob the title-less (male)"
        " (elf)\nHe is in good shape.\n"
        "Bob has a shiny blah!\n    Carrying:\n" +
        expectedInventory, Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ExamineLivingWithBriefDoesNotShowInventory()
{
    PrepPlayerWithInventory();

    ExpectTrue(Player.executeCommand("examine -b bob"));
    ExpectEq("Bob the title-less (male)"
        " (elf)\nHe is in good shape.\n"
        "Bob has a shiny blah!\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GlanceAtDoesNotShowInventory()
{
    PrepPlayerWithInventory();

    ExpectTrue(Player.executeCommand("glance at bob"));
    ExpectEq("Bob the title-less (male)"
        " (elf)\nHe is in good shape.\n"
        "Bob has a shiny blah!\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GlanceInDoesNotShowInventory()
{
    PrepPlayerWithInventory();

    ExpectTrue(Player.executeCommand("glance in bob"));
    ExpectEq("Bob the title-less (male)"
        " (elf)\nHe is in good shape.\n"
        "Bob has a shiny blah!\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LookAtItemShowsDetails()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("weapon type", "long sword");
    weapon.set("short", "Sword of Blah");
    move_object(weapon, Player);
    weapon.equip("blah");

    Player.addSkillPoints(100);
    Player.advanceSkill("long sword", 6);

    ExpectTrue(command("look at blah", Player));
    ExpectEq("This is a sword with a blade that is about 40 inches (100 cm) long.\n" + 
        "This long sword is typical for its type.\n"
        "    Material: Iron\n"
        "    Attack: 8 to 108\n"
        "    Damage: 9 to 12\n"
        "    Defense: 2 to 3\n"
        "    Encumberance: 2\n"
        "    Weight: 5\n\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LookAtNonexistentThingReturnsFailureMessage()
{
    ExpectTrue(Player.executeCommand("look at llama"));
    ExpectSubStringMatch("There is no 'llama' here.",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LookWithoutArgsShowsEnvironment()
{
    ExpectTrue(Player.executeCommand("look"));
    ExpectSubStringMatch("a deciduous forest. To the north.*Bob",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanLookAtEnvironmentElements()
{
    ExpectTrue(Player.executeCommand("look at oak"));
    ExpectSubStringMatch("many majestic oaks with branches laden with acorns",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanOnlyLookAtEnvironmentElementsWhenInCorrectState()
{
    ExpectTrue(Player.executeCommand("look at charred stumps"));
    ExpectSubStringMatch("There is no 'charred stumps' here.",
        Player.caughtMessage());

    Environment.currentState("deadified");
    ExpectTrue(Player.executeCommand("look at charred stumps"));
    ExpectSubStringMatch("You see many charred tree stumps.",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LookWhenBlindFailsWithBlindMessage()
{
    ExpectTrue(Player.addTrait("/lib/instances/traits/diseases/cataracts.c"));
    ExpectTrue(Player.executeCommand("look"));
    ExpectEq("You are blind.\n", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LookWhenDarkFailsWithDarkMessage()
{
    move_object(Player, "/lib/tests/support/environment/darkRoom.c");

    ExpectTrue(Player.executeCommand("look"));
    ExpectEq("It is too dark.\n", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LookWhenDarkSucceedsWhenUserHasDarkvision()
{
    object elf = clone_object("/lib/tests/support/services/mockPlayer.c");
    elf.Name("gertrude");
    elf.Gender("female");
    elf.Race("elf");
    move_object(elf, environment(Player));

    object dictionary = load_object("/lib/dictionaries/environmentDictionary.c");
    dictionary.timeOfDay("midnight");
    Player.addTrait("/lib/tests/support/traits/testDarkvisionTrait.c");
    command("look", Player);

    ExpectSubStringMatch("a deciduous forest. To the north.*Gertrude",
        Player.caughtMessage());

    destruct(elf);
    destruct(dictionary);
}

/////////////////////////////////////////////////////////////////////////////
void LookWhenDarkShowsLifeSignaturesWithInfravision()
{
    object elf = clone_object("/lib/tests/support/services/mockPlayer.c");
    elf.Name("gertrude");
    elf.Gender("female");
    elf.Race("elf");
    move_object(elf, environment(Player));

    object dictionary = load_object("/lib/dictionaries/environmentDictionary.c");
    dictionary.timeOfDay("midnight");
    Player.addTrait("/lib/tests/support/traits/testInfravisionTrait.c");
    command("look", Player);

    ExpectSubStringMatch("You can see objects faintly glowing in red.*A "
        "female elf", Player.caughtMessage());

    destruct(elf);
    destruct(dictionary);
}

/////////////////////////////////////////////////////////////////////////////
void LookWhenDarkDoesNotShowEtherealSignaturesWithInfravision()
{
    move_object(Player, "/lib/tests/support/environment/infraRoom.c");

    object elf = clone_object("/lib/tests/support/services/mockPlayer.c");
    elf.Name("gertrude");
    elf.Gender("female");
    elf.Race("elf");
    move_object(elf, environment(Player));

    Player.addTrait("/lib/tests/support/traits/testInfravisionTrait.c");
    Player.addTrait("/lib/tests/support/traits/testEtherealTrait.c");
    elf.addTrait("/lib/tests/support/traits/testEtherealTrait.c");
    ExpectTrue(Player.executeCommand("look"));
    ExpectEq("It is too dark.\n", Player.caughtMessage());

    destruct(elf);
}

/////////////////////////////////////////////////////////////////////////////
void LookWhenDarkDoesNotShowUndeadSignaturesWithInfravision()
{
    move_object(Player, "/lib/tests/support/environment/infraRoom.c");

    object elf = clone_object("/lib/tests/support/services/mockPlayer.c");
    elf.Name("gertrude");
    elf.Gender("female");
    elf.Race("elf");
    move_object(elf, environment(Player));

    Player.addTrait("/lib/tests/support/traits/testInfravisionTrait.c");
    Player.addTrait("/lib/tests/support/traits/testUndeadTrait.c");
    elf.addTrait("/lib/tests/support/traits/testUndeadTrait.c");
    ExpectTrue(Player.executeCommand("look"));
    ExpectEq("It is too dark.\n", Player.caughtMessage());

    destruct(elf);
}

/////////////////////////////////////////////////////////////////////////////
void LooksSupportsColorsAndUnicode()
{
    string expectedInventory = PrepPlayerWithInventory();
    Player.colorConfiguration("8-bit");
    Player.charsetConfiguration("unicode");

    ExpectTrue(Player.executeCommand("l at bob"));
    ExpectEq("\x1b[0;38;5;190mBob the title-less\x1b[0m\x1b[0;38;5;238m (male)\x1b[0m\x1b[0;38;5;2m (elf)\x1b[0m\n"
        "\x1b[0;38;5;9;1mHe is in good shape.\n"
        "\x1b[0mBob has a shiny blah!\n"
        "\x1b[0;38;5;80m    Carrying:\n"
        "\x1b[0m\x1b[0;38;5;124m\u2554\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2561 Wielded Weapons \u255e\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2557\n"
        "\x1b[0m\x1b[0;38;5;124m\u2551\x1b[0m \x1b[0;38;5;80mPrimary Weapon: \x1b[0m\x1b[0;38;5;231;1mSword of Blah        \x1b[0m \x1b[0;38;5;80mOffhand Weapon: \x1b[0m\x1b[0;38;5;238;1mnothing              \x1b[0m \x1b[0;38;5;124m\u2551\x1b[0m\n"
        "\x1b[0;38;5;124m\u2560\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2561 Worn Items \u255e\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2563\n"
        "\x1b[0m\x1b[0;38;5;124m\u2551\x1b[0m \x1b[0;38;5;80mArmor:          \x1b[0m\x1b[0;38;5;231;1mEquipment of equi... \x1b[0m \x1b[0;38;5;80mHelmet:         \x1b[0m\x1b[0;38;5;238;1mnothing              \x1b[0m \x1b[0;38;5;124m\u2551\x1b[0m\n"
        "\x1b[0;38;5;124m\u2551\x1b[0m \x1b[0;38;5;80mGloves:         \x1b[0m\x1b[0;38;5;231;1mEquipment of equi... \x1b[0m \x1b[0;38;5;80mBoots:          \x1b[0m\x1b[0;38;5;231;1mEquipment of equi... \x1b[0m \x1b[0;38;5;124m\u2551\x1b[0m\n"
        "\x1b[0;38;5;124m\u2551\x1b[0m \x1b[0;38;5;80mCloak:          \x1b[0m\x1b[0;38;5;238;1mnothing              \x1b[0m \x1b[0;38;5;80mAmulet:         \x1b[0m\x1b[0;38;5;238;1mnothing              \x1b[0m \x1b[0;38;5;124m\u2551\x1b[0m\n"
        "\x1b[0;38;5;124m\u2551\x1b[0m \x1b[0;38;5;80mBelt:           \x1b[0m\x1b[0;38;5;238;1mnothing              \x1b[0m \x1b[0;38;5;80mBracers:        \x1b[0m\x1b[0;38;5;238;1mnothing              \x1b[0m \x1b[0;38;5;124m\u2551\x1b[0m\n"
        "\x1b[0;38;5;124m\u2551\x1b[0m \x1b[0;38;5;80mArm Greaves:    \x1b[0m\x1b[0;38;5;231;1mEquipment of equi... \x1b[0m \x1b[0;38;5;80mLeg Greaves:    \x1b[0m\x1b[0;38;5;231;1mEquipment of equi... \x1b[0m \x1b[0;38;5;124m\u2551\x1b[0m\n"
        "\x1b[0;38;5;124m\u2551\x1b[0m \x1b[0;38;5;80mFirst Ring:     \x1b[0m\x1b[0;38;5;238;1mnothing              \x1b[0m \x1b[0;38;5;80mSecond Ring:    \x1b[0m\x1b[0;38;5;238;1mnothing              \x1b[0m \x1b[0;38;5;124m\u2551\x1b[0m\n"
        "\x1b[0;38;5;124m\u2560\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2561 Miscellaneous Items \u255e\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2563\n"
        "\x1b[0m\x1b[0;38;5;124m\u2551\x1b[0m \x1b[0;38;5;231;1mSome junk                \x1b[0m                                                   \x1b[0;38;5;124m\u2551\x1b[0m\n"
        "\x1b[0;38;5;124m\u255a\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2561  \u255e\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u255d\n"
        "\x1b[0m",
        Player.caughtMessage());
}
