//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

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
void Init()
{
    ignoreList += ({ "BuildInventoryString" });
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
void CanExecuteLookCommand()
{
    ExpectTrue(Player->executeCommand("look"));
}

/////////////////////////////////////////////////////////////////////////////
void CanExecuteLCommand()
{
    ExpectTrue(Player->executeCommand("l"));
}

/////////////////////////////////////////////////////////////////////////////
void CanExecuteExamineCommand()
{
    ExpectTrue(Player->executeCommand("examine"));
}

/////////////////////////////////////////////////////////////////////////////
void CanExecuteExaCommand()
{
    ExpectTrue(Player->executeCommand("exa"));
}

/////////////////////////////////////////////////////////////////////////////
void CanExecuteGlanceCommand()
{
    ExpectTrue(Player->executeCommand("glance"));
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

    ExpectTrue(Player->executeCommand("look at bob"));
    ExpectEq("Bob the title-less (male) (elf)\nHe is in good shape.\nBob has a shiny blah!\n\tCarrying:\n" + 
        BuildInventoryString(items, unequipped), Player->caughtMessage());
}
