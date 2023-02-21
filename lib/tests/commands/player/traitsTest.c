//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;

string EndBar = "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m";
string TraitsRow = "\x1b[0;31m|\x1b[0m %s %23s \x1b[0m%s %23s \x1b[0m%s %23s \x1b[0m \x1b[0;31m|\x1b[0m\n";
string TraitsRowOne = "\x1b[0;31m|\x1b[0m %s %23s \x1b[0m%s %23s %s %23s  \x1b[0;31m|\x1b[0m\n";
string TraitsRowTwo = "\x1b[0;31m|\x1b[0m %s %23s \x1b[0m%s %23s \x1b[0m%s %23s  \x1b[0;31m|\x1b[0m\n";

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("bob");
    Player.addCommands();
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void CanExecuteTraitsCommand()
{
    ExpectTrue(Player.executeCommand("traits"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpIsNotGreedy()
{
    ExpectFalse(Player.executeCommand("traitseses"));
    ExpectFalse(Player.executeCommand("atrait"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpFailsIfInvalidFlagsPassed()
{
    ExpectFalse(Player.executeCommand("traits -t"));
    ExpectFalse(Player.executeCommand("skills -edu"));
}

/////////////////////////////////////////////////////////////////////////////
void TraitsWithNoneLoadedReturnsNoTraitsMessage()
{
    ExpectTrue(Player.executeCommand("traits"));
    ExpectEq("\n\x1b[0;36mYou currently do not have any tracked traits.\n\x1b[0m", 
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SectionWithOneTraitCorrectlyPadsEmptyColumns()
{
    Player.addTrait("/lib/tests/support/traits/testPersonalityTrait.c");

    ExpectTrue(Player.executeCommand("traits"));
    ExpectEq("\n\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Personality Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;31;1m", "Test 1", "", "", "", "") + EndBar,
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SectionWithTwoTraitsCorrectlyPadsEmptyColumn()
{
    Player.addTrait("/lib/tests/support/traits/testPersonalityTrait.c");
    Player.addTrait("/lib/tests/support/traits/testPersonalityTrait2.c");

    ExpectTrue(Player.executeCommand("traits"));
    ExpectEq("\n\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Personality Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowTwo, "\x1b[0;31;1m", "Test 1", "\x1b[0;36m", "Test 2", "", "") + EndBar,
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SectionWithThreeTraitsHasNoEmptyColumns()
{
    Player.addTrait("/lib/tests/support/traits/testPersonalityTrait.c");
    Player.addTrait("/lib/tests/support/traits/testPersonalityTrait2.c");
    Player.addTrait("/lib/instances/traits/personality/abrasive.c");

    ExpectTrue(Player.executeCommand("traits"));
    ExpectEq("\n\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Personality Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRow, "\x1b[0;36m", "Abrasive", "\x1b[0;31;1m", "Test 1", "\x1b[0;36m", "Test 2") + EndBar,
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SectionWithMoreThanThreeTraitsCorrectlyDisplays()
{
    Player.addTrait("/lib/tests/support/traits/testPersonalityTrait.c");
    Player.addTrait("/lib/tests/support/traits/testPersonalityTrait2.c");
    Player.addTrait("/lib/instances/traits/personality/abrasive.c");
    Player.addTrait("/lib/instances/traits/personality/charming.c");

    ExpectTrue(Player.executeCommand("traits"));
    ExpectEq("\n\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Personality Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRow, "\x1b[0;36m", "Abrasive", "\x1b[0;36m", "Charming", "\x1b[0;31;1m", "Test 1") +
        sprintf(TraitsRowOne, "\x1b[0;36m", "Test 2", "", "", "", "") + EndBar,
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PersonalityFlagDisplaysOnlyPersonalityTraits()
{
    Player.addTrait("/lib/tests/support/traits/testPersonalityTrait.c");
    Player.addTrait("/lib/tests/support/traits/testTraitWithDuration.c");

    ExpectTrue(Player.executeCommand("traits -personality"));
    ExpectEq("\n\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Personality Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;31;1m", "Test 1", "", "", "", "") + EndBar,
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PeFlagDisplaysOnlyPersonalityTraits()
{
    Player.addTrait("/lib/tests/support/traits/testPersonalityTrait.c");
    Player.addTrait("/lib/tests/support/traits/testTraitWithDuration.c");

    ExpectTrue(Player.executeCommand("traits -pe"));
    ExpectEq("\n\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Personality Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;31;1m", "Test 1", "", "", "", "") + EndBar,
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EducationalFlagDisplaysOnlyEducationalTraits()
{
    Player.addTrait("/lib/tests/support/traits/testPersonalityTrait.c");
    Player.addTrait("/lib/tests/support/traits/testTraitWithResearchNoPrerequisites.c");

    ExpectTrue(Player.executeCommand("traits -educational"));
    ExpectEq("\n\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Educational Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;32;1m", "Duelist", "", "", "", "") + EndBar,
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EdFlagDisplaysOnlyEducationalTraits()
{
    Player.addTrait("/lib/tests/support/traits/testPersonalityTrait.c");
    Player.addTrait("/lib/tests/support/traits/testTraitWithResearchNoPrerequisites.c");

    ExpectTrue(Player.executeCommand("traits -ed"));
    ExpectEq("\n\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Educational Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;32;1m", "Duelist", "", "", "", "") + EndBar,
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EffectFlagDisplaysPersistedAndSustainedTraits()
{
    load_object("/lib/tests/support/research/testSustainedTraitResearch.c");
    Player.addTrait("/lib/tests/support/traits/testPersonalityTrait.c");
    Player.addTrait("/lib/tests/support/traits/testTraitWithDuration.c");
    Player.addTrait("/lib/tests/support/traits/testTraitForSustainedResearch.c");

    ExpectTrue(Player.executeCommand("traits -effect"));
    ExpectEq("\n\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Effect Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowTwo, "\x1b[0;35m", "Sustained Jerk", "\x1b[0;34;1m", "Temporary Jerk", "", "") + EndBar,
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EfFlagDisplaysPersistedAndSustainedTraits()
{
    Player.addTrait("/lib/tests/support/traits/testPersonalityTrait.c");
    Player.addTrait("/lib/tests/support/traits/testTraitWithDuration.c");
    Player.addTrait("/lib/tests/support/traits/testTraitForSustainedResearch.c");

    ExpectTrue(Player.executeCommand("traits -ef"));
    ExpectEq("\n\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Effect Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowTwo, "\x1b[0;35m", "Sustained Jerk", "\x1b[0;34;1m", "Temporary Jerk", "", "") + EndBar,
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GeneticFlagDisplaysGeneticTraits()
{
    Player.addTrait("/lib/tests/support/traits/testPersonalityTrait.c");
    Player.addTrait("/lib/tests/support/traits/testGeneticTrait.c");

    ExpectTrue(Player.executeCommand("traits -genetic"));
    ExpectEq("\n\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Genetic Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;36m", "Hunchback", "", "", "", "") + EndBar,
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GeFlagDisplaysGeneticTraits()
{
    Player.addTrait("/lib/tests/support/traits/testPersonalityTrait.c");
    Player.addTrait("/lib/tests/support/traits/testGeneticTrait.c");

    ExpectTrue(Player.executeCommand("traits -ge"));
    ExpectEq("\n\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Genetic Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;36m", "Hunchback", "", "", "", "") + EndBar,
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GuildFlagDisplaysGuildTraits()
{
    Player.addTrait("/lib/tests/support/traits/testGuildTrait.c");
    Player.addTrait("/lib/tests/support/traits/testGeneticTrait.c");

    ExpectTrue(Player.executeCommand("traits -guild"));
    ExpectEq("\n\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Guild Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;36m", "Sword Dude", "", "", "", "") + EndBar,
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GFlagDisplaysGuildTraits()
{
    Player.addTrait("/lib/tests/support/traits/testGuildTrait.c");
    Player.addTrait("/lib/tests/support/traits/testGeneticTrait.c");

    ExpectTrue(Player.executeCommand("traits -g"));
    ExpectEq("\n\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Guild Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;36m", "Sword Dude", "", "", "", "") + EndBar,
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HealthFlagDisplaysHealthTraits()
{
    Player.addTrait("/lib/tests/support/traits/testHealthTrait.c");
    Player.addTrait("/lib/tests/support/traits/testGeneticTrait.c");

    ExpectTrue(Player.executeCommand("traits -health"));
    ExpectEq("\n\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Health Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;36m", "Leprosy", "", "", "", "") + EndBar,
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HFlagDisplaysHealthTraits()
{
    Player.addTrait("/lib/tests/support/traits/testHealthTrait.c");
    Player.addTrait("/lib/tests/support/traits/testGeneticTrait.c");

    ExpectTrue(Player.executeCommand("traits -h"));
    ExpectEq("\n\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Health Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;36m", "Leprosy", "", "", "", "") + EndBar,
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ProfessionalFlagDisplaysProfessionalTraits()
{
    Player.addTrait("/lib/tests/support/traits/testHealthTrait.c");
    Player.addTrait("/lib/tests/support/traits/testProfessionalTrait.c");

    ExpectTrue(Player.executeCommand("traits -professional"));
    ExpectEq("\n\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Professional Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;36m", "Engineer", "", "", "", "") + EndBar,
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PrFlagDisplaysProfessionalTraits()
{
    Player.addTrait("/lib/tests/support/traits/testHealthTrait.c");
    Player.addTrait("/lib/tests/support/traits/testProfessionalTrait.c");

    ExpectTrue(Player.executeCommand("traits -pr"));
    ExpectEq("\n\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Professional Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;36m", "Engineer", "", "", "", "") + EndBar,
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void RoleFlagDisplaysRoleTraits()
{
    Player.addTrait("/lib/tests/support/traits/testHealthTrait.c");
    Player.addTrait("/lib/tests/support/traits/testProfessionalTrait.c");
    Player.addTrait("/lib/tests/support/traits/testTraitOnlyOpinion.c");

    ExpectTrue(Player.executeCommand("traits -role"));
    ExpectEq("\n\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Role Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;36m", "Weasel Lord", "", "", "", "") + EndBar,
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void RFlagDisplaysRoleTraits()
{
    Player.addTrait("/lib/tests/support/traits/testHealthTrait.c");
    Player.addTrait("/lib/tests/support/traits/testProfessionalTrait.c");
    Player.addTrait("/lib/tests/support/traits/testTraitOnlyOpinion.c");

    ExpectTrue(Player.executeCommand("traits -ro"));
    ExpectEq("\n\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Role Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;36m", "Weasel Lord", "", "", "", "") + EndBar,
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void RacialFlagDisplaysRacialTraits()
{
    Player.addTrait("/lib/instances/traits/racial/hillgarathElf.c");

    ExpectTrue(Player.executeCommand("traits -racial"));
    ExpectEq("\n\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Racial Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;36m", "Hillgarathi Elf", "", "", "", "") + EndBar,
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void RaFlagDisplaysRaTraits()
{
    Player.addTrait("/lib/instances/traits/racial/hillgarathElf.c");

    ExpectTrue(Player.executeCommand("traits -ra"));
    ExpectEq("\n\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Racial Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;36m", "Hillgarathi Elf", "", "", "", "") + EndBar,
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AllFlagDisplaysAllTraits()
{
    Player.addTrait("/lib/tests/support/traits/testHealthTrait.c");
    Player.addTrait("/lib/tests/support/traits/testProfessionalTrait.c");
    Player.addTrait("/lib/tests/support/traits/testTraitOnlyOpinion.c");
    Player.addTrait("/lib/tests/support/traits/testGuildTrait.c");
    Player.addTrait("/lib/tests/support/traits/testGeneticTrait.c");
    Player.addTrait("/lib/tests/support/traits/testPersonalityTrait.c");
    Player.addTrait("/lib/tests/support/traits/testTraitWithDuration.c");
    Player.addTrait("/lib/tests/support/traits/testTraitForSustainedResearch.c");
    Player.addTrait("/lib/tests/support/traits/testTraitWithResearchNoPrerequisites.c");

    ExpectTrue(Player.executeCommand("traits -all"));
    ExpectEq("\n\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Educational Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;32;1m", "Duelist", "", "", "", "") +
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Effect Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowTwo, "\x1b[0;35m", "Sustained Jerk", "\x1b[0;34;1m", "Temporary Jerk", "", "") + 
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Genetic Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;36m", "Hunchback", "", "", "", "") +
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Guild Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;36m", "Sword Dude", "", "", "", "") +
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Health Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;36m", "Leprosy", "", "", "", "") +
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Personality Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;31;1m", "Test 1", "", "", "", "") +
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Professional Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;36m", "Engineer", "", "", "", "") +
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Role Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;36m", "Weasel Lord", "", "", "", "") + EndBar,
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AFlagDisplaysAllTraits()
{
    Player.addTrait("/lib/tests/support/traits/testHealthTrait.c");
    Player.addTrait("/lib/tests/support/traits/testProfessionalTrait.c");
    Player.addTrait("/lib/tests/support/traits/testTraitOnlyOpinion.c");
    Player.addTrait("/lib/tests/support/traits/testGuildTrait.c");
    Player.addTrait("/lib/tests/support/traits/testGeneticTrait.c");
    Player.addTrait("/lib/tests/support/traits/testPersonalityTrait.c");
    Player.addTrait("/lib/tests/support/traits/testTraitWithDuration.c");
    Player.addTrait("/lib/tests/support/traits/testTraitForSustainedResearch.c");
    Player.addTrait("/lib/tests/support/traits/testTraitWithResearchNoPrerequisites.c");

    ExpectTrue(Player.executeCommand("traits -a"));
    ExpectEq("\n\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Educational Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;32;1m", "Duelist", "", "", "", "") +
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Effect Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowTwo, "\x1b[0;35m", "Sustained Jerk", "\x1b[0;34;1m", "Temporary Jerk", "", "") +
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Genetic Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;36m", "Hunchback", "", "", "", "") +
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Guild Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;36m", "Sword Dude", "", "", "", "") +
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Health Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;36m", "Leprosy", "", "", "", "") +
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Personality Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;31;1m", "Test 1", "", "", "", "") +
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Professional Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;36m", "Engineer", "", "", "", "") +
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Role Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;36m", "Weasel Lord", "", "", "", "") + EndBar,
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void NoFlagDisplaysAllTraits()
{
    Player.addTrait("/lib/tests/support/traits/testHealthTrait.c");
    Player.addTrait("/lib/tests/support/traits/testProfessionalTrait.c");
    Player.addTrait("/lib/tests/support/traits/testTraitOnlyOpinion.c");
    Player.addTrait("/lib/tests/support/traits/testGuildTrait.c");
    Player.addTrait("/lib/tests/support/traits/testGeneticTrait.c");
    Player.addTrait("/lib/tests/support/traits/testPersonalityTrait.c");
    Player.addTrait("/lib/tests/support/traits/testTraitWithDuration.c");
    Player.addTrait("/lib/tests/support/traits/testTraitForSustainedResearch.c");
    Player.addTrait("/lib/tests/support/traits/testTraitWithResearchNoPrerequisites.c");

    ExpectTrue(Player.executeCommand("traits"));
    ExpectEq("\n\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Educational Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;32;1m", "Duelist", "", "", "", "") +
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Effect Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowTwo, "\x1b[0;35m", "Sustained Jerk", "\x1b[0;34;1m", "Temporary Jerk", "", "") +
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Genetic Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;36m", "Hunchback", "", "", "", "") +
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Guild Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;36m", "Sword Dude", "", "", "", "") +
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Health Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;36m", "Leprosy", "", "", "", "") +
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Personality Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;31;1m", "Test 1", "", "", "", "") +
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Professional Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;36m", "Engineer", "", "", "", "") +
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Role Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m" +
        sprintf(TraitsRowOne, "\x1b[0;36m", "Weasel Lord", "", "", "", "") + EndBar,
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DetailsFlagReturnsTraitDetails()
{
    object trait = load_object("/lib/tests/support/traits/testTrait.c");
    trait.create();

    Player.addTrait("/lib/tests/support/traits/testTrait.c");
    ExpectTrue(Player.executeCommand("traits -details sword boy"));
}

/////////////////////////////////////////////////////////////////////////////
void DFlagReturnsTraitDetails()
{
    object trait = load_object("/lib/tests/support/traits/testTrait.c");
    trait.create();

    Player.addTrait("/lib/tests/support/traits/testTrait.c");
    ExpectTrue(Player.executeCommand("traits -d sword boy"));
}

/////////////////////////////////////////////////////////////////////////////
void TraitDetailsForInvalidTraitReturnsCorrectMessage()
{
    ExpectTrue(Player.executeCommand("traits -d llama king"));
    ExpectEq("Llama king is not a valid trait.\n",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TraitDetailsDisplayTraitInformation()
{
    string message = "\x1b[0;36mTrait Name: \x1b[0m\x1b[0;33mSword Boy\x1b[0m\n"
        "\x1b[0;36mTrait Type: \x1b[0m\x1b[0;33mRole\x1b[0m\n"
        "\x1b[0;33mblah blah blah\n\x1b[0m\n"
        "\x1b[0;36mRoot Trait Class: \x1b[0m\x1b[0;33mJock\x1b[0m\n"
        "\x1b[0;36mOpposing Trait Class: \x1b[0m\x1b[0;33mNerd\x1b[0m\n"
        "\x1b[0;36mOpinion: \x1b[0m\x1b[0;34;1m+5\n"
        "\x1b[0m\x1b[0;36mOpposing opinion: \x1b[0m\x1b[0;31m-5\n"
        "\x1b[0m\x1b[0;36mCost: \x1b[0m\x1b[0;34;1m+8\n"
        "\x1b[0m\x1b[0;34;1m(+15)\x1b[0m\x1b[0;33m Bonus Fire attack\n"
        "\x1b[0m\x1b[0;34;1m(+1)\x1b[0m\x1b[0;33m Bonus Long sword\n"
        "\x1b[0m\x1b[0;34;1m(+10)\x1b[0m\x1b[0;33m Bonus Resist fire\n"
        "\x1b[0m\x1b[0;34;1m(+2)\x1b[0m\x1b[0;33m Bonus Strength\n"
        "\x1b[0m\x1b[0;34;1m(+1)\x1b[0m\x1b[0;33m Bonus Weapon attack\n\x1b[0m";
    object trait = load_object("/lib/tests/support/traits/testTrait.c");
    trait.create();

    Player.addTrait("/lib/tests/support/traits/testTrait.c");
    ExpectTrue(Player.executeCommand("traits -details sword boy"));
    ExpectEq(message, Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TraitDetailsDisplayTraitPenalties()
{
    string message = "\x1b[0;36mTrait Name: \x1b[0m\x1b[0;33mSword Boy\x1b[0m\n"
        "\x1b[0;36mTrait Type: \x1b[0m\x1b[0;33mRole\x1b[0m\n"
        "\x1b[0;33mblah blah blah\n\x1b[0m\n"
        "\x1b[0;36mRoot Trait Class: \x1b[0m\x1b[0;33mJock\x1b[0m\n"
        "\x1b[0;36mOpposing Trait Class: \x1b[0m\x1b[0;33mNerd\x1b[0m\n"
        "\x1b[0;36mOpinion: \x1b[0m\x1b[0;34;1m+5\n"
        "\x1b[0m\x1b[0;36mOpposing opinion: \x1b[0m\x1b[0;31m-5\n"
        "\x1b[0m\x1b[0;36mCost: \x1b[0m\x1b[0;34;1m+8\n"
        "\x1b[0m\x1b[0;34;1m(+15)\x1b[0m\x1b[0;33m Bonus Fire attack\n"
        "\x1b[0m\x1b[0;34;1m(+1)\x1b[0m\x1b[0;33m Bonus Long sword\n"
        "\x1b[0m\x1b[0;34;1m(+10)\x1b[0m\x1b[0;33m Bonus Resist fire\n"
        "\x1b[0m\x1b[0;34;1m(+2)\x1b[0m\x1b[0;33m Bonus Strength\n"
        "\x1b[0m\x1b[0;34;1m(+1)\x1b[0m\x1b[0;33m Bonus Weapon attack\n"
        "\x1b[0m\x1b[0;31m(-2)\x1b[0m\x1b[0;33m Penalty to Wisdom\n\x1b[0m";
    object trait = load_object("/lib/tests/support/traits/testTrait.c");
    trait.create();

    trait.addSpecification("penalty to wisdom", 2);
    Player.addTrait("/lib/tests/support/traits/testTrait.c");
    ExpectTrue(Player.executeCommand("traits -details sword boy"));
    ExpectEq(message, Player.caughtMessage());
    destruct(trait);
}

/////////////////////////////////////////////////////////////////////////////
void NegativeTraitDetailsDisplayNegativeIdentifier()
{
    Player.addTrait("/lib/instances/traits/personality/abrasive.c");
    ExpectTrue(Player.executeCommand("traits -details abrasive"));
    ExpectTrue(sizeof(regexp(({ Player.caughtMessage() }), "[Negative]")));
}

/////////////////////////////////////////////////////////////////////////////
void TraitDetailsDisplayTraitResearch()
{
    string message = "\x1b[0;36mTrait Name: \x1b[0m\x1b[0;33mSword Boy\x1b[0m\n"
        "\x1b[0;36mTrait Type: \x1b[0m\x1b[0;33mRole\x1b[0m\n"
        "\x1b[0;33mblah blah blah\n\x1b[0m\n"
        "\x1b[0;36mRoot Trait Class: \x1b[0m\x1b[0;33mJock\x1b[0m\n"
        "\x1b[0;36mOpposing Trait Class: \x1b[0m\x1b[0;33mNerd\x1b[0m\n"
        "\x1b[0;36mOpinion: \x1b[0m\x1b[0;34;1m+5\n"
        "\x1b[0m\x1b[0;36mOpposing opinion: \x1b[0m\x1b[0;31m-5\n"
        "\x1b[0m\x1b[0;36mCost: \x1b[0m\x1b[0;34;1m+8\n"
        "\x1b[0m\x1b[0;34;1m(+15)\x1b[0m\x1b[0;33m Bonus Fire attack\n"
        "\x1b[0m\x1b[0;34;1m(+1)\x1b[0m\x1b[0;33m Bonus Long sword\n"
        "\x1b[0m\x1b[0;34;1m(+10)\x1b[0m\x1b[0;33m Bonus Resist fire\n"
        "\x1b[0m\x1b[0;34;1m(+2)\x1b[0m\x1b[0;33m Bonus Strength\n"
        "\x1b[0m\x1b[0;34;1m(+1)\x1b[0m\x1b[0;33m Bonus Weapon attack\n\x1b[0m"
        "\x1b[0;34;1mThis trait makes the tree of researchiness research tree available.\n\x1b[0m";
    object trait = load_object("/lib/tests/support/traits/testTrait.c");
    trait.create();

    trait.addSpecification("research tree", "/lib/tests/support/research/testResearchTreeNoPrerequisites.c");
    Player.addTrait("/lib/tests/support/traits/testTrait.c");
    ExpectTrue(Player.executeCommand("traits -details sword boy"));
    ExpectEq(message, Player.caughtMessage());
    destruct(trait);
}

/////////////////////////////////////////////////////////////////////////////
void TraitDetailsDisplayTraitPrerequisites()
{
    string message = "\x1b[0;36mTrait Name: \x1b[0m\x1b[0;33mFreak\x1b[0m\n"
        "\x1b[0;36mTrait Type: \x1b[0m\x1b[0;33mGenetic\x1b[0m\n"
        "\x1b[0;33mblah blah blah\n\x1b[0m\n"
        "\x1b[0;36mRoot Trait Class: \x1b[0m\x1b[0;33mDisfigured\x1b[0m\n"
        "\x1b[0;36mOpposing Trait Class: \x1b[0m\x1b[0;33mNormal\x1b[0m\n"
        "\x1b[0;36mPrerequisites:\n\x1b[0m"
        "\x1b[0;33m          Skill: \x1b[0m\x1b[0;35mLong sword of 10\n\x1b[0m";
    object trait = load_object("/lib/tests/support/traits/testTraitWithPrerequisites.c");
    trait.create();

    ExpectTrue(Player.executeCommand("traits -details freak"));
    ExpectEq(message, Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TraitDetailsDisplayTraitLimiters()
{
    string message = "\x1b[0;36mTrait Name: \x1b[0m\x1b[0;33mSword Boy\x1b[0m\n"
        "\x1b[0;36mTrait Type: \x1b[0m\x1b[0;33mRole\x1b[0m\n"
        "\x1b[0;33mblah blah blah\n\x1b[0m\n"
        "\x1b[0;36mRoot Trait Class: \x1b[0m\x1b[0;33mJock\x1b[0m\n"
        "\x1b[0;36mOpposing Trait Class: \x1b[0m\x1b[0;33mNerd\x1b[0m\n"
        "\x1b[0;36mOpinion: \x1b[0m\x1b[0;34;1m+5\n"
        "\x1b[0m\x1b[0;36mOpposing opinion: \x1b[0m\x1b[0;31m-5\n"
        "\x1b[0m\x1b[0;36mCost: \x1b[0m\x1b[0;34;1m+8\n"
        "\x1b[0m\x1b[0;34;1m(+15)\x1b[0m\x1b[0;33m Bonus Fire attack\n"
        "\x1b[0m\x1b[0;34;1m(+1)\x1b[0m\x1b[0;33m Bonus Long sword\n"
        "\x1b[0m\x1b[0;34;1m(+10)\x1b[0m\x1b[0;33m Bonus Resist fire\n"
        "\x1b[0m\x1b[0;34;1m(+2)\x1b[0m\x1b[0;33m Bonus Strength\n"
        "\x1b[0m\x1b[0;34;1m(+1)\x1b[0m\x1b[0;33m Bonus Weapon attack\n\x1b[0m"
        "\x1b[0;36mThis is only applied when the opponent race is elf.\n\x1b[0m";
    object trait = load_object("/lib/tests/support/traits/testTrait.c");
    trait.create();

    trait.addSpecification("limited by", (["opponent race":"elf"]));
    ExpectTrue(Player.executeCommand("traits -details sword boy"));
    ExpectEq(message, Player.caughtMessage());
    destruct(trait);
}
