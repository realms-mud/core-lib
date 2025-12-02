//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Service;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Service = clone_object("/lib/services/bonusesService");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Service);
}

/////////////////////////////////////////////////////////////////////////////
void BlargIsNotAValidBonus()
{
    ExpectFalse(Service.isValidBonus("blarg"), "blarg is not a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void StrengthIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("strength"), "strength is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void IntelligenceIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("intelligence"), "intelligence is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void DexterityIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("dexterity"), "dexterity is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void WisdomIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("wisdom"), "wisdom is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ConstitutionIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("constitution"), "constitution is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void CharismaIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("charisma"), "charisma is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ToIntoxicatedIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("to intoxicated"), "to intoxicated is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ToStuffedIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("to stuffed"), "to stuffed is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ToDruggedIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("to drugged"), "to drugged is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void HeadacheIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("headache"), "headache is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ArmorClassIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("armor class"), "armor class is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void DefenseClassIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("defense class"), "defense class is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void AttackIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("attack"), "attack is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void DaamgeIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("damage"), "damage is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void SoakIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("soak"), "soak is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void HitPointsIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("hit points"), "hit points is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void SpellPointsIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("spell points"), "spell points is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void StaminaPointsIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("stamina points"), "stamina points is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void HealHitPointsRateIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("heal hit points rate"), "heal hit points rate is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void HealHitPointsIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("heal hit points"), "heal hit points is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void HealSpellPointsRateIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("heal spell points rate"), "heal spell points rate is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void HealSpellPointsIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("heal spell points"), "heal spell points is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void HealStaminaRateIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("heal stamina rate"), "heal stamina rate is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void HealStaminaIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("heal stamina"), "heal stamina is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ReduceSpellPointsIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("reduce spell points"), "reduce spell points is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void RecoverSpellPointsIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("recover spell points"), "recover spell points is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ReduceStaminaPointsIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("reduce stamina points"), "reduce stamina points is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void RecoverStaminaPointsIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("recover stamina points"), "recover stamina points is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void WeaponAttackIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("weapon attack"), "weapon attack is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistAcidIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("resist acid"), "resist acid is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistAirIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("resist air"), "resist air is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistBludgeonIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("resist bludgeon"), "resist bludgeon is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistFireIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("resist fire"), "resist fire is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistEvilIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("resist evil"), "resist evil is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistNeutralIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("resist neutral"), "resist neutral is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistPhysicalIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("resist physical"), "resist physical is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistSlashIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("resist slash"), "resist slash is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistDiseaseIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("resist disease"), "resist disease is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistGoodIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("resist good"), "resist good is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistMagicalIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("resist magical"), "resist magical is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistEnergyIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("resist energy"), "resist energy is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistElectricityIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("resist electricity"), "resist electricity is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistThrustIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("resist thrust"), "resist thrust is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistSonicIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("resist sonic"), "resist sonic is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistChaosIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("resist chaos"), "resist chaos is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistEarthIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("resist earth"), "resist earth is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistParalysisIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("resist paralysis"), "resist paralysis is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistPsionicIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("resist psionic"), "resist psionic is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistPoisonIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("resist poison"), "resist poison is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistUndeadIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("resist undead"), "resist undead is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistWaterIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("resist water"), "resist water is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void ResistColdIsAValidBonus()
{
    ExpectTrue(Service.isValidBonus("resist cold"), "resist cold is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void BonusSkillsAreValidBonuses()
{
    // Just test a sampling of the bonuses - for the full test, see skillsServiceTest
    ExpectTrue(Service.isValidBonus("dodge"), "dodge is a valid bonus type");
    ExpectTrue(Service.isValidBonus("long sword"), "long sword is a valid bonus type");
    ExpectTrue(Service.isValidBonus("gem crafting"), "gem crafting is a valid bonus type");
    ExpectTrue(Service.isValidBonus("spellcraft"), "spellcraft is a valid bonus type");
    ExpectFalse(Service.isValidBonus("fake skill"), "fake skill is not a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void AttackTypesAreValidBonuses()
{
    // Just test a sampling of the bonuses - for the full test, see attacksServiceTest
    ExpectTrue(Service.isValidBonus("cold attack"), "cold attack is a valid bonus type");
    ExpectTrue(Service.isValidBonus("fire attack"), "fire attack is a valid bonus type");
    ExpectTrue(Service.isValidBonus("slash attack"), "slash attack is a valid bonus type");
    ExpectTrue(Service.isValidBonus("physical attack"), "physical attack is a valid bonus type");
    ExpectFalse(Service.isValidBonus("flame attack"), "flame attack is a valid bonus type");
}

/////////////////////////////////////////////////////////////////////////////
void StrengthOfFiveIsAValidBonusModifier()
{
    ExpectTrue(Service.isValidBonusModifier("strength", 5), "Strength of 5 is a valid bonus modifier");
}
