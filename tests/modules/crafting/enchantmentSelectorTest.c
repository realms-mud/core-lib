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
    Selector = clone_object("/lib/modules/crafting/selectMaterialsSelector.c");
    Selector->setItem("long sword");
    Selector->setType("weapons");
    Selector->setSubType("swords");

    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->addCommands();

    Player->Wis(50);
    Player->Str(50);
    Player->Int(50);
    Player->addSkillPoints(500);
    Player->advanceSkill("blacksmithing", 20);
    Player->advanceSkill("metal crafting", 10);
    Player->advanceSkill("weapon smithing", 10);
    Player->advanceSkill("chemistry", 10);
    Player->advanceSkill("physics", 10);
    Player->advanceSkill("spellcraft", 20);
    Player->advanceSkill("elemental fire", 20);
    Player->addResearchPoints(20);

    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/weapons/craftWeapons.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/weapons/swords/craftBasicSwords.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/weapons/swords/craftLongSwords.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/enchantments/craftEnchantments.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/enchantments/fire/craftFireEnchantment.c"));

    move_object(Selector, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Selector);
}

/////////////////////////////////////////////////////////////////////////////
void SelectingEnchantDisplaysEnchantmentTypeMenu()
{
    Selector->initiateSelector(Player);
    command("5", Player);

    ExpectEq("\x1b[0;36mSelect Enchantment type - \x1b[0m\x1b[0;37;1mchoose the enchantment type with which to craft\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mAbilities           \x1b[0m     \n"
        "    [\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mAttributes          \x1b[0m     \n"
        "    [\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mDefensive           \x1b[0m     \n"
        "    [\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mOffensive           \x1b[0m     \n"
        "    [\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mSkills              \x1b[0m     \n"
        "    [\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mVitals              \x1b[0m     \n"
        "    [\x1b[0;31;1m7\x1b[0m] - \x1b[0;32mExit Select Enchantment type Menu\x1b[0m     \n"
        "\x1b[0;32;1mYou must select a number from 1 to 7.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1mYou can imbue this item with 1 more (out of 1) enchantments.\n\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingEnchantAbilitiesDisplaysAbilitiesMenu()
{
    Selector->initiateSelector(Player);
    command("5", Player);
    command("1", Player);

    ExpectEq("\x1b[0;36mSelect Enchant abilities - \x1b[0m\x1b[0;37;1mchoose the enchant abilities with which to craft\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mExit Select Enchant abilities Menu\x1b[0m     \n"
        "\x1b[0;32;1mYou must select a number from 1 to 1. You may also undo or reset.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1mYou can imbue this item with 1 more (out of 1) enchantments.\n"
        "\x1b[0;32mEach \x1b[0;35;1m*\x1b[0;32m denotes that an enchantment has been chosen once (max 3 per option).\n"
        "\x1b[0;35mP\x1b[0m\x1b[0;32m denotes unrealized prerequisites.\n"
        "\x1b[0;35mM\x1b[0m\x1b[0;32m denotes that material requirements are missing.\n\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingEnchantAttributesDisplaysAttributesMenu()
{
    Selector->initiateSelector(Player);
    command("5", Player);
    command("2", Player);

    ExpectEq("\x1b[0;36mSelect Enchant attributes - \x1b[0m\x1b[0;37;1mchoose the enchant attributes with which to craft\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m] - \x1b[0;31mEnhance charisma    \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m2\x1b[0m] - \x1b[0;31mEnhance constitution\x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  \n"
        "    [\x1b[0;31;1m3\x1b[0m] - \x1b[0;31mEnhance dexterity   \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m4\x1b[0m] - \x1b[0;31mEnhance intelligence\x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  \n"
        "    [\x1b[0;31;1m5\x1b[0m] - \x1b[0;31mEnhance strength    \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m6\x1b[0m] - \x1b[0;31mEnhance wisdom      \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  \n"
        "    [\x1b[0;31;1m7\x1b[0m] - \x1b[0;32mExit Select Enchant attributes Menu\x1b[0m     \n"
        "\x1b[0;32;1mYou must select a number from 1 to 7. You may also undo or reset.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1mYou can imbue this item with 1 more (out of 1) enchantments.\n"
        "\x1b[0;32mEach \x1b[0;35;1m*\x1b[0;32m denotes that an enchantment has been chosen once (max 3 per option).\n"
        "\x1b[0;35mP\x1b[0m\x1b[0;32m denotes unrealized prerequisites.\n"
        "\x1b[0;35mM\x1b[0m\x1b[0;32m denotes that material requirements are missing.\n\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingDefensiveEnchantmentDisplaysDefensiveMenu()
{
    Selector->initiateSelector(Player);
    command("5", Player);
    command("3", Player);

    ExpectEq("\x1b[0;36mSelect Enchant defensive - \x1b[0m\x1b[0;37;1mchoose the enchant defensive with which to craft\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m]  - \x1b[0;31mAcid resistance     \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m2\x1b[0m]  - \x1b[0;31mAir resistance      \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  \n"
        "    [\x1b[0;31;1m3\x1b[0m]  - \x1b[0;31mChaos resistance    \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m4\x1b[0m]  - \x1b[0;31mCold resistance     \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  \n"
        "    [\x1b[0;31;1m5\x1b[0m]  - \x1b[0;31mDamage reflection   \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m6\x1b[0m]  - \x1b[0;31mDamage soak         \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  \n"
        "    [\x1b[0;31;1m7\x1b[0m]  - \x1b[0;31mDisease resistance  \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m8\x1b[0m]  - \x1b[0;31mEarth resistance    \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  \n"
        "    [\x1b[0;31;1m9\x1b[0m]  - \x1b[0;31mElectricity resis...\x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m10\x1b[0m] - \x1b[0;31mEnergy resistance   \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  \n"
        "    [\x1b[0;31;1m11\x1b[0m] - \x1b[0;31mEvil resistance     \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m12\x1b[0m] - \x1b[0;32mFire resistance     \x1b[0m     \n"
        "    [\x1b[0;31;1m13\x1b[0m] - \x1b[0;31mGood resistance     \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m14\x1b[0m] - \x1b[0;31mMagical resistance  \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  \n"
        "    [\x1b[0;31;1m15\x1b[0m] - \x1b[0;31mNeutral resistance  \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m16\x1b[0m] - \x1b[0;31mParalysis resistance\x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  \n"
        "    [\x1b[0;31;1m17\x1b[0m] - \x1b[0;31mPoison resistance   \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m18\x1b[0m] - \x1b[0;31mPsionic resistance  \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  \n"
        "    [\x1b[0;31;1m19\x1b[0m] - \x1b[0;31mSonic resistance    \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m20\x1b[0m] - \x1b[0;31mUndead resistance   \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  \n"
        "    [\x1b[0;31;1m21\x1b[0m] - \x1b[0;31mWater resistance    \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m22\x1b[0m] - \x1b[0;31mWeapon defense      \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  \n"
        "    [\x1b[0;31;1m23\x1b[0m] - \x1b[0;32mExit Select Enchant defensive Menu\x1b[0m     \n"
        "\x1b[0;32;1mYou must select a number from 1 to 23. You may also undo or reset.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1mYou can imbue this item with 1 more (out of 1) enchantments.\n"
        "\x1b[0;32mEach \x1b[0;35;1m*\x1b[0;32m denotes that an enchantment has been chosen once (max 3 per option).\n"
        "\x1b[0;35mP\x1b[0m\x1b[0;32m denotes unrealized prerequisites.\n"
        "\x1b[0;35mM\x1b[0m\x1b[0;32m denotes that material requirements are missing.\n\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingOffensiveEnchantmentDisplaysOffensiveMenu()
{
    Selector->initiateSelector(Player);
    command("5", Player);
    command("4", Player);

    ExpectEq("\x1b[0;36mSelect Enchant offensive - \x1b[0m\x1b[0;37;1mchoose the enchant offensive with which to craft\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m]  - \x1b[0;31mAcid enchantment    \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m2\x1b[0m]  - \x1b[0;31mAdditional attack   \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  \n"
        "    [\x1b[0;31;1m3\x1b[0m]  - \x1b[0;31mAir enchantment     \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m4\x1b[0m]  - \x1b[0;31mChaos enchantment   \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  \n"
        "    [\x1b[0;31;1m5\x1b[0m]  - \x1b[0;31mCold enchantment    \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m6\x1b[0m]  - \x1b[0;31mDisease enchantment \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  \n"
        "    [\x1b[0;31;1m7\x1b[0m]  - \x1b[0;31mEarth enchantment   \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m8\x1b[0m]  - \x1b[0;31mElectricity encha...\x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  \n"
        "    [\x1b[0;31;1m9\x1b[0m]  - \x1b[0;31mEnergy enchantment  \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m10\x1b[0m] - \x1b[0;31mEvil enchantment    \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  \n"
        "    [\x1b[0;31;1m11\x1b[0m] - \x1b[0;32mFire enchantment    \x1b[0m     "
        "    [\x1b[0;31;1m12\x1b[0m] - \x1b[0;31mGood enchantment    \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  \n"
        "    [\x1b[0;31;1m13\x1b[0m] - \x1b[0;31mMagical enchantment \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m14\x1b[0m] - \x1b[0;31mNeutral enchantment \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  \n"
        "    [\x1b[0;31;1m15\x1b[0m] - \x1b[0;31mParalysis enchant...\x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m16\x1b[0m] - \x1b[0;31mPoison enchantment  \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  \n"
        "    [\x1b[0;31;1m17\x1b[0m] - \x1b[0;31mPsionic enchantment \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m18\x1b[0m] - \x1b[0;31mSonic enchantment   \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  \n"
        "    [\x1b[0;31;1m19\x1b[0m] - \x1b[0;31mUndead enchantment  \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m20\x1b[0m] - \x1b[0;31mWater enchantment   \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  \n"
        "    [\x1b[0;31;1m21\x1b[0m] - \x1b[0;31mWeapon attack       \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m22\x1b[0m] - \x1b[0;31mWeapon damage       \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  \n"
        "    [\x1b[0;31;1m23\x1b[0m] - \x1b[0;32mExit Select Enchant offensive Menu\x1b[0m     \n"
        "\x1b[0;32;1mYou must select a number from 1 to 23. You may also undo or reset.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1mYou can imbue this item with 1 more (out of 1) enchantments.\n"
        "\x1b[0;32mEach \x1b[0;35;1m*\x1b[0;32m denotes that an enchantment has been chosen once (max 3 per option).\n"
        "\x1b[0;35mP\x1b[0m\x1b[0;32m denotes unrealized prerequisites.\n"
        "\x1b[0;35mM\x1b[0m\x1b[0;32m denotes that material requirements are missing.\n\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingSkillsEnchantmentDisplaysSkillsMenu()
{
    Selector->initiateSelector(Player);
    command("5", Player);
    command("5", Player);

    ExpectEq("\x1b[0;36mSelect Enchant skills - \x1b[0m\x1b[0;37;1mchoose the enchant skills with which to craft\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mExit Select Enchant skills Menu\x1b[0m     \n"
        "\x1b[0;32;1mYou must select a number from 1 to 1. You may also undo or reset.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1mYou can imbue this item with 1 more (out of 1) enchantments.\n"
        "\x1b[0;32mEach \x1b[0;35;1m*\x1b[0;32m denotes that an enchantment has been chosen once (max 3 per option).\n"
        "\x1b[0;35mP\x1b[0m\x1b[0;32m denotes unrealized prerequisites.\n"
        "\x1b[0;35mM\x1b[0m\x1b[0;32m denotes that material requirements are missing.\n\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingVitalsEnchantmentDisplaysVitalsMenu()
{
    Selector->initiateSelector(Player);
    command("5", Player);
    command("6", Player);

    ExpectEq("\x1b[0;36mSelect Enchant vitals - \x1b[0m\x1b[0;37;1mchoose the enchant vitals with which to craft\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m]  - \x1b[0;31mHeal hit points a...\x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m2\x1b[0m]  - \x1b[0;31mHeal hit points rate\x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  \n"
        "    [\x1b[0;31;1m3\x1b[0m]  - \x1b[0;31mHeal spell points...\x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m4\x1b[0m]  - \x1b[0;31mHeal spell points...\x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  \n"
        "    [\x1b[0;31;1m5\x1b[0m]  - \x1b[0;31mHeal stamina poin...\x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m6\x1b[0m]  - \x1b[0;31mHeal stamina poin...\x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  \n"
        "    [\x1b[0;31;1m7\x1b[0m]  - \x1b[0;31mHit points          \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m8\x1b[0m]  - \x1b[0;31mSpell points        \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  \n"
        "    [\x1b[0;31;1m9\x1b[0m]  - \x1b[0;31mStamina points      \x1b[0m\x1b[0;34;1m(\x1b[0;35mP\x1b[0;34;1m)\x1b[0m  "
        "    [\x1b[0;31;1m10\x1b[0m] - \x1b[0;32mExit Select Enchant vitals Menu\x1b[0m     \n"
        "\x1b[0;32;1mYou must select a number from 1 to 10. You may also undo or reset.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1mYou can imbue this item with 1 more (out of 1) enchantments.\n"
        "\x1b[0;32mEach \x1b[0;35;1m*\x1b[0;32m denotes that an enchantment has been chosen once (max 3 per option).\n"
        "\x1b[0;35mP\x1b[0m\x1b[0;32m denotes unrealized prerequisites.\n"
        "\x1b[0;35mM\x1b[0m\x1b[0;32m denotes that material requirements are missing.\n\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingExitReturnsToPreviousMenu()
{
    Selector->initiateSelector(Player);
    command("5", Player);
    command("7", Player);

    ExpectSubStringMatch("Exit Craft Long sword Menu",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanNotAddMoreThanMaximumEnchantmentsAllowed()
{
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/craftingBonusesResearch.c"));
    Selector->initiateSelector(Player);
    command("5", Player);
    command("4", Player);
    ExpectSubStringMatch("32mFire enchantment[ ]+..0m.*4 more", Player->caughtMessage());
    command("11", Player);
    ExpectSubStringMatch("32mFire enchantment[^(]+[(]\\*[)].*3 more", Player->caughtMessage());
    command("11", Player);
    ExpectSubStringMatch("32mFire enchantment[^(]+[(]\\*\\*[)].*2 more", Player->caughtMessage());
    command("11", Player);
    ExpectSubStringMatch("32mFire enchantment[^(]+[(]\\*\\*\\*[)].*1 more", Player->caughtMessage());
    command("11", Player);
    ExpectSubStringMatch("32mFire enchantment[^(]+[(]\\*\\*\\*[)].*1 more", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionCanBeZeroToThreeEntriesAndDoesNotIncreaseBeyondThree()
{
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/craftingBonusesResearch.c"));
    Selector->initiateSelector(Player);
    command("5", Player);
    command("4", Player);
    ExpectSubStringMatch("32mFire enchantment[ ]+..0m.*4 more", Player->caughtMessage());
    command("11", Player);
    ExpectSubStringMatch("32mFire enchantment[^(]+[(]\\*[)].*3 more", Player->caughtMessage());
    command("11", Player);
    ExpectSubStringMatch("32mFire enchantment[^(]+[(]\\*\\*[)].*2 more", Player->caughtMessage());
    command("11", Player);
    ExpectSubStringMatch("32mFire enchantment[^(]+[(]\\*\\*\\*[)].*1 more", Player->caughtMessage());
    command("11", Player);
    ExpectSubStringMatch("32mFire enchantment[^(]+[(]\\*\\*\\*[)].*1 more", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanUndoSelection()
{
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/craftingBonusesResearch.c"));
    Selector->initiateSelector(Player);
    command("5", Player);
    command("4", Player);
    ExpectSubStringMatch("32mFire enchantment[ ]+..0m", Player->caughtMessage());
    command("11", Player);
    ExpectSubStringMatch("32mFire enchantment[^(]+[(]\\*[)]", Player->caughtMessage());
    command("11", Player);
    ExpectSubStringMatch("32mFire enchantment[^(]+[(]\\*\\*[)]", Player->caughtMessage());
    command("undo", Player);
    ExpectSubStringMatch("32mFire enchantment[^(]+[(]\\*[)]", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChangesToEnchantmentSelectionIsPropegatedToOtherMenus()
{
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/craftingBonusesResearch.c"));
    Selector->initiateSelector(Player);
    command("5", Player);
    command("4", Player);
    ExpectSubStringMatch("32mFire enchantment[ ]+..0m.*4 more.*out of 4", Player->caughtMessage());
    command("11", Player);
    ExpectSubStringMatch("32mFire enchantment[ ]+..0m.*3 more.*out of 4", Player->caughtMessage());
    command("11", Player);
    ExpectSubStringMatch("32mFire enchantment[ ]+..0m.*2 more.*out of 4", Player->caughtMessage());
    command("23", Player);
    ExpectSubStringMatch("Select Enchantment type.*2 more.*out of 4", Player->caughtMessage());
}