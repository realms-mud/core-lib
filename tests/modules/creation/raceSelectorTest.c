//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mChoose your race[0m:\n"
        "\t[[0;31m1[0m] - [0;32mDraconid            [0m\n"
        "\t[[0;31m2[0m] - [0;32mDwarf               [0m\n"
        "\t[[0;31m3[0m] - [0;32mElf                 [0m\n"
        "\t[[0;31m4[0m] - [0;32mFaerie              [0m\n"
        "\t[[0;31m5[0m] - [0;32mGnome               [0m\n"
        "\t[[0;31m6[0m] - [0;32mHalf elf            [0m\n"
        "\t[[0;31m7[0m] - [0;32mHalf orc            [0m\n"
        "\t[[0;31m8[0m] - [0;32mHalf troll          [0m\n"
        "\t[[0;31m9[0m] - [0;32mHalfling            [0m\n"
        "\t[[0;31m10[0m] - [0;32mHigh elf            [0m\n"
        "\t[[0;31m11[0m] - [0;32mHuman               [0m\n"
        "[0;32;1mYou must select a number from 1 to 11.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfDraconidSetsRaceToDraconid()
{
    Selector->initiateSelector(User);
    Selector->applySelection("1");
    ExpectEq("[0;36mYou have selected 'Draconid'.\n[0m", User->caughtMessage());
    ExpectEq("draconid", User->Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfDwarfSetsRaceToDwarf()
{
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    ExpectEq("[0;36mYou have selected 'Dwarf'.\n[0m", User->caughtMessage());
    ExpectEq("dwarf", User->Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfElfSetsRaceToElf()
{
    Selector->initiateSelector(User);
    Selector->applySelection("3");
    ExpectEq("[0;36mYou have selected 'Elf'.\n[0m", User->caughtMessage());
    ExpectEq("elf", User->Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfFaerieSetsRaceToFaerie()
{
    Selector->initiateSelector(User);
    Selector->applySelection("4");
    ExpectEq("[0;36mYou have selected 'Faerie'.\n[0m", User->caughtMessage());
    ExpectEq("faerie", User->Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfGnomeSetsRaceToGnome()
{
    Selector->initiateSelector(User);
    Selector->applySelection("5");
    ExpectEq("[0;36mYou have selected 'Gnome'.\n[0m", User->caughtMessage());
    ExpectEq("gnome", User->Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHalfElfSetsRaceToHalfElf()
{
    Selector->initiateSelector(User);
    Selector->applySelection("6");
    ExpectEq("[0;36mYou have selected 'Half elf'.\n[0m", User->caughtMessage());
    ExpectEq("half elf", User->Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHalfOrcSetsRaceToHalfOrc()
{
    Selector->initiateSelector(User);
    Selector->applySelection("7");
    ExpectEq("[0;36mYou have selected 'Half orc'.\n[0m", User->caughtMessage());
    ExpectEq("half orc", User->Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHalfTrollSetsRaceToHalfTroll()
{
    Selector->initiateSelector(User);
    Selector->applySelection("8");
    ExpectEq("[0;36mYou have selected 'Half troll'.\n[0m", User->caughtMessage());
    ExpectEq("half troll", User->Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHalflingSetsRaceToHalfling()
{
    Selector->initiateSelector(User);
    Selector->applySelection("9");
    ExpectEq("[0;36mYou have selected 'Halfling'.\n[0m", User->caughtMessage());
    ExpectEq("halfling", User->Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHighElfSetsRaceToHighElf()
{
    Selector->initiateSelector(User);
    Selector->applySelection("10");
    ExpectEq("[0;36mYou have selected 'High elf'.\n[0m", User->caughtMessage());
    ExpectEq("high elf", User->Race());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHumanSetsRaceToHuman()
{
    Selector->initiateSelector(User);
    Selector->applySelection("11");
    ExpectEq("[0;36mYou have selected 'Human'.\n[0m", User->caughtMessage());
    ExpectEq("human", User->Race());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeDraconidDisplaysDraconidDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 1");
    ExpectEq("[0;36m\n"
        "The draconid race incurs the following in-game bonuses/penalties:\n"
        "\t[0;32mStarting skill points:[0m [0;34;1m10[0m\n"
        "\t[0;32mBonus to trait selection:[0m [0;34;1m3[0m\n"
        "\t[0;32mStrength    [0m [0;34;1m+1[0m\n"
        "\t[0;32mIntelligence[0m [0;34;1m+1[0m\n"
        "\t[0;32mCharisma    [0m [0;34;1m+1[0m\n"
        "\t[0;32mBonus heal spell points[0m [0;34;1m+2[0m\n"
        "\t[0;32mBonus heal spell points rate[0m [0;34;1m+2[0m\n"
        "\t[0;32mSpell points[0m [0;34;1m+50[0m\n"
        "\t[0;34;1mA special research tree only available to this race is unlocked.[0m\n"
        "[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeDwarfDisplaysDwarfDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 2");
    ExpectEq("[0;36mThe dwarves are a short, stocky race of people. They generally\n"
        "live in hilly or mountainous areas, usually inside caves or\n"
        "similar dwellings. Dwarven craftsmanship is world renowned\n"
        "for it's durability and functionality. Dwarven structures are\n"
        "built to last through war and the elements.\n\n"
        "The dwarf race incurs the following in-game bonuses/penalties:\n"
        "\t[0;32mStarting skill points:[0m [0;34;1m6[0m\n"
        "\t[0;32mBonus to trait selection:[0m [0;34;1m2[0m\n"
        "\t[0;32mStrength    [0m [0;34;1m+1[0m\n"
        "\t[0;32mIntelligence[0m [0;31m-1[0m\n"
        "\t[0;32mWisdom      [0m [0;31m-1[0m\n"
        "\t[0;32mConstitution[0m [0;34;1m+2[0m\n"
        "\t[0;32mCharisma    [0m [0;31m-1[0m\n"
        "\t[0;32mDefense     [0m [0;34;1m+2[0m\n"
        "\t[0;32mHit points  [0m [0;34;1m+10[0m\n"
        "\t[0;32mStamina points[0m [0;34;1m+25[0m\n"
        "\t[0;32mBonus Blacksmithing skill[0m [0;34;1m+4[0m\n"
        "\t[0;32mBonus Hammer skill[0m [0;34;1m+2[0m\n"
        "[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeElfDisplaysElfDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 3");
    ExpectEq("[0;36mIn appearance, elves typically have grey or blue eyes and blond\n"
        "hair. They are fair to look upon and typically stand taller than\n"
        "humans. In all ways, their bearing is majestic and sight of them\n"
        "demands attention. Elves, while they can be slain in battle or by\n"
        "mishap, do not age in the way that most races do - in fact, some\n"
        "consider them 'immortal'. The elves also tend to be aloof and\n"
        "somewhat detached from the outside world, seemingly only interested\n"
        "in their own lives. Elves also favor nature and natural beauty,\n"
        "their buildings and art reflect this.\n\n"
        "The elf race incurs the following in-game bonuses/penalties:\n"
        "\t[0;32mStarting skill points:[0m [0;34;1m6[0m\n"
        "\t[0;32mBonus to trait selection:[0m [0;34;1m1[0m\n"
        "\t[0;32mStrength    [0m [0;34;1m+1[0m\n"
        "\t[0;32mIntelligence[0m [0;34;1m+1[0m\n"
        "\t[0;32mDexterity   [0m [0;34;1m+1[0m\n"
        "\t[0;32mConstitution[0m [0;34;1m+1[0m\n"
        "\t[0;32mCharisma    [0m [0;34;1m+1[0m\n"
        "\t[0;32mBonus heal spell points rate[0m [0;34;1m+2[0m\n"
        "\t[0;32mDefend attack[0m [0;34;1m+1[0m\n"
        "\t[0;32mSpell points[0m [0;34;1m+25[0m\n"
        "[0m",
        User->caughtMessage());
}


/////////////////////////////////////////////////////////////////////////////
void DescribeFaerieDisplaysFaerieDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 4");
    ExpectEq("[0;36mThe faeries are a magical race of winged humanoids. They are\n"
        "smaller than humans, and are generally friendly to all. The\n"
        "faeries enjoy conversation, and enjoy companionship. They\n"
        "tend to have their own personal agendas, that they keep to\n"
        "themselves, faeries like secrets. The faeries tend to reside\n"
        "in forests or prairies, though they hide their existence well.\n\n"
        "The faerie race incurs the following in-game bonuses/penalties:\n"
        "\t[0;32mStarting skill points:[0m [0;34;1m10[0m\n"
        "\t[0;32mBonus to trait selection:[0m [0;34;1m4[0m\n"
        "\t[0;32mStrength    [0m [0;31m-2[0m\n"
        "\t[0;32mIntelligence[0m [0;34;1m+1[0m\n"
        "\t[0;32mDexterity   [0m [0;34;1m+2[0m\n"
        "\t[0;32mConstitution[0m [0;31m-2[0m\n"
        "\t[0;32mCharisma    [0m [0;34;1m+1[0m\n"
        "\t[0;32mBonus heal spell points[0m [0;34;1m+2[0m\n"
        "\t[0;32mBonus heal spell points rate[0m [0;34;1m+4[0m\n"
        "\t[0;32mHit points  [0m [0;31m-50[0m\n"
        "\t[0;32mSpell points[0m [0;34;1m+50[0m\n"
        "[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeGnomeDisplaysGnomeDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 5");
    ExpectEq("[0;36mThe gnomes are an intelligent race of beings closely related\n"
        "to the dwarves. They are short, but less stocky than their\n"
        "dwarven cousins, They tend to have dark skin and light colored\n"
        "hair and are well-known for their rather large noses. The gnomes\n"
        "are a playful race, and they love to play jokes on others.\n"
        "They generally reside in tunnels burrowed into mountains or\n"
        "hills.\n\n"
        "The gnome race incurs the following in-game bonuses/penalties:\n"
        "\t[0;32mStarting skill points:[0m [0;34;1m8[0m\n"
        "\t[0;32mBonus to trait selection:[0m [0;34;1m3[0m\n"
        "\t[0;32mStrength    [0m [0;31m-1[0m\n"
        "\t[0;32mIntelligence[0m [0;34;1m+2[0m\n"
        "\t[0;32mWisdom      [0m [0;31m-1[0m\n"
        "\t[0;32mBonus heal spell points[0m [0;34;1m+2[0m\n"
        "\t[0;32mSpell points[0m [0;34;1m+25[0m\n"
        "[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeHalfElfDisplaysHalfElfDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 6");
    ExpectEq("[0;36m\n"
        "The half elf race incurs the following in-game bonuses/penalties:\n"
        "\t[0;32mStarting skill points:[0m [0;34;1m10[0m\n"
        "\t[0;32mBonus to trait selection:[0m [0;34;1m5[0m\n"
        "\t[0;32mIntelligence[0m [0;34;1m+1[0m\n"
        "\t[0;32mSpell points[0m [0;34;1m+10[0m\n"
        "[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeHalfOrcDisplaysHalfOrcDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 7");
    ExpectEq("[0;36mHalf-orcs are people that have both human and orcish parents.\n"
        "Like most crossbreeds, they are shunned by both of their races,\n"
        "they gain the physical strength of their orcish heritage, along\n"
        "with the incredible stamina of the orcs. From their human side,\n"
        "they gain intelligence and dexterity that the orcs lack.\n\n"
        "The half orc race incurs the following in-game bonuses/penalties:\n"
        "\t[0;32mStarting skill points:[0m [0;34;1m6[0m\n"
        "\t[0;32mBonus to trait selection:[0m [0;34;1m3[0m\n"
        "\t[0;32mStrength    [0m [0;34;1m+2[0m\n"
        "\t[0;32mIntelligence[0m [0;31m-1[0m\n"
        "\t[0;32mConstitution[0m [0;34;1m+1[0m\n"
        "\t[0;32mCharisma    [0m [0;31m-2[0m\n"
        "\t[0;32mSpell points[0m [0;31m-50[0m\n"
        "\t[0;32mStamina points[0m [0;34;1m+50[0m\n"
        "[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeHalfTrollDisplaysHalfTrollDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 8");
    ExpectEq("[0;36mHalf-trolls are people that have both human and troll parents.\n"
        "Half trolls are often seen by other trolls in much the same light as\n"
        "pure-blood trolls - trolls simply don't seem to care if half-trolls\n"
        "have a human parent. Half-trolls generally live with trolls, which\n"
        "is wherever they feel like living.\n\n"
        "The half troll race incurs the following in-game bonuses/penalties:\n"
        "\t[0;32mStarting skill points:[0m [0;34;1m6[0m\n"
        "\t[0;32mBonus to trait selection:[0m [0;34;1m5[0m\n"
        "\t[0;32mStrength    [0m [0;34;1m+5[0m\n"
        "\t[0;32mIntelligence[0m [0;31m-1[0m\n"
        "\t[0;32mWisdom      [0m [0;31m-1[0m\n"
        "\t[0;32mDexterity   [0m [0;31m-1[0m\n"
        "\t[0;32mConstitution[0m [0;34;1m+2[0m\n"
        "\t[0;32mCharisma    [0m [0;31m-2[0m\n"
        "\t[0;32mBonus heal hit points[0m [0;34;1m+2[0m\n"
        "\t[0;32mBonus heal hit points rate[0m [0;34;1m+4[0m\n"
        "\t[0;32mBonus heal spell points rate[0m [0;31m-4[0m\n"
        "\t[0;32mDefense     [0m [0;34;1m+4[0m\n"
        "\t[0;32mHit points  [0m [0;34;1m+50[0m\n"
        "\t[0;32mSpell points[0m [0;31m-75[0m\n"
        "\t[0;32mStamina points[0m [0;34;1m+25[0m\n"
        "[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeHalflingDisplaysHalflingDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 9");
    ExpectEq("[0;36mHalflings are a very small people that tend to look like\n"
        "miniaturized humans.The halflings are a fairly peaceful race:\n"
        "they don't start wars amongst themselves or others, they prefer\n"
        "to spend their time telling stories at gatherings... Halfling\n"
        "families are quite large. Halflings live in above ground homes\n"
        "made from materials in the surrounding forests.\n\n"
        "The halfling race incurs the following in-game bonuses/penalties:\n"
        "\t[0;32mStarting skill points:[0m [0;34;1m6[0m\n"
        "\t[0;32mBonus to trait selection:[0m [0;34;1m5[0m\n"
        "\t[0;32mStrength    [0m [0;31m-1[0m\n"
        "\t[0;32mDexterity   [0m [0;34;1m+2[0m\n"
        "\t[0;32mCharisma    [0m [0;31m-1[0m\n"
        "\t[0;32mBonus heal hit points[0m [0;34;1m+2[0m\n"
        "\t[0;32mBonus heal hit points rate[0m [0;34;1m+2[0m\n"
        "[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeHighElfDisplaysHighElfDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 10");
    ExpectEq("[0;36mIn the crafting of items of wonder, in strength, in keen intelligence,\n"
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
        "\t[0;32mStarting skill points:[0m [0;34;1m6[0m\n"
        "\t[0;32mBonus to trait selection:[0m [0;34;1m2[0m\n"
        "\t[0;32mStrength    [0m [0;34;1m+1[0m\n"
        "\t[0;32mIntelligence[0m [0;34;1m+2[0m\n"
        "\t[0;32mConstitution[0m [0;34;1m+1[0m\n"
        "\t[0;32mCharisma    [0m [0;34;1m+2[0m\n"
        "\t[0;32mBonus heal spell points rate[0m [0;34;1m+2[0m\n"
        "\t[0;32mDefend attack[0m [0;34;1m+1[0m\n"
        "\t[0;32mSpell points[0m [0;34;1m+50[0m\n"
        "\t[0;32mBonus Blacksmithing skill[0m [0;34;1m+3[0m\n"
        "\t[0;32mBonus Bow skill[0m [0;34;1m+3[0m\n"
        "\t[0;32mBonus Long sword skill[0m [0;34;1m+5[0m\n"
        "\t[0;32mBonus Weapon smithing skill[0m [0;34;1m+3[0m\n"
        "\t[0;34;1mA special research tree only available to this race is unlocked.[0m\n"
        "[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeHumanDisplaysHumanDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 11");
    ExpectEq("[0;36mHumans are the most common race on Realmsmud. They don't have any\n"
        "real preferences on where they live, except that they prefer tropical\n"
        "or temperate regions. They live in above ground dwellings, and tend\n"
        "to admire the elaborate, elegant architecture of the elves and dwarves.\n"
        "Humans gain no advantages or disadvantages on Realmsmud, they are the\n"
        "happy medium... and they like it that way.\n\n"
        "The human race incurs the following in-game bonuses/penalties:\n"
        "\t[0;32mBonus to trait selection:[0m [0;34;1m5[0m\n"
        "\t[0;32mBase starting skill points[0m [0;34;1m+10[0m\n"
        "[0m",
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