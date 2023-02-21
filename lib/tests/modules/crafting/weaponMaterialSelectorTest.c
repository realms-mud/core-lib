//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Selector;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/modules/crafting/selectMaterialsSelector.c");
    Selector.setItem("long sword");
    Selector.setType("weapons");
    Selector.setSubType("swords");

    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("bob");
    Player.addCommands();

    Player.Wis(50);
    Player.Str(50);
    Player.Int(50);
    Player.addSkillPoints(500);
    Player.advanceSkill("blacksmithing", 20);
    Player.advanceSkill("metal crafting", 10);
    Player.advanceSkill("weapon smithing", 10);
    Player.advanceSkill("chemistry", 10);
    Player.advanceSkill("physics", 10);
    Player.addResearchPoints(20);
    
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/weapons/craftWeapons.c"));
    ExpectTrue(Player.addResearchTree("/lib/instances/research/crafting/weapons/swords/swordsmithing.c"));
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/weapons/common/annealing.c"));
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/weapons/swords/craftLongSwords.c"));

    move_object(Selector, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Selector);
}

/////////////////////////////////////////////////////////////////////////////
void SelectingMaterialDisplaysComponentMenu()
{
    Selector.initiateSelector(Player);
    command("1", Player);
    command("1", Player);

    ExpectEq("\x1b[0;36mSelect Metal - \x1b[0m\x1b[0;37;1mchoose a metal with which to craft\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m]  - \x1b[0;31mAdmantite           \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m2\x1b[0m]  - \x1b[0;31mAluminum            \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m3\x1b[0m]  - \x1b[0;31mAluminum bronze     \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m4\x1b[0m]  - \x1b[0;31mAntimony            \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m5\x1b[0m]  - \x1b[0;31mAsurnalt            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m6\x1b[0m]  - \x1b[0;31mBismuth             \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m7\x1b[0m]  - \x1b[0;31mBrass               \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m8\x1b[0m]  - \x1b[0;31mBronze              \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m9\x1b[0m]  - \x1b[0;31mCast iron           \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m10\x1b[0m] - \x1b[0;31mCobalt              \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m11\x1b[0m] - \x1b[0;31mCopper              \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m12\x1b[0m] - \x1b[0;31mCupronickel         \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m13\x1b[0m] - \x1b[0;31mDurnalt             \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m14\x1b[0m] - \x1b[0;31mElectrum            \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m15\x1b[0m] - \x1b[0;31mGalvorn             \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m16\x1b[0m] - \x1b[0;31mGold                \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m17\x1b[0m] - \x1b[0;31mGraphite            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m18\x1b[0m] - \x1b[0;31mGwyrnalt            \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m19\x1b[0m] - \x1b[0;31mIridium             \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m20\x1b[0m] - \x1b[0;31mIron                \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m21\x1b[0m] - \x1b[0;31mKirdarium           \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m22\x1b[0m] - \x1b[0;31mKirnalt             \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m23\x1b[0m] - \x1b[0;31mLead                \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m24\x1b[0m] - \x1b[0;31mMagnalium           \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m25\x1b[0m] - \x1b[0;31mMagnesium           \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m26\x1b[0m] - \x1b[0;31mMarnalt             \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m27\x1b[0m] - \x1b[0;31mMelynalt            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m28\x1b[0m] - \x1b[0;31mMeteoric iron       \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m29\x1b[0m] - \x1b[0;31mMithril             \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m30\x1b[0m] - \x1b[0;31mNickel              \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m31\x1b[0m] - \x1b[0;31mNurilium            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m32\x1b[0m] - \x1b[0;31mOsmium              \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m33\x1b[0m] - \x1b[0;31mPalladium           \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m34\x1b[0m] - \x1b[0;31mPewter              \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m35\x1b[0m] - \x1b[0;31mPlatinum            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m36\x1b[0m] - \x1b[0;31mRhudnalt            \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m37\x1b[0m] - \x1b[0;31mSilver              \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m38\x1b[0m] - \x1b[0;31mSteel               \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m39\x1b[0m] - \x1b[0;31mTantalum            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m40\x1b[0m] - \x1b[0;31mTin                 \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m41\x1b[0m] - \x1b[0;31mTitanium            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m42\x1b[0m] - \x1b[0;31mTrynalt             \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m43\x1b[0m] - \x1b[0;31mTungsten            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m44\x1b[0m] - \x1b[0;31mZinc                \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n" +
        "    [\x1b[0;31;1m45\x1b[0m] - \x1b[0;32mExit Select Metal Menu\x1b[0m     \n"
        "\x1b[0;32;1mYou must select a number from 1 to 45.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1m\x1b[0;35mP\x1b[0m\x1b[0;32m denotes unrealized prerequisites.\n"
        "\x1b[0m\x1b[0;35mM\x1b[0m\x1b[0;32m denotes that proper quantities of the material requirements are missing.\n\x1b[0m\x1b[0m",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PFlagRemovedWhenPrerequisitesMet()
{
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftCommonMetal.c"));
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftUncommonMetal.c"));
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftAlloy.c"));
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftRareMetal.c"));
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftPreciousMetal.c"));
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftMythicMetal.c"));
    Selector.initiateSelector(Player);
    command("1", Player);
    command("1", Player);

    ExpectEq("\x1b[0;36mSelect Metal - \x1b[0m\x1b[0;37;1mchoose a metal with which to craft\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m]  - \x1b[0;31mAdmantite           \x1b[0m\x1b[0;35m(M)\x1b[0m  "
        "    [\x1b[0;31;1m2\x1b[0m]  - \x1b[0;31mAluminum            \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m3\x1b[0m]  - \x1b[0;31mAluminum bronze     \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m4\x1b[0m]  - \x1b[0;31mAntimony            \x1b[0m\x1b[0;35m(M)\x1b[0m  \n"
        "    [\x1b[0;31;1m5\x1b[0m]  - \x1b[0;31mAsurnalt            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m6\x1b[0m]  - \x1b[0;31mBismuth             \x1b[0m\x1b[0;35m(M)\x1b[0m  \n"
        "    [\x1b[0;31;1m7\x1b[0m]  - \x1b[0;31mBrass               \x1b[0m\x1b[0;35m(M)\x1b[0m  "
        "    [\x1b[0;31;1m8\x1b[0m]  - \x1b[0;31mBronze              \x1b[0m\x1b[0;35m(M)\x1b[0m  \n"
        "    [\x1b[0;31;1m9\x1b[0m]  - \x1b[0;31mCast iron           \x1b[0m\x1b[0;35m(M)\x1b[0m  "
        "    [\x1b[0;31;1m10\x1b[0m] - \x1b[0;31mCobalt              \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m11\x1b[0m] - \x1b[0;31mCopper              \x1b[0m\x1b[0;35m(M)\x1b[0m  "
        "    [\x1b[0;31;1m12\x1b[0m] - \x1b[0;31mCupronickel         \x1b[0m\x1b[0;35m(M)\x1b[0m  \n"
        "    [\x1b[0;31;1m13\x1b[0m] - \x1b[0;31mDurnalt             \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m14\x1b[0m] - \x1b[0;31mElectrum            \x1b[0m\x1b[0;35m(M)\x1b[0m  \n"
        "    [\x1b[0;31;1m15\x1b[0m] - \x1b[0;31mGalvorn             \x1b[0m\x1b[0;35m(M)\x1b[0m  "
        "    [\x1b[0;31;1m16\x1b[0m] - \x1b[0;31mGold                \x1b[0m\x1b[0;35m(M)\x1b[0m  \n"
        "    [\x1b[0;31;1m17\x1b[0m] - \x1b[0;31mGraphite            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m18\x1b[0m] - \x1b[0;31mGwyrnalt            \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m19\x1b[0m] - \x1b[0;31mIridium             \x1b[0m\x1b[0;35m(M)\x1b[0m  "
        "    [\x1b[0;31;1m20\x1b[0m] - \x1b[0;31mIron                \x1b[0m\x1b[0;35m(M)\x1b[0m  \n"
        "    [\x1b[0;31;1m21\x1b[0m] - \x1b[0;31mKirdarium           \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m22\x1b[0m] - \x1b[0;31mKirnalt             \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m23\x1b[0m] - \x1b[0;31mLead                \x1b[0m\x1b[0;35m(M)\x1b[0m  "
        "    [\x1b[0;31;1m24\x1b[0m] - \x1b[0;31mMagnalium           \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m25\x1b[0m] - \x1b[0;31mMagnesium           \x1b[0m\x1b[0;35m(M)\x1b[0m  "
        "    [\x1b[0;31;1m26\x1b[0m] - \x1b[0;31mMarnalt             \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m27\x1b[0m] - \x1b[0;31mMelynalt            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m28\x1b[0m] - \x1b[0;31mMeteoric iron       \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m29\x1b[0m] - \x1b[0;31mMithril             \x1b[0m\x1b[0;35m(M)\x1b[0m  "
        "    [\x1b[0;31;1m30\x1b[0m] - \x1b[0;31mNickel              \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m31\x1b[0m] - \x1b[0;31mNurilium            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m32\x1b[0m] - \x1b[0;31mOsmium              \x1b[0m\x1b[0;35m(M)\x1b[0m  \n"
        "    [\x1b[0;31;1m33\x1b[0m] - \x1b[0;31mPalladium           \x1b[0m\x1b[0;35m(M)\x1b[0m  "
        "    [\x1b[0;31;1m34\x1b[0m] - \x1b[0;31mPewter              \x1b[0m\x1b[0;35m(M)\x1b[0m  \n"
        "    [\x1b[0;31;1m35\x1b[0m] - \x1b[0;31mPlatinum            \x1b[0m\x1b[0;35m(M)\x1b[0m  "
        "    [\x1b[0;31;1m36\x1b[0m] - \x1b[0;31mRhudnalt            \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m37\x1b[0m] - \x1b[0;31mSilver              \x1b[0m\x1b[0;35m(M)\x1b[0m  "
        "    [\x1b[0;31;1m38\x1b[0m] - \x1b[0;31mSteel               \x1b[0m\x1b[0;35m(M)\x1b[0m  \n"
        "    [\x1b[0;31;1m39\x1b[0m] - \x1b[0;31mTantalum            \x1b[0m\x1b[0;35m(M)\x1b[0m  "
        "    [\x1b[0;31;1m40\x1b[0m] - \x1b[0;31mTin                 \x1b[0m\x1b[0;35m(M)\x1b[0m  \n"
        "    [\x1b[0;31;1m41\x1b[0m] - \x1b[0;31mTitanium            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m42\x1b[0m] - \x1b[0;31mTrynalt             \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m43\x1b[0m] - \x1b[0;31mTungsten            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m44\x1b[0m] - \x1b[0;31mZinc                \x1b[0m\x1b[0;35m(M)\x1b[0m  \n" +
        "    [\x1b[0;31;1m45\x1b[0m] - \x1b[0;32mExit Select Metal Menu\x1b[0m     \n"
        "\x1b[0;32;1mYou must select a number from 1 to 45.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1m\x1b[0;35mP\x1b[0m\x1b[0;32m denotes unrealized prerequisites.\n"
        "\x1b[0m\x1b[0;35mM\x1b[0m\x1b[0;32m denotes that proper quantities of the material requirements are missing.\n\x1b[0m\x1b[0m",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MFlagRemovedWhenQuantityMet()
{
    object material = clone_object("/lib/instances/items/materials/metal/admantite.c");
    material.set("quantity", 6);
    move_object(material, Player);

    Selector.initiateSelector(Player);
    command("1", Player);
    command("1", Player);

    ExpectEq("\x1b[0;36mSelect Metal - \x1b[0m\x1b[0;37;1mchoose a metal with which to craft\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m]  - \x1b[0;31mAdmantite           \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m2\x1b[0m]  - \x1b[0;31mAluminum            \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m3\x1b[0m]  - \x1b[0;31mAluminum bronze     \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m4\x1b[0m]  - \x1b[0;31mAntimony            \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m5\x1b[0m]  - \x1b[0;31mAsurnalt            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m6\x1b[0m]  - \x1b[0;31mBismuth             \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m7\x1b[0m]  - \x1b[0;31mBrass               \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m8\x1b[0m]  - \x1b[0;31mBronze              \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m9\x1b[0m]  - \x1b[0;31mCast iron           \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m10\x1b[0m] - \x1b[0;31mCobalt              \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m11\x1b[0m] - \x1b[0;31mCopper              \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m12\x1b[0m] - \x1b[0;31mCupronickel         \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m13\x1b[0m] - \x1b[0;31mDurnalt             \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m14\x1b[0m] - \x1b[0;31mElectrum            \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m15\x1b[0m] - \x1b[0;31mGalvorn             \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m16\x1b[0m] - \x1b[0;31mGold                \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m17\x1b[0m] - \x1b[0;31mGraphite            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m18\x1b[0m] - \x1b[0;31mGwyrnalt            \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m19\x1b[0m] - \x1b[0;31mIridium             \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m20\x1b[0m] - \x1b[0;31mIron                \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m21\x1b[0m] - \x1b[0;31mKirdarium           \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m22\x1b[0m] - \x1b[0;31mKirnalt             \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m23\x1b[0m] - \x1b[0;31mLead                \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m24\x1b[0m] - \x1b[0;31mMagnalium           \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m25\x1b[0m] - \x1b[0;31mMagnesium           \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m26\x1b[0m] - \x1b[0;31mMarnalt             \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m27\x1b[0m] - \x1b[0;31mMelynalt            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m28\x1b[0m] - \x1b[0;31mMeteoric iron       \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m29\x1b[0m] - \x1b[0;31mMithril             \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m30\x1b[0m] - \x1b[0;31mNickel              \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m31\x1b[0m] - \x1b[0;31mNurilium            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m32\x1b[0m] - \x1b[0;31mOsmium              \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m33\x1b[0m] - \x1b[0;31mPalladium           \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m34\x1b[0m] - \x1b[0;31mPewter              \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m35\x1b[0m] - \x1b[0;31mPlatinum            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m36\x1b[0m] - \x1b[0;31mRhudnalt            \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m37\x1b[0m] - \x1b[0;31mSilver              \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m38\x1b[0m] - \x1b[0;31mSteel               \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m39\x1b[0m] - \x1b[0;31mTantalum            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m40\x1b[0m] - \x1b[0;31mTin                 \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m41\x1b[0m] - \x1b[0;31mTitanium            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m42\x1b[0m] - \x1b[0;31mTrynalt             \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m43\x1b[0m] - \x1b[0;31mTungsten            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m44\x1b[0m] - \x1b[0;31mZinc                \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n" +
        "    [\x1b[0;31;1m45\x1b[0m] - \x1b[0;32mExit Select Metal Menu\x1b[0m     \n"
        "\x1b[0;32;1mYou must select a number from 1 to 45.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1m\x1b[0;35mP\x1b[0m\x1b[0;32m denotes unrealized prerequisites.\n"
        "\x1b[0m\x1b[0;35mM\x1b[0m\x1b[0;32m denotes that proper quantities of the material requirements are missing.\n\x1b[0m\x1b[0m",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void QuantityCanBeSpreadAcrossMultipleObjects()
{
    object material = clone_object("/lib/instances/items/materials/metal/admantite.c");
    material.set("quantity", 2);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/admantite.c");
    material.set("quantity", 2);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/admantite.c");
    material.set("quantity", 1);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/admantite.c");
    material.set("quantity", 1);
    move_object(material, Player);

    Selector.initiateSelector(Player);
    command("1", Player);
    command("1", Player);

    ExpectEq("\x1b[0;36mSelect Metal - \x1b[0m\x1b[0;37;1mchoose a metal with which to craft\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m]  - \x1b[0;31mAdmantite           \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m2\x1b[0m]  - \x1b[0;31mAluminum            \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m3\x1b[0m]  - \x1b[0;31mAluminum bronze     \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m4\x1b[0m]  - \x1b[0;31mAntimony            \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m5\x1b[0m]  - \x1b[0;31mAsurnalt            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m6\x1b[0m]  - \x1b[0;31mBismuth             \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m7\x1b[0m]  - \x1b[0;31mBrass               \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m8\x1b[0m]  - \x1b[0;31mBronze              \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m9\x1b[0m]  - \x1b[0;31mCast iron           \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m10\x1b[0m] - \x1b[0;31mCobalt              \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m11\x1b[0m] - \x1b[0;31mCopper              \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m12\x1b[0m] - \x1b[0;31mCupronickel         \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m13\x1b[0m] - \x1b[0;31mDurnalt             \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m14\x1b[0m] - \x1b[0;31mElectrum            \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m15\x1b[0m] - \x1b[0;31mGalvorn             \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m16\x1b[0m] - \x1b[0;31mGold                \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m17\x1b[0m] - \x1b[0;31mGraphite            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m18\x1b[0m] - \x1b[0;31mGwyrnalt            \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m19\x1b[0m] - \x1b[0;31mIridium             \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m20\x1b[0m] - \x1b[0;31mIron                \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m21\x1b[0m] - \x1b[0;31mKirdarium           \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m22\x1b[0m] - \x1b[0;31mKirnalt             \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m23\x1b[0m] - \x1b[0;31mLead                \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m24\x1b[0m] - \x1b[0;31mMagnalium           \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m25\x1b[0m] - \x1b[0;31mMagnesium           \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m26\x1b[0m] - \x1b[0;31mMarnalt             \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m27\x1b[0m] - \x1b[0;31mMelynalt            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m28\x1b[0m] - \x1b[0;31mMeteoric iron       \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m29\x1b[0m] - \x1b[0;31mMithril             \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m30\x1b[0m] - \x1b[0;31mNickel              \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m31\x1b[0m] - \x1b[0;31mNurilium            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m32\x1b[0m] - \x1b[0;31mOsmium              \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m33\x1b[0m] - \x1b[0;31mPalladium           \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m34\x1b[0m] - \x1b[0;31mPewter              \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m35\x1b[0m] - \x1b[0;31mPlatinum            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m36\x1b[0m] - \x1b[0;31mRhudnalt            \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m37\x1b[0m] - \x1b[0;31mSilver              \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m38\x1b[0m] - \x1b[0;31mSteel               \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m39\x1b[0m] - \x1b[0;31mTantalum            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m40\x1b[0m] - \x1b[0;31mTin                 \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m41\x1b[0m] - \x1b[0;31mTitanium            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m42\x1b[0m] - \x1b[0;31mTrynalt             \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m43\x1b[0m] - \x1b[0;31mTungsten            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m44\x1b[0m] - \x1b[0;31mZinc                \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n" +
        "    [\x1b[0;31;1m45\x1b[0m] - \x1b[0;32mExit Select Metal Menu\x1b[0m     \n"
        "\x1b[0;32;1mYou must select a number from 1 to 45.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1m\x1b[0;35mP\x1b[0m\x1b[0;32m denotes unrealized prerequisites.\n"
        "\x1b[0m\x1b[0;35mM\x1b[0m\x1b[0;32m denotes that proper quantities of the material requirements are missing.\n\x1b[0m\x1b[0m",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void FlagsMovedAndOptionEnabledWhenPrerequisitesAndQuantityMet()
{
    object material = clone_object("/lib/instances/items/materials/metal/admantite.c");
    material.set("quantity", 6);
    move_object(material, Player);

    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftCommonMetal.c"));
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftUncommonMetal.c"));
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftAlloy.c"));
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftRareMetal.c"));
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftPreciousMetal.c"));
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/materials/craftMythicMetal.c"));
    Selector.initiateSelector(Player);
    command("1", Player);
    command("1", Player);

    ExpectEq("\x1b[0;36mSelect Metal - \x1b[0m\x1b[0;37;1mchoose a metal with which to craft\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m]  - \x1b[0;32mAdmantite           \x1b[0m     "
        "    [\x1b[0;31;1m2\x1b[0m]  - \x1b[0;31mAluminum            \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m3\x1b[0m]  - \x1b[0;31mAluminum bronze     \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m4\x1b[0m]  - \x1b[0;31mAntimony            \x1b[0m\x1b[0;35m(M)\x1b[0m  \n"
        "    [\x1b[0;31;1m5\x1b[0m]  - \x1b[0;31mAsurnalt            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m6\x1b[0m]  - \x1b[0;31mBismuth             \x1b[0m\x1b[0;35m(M)\x1b[0m  \n"
        "    [\x1b[0;31;1m7\x1b[0m]  - \x1b[0;31mBrass               \x1b[0m\x1b[0;35m(M)\x1b[0m  "
        "    [\x1b[0;31;1m8\x1b[0m]  - \x1b[0;31mBronze              \x1b[0m\x1b[0;35m(M)\x1b[0m  \n"
        "    [\x1b[0;31;1m9\x1b[0m]  - \x1b[0;31mCast iron           \x1b[0m\x1b[0;35m(M)\x1b[0m  "
        "    [\x1b[0;31;1m10\x1b[0m] - \x1b[0;31mCobalt              \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m11\x1b[0m] - \x1b[0;31mCopper              \x1b[0m\x1b[0;35m(M)\x1b[0m  "
        "    [\x1b[0;31;1m12\x1b[0m] - \x1b[0;31mCupronickel         \x1b[0m\x1b[0;35m(M)\x1b[0m  \n"
        "    [\x1b[0;31;1m13\x1b[0m] - \x1b[0;31mDurnalt             \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m14\x1b[0m] - \x1b[0;31mElectrum            \x1b[0m\x1b[0;35m(M)\x1b[0m  \n"
        "    [\x1b[0;31;1m15\x1b[0m] - \x1b[0;31mGalvorn             \x1b[0m\x1b[0;35m(M)\x1b[0m  "
        "    [\x1b[0;31;1m16\x1b[0m] - \x1b[0;31mGold                \x1b[0m\x1b[0;35m(M)\x1b[0m  \n"
        "    [\x1b[0;31;1m17\x1b[0m] - \x1b[0;31mGraphite            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m18\x1b[0m] - \x1b[0;31mGwyrnalt            \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m19\x1b[0m] - \x1b[0;31mIridium             \x1b[0m\x1b[0;35m(M)\x1b[0m  "
        "    [\x1b[0;31;1m20\x1b[0m] - \x1b[0;31mIron                \x1b[0m\x1b[0;35m(M)\x1b[0m  \n"
        "    [\x1b[0;31;1m21\x1b[0m] - \x1b[0;31mKirdarium           \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m22\x1b[0m] - \x1b[0;31mKirnalt             \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m23\x1b[0m] - \x1b[0;31mLead                \x1b[0m\x1b[0;35m(M)\x1b[0m  "
        "    [\x1b[0;31;1m24\x1b[0m] - \x1b[0;31mMagnalium           \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m25\x1b[0m] - \x1b[0;31mMagnesium           \x1b[0m\x1b[0;35m(M)\x1b[0m  "
        "    [\x1b[0;31;1m26\x1b[0m] - \x1b[0;31mMarnalt             \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m27\x1b[0m] - \x1b[0;31mMelynalt            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m28\x1b[0m] - \x1b[0;31mMeteoric iron       \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m29\x1b[0m] - \x1b[0;31mMithril             \x1b[0m\x1b[0;35m(M)\x1b[0m  "
        "    [\x1b[0;31;1m30\x1b[0m] - \x1b[0;31mNickel              \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m31\x1b[0m] - \x1b[0;31mNurilium            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m32\x1b[0m] - \x1b[0;31mOsmium              \x1b[0m\x1b[0;35m(M)\x1b[0m  \n"
        "    [\x1b[0;31;1m33\x1b[0m] - \x1b[0;31mPalladium           \x1b[0m\x1b[0;35m(M)\x1b[0m  "
        "    [\x1b[0;31;1m34\x1b[0m] - \x1b[0;31mPewter              \x1b[0m\x1b[0;35m(M)\x1b[0m  \n"
        "    [\x1b[0;31;1m35\x1b[0m] - \x1b[0;31mPlatinum            \x1b[0m\x1b[0;35m(M)\x1b[0m  "
        "    [\x1b[0;31;1m36\x1b[0m] - \x1b[0;31mRhudnalt            \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m37\x1b[0m] - \x1b[0;31mSilver              \x1b[0m\x1b[0;35m(M)\x1b[0m  "
        "    [\x1b[0;31;1m38\x1b[0m] - \x1b[0;31mSteel               \x1b[0m\x1b[0;35m(M)\x1b[0m  \n"
        "    [\x1b[0;31;1m39\x1b[0m] - \x1b[0;31mTantalum            \x1b[0m\x1b[0;35m(M)\x1b[0m  "
        "    [\x1b[0;31;1m40\x1b[0m] - \x1b[0;31mTin                 \x1b[0m\x1b[0;35m(M)\x1b[0m  \n"
        "    [\x1b[0;31;1m41\x1b[0m] - \x1b[0;31mTitanium            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m42\x1b[0m] - \x1b[0;31mTrynalt             \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m43\x1b[0m] - \x1b[0;31mTungsten            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m44\x1b[0m] - \x1b[0;31mZinc                \x1b[0m\x1b[0;35m(M)\x1b[0m  \n" +
        "    [\x1b[0;31;1m45\x1b[0m] - \x1b[0;32mExit Select Metal Menu\x1b[0m     \n"
        "\x1b[0;32;1mYou must select a number from 1 to 45.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1m\x1b[0;35mP\x1b[0m\x1b[0;32m denotes unrealized prerequisites.\n"
        "\x1b[0m\x1b[0;35mM\x1b[0m\x1b[0;32m denotes that proper quantities of the material requirements are missing.\n\x1b[0m\x1b[0m",
        Player.caughtMessage());
}
