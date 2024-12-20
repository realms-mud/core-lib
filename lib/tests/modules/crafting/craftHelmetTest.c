//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Selector;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/modules/crafting/craftItemSelector.c");
    Selector.setType("armor");
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("bob");
    Player.addCommands();

    Player.Wis(50);
    Player.Str(50);
    Player.Int(50);
    Player.addSkillPoints(500);
    Player.advanceSkill("sewing", 10);
    Player.advanceSkill("wood crafting", 10);
    Player.advanceSkill("metal crafting", 50);
    Player.advanceSkill("gem crafting", 20);
    Player.advanceSkill("armorer", 10);
    Player.advanceSkill("blacksmithing", 10);
    Player.advanceSkill("leatherworking", 10);
    Player.advanceSkill("chemistry", 10);
    Player.advanceSkill("physics", 10);
    Player.advanceSkill("sculpture", 10);
    Player.addResearchPoints(20);
    Player.colorConfiguration("none");

    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/armor/craftHelmet.c"));
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftCommonMetal.c"));
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftUncommonMetal.c"));
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftAlloy.c"));
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftRareMetal.c"));
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftPreciousMetal.c"));
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftMythicMetal.c"));
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftGems.c"));
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftRareGems.c"));
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftLeather.c"));
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftExoticMaterials.c"));

    object material = clone_object("/lib/instances/items/materials/textile/silk.c");
    material.set("quantity", 15);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/admantite.c");
    material.set("quantity", 15);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/gold.c");
    material.set("quantity", 15);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/crystal/ruby.c");
    material.set("quantity", 15);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/leather/boar-leather.c");
    material.set("quantity", 15);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/skeletal/ivory.c");
    material.set("quantity", 15);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/plumage/peacock-feather.c");
    material.set("quantity", 15);
    move_object(material, Player);

    move_object(Selector, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Selector);
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingClothingDisplaysClothingMenu()
{
    Selector.initiateSelector(Player);
    command("1", Player);

    ExpectEq("Craft Accessory - From this menu, you can craft items:\n"
        "    [1]  - Amulet              (P)      [2]  - Belt                (P)  \n"
        "    [3]  - Boots               (P)      [4]  - Bracelet            (P)  \n"
        "    [5]  - Bracers             (P)      [6]  - Circlet             (P)  \n"
        "    [7]  - Coif                         [8]  - Crown               (P)  \n"
        "    [9]  - Diadem              (P)      [10] - Gauntlets           (P)  \n"
        "    [11] - Gloves              (P)      [12] - Hat                 (P)  \n"
        "    [13] - Helm                         [14] - Helmet                   \n"
        "    [15] - Necklace            (P)      [16] - Ring                (P)  \n"
        "    [17] - Sabaton             (P)      [18] - Sandals             (P)  \n"
        "    [19] - Sash                (P)      [20] - Shoes               (P)  \n"
        "    [21] - Tiara               (P)      [22] - Exit Craft Accessory Menu\n"
        "You must select a number from 1 to 22.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "P denotes unrealized prerequisites.\n"
        "M denotes that proper quantities of the material requirements are missing.\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingHelmDisplaysHelmMenu()
{
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/armor/craftClothing.c"));
    Selector.initiateSelector(Player);
    command("1", Player);
    command("13", Player);

    ExpectEq("Craft Helm - From this menu, you will select the components "
        "that will be used\nto craft your helm. The relative statistics "
        "for the item you are creating are:\n\n"
        "    Material: none selected\n"
        "    Weight: 1\n"
        "\n"
        "    [1] - Select Crest        \n"
        "    [2] - Select Helm design  \n"
        "    [3] - Enchant Helm        \n"
        "    [4] - Give helm a name    \n"
        "    [5] - Give helm a special description\n"
        "    [6] - Craft Selected Helm \n"
        "    [7] - Exit Craft Helm Menu\n"
        "You must select a number from 1 to 7.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "(*) denotes that a specific component type has been chosen.\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingSelectMaterialDisplaysMaterialMenu()
{
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/armor/craftClothing.c"));
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftTextiles.c"));
    Player.advanceSkill("weaving and beadwork", 10);
    Selector.initiateSelector(Player);
    command("1", Player);
    command("13", Player);
    command("1", Player);

    ExpectEq("Craft Crest - Select materials and the type of crest you will craft:\n"
        "    [1]  - Select crystal      N/A          [2]  - Select metal        N/A      \n"
        "    [3]  - Select plumage      N/A          [4]  - Select skeletal     N/A      \n"
        "    [5]  - Antlered                         [6]  - Horned                       \n"
        "    [7]  - Ornate Boar                      [8]  - Ornate Dragon                \n"
        "    [9]  - Ornate Griffin                   [10] - Ornate Serpent               \n"
        "    [11] - Ornate Wolf                      [12] - Plume                        \n"
        "    [13] - Simple Crest                     [14] - Winged                       \n"
        "    [15] - Confirm Selection                [16] - Cancel Selection             \n"
        "You must select a number from 1 to 16.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "<material> denotes a selected material.\n"
        "(*) denotes that a specific component type has been chosen.\n",
        Player.caughtMessage());

    command("14", Player);

    ExpectEq("Craft Crest - Select materials and the type of crest you will craft:\n"
        "    [1]  - Select crystal      N/A          [2]  - Select metal        none     \n" 
        "    [3]  - Select plumage      none         [4]  - Select skeletal     N/A      \n"
        "    [5]  - Antlered                         [6]  - Horned                       \n"
        "    [7]  - Ornate Boar                      [8]  - Ornate Dragon                \n"
        "    [9]  - Ornate Griffin                   [10] - Ornate Serpent               \n"  
        "    [11] - Ornate Wolf                      [12] - Plume                        \n"     
        "    [13] - Simple Crest                     [14] - Winged                 (*)   \n"      
        "    [15] - Confirm Selection                [16] - Cancel Selection             \n"        
        "You must select a number from 1 to 16.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "<material> denotes a selected material.\n"
        "(*) denotes that a specific component type has been chosen.\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingMaterialUpdatesRingMenu()
{
    Selector.initiateSelector(Player);
    command("1", Player);
    command("13", Player);
    command("1", Player);
    command("14", Player);
    command("3", Player);

    ExpectSubStringMatch("Peacock feather",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanCraftItemWithBothPrimaryMaterialAndComponent()
{
    Selector.initiateSelector(Player);
    command("1", Player);
    command("13", Player);
    command("1", Player);
    command("14", Player);
    command("3", Player);
    command("31", Player);
    command("2", Player);
    command("16", Player);
    command("15", Player);
    command("2", Player);
    command("3", Player);
    command("1", Player);
    command("3", Player);
    command("2", Player);
    command("1", Player);
    command("21", Player);
    command("6", Player);

    ExpectSubStringMatch("This is a helm. The crest is a pair of gold wings covered in peacock feather.*"
        "that juts out from each temple. The helm design is a curved admantite skull.*"
        "piece formed to wrap around the user's head. It has two hinged cheek-pieces.*"
        "that lock in the front over the chin and a visor on a double pivot, one to.*"
        "each side of the skull. The interior is padded with boar leather", 
        present("helm", Player).long());
}
