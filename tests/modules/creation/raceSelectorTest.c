//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

#define Block 1
#define Describe 2
#define Success 3

object User;
object Selector;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/modules/creation/raceSelector.c");
    Selector->init();

    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User->Name("Bob");
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
    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your race\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m]  - \x1b[0;32mDraconid            \x1b[0m\n"
        "\t[\x1b[0;31;1m2\x1b[0m]  - \x1b[0;32mDwarf               \x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m]  - \x1b[0;32mElf                 \x1b[0m\n"
        "\t[\x1b[0;31;1m4\x1b[0m]  - \x1b[0;32mFaerie              \x1b[0m\n"
        "\t[\x1b[0;31;1m5\x1b[0m]  - \x1b[0;32mGnome               \x1b[0m\n"
        "\t[\x1b[0;31;1m6\x1b[0m]  - \x1b[0;32mHalf elf            \x1b[0m\n"
        "\t[\x1b[0;31;1m7\x1b[0m]  - \x1b[0;32mHalf orc            \x1b[0m\n"
        "\t[\x1b[0;31;1m8\x1b[0m]  - \x1b[0;32mHalf troll          \x1b[0m\n"
        "\t[\x1b[0;31;1m9\x1b[0m]  - \x1b[0;32mHalfling            \x1b[0m\n"
        "\t[\x1b[0;31;1m10\x1b[0m] - \x1b[0;32mHigh elf            \x1b[0m\n"
        "\t[\x1b[0;31;1m11\x1b[0m] - \x1b[0;32mHuman               \x1b[0m\n"
        "\t[\x1b[0;31;1m12\x1b[0m] - \x1b[0;32mMaegenstryd         \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 12.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') "
        "where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfDraconidSetsRaceToDraconid()
{
    Selector->initiateSelector(User);
    Selector->applySelection("1");
    ExpectEq("\x1b[0;36mYou have selected 'Draconid'.\n\x1b[0m", User->caughtMessage());
    ExpectEq("draconid", User->Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfDwarfSetsRaceToDwarf()
{
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    ExpectEq("\x1b[0;36mYou have selected 'Dwarf'.\n\x1b[0m", User->caughtMessage());
    ExpectEq("dwarf", User->Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfElfSetsRaceToElf()
{
    Selector->initiateSelector(User);
    Selector->applySelection("3");
    ExpectEq("\x1b[0;36mYou have selected 'Elf'.\n\x1b[0m", User->caughtMessage());
    ExpectEq("elf", User->Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfFaerieSetsRaceToFaerie()
{
    Selector->initiateSelector(User);
    Selector->applySelection("4");
    ExpectEq("\x1b[0;36mYou have selected 'Faerie'.\n\x1b[0m", User->caughtMessage());
    ExpectEq("faerie", User->Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfGnomeSetsRaceToGnome()
{
    Selector->initiateSelector(User);
    Selector->applySelection("5");
    ExpectEq("\x1b[0;36mYou have selected 'Gnome'.\n\x1b[0m", User->caughtMessage());
    ExpectEq("gnome", User->Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHalfElfSetsRaceToHalfElf()
{
    Selector->initiateSelector(User);
    Selector->applySelection("6");
    ExpectEq("\x1b[0;36mYou have selected 'Half elf'.\n\x1b[0m", User->caughtMessage());
    ExpectEq("half elf", User->Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHalfOrcSetsRaceToHalfOrc()
{
    Selector->initiateSelector(User);
    Selector->applySelection("7");
    ExpectEq("\x1b[0;36mYou have selected 'Half orc'.\n\x1b[0m", User->caughtMessage());
    ExpectEq("half orc", User->Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHalfTrollSetsRaceToHalfTroll()
{
    Selector->initiateSelector(User);
    Selector->applySelection("8");
    ExpectEq("\x1b[0;36mYou have selected 'Half troll'.\n\x1b[0m", User->caughtMessage());
    ExpectEq("half troll", User->Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHalflingSetsRaceToHalfling()
{
    Selector->initiateSelector(User);
    Selector->applySelection("9");
    ExpectEq("\x1b[0;36mYou have selected 'Halfling'.\n\x1b[0m", User->caughtMessage());
    ExpectEq("halfling", User->Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHighElfSetsRaceToHighElf()
{
    Selector->initiateSelector(User);
    Selector->applySelection("10");
    ExpectEq("\x1b[0;36mYou have selected 'High elf'.\n\x1b[0m", User->caughtMessage());
    ExpectEq("high elf", User->Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHumanSetsRaceToHuman()
{
    Selector->initiateSelector(User);
    Selector->applySelection("11");
    ExpectEq("\x1b[0;36mYou have selected 'Human'.\n\x1b[0m", User->caughtMessage());
    ExpectEq("human", User->Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfMaegenstrydSetsRaceToMaegenstryd()
{
    Selector->initiateSelector(User);
    Selector->applySelection("12");
    ExpectEq("\x1b[0;36mYou have selected 'Maegenstryd'.\n\x1b[0m", User->caughtMessage());
    ExpectEq("maegenstryd", User->Race());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeDraconidDisplaysDraconidDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 1");
    ExpectEq("\x1b[0;36m\n\n"
        "The draconid race incurs the following in-game bonuses/penalties:\n"
        "\t\x1b[0;32mStarting skill points:\x1b[0m \x1b[0;34;1m8\x1b[0m\n"
        "\t\x1b[0;32mBonus to trait selection:\x1b[0m \x1b[0;34;1m4\x1b[0m\n"
        "\t\x1b[0;32mStrength    \x1b[0m \x1b[0;34;1m+1\x1b[0m\n"
        "\t\x1b[0;32mIntelligence\x1b[0m \x1b[0;34;1m+1\x1b[0m\n"
        "\t\x1b[0;32mCharisma    \x1b[0m \x1b[0;34;1m+1\x1b[0m\n"
        "\t\x1b[0;32mBonus heal spell points\x1b[0m \x1b[0;34;1m+2\x1b[0m\n"
        "\t\x1b[0;32mBonus heal spell points rate\x1b[0m \x1b[0;34;1m+2\x1b[0m\n"
        "\t\x1b[0;32mSpell points\x1b[0m \x1b[0;34;1m+75\x1b[0m\n"
        "\t\x1b[0;32mBonus Common skill\x1b[0m \x1b[0;34;1m+5\x1b[0m\n"
        "\t\x1b[0;32mBonus Draconid skill\x1b[0m \x1b[0;34;1m+8\x1b[0m\n"
        "\t\x1b[0;32mBonus Elemental air skill\x1b[0m \x1b[0;34;1m+1\x1b[0m\n"
        "\t\x1b[0;32mBonus Elemental earth skill\x1b[0m \x1b[0;34;1m+1\x1b[0m\n"
        "\t\x1b[0;32mBonus Elemental fire skill\x1b[0m \x1b[0;34;1m+1\x1b[0m\n"
        "\t\x1b[0;32mBonus Elemental water skill\x1b[0m \x1b[0;34;1m+1\x1b[0m\n"
        "\t\x1b[0;32mBonus Magical essence skill\x1b[0m \x1b[0;34;1m+5\x1b[0m\n"
        "\t\x1b[0;32mBonus Spellcraft skill\x1b[0m \x1b[0;34;1m+5\x1b[0m\n"
        "\t\x1b[0;34;1mA special research tree only available to this race is unlocked.\x1b[0m\n"
        "\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeDwarfDisplaysDwarfDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 2");
    ExpectEq("\x1b[0;36mThe dwarves are a short, stocky race of people. They generally "
        "live in hilly\nor mountainous areas, usually inside caves or "
        "similar dwellings. Dwarven\ncraftsmanship is world renowned "
        "for it's durability and functionality. Dwarven\nstructures are "
        "built to last through war and the elements.\n\n"
        "The dwarf race incurs the following in-game bonuses/penalties:\n"
        "\t\x1b[0;32mStarting skill points:\x1b[0m \x1b[0;34;1m8\x1b[0m\n"
        "\t\x1b[0;32mBonus to trait selection:\x1b[0m \x1b[0;34;1m5\x1b[0m\n"
        "\t\x1b[0;32mStrength    \x1b[0m \x1b[0;34;1m+1\x1b[0m\n"
        "\t\x1b[0;32mIntelligence\x1b[0m \x1b[0;31m-1\x1b[0m\n"
        "\t\x1b[0;32mWisdom      \x1b[0m \x1b[0;31m-1\x1b[0m\n"
        "\t\x1b[0;32mConstitution\x1b[0m \x1b[0;34;1m+2\x1b[0m\n"
        "\t\x1b[0;32mCharisma    \x1b[0m \x1b[0;31m-1\x1b[0m\n"
        "\t\x1b[0;32mDefense     \x1b[0m \x1b[0;34;1m+2\x1b[0m\n"
        "\t\x1b[0;32mHit points  \x1b[0m \x1b[0;34;1m+25\x1b[0m\n"
        "\t\x1b[0;32mStamina points\x1b[0m \x1b[0;34;1m+25\x1b[0m\n"
        "\t\x1b[0;32mBonus Blacksmithing skill\x1b[0m \x1b[0;34;1m+4\x1b[0m\n"
        "\t\x1b[0;32mBonus Common skill\x1b[0m \x1b[0;34;1m+5\x1b[0m\n"
        "\t\x1b[0;32mBonus Dwarven skill\x1b[0m \x1b[0;34;1m+8\x1b[0m\n"
        "\t\x1b[0;32mBonus Hammer skill\x1b[0m \x1b[0;34;1m+3\x1b[0m\n"
        "\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeElfDisplaysElfDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 3");
    ExpectEq("\x1b[0;36mIn appearance, elves typically have grey or blue eyes and blond "
        "hair. They are\nfair to look upon and typically stand taller than "
        "humans. In all ways, their\nbearing is majestic and sight of them "
        "demands attention. Elves, while they can\nbe slain in battle or by "
        "mishap, do not age in the way that most races do - in\nfact, some "
        "consider them 'immortal'. The elves also tend to be aloof and\n"
        "somewhat detached from the outside world, seemingly only interested "
        "in their\nown lives. Elves also favor nature and natural beauty, "
        "their buildings and art\nreflect this.\n\n"
        "The elf race incurs the following in-game bonuses/penalties:\n"
        "\t\x1b[0;32mStarting skill points:\x1b[0m \x1b[0;34;1m10\x1b[0m\n"
        "\t\x1b[0;32mBonus to trait selection:\x1b[0m \x1b[0;34;1m4\x1b[0m\n"
        "\t\x1b[0;32mStrength    \x1b[0m \x1b[0;34;1m+1\x1b[0m\n"
        "\t\x1b[0;32mIntelligence\x1b[0m \x1b[0;34;1m+1\x1b[0m\n"
        "\t\x1b[0;32mDexterity   \x1b[0m \x1b[0;34;1m+1\x1b[0m\n"
        "\t\x1b[0;32mConstitution\x1b[0m \x1b[0;34;1m+1\x1b[0m\n"
        "\t\x1b[0;32mCharisma    \x1b[0m \x1b[0;34;1m+1\x1b[0m\n"
        "\t\x1b[0;32mBonus heal spell points rate\x1b[0m \x1b[0;34;1m+2\x1b[0m\n"
        "\t\x1b[0;32mDefend attack\x1b[0m \x1b[0;34;1m+1\x1b[0m\n"
        "\t\x1b[0;32mSpell points\x1b[0m \x1b[0;34;1m+25\x1b[0m\n"
        "\t\x1b[0;32mBonus Common skill\x1b[0m \x1b[0;34;1m+5\x1b[0m\n"
        "\t\x1b[0;32mBonus Elven skill\x1b[0m \x1b[0;34;1m+8\x1b[0m\n"
        "\x1b[0m",
        User->caughtMessage());
}


/////////////////////////////////////////////////////////////////////////////
void DescribeFaerieDisplaysFaerieDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 4");
    ExpectEq("\x1b[0;36mThe faeries are a magical race of winged humanoids. They are "
        "smaller than\nhumans, and are generally friendly to all. The "
        "faeries enjoy conversation, and\nenjoy companionship. They "
        "tend to have their own personal agendas, that they\nkeep to "
        "themselves, faeries like secrets. The faeries tend to reside "
        "in\nforests or prairies, though they hide their existence well.\n\n"
        "The faerie race incurs the following in-game bonuses/penalties:\n"
        "\t\x1b[0;32mStarting skill points:\x1b[0m \x1b[0;34;1m10\x1b[0m\n"
        "\t\x1b[0;32mBonus to trait selection:\x1b[0m \x1b[0;34;1m5\x1b[0m\n"
        "\t\x1b[0;32mStrength    \x1b[0m \x1b[0;31m-2\x1b[0m\n"
        "\t\x1b[0;32mIntelligence\x1b[0m \x1b[0;34;1m+1\x1b[0m\n"
        "\t\x1b[0;32mDexterity   \x1b[0m \x1b[0;34;1m+2\x1b[0m\n"
        "\t\x1b[0;32mConstitution\x1b[0m \x1b[0;31m-2\x1b[0m\n"
        "\t\x1b[0;32mCharisma    \x1b[0m \x1b[0;34;1m+1\x1b[0m\n"
        "\t\x1b[0;32mBonus heal spell points\x1b[0m \x1b[0;34;1m+2\x1b[0m\n"
        "\t\x1b[0;32mBonus heal spell points rate\x1b[0m \x1b[0;34;1m+4\x1b[0m\n"
        "\t\x1b[0;32mHit points  \x1b[0m \x1b[0;31m-50\x1b[0m\n"
        "\t\x1b[0;32mSpell points\x1b[0m \x1b[0;34;1m+50\x1b[0m\n"
        "\t\x1b[0;32mBonus Common skill\x1b[0m \x1b[0;34;1m+8\x1b[0m\n"
        "\t\x1b[0;32mBonus Elven skill\x1b[0m \x1b[0;34;1m+8\x1b[0m\n"
        "\t\x1b[0;32mBonus Magical essence skill\x1b[0m \x1b[0;34;1m+5\x1b[0m\n"
        "\t\x1b[0;32mBonus Spellcraft skill\x1b[0m \x1b[0;34;1m+5\x1b[0m\n"
        "\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeGnomeDisplaysGnomeDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 5");
    ExpectEq("\x1b[0;36mThe gnomes are an intelligent race of beings closely related "
        "to the dwarves.\nThey are short, but less stocky than their "
        "dwarven cousins, They tend to have\ndark skin and light colored "
        "hair and are well-known for their rather large\nnoses. The gnomes "
        "are a playful race, and they love to play jokes on others.\n"
        "They generally reside in tunnels burrowed into mountains or "
        "hills.\n\n"
        "The gnome race incurs the following in-game bonuses/penalties:\n"
        "\t\x1b[0;32mStarting skill points:\x1b[0m \x1b[0;34;1m10\x1b[0m\n"
        "\t\x1b[0;32mBonus to trait selection:\x1b[0m \x1b[0;34;1m5\x1b[0m\n"
        "\t\x1b[0;32mStrength    \x1b[0m \x1b[0;31m-1\x1b[0m\n"
        "\t\x1b[0;32mIntelligence\x1b[0m \x1b[0;34;1m+2\x1b[0m\n"
        "\t\x1b[0;32mWisdom      \x1b[0m \x1b[0;31m-1\x1b[0m\n"
        "\t\x1b[0;32mBonus heal spell points\x1b[0m \x1b[0;34;1m+2\x1b[0m\n"
        "\t\x1b[0;32mSpell points\x1b[0m \x1b[0;34;1m+25\x1b[0m\n"
        "\t\x1b[0;32mBonus Common skill\x1b[0m \x1b[0;34;1m+8\x1b[0m\n"
        "\t\x1b[0;32mBonus Engineering skill\x1b[0m \x1b[0;34;1m+2\x1b[0m\n"
        "\t\x1b[0;32mBonus Spellcraft skill\x1b[0m \x1b[0;34;1m+3\x1b[0m\n"
        "\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeHalfElfDisplaysHalfElfDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 6");
    ExpectEq("\x1b[0;36m\n\n"
        "The half elf race incurs the following in-game bonuses/penalties:\n"
        "\t\x1b[0;32mStarting skill points:\x1b[0m \x1b[0;34;1m10\x1b[0m\n"
        "\t\x1b[0;32mBonus to trait selection:\x1b[0m \x1b[0;34;1m5\x1b[0m\n"
        "\t\x1b[0;32mIntelligence\x1b[0m \x1b[0;34;1m+1\x1b[0m\n"
        "\t\x1b[0;32mHit points  \x1b[0m \x1b[0;34;1m+10\x1b[0m\n"
        "\t\x1b[0;32mSpell points\x1b[0m \x1b[0;34;1m+25\x1b[0m\n"
        "\t\x1b[0;32mBonus Common skill\x1b[0m \x1b[0;34;1m+8\x1b[0m\n"
        "\t\x1b[0;32mBonus Elven skill\x1b[0m \x1b[0;34;1m+8\x1b[0m\n"
        "\t\x1b[0;32mBonus Spellcraft skill\x1b[0m \x1b[0;34;1m+3\x1b[0m\n"
        "\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeHalfOrcDisplaysHalfOrcDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 7");
    ExpectEq("\x1b[0;36mHalf-orcs are people that have both human and orcish parents. "
        "Like most\ncrossbreeds, they are shunned by both of their races, "
        "they gain the physical\nstrength of their orcish heritage, along "
        "with the incredible stamina of the\norcs. From their human side, "
        "they gain intelligence and dexterity that the\norcs lack.\n\n"
        "The half orc race incurs the following in-game bonuses/penalties:\n"
        "\t\x1b[0;32mStarting skill points:\x1b[0m \x1b[0;34;1m8\x1b[0m\n"
        "\t\x1b[0;32mBonus to trait selection:\x1b[0m \x1b[0;34;1m5\x1b[0m\n"
        "\t\x1b[0;32mStrength    \x1b[0m \x1b[0;34;1m+2\x1b[0m\n"
        "\t\x1b[0;32mIntelligence\x1b[0m \x1b[0;31m-1\x1b[0m\n"
        "\t\x1b[0;32mConstitution\x1b[0m \x1b[0;34;1m+1\x1b[0m\n"
        "\t\x1b[0;32mCharisma    \x1b[0m \x1b[0;31m-2\x1b[0m\n"
        "\t\x1b[0;32mSpell points\x1b[0m \x1b[0;31m-50\x1b[0m\n"
        "\t\x1b[0;32mStamina points\x1b[0m \x1b[0;34;1m+50\x1b[0m\n"
        "\t\x1b[0;32mBonus Orcish skill\x1b[0m \x1b[0;34;1m+8\x1b[0m\n"
        "\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeHalfTrollDisplaysHalfTrollDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 8");
    ExpectEq("\x1b[0;36mHalf-trolls are people that have both human and troll parents. "
        "Half trolls are\noften seen by other trolls in much the same light as "
        "pure-blood trolls -\ntrolls simply don't seem to care if half-trolls "
        "have a human parent.\nHalf-trolls generally live with trolls, which "
        "is wherever they feel like\nliving.\n\n"
        "The half troll race incurs the following in-game bonuses/penalties:\n"
        "\t\x1b[0;32mStarting skill points:\x1b[0m \x1b[0;34;1m6\x1b[0m\n"
        "\t\x1b[0;32mBonus to trait selection:\x1b[0m \x1b[0;34;1m5\x1b[0m\n"
        "\t\x1b[0;32mStrength    \x1b[0m \x1b[0;34;1m+5\x1b[0m\n"
        "\t\x1b[0;32mIntelligence\x1b[0m \x1b[0;31m-1\x1b[0m\n"
        "\t\x1b[0;32mWisdom      \x1b[0m \x1b[0;31m-1\x1b[0m\n"
        "\t\x1b[0;32mDexterity   \x1b[0m \x1b[0;31m-1\x1b[0m\n"
        "\t\x1b[0;32mConstitution\x1b[0m \x1b[0;34;1m+2\x1b[0m\n"
        "\t\x1b[0;32mCharisma    \x1b[0m \x1b[0;31m-2\x1b[0m\n"
        "\t\x1b[0;32mBonus heal hit points\x1b[0m \x1b[0;34;1m+2\x1b[0m\n"
        "\t\x1b[0;32mBonus heal hit points rate\x1b[0m \x1b[0;34;1m+4\x1b[0m\n"
        "\t\x1b[0;32mBonus heal spell points rate\x1b[0m \x1b[0;31m-4\x1b[0m\n"
        "\t\x1b[0;32mDefense     \x1b[0m \x1b[0;34;1m+4\x1b[0m\n"
        "\t\x1b[0;32mHit points  \x1b[0m \x1b[0;34;1m+100\x1b[0m\n"
        "\t\x1b[0;32mSpell points\x1b[0m \x1b[0;31m-100\x1b[0m\n"
        "\t\x1b[0;32mStamina points\x1b[0m \x1b[0;34;1m+25\x1b[0m\n"
        "\t\x1b[0;32mBonus Orcish skill\x1b[0m \x1b[0;34;1m+8\x1b[0m\n"
        "\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeHalflingDisplaysHalflingDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 9");
    ExpectEq("\x1b[0;36mHalflings are a very small people that tend to look like "
        "miniaturized humans.\nThe halflings are a fairly peaceful race: "
        "they don't start wars amongst\nthemselves or others, they prefer "
        "to spend their time telling stories at\ngatherings... Halfling "
        "families are quite large. Halflings live in above\nground homes "
        "made from materials in the surrounding forests.\n\n"
        "The halfling race incurs the following in-game bonuses/penalties:\n"
        "\t\x1b[0;32mStarting skill points:\x1b[0m \x1b[0;34;1m10\x1b[0m\n"
        "\t\x1b[0;32mBonus to trait selection:\x1b[0m \x1b[0;34;1m5\x1b[0m\n"
        "\t\x1b[0;32mStrength    \x1b[0m \x1b[0;31m-1\x1b[0m\n"
        "\t\x1b[0;32mDexterity   \x1b[0m \x1b[0;34;1m+2\x1b[0m\n"
        "\t\x1b[0;32mCharisma    \x1b[0m \x1b[0;31m-1\x1b[0m\n"
        "\t\x1b[0;32mBonus heal hit points\x1b[0m \x1b[0;34;1m+2\x1b[0m\n"
        "\t\x1b[0;32mBonus heal hit points rate\x1b[0m \x1b[0;34;1m+2\x1b[0m\n"
        "\t\x1b[0;32mBonus Common skill\x1b[0m \x1b[0;34;1m+5\x1b[0m\n"
        "\t\x1b[0;32mBonus Hide skill\x1b[0m \x1b[0;34;1m+3\x1b[0m\n"
        "\t\x1b[0;32mBonus Move silently skill\x1b[0m \x1b[0;34;1m+3\x1b[0m\n"
        "\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeHighElfDisplaysHighElfDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 10");
    ExpectEq("\x1b[0;36mIn the crafting of items of wonder, in strength, in keen intelligence, "
        "and in\nthe learning of knowledge, few surpass the high elves. Indeed, "
        "written\nlanguage was first used by them. Industrious, no other race did "
        "more to\nbeautify the lands of the world. So honored were they that the once "
        "lived with\nthe very gods of the world. Little is here recorded of their deeds "
        "in those\ntimes save that many high elves left the blessed lands on the heels "
        "of a great\nenemy and that a darkness, both of deeds and of the soul, enshrouds "
        "them. In\nappearance, high elves typically have grey or blue eyes and black hair. "
        "They\nare fair to look upon and stand nigh on 7 feet tall. In all ways, their\n"
        "bearing is majestic and sight of them demands attention.\n\n"
        "The high elf race incurs the following in-game bonuses/penalties:\n"
        "\t\x1b[0;32mStarting skill points:\x1b[0m \x1b[0;34;1m6\x1b[0m\n"
        "\t\x1b[0;32mBonus to trait selection:\x1b[0m \x1b[0;34;1m4\x1b[0m\n"
        "\t\x1b[0;32mStrength    \x1b[0m \x1b[0;34;1m+1\x1b[0m\n"
        "\t\x1b[0;32mIntelligence\x1b[0m \x1b[0;34;1m+2\x1b[0m\n"
        "\t\x1b[0;32mConstitution\x1b[0m \x1b[0;34;1m+1\x1b[0m\n"
        "\t\x1b[0;32mCharisma    \x1b[0m \x1b[0;34;1m+2\x1b[0m\n"
        "\t\x1b[0;32mBonus heal spell points rate\x1b[0m \x1b[0;34;1m+2\x1b[0m\n"
        "\t\x1b[0;32mDefend attack\x1b[0m \x1b[0;34;1m+1\x1b[0m\n"
        "\t\x1b[0;32mHit points  \x1b[0m \x1b[0;34;1m+25\x1b[0m\n"
        "\t\x1b[0;32mSpell points\x1b[0m \x1b[0;34;1m+50\x1b[0m\n"
        "\t\x1b[0;32mBonus Blacksmithing skill\x1b[0m \x1b[0;34;1m+3\x1b[0m\n"
        "\t\x1b[0;32mBonus Bow skill\x1b[0m \x1b[0;34;1m+3\x1b[0m\n"
        "\t\x1b[0;32mBonus Common skill\x1b[0m \x1b[0;34;1m+8\x1b[0m\n"
        "\t\x1b[0;32mBonus Elven skill\x1b[0m \x1b[0;34;1m+8\x1b[0m\n"
        "\t\x1b[0;32mBonus High elven skill\x1b[0m \x1b[0;34;1m+10\x1b[0m\n"
        "\t\x1b[0;32mBonus Long sword skill\x1b[0m \x1b[0;34;1m+5\x1b[0m\n"
        "\t\x1b[0;32mBonus Spellcraft skill\x1b[0m \x1b[0;34;1m+5\x1b[0m\n"
        "\t\x1b[0;32mBonus Weapon smithing skill\x1b[0m \x1b[0;34;1m+3\x1b[0m\n"
        "\t\x1b[0;34;1mA special research tree only available to this race is unlocked.\x1b[0m\n"
        "\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeHumanDisplaysHumanDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 11");
    ExpectEq("\x1b[0;36mHumans are the most common race on RealmsMUD. They don't have any "
        "real\npreferences on where they live, except that they prefer tropical "
        "or temperate\nregions. They live in above ground dwellings, and tend "
        "to admire the\nelaborate, elegant architecture of the elves and dwarves. "
        "Humans gain no\nadvantages or disadvantages on RealmsMUD, they are the "
        "happy medium... and\nthey like it that way.\n\n"
        "The human race incurs the following in-game bonuses/penalties:\n"
        "\t\x1b[0;32mStarting skill points:\x1b[0m \x1b[0;34;1m14\x1b[0m\n"
        "\t\x1b[0;32mBonus to trait selection:\x1b[0m \x1b[0;34;1m6\x1b[0m\n"
        "\t\x1b[0;32mBonus Common skill\x1b[0m \x1b[0;34;1m+5\x1b[0m\n"
        "\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeMaegenstrydDisplaysMaegenstrydDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 12");
    ExpectEq("\x1b[0;36mThe Maegenstryd are the descendants of the union of high elves, "
        "humans, and\nthe gods themselves. It is said that Aronath - son of Aradran, "
        "the high king\nof the elves and Eadwyn, a goddess of hope and the mistress "
        "of desires - fell\nin love with Maerwena, the daughter of the human king of "
        "Tirnen. While the\nensuing millenia have diluted their blood as they mate "
        "most often with humans,\nthe touch of the gods and the elves is ever-present. "
        "In appearance, they\ntypically have grey or blue eyes and black hair, much "
        "like their elven and\nhuman forbears did. They are typically taller than "
        "humans - few, indeed are\nless than six feet tall. About three thousand years "
        "ago after a great war\nshattered their realms to the far west, the remnants of "
        "their 'race'\nestablished the Kingdom of Eledhel and most of that land's "
        "nobility are of\nthis race.\n\n"
        "The maegenstryd race incurs the following in-game bonuses/penalties:\n"
        "\t\x1b[0;32mStarting skill points:\x1b[0m \x1b[0;34;1m8\x1b[0m\n"
        "\t\x1b[0;32mBonus to trait selection:\x1b[0m \x1b[0;34;1m4\x1b[0m\n"
        "\t\x1b[0;32mStrength    \x1b[0m \x1b[0;34;1m+1\x1b[0m\n"
        "\t\x1b[0;32mIntelligence\x1b[0m \x1b[0;34;1m+2\x1b[0m\n"
        "\t\x1b[0;32mConstitution\x1b[0m \x1b[0;34;1m+2\x1b[0m\n"
        "\t\x1b[0;32mCharisma    \x1b[0m \x1b[0;34;1m+1\x1b[0m\n"
        "\t\x1b[0;32mBonus heal hit points rate\x1b[0m \x1b[0;34;1m+2\x1b[0m\n"
        "\t\x1b[0;32mHit points  \x1b[0m \x1b[0;34;1m+25\x1b[0m\n"
        "\t\x1b[0;32mSpell points\x1b[0m \x1b[0;34;1m+15\x1b[0m\n"
        "\t\x1b[0;32mStamina points\x1b[0m \x1b[0;34;1m+15\x1b[0m\n"
        "\t\x1b[0;32mBonus Ancient history skill\x1b[0m \x1b[0;34;1m+3\x1b[0m\n"
        "\t\x1b[0;32mBonus Common skill\x1b[0m \x1b[0;34;1m+5\x1b[0m\n"
        "\t\x1b[0;32mBonus Eledhelean skill\x1b[0m \x1b[0;34;1m+8\x1b[0m\n"
        "\t\x1b[0;32mBonus Elven skill\x1b[0m \x1b[0;34;1m+4\x1b[0m\n"
        "\t\x1b[0;32mBonus High elven skill\x1b[0m \x1b[0;34;1m+4\x1b[0m\n"
        "\t\x1b[0;32mBonus Magical essence skill\x1b[0m \x1b[0;34;1m+3\x1b[0m\n"
        "\t\x1b[0;32mBonus Perception skill\x1b[0m \x1b[0;34;1m+1\x1b[0m\n"
        "\t\x1b[0;32mBonus Spellcraft skill\x1b[0m \x1b[0;34;1m+3\x1b[0m\n"
        "\t\x1b[0;34;1mA special research tree only available to this race is unlocked.\x1b[0m\n"
        "\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectorFiresOnSelectorCompletedWhenRaceChosen()
{
    object subscriber = clone_object("/lib/tests/support/events/onSelectorCompletedEventSubscriber.c");
    Selector->registerEvent(subscriber);
    Selector->initiateSelector(User);

    ExpectEq(0, subscriber->TimesEventReceived());
    Selector->applySelection("10");
    ExpectEq(1, subscriber->TimesEventReceived());
}

/////////////////////////////////////////////////////////////////////////////
void NoneColorConfigurationDisplaysCorrectly()
{
    User->colorConfiguration("none");
    Selector->initiateSelector(User);
    ExpectEq("Character creation - Choose your race:\n"
        "\t[1]  - Draconid            \n"
        "\t[2]  - Dwarf               \n"
        "\t[3]  - Elf                 \n"
        "\t[4]  - Faerie              \n"
        "\t[5]  - Gnome               \n"
        "\t[6]  - Half elf            \n"
        "\t[7]  - Half orc            \n"
        "\t[8]  - Half troll          \n"
        "\t[9]  - Halfling            \n"
        "\t[10] - High elf            \n"
        "\t[11] - Human               \n"
        "\t[12] - Maegenstryd         \n"
        "You must select a number from 1 to 12.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EightBitColorConfigurationDisplaysCorrectly()
{
    User->colorConfiguration("8-bit");
    Selector->initiateSelector(User);
    ExpectEq("\x1b[0;38;5;80mCharacter creation - \x1b[0m\x1b[0;38;5;15;1mChoose your race\x1b[0m:\n"
        "\t[\x1b[0;38;5;9;1m1\x1b[0m]  - \x1b[0;38;5;2mDraconid            \x1b[0m\n"
        "\t[\x1b[0;38;5;9;1m2\x1b[0m]  - \x1b[0;38;5;2mDwarf               \x1b[0m\n"
        "\t[\x1b[0;38;5;9;1m3\x1b[0m]  - \x1b[0;38;5;2mElf                 \x1b[0m\n"
        "\t[\x1b[0;38;5;9;1m4\x1b[0m]  - \x1b[0;38;5;2mFaerie              \x1b[0m\n"
        "\t[\x1b[0;38;5;9;1m5\x1b[0m]  - \x1b[0;38;5;2mGnome               \x1b[0m\n"
        "\t[\x1b[0;38;5;9;1m6\x1b[0m]  - \x1b[0;38;5;2mHalf elf            \x1b[0m\n"
        "\t[\x1b[0;38;5;9;1m7\x1b[0m]  - \x1b[0;38;5;2mHalf orc            \x1b[0m\n"
        "\t[\x1b[0;38;5;9;1m8\x1b[0m]  - \x1b[0;38;5;2mHalf troll          \x1b[0m\n"
        "\t[\x1b[0;38;5;9;1m9\x1b[0m]  - \x1b[0;38;5;2mHalfling            \x1b[0m\n"
        "\t[\x1b[0;38;5;9;1m10\x1b[0m] - \x1b[0;38;5;2mHigh elf            \x1b[0m\n"
        "\t[\x1b[0;38;5;9;1m11\x1b[0m] - \x1b[0;38;5;2mHuman               \x1b[0m\n"
        "\t[\x1b[0;38;5;9;1m12\x1b[0m] - \x1b[0;38;5;2mMaegenstryd         \x1b[0m\n"
        "\x1b[0;38;5;2;1mYou must select a number from 1 to 12.\n\x1b[0m"
        "\x1b[0;38;5;144mFor details on a given choice, type 'describe X' (or '? X') "
        "where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;38;5;2;1m\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TwentyFourBitColorConfigurationDisplaysCorrectly()
{
    User->colorConfiguration("24-bit");
    Selector->initiateSelector(User);
    ExpectEq("\x1b[0;38;2;180;180;190mCharacter creation - \x1b[0m"
        "\x1b[0;38;2;255;255;255;1mChoose your race\x1b[0m:\n"
        "\t[\x1b[0;38;2;220;40;0;1m1\x1b[0m]  - \x1b[0;38;2;170;180;110mDraconid            \x1b[0m\n"
        "\t[\x1b[0;38;2;220;40;0;1m2\x1b[0m]  - \x1b[0;38;2;170;180;110mDwarf               \x1b[0m\n"
        "\t[\x1b[0;38;2;220;40;0;1m3\x1b[0m]  - \x1b[0;38;2;170;180;110mElf                 \x1b[0m\n"
        "\t[\x1b[0;38;2;220;40;0;1m4\x1b[0m]  - \x1b[0;38;2;170;180;110mFaerie              \x1b[0m\n"
        "\t[\x1b[0;38;2;220;40;0;1m5\x1b[0m]  - \x1b[0;38;2;170;180;110mGnome               \x1b[0m\n"
        "\t[\x1b[0;38;2;220;40;0;1m6\x1b[0m]  - \x1b[0;38;2;170;180;110mHalf elf            \x1b[0m\n"
        "\t[\x1b[0;38;2;220;40;0;1m7\x1b[0m]  - \x1b[0;38;2;170;180;110mHalf orc            \x1b[0m\n"
        "\t[\x1b[0;38;2;220;40;0;1m8\x1b[0m]  - \x1b[0;38;2;170;180;110mHalf troll          \x1b[0m\n"
        "\t[\x1b[0;38;2;220;40;0;1m9\x1b[0m]  - \x1b[0;38;2;170;180;110mHalfling            \x1b[0m\n"
        "\t[\x1b[0;38;2;220;40;0;1m10\x1b[0m] - \x1b[0;38;2;170;180;110mHigh elf            \x1b[0m\n"
        "\t[\x1b[0;38;2;220;40;0;1m11\x1b[0m] - \x1b[0;38;2;170;180;110mHuman               \x1b[0m\n"
        "\t[\x1b[0;38;2;220;40;0;1m12\x1b[0m] - \x1b[0;38;2;170;180;110mMaegenstryd         \x1b[0m\n"
        "\x1b[0;38;2;160;220;60;1mYou must select a number from 1 to 12.\n\x1b[0m"
        "\x1b[0;38;2;100;180;150mFor details on a given choice, type 'describe X' "
        "(or '? X') where\nX is the option about which you would like further "
        "details.\n\x1b[0m\x1b[0;38;2;160;220;60;1m\x1b[0m",
        User->caughtMessage());
}
