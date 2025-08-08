//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    Selector.init();

    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User.Name("Bob");
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
    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your race\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m]  - \x1b[0;32mDraconid            \x1b[0m\n"
        "    [\x1b[0;31;1m2\x1b[0m]  - \x1b[0;32mDwarf               \x1b[0m\n"
        "    [\x1b[0;31;1m3\x1b[0m]  - \x1b[0;32mElf                 \x1b[0m\n"
        "    [\x1b[0;31;1m4\x1b[0m]  - \x1b[0;32mFaerie              \x1b[0m\n"
        "    [\x1b[0;31;1m5\x1b[0m]  - \x1b[0;32mGnome               \x1b[0m\n"
        "    [\x1b[0;31;1m6\x1b[0m]  - \x1b[0;32mHalf elf            \x1b[0m\n"
        "    [\x1b[0;31;1m7\x1b[0m]  - \x1b[0;32mHalf orc            \x1b[0m\n"
        "    [\x1b[0;31;1m8\x1b[0m]  - \x1b[0;32mHalf troll          \x1b[0m\n"
        "    [\x1b[0;31;1m9\x1b[0m]  - \x1b[0;32mHalfling            \x1b[0m\n"
        "    [\x1b[0;31;1m10\x1b[0m] - \x1b[0;32mHigh elf            \x1b[0m\n"
        "    [\x1b[0;31;1m11\x1b[0m] - \x1b[0;32mHuman               \x1b[0m\n"
        "    [\x1b[0;31;1m12\x1b[0m] - \x1b[0;32mMaegenstryd         \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 12.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') "
        "where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfDraconidSetsRaceToDraconid()
{
    Selector.initiateSelector(User);
    Selector.applySelection("1");
    ExpectEq("\x1b[0;36mYou have selected 'Draconid'.\n\x1b[0m", User.caughtMessage());
    ExpectEq("draconid", User.Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfDwarfSetsRaceToDwarf()
{
    Selector.initiateSelector(User);
    Selector.applySelection("2");
    ExpectEq("\x1b[0;36mYou have selected 'Dwarf'.\n\x1b[0m", User.caughtMessage());
    ExpectEq("dwarf", User.Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfElfSetsRaceToElf()
{
    Selector.initiateSelector(User);
    Selector.applySelection("3");
    ExpectEq("\x1b[0;36mYou have selected 'Elf'.\n\x1b[0m", User.caughtMessage());
    ExpectEq("elf", User.Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfFaerieSetsRaceToFaerie()
{
    Selector.initiateSelector(User);
    Selector.applySelection("4");
    ExpectEq("\x1b[0;36mYou have selected 'Faerie'.\n\x1b[0m", User.caughtMessage());
    ExpectEq("faerie", User.Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfGnomeSetsRaceToGnome()
{
    Selector.initiateSelector(User);
    Selector.applySelection("5");
    ExpectEq("\x1b[0;36mYou have selected 'Gnome'.\n\x1b[0m", User.caughtMessage());
    ExpectEq("gnome", User.Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHalfElfSetsRaceToHalfElf()
{
    Selector.initiateSelector(User);
    Selector.applySelection("6");
    ExpectEq("\x1b[0;36mYou have selected 'Half elf'.\n\x1b[0m", User.caughtMessage());
    ExpectEq("half elf", User.Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHalfOrcSetsRaceToHalfOrc()
{
    Selector.initiateSelector(User);
    Selector.applySelection("7");
    ExpectEq("\x1b[0;36mYou have selected 'Half orc'.\n\x1b[0m", User.caughtMessage());
    ExpectEq("half orc", User.Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHalfTrollSetsRaceToHalfTroll()
{
    Selector.initiateSelector(User);
    Selector.applySelection("8");
    ExpectEq("\x1b[0;36mYou have selected 'Half troll'.\n\x1b[0m", User.caughtMessage());
    ExpectEq("half troll", User.Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHalflingSetsRaceToHalfling()
{
    Selector.initiateSelector(User);
    Selector.applySelection("9");
    ExpectEq("\x1b[0;36mYou have selected 'Halfling'.\n\x1b[0m", User.caughtMessage());
    ExpectEq("halfling", User.Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHighElfSetsRaceToHighElf()
{
    Selector.initiateSelector(User);
    Selector.applySelection("10");
    ExpectEq("\x1b[0;36mYou have selected 'High elf'.\n\x1b[0m", User.caughtMessage());
    ExpectEq("high elf", User.Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHumanSetsRaceToHuman()
{
    Selector.initiateSelector(User);
    Selector.applySelection("11");
    ExpectEq("\x1b[0;36mYou have selected 'Human'.\n\x1b[0m", User.caughtMessage());
    ExpectEq("human", User.Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfMaegenstrydSetsRaceToMaegenstryd()
{
    Selector.initiateSelector(User);
    Selector.applySelection("12");
    ExpectEq("\x1b[0;36mYou have selected 'Maegenstryd'.\n\x1b[0m", User.caughtMessage());
    ExpectEq("maegenstryd", User.Race());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeDraconidDisplaysDraconidDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 1");
    ExpectEq("\x1b[0;36mDraconids are a rare and ancient race, said to be descended from the great\n"
        "dragons of old. Their appearance is striking: tall and imposing, with scales\n"
        "that shimmer in hues of gold, bronze, or emerald. Their eyes gleam with an\n"
        "inner fire, and some even bear vestigial horns or crests. Draconids possess a\n"
        "natural affinity for magic, especially elemental forces, and are often\n"
        "revered or feared for their wisdom and power. Their voices carry a subtle\n"
        "resonance, and their presence commands respect. Legends tell of draconids who\n"
        "can channel the breath of dragons, though such feats are rare in the modern\n"
        "age.\n\n"
        "The draconid race incurs the following in-game bonuses/penalties:\n"
        "\x1b[0;32m    Starting skill points: \x1b[0m\x1b[0;34;1m8\x1b[0m\n"
        "\x1b[0;32m    Bonus to trait selection: \x1b[0m\x1b[0;34;1m4\x1b[0m\n"
        "\x1b[0;32m    Strength     \x1b[0m\x1b[0;34;1m+1\n"
        "\x1b[0m\x1b[0;32m    Intelligence \x1b[0m\x1b[0;34;1m+1\n"
        "\x1b[0m\x1b[0;32m    Charisma     \x1b[0m\x1b[0;34;1m+1\n"
        "\x1b[0m\x1b[0;32m    Bonus heal spell points \x1b[0m\x1b[0;34;1m+2\n"
        "\x1b[0m\x1b[0;32m    Bonus heal spell points rate \x1b[0m\x1b[0;34;1m+2\n"
        "\x1b[0m\x1b[0;32m    Spell points \x1b[0m\x1b[0;34;1m+75\n"
        "\x1b[0m\x1b[0;32m    Bonus Common skill \x1b[0m\x1b[0;34;1m+5\n"
        "\x1b[0m\x1b[0;32m    Bonus Draconid skill \x1b[0m\x1b[0;34;1m+8\n"
        "\x1b[0m\x1b[0;32m    Bonus Elemental air skill \x1b[0m\x1b[0;34;1m+1\n"
        "\x1b[0m\x1b[0;32m    Bonus Elemental earth skill \x1b[0m\x1b[0;34;1m+1\n"
        "\x1b[0m\x1b[0;32m    Bonus Elemental fire skill \x1b[0m\x1b[0;34;1m+1\n"
        "\x1b[0m\x1b[0;32m    Bonus Elemental water skill \x1b[0m\x1b[0;34;1m+1\n"
        "\x1b[0m\x1b[0;32m    Bonus Magical essence skill \x1b[0m\x1b[0;34;1m+5\n"
        "\x1b[0m\x1b[0;32m    Bonus Spellcraft skill \x1b[0m\x1b[0;34;1m+5\n"
        "\x1b[0m\x1b[0;34;1m    A special research tree only available to this race is unlocked.\n"
        "\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeDwarfDisplaysDwarfDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 2");
    ExpectEq("\x1b[0;36mThe dwarves are a short, stocky race of people. They generally live in hilly\n"
        "or mountainous areas, usually inside caves or similar dwellings. Dwarven\n"
        "craftsmanship is world renowned for its durability and functionality. Dwarven\n"
        "structures are built to last through war and the elements. Dwarves are known\n"
        "for their long, braided beards, hearty appetites, and a fierce loyalty to kin\n"
        "and clan. They are slow to trust outsiders, but once a friend is made, that\n"
        "bond is unbreakable. Dwarves are also famed for their love of precious metals\n"
        "and gems, and many spend their lives mining the depths of the earth.\n\n"
        "The dwarf race incurs the following in-game bonuses/penalties:\n"
        "\x1b[0;32m    Starting skill points: \x1b[0m\x1b[0;34;1m8\x1b[0m\n"
        "\x1b[0;32m    Bonus to trait selection: \x1b[0m\x1b[0;34;1m5\x1b[0m\n"
        "\x1b[0;32m    Strength     \x1b[0m\x1b[0;34;1m+1\n"
        "\x1b[0m\x1b[0;32m    Intelligence \x1b[0m\x1b[0;31m-1\n"
        "\x1b[0m\x1b[0;32m    Wisdom       \x1b[0m\x1b[0;31m-1\n"
        "\x1b[0m\x1b[0;32m    Constitution \x1b[0m\x1b[0;34;1m+2\n"
        "\x1b[0m\x1b[0;32m    Charisma     \x1b[0m\x1b[0;31m-1\n"
        "\x1b[0m\x1b[0;32m    Defense      \x1b[0m\x1b[0;34;1m+2\n"
        "\x1b[0m\x1b[0;32m    Hit points   \x1b[0m\x1b[0;34;1m+25\n"
        "\x1b[0m\x1b[0;32m    Stamina points \x1b[0m\x1b[0;34;1m+25\n"
        "\x1b[0m\x1b[0;32m    Bonus Blacksmithing skill \x1b[0m\x1b[0;34;1m+4\n"
        "\x1b[0m\x1b[0;32m    Bonus Common skill \x1b[0m\x1b[0;34;1m+5\n"
        "\x1b[0m\x1b[0;32m    Bonus Dwarven skill \x1b[0m\x1b[0;34;1m+8\n"
        "\x1b[0m\x1b[0;32m    Bonus Hammer skill \x1b[0m\x1b[0;34;1m+3\n"
        "\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeElfDisplaysElfDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 3");
    ExpectEq("\x1b[0;36mIn appearance, elves typically have grey or blue eyes and blond "
        "hair. They\nare fair to look upon and typically stand taller than "
        "humans. In all ways,\ntheir bearing is majestic and sight of them "
        "demands attention. Elves, while\nthey can be slain in battle or by "
        "mishap, do not age in the way that most\nraces do - in fact, some "
        "consider them 'immortal'. The elves also tend to be\naloof and "
        "somewhat detached from the outside world, seemingly only interested\n"
        "in their own lives. Elves also favor nature and natural beauty, "
        "their\nbuildings and art reflect this.\n\n"
        "The elf race incurs the following in-game bonuses/penalties:\n"
        "\x1b[0;32m    Starting skill points: \x1b[0m\x1b[0;34;1m10\x1b[0m\n"
        "\x1b[0;32m    Bonus to trait selection: \x1b[0m\x1b[0;34;1m4\x1b[0m\n"
        "\x1b[0;32m    Strength     \x1b[0m\x1b[0;34;1m+1\n"
        "\x1b[0m\x1b[0;32m    Intelligence \x1b[0m\x1b[0;34;1m+1\n"
        "\x1b[0m\x1b[0;32m    Dexterity    \x1b[0m\x1b[0;34;1m+1\n"
        "\x1b[0m\x1b[0;32m    Constitution \x1b[0m\x1b[0;34;1m+1\n"
        "\x1b[0m\x1b[0;32m    Charisma     \x1b[0m\x1b[0;34;1m+1\n"
        "\x1b[0m\x1b[0;32m    Bonus heal spell points rate \x1b[0m\x1b[0;34;1m+2\n"
        "\x1b[0m\x1b[0;32m    Defend attack \x1b[0m\x1b[0;34;1m+1\n"
        "\x1b[0m\x1b[0;32m    Spell points \x1b[0m\x1b[0;34;1m+25\n"
        "\x1b[0m\x1b[0;32m    Bonus Common skill \x1b[0m\x1b[0;34;1m+5\n"
        "\x1b[0m\x1b[0;32m    Bonus Elven skill \x1b[0m\x1b[0;34;1m+8\n"
        "\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}


/////////////////////////////////////////////////////////////////////////////
void DescribeFaerieDisplaysFaerieDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 4");
    ExpectEq("\x1b[0;36mThe faeries are a magical race of winged humanoids. They are "
        "smaller than\nhumans, and are generally friendly to all. The "
        "faeries enjoy conversation,\nand enjoy companionship. They "
        "tend to have their own personal agendas, that\nthey keep to "
        "themselves, faeries like secrets. The faeries tend to reside "
        "in\nforests or prairies, though they hide their existence well.\n\n"
        "The faerie race incurs the following in-game bonuses/penalties:\n"
        "\x1b[0;32m    Starting skill points: \x1b[0m\x1b[0;34;1m10\x1b[0m\n"
        "\x1b[0;32m    Bonus to trait selection: \x1b[0m\x1b[0;34;1m5\x1b[0m\n"
        "\x1b[0;32m    Strength     \x1b[0m\x1b[0;31m-2\n"
        "\x1b[0m\x1b[0;32m    Intelligence \x1b[0m\x1b[0;34;1m+1\n"
        "\x1b[0m\x1b[0;32m    Dexterity    \x1b[0m\x1b[0;34;1m+2\n"
        "\x1b[0m\x1b[0;32m    Constitution \x1b[0m\x1b[0;31m-2\n"
        "\x1b[0m\x1b[0;32m    Charisma     \x1b[0m\x1b[0;34;1m+1\n"
        "\x1b[0m\x1b[0;32m    Bonus heal spell points \x1b[0m\x1b[0;34;1m+2\n"
        "\x1b[0m\x1b[0;32m    Bonus heal spell points rate \x1b[0m\x1b[0;34;1m+4\n"
        "\x1b[0m\x1b[0;32m    Hit points   \x1b[0m\x1b[0;31m-50\n"
        "\x1b[0m\x1b[0;32m    Spell points \x1b[0m\x1b[0;34;1m+50\n"
        "\x1b[0m\x1b[0;32m    Bonus Common skill \x1b[0m\x1b[0;34;1m+8\n"
        "\x1b[0m\x1b[0;32m    Bonus Elven skill \x1b[0m\x1b[0;34;1m+8\n"
        "\x1b[0m\x1b[0;32m    Bonus Magical essence skill \x1b[0m\x1b[0;34;1m+5\n"
        "\x1b[0m\x1b[0;32m    Bonus Spellcraft skill \x1b[0m\x1b[0;34;1m+5\n"
        "\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeGnomeDisplaysGnomeDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 5");
    ExpectEq("\x1b[0;36mThe gnomes are an intelligent race of beings closely related "
        "to the dwarves.\nThey are short, but less stocky than their "
        "dwarven cousins, They tend to have\ndark skin and light colored "
        "hair and are well-known for their rather large\nnoses. The gnomes "
        "are a playful race, and they love to play jokes on others.\n"
        "They generally reside in tunnels burrowed into mountains or "
        "hills.\n\n"
        "The gnome race incurs the following in-game bonuses/penalties:\n"
        "\x1b[0;32m    Starting skill points: \x1b[0m\x1b[0;34;1m10\x1b[0m\n"
        "\x1b[0;32m    Bonus to trait selection: \x1b[0m\x1b[0;34;1m5\x1b[0m\n"
        "\x1b[0;32m    Strength     \x1b[0m\x1b[0;31m-1\n"
        "\x1b[0m\x1b[0;32m    Intelligence \x1b[0m\x1b[0;34;1m+2\n"
        "\x1b[0m\x1b[0;32m    Wisdom       \x1b[0m\x1b[0;31m-1\n"
        "\x1b[0m\x1b[0;32m    Bonus heal spell points \x1b[0m\x1b[0;34;1m+2\n"
        "\x1b[0m\x1b[0;32m    Spell points \x1b[0m\x1b[0;34;1m+25\n"
        "\x1b[0m\x1b[0;32m    Bonus Common skill \x1b[0m\x1b[0;34;1m+8\n"
        "\x1b[0m\x1b[0;32m    Bonus Engineering skill \x1b[0m\x1b[0;34;1m+2\n"
        "\x1b[0m\x1b[0;32m    Bonus Spellcraft skill \x1b[0m\x1b[0;34;1m+3\n"
        "\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeHalfElfDisplaysHalfElfDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 6");
    ExpectEq("\x1b[0;36mHalf-elves are the rare offspring of unions between elves and humans. They\n"
        "inherit the beauty, grace, and keen senses of their elven heritage, as well\n"
        "as the adaptability and ambition of humankind. In appearance, half-elves are\n"
        "often tall and fair, with features that blend the best of both lineages with\n"
        "eyes that seem to hold both wisdom and longing. Caught between two worlds,\n"
        "half-elves are often marked by a sense of melancholy and a longing for\n"
        "belonging, for they are not fully accepted by either elves or men. In legend,\n"
        "some half-elves have been given the choice of mortality or immortality, a\n"
        "burden and a gift that shapes their destinies.\n\n"
        "The half elf race incurs the following in-game bonuses/penalties:\n"
        "\x1b[0;32m    Starting skill points: \x1b[0m\x1b[0;34;1m10\x1b[0m\n"
        "\x1b[0;32m    Bonus to trait selection: \x1b[0m\x1b[0;34;1m5\x1b[0m\n"
        "\x1b[0;32m    Intelligence \x1b[0m\x1b[0;34;1m+1\n"
        "\x1b[0m\x1b[0;32m    Hit points   \x1b[0m\x1b[0;34;1m+10\n"
        "\x1b[0m\x1b[0;32m    Spell points \x1b[0m\x1b[0;34;1m+25\n"
        "\x1b[0m\x1b[0;32m    Bonus Common skill \x1b[0m\x1b[0;34;1m+8\n"
        "\x1b[0m\x1b[0;32m    Bonus Elven skill \x1b[0m\x1b[0;34;1m+8\n"
        "\x1b[0m\x1b[0;32m    Bonus Spellcraft skill \x1b[0m\x1b[0;34;1m+3\n"
        "\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeHalfOrcDisplaysHalfOrcDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 7");
    ExpectEq("\x1b[0;36mHalf-orcs are people that have both human and orcish parents. "
        "Like most\ncrossbreeds, they are shunned by both of their races, "
        "they gain the physical\nstrength of their orcish heritage, along "
        "with the incredible stamina of the\norcs. From their human side, "
        "they gain intelligence and dexterity that the\norcs lack.\n\n"
        "The half orc race incurs the following in-game bonuses/penalties:\n"
        "\x1b[0;32m    Starting skill points: \x1b[0m\x1b[0;34;1m8\x1b[0m\n"
        "\x1b[0;32m    Bonus to trait selection: \x1b[0m\x1b[0;34;1m5\x1b[0m\n"
        "\x1b[0;32m    Strength     \x1b[0m\x1b[0;34;1m+2\n"
        "\x1b[0m\x1b[0;32m    Intelligence \x1b[0m\x1b[0;31m-1\n"
        "\x1b[0m\x1b[0;32m    Constitution \x1b[0m\x1b[0;34;1m+1\n"
        "\x1b[0m\x1b[0;32m    Charisma     \x1b[0m\x1b[0;31m-2\n"
        "\x1b[0m\x1b[0;32m    Spell points \x1b[0m\x1b[0;31m-50\n"
        "\x1b[0m\x1b[0;32m    Stamina points \x1b[0m\x1b[0;34;1m+50\n"
        "\x1b[0m\x1b[0;32m    Bonus Orcish skill \x1b[0m\x1b[0;34;1m+8\n"
        "\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeHalfTrollDisplaysHalfTrollDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 8");
    ExpectEq("\x1b[0;36mHalf-trolls are people that have both human and troll parents. "
        "Half trolls\nare often seen by other trolls in much the same light as "
        "pure-blood trolls -\ntrolls simply don't seem to care if half-trolls "
        "have a human parent.\nHalf-trolls generally live with trolls, which "
        "is wherever they feel like\nliving.\n\n"
        "The half troll race incurs the following in-game bonuses/penalties:\n"
        "\x1b[0;32m    Starting skill points: \x1b[0m\x1b[0;34;1m6\x1b[0m\n"
        "\x1b[0;32m    Bonus to trait selection: \x1b[0m\x1b[0;34;1m5\x1b[0m\n"
        "\x1b[0;32m    Strength     \x1b[0m\x1b[0;34;1m+5\n"
        "\x1b[0m\x1b[0;32m    Intelligence \x1b[0m\x1b[0;31m-1\n"
        "\x1b[0m\x1b[0;32m    Wisdom       \x1b[0m\x1b[0;31m-1\n"
        "\x1b[0m\x1b[0;32m    Dexterity    \x1b[0m\x1b[0;31m-1\n"
        "\x1b[0m\x1b[0;32m    Constitution \x1b[0m\x1b[0;34;1m+2\n"
        "\x1b[0m\x1b[0;32m    Charisma     \x1b[0m\x1b[0;31m-2\n"
        "\x1b[0m\x1b[0;32m    Bonus heal hit points \x1b[0m\x1b[0;34;1m+2\n"
        "\x1b[0m\x1b[0;32m    Bonus heal hit points rate \x1b[0m\x1b[0;34;1m+4\n"
        "\x1b[0m\x1b[0;32m    Bonus heal spell points rate \x1b[0m\x1b[0;31m-4\n"
        "\x1b[0m\x1b[0;32m    Defense      \x1b[0m\x1b[0;34;1m+4\n"
        "\x1b[0m\x1b[0;32m    Hit points   \x1b[0m\x1b[0;34;1m+100\n"
        "\x1b[0m\x1b[0;32m    Spell points \x1b[0m\x1b[0;31m-100\n"
        "\x1b[0m\x1b[0;32m    Stamina points \x1b[0m\x1b[0;34;1m+25\n"
        "\x1b[0m\x1b[0;32m    Bonus Orcish skill \x1b[0m\x1b[0;34;1m+8\n"
        "\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeHalflingDisplaysHalflingDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 9");
    ExpectEq("\x1b[0;36mHalflings are a very small people that tend to look like "
        "miniaturized humans.\nThe halflings are a fairly peaceful race: "
        "they don't start wars amongst\nthemselves or others, they prefer "
        "to spend their time telling stories at\ngatherings... Halfling "
        "families are quite large. Halflings live in above\nground homes "
        "made from materials in the surrounding forests.\n\n"
        "The halfling race incurs the following in-game bonuses/penalties:\n"
        "\x1b[0;32m    Starting skill points: \x1b[0m\x1b[0;34;1m10\x1b[0m\n"
        "\x1b[0;32m    Bonus to trait selection: \x1b[0m\x1b[0;34;1m5\x1b[0m\n"
        "\x1b[0;32m    Strength     \x1b[0m\x1b[0;31m-1\n"
        "\x1b[0m\x1b[0;32m    Dexterity    \x1b[0m\x1b[0;34;1m+2\n"
        "\x1b[0m\x1b[0;32m    Charisma     \x1b[0m\x1b[0;31m-1\n"
        "\x1b[0m\x1b[0;32m    Bonus heal hit points \x1b[0m\x1b[0;34;1m+2\n"
        "\x1b[0m\x1b[0;32m    Bonus heal hit points rate \x1b[0m\x1b[0;34;1m+2\n"
        "\x1b[0m\x1b[0;32m    Bonus Common skill \x1b[0m\x1b[0;34;1m+5\n"
        "\x1b[0m\x1b[0;32m    Bonus Hide skill \x1b[0m\x1b[0;34;1m+3\n"
        "\x1b[0m\x1b[0;32m    Bonus Move silently skill \x1b[0m\x1b[0;34;1m+3\n"
        "\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeHighElfDisplaysHighElfDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 10");
    ExpectEq("\x1b[0;36mIn the crafting of items of wonder, in strength, in keen intelligence, "
        "and in\nthe learning of knowledge, few surpass the high elves. Indeed, "
        "written\nlanguage was first used by them. Industrious, no other race did "
        "more to\nbeautify the lands of the world. So honored were they that the once "
        "lived\nwith the very gods of the world. Little is here recorded of their deeds "
        "in\nthose times save that many high elves left the blessed lands on the heels "
        "of\na great enemy and that a darkness, both of deeds and of the soul, enshrouds\n"
        "them. In appearance, high elves typically have grey or blue eyes and black\nhair. "
        "They are fair to look upon and stand nigh on 7 feet tall. In all ways,\ntheir "
        "bearing is majestic and sight of them demands attention.\n\n"
        "The high elf race incurs the following in-game bonuses/penalties:\n"
        "\x1b[0;32m    Starting skill points: \x1b[0m\x1b[0;34;1m6\x1b[0m\n"
        "\x1b[0;32m    Bonus to trait selection: \x1b[0m\x1b[0;34;1m4\x1b[0m\n"
        "\x1b[0;32m    Strength     \x1b[0m\x1b[0;34;1m+1\n"
        "\x1b[0m\x1b[0;32m    Intelligence \x1b[0m\x1b[0;34;1m+2\n"
        "\x1b[0m\x1b[0;32m    Constitution \x1b[0m\x1b[0;34;1m+1\n"
        "\x1b[0m\x1b[0;32m    Charisma     \x1b[0m\x1b[0;34;1m+2\n"
        "\x1b[0m\x1b[0;32m    Bonus heal spell points rate \x1b[0m\x1b[0;34;1m+2\n"
        "\x1b[0m\x1b[0;32m    Defend attack \x1b[0m\x1b[0;34;1m+1\n"
        "\x1b[0m\x1b[0;32m    Hit points   \x1b[0m\x1b[0;34;1m+25\n"
        "\x1b[0m\x1b[0;32m    Spell points \x1b[0m\x1b[0;34;1m+50\n"
        "\x1b[0m\x1b[0;32m    Bonus Blacksmithing skill \x1b[0m\x1b[0;34;1m+3\n"
        "\x1b[0m\x1b[0;32m    Bonus Bow skill \x1b[0m\x1b[0;34;1m+3\n"
        "\x1b[0m\x1b[0;32m    Bonus Common skill \x1b[0m\x1b[0;34;1m+8\n"
        "\x1b[0m\x1b[0;32m    Bonus Elven skill \x1b[0m\x1b[0;34;1m+8\n"
        "\x1b[0m\x1b[0;32m    Bonus High elven skill \x1b[0m\x1b[0;34;1m+10\n"
        "\x1b[0m\x1b[0;32m    Bonus Long sword skill \x1b[0m\x1b[0;34;1m+5\n"
        "\x1b[0m\x1b[0;32m    Bonus Spellcraft skill \x1b[0m\x1b[0;34;1m+5\n"
        "\x1b[0m\x1b[0;32m    Bonus Weapon smithing skill \x1b[0m\x1b[0;34;1m+3\n"
        "\x1b[0m\x1b[0;34;1m    A special research tree only available to this race is unlocked.\n"
        "\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeHumanDisplaysHumanDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 11");
    ExpectEq("\x1b[0;36mHumans are the most common race. They don't have any real preferences on\n"
        "where they live, except that they prefer tropical or temperate regions. They\n"
        "live in above ground dwellings, and tend to admire the elaborate, elegant\n"
        "architecture of the elves and dwarves. Humans gain no advantages or\n"
        "disadvantages on RealmsMUD, they are the happy medium... and they like it\n"
        "that way.\n\n"
        "The human race incurs the following in-game bonuses/penalties:\n"
        "\x1b[0;32m    Starting skill points: \x1b[0m\x1b[0;34;1m14\x1b[0m\n"
        "\x1b[0;32m    Bonus to trait selection: \x1b[0m\x1b[0;34;1m6\x1b[0m\n"
        "\x1b[0;32m    Bonus Common skill \x1b[0m\x1b[0;34;1m+5\n"
        "\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeMaegenstrydDisplaysMaegenstrydDescription()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 12");
    ExpectEq("\x1b[0;36mThe Maegenstryd are the descendants of the union of high elves, "
        "humans, and\nthe gods themselves. It is said that Aronath - son of Aradran, "
        "the high king\nof the elves and Eadwyn, a goddess of hope and the mistress "
        "of desires - fell\nin love with Maerwena, the daughter of the human king of "
        "Tirnen. While the\nensuing millenia have diluted their blood as they mate "
        "most often with\nhumans, the touch of the gods and the elves is ever-present. "
        "In appearance,\nthey typically have grey or blue eyes and black hair, much "
        "like their elven\nand human forbears did. They are typically taller than "
        "humans - few, indeed\nare less than six feet tall. About three thousand years "
        "ago after a great war\nshattered their realms to the far west, the remnants of "
        "their 'race'\nestablished the Kingdom of Eledhel and most of that land's "
        "nobility are of\nthis race.\n\n"
        "The maegenstryd race incurs the following in-game bonuses/penalties:\n"
        "\x1b[0;32m    Starting skill points: \x1b[0m\x1b[0;34;1m8\x1b[0m\n"
        "\x1b[0;32m    Bonus to trait selection: \x1b[0m\x1b[0;34;1m4\x1b[0m\n"
        "\x1b[0;32m    Strength     \x1b[0m\x1b[0;34;1m+1\n"
        "\x1b[0m\x1b[0;32m    Intelligence \x1b[0m\x1b[0;34;1m+2\n"
        "\x1b[0m\x1b[0;32m    Constitution \x1b[0m\x1b[0;34;1m+2\n"
        "\x1b[0m\x1b[0;32m    Charisma     \x1b[0m\x1b[0;34;1m+1\n"
        "\x1b[0m\x1b[0;32m    Bonus heal hit points rate \x1b[0m\x1b[0;34;1m+2\n"
        "\x1b[0m\x1b[0;32m    Hit points   \x1b[0m\x1b[0;34;1m+25\n"
        "\x1b[0m\x1b[0;32m    Spell points \x1b[0m\x1b[0;34;1m+15\n"
        "\x1b[0m\x1b[0;32m    Stamina points \x1b[0m\x1b[0;34;1m+15\n"
        "\x1b[0m\x1b[0;32m    Bonus Ancient history skill \x1b[0m\x1b[0;34;1m+3\n"
        "\x1b[0m\x1b[0;32m    Bonus Common skill \x1b[0m\x1b[0;34;1m+5\n"
        "\x1b[0m\x1b[0;32m    Bonus Eledhelean skill \x1b[0m\x1b[0;34;1m+8\n"
        "\x1b[0m\x1b[0;32m    Bonus Elven skill \x1b[0m\x1b[0;34;1m+4\n"
        "\x1b[0m\x1b[0;32m    Bonus High elven skill \x1b[0m\x1b[0;34;1m+4\n"
        "\x1b[0m\x1b[0;32m    Bonus Magical essence skill \x1b[0m\x1b[0;34;1m+3\n"
        "\x1b[0m\x1b[0;32m    Bonus Perception skill \x1b[0m\x1b[0;34;1m+1\n"
        "\x1b[0m\x1b[0;32m    Bonus Spellcraft skill \x1b[0m\x1b[0;34;1m+3\n"
        "\x1b[0m\x1b[0;34;1m    A special research tree only available to this race is unlocked.\n"
        "\x1b[0m\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectorFiresOnSelectorCompletedWhenRaceChosen()
{
    object subscriber = clone_object("/lib/tests/support/events/onSelectorCompletedEventSubscriber.c");
    Selector.registerEvent(subscriber);
    Selector.initiateSelector(User);

    ExpectEq(0, subscriber.TimesEventReceived());
    Selector.applySelection("10");
    ExpectEq(1, subscriber.TimesEventReceived());
}

/////////////////////////////////////////////////////////////////////////////
void NoneColorConfigurationDisplaysCorrectly()
{
    User.colorConfiguration("none");
    Selector.initiateSelector(User);
    ExpectEq("Character creation - Choose your race:\n"
        "    [1]  - Draconid            \n"
        "    [2]  - Dwarf               \n"
        "    [3]  - Elf                 \n"
        "    [4]  - Faerie              \n"
        "    [5]  - Gnome               \n"
        "    [6]  - Half elf            \n"
        "    [7]  - Half orc            \n"
        "    [8]  - Half troll          \n"
        "    [9]  - Halfling            \n"
        "    [10] - High elf            \n"
        "    [11] - Human               \n"
        "    [12] - Maegenstryd         \n"
        "You must select a number from 1 to 12.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EightBitColorConfigurationDisplaysCorrectly()
{
    User.colorConfiguration("8-bit");
    Selector.initiateSelector(User);
    ExpectEq("\x1b[0;38;5;80mCharacter creation - \x1b[0m\x1b[0;38;5;15;1mChoose your race\x1b[0m:\n"
        "    [\x1b[0;38;5;9;1m1\x1b[0m]  - \x1b[0;38;5;2mDraconid            \x1b[0m\n"
        "    [\x1b[0;38;5;9;1m2\x1b[0m]  - \x1b[0;38;5;2mDwarf               \x1b[0m\n"
        "    [\x1b[0;38;5;9;1m3\x1b[0m]  - \x1b[0;38;5;2mElf                 \x1b[0m\n"
        "    [\x1b[0;38;5;9;1m4\x1b[0m]  - \x1b[0;38;5;2mFaerie              \x1b[0m\n"
        "    [\x1b[0;38;5;9;1m5\x1b[0m]  - \x1b[0;38;5;2mGnome               \x1b[0m\n"
        "    [\x1b[0;38;5;9;1m6\x1b[0m]  - \x1b[0;38;5;2mHalf elf            \x1b[0m\n"
        "    [\x1b[0;38;5;9;1m7\x1b[0m]  - \x1b[0;38;5;2mHalf orc            \x1b[0m\n"
        "    [\x1b[0;38;5;9;1m8\x1b[0m]  - \x1b[0;38;5;2mHalf troll          \x1b[0m\n"
        "    [\x1b[0;38;5;9;1m9\x1b[0m]  - \x1b[0;38;5;2mHalfling            \x1b[0m\n"
        "    [\x1b[0;38;5;9;1m10\x1b[0m] - \x1b[0;38;5;2mHigh elf            \x1b[0m\n"
        "    [\x1b[0;38;5;9;1m11\x1b[0m] - \x1b[0;38;5;2mHuman               \x1b[0m\n"
        "    [\x1b[0;38;5;9;1m12\x1b[0m] - \x1b[0;38;5;2mMaegenstryd         \x1b[0m\n"
        "\x1b[0;38;5;2;1mYou must select a number from 1 to 12.\n\x1b[0m"
        "\x1b[0;38;5;144mFor details on a given choice, type 'describe X' (or '? X') "
        "where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;38;5;2;1m\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TwentyFourBitColorConfigurationDisplaysCorrectly()
{
    User.colorConfiguration("24-bit");
    Selector.initiateSelector(User);
    ExpectEq("\x1b[0;38;2;180;180;190mCharacter creation - \x1b[0m"
        "\x1b[0;38;2;255;255;255;1mChoose your race\x1b[0m:\n"
        "    [\x1b[0;38;2;220;40;0;1m1\x1b[0m]  - \x1b[0;38;2;170;180;110mDraconid            \x1b[0m\n"
        "    [\x1b[0;38;2;220;40;0;1m2\x1b[0m]  - \x1b[0;38;2;170;180;110mDwarf               \x1b[0m\n"
        "    [\x1b[0;38;2;220;40;0;1m3\x1b[0m]  - \x1b[0;38;2;170;180;110mElf                 \x1b[0m\n"
        "    [\x1b[0;38;2;220;40;0;1m4\x1b[0m]  - \x1b[0;38;2;170;180;110mFaerie              \x1b[0m\n"
        "    [\x1b[0;38;2;220;40;0;1m5\x1b[0m]  - \x1b[0;38;2;170;180;110mGnome               \x1b[0m\n"
        "    [\x1b[0;38;2;220;40;0;1m6\x1b[0m]  - \x1b[0;38;2;170;180;110mHalf elf            \x1b[0m\n"
        "    [\x1b[0;38;2;220;40;0;1m7\x1b[0m]  - \x1b[0;38;2;170;180;110mHalf orc            \x1b[0m\n"
        "    [\x1b[0;38;2;220;40;0;1m8\x1b[0m]  - \x1b[0;38;2;170;180;110mHalf troll          \x1b[0m\n"
        "    [\x1b[0;38;2;220;40;0;1m9\x1b[0m]  - \x1b[0;38;2;170;180;110mHalfling            \x1b[0m\n"
        "    [\x1b[0;38;2;220;40;0;1m10\x1b[0m] - \x1b[0;38;2;170;180;110mHigh elf            \x1b[0m\n"
        "    [\x1b[0;38;2;220;40;0;1m11\x1b[0m] - \x1b[0;38;2;170;180;110mHuman               \x1b[0m\n"
        "    [\x1b[0;38;2;220;40;0;1m12\x1b[0m] - \x1b[0;38;2;170;180;110mMaegenstryd         \x1b[0m\n"
        "\x1b[0;38;2;160;220;60;1mYou must select a number from 1 to 12.\n\x1b[0m"
        "\x1b[0;38;2;100;180;150mFor details on a given choice, type 'describe X' "
        "(or '? X') where\nX is the option about which you would like further "
        "details.\n\x1b[0m\x1b[0;38;2;160;220;60;1m\x1b[0m",
        User.caughtMessage());
}
