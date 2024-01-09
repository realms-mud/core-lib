//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Dictionary;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Dictionary = clone_object("/lib/dictionaries/bonusesDictionary");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Dictionary);
}

/////////////////////////////////////////////////////////////////////////////
void BlargIsNotAValidBonus()
{
    ExpectFalse(Dictionary.isValidBonus("blarg"), "blarg is not a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void StrengthIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("strength"), "strength is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void IntelligenceIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("intelligence"), "intelligence is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void DexterityIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("dexterity"), "dexterity is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void WisdomIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("wisdom"), "wisdom is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ConstitutionIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("constitution"), "constitution is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void CharismaIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("charisma"), "charisma is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ToIntoxicatedIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("to intoxicated"), "to intoxicated is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ToStuffedIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("to stuffed"), "to stuffed is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ToDruggedIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("to drugged"), "to drugged is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void HeadacheIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("headache"), "headache is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ArmorClassIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("armor class"), "armor class is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void DefenseClassIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("defense class"), "defense class is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void AttackIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("attack"), "attack is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void DaamgeIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("damage"), "damage is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void SoakIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("soak"), "soak is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void HitPointsIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("hit points"), "hit points is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void SpellPointsIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("spell points"), "spell points is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void StaminaPointsIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("stamina points"), "stamina points is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void HealHitPointsRateIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("heal hit points rate"), "heal hit points rate is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void HealHitPointsIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("heal hit points"), "heal hit points is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void HealSpellPointsRateIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("heal spell points rate"), "heal spell points rate is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void HealSpellPointsIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("heal spell points"), "heal spell points is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void HealStaminaRateIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("heal stamina rate"), "heal stamina rate is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void HealStaminaIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("heal stamina"), "heal stamina is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ReduceSpellPointsIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("reduce spell points"), "reduce spell points is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void RecoverSpellPointsIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("recover spell points"), "recover spell points is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ReduceStaminaPointsIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("reduce stamina points"), "reduce stamina points is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void RecoverStaminaPointsIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("recover stamina points"), "recover stamina points is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void WeaponAttackIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("weapon attack"), "weapon attack is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistAcidIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("resist acid"), "resist acid is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistAirIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("resist air"), "resist air is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistBludgeonIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("resist bludgeon"), "resist bludgeon is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistFireIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("resist fire"), "resist fire is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistEvilIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("resist evil"), "resist evil is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistNeutralIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("resist neutral"), "resist neutral is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistPhysicalIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("resist physical"), "resist physical is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistSlashIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("resist slash"), "resist slash is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistDiseaseIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("resist disease"), "resist disease is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistGoodIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("resist good"), "resist good is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistMagicalIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("resist magical"), "resist magical is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistEnergyIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("resist energy"), "resist energy is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistElectricityIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("resist electricity"), "resist electricity is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistThrustIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("resist thrust"), "resist thrust is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistSonicIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("resist sonic"), "resist sonic is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistChaosIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("resist chaos"), "resist chaos is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistEarthIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("resist earth"), "resist earth is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistParalysisIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("resist paralysis"), "resist paralysis is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistPsionicIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("resist psionic"), "resist psionic is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistPoisonIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("resist poison"), "resist poison is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistUndeadIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("resist undead"), "resist undead is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistWaterIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("resist water"), "resist water is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistColdIsAValidBonus()
{
    ExpectTrue(Dictionary.isValidBonus("resist cold"), "resist cold is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void BonusSkillsAreValidBonuses()
{
    // Just test a sampling of the bonuses - for the full test, see skillsDictionaryTest
    ExpectTrue(Dictionary.isValidBonus("dodge"), "dodge is a valid bonus type");
    ExpectTrue(Dictionary.isValidBonus("long sword"), "long sword is a valid bonus type");
    ExpectTrue(Dictionary.isValidBonus("gem crafting"), "gem crafting is a valid bonus type");
    ExpectTrue(Dictionary.isValidBonus("spellcraft"), "spellcraft is a valid bonus type");
    ExpectFalse(Dictionary.isValidBonus("fake skill"), "fake skill is not a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void AttackTypesAreValidBonuses()
{
    // Just test a sampling of the bonuses - for the full test, see attacksDictionaryTest
    ExpectTrue(Dictionary.isValidBonus("cold attack"), "cold attack is a valid bonus type");
    ExpectTrue(Dictionary.isValidBonus("fire attack"), "fire attack is a valid bonus type");
    ExpectTrue(Dictionary.isValidBonus("slash attack"), "slash attack is a valid bonus type");
    ExpectTrue(Dictionary.isValidBonus("physical attack"), "physical attack is a valid bonus type");
    ExpectFalse(Dictionary.isValidBonus("flame attack"), "flame attack is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void StrengthOfFiveIsAValidBonusModifier()
{
    ExpectTrue(Dictionary.isValidBonusModifier("strength", 5), "Strength of 5 is a valid bonus modifier");
}
