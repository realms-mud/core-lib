//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object User;
object Selector;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/modules/creation/combatSkillSelector.c");
    Selector->init();

    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User->Name("Bob");
    User->addSkillPoints(2);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(User);
    destruct(Selector);
}

/////////////////////////////////////////////////////////////////////////////
void InitialCreationDisplayIsCorrect()
{
    Selector->initiateSelector(User);
    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mSelect a skill to advance[0m:\n"
        "\t[[0;31m1[0m]  - [0;32mAxe                 [0m"
        "\t[[0;31m2[0m]  - [0;32mBow                 [0m\n"
        "\t[[0;31m3[0m]  - [0;32mChainmail           [0m"
        "\t[[0;31m4[0m]  - [0;32mCrossbow            [0m\n"
        "\t[[0;31m5[0m]  - [0;32mDagger              [0m"
        "\t[[0;31m6[0m]  - [0;32mDodge               [0m\n"
        "\t[[0;31m7[0m]  - [0;32mDual wield          [0m"
        "\t[[0;31m8[0m]  - [0;32mFlail               [0m\n"
        "\t[[0;31m9[0m]  - [0;32mHammer              [0m"
        "\t[[0;31m10[0m] - [0;32mHand and a half sword[0m\n"
        "\t[[0;31m11[0m] - [0;32mHard leather        [0m"
        "\t[[0;31m12[0m] - [0;32mLong sword          [0m\n"
        "\t[[0;31m13[0m] - [0;32mMace                [0m"
        "\t[[0;31m14[0m] - [0;32mNo armor            [0m\n"
        "\t[[0;31m15[0m] - [0;32mParry               [0m"
        "\t[[0;31m16[0m] - [0;32mPlate armor         [0m\n"
        "\t[[0;31m17[0m] - [0;32mPole arm            [0m"
        "\t[[0;31m18[0m] - [0;32mScalemail           [0m\n"
        "\t[[0;31m19[0m] - [0;32mShield              [0m"
        "\t[[0;31m20[0m] - [0;32mShort sword         [0m\n"
        "\t[[0;31m21[0m] - [0;32mSling               [0m"
        "\t[[0;31m22[0m] - [0;32mSoft leather        [0m\n"
        "\t[[0;31m23[0m] - [0;32mSplint armor        [0m"
        "\t[[0;31m24[0m] - [0;32mStaff               [0m\n"
        "\t[[0;31m25[0m] - [0;32mThrown              [0m"
        "\t[[0;31m26[0m] - [0;32mTwo-handed sword    [0m\n"
        "\t[[0;31m27[0m] - [0;32mUnarmed             [0m"
        "\t[[0;31m28[0m] - [0;32mReturn to previous menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 28.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1mYou may only select a skill once. [0;34;1m(*)[0m [0;32;1mdenotes an already-chosen skill.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CreationDisplayShowsChosenSkills()
{
    User->advanceSkill("bow", 1);
    Selector->initiateSelector(User);
    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mSelect a skill to advance[0m:\n"
        "\t[[0;31m1[0m]  - [0;32mAxe                 [0m"
        "\t[[0;31m2[0m]  - [0;32mBow                 [0m[0;34;1m(*)[0m\n"
        "\t[[0;31m3[0m]  - [0;32mChainmail           [0m"
        "\t[[0;31m4[0m]  - [0;32mCrossbow            [0m\n"
        "\t[[0;31m5[0m]  - [0;32mDagger              [0m"
        "\t[[0;31m6[0m]  - [0;32mDodge               [0m\n"
        "\t[[0;31m7[0m]  - [0;32mDual wield          [0m"
        "\t[[0;31m8[0m]  - [0;32mFlail               [0m\n"
        "\t[[0;31m9[0m]  - [0;32mHammer              [0m"
        "\t[[0;31m10[0m] - [0;32mHand and a half sword[0m\n"
        "\t[[0;31m11[0m] - [0;32mHard leather        [0m"
        "\t[[0;31m12[0m] - [0;32mLong sword          [0m\n"
        "\t[[0;31m13[0m] - [0;32mMace                [0m"
        "\t[[0;31m14[0m] - [0;32mNo armor            [0m\n"
        "\t[[0;31m15[0m] - [0;32mParry               [0m"
        "\t[[0;31m16[0m] - [0;32mPlate armor         [0m\n"
        "\t[[0;31m17[0m] - [0;32mPole arm            [0m"
        "\t[[0;31m18[0m] - [0;32mScalemail           [0m\n"
        "\t[[0;31m19[0m] - [0;32mShield              [0m"
        "\t[[0;31m20[0m] - [0;32mShort sword         [0m\n"
        "\t[[0;31m21[0m] - [0;32mSling               [0m"
        "\t[[0;31m22[0m] - [0;32mSoft leather        [0m\n"
        "\t[[0;31m23[0m] - [0;32mSplint armor        [0m"
        "\t[[0;31m24[0m] - [0;32mStaff               [0m\n"
        "\t[[0;31m25[0m] - [0;32mThrown              [0m"
        "\t[[0;31m26[0m] - [0;32mTwo-handed sword    [0m\n"
        "\t[[0;31m27[0m] - [0;32mUnarmed             [0m"
        "\t[[0;31m28[0m] - [0;32mReturn to previous menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 28.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1mYou may only select a skill once. [0;34;1m(*)[0m [0;32;1mdenotes an already-chosen skill.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingItemSetsSelectionAndFiresOnSelectorCompleted()
{
    object subscriber = clone_object("/lib/tests/support/events/onSelectorCompletedEventSubscriber.c");
    Selector->registerEvent(subscriber);
    Selector->initiateSelector(User);

    ExpectFalse(Selector->selection());
    ExpectEq(0, subscriber->TimesEventReceived());
    Selector->applySelection("1");

    ExpectEq(1, subscriber->TimesEventReceived(), "event received");
    ExpectEq("axe", Selector->selection());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingReturnToPreviousSetsSelectionToNullAndFiresOnSelectorCompleted()
{
    object subscriber = clone_object("/lib/tests/support/events/onSelectorCompletedEventSubscriber.c");
    Selector->registerEvent(subscriber);
    Selector->initiateSelector(User);

    ExpectFalse(Selector->selection());
    ExpectEq(0, subscriber->TimesEventReceived());
    Selector->applySelection("28");

    ExpectEq(1, subscriber->TimesEventReceived(), "event received");
    ExpectFalse(Selector->selection());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeAxeDisplaysDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 1");

    ExpectEq("[0;36mThis skill provides proficiency in the use of axes of any nature, barring\n"
        "those axes mounted to pole arms. This skill encompasses skill with battle\n"
        "axes, hand axes, crescent axes, war axes, and other weapons of that\n"
        "nature - weapons that can be wielded with one or two hands.\n[0m"
        "\t[0;32mAffecting attribute[0m: [0;34;1mStrength[0m\n"
        "\t[0;31;1mAttempting to use this skill untrained will incur a penalty.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeBowDisplaysDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 2");

    ExpectEq("[0;36mThis skill provides proficiency in all arm-drawn bows. This includes short\n"
        "bows, long bows, composite bows, recurves, and compound bows.\n[0m"
        "\t[0;32mAffecting attribute[0m: [0;34;1mDexterity[0m\n"
        "\t[0;31;1mAttempting to use this skill untrained will incur a penalty.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeChainmailDisplaysDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 3");

    ExpectEq("[0;36mThis skill provides proficiency in the use of chain-type armors such as\n"
        "chain mail and any other armor fashioned of interlocking or interwoven rings of\n"
        "material. This allows for good mobility in a fairly heavy/strong armor.\n[0m"
        "\t[0;32mAffecting attribute[0m: [0;34;1mStrength[0m\n"
        "\t[0;31;1mAttempting to use this skill untrained will incur a penalty.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeCrossbowDisplaysDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 4");

    ExpectEq("[0;36mThis skill provides proficiency in all mechanically drawn/held bows. This\n"
        "includes all crossbows, ballista, etc.\n[0m"
        "\t[0;32mAffecting attribute[0m: [0;34;1mDexterity[0m\n"
        "\t[0;31;1mAttempting to use this skill untrained will incur a penalty.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeDaggerDisplaysDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 5");

    ExpectEq("[0;36mThis skill provides proficiency in the use of bladed weapons that are\n"
        "typically less than 18\" long. This includes daggers, knives, dirks, stilletos,\n"
        "and other weapons of this nature.\n[0m"
        "\t[0;32mAffecting attribute[0m: [0;34;1mDexterity[0m\n"
        "\t[0;31;1mAttempting to use this skill untrained will incur a penalty.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeDodgeDisplaysDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 6");

    ExpectEq("[0;36mThis skill provides proficiency in avoiding an opponent's attack.\n[0m"
        "\t[0;32mAffecting attribute[0m: [0;34;1mDexterity[0m\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeDualWieldDisplaysDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 7");

    ExpectEq("[0;36mThis skill provides proficiency in attacking with an offhand weapon.\n[0m"
        "\t[0;32mAffecting attribute[0m: [0;34;1mDexterity[0m\n"
        "\t[0;31;1mAttempting to use this skill untrained will incur a penalty.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeFlailDisplaysDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 8");

    ExpectEq("[0;36mThis skill provides proficiency in the use of the more exotic 'jointed'\n"
        "style weapons. This includes weapons such as flails, whips, chains, and other\n"
        "such weapons.\n[0m"
        "\t[0;32mAffecting attribute[0m: [0;34;1mStrength[0m\n"
        "\t[0;31;1mAttempting to use this skill untrained will incur a penalty.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeHammerDisplaysDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 9");

    ExpectEq("[0;36mThis skill provides proficiency in the use of all of the various types of\n"
        "hammers including war hammers, mauls, luscerne hammers, and other weapons of\n"
        "that nature.\n[0m"
        "\t[0;32mAffecting attribute[0m: [0;34;1mStrength[0m\n"
        "\t[0;31;1mAttempting to use this skill untrained will incur a penalty.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeHandHalfSwordDisplaysDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 10");

    ExpectEq("[0;36mThis skill provides proficiency in the use of larger swords (upper end\n"
        "of long swords and larger) that could be wielded with either one or two hands.\n"
        "Using two hands with a weapon of this type provides a bonus on attack and damage\n"
        "rolls. Swords of this type include bastard swords and claymores.\n[0m"
        "\t[0;32mAffecting attribute[0m: [0;34;1mStrength[0m\n"
        "\t[0;31;1mAttempting to use this skill untrained will incur a penalty.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeHardLeatherDisplaysDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 11");

    ExpectEq("[0;36mHard leather is leather treated in a manner above and beyond simple\n"
        "tanning. The leather is fairly rigid and offers better protection than usual\n"
        "leather, but at the sacrifice of mobility. Often times, studs are sewn into the\n"
        "armor to provide extra protection against weapons.\n[0m"
        "\t[0;32mAffecting attribute[0m: [0;34;1mStrength[0m\n"
        "\t[0;31;1mAttempting to use this skill untrained will incur a penalty.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeLongSwordDisplaysDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 12");

    ExpectEq("[0;36mThis skill provides proficiency in the use of most swords ranging from\n"
        "two-and-a-half foot long swords to about four-and-a-half foot long swords with\n"
        "respect to an average 5'6\" human. This includes (but is not limited to) long\n"
        "swords, scimitars, cutlasses, rapiers, katanas, broadswords, and sabres.\n[0m"
        "\t[0;32mAffecting attribute[0m: [0;34;1mStrength[0m\n"
        "\t[0;31;1mAttempting to use this skill untrained will incur a penalty.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeMaceDisplaysDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 13");

    ExpectEq("[0;36mThe mace skill is used for any one-handed bludgeoning weapon crafted more or\n"
        "less entirely of a single material. This includes maces, clubs, and morning\n"
        "stars.\n[0m"
        "\t[0;32mAffecting attribute[0m: [0;34;1mStrength[0m\n"
        "\t[0;31;1mAttempting to use this skill untrained will incur a penalty.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeNoArmorDisplaysDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 14");

    ExpectEq("[0;36mArmors that fall in this category are padded armors made of cloth, robes,\n"
        "and every day clothing.\n[0m"
        "\t[0;32mAffecting attribute[0m: [0;34;1mDexterity[0m\n"
        "\t[0;31;1mAttempting to use this skill untrained will incur a penalty.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeParryDisplaysDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 15");

    ExpectEq("[0;36mThis skill provides proficiency in using one's weapon to block an attack.\n[0m"
        "\t[0;32mAffecting attribute[0m: [0;34;1mDexterity[0m\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribePlateArmorDisplaysDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 16");

    ExpectEq("[0;36mThis skill provides proficiency in the use of heavy armors made of\n"
        "plates of material, typically, but not exclusively, of metal. Armors of this\n"
        "family include full plate, field plate, plate mail, and breastplates.\n[0m"
        "\t[0;32mAffecting attribute[0m: [0;34;1mStrength[0m\n"
        "\t[0;31;1mAttempting to use this skill untrained will incur a penalty.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribePoleArmDisplaysDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 17");

    ExpectEq("[0;36mThis skill provides proficiency in the use of pole arms -- any weapon with\n"
        "a metal head attached to a long pole. This includes halberds, spears, pikes,\n"
        "glaives, bardiches, pole axes, bills, etc.\n[0m"
        "\t[0;32mAffecting attribute[0m: [0;34;1mStrength[0m\n"
        "\t[0;31;1mAttempting to use this skill untrained will incur a penalty.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeScalemailDisplaysDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 18");

    ExpectEq("[0;36mScale armor represents those armors fashioned of some substrate such as\n"
        "chain armor or leather with small metal (or other rigid substance) plates woven\n"
        "through the substrate (typically layered in a fashion similar to a fish's\n"
        "scales.) Armors of this nature typically afford decent protection at the cost\n"
        "of mobility.\n[0m"
        "\t[0;32mAffecting attribute[0m: [0;34;1mStrength[0m\n"
        "\t[0;31;1mAttempting to use this skill untrained will incur a penalty.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeShieldDisplaysDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 19");

    ExpectEq("[0;36mThis skill provides proficiency in the use of shields as both an\n"
        "offensive and defensive weapon, though the use of shields much larger than a\n"
        "kite shield have very limited usefulness offensively. This skill encompasses\n"
        "shields with attached blades and spikes as well as those without any overt\n"
        "signs of offensive capabilities.\n[0m"
        "\t[0;32mAffecting attribute[0m: [0;34;1mStrength[0m\n"
        "\t[0;31;1mAttempting to use this skill untrained will incur a penalty.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeShortSwordDisplaysDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 20");

    ExpectEq("[0;36mThis skill provides proficiency in the use of short swords -- swords\n"
        "typically ranging from two-and-a-half feet and under for a typical human (5'6\").\n"
        "This would include short swords, any form of gladus, machettes, etc.\n[0m"
        "\t[0;32mAffecting attribute[0m: [0;34;1mDexterity[0m\n"
        "\t[0;31;1mAttempting to use this skill untrained will incur a penalty.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeSlingDisplaysDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 21");

    ExpectEq("[0;36mThis skill provides proficiency in all sling and slinglike weapons (such\n"
        "as slingshots and staff slings).\n[0m"
        "\t[0;32mAffecting attribute[0m: [0;34;1mDexterity[0m\n"
        "\t[0;31;1mAttempting to use this skill untrained will incur a penalty.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeSoftLeatherDisplaysDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 22");

    ExpectEq("[0;36mThis skill provides proficiency in the use of untreated or tanned leather\n"
        "armors. The armor offers a great deal of mobility but offers only modest\n"
        "protection from harm.\n[0m"
        "\t[0;32mAffecting attribute[0m: [0;34;1mDexterity[0m\n"
        "\t[0;31;1mAttempting to use this skill untrained will incur a penalty.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeSplintArmorDisplaysDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 23");

    ExpectEq("[0;36mSplint armor allows for more flexibility than plate armor. Splint armors\n"
        "are typically fashioned out of long bands - or splints - of metal attached to a\n"
        "substrate of leather, cloth, or chain.\n[0m"
        "\t[0;32mAffecting attribute[0m: [0;34;1mStrength[0m\n"
        "\t[0;31;1mAttempting to use this skill untrained will incur a penalty.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeStaffDisplaysDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 24");

    ExpectEq("[0;36mThis skill provides proficiency in the use of all staves and other\n"
        "'blunt' pole arms such as a quarterstaff.\n[0m"
        "\t[0;32mAffecting attribute[0m: [0;34;1mStrength[0m\n"
        "\t[0;31;1mAttempting to use this skill untrained will incur a penalty.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeThrownDisplaysDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 25");

    ExpectEq("[0;36mThis skill provides proficiency in all thrown weapons. This includes rocks,\n"
        "bolos, hand axes, swords, daggers, hammers, javelins, as well as those weapons\n"
        "thrown with the aid of some other device such as a spear thrower.\n[0m"
        "\t[0;32mAffecting attribute[0m: [0;34;1mStrength[0m\n"
        "\t[0;31;1mAttempting to use this skill untrained will incur a penalty.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeTwoHandSwordDisplaysDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 26");

    ExpectEq("[0;36mThis skill provides proficiency in the use of large (roughly the length of\n"
        "the wielder's body) swords such as great swords or those swords known as\n"
        "'two-handed swords' They are weapons that could only be wielded by its user\n"
        "one-handed with great difficulty. If this isn't the case, the sword in question\n"
        "is likely a hand & a half sword.\n[0m"
        "\t[0;32mAffecting attribute[0m: [0;34;1mStrength[0m\n"
        "\t[0;31;1mAttempting to use this skill untrained will incur a penalty.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeUnarmedDisplaysDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 27");

    ExpectEq("[0;36mThis skill provides proficiency in unarmed combat. This includes punching\n"
        "wrestling, kicking, and other tactics of this nature.\n[0m"
        "\t[0;32mAffecting attribute[0m: [0;34;1mStrength[0m\n"
        "\t[0;31;1mAttempting to use this skill untrained will incur a penalty.\n[0m",
        User->caughtMessage());
}
