//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"
#include "/lib/include/itemFormatters.h"

object Player;

string *Slots = ({ "Primary Weapon", "Equipped Offhand", "Worn Armor", "Worn Helmet",
    "Worn Gloves", "Worn Boots", "Worn Cloak", "Worn Amulet", "Worn Belt",
    "Worn Arm Greaves", "Worn Leg Greaves", "Worn Bracers", "Worn First Ring",
    "Worn Second Ring" });

string Bar = "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n[0m";
string EquippedItem = "[0;31m| [0m[0;36m%s:%s[0m[0;%sm%s[0m%s\n";
string nothingEquipped = "[0;31m| [0m[0;36m%s:%s[0m[0;30;1mnothing[0m\n";
string UnequippedItem = "[0;31m| [0m[0;37;1m%s[0m%s\n";

/////////////////////////////////////////////////////////////////////////////
varargs string BuildInventoryString(mapping equipped, string *unequipped, int verbose)
{
    string ret = "";
    
    string showVerbose = verbose ? "   (blarg)" : "";

    if(sizeof(equipped))
    {
        ret += Bar;
        foreach(string slot in Slots)
        {
            string spacing = (strlen(slot) >= 14) ? "\t" : "\t\t";

            if(member(equipped, slot))
            {
                ret += sprintf(EquippedItem, slot, spacing, equipped[slot]["type"], equipped[slot]["data"], showVerbose);
            }
            else
            {
                ret += sprintf(nothingEquipped, slot, spacing);
            }

            if(slot == "Equipped Offhand")
            {
                ret += Bar;
            }
        }
        ret += Bar;
    }

    if(sizeof(unequipped))
    {
        foreach(string item in unequipped)
        {
            ret += sprintf(UnequippedItem, item, showVerbose);
        }

        ret += Bar;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
string PrepPlayerWithInventory()
{
    Player->Race("elf");
    Player->Gender(1);

    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("short", "Sword of Blah");
    weapon->set("user description", "##UserName## has a shiny blah!");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Player);
    weapon->equip("blah");
    mapping items = (["Primary Weapon":(["type":"37;1", "data" : "Sword of Blah"])]);

    object armor = clone_object("/lib/items/armor");
    armor->set("name", "blarg");
    armor->set("short", "Equipment of equippedness");
    armor->set("equipment locations", Gloves | Armor | ArmGreaves | LegGreaves | Boots);
    move_object(armor, Player);
    armor->equip("blarg");
    items["Worn Armor"] = (["type":"37;1", "data" : "Equipment of equippedness"]);
    items["Worn Gloves"] = (["type":"37;1", "data" : "Equipment of equippedness"]);
    items["Worn Boots"] = (["type":"37;1", "data" : "Equipment of equippedness"]);
    items["Worn Arm Greaves"] = (["type":"37;1", "data" : "Equipment of equippedness"]);
    items["Worn Leg Greaves"] = (["type":"37;1", "data" : "Equipment of equippedness"]);

    armor = clone_object("/lib/items/armor");
    armor->set("name", "f");
    armor->set("short", "Some junk");
    armor->set("equipment locations", Gloves | Armor | ArmGreaves | LegGreaves | Boots);
    move_object(armor, Player);
    string *unequipped = ({ "Some junk" });

    return BuildInventoryString(items, unequipped);
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
    Player->Name("bob");
    Player->addCommands();
    move_object(Player, clone_object("/lib/tests/support/services/mockPlayer.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpIsNotGreedy()
{
    ExpectFalse(Player->executeCommand("exam"));
    ExpectFalse(Player->executeCommand("lo"));
    ExpectFalse(Player->executeCommand("lookat"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpFailsIfInvalidFlagsPassed()
{
    ExpectFalse(Player->executeCommand("look -t bob"));
}

/////////////////////////////////////////////////////////////////////////////
void LookAtLivingShowsInventory()
{
    string expectedInventory = PrepPlayerWithInventory();

    ExpectTrue(Player->executeCommand("look at bob"));
    ExpectEq("Bob the title-less (male) (elf)\nHe is in good shape.\nBob has a shiny blah!\n\tCarrying:\n" + 
        expectedInventory, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LookAtLivingWithBriefDoesNotShowInventory()
{
    PrepPlayerWithInventory();

    ExpectTrue(Player->executeCommand("look -b at bob"));
    ExpectEq("Bob the title-less (male) (elf)\nHe is in good shape.\nBob has a shiny blah!\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LookInLivingShowsInventory()
{
    string expectedInventory = PrepPlayerWithInventory();

    ExpectTrue(Player->executeCommand("look in bob"));
    ExpectEq("Bob the title-less (male) (elf)\nHe is in good shape.\nBob has a shiny blah!\n\tCarrying:\n" +
        expectedInventory, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LookInLivingWithBriefDoesNotShowInventory()
{
    PrepPlayerWithInventory();

    ExpectTrue(Player->executeCommand("look -b in bob"));
    ExpectEq("Bob the title-less (male) (elf)\nHe is in good shape.\nBob has a shiny blah!\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LAtLivingShowsInventory()
{
    string expectedInventory = PrepPlayerWithInventory();

    ExpectTrue(Player->executeCommand("l at bob"));
    ExpectEq("Bob the title-less (male) (elf)\nHe is in good shape.\nBob has a shiny blah!\n\tCarrying:\n" +
        expectedInventory, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LAtLivingWithBriefDoesNotShowInventory()
{
    PrepPlayerWithInventory();

    ExpectTrue(Player->executeCommand("l -b at bob"));
    ExpectEq("Bob the title-less (male) (elf)\nHe is in good shape.\nBob has a shiny blah!\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LInLivingShowsInventory()
{
    string expectedInventory = PrepPlayerWithInventory();

    ExpectTrue(Player->executeCommand("l in bob"));
    ExpectEq("Bob the title-less (male) (elf)\nHe is in good shape.\nBob has a shiny blah!\n\tCarrying:\n" +
        expectedInventory, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LInLivingWithBriefDoesNotShowInventory()
{
    PrepPlayerWithInventory();

    ExpectTrue(Player->executeCommand("l -b in bob"));
    ExpectEq("Bob the title-less (male) (elf)\nHe is in good shape.\nBob has a shiny blah!\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ExaLivingShowsInventory()
{
    string expectedInventory = PrepPlayerWithInventory();

    ExpectTrue(Player->executeCommand("exa bob"));
    ExpectEq("Bob the title-less (male) (elf)\nHe is in good shape.\nBob has a shiny blah!\n\tCarrying:\n" +
        expectedInventory, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ExaLivingWithBriefDoesNotShowInventory()
{
    PrepPlayerWithInventory();

    ExpectTrue(Player->executeCommand("exa -b bob"));
    ExpectEq("Bob the title-less (male) (elf)\nHe is in good shape.\nBob has a shiny blah!\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ExamineLivingShowsInventory()
{
    string expectedInventory = PrepPlayerWithInventory();

    ExpectTrue(Player->executeCommand("examine bob"));
    ExpectEq("Bob the title-less (male) (elf)\nHe is in good shape.\nBob has a shiny blah!\n\tCarrying:\n" +
        expectedInventory, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ExamineLivingWithBriefDoesNotShowInventory()
{
    PrepPlayerWithInventory();

    ExpectTrue(Player->executeCommand("examine -b bob"));
    ExpectEq("Bob the title-less (male) (elf)\nHe is in good shape.\nBob has a shiny blah!\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GlanceAtDoesNotShowInventory()
{
    PrepPlayerWithInventory();

    ExpectTrue(Player->executeCommand("glance at bob"));
    ExpectEq("Bob the title-less (male) (elf)\nHe is in good shape.\nBob has a shiny blah!\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GlanceInDoesNotShowInventory()
{
    PrepPlayerWithInventory();

    ExpectTrue(Player->executeCommand("glance in bob"));
    ExpectEq("Bob the title-less (male) (elf)\nHe is in good shape.\nBob has a shiny blah!\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LookAtItemShowsInventory()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("blueprint", "long sword");
    weapon->set("craftsmanship", 130);
    weapon->set("short", "Sword of Blah");
    move_object(weapon, Player);
    weapon->equip("blah");

    ExpectTrue(Player->executeCommand("look at blah"));
    ExpectEq("Sword of Blah\n" + 
             sprintf(Masterwork, "This long sword is a masterwork item.\n") +
             "\n",
        Player->caughtMessage());
}