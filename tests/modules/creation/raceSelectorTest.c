//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
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
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
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
    ExpectEq("\x1b[0;36m\n"
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
    ExpectEq("\x1b[0;36mThe dwarves are a short, stocky race of people. They generally\n"
        "live in hilly or mountainous areas, usually inside caves or\n"
        "similar dwellings. Dwarven craftsmanship is world renowned\n"
        "for it's durability and functionality. Dwarven structures are\n"
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
    ExpectEq("\x1b[0;36mIn appearance, elves typically have grey or blue eyes and blond\n"
        "hair. They are fair to look upon and typically stand taller than\n"
        "humans. In all ways, their bearing is majestic and sight of them\n"
        "demands attention. Elves, while they can be slain in battle or by\n"
        "mishap, do not age in the way that most races do - in fact, some\n"
        "consider them 'immortal'. The elves also tend to be aloof and\n"
        "somewhat detached from the outside world, seemingly only interested\n"
        "in their own lives. Elves also favor nature and natural beauty,\n"
        "their buildings and art reflect this.\n\n"
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
    ExpectEq("\x1b[0;36mThe faeries are a magical race of winged humanoids. They are\n"
        "smaller than humans, and are generally friendly to all. The\n"
        "faeries enjoy conversation, and enjoy companionship. They\n"
        "tend to have their own personal agendas, that they keep to\n"
        "themselves, faeries like secrets. The faeries tend to reside\n"
        "in forests or prairies, though they hide their existence well.\n\n"
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
    ExpectEq("\x1b[0;36mThe gnomes are an intelligent race of beings closely related\n"
        "to the dwarves. They are short, but less stocky than their\n"
        "dwarven cousins, They tend to have dark skin and light colored\n"
        "hair and are well-known for their rather large noses. The gnomes\n"
        "are a playful race, and they love to play jokes on others.\n"
        "They generally reside in tunnels burrowed into mountains or\n"
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
    ExpectEq("\x1b[0;36m\n"
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
    ExpectEq("\x1b[0;36mHalf-orcs are people that have both human and orcish parents.\n"
        "Like most crossbreeds, they are shunned by both of their races,\n"
        "they gain the physical strength of their orcish heritage, along\n"
        "with the incredible stamina of the orcs. From their human side,\n"
        "they gain intelligence and dexterity that the orcs lack.\n\n"
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
    ExpectEq("\x1b[0;36mHalf-trolls are people that have both human and troll parents.\n"
        "Half trolls are often seen by other trolls in much the same light as\n"
        "pure-blood trolls - trolls simply don't seem to care if half-trolls\n"
        "have a human parent. Half-trolls generally live with trolls, which\n"
        "is wherever they feel like living.\n\n"
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
    ExpectEq("\x1b[0;36mHalflings are a very small people that tend to look like\n"
        "miniaturized humans.The halflings are a fairly peaceful race:\n"
        "they don't start wars amongst themselves or others, they prefer\n"
        "to spend their time telling stories at gatherings... Halfling\n"
        "families are quite large. Halflings live in above ground homes\n"
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
    ExpectEq("\x1b[0;36mIn the crafting of items of wonder, in strength, in keen intelligence,\n"
        "and in the learning of knowledge, few surpass the high elves. Indeed,\n"
        "written language was first used by them. Industrious, no other race did\n"
        "more to beautify the lands of the world. So honored were they that the once\n"
        "lived with the very gods of the world. Little is here recorded of their deeds\n"
        "in those times save that many high elves left the blessed lands on the heels\n"
        "of a great enemy and that a darkness, both of deeds and of the soul, enshrouds\n"
        "them. In appearance, high elves typically have grey or blue eyes and black hair.\n"
        "They are fair to look upon and stand nigh on 7 feet tall. In all ways, their\n"
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
    ExpectEq("\x1b[0;36mHumans are the most common race on RealmsMUD. They don't have any\n"
        "real preferences on where they live, except that they prefer tropical\n"
        "or temperate regions. They live in above ground dwellings, and tend\n"
        "to admire the elaborate, elegant architecture of the elves and dwarves.\n"
        "Humans gain no advantages or disadvantages on RealmsMUD, they are the\n"
        "happy medium... and they like it that way.\n\n"
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
    ExpectEq("\x1b[0;36mThe Maegenstryd are the descendants of the union of high elves,\n"
        "humans, and the gods themselves. It is said that Aronath - son of Aradran,\n"
        "the high king of the elves and Eadwyn, a goddess of hope and the mistress\n"
        "of desires - fell in love with Maerwena, the daughter of the human king of\n"
        "Tirnen. While the ensuing millenia have diluted their blood as they mate\n"
        "most often with humans, the touch of the gods and the elves is ever-present.\n"
        "In appearance, they typically have grey or blue eyes and black hair, much\n"
        "like their elven and human forbears did. They are typically taller than\n"
        "humans - few, indeed are less than six feet tall. About three thousand years\n"
        "ago after a great war shattered their realms to the far west, the remnants of\n"
        "their 'race' established the Kingdom of Eledhel and most of that land's\n"
        "nobility are of this race.\n\n"
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
