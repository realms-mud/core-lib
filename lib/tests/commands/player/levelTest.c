//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    load_object("/lib/dictionaries/guildsDictionary.c");
    load_object("/guilds/scion/scionOfDhuras.c");
    load_object("/lib/tests/support/guilds/fighterGuild.c");
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->hitPoints(30);
    Player->spellPoints(30);
    Player->staminaPoints(30);
    Player->Str(10);
    Player->Int(10);
    Player->Dex(10);
    Player->Wis(10);
    Player->Con(10);
    Player->Chr(10);
    Player->addCommands();
    Player->Race("high elf");
    Player->addTrait("/lib/instances/traits/racial/hillgarathElf.c");
    Player->addTrait("/lib/instances/traits/genetic/smart.c");
    Player->spellPoints(Player->maxSpellPoints());
    Player->staminaPoints(Player->maxStaminaPoints());
    Player->colorConfiguration("none");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void GuildAdvancementLevelNotDisplayedIfYouCannotAdvance()
{
    command("level up", Player);
    ExpectEq("You are not yet ready to advance in any guilds.\n", 
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GuildAdvancementLevelNotDisplayedIfYouAreNotInGuild()
{
    command("level up -g weasels", Player);
    ExpectEq("You are not yet ready to advance in any guilds.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelGuildMenuDisplaysCorrectly()
{
    Player->joinGuild("Scion of Dhuras");
    destruct(present_clone("lib/modules/guilds/advanceLevelSelector.c", Player));

    Player->addExperience(2000);
    command("level up", Player);
    ExpectEq("Advancement - Main Menu:\n"
        "[1] - Advance Scion of Dhuras level\n"
        "[2] - Exit Advancement Menu\n"
        "You must select a number from 1 to 2.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DoesNotAllowForGuildsNotReadyForAdvancement()
{
    Player->joinGuild("Scion of Dhuras");
    destruct(present_clone("lib/modules/guilds/advanceLevelSelector.c", Player));
    Player->addExperience(2000);
    Player->joinGuild("fake fighter");
    destruct(present_clone("lib/modules/guilds/advanceLevelSelector.c", Player));

    command("level up", Player);
    ExpectEq("Advancement - Main Menu:\n"
        "[1] - Advance fake fighter level               (Need More Experience)\n"
        "[2] - Advance Scion of Dhuras level\n"
        "[3] - Exit Advancement Menu\n"
        "You must select a number from 1 to 3.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanAdvanceMultipleGuilds()
{
    Player->joinGuild("Scion of Dhuras");
    destruct(present_clone("lib/modules/guilds/advanceLevelSelector.c", Player));
    Player->joinGuild("fake fighter");
    destruct(present_clone("lib/modules/guilds/advanceLevelSelector.c", Player));

    Player->addExperience(5000);
    command("level up", Player);
    ExpectEq("Advancement - Main Menu:\n"
        "[1] - Advance fake fighter level\n"
        "[2] - Advance Scion of Dhuras level\n"
        "[3] - Exit Advancement Menu\n"
        "You must select a number from 1 to 3.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanAdvanceInGuild()
{
    Player->joinGuild("Scion of Dhuras");
    destruct(present_clone("lib/modules/guilds/advanceLevelSelector.c", Player));
    Player->addExperience(2000);
    command("level up", Player);
    command("1", Player);

    ExpectEq("Advancement - Scion of Dhuras Menu:\n"
        "[1]  - Spend Attribute Points\n"
        "[2]  - Spend Skill Points\n"
        "[3]  - Research Choice: The Path (Axe)          (Prerequisite Missing)\n"
        "[4]  - Research Choice: The Focus\n"
        "[5]  - Research Choice: The Path (Dagger)       (Prerequisite Missing)\n"
        "[6]  - Research Choice: The Path (Staff)        (Prerequisite Missing)\n"
        "[7]  - Research Choice: The Path (Hammer)       (Prerequisite Missing)\n"
        "[8]  - Research Choice: The Path (Sword)        (Prerequisite Missing)\n"
        "[9]  - Research Choice: The Path (Mace)         (Prerequisite Missing)\n"
        "[10] - Spend Research Points                    (Select Choices First)\n"
        "[11] - Exit Advancement Menu\n"
        "You must select a number from 1 to 11.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanUpdateAttributes()
{
    Player->joinGuild("Scion of Dhuras");
    destruct(present_clone("lib/modules/guilds/advanceLevelSelector.c", Player));
    Player->addExperience(2000);
    Player->addAttributePointsToSpend(1);
    command("level up", Player);
    command("1", Player);
    command("1", Player);
    ExpectEq("Level up - Advance your attributes:\n"
        "    [1] - Strength            (current Str is 10)\n"
        "    [2] - Intelligence        (current Int is 10)\n"
        "    [3] - Dexterity           (current Dex is 10)\n"
        "    [4] - Wisdom              (current Wis is 10)\n"
        "    [5] - Constitution        (current Con is 10)\n"
        "    [6] - Charisma            (current Cha is 10)\n"
        "    [7] - Exit Attribute Menu \n"
        "You must select a number from 1 to 7. You may also undo or reset.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "You have 2 points left to spend on attributes.\n", 
        Player->caughtMessage());

    command("1", Player);
    ExpectEq("Level up - Advance your attributes:\n"
        "    [1] - Strength            (current Str is at maximum of 11)\n"
        "    [2] - Intelligence        (current Int is 10)\n"
        "    [3] - Dexterity           (current Dex is 10)\n"
        "    [4] - Wisdom              (current Wis is 10)\n"
        "    [5] - Constitution        (current Con is 10)\n"
        "    [6] - Charisma            (current Cha is 10)\n"
        "    [7] - Exit Attribute Menu \n"
        "You must select a number from 1 to 7. You may also undo or reset.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "You have 1 point left to spend on attributes.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanUpdateSkills()
{
    Player->joinGuild("Scion of Dhuras");
    destruct(present_clone("lib/modules/guilds/advanceLevelSelector.c", Player));
    Player->advanceSkill("long sword", 4);
    Player->advanceSkill("dagger", 1);
    Player->addExperience(2000);
    command("level up", Player);
    command("1", Player);
    command("2", Player);
    ExpectEq("Level up - Advance your skills:\n"
        "    [1] - Combat              \n"
        "    [2] - Crafting            \n"
        "    [3] - Erudite             \n"
        "    [4] - General             \n"
        "    [5] - Language            \n"
        "    [6] - Magic               \n"
        "    [7] - Subterfuge          \n"
        "    [8] - Exit Skill Menu     \n"
        "You must select a number from 1 to 8. You may also undo or reset.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "You have 5 skills left to assign.\n",
        Player->caughtMessage());

    ExpectEq(0, Player->getSkill("axe", 1));

    command("1", Player);
    command("1", Player);
    command("1", Player);
    command("1", Player);
    ExpectEq("Level up - Select a skill to advance:\n"
        "    [1]  - Axe                 ( 3)    [2]  - Blind fighting          \n"
        "    [3]  - Bow                         [4]  - Chainmail               \n"
        "    [5]  - Crossbow                    [6]  - Dagger              ( 1)\n"
        "    [7]  - Dodge                       [8]  - Dual wield              \n"
        "    [9]  - Flail                       [10] - Hammer                  \n"
        "    [11] - Hand and a half s...        [12] - Hard leather            \n"
        "    [13] - Long sword          ( 4)    [14] - Mace                    \n"
        "    [15] - No armor                    [16] - Parry                   \n"
        "    [17] - Plate armor                 [18] - Pole arm                \n"
        "    [19] - Scalemail                   [20] - Shield                  \n"
        "    [21] - Short sword                 [22] - Sling                   \n"
        "    [23] - Soft leather                [24] - Splint armor            \n"
        "    [25] - Staff                       [26] - Thrown                  \n"
        "    [27] - Two-handed sword            [28] - Unarmed                 \n"
        "    [29] - Return to previous menu    \n"
        "You must select a number from 1 to 29.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "(##) denotes current skill level. You have 2 points to spend.\n",
        Player->caughtMessage());

    ExpectEq(3, Player->getSkill("axe", 1));
    command("29", Player);
    ExpectEq("Level up - Advance your skills:\n"
        "    [1] - Combat              \n"
        "    [2] - Crafting            \n"
        "    [3] - Erudite             \n"
        "    [4] - General             \n"
        "    [5] - Language            \n"
        "    [6] - Magic               \n"
        "    [7] - Subterfuge          \n"
        "    [8] - Exit Skill Menu     \n"
        "You must select a number from 1 to 8. You may also undo or reset.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "You have 2 skills left to assign.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectResearchChoice()
{
    Player->joinGuild("Scion of Dhuras");
    destruct(present_clone("lib/modules/guilds/advanceLevelSelector.c", Player));
    Player->advanceSkill("long sword", 5);
    Player->addExperience(2000);
    command("level up", Player);
    command("1", Player);
    command("4", Player);
    ExpectFalse(Player->isResearched("guilds/scion/paths/sword/root.c"));
    ExpectEq(({ "lib/instances/research/races/highElfResearchTree.c",
        "guilds/scion/common/mana-shield/mana-shield.c" }), 
        Player->availableResearchTrees());

    ExpectEq("A new research choice is available: The Focus\n"
        "    [1] - The Way of the Sword\n"
        "    [2] - The Way of the Dagger\n"
        "    [3] - The Way of the Axe\n"
        "    [4] - The Way of the Mace\n"
        "    [5] - The Way of the Hammer\n"
        "    [6] - The Way of the Staff\n"
        "You must select a number from 1 to 6.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        Player->caughtMessage());

    command("1", Player);
    ExpectTrue(Player->isResearched("guilds/scion/paths/sword/root.c"));
    ExpectEq(({ "lib/instances/research/races/highElfResearchTree.c",
        "guilds/scion/common/mana-shield/mana-shield.c",
        "guilds/scion/paths/sword.c" }),
        Player->availableResearchTrees());

    ExpectEq("Advancement - Scion of Dhuras Menu:\n"
        "[1] - Spend Attribute Points\n"
        "[2] - Spend Skill Points\n"
        "[3] - Research Choice: The Path (Sword)\n"
        "[4] - Spend Research Points                    (Select Choices First)\n"
        "[5] - Exit Advancement Menu\n"
        "You must select a number from 1 to 5.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectResearchWhenAllChoicesMade()
{
    Player->joinGuild("Scion of Dhuras");
    destruct(present_clone("lib/modules/guilds/advanceLevelSelector.c", Player));
    Player->advanceSkill("long sword", 5);
    Player->addExperience(2000);
    command("level up", Player);
    command("1", Player);
    command("4", Player);
    command("1", Player);
    command("3", Player);
    command("1", Player);

    ExpectTrue(Player->isResearched("guilds/scion/paths/sword/root.c"));
    ExpectTrue(Player->isResearched("guilds/scion/paths/sword/flame/root.c"));
    ExpectEq(({ "lib/instances/research/races/highElfResearchTree.c",
        "guilds/scion/paths/sword.c", "guilds/scion/paths/sword/flame.c",
        "guilds/scion/common/mana-shield/mana-shield.c" }),
        Player->availableResearchTrees());

    ExpectEq("Advancement - Scion of Dhuras Menu:\n"
        "[1] - Spend Attribute Points\n"
        "[2] - Spend Skill Points\n"
        "[3] - Spend Research Points\n"
        "[4] - Exit Advancement Menu\n"
        "You must select a number from 1 to 4.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectResearch()
{
    Player->joinGuild("Scion of Dhuras");
    destruct(present_clone("lib/modules/guilds/advanceLevelSelector.c", Player));
    Player->advanceSkill("long sword", 5);
    Player->addExperience(2000);
    command("level up", Player);
    command("1", Player);
    command("4", Player);
    command("1", Player);
    command("3", Player);
    command("1", Player);
    command("3", Player);

    ExpectSubStringMatch("Research - Select a research item to view in more.*"
        "Way of the Sword.*Path of the Flame.*4 research points",
        Player->caughtMessage());
}
