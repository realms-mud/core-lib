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
    Player->addResearchPoints(20);

    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftWeapons.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftBasicSwords.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftLongSwords.c"));

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
    Selector->initiateSelector(Player);
    command("1", Player);
    command("1", Player);

    ExpectEq("[0;36mSelect Metal - [0m[0;37;1mchoose a metal with which to craft[0m:\n"
        "    [[0;31;1m1[0m]  - [0;31mAdmantite           [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m2[0m]  - [0;31mAluminum            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m3[0m]  - [0;31mAluminum bronze     [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m4[0m]  - [0;31mAntimony            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m5[0m]  - [0;31mAsurnalt            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m6[0m]  - [0;31mBismuth             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m7[0m]  - [0;31mBrass               [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m8[0m]  - [0;31mBronze              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m9[0m]  - [0;31mCast iron           [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m10[0m] - [0;31mCobalt              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m11[0m] - [0;31mCopper              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m12[0m] - [0;31mCupronickel         [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m13[0m] - [0;31mDurnalt             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m14[0m] - [0;31mElectrum            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m15[0m] - [0;31mGalvorn             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m16[0m] - [0;31mGold                [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m17[0m] - [0;31mGraphite            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m18[0m] - [0;31mGwyrnalt            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m19[0m] - [0;31mIridium             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m20[0m] - [0;31mIron                [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m21[0m] - [0;31mKirdarium           [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m22[0m] - [0;31mKirnalt             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m23[0m] - [0;31mLead                [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m24[0m] - [0;31mMagnalium           [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m25[0m] - [0;31mMagnesium           [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m26[0m] - [0;31mMarnalt             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m27[0m] - [0;31mMelynalt            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m28[0m] - [0;31mMeteoric iron       [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m29[0m] - [0;31mMithril             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m30[0m] - [0;31mNickel              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m31[0m] - [0;31mNurilium            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m32[0m] - [0;31mOsmium              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m33[0m] - [0;31mPalladium           [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m34[0m] - [0;31mPewter              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m35[0m] - [0;31mPlatinum            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m36[0m] - [0;31mRhudnalt            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m37[0m] - [0;31mSilver              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m38[0m] - [0;31mSteel               [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m39[0m] - [0;31mTantalum            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m40[0m] - [0;31mTin                 [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m41[0m] - [0;31mTitanium            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m42[0m] - [0;31mTrynalt             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m43[0m] - [0;31mTungsten            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m44[0m] - [0;31mZinc                [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n" +
        "    [[0;31;1m45[0m] - [0;32mExit Select Metal Menu[0m     \n"
        "[0;32;1mYou must select a number from 1 to 45.\n[0m"
        "[0;32mType 'abort' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1m[0;35mP[0m[0;32m denotes unrealized prerequisites.\n"
        "[0;35mM[0m[0;32m denotes that proper quantities of the material requirements are missing.\n[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PFlagRemovedWhenPrerequisitesMet()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftCommonMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftUncommonMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftAlloy.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftRareMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftPreciousMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftMythicMetal.c"));
    Selector->initiateSelector(Player);
    command("1", Player);
    command("1", Player);

    ExpectEq("[0;36mSelect Metal - [0m[0;37;1mchoose a metal with which to craft[0m:\n"
        "    [[0;31;1m1[0m]  - [0;31mAdmantite           [0m[0;34;1m([0;35mM[0;34;1m)[0m  "
        "    [[0;31;1m2[0m]  - [0;31mAluminum            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m3[0m]  - [0;31mAluminum bronze     [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m4[0m]  - [0;31mAntimony            [0m[0;34;1m([0;35mM[0;34;1m)[0m  \n"
        "    [[0;31;1m5[0m]  - [0;31mAsurnalt            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m6[0m]  - [0;31mBismuth             [0m[0;34;1m([0;35mM[0;34;1m)[0m  \n"
        "    [[0;31;1m7[0m]  - [0;31mBrass               [0m[0;34;1m([0;35mM[0;34;1m)[0m  "
        "    [[0;31;1m8[0m]  - [0;31mBronze              [0m[0;34;1m([0;35mM[0;34;1m)[0m  \n"
        "    [[0;31;1m9[0m]  - [0;31mCast iron           [0m[0;34;1m([0;35mM[0;34;1m)[0m  "
        "    [[0;31;1m10[0m] - [0;31mCobalt              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m11[0m] - [0;31mCopper              [0m[0;34;1m([0;35mM[0;34;1m)[0m  "
        "    [[0;31;1m12[0m] - [0;31mCupronickel         [0m[0;34;1m([0;35mM[0;34;1m)[0m  \n"
        "    [[0;31;1m13[0m] - [0;31mDurnalt             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m14[0m] - [0;31mElectrum            [0m[0;34;1m([0;35mM[0;34;1m)[0m  \n"
        "    [[0;31;1m15[0m] - [0;31mGalvorn             [0m[0;34;1m([0;35mM[0;34;1m)[0m  "
        "    [[0;31;1m16[0m] - [0;31mGold                [0m[0;34;1m([0;35mM[0;34;1m)[0m  \n"
        "    [[0;31;1m17[0m] - [0;31mGraphite            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m18[0m] - [0;31mGwyrnalt            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m19[0m] - [0;31mIridium             [0m[0;34;1m([0;35mM[0;34;1m)[0m  "
        "    [[0;31;1m20[0m] - [0;31mIron                [0m[0;34;1m([0;35mM[0;34;1m)[0m  \n"
        "    [[0;31;1m21[0m] - [0;31mKirdarium           [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m22[0m] - [0;31mKirnalt             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m23[0m] - [0;31mLead                [0m[0;34;1m([0;35mM[0;34;1m)[0m  "
        "    [[0;31;1m24[0m] - [0;31mMagnalium           [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m25[0m] - [0;31mMagnesium           [0m[0;34;1m([0;35mM[0;34;1m)[0m  "
        "    [[0;31;1m26[0m] - [0;31mMarnalt             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m27[0m] - [0;31mMelynalt            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m28[0m] - [0;31mMeteoric iron       [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m29[0m] - [0;31mMithril             [0m[0;34;1m([0;35mM[0;34;1m)[0m  "
        "    [[0;31;1m30[0m] - [0;31mNickel              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m31[0m] - [0;31mNurilium            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m32[0m] - [0;31mOsmium              [0m[0;34;1m([0;35mM[0;34;1m)[0m  \n"
        "    [[0;31;1m33[0m] - [0;31mPalladium           [0m[0;34;1m([0;35mM[0;34;1m)[0m  "
        "    [[0;31;1m34[0m] - [0;31mPewter              [0m[0;34;1m([0;35mM[0;34;1m)[0m  \n"
        "    [[0;31;1m35[0m] - [0;31mPlatinum            [0m[0;34;1m([0;35mM[0;34;1m)[0m  "
        "    [[0;31;1m36[0m] - [0;31mRhudnalt            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m37[0m] - [0;31mSilver              [0m[0;34;1m([0;35mM[0;34;1m)[0m  "
        "    [[0;31;1m38[0m] - [0;31mSteel               [0m[0;34;1m([0;35mM[0;34;1m)[0m  \n"
        "    [[0;31;1m39[0m] - [0;31mTantalum            [0m[0;34;1m([0;35mM[0;34;1m)[0m  "
        "    [[0;31;1m40[0m] - [0;31mTin                 [0m[0;34;1m([0;35mM[0;34;1m)[0m  \n"
        "    [[0;31;1m41[0m] - [0;31mTitanium            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m42[0m] - [0;31mTrynalt             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m43[0m] - [0;31mTungsten            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m44[0m] - [0;31mZinc                [0m[0;34;1m([0;35mM[0;34;1m)[0m  \n" +
        "    [[0;31;1m45[0m] - [0;32mExit Select Metal Menu[0m     \n"
        "[0;32;1mYou must select a number from 1 to 45.\n[0m"
        "[0;32mType 'abort' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1m[0;35mP[0m[0;32m denotes unrealized prerequisites.\n"
        "[0;35mM[0m[0;32m denotes that proper quantities of the material requirements are missing.\n[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MFlagRemovedWhenQuantityMet()
{
    object material = clone_object("/lib/instances/items/materials/metal/admantite.c");
    material->set("quantity", 6);
    move_object(material, Player);

    Selector->initiateSelector(Player);
    command("1", Player);
    command("1", Player);

    ExpectEq("[0;36mSelect Metal - [0m[0;37;1mchoose a metal with which to craft[0m:\n"
        "    [[0;31;1m1[0m]  - [0;31mAdmantite           [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m2[0m]  - [0;31mAluminum            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m3[0m]  - [0;31mAluminum bronze     [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m4[0m]  - [0;31mAntimony            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m5[0m]  - [0;31mAsurnalt            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m6[0m]  - [0;31mBismuth             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m7[0m]  - [0;31mBrass               [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m8[0m]  - [0;31mBronze              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m9[0m]  - [0;31mCast iron           [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m10[0m] - [0;31mCobalt              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m11[0m] - [0;31mCopper              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m12[0m] - [0;31mCupronickel         [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m13[0m] - [0;31mDurnalt             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m14[0m] - [0;31mElectrum            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m15[0m] - [0;31mGalvorn             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m16[0m] - [0;31mGold                [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m17[0m] - [0;31mGraphite            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m18[0m] - [0;31mGwyrnalt            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m19[0m] - [0;31mIridium             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m20[0m] - [0;31mIron                [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m21[0m] - [0;31mKirdarium           [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m22[0m] - [0;31mKirnalt             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m23[0m] - [0;31mLead                [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m24[0m] - [0;31mMagnalium           [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m25[0m] - [0;31mMagnesium           [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m26[0m] - [0;31mMarnalt             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m27[0m] - [0;31mMelynalt            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m28[0m] - [0;31mMeteoric iron       [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m29[0m] - [0;31mMithril             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m30[0m] - [0;31mNickel              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m31[0m] - [0;31mNurilium            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m32[0m] - [0;31mOsmium              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m33[0m] - [0;31mPalladium           [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m34[0m] - [0;31mPewter              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m35[0m] - [0;31mPlatinum            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m36[0m] - [0;31mRhudnalt            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m37[0m] - [0;31mSilver              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m38[0m] - [0;31mSteel               [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m39[0m] - [0;31mTantalum            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m40[0m] - [0;31mTin                 [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m41[0m] - [0;31mTitanium            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m42[0m] - [0;31mTrynalt             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m43[0m] - [0;31mTungsten            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m44[0m] - [0;31mZinc                [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n" +
        "    [[0;31;1m45[0m] - [0;32mExit Select Metal Menu[0m     \n"
        "[0;32;1mYou must select a number from 1 to 45.\n[0m"
        "[0;32mType 'abort' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1m[0;35mP[0m[0;32m denotes unrealized prerequisites.\n"
        "[0;35mM[0m[0;32m denotes that proper quantities of the material requirements are missing.\n[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void QuantityCanBeSpreadAcrossMultipleObjects()
{
    object material = clone_object("/lib/instances/items/materials/metal/admantite.c");
    material->set("quantity", 2);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/admantite.c");
    material->set("quantity", 2);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/admantite.c");
    material->set("quantity", 1);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/admantite.c");
    material->set("quantity", 1);
    move_object(material, Player);

    Selector->initiateSelector(Player);
    command("1", Player);
    command("1", Player);

    ExpectEq("[0;36mSelect Metal - [0m[0;37;1mchoose a metal with which to craft[0m:\n"
        "    [[0;31;1m1[0m]  - [0;31mAdmantite           [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m2[0m]  - [0;31mAluminum            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m3[0m]  - [0;31mAluminum bronze     [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m4[0m]  - [0;31mAntimony            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m5[0m]  - [0;31mAsurnalt            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m6[0m]  - [0;31mBismuth             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m7[0m]  - [0;31mBrass               [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m8[0m]  - [0;31mBronze              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m9[0m]  - [0;31mCast iron           [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m10[0m] - [0;31mCobalt              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m11[0m] - [0;31mCopper              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m12[0m] - [0;31mCupronickel         [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m13[0m] - [0;31mDurnalt             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m14[0m] - [0;31mElectrum            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m15[0m] - [0;31mGalvorn             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m16[0m] - [0;31mGold                [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m17[0m] - [0;31mGraphite            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m18[0m] - [0;31mGwyrnalt            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m19[0m] - [0;31mIridium             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m20[0m] - [0;31mIron                [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m21[0m] - [0;31mKirdarium           [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m22[0m] - [0;31mKirnalt             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m23[0m] - [0;31mLead                [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m24[0m] - [0;31mMagnalium           [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m25[0m] - [0;31mMagnesium           [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m26[0m] - [0;31mMarnalt             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m27[0m] - [0;31mMelynalt            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m28[0m] - [0;31mMeteoric iron       [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m29[0m] - [0;31mMithril             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m30[0m] - [0;31mNickel              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m31[0m] - [0;31mNurilium            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m32[0m] - [0;31mOsmium              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m33[0m] - [0;31mPalladium           [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m34[0m] - [0;31mPewter              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m35[0m] - [0;31mPlatinum            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m36[0m] - [0;31mRhudnalt            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m37[0m] - [0;31mSilver              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m38[0m] - [0;31mSteel               [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m39[0m] - [0;31mTantalum            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m40[0m] - [0;31mTin                 [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m41[0m] - [0;31mTitanium            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m42[0m] - [0;31mTrynalt             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m43[0m] - [0;31mTungsten            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m44[0m] - [0;31mZinc                [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n" +
        "    [[0;31;1m45[0m] - [0;32mExit Select Metal Menu[0m     \n"
        "[0;32;1mYou must select a number from 1 to 45.\n[0m"
        "[0;32mType 'abort' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1m[0;35mP[0m[0;32m denotes unrealized prerequisites.\n"
        "[0;35mM[0m[0;32m denotes that proper quantities of the material requirements are missing.\n[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void FlagsMovedAndOptionEnabledWhenPrerequisitesAndQuantityMet()
{
    object material = clone_object("/lib/instances/items/materials/metal/admantite.c");
    material->set("quantity", 6);
    move_object(material, Player);

    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftCommonMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftUncommonMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftAlloy.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftRareMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftPreciousMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftMythicMetal.c"));
    Selector->initiateSelector(Player);
    command("1", Player);
    command("1", Player);

    ExpectEq("[0;36mSelect Metal - [0m[0;37;1mchoose a metal with which to craft[0m:\n"
        "    [[0;31;1m1[0m]  - [0;32mAdmantite           [0m     "
        "    [[0;31;1m2[0m]  - [0;31mAluminum            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m3[0m]  - [0;31mAluminum bronze     [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m4[0m]  - [0;31mAntimony            [0m[0;34;1m([0;35mM[0;34;1m)[0m  \n"
        "    [[0;31;1m5[0m]  - [0;31mAsurnalt            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m6[0m]  - [0;31mBismuth             [0m[0;34;1m([0;35mM[0;34;1m)[0m  \n"
        "    [[0;31;1m7[0m]  - [0;31mBrass               [0m[0;34;1m([0;35mM[0;34;1m)[0m  "
        "    [[0;31;1m8[0m]  - [0;31mBronze              [0m[0;34;1m([0;35mM[0;34;1m)[0m  \n"
        "    [[0;31;1m9[0m]  - [0;31mCast iron           [0m[0;34;1m([0;35mM[0;34;1m)[0m  "
        "    [[0;31;1m10[0m] - [0;31mCobalt              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m11[0m] - [0;31mCopper              [0m[0;34;1m([0;35mM[0;34;1m)[0m  "
        "    [[0;31;1m12[0m] - [0;31mCupronickel         [0m[0;34;1m([0;35mM[0;34;1m)[0m  \n"
        "    [[0;31;1m13[0m] - [0;31mDurnalt             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m14[0m] - [0;31mElectrum            [0m[0;34;1m([0;35mM[0;34;1m)[0m  \n"
        "    [[0;31;1m15[0m] - [0;31mGalvorn             [0m[0;34;1m([0;35mM[0;34;1m)[0m  "
        "    [[0;31;1m16[0m] - [0;31mGold                [0m[0;34;1m([0;35mM[0;34;1m)[0m  \n"
        "    [[0;31;1m17[0m] - [0;31mGraphite            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m18[0m] - [0;31mGwyrnalt            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m19[0m] - [0;31mIridium             [0m[0;34;1m([0;35mM[0;34;1m)[0m  "
        "    [[0;31;1m20[0m] - [0;31mIron                [0m[0;34;1m([0;35mM[0;34;1m)[0m  \n"
        "    [[0;31;1m21[0m] - [0;31mKirdarium           [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m22[0m] - [0;31mKirnalt             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m23[0m] - [0;31mLead                [0m[0;34;1m([0;35mM[0;34;1m)[0m  "
        "    [[0;31;1m24[0m] - [0;31mMagnalium           [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m25[0m] - [0;31mMagnesium           [0m[0;34;1m([0;35mM[0;34;1m)[0m  "
        "    [[0;31;1m26[0m] - [0;31mMarnalt             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m27[0m] - [0;31mMelynalt            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m28[0m] - [0;31mMeteoric iron       [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m29[0m] - [0;31mMithril             [0m[0;34;1m([0;35mM[0;34;1m)[0m  "
        "    [[0;31;1m30[0m] - [0;31mNickel              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m31[0m] - [0;31mNurilium            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m32[0m] - [0;31mOsmium              [0m[0;34;1m([0;35mM[0;34;1m)[0m  \n"
        "    [[0;31;1m33[0m] - [0;31mPalladium           [0m[0;34;1m([0;35mM[0;34;1m)[0m  "
        "    [[0;31;1m34[0m] - [0;31mPewter              [0m[0;34;1m([0;35mM[0;34;1m)[0m  \n"
        "    [[0;31;1m35[0m] - [0;31mPlatinum            [0m[0;34;1m([0;35mM[0;34;1m)[0m  "
        "    [[0;31;1m36[0m] - [0;31mRhudnalt            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m37[0m] - [0;31mSilver              [0m[0;34;1m([0;35mM[0;34;1m)[0m  "
        "    [[0;31;1m38[0m] - [0;31mSteel               [0m[0;34;1m([0;35mM[0;34;1m)[0m  \n"
        "    [[0;31;1m39[0m] - [0;31mTantalum            [0m[0;34;1m([0;35mM[0;34;1m)[0m  "
        "    [[0;31;1m40[0m] - [0;31mTin                 [0m[0;34;1m([0;35mM[0;34;1m)[0m  \n"
        "    [[0;31;1m41[0m] - [0;31mTitanium            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m42[0m] - [0;31mTrynalt             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m43[0m] - [0;31mTungsten            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m44[0m] - [0;31mZinc                [0m[0;34;1m([0;35mM[0;34;1m)[0m  \n" +
        "    [[0;31;1m45[0m] - [0;32mExit Select Metal Menu[0m     \n"
        "[0;32;1mYou must select a number from 1 to 45.\n[0m"
        "[0;32mType 'abort' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1m[0;35mP[0m[0;32m denotes unrealized prerequisites.\n"
        "[0;35mM[0m[0;32m denotes that proper quantities of the material requirements are missing.\n[0m",
        Player->caughtMessage());
}