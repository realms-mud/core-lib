//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;

string EndBar = "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-+-=-=-=-=-=-=-=-=-=-=-=-=-+-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m";
string TraitsRow = "[0;31m| [0m%s%23s[0m [0;31m| [0m%s%23s[0m [0;31m| [0m%s%23s[0m [0;31m|\n[0m";

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->addCommands();
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void CanExecuteTraitsCommand()
{
    ExpectTrue(Player->executeCommand("traits"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpIsNotGreedy()
{
    ExpectFalse(Player->executeCommand("traitseses"));
    ExpectFalse(Player->executeCommand("atrait"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpFailsIfInvalidFlagsPassed()
{
    ExpectFalse(Player->executeCommand("traits -t"));
    ExpectFalse(Player->executeCommand("skills -edu"));
}

/////////////////////////////////////////////////////////////////////////////
void TraitsWithNoneLoadedReturnsNoTraitsMessage()
{
    ExpectTrue(Player->executeCommand("traits"));
    ExpectEq("\n[0;36mYou currently do not have any tracked traits.\n[0m", 
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SectionWithOneTraitCorrectlyPadsEmptyColumns()
{
    Player->addTrait("/lib/tests/support/traits/testPersonalityTrait.c");

    ExpectTrue(Player->executeCommand("traits"));
    ExpectEq("\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Personality Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;31;1m", "Test 1", "", "", "", "") + EndBar,
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SectionWithTwoTraitsCorrectlyPadsEmptyColumn()
{
    Player->addTrait("/lib/tests/support/traits/testPersonalityTrait.c");
    Player->addTrait("/lib/tests/support/traits/testPersonalityTrait2.c");

    ExpectTrue(Player->executeCommand("traits"));
    ExpectEq("\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Personality Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;31;1m", "Test 1", "[0;36m", "Test 2", "", "") + EndBar,
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SectionWithThreeTraitsHasNoEmptyColumns()
{
    Player->addTrait("/lib/tests/support/traits/testPersonalityTrait.c");
    Player->addTrait("/lib/tests/support/traits/testPersonalityTrait2.c");
    Player->addTrait("/lib/modules/traits/personality/abrasive.c");

    ExpectTrue(Player->executeCommand("traits"));
    ExpectEq("\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Personality Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;31;1m", "Abrasive", "[0;31;1m", "Test 1", "[0;36m", "Test 2") + EndBar,
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SectionWithMoreThanThreeTraitsCorrectlyDisplays()
{
    Player->addTrait("/lib/tests/support/traits/testPersonalityTrait.c");
    Player->addTrait("/lib/tests/support/traits/testPersonalityTrait2.c");
    Player->addTrait("/lib/modules/traits/personality/abrasive.c");
    Player->addTrait("/lib/modules/traits/personality/charming.c");

    ExpectTrue(Player->executeCommand("traits"));
    ExpectEq("\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Personality Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;31;1m", "Abrasive", "[0;33m", "Charming", "[0;31;1m", "Test 1") +
        sprintf(TraitsRow, "[0;36m", "Test 2", "", "", "", "") + EndBar,
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PersonalityFlagDisplaysOnlyPersonalityTraits()
{
    Player->addTrait("/lib/tests/support/traits/testPersonalityTrait.c");
    Player->addTrait("/lib/tests/support/traits/testTraitWithDuration.c");

    ExpectTrue(Player->executeCommand("traits -personality"));
    ExpectEq("\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Personality Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;31;1m", "Test 1", "", "", "", "") + EndBar,
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PeFlagDisplaysOnlyPersonalityTraits()
{
    Player->addTrait("/lib/tests/support/traits/testPersonalityTrait.c");
    Player->addTrait("/lib/tests/support/traits/testTraitWithDuration.c");

    ExpectTrue(Player->executeCommand("traits -pe"));
    ExpectEq("\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Personality Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;31;1m", "Test 1", "", "", "", "") + EndBar,
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EducationalFlagDisplaysOnlyEducationalTraits()
{
    Player->addTrait("/lib/tests/support/traits/testPersonalityTrait.c");
    Player->addTrait("/lib/tests/support/traits/testTraitWithResearchNoPrerequisites.c");

    ExpectTrue(Player->executeCommand("traits -educational"));
    ExpectEq("\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Educational Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;32;1m", "Duelist", "", "", "", "") + EndBar,
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EdFlagDisplaysOnlyEducationalTraits()
{
    Player->addTrait("/lib/tests/support/traits/testPersonalityTrait.c");
    Player->addTrait("/lib/tests/support/traits/testTraitWithResearchNoPrerequisites.c");

    ExpectTrue(Player->executeCommand("traits -ed"));
    ExpectEq("\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Educational Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;32;1m", "Duelist", "", "", "", "") + EndBar,
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EffectFlagDisplaysPersistedAndSustainedTraits()
{
    Player->addTrait("/lib/tests/support/traits/testPersonalityTrait.c");
    Player->addTrait("/lib/tests/support/traits/testTraitWithDuration.c");
    Player->addTrait("/lib/tests/support/traits/testTraitForSustainedResearch.c");

    ExpectTrue(Player->executeCommand("traits -effect"));
    ExpectEq("\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Effect Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;35m", "Sustained Jerk", "[0;34;1m", "Temporary Jerk", "", "") + EndBar,
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EfFlagDisplaysPersistedAndSustainedTraits()
{
    Player->addTrait("/lib/tests/support/traits/testPersonalityTrait.c");
    Player->addTrait("/lib/tests/support/traits/testTraitWithDuration.c");
    Player->addTrait("/lib/tests/support/traits/testTraitForSustainedResearch.c");

    ExpectTrue(Player->executeCommand("traits -ef"));
    ExpectEq("\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Effect Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;35m", "Sustained Jerk", "[0;34;1m", "Temporary Jerk", "", "") + EndBar,
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GeneticFlagDisplaysGeneticTraits()
{
    Player->addTrait("/lib/tests/support/traits/testPersonalityTrait.c");
    Player->addTrait("/lib/tests/support/traits/testGeneticTrait.c");

    ExpectTrue(Player->executeCommand("traits -genetic"));
    ExpectEq("\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Genetic Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;36m", "Hunchback", "", "", "", "") + EndBar,
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GeFlagDisplaysGeneticTraits()
{
    Player->addTrait("/lib/tests/support/traits/testPersonalityTrait.c");
    Player->addTrait("/lib/tests/support/traits/testGeneticTrait.c");

    ExpectTrue(Player->executeCommand("traits -ge"));
    ExpectEq("\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Genetic Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;36m", "Hunchback", "", "", "", "") + EndBar,
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GuildFlagDisplaysGuildTraits()
{
    Player->addTrait("/lib/tests/support/traits/testGuildTrait.c");
    Player->addTrait("/lib/tests/support/traits/testGeneticTrait.c");

    ExpectTrue(Player->executeCommand("traits -guild"));
    ExpectEq("\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Guild Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;36m", "Sword Dude", "", "", "", "") + EndBar,
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GFlagDisplaysGuildTraits()
{
    Player->addTrait("/lib/tests/support/traits/testGuildTrait.c");
    Player->addTrait("/lib/tests/support/traits/testGeneticTrait.c");

    ExpectTrue(Player->executeCommand("traits -g"));
    ExpectEq("\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Guild Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;36m", "Sword Dude", "", "", "", "") + EndBar,
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HealthFlagDisplaysHealthTraits()
{
    Player->addTrait("/lib/tests/support/traits/testHealthTrait.c");
    Player->addTrait("/lib/tests/support/traits/testGeneticTrait.c");

    ExpectTrue(Player->executeCommand("traits -health"));
    ExpectEq("\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Health Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;36m", "Leprosy", "", "", "", "") + EndBar,
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HFlagDisplaysHealthTraits()
{
    Player->addTrait("/lib/tests/support/traits/testHealthTrait.c");
    Player->addTrait("/lib/tests/support/traits/testGeneticTrait.c");

    ExpectTrue(Player->executeCommand("traits -h"));
    ExpectEq("\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Health Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;36m", "Leprosy", "", "", "", "") + EndBar,
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ProfessionalFlagDisplaysProfessionalTraits()
{
    Player->addTrait("/lib/tests/support/traits/testHealthTrait.c");
    Player->addTrait("/lib/tests/support/traits/testProfessionalTrait.c");

    ExpectTrue(Player->executeCommand("traits -professional"));
    ExpectEq("\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Professional Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;36m", "Engineer", "", "", "", "") + EndBar,
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PrFlagDisplaysProfessionalTraits()
{
    Player->addTrait("/lib/tests/support/traits/testHealthTrait.c");
    Player->addTrait("/lib/tests/support/traits/testProfessionalTrait.c");

    ExpectTrue(Player->executeCommand("traits -pr"));
    ExpectEq("\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Professional Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;36m", "Engineer", "", "", "", "") + EndBar,
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void RoleFlagDisplaysRoleTraits()
{
    Player->addTrait("/lib/tests/support/traits/testHealthTrait.c");
    Player->addTrait("/lib/tests/support/traits/testProfessionalTrait.c");
    Player->addTrait("/lib/tests/support/traits/testTraitOnlyOpinion.c");

    ExpectTrue(Player->executeCommand("traits -role"));
    ExpectEq("\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Role Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;36m", "Weasel Lord", "", "", "", "") + EndBar,
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void RFlagDisplaysRoleTraits()
{
    Player->addTrait("/lib/tests/support/traits/testHealthTrait.c");
    Player->addTrait("/lib/tests/support/traits/testProfessionalTrait.c");
    Player->addTrait("/lib/tests/support/traits/testTraitOnlyOpinion.c");

    ExpectTrue(Player->executeCommand("traits -r"));
    ExpectEq("\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Role Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;36m", "Weasel Lord", "", "", "", "") + EndBar,
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AllFlagDisplaysAllTraits()
{
    Player->addTrait("/lib/tests/support/traits/testHealthTrait.c");
    Player->addTrait("/lib/tests/support/traits/testProfessionalTrait.c");
    Player->addTrait("/lib/tests/support/traits/testTraitOnlyOpinion.c");
    Player->addTrait("/lib/tests/support/traits/testGuildTrait.c");
    Player->addTrait("/lib/tests/support/traits/testGeneticTrait.c");
    Player->addTrait("/lib/tests/support/traits/testPersonalityTrait.c");
    Player->addTrait("/lib/tests/support/traits/testTraitWithDuration.c");
    Player->addTrait("/lib/tests/support/traits/testTraitForSustainedResearch.c");
    Player->addTrait("/lib/tests/support/traits/testTraitWithResearchNoPrerequisites.c");

    ExpectTrue(Player->executeCommand("traits -all"));
    ExpectEq("\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Educational Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;32;1m", "Duelist", "", "", "", "") +
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Effect Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;35m", "Sustained Jerk", "[0;34;1m", "Temporary Jerk", "", "") + 
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Genetic Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;36m", "Hunchback", "", "", "", "") + 
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Guild Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;36m", "Sword Dude", "", "", "", "") +
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Health Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;36m", "Leprosy", "", "", "", "") + 
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Personality Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;31;1m", "Test 1", "", "", "", "") + 
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Professional Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;36m", "Engineer", "", "", "", "") + 
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Role Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;36m", "Weasel Lord", "", "", "", "") + EndBar,
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AFlagDisplaysAllTraits()
{
    Player->addTrait("/lib/tests/support/traits/testHealthTrait.c");
    Player->addTrait("/lib/tests/support/traits/testProfessionalTrait.c");
    Player->addTrait("/lib/tests/support/traits/testTraitOnlyOpinion.c");
    Player->addTrait("/lib/tests/support/traits/testGuildTrait.c");
    Player->addTrait("/lib/tests/support/traits/testGeneticTrait.c");
    Player->addTrait("/lib/tests/support/traits/testPersonalityTrait.c");
    Player->addTrait("/lib/tests/support/traits/testTraitWithDuration.c");
    Player->addTrait("/lib/tests/support/traits/testTraitForSustainedResearch.c");
    Player->addTrait("/lib/tests/support/traits/testTraitWithResearchNoPrerequisites.c");

    ExpectTrue(Player->executeCommand("traits -a"));
    ExpectEq("\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Educational Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;32;1m", "Duelist", "", "", "", "") +
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Effect Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;35m", "Sustained Jerk", "[0;34;1m", "Temporary Jerk", "", "") +
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Genetic Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;36m", "Hunchback", "", "", "", "") +
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Guild Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;36m", "Sword Dude", "", "", "", "") +
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Health Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;36m", "Leprosy", "", "", "", "") +
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Personality Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;31;1m", "Test 1", "", "", "", "") +
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Professional Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;36m", "Engineer", "", "", "", "") +
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Role Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;36m", "Weasel Lord", "", "", "", "") + EndBar,
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void NoFlagDisplaysAllTraits()
{
    Player->addTrait("/lib/tests/support/traits/testHealthTrait.c");
    Player->addTrait("/lib/tests/support/traits/testProfessionalTrait.c");
    Player->addTrait("/lib/tests/support/traits/testTraitOnlyOpinion.c");
    Player->addTrait("/lib/tests/support/traits/testGuildTrait.c");
    Player->addTrait("/lib/tests/support/traits/testGeneticTrait.c");
    Player->addTrait("/lib/tests/support/traits/testPersonalityTrait.c");
    Player->addTrait("/lib/tests/support/traits/testTraitWithDuration.c");
    Player->addTrait("/lib/tests/support/traits/testTraitForSustainedResearch.c");
    Player->addTrait("/lib/tests/support/traits/testTraitWithResearchNoPrerequisites.c");

    ExpectTrue(Player->executeCommand("traits"));
    ExpectEq("\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Educational Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;32;1m", "Duelist", "", "", "", "") +
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Effect Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;35m", "Sustained Jerk", "[0;34;1m", "Temporary Jerk", "", "") +
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Genetic Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;36m", "Hunchback", "", "", "", "") +
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Guild Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;36m", "Sword Dude", "", "", "", "") +
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Health Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;36m", "Leprosy", "", "", "", "") +
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Personality Traits +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;31;1m", "Test 1", "", "", "", "") +
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Professional Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;36m", "Engineer", "", "", "", "") +
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Role Traits +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(TraitsRow, "[0;36m", "Weasel Lord", "", "", "", "") + EndBar,
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DetailsFlagReturnsTraitDetails()
{
    object trait = load_object("/lib/tests/support/traits/testTrait.c");
    trait->init();

    Player->addTrait("/lib/tests/support/traits/testTrait.c");
    ExpectTrue(Player->executeCommand("traits -details sword boy"));
}

/////////////////////////////////////////////////////////////////////////////
void DFlagReturnsTraitDetails()
{
    object trait = load_object("/lib/tests/support/traits/testTrait.c");
    trait->init();

    Player->addTrait("/lib/tests/support/traits/testTrait.c");
    ExpectTrue(Player->executeCommand("traits -d sword boy"));
}

/////////////////////////////////////////////////////////////////////////////
void TraitDetailsForInvalidTraitReturnsCorrectMessage()
{
    ExpectTrue(Player->executeCommand("traits -d llama king"));
    ExpectEq("Llama king is not a valid trait.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TraitDetailsDisplayTraitInformation()
{
    string message = "[0;36mTrait Name[0m: [0;33mSword Boy[0m\n"
        "[0;36mTrait Type[0m: [0;33mRole[0m\n"
        "[0;33mblah blah blah[0m\n"
        "[0;36mRoot Trait Class[0m: [0;33mJock[0m\n"
        "[0;36mOpposing Trait Class[0m: [0;33mNerd[0m\n"
        "[0;36mOpinion[0m: [0;34;1m+5[0m\n"
        "[0;36mOpposing opinion[0m: [0;31m-5[0m\n"
        "[0;36mCost[0m: [0;34;1m+8[0m\n"
        "[0;34;1m(+15)[0m [0;33mBonus Fire attack[0m\n"
        "[0;34;1m(+1)[0m [0;33mBonus Long sword[0m\n"
        "[0;34;1m(+2)[0m [0;33mBonus Strength[0m\n"
        "[0;34;1m(+1)[0m [0;33mBonus Weapon attack[0m\n";
    object trait = load_object("/lib/tests/support/traits/testTrait.c");
    trait->init();

    Player->addTrait("/lib/tests/support/traits/testTrait.c");
    ExpectTrue(Player->executeCommand("traits -details sword boy"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TraitDetailsDisplayTraitPenalties()
{
    string message = "[0;36mTrait Name[0m: [0;33mSword Boy[0m\n"
        "[0;36mTrait Type[0m: [0;33mRole[0m\n"
        "[0;33mblah blah blah[0m\n"
        "[0;36mRoot Trait Class[0m: [0;33mJock[0m\n"
        "[0;36mOpposing Trait Class[0m: [0;33mNerd[0m\n"
        "[0;36mOpinion[0m: [0;34;1m+5[0m\n"
        "[0;36mOpposing opinion[0m: [0;31m-5[0m\n"
        "[0;36mCost[0m: [0;34;1m+8[0m\n"
        "[0;34;1m(+15)[0m [0;33mBonus Fire attack[0m\n"
        "[0;34;1m(+1)[0m [0;33mBonus Long sword[0m\n"
        "[0;34;1m(+2)[0m [0;33mBonus Strength[0m\n"
        "[0;34;1m(+1)[0m [0;33mBonus Weapon attack[0m\n"
        "[0;31m(-2)[0m [0;33mPenalty to Wisdom[0m\n";
    object trait = load_object("/lib/tests/support/traits/testTrait.c");
    trait->init();

    trait->addSpecification("penalty to wisdom", 2);
    Player->addTrait("/lib/tests/support/traits/testTrait.c");
    ExpectTrue(Player->executeCommand("traits -details sword boy"));
    ExpectEq(message, Player->caughtMessage());
    destruct(trait);
}

/////////////////////////////////////////////////////////////////////////////
void NegativeTraitDetailsDisplayNegativeIdentifier()
{
    Player->addTrait("/lib/modules/traits/personality/abrasive.c");
    ExpectTrue(Player->executeCommand("traits -details abrasive"));
    ExpectTrue(sizeof(regexp(({ Player->caughtMessage() }), "[Negative]")));
}

/////////////////////////////////////////////////////////////////////////////
void TraitDetailsDisplayTraitResearch()
{
    string message = "[0;36mTrait Name[0m: [0;33mSword Boy[0m\n"
        "[0;36mTrait Type[0m: [0;33mRole[0m\n"
        "[0;33mblah blah blah[0m\n"
        "[0;36mRoot Trait Class[0m: [0;33mJock[0m\n"
        "[0;36mOpposing Trait Class[0m: [0;33mNerd[0m\n"
        "[0;36mOpinion[0m: [0;34;1m+5[0m\n"
        "[0;36mOpposing opinion[0m: [0;31m-5[0m\n"
        "[0;36mCost[0m: [0;34;1m+8[0m\n"
        "[0;34;1m(+15)[0m [0;33mBonus Fire attack[0m\n"
        "[0;34;1m(+1)[0m [0;33mBonus Long sword[0m\n"
        "[0;34;1m(+2)[0m [0;33mBonus Strength[0m\n"
        "[0;34;1m(+1)[0m [0;33mBonus Weapon attack[0m\n"
        "[0;34;1mThis trait makes the tree of researchiness research tree available.[0m\n";
    object trait = load_object("/lib/tests/support/traits/testTrait.c");
    trait->init();

    trait->addSpecification("research tree", "/lib/tests/support/research/testResearchTreeNoPrerequisites.c");
    Player->addTrait("/lib/tests/support/traits/testTrait.c");
    ExpectTrue(Player->executeCommand("traits -details sword boy"));
    ExpectEq(message, Player->caughtMessage());
    destruct(trait);
}

/////////////////////////////////////////////////////////////////////////////
void TraitDetailsDisplayTraitPrerequisites()
{
    string message = "[0;36mTrait Name[0m: [0;33mFreak[0m\n"
        "[0;36mTrait Type[0m: [0;33mGenetic[0m\n"
        "[0;33mblah blah blah[0m\n"
        "[0;36mRoot Trait Class[0m: [0;33mDisfigured[0m\n"
        "[0;36mOpposing Trait Class[0m: [0;33mNormal[0m\n"
        "[0;36mPrerequisites:[0m\n"
        "\t[0;36mSkill[0m: [0;35mLong sword of 10[0m\n";
    object trait = load_object("/lib/tests/support/traits/testTraitWithPrerequisites.c");
    trait->init();

    ExpectTrue(Player->executeCommand("traits -details freak"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TraitDetailsDisplayTraitLimiters()
{
    string message = "[0;36mTrait Name[0m: [0;33mSword Boy[0m\n"
        "[0;36mTrait Type[0m: [0;33mRole[0m\n"
        "[0;33mblah blah blah[0m\n"
        "[0;36mRoot Trait Class[0m: [0;33mJock[0m\n"
        "[0;36mOpposing Trait Class[0m: [0;33mNerd[0m\n"
        "[0;36mOpinion[0m: [0;34;1m+5[0m\n"
        "[0;36mOpposing opinion[0m: [0;31m-5[0m\n"
        "[0;36mCost[0m: [0;34;1m+8[0m\n"
        "[0;34;1m(+15)[0m [0;33mBonus Fire attack[0m\n"
        "[0;34;1m(+1)[0m [0;33mBonus Long sword[0m\n"
        "[0;34;1m(+2)[0m [0;33mBonus Strength[0m\n"
        "[0;34;1m(+1)[0m [0;33mBonus Weapon attack[0m\n"
        "[0;36mThis is only applied when opponent race is elf.[0m\n";
    object trait = load_object("/lib/tests/support/traits/testTrait.c");
    trait->init();

    trait->addSpecification("limited by", (["opponent race":"elf"]));
    ExpectTrue(Player->executeCommand("traits -details sword boy"));
    ExpectEq(message, Player->caughtMessage());
    destruct(trait);
}