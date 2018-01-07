//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Attributes;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Attributes = clone_object("/lib/realizations/player");
    Attributes->Name("Bob");
    Attributes->hitPoints(500);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Attributes);
}

/////////////////////////////////////////////////////////////////////////////
void NameReturnsCorrectValue()
{
    ExpectEq("Bob", Attributes->Name("Bob"));
    ExpectEq("Bob", Attributes->Name());
}

/////////////////////////////////////////////////////////////////////////////
void NameIsSomeMistWhenDead()
{
    ExpectEq("Bob", Attributes->Name("Bob"));
    ExpectEq("Bob", Attributes->Name());
    ExpectTrue(Attributes->Ghost(1));
    ExpectEq("some mist", Attributes->Name());
}

/////////////////////////////////////////////////////////////////////////////
void RealNameIsAlwaysName()
{
    ExpectEq("Bob", Attributes->Name("Bob"));
    ExpectEq("Bob", Attributes->RealName());
    ExpectTrue(Attributes->Ghost(1));
    ExpectEq("Bob", Attributes->RealName());
}

/////////////////////////////////////////////////////////////////////////////
void MaleGenderCanBeSet()
{
    ExpectEq(1, Attributes->Gender(1));
}

/////////////////////////////////////////////////////////////////////////////
void FemaleGenderCanBeSet()
{
    ExpectEq(2, Attributes->Gender(2));
}

/////////////////////////////////////////////////////////////////////////////
void NeuterGenderCanBeSet()
{
    ExpectEq(0, Attributes->Gender(0));
}

/////////////////////////////////////////////////////////////////////////////
void OtherGendersCannotBeSet()
{
    string err = catch(ExpectFalse(Attributes->Gender(-2)));
    ExpectEq("*materialAttributes: gender can only be set to 0, 1, or 2.\n", err);
}

/////////////////////////////////////////////////////////////////////////////
void MaleGenderDescIsMale()
{
    ExpectEq(1, Attributes->Gender(1));
    ExpectEq("male", Attributes->GenderDesc());
}

/////////////////////////////////////////////////////////////////////////////
void FemaleGenderDescIsFemale()
{
    ExpectEq(2, Attributes->Gender(2));
    ExpectEq("female", Attributes->GenderDesc());
}

/////////////////////////////////////////////////////////////////////////////
void NeuterGenderDescIsNeuter()
{
    ExpectEq(0, Attributes->Gender(0));
    ExpectEq("neuter", Attributes->GenderDesc());
}

/////////////////////////////////////////////////////////////////////////////
void MalePronounIsMale()
{
    ExpectEq(1, Attributes->Gender(1));
    ExpectEq("he", Attributes->Pronoun());
}

/////////////////////////////////////////////////////////////////////////////
void FemalePronounIsFemale()
{
    ExpectEq(2, Attributes->Gender(2));
    ExpectEq("she", Attributes->Pronoun());
}

/////////////////////////////////////////////////////////////////////////////
void NeuterPronounIsNeuter()
{
    ExpectEq(0, Attributes->Gender(0));
    ExpectEq("it", Attributes->Pronoun());
}

/////////////////////////////////////////////////////////////////////////////
void MaleObjectiveIsMale()
{
    ExpectEq(1, Attributes->Gender(1));
    ExpectEq("him", Attributes->Objective());
}

/////////////////////////////////////////////////////////////////////////////
void FemaleObjectiveIsFemale()
{
    ExpectEq(2, Attributes->Gender(2));
    ExpectEq("her", Attributes->Objective());
}

/////////////////////////////////////////////////////////////////////////////
void NeuterObjectiveIsNeuter()
{
    ExpectEq(0, Attributes->Gender(0));
    ExpectEq("it", Attributes->Objective());
}

/////////////////////////////////////////////////////////////////////////////
void MalePossessiveIsMale()
{
    ExpectEq(1, Attributes->Gender(1));
    ExpectEq("his", Attributes->Possessive());
}

/////////////////////////////////////////////////////////////////////////////
void FemalePossessiveIsFemale()
{
    ExpectEq(2, Attributes->Gender(2));
    ExpectEq("her", Attributes->Possessive());
}

/////////////////////////////////////////////////////////////////////////////
void NeuterPossessiveIsNeuter()
{
    ExpectEq(0, Attributes->Gender(0));
    ExpectEq("its", Attributes->Possessive());
}

/////////////////////////////////////////////////////////////////////////////
void MaleReflexiveIsMale()
{
    ExpectEq(1, Attributes->Gender(1));
    ExpectEq("himself", Attributes->Reflexive());
}

/////////////////////////////////////////////////////////////////////////////
void FemaleReflexiveIsFemale()
{
    ExpectEq(2, Attributes->Gender(2));
    ExpectEq("herself", Attributes->Reflexive());
}

/////////////////////////////////////////////////////////////////////////////
void NeuterReflexiveIsNeuter()
{
    ExpectEq(0, Attributes->Gender(0));
    ExpectEq("itself", Attributes->Reflexive());
}

/////////////////////////////////////////////////////////////////////////////
void InvisibilityTogglesCorrectly()
{
    ExpectEq(0, Attributes->Invisibility(), "invisibility is 0");
    ExpectEq(1, Attributes->Invisibility(1), "invisibility is toggled on");
    ExpectEq(1, Attributes->Invisibility(), "invisibility is 1");
    ExpectEq(0, Attributes->Invisibility(1), "invisibility is toggled off");
}

/////////////////////////////////////////////////////////////////////////////
void GhostTogglesCorrectly()
{
    ExpectEq(0, Attributes->Ghost(), "Ghost is 0");
    ExpectEq(1, Attributes->Ghost(1), "Ghost is toggled on");
    ExpectEq(1, Attributes->Ghost(), "Ghost is 1");
    ExpectEq(0, Attributes->Ghost(1), "Ghost is toggled off");
}

/////////////////////////////////////////////////////////////////////////////
void MessageInCanBeSetAndReturnsCorrectValue()
{
    ExpectEq("arrives", Attributes->MessageIn(), "MessageIn is 'arrives' by default");
    ExpectEq("lumbers in", Attributes->MessageIn("lumbers in"), "MessageIn is set");
    ExpectEq("lumbers in", Attributes->MessageIn(), "MessageIn is 'lumbers in'");
}

/////////////////////////////////////////////////////////////////////////////
void MessageOutCanBeSetAndReturnsCorrectValue()
{
    ExpectEq("leaves", Attributes->MessageOut(), "MessageOut is 'leaves' by default");
    ExpectEq("lumbers out", Attributes->MessageOut("lumbers out"), "MessageOut is set");
    ExpectEq("lumbers out", Attributes->MessageOut(), "MessageOut is 'lumbers out'");
}

/////////////////////////////////////////////////////////////////////////////
void MagicalMessageInCanBeSetAndReturnsCorrectValue()
{
    ExpectEq("appears in a puff of smoke", Attributes->MagicalMessageIn(), "MagicalMessageIn is 'appears in a puff of smoke' by default");
    ExpectEq("blargs magically", Attributes->MagicalMessageIn("blargs magically"), "MagicalMessageIn is set");
    ExpectEq("blargs magically", Attributes->MagicalMessageIn(), "MagicalMessageIn is 'blargs magically'");
}

/////////////////////////////////////////////////////////////////////////////
void MagicalMessageOutCanBeSetAndReturnsCorrectValue()
{
    ExpectEq("vanishes in a puff of smoke", Attributes->MagicalMessageOut(), "MagicalMessageOut is 'vanishes in a puff of smoke' by default");
    ExpectEq("deblargifies", Attributes->MagicalMessageOut("deblargifies"), "MagicalMessageOut is set");
    ExpectEq("deblargifies", Attributes->MagicalMessageOut(), "MagicalMessageOut is 'deblargifies'");
}

/////////////////////////////////////////////////////////////////////////////
void MessageHomeCanBeSetAndReturnsCorrectValue()
{
    ExpectEq("goes home", Attributes->MessageHome(), "MessageHome is 'goes home' by default");
    ExpectEq("whooshes away", Attributes->MessageHome("whooshes away"), "MessageHome is set");
    ExpectEq("whooshes away", Attributes->MessageHome(), "MessageHome is 'whooshes away'");
}

/////////////////////////////////////////////////////////////////////////////
void MessageCloneCanBeSetAndReturnsCorrectValue()
{
    ExpectEq("creates something", Attributes->MessageClone(), "MessageClone is 'creates something' by default");
    ExpectEq("does stuff", Attributes->MessageClone("does stuff"), "MessageClone is set");
    ExpectEq("does stuff", Attributes->MessageClone(), "MessageClone is 'does stuff'");
}

/////////////////////////////////////////////////////////////////////////////
void TitleCanBeSetAndReturnsCorrectValue()
{
    ExpectEq("the title-less", Attributes->Title(), "Title is 'the title-less' by default");
    ExpectEq("is neat", Attributes->Title("is neat"), "Title is set");
    ExpectEq("is neat", Attributes->Title(), "Title is 'is neat'");
}

/////////////////////////////////////////////////////////////////////////////
void PretitleCanBeSetAndReturnsCorrectValue()
{
    ExpectEq(0, Attributes->Pretitle(), "Pretitle is nothing by default");
    ExpectEq("blah", Attributes->Pretitle("blah"), "Pretitle is set");
    ExpectEq("blah", Attributes->Pretitle(), "Pretitle is 'blah'");
}

/////////////////////////////////////////////////////////////////////////////
void ShortCanBeSetAndReturnsCorrectValue()
{
    Attributes->Name("Bob");
    ExpectEq("Bob", Attributes->short(), "short is name by default");
    ExpectEq("blah", Attributes->short("blah"), "short is set");
    ExpectEq("blah", Attributes->short(), "short is 'blah'");
}

/////////////////////////////////////////////////////////////////////////////
void ShortIsEmptyStringWhenInvisible()
{
    Attributes->Name("Bob");
    Attributes->Invisibility(1);
    ExpectEq("", Attributes->short(), "short is empty");
}

/////////////////////////////////////////////////////////////////////////////
void ShortIsGhostOfWhenDead()
{
    Attributes->Name("Bob");
    Attributes->Ghost(1);
    ExpectEq("ghost of Bob", Attributes->short(), "short is a ghost");
}

/////////////////////////////////////////////////////////////////////////////
void DescriptionCanBeSetAndReturnsCorrectValue()
{
    ExpectEq("", Attributes->description(), "description is empty by default");
    ExpectEq("blah", Attributes->description("blah"), "description is set");
    ExpectEq("blah", Attributes->description(), "description is 'blah'");
}

/////////////////////////////////////////////////////////////////////////////
void MaterialAttributeLongDataReturnedByLong()
{
    Attributes->Name("Tantor");
    Attributes->Gender(1);
    ExpectEq("Tantor the title-less (male)\nHe is in good shape.\n", Attributes->long());
}

/////////////////////////////////////////////////////////////////////////////
void LongReturnsTitle()
{
    Attributes->Name("Tantor");
    Attributes->Gender(1);
    Attributes->Title("the Unclean");
    ExpectEq("Tantor the Unclean (male)\nHe is in good shape.\n", Attributes->long());
}

/////////////////////////////////////////////////////////////////////////////
void LongReturnsRace()
{
    Attributes->Name("Tantor");
    Attributes->Gender(1);
    Attributes->Race("elf");
    Attributes->hitPoints(200);
    ExpectEq("Tantor the title-less (male) (elf)\nHe is in good shape.\n", Attributes->long());
}

/////////////////////////////////////////////////////////////////////////////
void LongReturnsDescription()
{
    Attributes->Name("Tantor");
    Attributes->Gender(1);
    Attributes->Race("elf");
    Attributes->hitPoints(200);
    Attributes->description("This is a description.");
    ExpectEq("Tantor the title-less (male) (elf)\nThis is a description.\nHe is in good shape.\n", 
        Attributes->long());
}

/////////////////////////////////////////////////////////////////////////////
void LongReturnsInventoryBasedUserDescriptions()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("short", "A Sword");
    weapon->set("user description", "##UserName## has a shiny blah!");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Attributes);
    ExpectTrue(weapon->equip("blah"));

    Attributes->Name("Tantor");
    Attributes->Gender(1);

    string expected = "Tantor the title-less (male)\nHe is in good shape.\nTantor has a shiny blah!\n\tCarrying:\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n[0m[0;31m| [0m[0;36mPrimary Weapon:\t[0m[0;37;1mA Sword[0m\n[0;31m| [0m[0;36mEquipped Offhand:\t[0m[0;30;1mnothing[0m\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n[0m[0;31m| [0m[0;36mWorn Armor:\t\t[0m[0;30;1mnothing[0m\n[0;31m| [0m[0;36mWorn Helmet:\t\t[0m[0;30;1mnothing[0m\n[0;31m| [0m[0;36mWorn Gloves:\t\t[0m[0;30;1mnothing[0m\n[0;31m| [0m[0;36mWorn Boots:\t\t[0m[0;30;1mnothing[0m\n[0;31m| [0m[0;36mWorn Cloak:\t\t[0m[0;30;1mnothing[0m\n[0;31m| [0m[0;36mWorn Amulet:\t\t[0m[0;30;1mnothing[0m\n[0;31m| [0m[0;36mWorn Belt:\t\t[0m[0;30;1mnothing[0m\n[0;31m| [0m[0;36mWorn Arm Greaves:\t[0m[0;30;1mnothing[0m\n[0;31m| [0m[0;36mWorn Leg Greaves:\t[0m[0;30;1mnothing[0m\n[0;31m| [0m[0;36mWorn Bracers:\t\t[0m[0;30;1mnothing[0m\n[0;31m| [0m[0;36mWorn First Ring:\t[0m[0;30;1mnothing[0m\n[0;31m| [0m[0;36mWorn Second Ring:\t[0m[0;30;1mnothing[0m\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n[0m";
    ExpectEq(expected, Attributes->long());
}

/////////////////////////////////////////////////////////////////////////////
void LongReturnsInventoryWithDetails()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("short", "A Sword");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Attributes);

    Attributes->Name("Tantor");
    Attributes->Gender(1);
    ExpectEq("Tantor the title-less (male)\nHe is in good shape.\n\tCarrying:\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n[0m[0;31m| [0m[0;37;1mA Sword[0m\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n[0m",
        Attributes->long());
}

/////////////////////////////////////////////////////////////////////////////
void LongReturnsWizardInformation()
{
    destruct(Attributes);
    Attributes = clone_object("/lib/tests/support/services/mockWizard.c");
    Attributes->Name("Tantor");
    Attributes->Gender(1);
    ExpectSubStringMatch("Player", Attributes->long());
}

/////////////////////////////////////////////////////////////////////////////
void AliasesReturnsListOfAliasesIncludingName()
{
    Attributes->Name("Bob");
    Attributes->Aliases(({ "some guy", "the bobinator" }));
    ExpectEq(3, sizeof(Attributes->Aliases()));
    ExpectEq("some guy", Attributes->Aliases()[0]);
    ExpectEq("the bobinator", Attributes->Aliases()[1]);
    ExpectEq("Bob", Attributes->Aliases()[2]);
}

/////////////////////////////////////////////////////////////////////////////
void AddAliasInsertsAnAlias()
{
    Attributes->Name("Bob");
    ExpectEq(1, sizeof(Attributes->Aliases()));

    ExpectTrue(Attributes->addAlias("bobster"));
    ExpectEq(2, sizeof(Attributes->Aliases()));
    ExpectEq("bobster", Attributes->Aliases()[0]);
    ExpectEq("Bob", Attributes->Aliases()[1]);
}

/////////////////////////////////////////////////////////////////////////////
void IdReturnsTrueForAliasesAndName()
{
    Attributes->Name("Bob");
    ExpectTrue(Attributes->addAlias("bobicles"));

    ExpectTrue(Attributes->id("Bob"), "Bob is a valid id");
    ExpectTrue(Attributes->id("bobicles"), "bobicles is a valid id");
    ExpectFalse(Attributes->id("bobstradamus"), "bobstradamus is not a valid id");
    ExpectFalse(Attributes->id("fred"), "fred is not a valid id");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetAndGetProperties()
{
    ExpectFalse(Attributes->queryProperty("did stuff"));
    Attributes->setProperty("did stuff", 1);
    ExpectEq(1,Attributes->queryProperty("did stuff"));

    Attributes->setProperty("blah", "more stuff");
    ExpectEq("more stuff", Attributes->queryProperty("blah"));
}

/////////////////////////////////////////////////////////////////////////////
void CanClearProperties()
{
    Attributes->setProperty("did stuff", 1);
    ExpectEq(1, Attributes->queryProperty("did stuff"));
    Attributes->clearProperty("did stuff");
    ExpectFalse(Attributes->queryProperty("did stuff"));
}

/////////////////////////////////////////////////////////////////////////////
void AgeIncrements()
{
    ExpectEq(0, Attributes->Age());
    Attributes->heart_beat();
    ExpectEq(2, Attributes->Age());
    Attributes->heart_beat();
    ExpectEq(4, Attributes->Age());
}

/////////////////////////////////////////////////////////////////////////////
void AgeStringReturnsCorrectValueWhenNoParamPassed()
{
    Attributes->heart_beat();
    ExpectEq("2 seconds", Attributes->ageString());
}

/////////////////////////////////////////////////////////////////////////////
void AgeStringReturnsCorrectValue()
{
    ExpectEq("3 years 61 days 9 hours 46 minutes 40 seconds", Attributes->ageString(100000000));
}

/////////////////////////////////////////////////////////////////////////////
void GetReturnsFalse()
{
    ExpectFalse(Attributes->get());
}

/////////////////////////////////////////////////////////////////////////////
void CanSeeReturnsEnvironmentIlluminationByDefault()
{
    object dictionary = load_object("/lib/dictionaries/environmentDictionary.c");
    dictionary->timeOfDay("midnight");
    move_object(Attributes, clone_object("/lib/tests/support/environment/fakeEnvironment.c"));
    ExpectFalse(Attributes->canSee());

    dictionary->timeOfDay("noon");
    ExpectTrue(Attributes->canSee());
    destruct(dictionary);
}

/////////////////////////////////////////////////////////////////////////////
void CanSeeReturnsTrueWhenDarkvisionPresent()
{
    object dictionary = load_object("/lib/dictionaries/environmentDictionary.c");
    dictionary->timeOfDay("midnight");
    move_object(Attributes, clone_object("/lib/tests/support/environment/fakeEnvironment.c"));
    ExpectFalse(Attributes->canSee());

    Attributes->addTrait("/lib/tests/support/traits/testDarkvisionTrait.c");
    ExpectTrue(Attributes->canSee());
    destruct(dictionary);
}

/////////////////////////////////////////////////////////////////////////////
void CanSeeReturnsFalseWhenBlindTraitPresent()
{
    object dictionary = load_object("/lib/dictionaries/environmentDictionary.c");
    dictionary->timeOfDay("noon");
    move_object(Attributes, clone_object("/lib/tests/support/environment/fakeEnvironment.c"));
    ExpectTrue(Attributes->canSee());

    Attributes->addTrait("/lib/modules/traits/diseases/cataracts.c");
    ExpectFalse(Attributes->canSee());
    destruct(dictionary);
}

/////////////////////////////////////////////////////////////////////////////
void CanSeeReturnsTrueWhenItemWithLightPresent()
{
    object dictionary = load_object("/lib/dictionaries/environmentDictionary.c");
    dictionary->timeOfDay("midnight");
    move_object(Attributes, clone_object("/lib/tests/support/environment/fakeEnvironment.c"));
    ExpectFalse(Attributes->canSee());

    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("short", "A Sword");
    weapon->set("weapon type", "long sword");
    weapon->set("light", 1);
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Attributes);
    ExpectTrue(Attributes->canSee());
    destruct(dictionary);
}
