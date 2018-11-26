//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Selector;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/modules/crafting/craftItemSelector.c");
    Selector->setType("weapons");
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->addCommands();

    move_object(Selector, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Selector);
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelMenuWithoutAnyPrereqsMetDisplaysCorrectly()
{
    Selector->initiateSelector(Player);

    ExpectEq("\x1b[0;36mCraft Weapons - \x1b[0m\x1b[0;37;1mFrom this menu, you can craft items\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m]  - \x1b[0;32mAxe                 \x1b[0m\n"
        "    [\x1b[0;31;1m2\x1b[0m]  - \x1b[0;32mBow                 \x1b[0m\n"
        "    [\x1b[0;31;1m3\x1b[0m]  - \x1b[0;32mCrossbow            \x1b[0m\n"
        "    [\x1b[0;31;1m4\x1b[0m]  - \x1b[0;32mDagger              \x1b[0m\n"
        "    [\x1b[0;31;1m5\x1b[0m]  - \x1b[0;32mFlail               \x1b[0m\n"
        "    [\x1b[0;31;1m6\x1b[0m]  - \x1b[0;32mHammer              \x1b[0m\n"
        "    [\x1b[0;31;1m7\x1b[0m]  - \x1b[0;32mMace                \x1b[0m\n"
        "    [\x1b[0;31;1m8\x1b[0m]  - \x1b[0;32mPole arm            \x1b[0m\n"
        "    [\x1b[0;31;1m9\x1b[0m]  - \x1b[0;32mShield              \x1b[0m\n"
        "    [\x1b[0;31;1m10\x1b[0m] - \x1b[0;32mSling               \x1b[0m\n"
        "    [\x1b[0;31;1m11\x1b[0m] - \x1b[0;32mStaff               \x1b[0m\n"
        "    [\x1b[0;31;1m12\x1b[0m] - \x1b[0;32mSword               \x1b[0m\n"
        "    [\x1b[0;31;1m13\x1b[0m] - \x1b[0;32mThrown              \x1b[0m\n"
        "    [\x1b[0;31;1m14\x1b[0m] - \x1b[0;32mExit Craft Weapons Menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 14.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingAxeDisplaysAxeMenu()
{
    Selector->initiateSelector(Player);
    command("1", Player);

    ExpectSubStringMatch("36mCraft Axe.*Exit Craft Axe",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingBowDisplaysBowMenu()
{
    Selector->initiateSelector(Player);
    command("2", Player);

    ExpectSubStringMatch("36mCraft Bow.*Exit Craft Bow",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingCrossbowDisplaysCrossbowMenu()
{
    Selector->initiateSelector(Player);
    command("3", Player);

    ExpectSubStringMatch("36mCraft Crossbow.*Exit Craft Crossbow",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingDaggerDisplaysDaggerMenu()
{
    Selector->initiateSelector(Player);
    command("4", Player);

    ExpectSubStringMatch("36mCraft Dagger.*Exit Craft Dagger",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingFlailDisplaysFlailMenu()
{
    Selector->initiateSelector(Player);
    command("5", Player);

    ExpectSubStringMatch("36mCraft Flail.*Exit Craft Flail",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingHammerDisplaysHammerMenu()
{
    Selector->initiateSelector(Player);
    command("6", Player);

    ExpectSubStringMatch("36mCraft Hammer.*Exit Craft Hammer",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingMaceDisplaysMaceMenu()
{
    Selector->initiateSelector(Player);
    command("7", Player);

    ExpectSubStringMatch("36mCraft Mace.*Exit Craft Mace",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingPoleArmDisplaysPoleArmMenu()
{
    Selector->initiateSelector(Player);
    command("8", Player);

    ExpectSubStringMatch("36mCraft Pole arm.*Exit Craft Pole arm",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingShieldDisplaysShieldMenu()
{
    Selector->initiateSelector(Player);
    command("9", Player);

    ExpectSubStringMatch("36mCraft Shield.*Exit Craft Shield",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingSlingDisplaysSlingMenu()
{
    Selector->initiateSelector(Player);
    command("10", Player);

    ExpectSubStringMatch("36mCraft Sling.*Exit Craft Sling",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingStaffDisplaysStaffMenu()
{
    Selector->initiateSelector(Player);
    command("11", Player);

    ExpectSubStringMatch("36mCraft Staff.*Exit Craft Staff",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingSwordDisplaysSwordMenu()
{
    Selector->initiateSelector(Player);
    command("12", Player);

    ExpectSubStringMatch("36mCraft Sword.*Exit Craft Sword",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingThrownDisplaysThrownMenu()
{
    Selector->initiateSelector(Player);
    command("13", Player);

    ExpectSubStringMatch("36mCraft Thrown.*Exit Craft Thrown",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SubmenuChoicesDisabledWhenMaterialAndPrerequisiteChecksFail()
{
    Selector->initiateSelector(Player);
    command("12", Player);
    command("1", Player);

    ExpectSubStringMatch("36mCraft Sword.*Exit Craft Sword",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionDisabledWhenMaterialAndPrerequisiteChecksFail()
{
    Selector->initiateSelector(Player);
    command("12", Player);

    ExpectSubStringMatch("31mLong sword.*35m.P,M",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionDisabledWhenMaterialCheckFailsButPrerequisitesPass()
{
    Player->Wis(20);
    Player->Str(20);
    Player->addSkillPoints(100);
    Player->advanceSkill("blacksmithing", 10);
    Player->advanceSkill("metal crafting", 10);
    Player->advanceSkill("weapon smithing", 10);

    Player->addResearchPoints(2);
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/weapons/craftWeapons.c"));
    ExpectTrue(Player->addResearchTree("lib/instances/research/crafting/weapons/swords/swordsmithing.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/weapons/common/annealing.c"), "annealing");
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/weapons/swords/craftLongSwords.c"), "long swords");

    Selector->initiateSelector(Player);
    command("12", Player);

    ExpectSubStringMatch("31mLong sword.*35m.M",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionEnabledWhenMaterialCheckPassesButPrerequisitesFail()
{
    Player->Wis(20);
    Player->Str(20);
    Player->addSkillPoints(100);
    Player->advanceSkill("blacksmithing", 10);
    Player->advanceSkill("metal crafting", 10);
    Player->advanceSkill("weapon smithing", 10);

    object material = clone_object("/lib/instances/items/materials/metal/admantite.c");
    material->set("quantity", 5);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/admantite.c");
    material->set("quantity", 6);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/steel.c");
    material->set("quantity", 10);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/wood/koa.c");
    material->set("quantity", 5);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/leather/pegasus-leather.c");
    material->set("quantity", 5);
    move_object(material, Player);

    Selector->initiateSelector(Player);
    command("12", Player);

    ExpectSubStringMatch("31mLong sword.*35m.P",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionEnabledWhenMaterialCheckAndPrerequisitesPass()
{
    Player->Wis(20);
    Player->Str(20);
    Player->addSkillPoints(100);
    Player->advanceSkill("blacksmithing", 10);
    Player->advanceSkill("metal crafting", 10);
    Player->advanceSkill("weapon smithing", 10);

    object material = clone_object("/lib/instances/items/materials/metal/admantite.c");
    material->set("quantity", 5);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/admantite.c");
    material->set("quantity", 6);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/steel.c");
    material->set("quantity", 10);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/wood/koa.c");
    material->set("quantity", 5);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/leather/pegasus-leather.c");
    material->set("quantity", 5);
    move_object(material, Player);

    Player->addResearchPoints(2);
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/weapons/craftWeapons.c"));
    ExpectTrue(Player->addResearchTree("lib/instances/research/crafting/weapons/swords/swordsmithing.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/weapons/common/annealing.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/weapons/swords/craftLongSwords.c"));

    Selector->initiateSelector(Player);
    command("12", Player);

    ExpectSubStringMatch("32mLong sword[^()]+",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingItemOpensSelectMaterialMenu()
{
    Player->Wis(20);
    Player->Str(20);
    Player->addSkillPoints(100);
    Player->advanceSkill("blacksmithing", 10);
    Player->advanceSkill("metal crafting", 10);
    Player->advanceSkill("weapon smithing", 10);

    object material = clone_object("/lib/instances/items/materials/metal/admantite.c");
    material->set("quantity", 5);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/admantite.c");
    material->set("quantity", 6);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/steel.c");
    material->set("quantity", 10);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/wood/koa.c");
    material->set("quantity", 5);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/leather/pegasus-leather.c");
    material->set("quantity", 5);
    move_object(material, Player);

    Player->addResearchPoints(2);
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/weapons/craftWeapons.c"));
    ExpectTrue(Player->addResearchTree("lib/instances/research/crafting/weapons/swords/swordsmithing.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/weapons/common/annealing.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/weapons/swords/craftLongSwords.c"));

    Selector->initiateSelector(Player);
    command("12", Player);
    command("10", Player);

    ExpectSubStringMatch("36mCraft Long sword.*Exit Craft Long sword",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingExitReturnsToTopLevelMenu()
{
    Selector->initiateSelector(Player);
    command("14", Player);

    ExpectSubStringMatch("You have selected 'Exit Craft Weapons Menu'",
        Player->caughtMessage());
}
