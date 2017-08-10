//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
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
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Attributes);
}

/////////////////////////////////////////////////////////////////////////////
void StrReturnsCorrectValue()
{
    ExpectEq(0, Attributes->Str(), "strength is initially 0");
    ExpectEq(10, Attributes->Str(10), "strength is updated to 10");
    ExpectEq(10, Attributes->Str(), "strength is 10");
    ExpectEq(12, Attributes->Str(2, 1), "strength is incremented to 12");
}

/////////////////////////////////////////////////////////////////////////////
void IntReturnsCorrectValue()
{
    ExpectEq(0, Attributes->Int(), "intelligence is initially 0");
    ExpectEq(12, Attributes->Int(12), "intelligence is updated to 12");
    ExpectEq(12, Attributes->Int(), "intelligence is 12");
    ExpectEq(15, Attributes->Int(3, 1), "intelligence is incremented to 15");
}

/////////////////////////////////////////////////////////////////////////////
void DexReturnsCorrectValue()
{
    ExpectEq(0, Attributes->Dex(), "dexterity is initially 0");
    ExpectEq(10, Attributes->Dex(10), "dexterity is updated to 10");
    ExpectEq(10, Attributes->Dex(), "dexterity is 10");
    ExpectEq(12, Attributes->Dex(2, 1), "dexterity is incremented to 12");
}

/////////////////////////////////////////////////////////////////////////////
void WisReturnsCorrectValue()
{
    ExpectEq(0, Attributes->Wis(), "wisdom is initially 0");
    ExpectEq(10, Attributes->Wis(10), "wisdom is updated to 10");
    ExpectEq(10, Attributes->Wis(), "wisdom is 10");
    ExpectEq(12, Attributes->Wis(2, 1), "wisdom is incremented to 12");
}

/////////////////////////////////////////////////////////////////////////////
void ConReturnsCorrectValue()
{
    ExpectEq(0, Attributes->Con(), "constitution is initially 0");
    ExpectEq(10, Attributes->Con(10), "constitution is updated to 10");
    ExpectEq(10, Attributes->Con(), "constitution is 10");
    ExpectEq(12, Attributes->Con(2, 1), "constitution is incremented to 12");
}

/////////////////////////////////////////////////////////////////////////////
void ChrReturnsCorrectValue()
{
    ExpectEq(0, Attributes->Chr(), "charisma is initially 0");
    ExpectEq(10, Attributes->Chr(10), "charisma is updated to 10");
    ExpectEq(10, Attributes->Chr(), "charisma is 10");
    ExpectEq(12, Attributes->Chr(2, 1), "charisma is incremented to 12");
}

/////////////////////////////////////////////////////////////////////////////
void AttributesAreModifiedByInventory()
{
    ExpectEq(20, Attributes->Str(20), "strength is initially 20");

    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("weapon class", 8);
    weapon->set("material", "mithril");
    weapon->set("weapon type", "long sword");
    weapon->set("bonus strength", 1);
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Attributes);

    object shield = clone_object("/lib/items/weapon");
    shield->set("name", "shield");
    shield->set("defense class", 1);
    shield->set("material", "mithril");
    shield->set("bonus strength", 2);
    shield->set("equipment locations", Shield);
    shield->set("weapon type", "shield");
    move_object(shield, Attributes);

    object armor = clone_object("/lib/items/armor");
    armor->set("name", "stuff");
    armor->set("bonus attack", 1);
    armor->set("bonus strength", 3);
    armor->set("armor class", 5);
    armor->set("armor type", "chainmail");
    armor->set("equipment locations", Armor);
    move_object(armor, Attributes);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier->set("fully qualified name", "thingy");
    modifier->set("bonus attack", 3);
    modifier->set("bonus strength", 4);
    modifier->set("bonus long sword", 5);

    ExpectTrue(weapon->equip("blah"), "weapon equip called");
    ExpectTrue(shield->equip("shield offhand"), "shield equip called");
    ExpectTrue(armor->equip("stuff"), "armor equip called");
    ExpectEq(1, modifier->set("registration list", ({ Attributes })), "registration list can be set");
    ExpectEq(30, Attributes->Str(), "strength is 30");
}

/////////////////////////////////////////////////////////////////////////////
void AttributesAreModifiedByServices()
{
    destruct(Attributes);
    Attributes = clone_object("/lib/tests/support/services/combatWithMockServices");

    ExpectEq(15, Attributes->Str(15), "strength is initially 15");

    Attributes->Race("dwarf");
    ExpectEq(16, Attributes->Str(15), "strength is affected by race");

    Attributes->ToggleMockGuilds();
    ExpectEq(16, Attributes->Str(15), "strength is not affected by guilds");

    Attributes->ToggleMockResearch();
    ExpectEq(18, Attributes->Str(15), "strength is affected by research");

    Attributes->ToggleMockTrait();
    ExpectEq(19, Attributes->Str(15), "strength is affected by traits");

    Attributes->ToggleMockBiological();
    ExpectEq(19, Attributes->Str(15), "strength is not affected by biological");

    Attributes->ToggleMockBackground();
    ExpectEq(19, Attributes->Str(15), "strength is not affected by background");
}

/////////////////////////////////////////////////////////////////////////////
void StrengthBonusReturnsCorrectly()
{
    destruct(Attributes);
    Attributes = clone_object("/lib/tests/support/services/combatWithMockServices");

    Attributes->Str(16);
    ExpectEq(3, Attributes->strengthBonus());

    Attributes->ToggleMockResearch();
    Attributes->ToggleMockTrait();
    ExpectEq(4, Attributes->strengthBonus());

    object modifier = clone_object("/lib/items/modifierObject");
    modifier->set("fully qualified name", "thingy");
    modifier->set("bonus strength", 4);

    ExpectEq(1, modifier->set("registration list", ({ Attributes })), "registration list can be set");
    ExpectEq(6, Attributes->strengthBonus());
}

/////////////////////////////////////////////////////////////////////////////
void IntelligenceBonusReturnsCorrectly()
{
    destruct(Attributes);
    Attributes = clone_object("/lib/tests/support/services/combatWithMockServices");

    Attributes->Int(16);
    ExpectEq(3, Attributes->intelligenceBonus());

    Attributes->ToggleMockResearch();
    Attributes->ToggleMockTrait();
    ExpectEq(4, Attributes->intelligenceBonus());

    object modifier = clone_object("/lib/items/modifierObject");
    modifier->set("fully qualified name", "thingy");
    modifier->set("bonus intelligence", 2);

    ExpectEq(1, modifier->set("registration list", ({ Attributes })), "registration list can be set");
    ExpectEq(5, Attributes->intelligenceBonus());
}

/////////////////////////////////////////////////////////////////////////////
void DexterityBonusReturnsCorrectly()
{
    destruct(Attributes);
    Attributes = clone_object("/lib/tests/support/services/combatWithMockServices");

    Attributes->Dex(16);
    ExpectEq(3, Attributes->dexterityBonus());

    Attributes->ToggleMockResearch();
    Attributes->ToggleMockTrait();
    ExpectEq(4, Attributes->dexterityBonus());

    object modifier = clone_object("/lib/items/modifierObject");
    modifier->set("fully qualified name", "thingy");
    modifier->set("bonus dexterity", 2);

    ExpectEq(1, modifier->set("registration list", ({ Attributes })), "registration list can be set");
    ExpectEq(5, Attributes->dexterityBonus());
}

/////////////////////////////////////////////////////////////////////////////
void WisdomBonusReturnsCorrectly()
{
    destruct(Attributes);
    Attributes = clone_object("/lib/tests/support/services/combatWithMockServices");

    Attributes->Wis(16);
    ExpectEq(3, Attributes->wisdomBonus());

    Attributes->ToggleMockResearch();
    Attributes->ToggleMockTrait();
    ExpectEq(4, Attributes->wisdomBonus());

    object modifier = clone_object("/lib/items/modifierObject");
    modifier->set("fully qualified name", "thingy");
    modifier->set("bonus wisdom", 2);

    ExpectEq(1, modifier->set("registration list", ({ Attributes })), "registration list can be set");
    ExpectEq(5, Attributes->wisdomBonus());
}

/////////////////////////////////////////////////////////////////////////////
void ConstitutionBonusReturnsCorrectly()
{
    destruct(Attributes);
    Attributes = clone_object("/lib/tests/support/services/combatWithMockServices");

    Attributes->Con(16);
    ExpectEq(3, Attributes->constitutionBonus());

    Attributes->ToggleMockResearch();
    Attributes->ToggleMockTrait();
    ExpectEq(4, Attributes->constitutionBonus());

    object modifier = clone_object("/lib/items/modifierObject");
    modifier->set("fully qualified name", "thingy");
    modifier->set("bonus constitution", 2);

    ExpectEq(1, modifier->set("registration list", ({ Attributes })), "registration list can be set");
    ExpectEq(5, Attributes->constitutionBonus());
}

/////////////////////////////////////////////////////////////////////////////
void CharismaBonusReturnsCorrectly()
{
    destruct(Attributes);
    Attributes = clone_object("/lib/tests/support/services/combatWithMockServices");

    Attributes->Chr(16);
    ExpectEq(3, Attributes->charismaBonus());

    Attributes->ToggleMockResearch();
    Attributes->ToggleMockTrait();
    ExpectEq(4, Attributes->charismaBonus());

    object modifier = clone_object("/lib/items/modifierObject");
    modifier->set("fully qualified name", "thingy");
    modifier->set("bonus charisma", 2);

    ExpectEq(1, modifier->set("registration list", ({ Attributes })), "registration list can be set");
    ExpectEq(5, Attributes->charismaBonus());
}

/////////////////////////////////////////////////////////////////////////////
void SpendAttributesIncrementsStrengthCorrectly()
{
    ExpectEq(8, Attributes->Str(8), "initial strength is 8");

    ExpectEq(2, Attributes->addAttributePointsToSpend(2));
    ExpectEq(10, Attributes->spendAttributePoints("strength", 2), "spendAttributePoints increments by 2");
    ExpectEq(10, Attributes->Str(), "strength is 10");
}

/////////////////////////////////////////////////////////////////////////////
void SpendAttributesIncrementsDexterityCorrectly()
{
    ExpectEq(8, Attributes->Dex(8), "initial dexterity is 8");

    ExpectEq(2, Attributes->addAttributePointsToSpend(2));
    ExpectEq(2, Attributes->attributePoints());
    ExpectEq(10, Attributes->spendAttributePoints("dexterity", 2), "spendAttributePoints increments by 2");
    ExpectEq(10, Attributes->Dex(), "dexterity is 10");
}

/////////////////////////////////////////////////////////////////////////////
void SpendAttributesIncrementsIntelligenceCorrectly()
{
    ExpectEq(8, Attributes->Int(8), "initial intelligence is 8");

    ExpectEq(2, Attributes->addAttributePointsToSpend(2));
    ExpectEq(10, Attributes->spendAttributePoints("intelligence", 2), "spendAttributePoints increments by 2");
    ExpectEq(10, Attributes->Int(), "intelligence is 10");
}

/////////////////////////////////////////////////////////////////////////////
void SpendAttributesIncrementsWisdomCorrectly()
{
    ExpectEq(8, Attributes->Wis(8), "initial wisdom is 8");

    ExpectEq(2, Attributes->addAttributePointsToSpend(2));
    ExpectEq(10, Attributes->spendAttributePoints("wisdom", 2), "spendAttributePoints increments by 2");
    ExpectEq(10, Attributes->Wis(), "wisdom is 10");
}

/////////////////////////////////////////////////////////////////////////////
void SpendAttributesIncrementsConstitutionCorrectly()
{
    ExpectEq(8, Attributes->Con(8), "initial constitution is 8");

    ExpectEq(2, Attributes->addAttributePointsToSpend(2));
    ExpectEq(10, Attributes->spendAttributePoints("constitution", 2), "spendAttributePoints increments by 2");
    ExpectEq(10, Attributes->Con(), "constitution is 10");
}

/////////////////////////////////////////////////////////////////////////////
void SpendAttributesIncrementsCharismaCorrectly()
{
    ExpectEq(8, Attributes->Chr(8), "initial charisma is 8");

    ExpectEq(2, Attributes->addAttributePointsToSpend(2));
    ExpectEq(10, Attributes->spendAttributePoints("charisma", 2), "spendAttributePoints increments by 2");
    ExpectEq(10, Attributes->Chr(), "charisma is 10");
}

/////////////////////////////////////////////////////////////////////////////
void SpendAttributesFailsWhenAdvancementExceedsAvailablePoints()
{
    ExpectEq(10, Attributes->Chr(10), "initial charisma is 10");

    ExpectEq(1, Attributes->addAttributePointsToSpend(1));
    ExpectFalse(Attributes->spendAttributePoints("charisma", 2), "spendAttributePoints fails");
    ExpectEq(10, Attributes->Chr(), "charisma is still 10");
}

/////////////////////////////////////////////////////////////////////////////
void SpendAttributesDecrementsAvailablePoints()
{
    ExpectEq(8, Attributes->Chr(8), "initial charisma is 8");

    ExpectEq(2, Attributes->addAttributePointsToSpend(2));
    ExpectEq(9, Attributes->spendAttributePoints("charisma", 1), "spendAttributePoints fails");
    ExpectEq(10, Attributes->spendAttributePoints("charisma", 1), "spendAttributePoints fails");
    ExpectFalse(Attributes->spendAttributePoints("charisma", 1), "spendAttributePoints fails");
    ExpectEq(10, Attributes->Chr(), "charisma is 10");
}

/////////////////////////////////////////////////////////////////////////////
void SpendAttributesFailsWhenAdvancementExceeds10ForLevelLessThan10()
{
    ExpectEq(10, Attributes->Chr(10), "initial charisma is 10");

    ExpectEq(1, Attributes->addAttributePointsToSpend(1));
    ExpectFalse(Attributes->spendAttributePoints("charisma", 1), "spendAttributePoints fails");
    ExpectEq(10, Attributes->Chr(), "charisma is still 10");
}

/////////////////////////////////////////////////////////////////////////////
void SpendAttributesSucceedsWhenAdvancementEqualToOrLessThanLevel()
{
    destruct(Attributes);
    Attributes = clone_object("/lib/realizations/monster.c");

    Attributes->effectiveLevel(16);
    ExpectEq(15, Attributes->Chr(15), "initial charisma is 15");

    ExpectEq(2, Attributes->addAttributePointsToSpend(2));
    ExpectTrue(Attributes->spendAttributePoints("charisma", 1), "spendAttributePoints fails");
    ExpectEq(16, Attributes->Chr(), "charisma is now 16");
}

/////////////////////////////////////////////////////////////////////////////
void SpendAttributesFailsWhenAdvancementExceedsLevelForLevelGreaterThan10()
{
    destruct(Attributes);
    Attributes = clone_object("/lib/realizations/monster.c");

    Attributes->effectiveLevel(16);
    ExpectEq(15, Attributes->Chr(15), "initial charisma is 15");

    ExpectEq(2, Attributes->addAttributePointsToSpend(2));
    ExpectFalse(Attributes->spendAttributePoints("charisma", 2), "spendAttributePoints fails");
    ExpectEq(15, Attributes->Chr(), "charisma is still 15");
}