//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Service;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Service = clone_object("/lib/services/skillsService");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Service);
}

/////////////////////////////////////////////////////////////////////////////
void BlargIsNotAValidSkill()
{
    ExpectFalse(Service.isValidSkill("blarg"), "blarg is not a valid skill");
}

/////////////////////////////////////////////////////////////////////////////
void ParryIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("parry"), "parry is a valid skill");
    ExpectEq("combat", Service.skillType("parry"), "returns proper skill type");
    ExpectEq("dexterity", Service.attributeForSkill("parry"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("parry", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("parry", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void DodgeIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("dodge"), "dodge is a valid skill");
    ExpectEq("combat", Service.skillType("dodge"), "returns proper skill type");
    ExpectEq("dexterity", Service.attributeForSkill("dodge"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("dodge", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("dodge", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void DualWieldIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("dual wield"), "dual wield is a valid skill");
    ExpectEq("combat", Service.skillType("dual wield"), "returns proper skill type");
    ExpectEq("dexterity", Service.attributeForSkill("dual wield"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("dual wield", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("dual wield", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ShieldIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("shield"), "shield is a valid skill");
    ExpectEq("combat", Service.skillType("shield"), "returns proper skill type");
    ExpectEq("strength", Service.attributeForSkill("shield"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("shield", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("shield", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void AxeIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("axe"), "axe is a valid skill");
    ExpectEq("combat", Service.skillType("axe"), "returns proper skill type");
    ExpectEq("strength", Service.attributeForSkill("axe"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("axe", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("axe", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void LongSwordIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("long sword"), "long sword is a valid skill");
    ExpectEq("combat", Service.skillType("long sword"), "returns proper skill type");
    ExpectEq("strength", Service.attributeForSkill("long sword"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("long sword", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("long sword", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void HandAndAHalfSwordIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("hand and a half sword"), "hand and a half sword is a valid skill");
    ExpectEq("combat", Service.skillType("hand and a half sword"), "returns proper skill type");
    ExpectEq("strength", Service.attributeForSkill("hand and a half sword"), "returns proper attribute");
    ExpectEq(6, Service.skillBonus("hand and a half sword", 12), "skill of 12 returns a 6 bonus");
    ExpectEq(-10, Service.skillBonus("hand and a half sword", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ShortSwordIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("short sword"), "short sword is a valid skill");
    ExpectEq("combat", Service.skillType("short sword"), "returns proper skill type");
    ExpectEq("dexterity", Service.attributeForSkill("short sword"), "returns proper attribute");
    ExpectEq(2, Service.skillBonus("short sword", 5), "skill of 5 returns a 2 bonus");
    ExpectEq(-10, Service.skillBonus("short sword", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void TwoHandedSwordIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("two-handed sword"), "two-handed sword is a valid skill");
    ExpectEq("combat", Service.skillType("two-handed sword"), "returns proper skill type");
    ExpectEq("strength", Service.attributeForSkill("two-handed sword"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("two-handed sword", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("two-handed sword", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void DaggerIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("dagger"), "dagger is a valid skill");
    ExpectEq("combat", Service.skillType("dagger"), "returns proper skill type");
    ExpectEq("dexterity", Service.attributeForSkill("dagger"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("dagger", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("dagger", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void BowIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("bow"), "bow is a valid skill");
    ExpectEq("combat", Service.skillType("bow"), "returns proper skill type");
    ExpectEq("dexterity", Service.attributeForSkill("bow"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("bow", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("bow", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void CrossbowIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("crossbow"), "crossbow is a valid skill");
    ExpectEq("combat", Service.skillType("crossbow"), "returns proper skill type");
    ExpectEq("dexterity", Service.attributeForSkill("crossbow"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("crossbow", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("crossbow", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void SlingIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("sling"), "sling is a valid skill");
    ExpectEq("combat", Service.skillType("sling"), "returns proper skill type");
    ExpectEq("dexterity", Service.attributeForSkill("sling"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("sling", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("sling", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ThrownIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("thrown"), "thrown is a valid skill");
    ExpectEq("combat", Service.skillType("thrown"), "returns proper skill type");
    ExpectEq("strength", Service.attributeForSkill("thrown"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("thrown", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("thrown", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void PoleArmIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("pole arm"), "pole arm is a valid skill");
    ExpectEq("combat", Service.skillType("pole arm"), "returns proper skill type");
    ExpectEq("strength", Service.attributeForSkill("pole arm"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("pole arm", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("pole arm", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void MaceIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("mace"), "mace is a valid skill");
    ExpectEq("combat", Service.skillType("mace"), "returns proper skill type");
    ExpectEq("strength", Service.attributeForSkill("mace"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("mace", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("mace", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void HammerIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("hammer"), "hammer is a valid skill");
    ExpectEq("combat", Service.skillType("hammer"), "returns proper skill type");
    ExpectEq("strength", Service.attributeForSkill("hammer"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("hammer", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("hammer", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void FlailIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("flail"), "flail is a valid skill");
    ExpectEq("combat", Service.skillType("flail"), "returns proper skill type");
    ExpectEq("strength", Service.attributeForSkill("flail"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("flail", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("flail", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void StaffIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("staff"), "staff is a valid skill");
    ExpectEq("combat", Service.skillType("staff"), "returns proper skill type");
    ExpectEq("strength", Service.attributeForSkill("staff"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("staff", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("staff", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void PlateArmorIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("plate armor"), "plate armor is a valid skill");
    ExpectEq("combat", Service.skillType("plate armor"), "returns proper skill type");
    ExpectEq("strength", Service.attributeForSkill("plate armor"), "returns proper attribute");
    ExpectEq(3, Service.skillBonus("plate armor", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("plate armor", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void SplintArmorIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("splint armor"), "splint armor is a valid skill");
    ExpectEq("combat", Service.skillType("splint armor"), "returns proper skill type");
    ExpectEq("strength", Service.attributeForSkill("splint armor"), "returns proper attribute");
    ExpectEq(3, Service.skillBonus("splint armor", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("splint armor", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ChainmailIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("chainmail"), "chainmail is a valid skill");
    ExpectEq("combat", Service.skillType("chainmail"), "returns proper skill type");
    ExpectEq("strength", Service.attributeForSkill("chainmail"), "returns proper attribute");
    ExpectEq(3, Service.skillBonus("chainmail", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("chainmail", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ScalemailIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("scalemail"), "scalemail is a valid skill");
    ExpectEq("combat", Service.skillType("scalemail"), "returns proper skill type");
    ExpectEq("strength", Service.attributeForSkill("scalemail"), "returns proper attribute");
    ExpectEq(7, Service.skillBonus("scalemail", 21), "skill of 20 returns a 10 bonus");
    ExpectEq(-10, Service.skillBonus("scalemail", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void HardLeatherIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("hard leather"), "hard leather is a valid skill");
    ExpectEq("combat", Service.skillType("hard leather"), "returns proper skill type");
    ExpectEq("strength", Service.attributeForSkill("hard leather"), "returns proper attribute");
    ExpectEq(3, Service.skillBonus("hard leather", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("hard leather", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void SoftLeatherIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("soft leather"), "soft leather is a valid skill");
    ExpectEq("combat", Service.skillType("soft leather"), "returns proper skill type");
    ExpectEq("dexterity", Service.attributeForSkill("soft leather"), "returns proper attribute");
    ExpectEq(3, Service.skillBonus("soft leather", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("soft leather", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void NoArmorIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("no armor"), "no armor is a valid skill");
    ExpectEq("combat", Service.skillType("no armor"), "returns proper skill type");
    ExpectEq("dexterity", Service.attributeForSkill("no armor"), "returns proper attribute");
    ExpectEq(3, Service.skillBonus("no armor", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("no armor", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void UnarmedIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("unarmed"), "unarmed is a valid skill");
    ExpectEq("combat", Service.skillType("unarmed"), "returns proper skill type");
    ExpectEq("strength", Service.attributeForSkill("unarmed"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("unarmed", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("unarmed", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void AcrobaticsIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("acrobatics"), "acrobatics is a valid skill");
    ExpectEq("crafting", Service.skillType("acrobatics"), "returns proper skill type");
    ExpectEq("dexterity", Service.attributeForSkill("acrobatics"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("acrobatics", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("acrobatics", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void AerophoneIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("aerophone crafting"), "aerophone crafting is a valid skill");
    ExpectEq("crafting", Service.skillType("aerophone crafting"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("aerophone crafting"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("aerophone crafting", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("aerophone crafting", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void BrewingIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("brewing"), "brewing is a valid skill");
    ExpectEq("crafting", Service.skillType("brewing"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("brewing"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("brewing", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("brewing", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void DrumCraftingIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("drum crafting"), "drum crafting is a valid skill");
    ExpectEq("crafting", Service.skillType("drum crafting"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("drum crafting"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("drum crafting", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("drum crafting", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void LuthieryIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("luthiery"), "luthiery is a valid skill");
    ExpectEq("crafting", Service.skillType("luthiery"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("luthiery"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("luthiery", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("luthiery", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ArmorerIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("armorer"), "armorer is a valid skill");
    ExpectEq("crafting", Service.skillType("armorer"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("armorer"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("armorer", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("armorer", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void BlacksmithingIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("blacksmithing"), "blacksmithing is a valid skill");
    ExpectEq("crafting", Service.skillType("blacksmithing"), "returns proper skill type");
    ExpectEq("strength", Service.attributeForSkill("blacksmithing"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("blacksmithing", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("blacksmithing", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void BowyerAndFletcherIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("bowyer and fletcher"), "bowyer and fletcher is a valid skill");
    ExpectEq("crafting", Service.skillType("bowyer and fletcher"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("bowyer and fletcher"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("bowyer and fletcher", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("bowyer and fletcher", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void CarpentryIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("carpentry"), "carpentry is a valid skill");
    ExpectEq("crafting", Service.skillType("carpentry"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("carpentry"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("carpentry", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("carpentry", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void DancingIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("dancing"), "dancing is a valid skill");
    ExpectEq("crafting", Service.skillType("dancing"), "returns proper skill type");
    ExpectEq("dexterity", Service.attributeForSkill("dancing"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("dancing", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("dancing", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void gemGraftingIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("gem crafting"), "gem crafting is a valid skill");
    ExpectEq("crafting", Service.skillType("gem crafting"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("gem crafting"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("gem crafting", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("gem crafting", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void LeatherworkingIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("leatherworking"), "leatherworking is a valid skill");
    ExpectEq("crafting", Service.skillType("leatherworking"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("leatherworking"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("leatherworking", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("leatherworking", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void MetalCraftingIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("metal crafting"), "metal crafting is a valid skill");
    ExpectEq("crafting", Service.skillType("metal crafting"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("metal crafting"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("metal crafting", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("metal crafting", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void MiningIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("mining"), "mining is a valid skill");
    ExpectEq("crafting", Service.skillType("mining"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("mining"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("mining", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("mining", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void InstrumentPluckedIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("instrument: plucked"), "instrument: plucked is a valid skill");
    ExpectEq("crafting", Service.skillType("instrument: plucked"), "returns proper skill type");
    ExpectEq("charisma", Service.attributeForSkill("instrument: plucked"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("instrument: plucked", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("instrument: plucked", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void InstrumentBowedIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("instrument: bowed"), "instrument: bowed is a valid skill");
    ExpectEq("crafting", Service.skillType("instrument: bowed"), "returns proper skill type");
    ExpectEq("charisma", Service.attributeForSkill("instrument: bowed"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("instrument: bowed", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("instrument: bowed", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void InstrumentWoodwindIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("instrument: woodwind"), "instrument: woodwind is a valid skill");
    ExpectEq("crafting", Service.skillType("instrument: woodwind"), "returns proper skill type");
    ExpectEq("charisma", Service.attributeForSkill("instrument: woodwind"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("instrument: woodwind", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("instrument: woodwind", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void InstrumentBrassIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("instrument: brass"), "instrument: brass is a valid skill");
    ExpectEq("crafting", Service.skillType("instrument: brass"), "returns proper skill type");
    ExpectEq("charisma", Service.attributeForSkill("instrument: brass"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("instrument: brass", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("instrument: brass", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void InstrumentPercussionIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("instrument: percussion"), "instrument: percussion is a valid skill");
    ExpectEq("crafting", Service.skillType("instrument: percussion"), "returns proper skill type");
    ExpectEq("charisma", Service.attributeForSkill("instrument: percussion"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("instrument: percussion", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("instrument: percussion", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void PotteryIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("pottery"), "pottery is a valid skill");
    ExpectEq("crafting", Service.skillType("pottery"), "returns proper skill type");
    ExpectEq("dexterity", Service.attributeForSkill("pottery"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("pottery", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("pottery", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void SculptureIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("sculpture"), "sculpture is a valid skill");
    ExpectEq("crafting", Service.skillType("sculpture"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("sculpture"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("sculpture", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("sculpture", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void SewingIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("sewing"), "sewing is a valid skill");
    ExpectEq("crafting", Service.skillType("sewing"), "returns proper skill type");
    ExpectEq("dexterity", Service.attributeForSkill("sewing"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("sewing", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("sewing", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void SingingIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("singing"), "singing is a valid skill");
    ExpectEq("crafting", Service.skillType("singing"), "returns proper skill type");
    ExpectEq("charisma", Service.attributeForSkill("singing"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("singing", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("singing", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void StonemasonryIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("stonemasonry"), "stonemasonry is a valid skill");
    ExpectEq("crafting", Service.skillType("stonemasonry"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("stonemasonry"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("stonemasonry", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("stonemasonry", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void WeaponSmithingIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("weapon smithing"), "weapon smithing is a valid skill");
    ExpectEq("crafting", Service.skillType("weapon smithing"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("weapon smithing"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("weapon smithing", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("weapon smithing", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void WeavingAndBeadworkIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("weaving and beadwork"), "weaving and beadwork is a valid skill");
    ExpectEq("crafting", Service.skillType("weaving and beadwork"), "returns proper skill type");
    ExpectEq("dexterity", Service.attributeForSkill("weaving and beadwork"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("weaving and beadwork", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("weaving and beadwork", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void WoodCraftingIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("wood crafting"), "wood crafting is a valid skill");
    ExpectEq("crafting", Service.skillType("wood crafting"), "returns proper skill type");
    ExpectEq("dexterity", Service.attributeForSkill("wood crafting"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("wood crafting", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("wood crafting", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void AnatomyAndPhysiologyIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("anatomy and physiology"), "anatomy and physiology is a valid skill");
    ExpectEq("erudite", Service.skillType("anatomy and physiology"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("anatomy and physiology"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("anatomy and physiology", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Service.skillBonus("anatomy and physiology", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void PerceptionIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("perception"), "perception is a valid skill");
    ExpectEq("erudite", Service.skillType("perception"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("perception"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("perception", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("perception", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void AncientHistoryIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("ancient history"), "ancient history is a valid skill");
    ExpectEq("erudite", Service.skillType("ancient history"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("ancient history"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("ancient history", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("ancient history", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void AstronomyIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("astronomy"), "astronomy is a valid skill");
    ExpectEq("erudite", Service.skillType("astronomy"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("astronomy"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("astronomy", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("astronomy", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ChemistryIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("chemistry"), "chemistry is a valid skill");
    ExpectEq("erudite", Service.skillType("chemistry"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("chemistry"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("chemistry", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("chemistry", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void EngineeringIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("engineering"), "engineering is a valid skill");
    ExpectEq("erudite", Service.skillType("engineering"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("engineering"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("engineering", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("engineering", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void GeologyIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("geology"), "geology is a valid skill");
    ExpectEq("erudite", Service.skillType("geology"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("geology"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("geology", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("geology", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void HerbalismIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("herbalism"), "herbalism is a valid skill");
    ExpectEq("erudite", Service.skillType("herbalism"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("herbalism"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("herbalism", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("herbalism", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void LinguisticsIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("linguistics"), "linguistics is a valid skill");
    ExpectEq("erudite", Service.skillType("linguistics"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("linguistics"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("linguistics", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("linguistics", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void LocalHistoryIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("local history"), "local history is a valid skill");
    ExpectEq("erudite", Service.skillType("local history"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("local history"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("local history", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("local history", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void MathematicsIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("mathematics"), "mathematics is a valid skill");
    ExpectEq("erudite", Service.skillType("mathematics"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("mathematics"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("mathematics", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("mathematics", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void NavigationIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("navigation"), "navigation is a valid skill");
    ExpectEq("erudite", Service.skillType("navigation"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("navigation"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("navigation", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("navigation", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void PhilosophyIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("philosophy"), "philosophy is a valid skill");
    ExpectEq("erudite", Service.skillType("philosophy"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("philosophy"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("philosophy", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("philosophy", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void PhysicsIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("physics"), "physics is a valid skill");
    ExpectEq("erudite", Service.skillType("physics"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("physics"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("physics", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("physics", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ReadingIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("reading"), "reading is a valid skill");
    ExpectEq("erudite", Service.skillType("reading"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("reading"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("reading", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("reading", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void SpellcraftIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("spellcraft"), "spellcraft is a valid skill");
    ExpectEq("erudite", Service.skillType("spellcraft"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("spellcraft"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("spellcraft", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("spellcraft", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void TheologyIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("theology"), "theology is a valid skill");
    ExpectEq("erudite", Service.skillType("theology"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("theology"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("theology", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("theology", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void WritingIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("writing"), "writing is a valid skill");
    ExpectEq("erudite", Service.skillType("writing"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("writing"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("writing", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("writing", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ZoologyIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("zoology"), "zoology is a valid skill");
    ExpectEq("erudite", Service.skillType("zoology"), "returns proper skill type");
    ExpectEq("charisma", Service.attributeForSkill("zoology"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("zoology", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("zoology", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void BluffIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("bluff"), "bluff is a valid skill");
    ExpectEq("subterfuge", Service.skillType("bluff"), "returns proper skill type");
    ExpectEq("charisma", Service.attributeForSkill("bluff"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("bluff", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("bluff", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ClimbIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("climb"), "climb is a valid skill");
    ExpectEq("subterfuge", Service.skillType("climb"), "returns proper skill type");
    ExpectEq("dexterity", Service.attributeForSkill("climb"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("climb", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("climb", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void DisableTrapsIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("disable traps"), "disable traps is a valid skill");
    ExpectEq("subterfuge", Service.skillType("disable traps"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("disable traps"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("disable traps", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("disable traps", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void DisguiseIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("disguise"), "disguise is a valid skill");
    ExpectEq("subterfuge", Service.skillType("disguise"), "returns proper skill type");
    ExpectEq("charisma", Service.attributeForSkill("disguise"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("disguise", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("disguise", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void FindTrapsIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("find traps"), "find traps is a valid skill");
    ExpectEq("subterfuge", Service.skillType("find traps"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("find traps"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("find traps", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("find traps", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void HideIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("hide"), "hide is a valid skill");
    ExpectEq("subterfuge", Service.skillType("hide"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("hide"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("hide", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("hide", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void DirectionSenseIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("direction sense"), "direction sense is a valid skill");
    ExpectEq("subterfuge", Service.skillType("direction sense"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("direction sense"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("direction sense", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("direction sense", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ListenIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("listen"), "listen is a valid skill");
    ExpectEq("subterfuge", Service.skillType("listen"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("listen"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("listen", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("listen", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void MoveSilentlyIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("move silently"), "move silently is a valid skill");
    ExpectEq("subterfuge", Service.skillType("move silently"), "returns proper skill type");
    ExpectEq("dexterity", Service.attributeForSkill("move silently"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("move silently", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("move silently", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void OpenLockIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("open lock"), "open lock is a valid skill");
    ExpectEq("subterfuge", Service.skillType("open lock"), "returns proper skill type");
    ExpectEq("dexterity", Service.attributeForSkill("open lock"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("open lock", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("open lock", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void SearchIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("search"), "search is a valid skill");
    ExpectEq("subterfuge", Service.skillType("search"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("search"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("search", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("search", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void SetTrapsAndSnaresIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("set traps and snares"), "set traps and snares is a valid skill");
    ExpectEq("subterfuge", Service.skillType("set traps and snares"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("set traps and snares"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("set traps and snares", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("set traps and snares", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void SpotIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("spot"), "spot is a valid skill");
    ExpectEq("subterfuge", Service.skillType("spot"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("spot"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("spot", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("spot", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void TrackingIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("tracking"), "tracking is a valid skill");
    ExpectEq("subterfuge", Service.skillType("tracking"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("tracking"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("tracking", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("tracking", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void AgricultureIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("agriculture"), "agriculture is a valid skill");
    ExpectEq("general", Service.skillType("agriculture"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("agriculture"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("agriculture", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("agriculture", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void AnimalHandlingAndTrainingIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("animal handling"), "animal handling is a valid skill");
    ExpectEq("general", Service.skillType("animal handling"), "returns proper skill type");
    ExpectEq("charisma", Service.attributeForSkill("animal handling"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("animal handling", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("animal handling", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void CampSkillsIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("camp skills"), "camp skills is a valid skill");
    ExpectEq("general", Service.skillType("camp skills"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("camp skills"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("camp skills", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("camp skills", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void CookingIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("cooking"), "cooking is a valid skill");
    ExpectEq("general", Service.skillType("cooking"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("cooking"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("cooking", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("cooking", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void EtiquetteIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("etiquette"), "etiquette is a valid skill");
    ExpectEq("general", Service.skillType("etiquette"), "returns proper skill type");
    ExpectEq("charisma", Service.attributeForSkill("etiquette"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("etiquette", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("etiquette", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ForestryIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("forestry"), "forestry is a valid skill");
    ExpectEq("general", Service.skillType("forestry"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("forestry"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("forestry", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("forestry", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void PersuasionIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("persuasion"), "persuasion is a valid skill");
    ExpectEq("general", Service.skillType("persuasion"), "returns proper skill type");
    ExpectEq("charisma", Service.attributeForSkill("persuasion"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("persuasion", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("persuasion", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void IntimidationIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("intimidation"), "intimidation is a valid skill");
    ExpectEq("general", Service.skillType("intimidation"), "returns proper skill type");
    ExpectEq("charisma", Service.attributeForSkill("intimidation"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("intimidation", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("intimidation", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void BarterIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("barter"), "barter is a valid skill");
    ExpectEq("general", Service.skillType("barter"), "returns proper skill type");
    ExpectEq("charisma", Service.attributeForSkill("barter"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("barter", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("barter", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void DiplomacyIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("diplomacy"), "diplomacy is a valid skill");
    ExpectEq("general", Service.skillType("diplomacy"), "returns proper skill type");
    ExpectEq("charisma", Service.attributeForSkill("diplomacy"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("diplomacy", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("diplomacy", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void HuntingIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("hunting"), "hunting is a valid skill");
    ExpectEq("general", Service.skillType("hunting"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("hunting"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("hunting", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("hunting", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void NauticalSkillsIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("nautical skills"), "nautical skills is a valid skill");
    ExpectEq("general", Service.skillType("nautical skills"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("nautical skills"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("nautical skills", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("nautical skills", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void RopeSkillsIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("rope skills"), "rope skills is a valid skill");
    ExpectEq("general", Service.skillType("rope skills"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("rope skills"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("rope skills", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("rope skills", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void SwimmingIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("swimming"), "swimming is a valid skill");
    ExpectEq("general", Service.skillType("swimming"), "returns proper skill type");
    ExpectEq("dexterity", Service.attributeForSkill("swimming"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("swimming", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("swimming", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void WeatherSenseIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("weather sense"), "weather sense is a valid skill");
    ExpectEq("general", Service.skillType("weather sense"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("weather sense"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("weather sense", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Service.skillBonus("weather sense", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void EvocationIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("evocation"), "evocation is a valid skill");
    ExpectEq("magic", Service.skillType("evocation"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("evocation"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("evocation", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Service.skillBonus("evocation", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void TransformationIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("transformation"), "transformation is a valid skill");
    ExpectEq("magic", Service.skillType("transformation"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("transformation"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("transformation", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Service.skillBonus("transformation", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void DestructionIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("destruction"), "destruction is a valid skill");
    ExpectEq("magic", Service.skillType("destruction"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("destruction"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("destruction", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Service.skillBonus("destruction", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ManipulationIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("manipulation"), "manipulation is a valid skill");
    ExpectEq("magic", Service.skillType("manipulation"), "returns proper skill type");
    ExpectEq("charisma", Service.attributeForSkill("manipulation"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("manipulation", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Service.skillBonus("manipulation", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void DivinationIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("divination"), "divination is a valid skill");
    ExpectEq("magic", Service.skillType("divination"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("divination"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("divination", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Service.skillBonus("divination", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ElementalAirIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("elemental air"), "elemental air is a valid skill");
    ExpectEq("magic", Service.skillType("elemental air"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("elemental air"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("elemental air", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Service.skillBonus("elemental air", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ElementalEarthIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("elemental earth"), "elemental earth is a valid skill");
    ExpectEq("magic", Service.skillType("elemental earth"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("elemental earth"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("elemental earth", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Service.skillBonus("elemental earth", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ElementalFireIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("elemental fire"), "elemental fire is a valid skill");
    ExpectEq("magic", Service.skillType("elemental fire"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("elemental fire"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("elemental fire", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Service.skillBonus("elemental fire", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ElementalWaterIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("elemental water"), "elemental water is a valid skill");
    ExpectEq("magic", Service.skillType("elemental water"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("elemental water"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("elemental water", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Service.skillBonus("elemental water", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void MagicalEssenceIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("magical essence"), "magical essence is a valid skill");
    ExpectEq("magic", Service.skillType("magical essence"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("magical essence"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("magical essence", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Service.skillBonus("magical essence", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void MindIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("mind"), "mind is a valid skill");
    ExpectEq("magic", Service.skillType("mind"), "returns proper skill type");
    ExpectEq("charisma", Service.attributeForSkill("mind"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("mind", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Service.skillBonus("mind", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void SensesIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("senses"), "senses is a valid skill");
    ExpectEq("magic", Service.skillType("senses"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("senses"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("senses", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Service.skillBonus("senses", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void PlantIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("plant"), "plant is a valid skill");
    ExpectEq("magic", Service.skillType("plant"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("plant"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("plant", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Service.skillBonus("plant", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void AnimalIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("animal"), "animal is a valid skill");
    ExpectEq("magic", Service.skillType("animal"), "returns proper skill type");
    ExpectEq("wisdom", Service.attributeForSkill("animal"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("animal", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Service.skillBonus("animal", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void BodyIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("body"), "body is a valid skill");
    ExpectEq("magic", Service.skillType("body"), "returns proper skill type");
    ExpectEq("constitution", Service.attributeForSkill("body"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("body", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Service.skillBonus("body", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void SpiritIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("spirit"), "spirit is a valid skill");
    ExpectEq("magic", Service.skillType("spirit"), "returns proper skill type");
    ExpectEq("charisma", Service.attributeForSkill("spirit"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("spirit", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Service.skillBonus("spirit", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void BloodIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("blood"), "blood is a valid skill");
    ExpectEq("magic", Service.skillType("blood"), "returns proper skill type");
    ExpectEq("constitution", Service.attributeForSkill("blood"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("blood", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Service.skillBonus("blood", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void DwarvenIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("dwarven"), "dwarven is a valid skill");
    ExpectEq("language", Service.skillType("dwarven"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("dwarven"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("dwarven", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("dwarven", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void HighElvenIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("high elven"), "high elven is a valid skill");
    ExpectEq("language", Service.skillType("high elven"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("high elven"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("high elven", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("high elven", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ElvenIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("elven"), "elven is a valid skill");
    ExpectEq("language", Service.skillType("elven"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("elven"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("elven", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("elven", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void SylvanIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("sylvan"), "sylvan is a valid skill");
    ExpectEq("language", Service.skillType("sylvan"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("sylvan"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("sylvan", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("sylvan", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void TirnostiIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("tirnosti"), "tirnosti is a valid skill");
    ExpectEq("language", Service.skillType("tirnosti"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("tirnosti"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("tirnosti", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("tirnosti", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void HillgarathiIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("hillgarathi"), "hillgarathi is a valid skill");
    ExpectEq("language", Service.skillType("hillgarathi"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("hillgarathi"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("hillgarathi", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("hillgarathi", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void AndurathiIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("andurathi"), "andurathi is a valid skill");
    ExpectEq("language", Service.skillType("andurathi"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("andurathi"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("andurathi", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("andurathi", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void MenadrostiIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("menadrosti"), "menadrosti is a valid skill");
    ExpectEq("language", Service.skillType("menadrosti"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("menadrosti"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("menadrosti", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("menadrosti", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void EndurghulIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("endurghul"), "endurghul is a valid skill");
    ExpectEq("language", Service.skillType("endurghul"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("endurghul"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("endurghul", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("endurghul", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void OrcishIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("orcish"), "orcish is a valid skill");
    ExpectEq("language", Service.skillType("orcish"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("orcish"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("orcish", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("orcish", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void CommonIsAValidSkill()
{
    ExpectTrue(Service.isValidSkill("common"), "common is a valid skill");
    ExpectEq("language", Service.skillType("common"), "returns proper skill type");
    ExpectEq("intelligence", Service.attributeForSkill("common"), "returns proper attribute");
    ExpectEq(5, Service.skillBonus("common", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Service.skillBonus("common", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void OneForTwoSkillReturnsProperBonus()
{
    ExpectEq(5, Service.skillBonus("swimming", 10), "One for two skill of 10 returns a 5 bonus");
}

/////////////////////////////////////////////////////////////////////////////
void CanAddCustomSkill()
{
    mapping newSkill = ([
        "type":"general",
            "attribute" : "wisdom",
            "bonus calculator" : "one for one",
            "untrained penalty" : 0,
            "description" : "blah"
    ]);

    ExpectTrue(Service.addSkill("thing", newSkill));
}

/////////////////////////////////////////////////////////////////////////////
void OneForOneSkillReturnsProperBonus()
{
    mapping newSkill = ([
        "type":"general",
            "attribute" : "wisdom",
            "bonus calculator" : "one for one",
            "untrained penalty" : 0,
            "description" : "blah"
    ]);

    ExpectTrue(Service.addSkill("thing", newSkill));
    ExpectEq(10, Service.skillBonus("thing", 10), "One for one skill of 10 returns a 10 bonus");
}

/////////////////////////////////////////////////////////////////////////////
void LogarithmicSkillReturnsProperBonus()
{
    mapping newSkill = ([
        "type":"general",
            "attribute" : "wisdom",
            "bonus calculator" : "logarithmic",
            "untrained penalty" : 0,
            "description" : "blah"
    ]);

    ExpectTrue(Service.addSkill("thing", newSkill));
    ExpectEq(5, Service.skillBonus("thing", 32), "One for one skill of 32 returns a 5 bonus");
}

/////////////////////////////////////////////////////////////////////////////
void CanAdvanceSkillReturnsCorrectly()
{
    object skillOwner = clone_object("/lib/modules/attributes");

    skillOwner.Dex(20);

    ExpectFalse(Service.canAdvanceSkill(skillOwner, "dodge", -5), "cannot advance skill negatively");
    ExpectFalse(Service.canAdvanceSkill(skillOwner, "dodge", 0), "cannot advance skill by 0");
    ExpectTrue(Service.canAdvanceSkill(skillOwner, "dodge", 10), "can advance when skill lower than attribute");
    ExpectFalse(Service.canAdvanceSkill(skillOwner, "dodge", 31), "cannot advance when skill higher than attribute+10");
}
