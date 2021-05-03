//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Selector;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/modules/domains/buildComponentSelector.c");
    Selector.setLocation("argalach castle");
    Selector.setConstructionData((["type": "keep", "name": "stone keep"]));

    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("bob");
    Player.addCommands();
    Player.colorConfiguration("none");
    Player.charsetConfiguration("ascii");
    Player.addPlayerHolding("argalach castle");

    move_object(Selector, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Selector);
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelMenuWithoutAnyPrereqsMetDisplaysCorrectly()
{
    Selector.initiateSelector(Player);

    ExpectEq("Building Projects - Stone Keep:\n"
        "From this menu, you can initiate, modify, or abort projects in your holdings\n"
        "at Argalach Castle.\n\n"
        "Layout:                                                                         \n"
        "+=======+                       ......            .........            ......   \n"
        "| +---+ |                       .    ..............       ..............    .   \n"
        "| |   | |                       .     .?.         .........         .?.     .   \n"
        "| +---+ |                       ..    ...                           ...    ..   \n"
        "+=======+                        . ..    ......      ...      ......    .. .    \n"
        "Completion time: 1000            . ?.    .    ........ ........    .    .? .    \n"
        "                                 . ..    .     .?.         .?.     .    .. .    \n"
        "Stone Battlement:                .       ..    ...         ...    ..       .    \n"
        "    <select>                     .        . ..                 .. .        .    \n"
        "Central Stone Tower:            ....      . ?.    .........    .? .      ....   \n"
        "    <select>                    .  .      . ..    .       .    .. .      .  .   \n"
        "Main Stone Keep:                .  .     ...      .       .      ...     .  .   \n"
        "    <select>                    .  .     ...      .       .      ...     .  .   \n"
        "                                .  .      . ..    .........    .. .      .  .   \n"
        "Needed workers:                 ....      . ?.                 .? .      ....   \n"
        "    Architect         -  0/1     .        . ..                 .. .        .    \n"
        "    Blacksmith        -  0/1     .       ..    ...         ...    ..       .    \n"
        "    Carpenter         -  0/3     . ..    .     .?.         .?.     .    .. .    \n"
        "    Foreman           -  0/1     . ?.    .    ........ ........    .    .? .    \n"
        "    Stonemason        -  0/10    . ..    ......      ...      ......    .. .    \n"
        "                                ..    ...                           ...    ..   \n"
        "                                .     .?.         .........         .?.     .   \n"
        "Select building options for:    .    ..............       ..............    .   \n"
        "[1] - Central Stone Tower       ......            .........            ......   \n"
        "[2] - Main Stone Keep                                                           \n"
        "[3] - Stone Battlement       \n"
        "[4] - Select Workers         \n"
        "[5] - Create Building        N/A\n"
        "[6] - Exit Building Menu     \n"
        "You must select a number from 1 to 6.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyDisplaysSectionMenu()
{
    Selector.initiateSelector(Player);
    command("1", Player);

    ExpectEq("Building Projects - Stone Keep:\n"
        "From this menu, you can select the materials to construct with and style of\n"
        "central stone tower to build for your stone keep project at Argalach Castle.\n"
        "\n"
        "Layout: +=======+            Building Sections:                               \n"
        "        | +---+ |                Central Stone Tower: <Make Selection>        \n"
        "        | |   | |                Main Stone Keep: <Not Selected Yet>          \n"
        "        | +---+ |                Stone Battlement: <Not Selected Yet>         \n"
        "        +=======+            \n"
        "\n"
        "[1]  - Select Metal           none     [2]  - Select Stone           none     \n"
        "[3]  - Select Textile         N/A      [4]  - Select Wood            none     \n"
        "[5]  - Hexagonal Stone Tower           [6]  - Magi Stone Tower                \n"
        "[7]  - Octagonal Stone Tower           [8]  - Round Stone Tower               \n"
        "[9]  - Square Stone Tower              [10] - Stone Bergfriede                \n"
        "[11] - Stone Bretasche                 [12] - Stone Observatory               \n"
        "[13] - Begin Construction     N/A      [14] - Exit Section Menu               \n"
        "You must select a number from 1 to 14.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SectionUpdatedWhenSelected()
{
    Selector.initiateSelector(Player);
    command("1", Player);
    command("10", Player);

    ExpectEq("Building Projects - Stone Keep:\n"
        "From this menu, you can select the materials to construct with and style of\n"
        "central stone tower to build for your stone keep project at Argalach Castle.\n"
        "\n"
        "Layout: +=======+            Building Sections:                               \n"
        "        | +---+ |                Central Stone Tower: Stone Bergfriede        \n"
        "        | |   | |                Main Stone Keep: <Not Selected Yet>          \n"
        "        | +---+ |                Stone Battlement: <Not Selected Yet>         \n"
        "        +=======+            \n"
        "\n"
        "[1]  - Select Metal           none     [2]  - Select Stone           none     \n"
        "[3]  - Select Textile         none     [4]  - Select Wood            none     \n"
        "[5]  - Hexagonal Stone Tower           [6]  - Magi Stone Tower                \n"
        "[7]  - Octagonal Stone Tower           [8]  - Round Stone Tower               \n"
        "[9]  - Square Stone Tower              [10] - Stone Bergfriede            (*) \n"
        "[11] - Stone Bretasche                 [12] - Stone Observatory               \n"
        "[13] - Begin Construction     N/A      [14] - Exit Section Menu               \n"
        "You must select a number from 1 to 14.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyDisplaysMaterialsMenu()
{
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftStone.c"));

    object material = clone_object("/lib/instances/items/materials/stone/granite.c");
    material.set("quantity", 100);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/stone/granite.c");
    material.set("quantity", 250);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/stone/marble.c");
    material.set("quantity", 500);
    move_object(material, Player);

    Player.addSkillPoints(500);
    Player.advanceSkill("stonemasonry", 10);

    Selector.initiateSelector(Player);
    command("1", Player);
    command("2", Player);

    ExpectEq("Building Projects - Select Material:\n"
        "From this menu, you can select the type of stone to construct with for your\n"
        "central stone tower of your stone keep project at Argalach Castle.\n"
        "\n"
        "    [1]  - Alabaster           (M)      [2]  - Andesite            (M)  \n"
        "    [3]  - Basalt              (M)      [4]  - Boninite            (M)  \n"
        "    [5]  - Brick               (P,M)    [6]  - Chalk               (M)  \n"
        "    [7]  - Chert               (M)      [8]  - Claystone           (M)  \n"
        "    [9]  - Coal                (M)      [10] - Concrete            (P,M)\n"
        "    [11] - Diorite             (M)      [12] - Dolomite            (M)  \n"
        "    [13] - Flint               (M)      [14] - Gneiss              (M)  \n"
        "    [15] - Granite                      [16] - Lazurite            (M)  \n"
        "    [17] - Limestone           (M)      [18] - Marble              (P)  \n"
        "    [19] - Obsidian            (P,M)    [20] - Quartzite           (P,M)\n"
        "    [21] - Sandstone           (M)      [22] - Scoria              (P,M)\n"
        "    [23] - Shale               (M)      [24] - Slate               (M)  \n"
        "    [25] - Stone               (M)      [26] - Travertine          (M)  \n"
        "    [27] - Tuff                (M)      [28] - Exit Material Menu       \n"
        "You must select a number from 1 to 28.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "P denotes unrealized prerequisites.\n"
        "M denotes that proper quantities of the material requirements are missing.\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectMaterialForComponent()
{
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftStone.c"));

    object material = clone_object("/lib/instances/items/materials/stone/granite.c");
    material.set("quantity", 100);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/stone/granite.c");
    material.set("quantity", 250);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/stone/marble.c");
    material.set("quantity", 500);
    move_object(material, Player);

    Player.addSkillPoints(500);
    Player.advanceSkill("stonemasonry", 10);

    Selector.initiateSelector(Player);
    command("1", Player);
    command("2", Player);
    command("15", Player);

    ExpectEq("Building Projects - Stone Keep:\n"
        "From this menu, you can select the materials to construct with and style of\n"
        "central stone tower to build for your stone keep project at Argalach Castle.\n"
        "\n"
        "Layout: +=======+            Building Sections:                               \n"
        "        | +---+ |                Central Stone Tower: <Make Selection>        \n"
        "        | |   | |                Main Stone Keep: <Not Selected Yet>          \n"
        "        | +---+ |                Stone Battlement: <Not Selected Yet>         \n"
        "        +=======+            \n"
        "\n"
        "[1]  - Select Metal           none     [2]  - Select Stone           granite  \n"
        "[3]  - Select Textile         N/A      [4]  - Select Wood            none     \n"
        "[5]  - Hexagonal Stone Tower           [6]  - Magi Stone Tower                \n"
        "[7]  - Octagonal Stone Tower           [8]  - Round Stone Tower               \n"
        "[9]  - Square Stone Tower              [10] - Stone Bergfriede                \n"
        "[11] - Stone Bretasche                 [12] - Stone Observatory               \n"
        "[13] - Begin Construction     N/A      [14] - Exit Section Menu               \n"
        "You must select a number from 1 to 14.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotSelectMaterialsWithFailedPrerequisiteCheck()
{
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftStone.c"));

    object material = clone_object("/lib/instances/items/materials/stone/granite.c");
    material.set("quantity", 100);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/stone/granite.c");
    material.set("quantity", 250);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/stone/marble.c");
    material.set("quantity", 500);
    move_object(material, Player);

    Player.addSkillPoints(500);
    Player.advanceSkill("stonemasonry", 10);

    Selector.initiateSelector(Player);
    command("1", Player);
    command("2", Player);
    command("18", Player);

    ExpectEq("Building Projects - Select Material:\n"
        "From this menu, you can select the type of stone to construct with for your\n"
        "central stone tower of your stone keep project at Argalach Castle.\n"
        "\n"
        "    [1]  - Alabaster           (M)      [2]  - Andesite            (M)  \n"
        "    [3]  - Basalt              (M)      [4]  - Boninite            (M)  \n"
        "    [5]  - Brick               (P,M)    [6]  - Chalk               (M)  \n"
        "    [7]  - Chert               (M)      [8]  - Claystone           (M)  \n"
        "    [9]  - Coal                (M)      [10] - Concrete            (P,M)\n"
        "    [11] - Diorite             (M)      [12] - Dolomite            (M)  \n"
        "    [13] - Flint               (M)      [14] - Gneiss              (M)  \n"
        "    [15] - Granite                      [16] - Lazurite            (M)  \n"
        "    [17] - Limestone           (M)      [18] - Marble              (P)  \n"
        "    [19] - Obsidian            (P,M)    [20] - Quartzite           (P,M)\n"
        "    [21] - Sandstone           (M)      [22] - Scoria              (P,M)\n"
        "    [23] - Shale               (M)      [24] - Slate               (M)  \n"
        "    [25] - Stone               (M)      [26] - Travertine          (M)  \n"
        "    [27] - Tuff                (M)      [28] - Exit Material Menu       \n"
        "You must select a number from 1 to 28.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "P denotes unrealized prerequisites.\n"
        "M denotes that proper quantities of the material requirements are missing.\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotSelectMaterialsWithFailedMaterialsCheck()
{
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftStone.c"));

    object material = clone_object("/lib/instances/items/materials/stone/granite.c");
    material.set("quantity", 100);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/stone/granite.c");
    material.set("quantity", 250);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/stone/marble.c");
    material.set("quantity", 500);
    move_object(material, Player);

    Player.addSkillPoints(500);
    Player.advanceSkill("stonemasonry", 10);

    Selector.initiateSelector(Player);
    command("1", Player);
    command("2", Player);
    command("1", Player);

    ExpectEq("Building Projects - Select Material:\n"
        "From this menu, you can select the type of stone to construct with for your\n"
        "central stone tower of your stone keep project at Argalach Castle.\n"
        "\n"
        "    [1]  - Alabaster           (M)      [2]  - Andesite            (M)  \n"
        "    [3]  - Basalt              (M)      [4]  - Boninite            (M)  \n"
        "    [5]  - Brick               (P,M)    [6]  - Chalk               (M)  \n"
        "    [7]  - Chert               (M)      [8]  - Claystone           (M)  \n"
        "    [9]  - Coal                (M)      [10] - Concrete            (P,M)\n"
        "    [11] - Diorite             (M)      [12] - Dolomite            (M)  \n"
        "    [13] - Flint               (M)      [14] - Gneiss              (M)  \n"
        "    [15] - Granite                      [16] - Lazurite            (M)  \n"
        "    [17] - Limestone           (M)      [18] - Marble              (P)  \n"
        "    [19] - Obsidian            (P,M)    [20] - Quartzite           (P,M)\n"
        "    [21] - Sandstone           (M)      [22] - Scoria              (P,M)\n"
        "    [23] - Shale               (M)      [24] - Slate               (M)  \n"
        "    [25] - Stone               (M)      [26] - Travertine          (M)  \n"
        "    [27] - Tuff                (M)      [28] - Exit Material Menu       \n"
        "You must select a number from 1 to 28.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "P denotes unrealized prerequisites.\n"
        "M denotes that proper quantities of the material requirements are missing.\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyDisplaysNonStandardMaterials()
{
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftStone.c"));
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftClay.c"));
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftGems.c"));
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftConcrete.c"));
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/useClaysAsStone.c"));
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/useCrystalsAsStone.c"));

    object material = clone_object("/lib/instances/items/materials/stone/granite.c");
    material.set("quantity", 100);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/stone/granite.c");
    material.set("quantity", 250);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/stone/marble.c");
    material.set("quantity", 500);
    move_object(material, Player);

    Player.addSkillPoints(500);
    Player.advanceSkill("stonemasonry", 10);

    Selector.initiateSelector(Player);
    command("1", Player);
    command("2", Player);
    command("1", Player);

    ExpectEq("Building Projects - Select Material:\n"
        "From this menu, you can select the type of stone to construct with for your\n"
        "central stone tower of your stone keep project at Argalach Castle.\n"
        "\n"
        "    [1]  - Agate               (P,M)    [2]  - Alabaster           (M)  \n"
        "    [3]  - Amber               (P,M)    [4]  - Amethyst            (P,M)\n"
        "    [5]  - Andesite            (M)      [6]  - Aquamarine          (P,M)\n"
        "    [7]  - Asurluin            (P,M)    [8]  - Basalt              (M)  \n"
        "    [9]  - Bloodstone          (P,M)    [10] - Boninite            (M)  \n"
        "    [11] - Brick               (P,M)    [12] - Ceramic slip        (P,M)\n"
        "    [13] - Chalk               (M)      [14] - Chert               (M)  \n"
        "    [15] - Citrine             (P,M)    [16] - Claystone           (M)  \n"
        "    [17] - Coal                (M)      [18] - Concrete            (P,M)\n"
        "    [19] - Crystal             (P,M)    [20] - Diamond             (P,M)\n"
        "    [21] - Diorite             (M)      [22] - Dolomite            (M)  \n"
        "    [23] - Durluin             (P,M)    [24] - Earthenware         (P,M)\n"
        "    [25] - Emerald             (P,M)    [26] - Flint               (M)  \n"
        "    [27] - Florite             (P,M)    [28] - Garnet              (P,M)\n"
        "    [29] - Gneiss              (M)      [30] - Granite                  \n"
        "    [31] - Gwyrluin            (P,M)    [32] - Jade                (P,M)\n"
        "    [33] - Kaolin              (P,M)    [34] - Kirluin             (P,M)\n"
        "    [35] - Lazurite            (M)      [36] - Limestone           (M)  \n"
        "    [37] - Magical crystal     (P,M)    [38] - Magical ice         (P,M)\n"
        "    [39] - Marble              (P)      [40] - Marnluin            (P,M)\n"
        "    [41] - Melynuin            (P,M)    [42] - Obsidian            (P,M)\n"
        "    [43] - Onyx                (P,M)    [44] - Opal                (P,M)\n"
        "    [45] - Plaster             (P,M)    [46] - Pyrite              (P,M)\n"
        "    [47] - Quartz              (P,M)    [48] - Quartzite           (P,M)\n"
        "    [49] - Rhudluin            (P,M)    [50] - Ruby                (P,M)\n"
        "    [51] - Sandstone           (M)      [52] - Sapphire            (P,M)\n"
        "    [53] - Scoria              (P,M)    [54] - Shale               (M)  \n"
        "    [55] - Slate               (M)      [56] - Stone               (M)  \n"
        "    [57] - Stoneware           (P,M)    [58] - Terra cotta         (P,M)\n"
        "    [59] - Topaz               (P,M)    [60] - Travertine          (M)  \n"
        "    [61] - Trynluin            (P,M)    [62] - Tuff                (M)  \n"
        "    [63] - Turquoise           (P,M)    [64] - Exit Material Menu       \n"
        "You must select a number from 1 to 64.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "P denotes unrealized prerequisites.\n"
        "M denotes that proper quantities of the material requirements are missing.\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyDisplaysWorkerMenu()
{
    Selector.initiateSelector(Player);
    command("4", Player);

    ExpectEq("Building Projects - Assign Workers:\n"
        "From this menu, you can select the workers who will be executing your Stone\n"
        "Keep project in your holdings at Argalach Castle.\n"
        "\n"
        "Layout: +=======+            Needed workers:                                  \n"
        "        | +---+ |                Architect         -  0/1                     \n"
        "        | |   | |                Blacksmith        -  0/1                     \n"
        "        | +---+ |                Carpenter         -  0/3                     \n"
        "        +=======+                Foreman           -  0/1                     \n"
        "                                 Stonemason        -  0/10                    \n"
        "\n"
        "[1] - Auto-Select Workers \n"
        "[2] - Select Architects   \n"
        "[3] - Select Blacksmiths  \n"
        "[4] - Select Carpenters   \n"
        "[5] - Select Foremen      \n"
        "[6] - Select Stonemasons  \n"
        "[7] - Confirm Selected Workers\n"
        "[8] - Exit Building Menu  \n"
        "You must select a number from 1 to 8.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyDisplaysWorkerSelectionMenu()
{
    Selector.initiateSelector(Player);
    command("4", Player);
    command("2", Player);

    ExpectEq("Building Projects - Assign Workers:\n"
        "From this menu, you can select the architects who will be executing your\n"
        "project in your holdings at Argalach Castle.\n"
        "\nArchitects selected: 0 of 1.\n\n"
        "[1] - Hire Apprentice ($25000) low $  [2] - Hire Journeyman ($225000)low $  \n"
        "[3] - Confirm Selections       N/A    [4] - Exit Building Menu              \n"
        "You must select a number from 1 to 4.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "You have 1 worker left to assign.\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WorkerDisplayIsUpdatedOnAssignmentMenu()
{
    Player.addMoney(125000);
    Selector.initiateSelector(Player);
    command("4", Player);
    command("2", Player);
    command("1", Player);
    command("4", Player);

    ExpectEq("Building Projects - Assign Workers:\n"
        "From this menu, you can select the workers who will be executing your Stone\n"
        "Keep project in your holdings at Argalach Castle.\n"
        "\n"
        "Layout: +=======+            Needed workers:                                  \n"
        "        | +---+ |                Architect         -  1/1                     \n"
        "        | |   | |                Blacksmith        -  0/1                     \n"
        "        | +---+ |                Carpenter         -  0/3                     \n"
        "        +=======+                Foreman           -  0/1                     \n"
        "                                 Stonemason        -  0/10                    \n"
        "\n"
        "[1] - Auto-Select Workers \n"
        "[2] - Select Architects   \n"
        "[3] - Select Blacksmiths  \n"
        "[4] - Select Carpenters   \n"
        "[5] - Select Foremen      \n"
        "[6] - Select Stonemasons  \n"
        "[7] - Confirm Selected Workers\n"
        "[8] - Exit Building Menu  \n"
        "You must select a number from 1 to 8.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WorkerDisplayIsUpdatedOnTopLevel()
{
    object workerSelector = 
        clone_object("/lib/modules/domains/workCrewSelector.c");

    workerSelector.setConstructionData(([ 
        "assigned workers": ([
            "architect": ([ 
                "A Aladain": ([ 
                ]), 
            ]),
            "blacksmith": ([ 
                "B Aladain": ([ 
                ]), 
            ]),
            "carpenter": ([ 
                "Oredh Aladain": ([ 
                ]), 
                "Bob Aladain": ([ 
                ]), 
            ]),
            "stonemason": ([ 
                "C Aladain": ([ 
                ]), 
                "D Aladain": ([ 
                ]), 
                "E Aladain": ([ 
                ]), 
                "F Aladain": ([ 
                ]), 
                "G Aladain": ([ 
                ]), 
            ]),
        ]),
    ]));

    Selector.initiateSelector(Player);
    Selector.onSelectorCompleted(workerSelector);

    ExpectEq("Building Projects - Stone Keep:\n"
        "From this menu, you can initiate, modify, or abort projects in your holdings\n"
        "at Argalach Castle.\n\n"
        "Layout:                                                                         \n"
        "+=======+                       ......            .........            ......   \n"
        "| +---+ |                       .    ..............       ..............    .   \n"
        "| |   | |                       .     .?.         .........         .?.     .   \n"
        "| +---+ |                       ..    ...                           ...    ..   \n"
        "+=======+                        . ..    ......      ...      ......    .. .    \n"
        "Completion time: 1000            . ?.    .    ........ ........    .    .? .    \n"
        "                                 . ..    .     .?.         .?.     .    .. .    \n"
        "Stone Battlement:                .       ..    ...         ...    ..       .    \n"
        "    <select>                     .        . ..                 .. .        .    \n"
        "Central Stone Tower:            ....      . ?.    .........    .? .      ....   \n"
        "    <select>                    .  .      . ..    .       .    .. .      .  .   \n"
        "Main Stone Keep:                .  .     ...      .       .      ...     .  .   \n"
        "    <select>                    .  .     ...      .       .      ...     .  .   \n"
        "                                .  .      . ..    .........    .. .      .  .   \n"
        "Needed workers:                 ....      . ?.                 .? .      ....   \n"
        "    Architect         -  1/1     .        . ..                 .. .        .    \n"
        "    Blacksmith        -  1/1     .       ..    ...         ...    ..       .    \n"
        "    Carpenter         -  2/3     . ..    .     .?.         .?.     .    .. .    \n"
        "    Foreman           -  0/1     . ?.    .    ........ ........    .    .? .    \n"
        "    Stonemason        -  5/10    . ..    ......      ...      ......    .. .    \n"
        "                                ..    ...                           ...    ..   \n"
        "                                .     .?.         .........         .?.     .   \n"
        "Select building options for:    .    ..............       ..............    .   \n"
        "[1] - Central Stone Tower       ......            .........            ......   \n"
        "[2] - Main Stone Keep                                                           \n"
        "[3] - Stone Battlement       \n"
        "[4] - Select Workers         \n"
        "[5] - Create Building        N/A\n"
        "[6] - Exit Building Menu     \n"
        "You must select a number from 1 to 6.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SectionDisplayIsUpdatedOnTopLevel()
{
    object sectionSelector = 
        clone_object("/lib/modules/domains/sectionSelector.c");

    sectionSelector.setDetails(
        ([
            "main stone keep": ([ 
                "metal": 10,
                "textile": 0,
                "wood": 50,
                "stone": 400
            ]),
            "stone battlement": ([ 
                "metal": 5,
                "wood": 25,
                "stone": 75
            ]),
            "central stone tower": ([
                "metal": 10,
                "textile": 0,
                "wood": 50,
                "stone": 300
            ]),
            "chosen section": "Stone Observatory",
            "selected materials": ([ 
                "metal": "iron",
                "wood": "pine",
                "textile": "linen",
                "stone": "granite"
            ]),
        ]),
        "stone keep", "central stone tower");

    Selector.initiateSelector(Player);
    Selector.onSelectorCompleted(sectionSelector);

    ExpectEq("Building Projects - Stone Keep:\n"
        "From this menu, you can initiate, modify, or abort projects in your holdings\n"
        "at Argalach Castle.\n\n"
        "Layout:   Units:                                                                \n"
        "+=======+  7 Henchmen           ......            .........            ......   \n"
        "| +---+ |  3 Knights            .    ..............       ..............    .   \n"
        "| |   | |                       .     .?.         .........         .?.     .   \n"
        "| +---+ |                       ..    ...                           ...    ..   \n"
        "+=======+                        . ..    ......      ...      ......    .. .    \n"
        "Effects:                         . ?.    .    ........ ........    .    .? .    \n"
        "+3   to defend air attack        . ..    .     .?.         .?.     .    .. .    \n"
        "+350 to structure                .       ..    ...         ...    ..       .    \n"
        "+6   to defend ground attack     .        . ..                 .. .        .    \n"
        "Completion time: 1500           ....      . ?.    .........    .? .      ....   \n"
        "                                .  .      . ..    .       .    .. .      .  .   \n"
        "Stone Battlement:               .  .     ...      .       .      ...     .  .   \n"
        "    <select>                    .  .     ...      .       .      ...     .  .   \n"
        "Central Stone Tower:            .  .      . ..    .........    .. .      .  .   \n"
        "    Stone Observatory           ....      . ?.                 .? .      ....   \n"
        "Main Stone Keep:                 .        . ..                 .. .        .    \n"
        "    <select>                     .       ..    ...         ...    ..       .    \n"
        "                                 . ..    .     .?.         .?.     .    .. .    \n"
        "Needed workers:                  . ?.    .    ........ ........    .    .? .    \n"
        "    Architect         -  0/1     . ..    ......      ...      ......    .. .    \n"
        "    Blacksmith        -  0/1    ..    ...                           ...    ..   \n"
        "    Carpenter         -  0/3    .     .?.         .........         .?.     .   \n"
        "    Foreman           -  0/1    .    ..............       ..............    .   \n"
        "    Stonemason        -  0/10   ......            .........            ......   \n"
        "                                                                                \n"
        "Select building options for: \n"
        "[1] - Central Stone Tower    \n"
        "[2] - Main Stone Keep        \n"
        "[3] - Stone Battlement       \n"
        "[4] - Select Workers         \n"
        "[5] - Create Building        N/A\n"
        "[6] - Exit Building Menu     \n"
        "You must select a number from 1 to 6.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SectionDisplayIsUpdatedOnSectionMenu()
{
    object sectionSelector = 
        clone_object("/lib/modules/domains/sectionSelector.c");

    sectionSelector.setDetails(
        ([
            "main stone keep": ([ 
                "metal": 10,
                "textile": 0,
                "wood": 50,
                "stone": 400
            ]),
            "stone battlement": ([ 
                "metal": 5,
                "wood": 25,
                "stone": 75
            ]),
            "central stone tower": ([
                "metal": 10,
                "textile": 0,
                "wood": 50,
                "stone": 300
            ]),
            "chosen section": "Stone Observatory",
            "selected materials": ([ 
                "metal": "iron",
                "wood": "pine",
                "textile": "linen",
                "stone": "granite"
            ]),
        ]),
        "stone keep", "central stone tower");

    Selector.initiateSelector(Player);
    Selector.onSelectorCompleted(sectionSelector);

    command("2", Player);

    ExpectEq("Building Projects - Stone Keep:\n"
        "From this menu, you can select the materials to construct with and style of\n"
        "main stone keep to build for your stone keep project at Argalach Castle.\n"
        "\n"
        "Layout: +=======+            Building Sections:                               \n"
        "        | +---+ |                Central Stone Tower: Stone Observatory       \n"
        "        | |   | |                Main Stone Keep: <Make Selection>            \n"
        "        | +---+ |                Stone Battlement: <Not Selected Yet>         \n"
        "        +=======+            \n"
        "\n"
        "[1]  - Select Metal           none     [2]  - Select Stone           none     \n"
        "[3]  - Select Textile         N/A      [4]  - Select Wood            none     \n"
        "[5]  - Large Hexagonal Sto...          [6]  - Large Octagonal Sto...          \n"
        "[7]  - Large Round Stone Keep          [8]  - Large Square Stone ...          \n"
        "[9]  - Simple Hexagonal St...          [10] - Simple Octagonal St...          \n"
        "[11] - Simple Round Stone ...          [12] - Simple Square Stone...          \n"
        "[13] - Tall Hexagonal Ston...          [14] - Tall Octagonal Ston...          \n"
        "[15] - Tall Round Stone Keep           [16] - Tall Square Stone Keep          \n"
        "[17] - Begin Construction     N/A      [18] - Exit Section Menu               \n"
        "You must select a number from 1 to 18.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        Player.caughtMessage());
}
/////////////////////////////////////////////////////////////////////////////
void CompletionTimeIsUpdated()
{
    object workerSelector =
        clone_object("/lib/modules/domains/workCrewSelector.c");

    workerSelector.setConstructionData(([
        "assigned workers":([
            "carpenter":([
                "Arnalt Arator": ([ 
                    "benefits": ([ 
                        "duration": -5,
                        "traits": ({ 
                            "/lib/instances/traits/domains/apprentice-carpenter.c",
                            "/lib/instances/traits/personas/fighters/swordsman.c"
                        }),
                        "structure": -5,
                        "level": "low end worker",
                        "materials": -5,
                        "units": -5,
                        "combat": -5,
                        "skills": ([ 
                            "primary": 2,
                            "wood crafting": 1
                        ]),
                    "description": "M: -5%, D: -5%, C: -5%, U: -5%, S: -5%"
                    ]),
                    "object": "/lib/realizations/henchman#344",
                    "level": "low end worker"
                ]),
                "Marik Argalen": ([ 
                    "benefits": ([ 
                        "duration": 17,
                        "traits": ({
                           "/lib/instances/traits/domains/master-carpenter.c",
                         "/lib/instances/traits/personas/fighters/swordsman.c"
                        }),
                        "structure": 15,
                        "level": "elite worker",
                        "materials": 17,
                        "units": 10,
                        "combat": 10,
                        "skills": ([
                            "primary": 25,
                            "wood crafting": 20
                        ]),
                        "description": "M: +17%, D: +17%, C: +10%, U: +10%, S: +15%"
                    ]),
                    "object": "/lib/realizations/henchman#337",
                    "level": "elite worker"
                ]),
                "Royce Eralkidh": ([
                    "benefits": ([
                        "duration": 0,
                        "traits": ({ 
                            "/lib/instances/traits/domains/journeyman-carpenter.c",
                            "/lib/instances/traits/personas/fighters/swordsman.c"
                        }),
                        "structure": 0,
                        "level": "average worker",
                        "materials": 0,
                        "units": 0,
                        "combat": 0,
                        "skills": ([
                            "primary": 10,
                            "wood crafting": 5
                        ]),
                    "description": "No bonuses or penalties"
                    ]),
                    "object": "/lib/realizations/henchman#330",
                    "level": "average worker"
                ])
            ])
        ])
    ]));

    Selector.initiateSelector(Player);
    Selector.onSelectorCompleted(workerSelector);

    ExpectEq("Building Projects - Stone Keep:\n"
        "From this menu, you can initiate, modify, or abort projects in your holdings\n"
        "at Argalach Castle.\n\n"
        "Layout:                                                                         \n"
        "+=======+                       ......            .........            ......   \n"
        "| +---+ |                       .    ..............       ..............    .   \n"
        "| |   | |                       .     .?.         .........         .?.     .   \n"
        "| +---+ |                       ..    ...                           ...    ..   \n"
        "+=======+                        . ..    ......      ...      ......    .. .    \n"
        "Completion time: 960             . ?.    .    ........ ........    .    .? .    \n"
        "                                 . ..    .     .?.         .?.     .    .. .    \n"
        "Stone Battlement:                .       ..    ...         ...    ..       .    \n"
        "    <select>                     .        . ..                 .. .        .    \n"
        "Central Stone Tower:            ....      . ?.    .........    .? .      ....   \n"
        "    <select>                    .  .      . ..    .       .    .. .      .  .   \n"
        "Main Stone Keep:                .  .     ...      .       .      ...     .  .   \n"
        "    <select>                    .  .     ...      .       .      ...     .  .   \n"
        "                                .  .      . ..    .........    .. .      .  .   \n"
        "Needed workers:                 ....      . ?.                 .? .      ....   \n"
        "    Architect         -  0/1     .        . ..                 .. .        .    \n"
        "    Blacksmith        -  0/1     .       ..    ...         ...    ..       .    \n"
        "    Carpenter         -  3/3     . ..    .     .?.         .?.     .    .. .    \n"
        "    Foreman           -  0/1     . ?.    .    ........ ........    .    .? .    \n"
        "    Stonemason        -  0/10    . ..    ......      ...      ......    .. .    \n"
        "                                ..    ...                           ...    ..   \n"
        "                                .     .?.         .........         .?.     .   \n"
        "Select building options for:    .    ..............       ..............    .   \n"
        "[1] - Central Stone Tower       ......            .........            ......   \n"
        "[2] - Main Stone Keep                                                           \n"
        "[3] - Stone Battlement       \n"
        "[4] - Select Workers         \n"
        "[5] - Create Building        N/A\n"
        "[6] - Exit Building Menu     \n"
        "You must select a number from 1 to 6.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        Player.caughtMessage());

    object sectionSelector = 
        clone_object("/lib/modules/domains/sectionSelector.c");

    sectionSelector.setDetails(
        ([
            "main stone keep": ([ 
                "metal": 10,
                "textile": 0,
                "wood": 50,
                "stone": 400
            ]),
            "stone battlement": ([ 
                "metal": 5,
                "wood": 25,
                "stone": 75
            ]),
            "central stone tower": ([
                "metal": 10,
                "textile": 0,
                "wood": 50,
                "stone": 300
            ]),
            "chosen section": "Stone Observatory",
            "selected materials": ([ 
                "metal": "iron",
                "wood": "pine",
                "textile": "linen",
                "stone": "granite"
            ]),
        ]),
        "stone keep", "central stone tower");

    Selector.onSelectorCompleted(sectionSelector);
    ExpectEq("Building Projects - Stone Keep:\n"
        "From this menu, you can initiate, modify, or abort projects in your holdings\n"
        "at Argalach Castle.\n\n"
        "Layout:   Units:                                                                \n"
        "+=======+  7 Henchmen           ......            .........            ......   \n"
        "| +---+ |  3 Knights            .    ..............       ..............    .   \n"
        "| |   | |                       .     .?.         .........         .?.     .   \n"
        "| +---+ |                       ..    ...                           ...    ..   \n"
        "+=======+                        . ..    ......      ...      ......    .. .    \n"
        "Effects:                         . ?.    .    ........ ........    .    .? .    \n"
        "+3   to defend air attack        . ..    .     .?.         .?.     .    .. .    \n"
        "+350 to structure                .       ..    ...         ...    ..       .    \n"
        "+6   to defend ground attack     .        . ..                 .. .        .    \n"
        "Completion time: 1440           ....      . ?.    .........    .? .      ....   \n"
        "                                .  .      . ..    .       .    .. .      .  .   \n"
        "Stone Battlement:               .  .     ...      .       .      ...     .  .   \n"
        "    <select>                    .  .     ...      .       .      ...     .  .   \n"
        "Central Stone Tower:            .  .      . ..    .........    .. .      .  .   \n"
        "    Stone Observatory           ....      . ?.                 .? .      ....   \n"
        "Main Stone Keep:                 .        . ..                 .. .        .    \n"
        "    <select>                     .       ..    ...         ...    ..       .    \n"
        "                                 . ..    .     .?.         .?.     .    .. .    \n"
        "Needed workers:                  . ?.    .    ........ ........    .    .? .    \n"
        "    Architect         -  0/1     . ..    ......      ...      ......    .. .    \n"
        "    Blacksmith        -  0/1    ..    ...                           ...    ..   \n"
        "    Carpenter         -  3/3    .     .?.         .........         .?.     .   \n"
        "    Foreman           -  0/1    .    ..............       ..............    .   \n"
        "    Stonemason        -  0/10   ......            .........            ......   \n"
        "                                                                                \n"
        "Select building options for: \n"
        "[1] - Central Stone Tower    \n"
        "[2] - Main Stone Keep        \n"
        "[3] - Stone Battlement       \n"
        "[4] - Select Workers         \n"
        "[5] - Create Building        N/A\n"
        "[6] - Exit Building Menu     \n"
        "You must select a number from 1 to 6.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CancelClearsSectionSelection()
{
    Selector.initiateSelector(Player);
    command("1", Player);
    command("10", Player);
    command("14", Player);

    ExpectEq("Building Projects - Stone Keep:\n"
        "From this menu, you can initiate, modify, or abort projects in your holdings\n"
        "at Argalach Castle.\n\n"
        "Layout:                                                                         \n"
        "+=======+                       ......            .........            ......   \n"
        "| +---+ |                       .    ..............       ..............    .   \n"
        "| |   | |                       .     .?.         .........         .?.     .   \n"
        "| +---+ |                       ..    ...                           ...    ..   \n"
        "+=======+                        . ..    ......      ...      ......    .. .    \n"
        "Completion time: 1000            . ?.    .    ........ ........    .    .? .    \n"
        "                                 . ..    .     .?.         .?.     .    .. .    \n"
        "Stone Battlement:                .       ..    ...         ...    ..       .    \n"
        "    <select>                     .        . ..                 .. .        .    \n"
        "Central Stone Tower:            ....      . ?.    .........    .? .      ....   \n"
        "    <select>                    .  .      . ..    .       .    .. .      .  .   \n"
        "Main Stone Keep:                .  .     ...      .       .      ...     .  .   \n"
        "    <select>                    .  .     ...      .       .      ...     .  .   \n"
        "                                .  .      . ..    .........    .. .      .  .   \n"
        "Needed workers:                 ....      . ?.                 .? .      ....   \n"
        "    Architect         -  0/1     .        . ..                 .. .        .    \n"
        "    Blacksmith        -  0/1     .       ..    ...         ...    ..       .    \n"
        "    Carpenter         -  0/3     . ..    .     .?.         .?.     .    .. .    \n"
        "    Foreman           -  0/1     . ?.    .    ........ ........    .    .? .    \n"
        "    Stonemason        -  0/10    . ..    ......      ...      ......    .. .    \n"
        "                                ..    ...                           ...    ..   \n"
        "                                .     .?.         .........         .?.     .   \n"
        "Select building options for:    .    ..............       ..............    .   \n"
        "[1] - Central Stone Tower       ......            .........            ......   \n"
        "[2] - Main Stone Keep                                                           \n"
        "[3] - Stone Battlement       \n"
        "[4] - Select Workers         \n"
        "[5] - Create Building        N/A\n"
        "[6] - Exit Building Menu     \n"
        "You must select a number from 1 to 6.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DisplayBenefitsFromBuilding()
{
    object sectionSelector = 
        clone_object("/lib/modules/domains/sectionSelector.c");

    sectionSelector.setDetails(
        ([
            "main stone keep": ([ 
                "metal": 10,
                "textile": 0,
                "wood": 50,
                "stone": 400
            ]),
            "stone battlement": ([ 
                "metal": 5,
                "wood": 25,
                "stone": 75
            ]),
            "central stone tower": ([
                "metal": 10,
                "textile": 0,
                "wood": 50,
                "stone": 300
            ]),
            "chosen section": "Stone Bergfriede",
            "selected materials": ([ 
                "metal": "iron",
                "wood": "pine",
                "textile": "linen",
                "stone": "granite"
            ]),
        ]),
        "stone keep", "central stone tower");

    Selector.initiateSelector(Player);
    Selector.onSelectorCompleted(sectionSelector);

    sectionSelector =
        clone_object("/lib/modules/domains/sectionSelector.c");
    sectionSelector.setDetails(
        ([
            "main stone keep": ([ 
                "metal": 10,
                "textile": 0,
                "wood": 50,
                "stone": 400
            ]),
            "stone battlement": ([ 
                "metal": 5,
                "wood": 25,
                "stone": 75
            ]),
            "central stone tower": ([
                "metal": 10,
                "textile": 0,
                "wood": 50,
                "stone": 300
            ]),
            "chosen section": "Machicolationed Stone Battlement",
            "selected materials": ([ 
                "metal": "iron",
                "wood": "pine",
                "textile": "linen",
                "stone": "granite"
            ]),
        ]),
        "stone keep", "stone battlement");
    Selector.onSelectorCompleted(sectionSelector);

    sectionSelector =
        clone_object("/lib/modules/domains/sectionSelector.c");
    sectionSelector.setDetails(
        ([
            "main stone keep": ([ 
                "metal": 10,
                "textile": 0,
                "wood": 50,
                "stone": 400
            ]),
            "stone battlement": ([ 
                "metal": 5,
                "wood": 25,
                "stone": 75
            ]),
            "central stone tower": ([
                "metal": 10,
                "textile": 0,
                "wood": 50,
                "stone": 300
            ]),
            "chosen section": "Large Octagonal Stone Keep",
            "selected materials": ([ 
                "metal": "iron",
                "wood": "pine",
                "textile": "linen",
                "stone": "granite"
            ]),
        ]),
        "stone keep", "main stone keep");
    Selector.onSelectorCompleted(sectionSelector);

    ExpectEq("Building Projects - Stone Keep:\n"
        "From this menu, you can initiate, modify, or abort projects in your holdings\n"
        "at Argalach Castle.\n\n"
        "Layout:   Units:                                                                \n"
        "+=======+ 35 Spearmen           ......            .........            ......   \n"
        "| +---+ |  9 Henchmen           .    ..............       ..............    .   \n"
        "| |   | | 25 Archers            .     .?.         .........         .?.     .   \n"
        "| +---+ | 20 Knights            ..    ...                           ...    ..   \n"
        "+=======+ 35 Swordsmen           . ..    ......      ...      ......    .. .    \n"
        "           5 Bombadiers          . ?.    .    ........ ........    .    .? .    \n"
        "          40 Men-at-arms         . ..    .     .?.         .?.     .    .. .    \n"
        "Effects:                         .       ..    ...         ...    ..       .    \n"
        "+2   to air attack               .        . ..                 .. .        .    \n"
        "+10  to defend air attack       ....      . ?.    .........    .? .      ....   \n"
        "+925 to structure               .  .      . ..    .       .    .. .      .  .   \n"
        "+18  to defend ground attack    .  .     ...      .       .      ...     .  .   \n"
        "Completion time: 2100           .  .     ...      .       .      ...     .  .   \n"
        "                                .  .      . ..    .........    .. .      .  .   \n"
        "Stone Battlement:               ....      . ?.                 .? .      ....   \n"
        "    Machicolationed Stone ...    .        . ..                 .. .        .    \n"
        "Central Stone Tower:             .       ..    ...         ...    ..       .    \n"
        "    Stone Bergfriede             . ..    .     .?.         .?.     .    .. .    \n"
        "Main Stone Keep:                 . ?.    .    ........ ........    .    .? .    \n"
        "    Large Octagonal Stone ...    . ..    ......      ...      ......    .. .    \n"
        "                                ..    ...                           ...    ..   \n"
        "Needed workers:                 .     .?.         .........         .?.     .   \n"
        "    Architect         -  0/1    .    ..............       ..............    .   \n"
        "    Blacksmith        -  0/1    ......            .........            ......   \n"
        "    Carpenter         -  0/3                                                    \n"
        "    Foreman           -  0/1 \n"
        "    Stonemason        -  0/10\n"
        "Select building options for: \n"
        "[1] - Central Stone Tower    \n"
        "[2] - Main Stone Keep        \n"
        "[3] - Stone Battlement       \n"
        "[4] - Select Workers         \n"
        "[5] - Create Building        N/A\n"
        "[6] - Exit Building Menu     \n"
        "You must select a number from 1 to 6.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        Player.caughtMessage());
}
