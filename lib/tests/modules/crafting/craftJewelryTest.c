//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Selector;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/modules/crafting/craftItemSelector.c");
    Selector->setType("armor");
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->addCommands();

    Player->Wis(50);
    Player->Str(50);
    Player->Int(50);
    Player->addSkillPoints(500);
    Player->advanceSkill("sewing", 10);
    Player->advanceSkill("metal crafting", 50);
    Player->advanceSkill("gem crafting", 20);
    Player->advanceSkill("armorer", 10);
    Player->advanceSkill("blacksmithing", 10);
    Player->advanceSkill("chemistry", 10);
    Player->advanceSkill("physics", 10);
    Player->advanceSkill("sculpture", 10);
    Player->addResearchPoints(20);

    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/armor/craftJewelry.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftCommonMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftUncommonMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftAlloy.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftRareMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftPreciousMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftMythicMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftGems.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftRareGems.c"));

    object material = clone_object("/lib/instances/items/materials/textile/silk.c");
    material->set("quantity", 15);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/admantite.c");
    material->set("quantity", 15);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/gold.c");
    material->set("quantity", 15);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/crystal/ruby.c");
    material->set("quantity", 15);
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
    Selector->initiateSelector(Player);
    command("1", Player);

    ExpectEq("\x1b[0;36mCraft Accessory - \x1b[0m\x1b[0;37;1mFrom this menu, you can craft items\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m]  - \x1b[0;32mAmulet              \x1b[0m     "
        "    [\x1b[0;31;1m2\x1b[0m]  - \x1b[0;31mBelt                \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m3\x1b[0m]  - \x1b[0;31mBoots               \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m4\x1b[0m]  - \x1b[0;31mBracelet            \x1b[0m\x1b[0;35m(P)\x1b[0m  \n"
        "    [\x1b[0;31;1m5\x1b[0m]  - \x1b[0;31mBracers             \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m6\x1b[0m]  - \x1b[0;32mCirclet             \x1b[0m     \n"
        "    [\x1b[0;31;1m7\x1b[0m]  - \x1b[0;31mCoif                \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m8\x1b[0m]  - \x1b[0;32mCrown               \x1b[0m     \n"
        "    [\x1b[0;31;1m9\x1b[0m]  - \x1b[0;32mDiadem              \x1b[0m     "
        "    [\x1b[0;31;1m10\x1b[0m] - \x1b[0;31mGauntlets           \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m11\x1b[0m] - \x1b[0;31mGloves              \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m12\x1b[0m] - \x1b[0;31mHat                 \x1b[0m\x1b[0;35m(P)\x1b[0m  \n"
        "    [\x1b[0;31;1m13\x1b[0m] - \x1b[0;31mHelm                \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m14\x1b[0m] - \x1b[0;31mHelmet              \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m15\x1b[0m] - \x1b[0;32mNecklace            \x1b[0m     "
        "    [\x1b[0;31;1m16\x1b[0m] - \x1b[0;32mRing                \x1b[0m     \n"
        "    [\x1b[0;31;1m17\x1b[0m] - \x1b[0;31mSabaton             \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m18\x1b[0m] - \x1b[0;31mSandals             \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m19\x1b[0m] - \x1b[0;31mSash                \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m20\x1b[0m] - \x1b[0;31mShoes               \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m21\x1b[0m] - \x1b[0;32mTiara               \x1b[0m     "
        "    [\x1b[0;31;1m22\x1b[0m] - \x1b[0;32mExit Craft Accessory Menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 22.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1m\x1b[0;35mP\x1b[0m\x1b[0;32m denotes unrealized prerequisites.\n"
        "\x1b[0m\x1b[0;35mM\x1b[0m\x1b[0;32m denotes that proper quantities of the material requirements are missing.\n\x1b[0m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingRingDisplaysRingMenu()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/armor/craftClothing.c"));
    Selector->initiateSelector(Player);
    command("1", Player);
    command("16", Player);

    ExpectEq("\x1b[0;36mCraft Ring - \x1b[0m\x1b[0;37;1mFrom this menu, you "
        "will select the components that will be used\nto craft your ring. "
        "The relative statistics for the item you are creating are:\n\n"
        "\x1b[0m\x1b[0;36m\tMaterial: \x1b[0;31mnone selected\x1b[0m\n\x1b[0m\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mSelect Metal        \x1b[0m\n"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mSelect Ring design  \x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;31mEnchant Ring        \x1b[0m\n"
        "\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mGive ring a name    \x1b[0m\n"
        "\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mGive ring a special description\x1b[0m\n"
        "\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;31mCraft Selected Ring \x1b[0m\n"
        "\t[\x1b[0;31;1m7\x1b[0m] - \x1b[0;32mExit Craft Ring Menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 7.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1m\x1b[0;34;1m(*)\x1b[0m\x1b[0;32m denotes that a specific component type has been chosen.\n\x1b[0m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingSelectMaterialDisplaysMaterialMenu()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/armor/craftClothing.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftTextiles.c"));
    Player->advanceSkill("weaving and beadwork", 10);
    Selector->initiateSelector(Player);
    command("1", Player);
    command("16", Player);
    command("1", Player);

    ExpectSubStringMatch("32mAdmantite.*31mAluminum.*Exit Select Metal",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingMaterialUpdatesRingMenu()
{
    Selector->initiateSelector(Player);
    command("1", Player);
    command("16", Player);
    command("1", Player);
    command("1", Player);

    ExpectEq("\x1b[0;36mCraft Ring - \x1b[0m\x1b[0;37;1mFrom this menu, you "
        "will select the components that will be used\nto craft your ring. "
        "The relative statistics for the item you are creating are:\n\n"
        "\x1b[0m\x1b[0;36m\tMaterial: \x1b[0m\x1b[0;33mAdmantite\x1b[0m\n\x1b[0m\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mSelect Metal        \x1b[0m\x1b[0;34;1m   (*)\x1b[0m\n"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mSelect Ring design  \x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;31mEnchant Ring        \x1b[0m\n"
        "\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mGive ring a name    \x1b[0m\n"
        "\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mGive ring a special description\x1b[0m\n"
        "\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;31mCraft Selected Ring \x1b[0m\n"
        "\t[\x1b[0;31;1m7\x1b[0m] - \x1b[0;32mExit Craft Ring Menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 7.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1m\x1b[0;34;1m(*)\x1b[0m\x1b[0;32m denotes that a specific component type has been chosen.\n\x1b[0m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanAddComponentThatDoesNotModifyMaterials()
{
    Selector->initiateSelector(Player);
    command("1", Player);
    command("16", Player);
    command("2", Player);
    command("10", Player);
    command("19", Player);

    ExpectEq("\x1b[0;36mCraft Ring - \x1b[0m\x1b[0;37;1mFrom this menu, you "
        "will select the components that will be used\nto craft your ring. "
        "The relative statistics for the item you are creating are:\n\n"
        "\x1b[0m\x1b[0;36m\tMaterial: \x1b[0;31mnone selected\x1b[0m\n\x1b[0m\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mSelect Metal        \x1b[0m\n"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mSelect Ring design  \x1b[0m\x1b[0;34;1m   (*)\x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;31mEnchant Ring        \x1b[0m\n"
        "\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mGive ring a name    \x1b[0m\n"
        "\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mGive ring a special description\x1b[0m\n"
        "\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;31mCraft Selected Ring \x1b[0m\n"
        "\t[\x1b[0;31;1m7\x1b[0m] - \x1b[0;32mExit Craft Ring Menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 7.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1m\x1b[0;34;1m(*)\x1b[0m\x1b[0;32m denotes that a specific component type has been chosen.\n\x1b[0m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotSelectComponentUntilMaterialsChosen()
{
    Selector->initiateSelector(Player);
    command("1", Player);
    command("16", Player);
    command("2", Player);
    command("7", Player);

    ExpectSubStringMatch("31mConfirm", Player->caughtMessage());

    command("1", Player);
    command("25", Player);
    ExpectSubStringMatch("31mConfirm", Player->caughtMessage());

    command("2", Player);
    command("16", Player);
    ExpectSubStringMatch("32mConfirm", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectComponentIfUnusedMaterialTypeNotSelected()
{
    Selector->initiateSelector(Player);
    command("1", Player);
    command("16", Player);
    command("2", Player);
    command("3", Player);

    ExpectSubStringMatch("31mConfirm", Player->caughtMessage());

    command("2", Player);
    command("16", Player);
    ExpectSubStringMatch("32mConfirm", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanCraftItemWithBothPrimaryMaterialAndComponent()
{
    Selector->initiateSelector(Player);
    command("1", Player);
    command("16", Player);
    command("2", Player);
    command("7", Player);
    command("1", Player);
    command("25", Player);
    command("2", Player);
    command("16", Player);
    command("19", Player);
    command("1", Player);
    command("1", Player);
    command("6", Player);

    ExpectSubStringMatch("This is a small band of admantite worn on the finger. The ring design is a\n"
        "ring of gold and admantite that has been intricately carved into the shape of\n"
        "an eagle's talon embossed with gold. It is clutching "
        "a large ruby.", present("ring", Player)->long());
}
