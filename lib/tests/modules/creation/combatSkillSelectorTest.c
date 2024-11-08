//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object User;
object Selector;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/modules/creation/combatSkillSelector.c");
    Selector.init();

    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User.Name("Bob");
    User.addSkillPoints(2);
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
    Selector.initiateSelector(User);
    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mSelect a skill to advance\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m]  - \x1b[0;32mAxe                 \x1b[0m    "
        "    [\x1b[0;31;1m2\x1b[0m]  - \x1b[0;32mBlind fighting      \x1b[0m    \n"
        "    [\x1b[0;31;1m3\x1b[0m]  - \x1b[0;32mBow                 \x1b[0m    "
        "    [\x1b[0;31;1m4\x1b[0m]  - \x1b[0;32mChainmail           \x1b[0m    \n"
        "    [\x1b[0;31;1m5\x1b[0m]  - \x1b[0;32mCrossbow            \x1b[0m    "
        "    [\x1b[0;31;1m6\x1b[0m]  - \x1b[0;32mDagger              \x1b[0m    \n"
        "    [\x1b[0;31;1m7\x1b[0m]  - \x1b[0;32mDodge               \x1b[0m    "
        "    [\x1b[0;31;1m8\x1b[0m]  - \x1b[0;32mDual wield          \x1b[0m    \n"
        "    [\x1b[0;31;1m9\x1b[0m]  - \x1b[0;32mFlail               \x1b[0m    "
        "    [\x1b[0;31;1m10\x1b[0m] - \x1b[0;32mHammer              \x1b[0m    \n"
        "    [\x1b[0;31;1m11\x1b[0m] - \x1b[0;32mHand and a half s...\x1b[0m    "
        "    [\x1b[0;31;1m12\x1b[0m] - \x1b[0;32mHard leather        \x1b[0m    \n"
        "    [\x1b[0;31;1m13\x1b[0m] - \x1b[0;32mLong sword          \x1b[0m    "
        "    [\x1b[0;31;1m14\x1b[0m] - \x1b[0;32mMace                \x1b[0m    \n"
        "    [\x1b[0;31;1m15\x1b[0m] - \x1b[0;32mNo armor            \x1b[0m    "
        "    [\x1b[0;31;1m16\x1b[0m] - \x1b[0;32mParry               \x1b[0m    \n"
        "    [\x1b[0;31;1m17\x1b[0m] - \x1b[0;32mPlate armor         \x1b[0m    "
        "    [\x1b[0;31;1m18\x1b[0m] - \x1b[0;32mPole arm            \x1b[0m    \n"
        "    [\x1b[0;31;1m19\x1b[0m] - \x1b[0;32mScalemail           \x1b[0m    "
        "    [\x1b[0;31;1m20\x1b[0m] - \x1b[0;32mShield              \x1b[0m    \n"
        "    [\x1b[0;31;1m21\x1b[0m] - \x1b[0;32mShort sword         \x1b[0m    "
        "    [\x1b[0;31;1m22\x1b[0m] - \x1b[0;32mSling               \x1b[0m    \n"
        "    [\x1b[0;31;1m23\x1b[0m] - \x1b[0;32mSoft leather        \x1b[0m    "
        "    [\x1b[0;31;1m24\x1b[0m] - \x1b[0;32mSplint armor        \x1b[0m    \n"
        "    [\x1b[0;31;1m25\x1b[0m] - \x1b[0;32mStaff               \x1b[0m    "
        "    [\x1b[0;31;1m26\x1b[0m] - \x1b[0;32mThrown              \x1b[0m    \n"
        "    [\x1b[0;31;1m27\x1b[0m] - \x1b[0;32mTwo-handed sword    \x1b[0m    "
        "    [\x1b[0;31;1m28\x1b[0m] - \x1b[0;32mUnarmed             \x1b[0m    \n"
        "    [\x1b[0;31;1m29\x1b[0m] - \x1b[0;32mReturn to previous menu\x1b[0m    \n"
        "\x1b[0;32;1mYou must select a number from 1 to 29.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1m\x1b[0;32;1mYou may only select a skill once. \x1b[0m\x1b[0;34;1m(*)\x1b[0m\x1b[0;32;1m denotes an already-chosen skill.\n\x1b[0m\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CreationDisplayShowsChosenSkills()
{
    User.advanceSkill("bow", 1);
    Selector.initiateSelector(User);
    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mSelect a skill to advance\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m]  - \x1b[0;32mAxe                 \x1b[0m    "
        "    [\x1b[0;31;1m2\x1b[0m]  - \x1b[0;32mBlind fighting      \x1b[0m    \n"
        "    [\x1b[0;31;1m3\x1b[0m]  - \x1b[0;32mBow                 \x1b[0m\x1b[0;34;1m (*)\x1b[0m"
        "    [\x1b[0;31;1m4\x1b[0m]  - \x1b[0;32mChainmail           \x1b[0m    \n"
        "    [\x1b[0;31;1m5\x1b[0m]  - \x1b[0;32mCrossbow            \x1b[0m    "
        "    [\x1b[0;31;1m6\x1b[0m]  - \x1b[0;32mDagger              \x1b[0m    \n"
        "    [\x1b[0;31;1m7\x1b[0m]  - \x1b[0;32mDodge               \x1b[0m    "
        "    [\x1b[0;31;1m8\x1b[0m]  - \x1b[0;32mDual wield          \x1b[0m    \n"
        "    [\x1b[0;31;1m9\x1b[0m]  - \x1b[0;32mFlail               \x1b[0m    "
        "    [\x1b[0;31;1m10\x1b[0m] - \x1b[0;32mHammer              \x1b[0m    \n"
        "    [\x1b[0;31;1m11\x1b[0m] - \x1b[0;32mHand and a half s...\x1b[0m    "
        "    [\x1b[0;31;1m12\x1b[0m] - \x1b[0;32mHard leather        \x1b[0m    \n"
        "    [\x1b[0;31;1m13\x1b[0m] - \x1b[0;32mLong sword          \x1b[0m    "
        "    [\x1b[0;31;1m14\x1b[0m] - \x1b[0;32mMace                \x1b[0m    \n"
        "    [\x1b[0;31;1m15\x1b[0m] - \x1b[0;32mNo armor            \x1b[0m    "
        "    [\x1b[0;31;1m16\x1b[0m] - \x1b[0;32mParry               \x1b[0m    \n"
        "    [\x1b[0;31;1m17\x1b[0m] - \x1b[0;32mPlate armor         \x1b[0m    "
        "    [\x1b[0;31;1m18\x1b[0m] - \x1b[0;32mPole arm            \x1b[0m    \n"
        "    [\x1b[0;31;1m19\x1b[0m] - \x1b[0;32mScalemail           \x1b[0m    "
        "    [\x1b[0;31;1m20\x1b[0m] - \x1b[0;32mShield              \x1b[0m    \n"
        "    [\x1b[0;31;1m21\x1b[0m] - \x1b[0;32mShort sword         \x1b[0m    "
        "    [\x1b[0;31;1m22\x1b[0m] - \x1b[0;32mSling               \x1b[0m    \n"
        "    [\x1b[0;31;1m23\x1b[0m] - \x1b[0;32mSoft leather        \x1b[0m    "
        "    [\x1b[0;31;1m24\x1b[0m] - \x1b[0;32mSplint armor        \x1b[0m    \n"
        "    [\x1b[0;31;1m25\x1b[0m] - \x1b[0;32mStaff               \x1b[0m    "
        "    [\x1b[0;31;1m26\x1b[0m] - \x1b[0;32mThrown              \x1b[0m    \n"
        "    [\x1b[0;31;1m27\x1b[0m] - \x1b[0;32mTwo-handed sword    \x1b[0m    "
        "    [\x1b[0;31;1m28\x1b[0m] - \x1b[0;32mUnarmed             \x1b[0m    \n"
        "    [\x1b[0;31;1m29\x1b[0m] - \x1b[0;32mReturn to previous menu\x1b[0m    \n"
        "\x1b[0;32;1mYou must select a number from 1 to 29.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1m\x1b[0;32;1mYou may only select a skill once. \x1b[0m\x1b[0;34;1m(*)\x1b[0m\x1b[0;32;1m denotes an already-chosen skill.\n\x1b[0m\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingItemSetsSelectionAndFiresOnSelectorCompleted()
{
    object subscriber = clone_object("/lib/tests/support/events/onSelectorCompletedEventSubscriber.c");
    Selector.registerEvent(subscriber);
    Selector.initiateSelector(User);

    ExpectEq(({}), Selector.selection());
    ExpectEq(0, subscriber.TimesEventReceived());
    Selector.applySelection("1");

    ExpectEq(1, subscriber.TimesEventReceived(), "event received");
    ExpectEq(({ "axe" }), Selector.selection());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingReturnToPreviousSetsSelectionToNullAndFiresOnSelectorCompleted()
{
    object subscriber = clone_object("/lib/tests/support/events/onSelectorCompletedEventSubscriber.c");
    Selector.registerEvent(subscriber);
    Selector.initiateSelector(User);

    ExpectEq(({}), Selector.selection());
    ExpectEq(0, subscriber.TimesEventReceived());
    Selector.applySelection("29");

    ExpectEq(1, subscriber.TimesEventReceived(), "event received");
    ExpectEq(({}), Selector.selection());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeAxeDisplaysDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 1");

    ExpectEq("\x1b[0;36mThis skill provides proficiency in the use of axes of any nature, barring\n"
        "those axes mounted to pole arms. This skill encompasses skill with battle\n"
        "axes, hand axes, crescent axes, war axes, and other weapons of that "
        "nature -\nweapons that can be wielded with one or two hands.\n"
        "\x1b[0;32m    Affecting attribute: \x1b[0m\x1b[0;34;1mStrength\x1b[0m\n"
        "\x1b[0;31;1m    Attempting to use this skill untrained will incur a penalty.\n\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeBlindFightingDisplaysDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 2");

    ExpectEq("\x1b[0;36mThis skill provides proficiency in attacking and defending when you cannot\nsee.\n"
        "\x1b[0;32m    Affecting attribute: \x1b[0m\x1b[0;34;1mWisdom\x1b[0m\n"
        "\x1b[0;31;1m    Attempting to use this skill untrained will incur a penalty.\n\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeBowDisplaysDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 3");

    ExpectEq("\x1b[0;36mThis skill provides proficiency in all arm-drawn bows. This includes short\n"
        "bows, long bows, composite bows, recurves, and compound bows.\n"
        "\x1b[0;32m    Affecting attribute: \x1b[0m\x1b[0;34;1mDexterity\x1b[0m\n"
        "\x1b[0;31;1m    Attempting to use this skill untrained will incur a penalty.\n\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeChainmailDisplaysDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 4");

    ExpectEq("\x1b[0;36mThis skill provides proficiency in the use of chain-type armors such as "
        "chain\nmail and any other armor fashioned of interlocking or interwoven rings of\n"
        "material. This allows for good mobility in a fairly heavy/strong armor.\n"
        "\x1b[0;32m    Affecting attribute: \x1b[0m\x1b[0;34;1mStrength\x1b[0m\n"
        "\x1b[0;31;1m    Attempting to use this skill untrained will incur a penalty.\n\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeCrossbowDisplaysDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 5");

    ExpectEq("\x1b[0;36mThis skill provides proficiency in all mechanically drawn/held bows. This\n"
        "includes all crossbows, ballista, etc.\n"
        "\x1b[0;32m    Affecting attribute: \x1b[0m\x1b[0;34;1mDexterity\x1b[0m\n"
        "\x1b[0;31;1m    Attempting to use this skill untrained will incur a penalty.\n\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeDaggerDisplaysDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 6");

    ExpectEq("\x1b[0;36mThis skill provides proficiency in the use of bladed weapons that are\n"
        "typically less than 18\" long. This includes daggers, knives, dirks,\nstilletos, "
        "and other weapons of this nature.\n"
        "\x1b[0;32m    Affecting attribute: \x1b[0m\x1b[0;34;1mDexterity\x1b[0m\n"
        "\x1b[0;31;1m    Attempting to use this skill untrained will incur a penalty.\n\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeDodgeDisplaysDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 7");

    ExpectEq("\x1b[0;36mThis skill provides proficiency in avoiding an opponent's attack.\n"
        "\x1b[0;32m    Affecting attribute: \x1b[0m\x1b[0;34;1mDexterity\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeDualWieldDisplaysDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 8");

    ExpectEq("\x1b[0;36mThis skill provides proficiency in attacking with an offhand weapon.\n"
        "\x1b[0;32m    Affecting attribute: \x1b[0m\x1b[0;34;1mDexterity\x1b[0m\n"
        "\x1b[0;31;1m    Attempting to use this skill untrained will incur a penalty.\n\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeFlailDisplaysDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 9");

    ExpectEq("\x1b[0;36mThis skill provides proficiency in the use of the more exotic 'jointed' "
        "style\nweapons. This includes weapons such as flails, whips, chains, and other "
        "such\nweapons.\n"
        "\x1b[0;32m    Affecting attribute: \x1b[0m\x1b[0;34;1mStrength\x1b[0m\n"
        "\x1b[0;31;1m    Attempting to use this skill untrained will incur a penalty.\n\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeHammerDisplaysDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 10");

    ExpectEq("\x1b[0;36mThis skill provides proficiency in the use of all of the various types of\n"
        "hammers including war hammers, mauls, luscerne hammers, and other weapons of\n"
        "that nature.\n"
        "\x1b[0;32m    Affecting attribute: \x1b[0m\x1b[0;34;1mStrength\x1b[0m\n"
        "\x1b[0;31;1m    Attempting to use this skill untrained will incur a penalty.\n\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeHandHalfSwordDisplaysDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 11");

    ExpectEq("\x1b[0;36mThis skill provides proficiency in the use of larger swords (upper end "
        "of\nlong swords and larger) that could be wielded with either one or two hands.\n"
        "Using two hands with a weapon of this type provides a bonus on attack and\ndamage "
        "attempts. Swords of this type include bastard swords and claymores.\n"
        "\x1b[0;32m    Affecting attribute: \x1b[0m\x1b[0;34;1mStrength\x1b[0m\n"
        "\x1b[0;31;1m    Attempting to use this skill untrained will incur a penalty.\n\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeHardLeatherDisplaysDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 12");

    ExpectEq("\x1b[0;36mHard leather is leather treated in a manner above and beyond simple "
        "tanning.\nThe leather is fairly rigid and offers better protection than usual "
        "leather,\nbut at the sacrifice of mobility. Often times, studs are sewn into the "
        "armor\nto provide extra protection against weapons.\n"
        "\x1b[0;32m    Affecting attribute: \x1b[0m\x1b[0;34;1mStrength\x1b[0m\n"
        "\x1b[0;31;1m    Attempting to use this skill untrained will incur a penalty.\n\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeLongSwordDisplaysDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 13");

    ExpectEq("\x1b[0;36mThis skill provides proficiency in the use of most swords ranging from\n"
        "two-and-a-half foot long swords to about four-and-a-half foot long swords\nwith "
        "respect to an average 5'6\" human. This includes (but is not limited to)\nlong "
        "swords, scimitars, cutlasses, rapiers, katanas, broadswords, and sabres.\n\n"
        "\x1b[0;32m    Affecting attribute: \x1b[0m\x1b[0;34;1mStrength\x1b[0m\n"
        "\x1b[0;31;1m    Attempting to use this skill untrained will incur a penalty.\n\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeMaceDisplaysDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 14");

    ExpectEq("\x1b[0;36mThe mace skill is used for any one-handed bludgeoning weapon crafted more or\n"
        "less entirely of a single material. This includes maces, clubs, and morning\n"
        "stars.\n"
        "\x1b[0;32m    Affecting attribute: \x1b[0m\x1b[0;34;1mStrength\x1b[0m\n"
        "\x1b[0;31;1m    Attempting to use this skill untrained will incur a penalty.\n\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeNoArmorDisplaysDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 15");

    ExpectEq("\x1b[0;36mArmors that fall in this category are padded armors made of cloth, robes, "
        "and\nevery day clothing.\n"
        "\x1b[0;32m    Affecting attribute: \x1b[0m\x1b[0;34;1mDexterity\x1b[0m\n"
        "\x1b[0;31;1m    Attempting to use this skill untrained will incur a penalty.\n\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeParryDisplaysDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 16");

    ExpectEq("\x1b[0;36mThis skill provides proficiency in using one's weapon to block an attack.\n"
        "\x1b[0;32m    Affecting attribute: \x1b[0m\x1b[0;34;1mDexterity\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribePlateArmorDisplaysDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 17");

    ExpectEq("\x1b[0;36mThis skill provides proficiency in the use of heavy armors made of "
        "plates of\nmaterial, typically, but not exclusively, of metal. Armors of this "
        "family\ninclude full plate, field plate, plate mail, and breastplates.\n"
        "\x1b[0;32m    Affecting attribute: \x1b[0m\x1b[0;34;1mStrength\x1b[0m\n"
        "\x1b[0;31;1m    Attempting to use this skill untrained will incur a penalty.\n\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribePoleArmDisplaysDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 18");

    ExpectEq("\x1b[0;36mThis skill provides proficiency in the use of pole arms -- any weapon with "
        "a\nmetal head attached to a long pole. This includes halberds, spears, pikes,\n"
        "glaives, bardiches, pole axes, bills, etc.\n"
        "\x1b[0;32m    Affecting attribute: \x1b[0m\x1b[0;34;1mStrength\x1b[0m\n"
        "\x1b[0;31;1m    Attempting to use this skill untrained will incur a penalty.\n\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeScalemailDisplaysDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 19");

    ExpectEq("\x1b[0;36mScale armor represents those armors fashioned of some substrate such as "
        "chain\narmor or leather with small metal (or other rigid substance) plates woven\n"
        "through the substrate (typically layered in a fashion similar to a fish's\n"
        "scales.) Armors of this nature typically afford decent protection at the cost\n"
        "of mobility.\n"
        "\x1b[0;32m    Affecting attribute: \x1b[0m\x1b[0;34;1mStrength\x1b[0m\n"
        "\x1b[0;31;1m    Attempting to use this skill untrained will incur a penalty.\n\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeShieldDisplaysDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 20");

    ExpectEq("\x1b[0;36mThis skill provides proficiency in the use of shields as both an "
        "offensive\nand defensive weapon, though the use of shields much larger than a "
        "kite\nshield have very limited usefulness offensively. This skill encompasses\n"
        "shields with attached blades and spikes as well as those without any overt\n"
        "signs of offensive capabilities.\n"
        "\x1b[0;32m    Affecting attribute: \x1b[0m\x1b[0;34;1mStrength\x1b[0m\n"
        "\x1b[0;31;1m    Attempting to use this skill untrained will incur a penalty.\n\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeShortSwordDisplaysDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 21");

    ExpectEq("\x1b[0;36mThis skill provides proficiency in the use of short swords -- swords\n"
        "typically ranging from two-and-a-half feet and under for a typical human\n(5'6\"). "
        "This would include short swords, any form of gladus, machettes, etc.\n"
        "\x1b[0;32m    Affecting attribute: \x1b[0m\x1b[0;34;1mDexterity\x1b[0m\n"
        "\x1b[0;31;1m    Attempting to use this skill untrained will incur a penalty.\n\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeSlingDisplaysDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 22");

    ExpectEq("\x1b[0;36mThis skill provides proficiency in all sling and slinglike weapons (such "
        "as\nslingshots and staff slings).\n"
        "\x1b[0;32m    Affecting attribute: \x1b[0m\x1b[0;34;1mDexterity\x1b[0m\n"
        "\x1b[0;31;1m    Attempting to use this skill untrained will incur a penalty.\n\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeSoftLeatherDisplaysDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 23");

    ExpectEq("\x1b[0;36mThis skill provides proficiency in the use of untreated or tanned leather\n"
        "armors. The armor offers a great deal of mobility but offers only modest\n"
        "protection from harm.\n"
        "\x1b[0;32m    Affecting attribute: \x1b[0m\x1b[0;34;1mDexterity\x1b[0m\n"
        "\x1b[0;31;1m    Attempting to use this skill untrained will incur a penalty.\n\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeSplintArmorDisplaysDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 24");

    ExpectEq("\x1b[0;36mSplint armor allows for more flexibility than plate armor. Splint armors "
        "are\ntypically fashioned out of long bands - or splints - of metal attached to a\n"
        "substrate of leather, cloth, or chain.\n"
        "\x1b[0;32m    Affecting attribute: \x1b[0m\x1b[0;34;1mStrength\x1b[0m\n"
        "\x1b[0;31;1m    Attempting to use this skill untrained will incur a penalty.\n\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeStaffDisplaysDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 25");

    ExpectEq("\x1b[0;36mThis skill provides proficiency in the use of all staves and other "
        "'blunt'\npole arms such as a quarterstaff.\n"
        "\x1b[0;32m    Affecting attribute: \x1b[0m\x1b[0;34;1mStrength\x1b[0m\n"
        "\x1b[0;31;1m    Attempting to use this skill untrained will incur a penalty.\n\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeThrownDisplaysDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 26");

    ExpectEq("\x1b[0;36mThis skill provides proficiency in all thrown weapons. This includes rocks,\n"
        "bolos, hand axes, swords, daggers, hammers, javelins, as well as those\nweapons "
        "thrown with the aid of some other device such as a spear thrower.\n"
        "\x1b[0;32m    Affecting attribute: \x1b[0m\x1b[0;34;1mStrength\x1b[0m\n"
        "\x1b[0;31;1m    Attempting to use this skill untrained will incur a penalty.\n\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeTwoHandSwordDisplaysDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 27");

    ExpectEq("\x1b[0;36mThis skill provides proficiency in the use of large (roughly the length of\n"
        "the wielder's body) swords such as great swords or those swords known as\n"
        "'two-handed swords' They are weapons that could only be wielded by its user\n"
        "one-handed with great difficulty. If this isn't the case, the sword in\nquestion "
        "is likely a hand & a half sword.\n"
        "\x1b[0;32m    Affecting attribute: \x1b[0m\x1b[0;34;1mStrength\x1b[0m\n"
        "\x1b[0;31;1m    Attempting to use this skill untrained will incur a penalty.\n\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeUnarmedDisplaysDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 28");

    ExpectEq("\x1b[0;36mThis skill provides proficiency in unarmed combat. This includes punching\n"
        "wrestling, kicking, and other tactics of this nature.\n"
        "\x1b[0;32m    Affecting attribute: \x1b[0m\x1b[0;34;1mStrength\x1b[0m\n"
        "\x1b[0;31;1m    Attempting to use this skill untrained will incur a penalty.\n\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}
