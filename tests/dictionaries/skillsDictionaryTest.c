//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Dictionary;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Dictionary = clone_object("/lib/dictionaries/skillsDictionary");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Dictionary);
}

/////////////////////////////////////////////////////////////////////////////
void BlargIsNotAValidSkill()
{
    ExpectFalse(Dictionary->isValidSkill("blarg"), "blarg is not a valid skill");
}

/////////////////////////////////////////////////////////////////////////////
void ParryIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("parry"), "parry is a valid skill");
    ExpectEq("combat", Dictionary->skillType("parry"), "returns proper skill type");
    ExpectEq("dexterity", Dictionary->attributeForSkill("parry"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("parry", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("parry", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void DodgeIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("dodge"), "dodge is a valid skill");
    ExpectEq("combat", Dictionary->skillType("dodge"), "returns proper skill type");
    ExpectEq("dexterity", Dictionary->attributeForSkill("dodge"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("dodge", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("dodge", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void DualWieldIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("dual wield"), "dual wield is a valid skill");
    ExpectEq("combat", Dictionary->skillType("dual wield"), "returns proper skill type");
    ExpectEq("dexterity", Dictionary->attributeForSkill("dual wield"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("dual wield", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("dual wield", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ShieldIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("shield"), "shield is a valid skill");
    ExpectEq("combat", Dictionary->skillType("shield"), "returns proper skill type");
    ExpectEq("strength", Dictionary->attributeForSkill("shield"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("shield", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("shield", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void AxeIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("axe"), "axe is a valid skill");
    ExpectEq("combat", Dictionary->skillType("axe"), "returns proper skill type");
    ExpectEq("strength", Dictionary->attributeForSkill("axe"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("axe", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("axe", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void LongSwordIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("long sword"), "long sword is a valid skill");
    ExpectEq("combat", Dictionary->skillType("long sword"), "returns proper skill type");
    ExpectEq("strength", Dictionary->attributeForSkill("long sword"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("long sword", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("long sword", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void HandAndAHalfSwordIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("hand and a half sword"), "hand and a half sword is a valid skill");
    ExpectEq("combat", Dictionary->skillType("hand and a half sword"), "returns proper skill type");
    ExpectEq("strength", Dictionary->attributeForSkill("hand and a half sword"), "returns proper attribute");
    ExpectEq(6, Dictionary->skillBonus("hand and a half sword", 12), "skill of 12 returns a 6 bonus");
    ExpectEq(-10, Dictionary->skillBonus("hand and a half sword", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ShortSwordIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("short sword"), "short sword is a valid skill");
    ExpectEq("combat", Dictionary->skillType("short sword"), "returns proper skill type");
    ExpectEq("dexterity", Dictionary->attributeForSkill("short sword"), "returns proper attribute");
    ExpectEq(2, Dictionary->skillBonus("short sword", 5), "skill of 5 returns a 2 bonus");
    ExpectEq(-10, Dictionary->skillBonus("short sword", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void TwoHandedSwordIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("two-handed sword"), "two-handed sword is a valid skill");
    ExpectEq("combat", Dictionary->skillType("two-handed sword"), "returns proper skill type");
    ExpectEq("strength", Dictionary->attributeForSkill("two-handed sword"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("two-handed sword", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("two-handed sword", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void DaggerIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("dagger"), "dagger is a valid skill");
    ExpectEq("combat", Dictionary->skillType("dagger"), "returns proper skill type");
    ExpectEq("dexterity", Dictionary->attributeForSkill("dagger"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("dagger", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("dagger", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void BowIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("bow"), "bow is a valid skill");
    ExpectEq("combat", Dictionary->skillType("bow"), "returns proper skill type");
    ExpectEq("dexterity", Dictionary->attributeForSkill("bow"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("bow", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("bow", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void CrossbowIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("crossbow"), "crossbow is a valid skill");
    ExpectEq("combat", Dictionary->skillType("crossbow"), "returns proper skill type");
    ExpectEq("dexterity", Dictionary->attributeForSkill("crossbow"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("crossbow", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("crossbow", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void SlingIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("sling"), "sling is a valid skill");
    ExpectEq("combat", Dictionary->skillType("sling"), "returns proper skill type");
    ExpectEq("dexterity", Dictionary->attributeForSkill("sling"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("sling", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("sling", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ThrownIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("thrown"), "thrown is a valid skill");
    ExpectEq("combat", Dictionary->skillType("thrown"), "returns proper skill type");
    ExpectEq("strength", Dictionary->attributeForSkill("thrown"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("thrown", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("thrown", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void PoleArmIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("pole arm"), "pole arm is a valid skill");
    ExpectEq("combat", Dictionary->skillType("pole arm"), "returns proper skill type");
    ExpectEq("strength", Dictionary->attributeForSkill("pole arm"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("pole arm", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("pole arm", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void MaceIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("mace"), "mace is a valid skill");
    ExpectEq("combat", Dictionary->skillType("mace"), "returns proper skill type");
    ExpectEq("strength", Dictionary->attributeForSkill("mace"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("mace", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("mace", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void HammerIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("hammer"), "hammer is a valid skill");
    ExpectEq("combat", Dictionary->skillType("hammer"), "returns proper skill type");
    ExpectEq("strength", Dictionary->attributeForSkill("hammer"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("hammer", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("hammer", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void FlailIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("flail"), "flail is a valid skill");
    ExpectEq("combat", Dictionary->skillType("flail"), "returns proper skill type");
    ExpectEq("strength", Dictionary->attributeForSkill("flail"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("flail", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("flail", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void StaffIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("staff"), "staff is a valid skill");
    ExpectEq("combat", Dictionary->skillType("staff"), "returns proper skill type");
    ExpectEq("strength", Dictionary->attributeForSkill("staff"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("staff", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("staff", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void PlateArmorIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("plate armor"), "plate armor is a valid skill");
    ExpectEq("combat", Dictionary->skillType("plate armor"), "returns proper skill type");
    ExpectEq("strength", Dictionary->attributeForSkill("plate armor"), "returns proper attribute");
    ExpectEq(3, Dictionary->skillBonus("plate armor", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("plate armor", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void SplintArmorIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("splint armor"), "splint armor is a valid skill");
    ExpectEq("combat", Dictionary->skillType("splint armor"), "returns proper skill type");
    ExpectEq("strength", Dictionary->attributeForSkill("splint armor"), "returns proper attribute");
    ExpectEq(3, Dictionary->skillBonus("splint armor", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("splint armor", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ChainmailIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("chainmail"), "chainmail is a valid skill");
    ExpectEq("combat", Dictionary->skillType("chainmail"), "returns proper skill type");
    ExpectEq("strength", Dictionary->attributeForSkill("chainmail"), "returns proper attribute");
    ExpectEq(3, Dictionary->skillBonus("chainmail", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("chainmail", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ScalemailIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("scalemail"), "scalemail is a valid skill");
    ExpectEq("combat", Dictionary->skillType("scalemail"), "returns proper skill type");
    ExpectEq("strength", Dictionary->attributeForSkill("scalemail"), "returns proper attribute");
    ExpectEq(7, Dictionary->skillBonus("scalemail", 21), "skill of 20 returns a 10 bonus");
    ExpectEq(-10, Dictionary->skillBonus("scalemail", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void HardLeatherIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("hard leather"), "hard leather is a valid skill");
    ExpectEq("combat", Dictionary->skillType("hard leather"), "returns proper skill type");
    ExpectEq("strength", Dictionary->attributeForSkill("hard leather"), "returns proper attribute");
    ExpectEq(3, Dictionary->skillBonus("hard leather", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("hard leather", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void SoftLeatherIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("soft leather"), "soft leather is a valid skill");
    ExpectEq("combat", Dictionary->skillType("soft leather"), "returns proper skill type");
    ExpectEq("dexterity", Dictionary->attributeForSkill("soft leather"), "returns proper attribute");
    ExpectEq(3, Dictionary->skillBonus("soft leather", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("soft leather", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void NoArmorIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("no armor"), "no armor is a valid skill");
    ExpectEq("combat", Dictionary->skillType("no armor"), "returns proper skill type");
    ExpectEq("dexterity", Dictionary->attributeForSkill("no armor"), "returns proper attribute");
    ExpectEq(3, Dictionary->skillBonus("no armor", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("no armor", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void UnarmedIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("unarmed"), "unarmed is a valid skill");
    ExpectEq("combat", Dictionary->skillType("unarmed"), "returns proper skill type");
    ExpectEq("strength", Dictionary->attributeForSkill("unarmed"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("unarmed", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("unarmed", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void AcrobaticsIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("acrobatics"), "acrobatics is a valid skill");
    ExpectEq("crafting", Dictionary->skillType("acrobatics"), "returns proper skill type");
    ExpectEq("dexterity", Dictionary->attributeForSkill("acrobatics"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("acrobatics", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("acrobatics", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void AerophoneIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("aerophone crafting"), "aerophone crafting is a valid skill");
    ExpectEq("crafting", Dictionary->skillType("aerophone crafting"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("aerophone crafting"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("aerophone crafting", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("aerophone crafting", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void BrewingIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("brewing"), "brewing is a valid skill");
    ExpectEq("crafting", Dictionary->skillType("brewing"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("brewing"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("brewing", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("brewing", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void DrumCraftingIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("drum crafting"), "drum crafting is a valid skill");
    ExpectEq("crafting", Dictionary->skillType("drum crafting"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("drum crafting"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("drum crafting", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("drum crafting", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void LuthieryIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("luthiery"), "luthiery is a valid skill");
    ExpectEq("crafting", Dictionary->skillType("luthiery"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("luthiery"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("luthiery", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("luthiery", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ArmorerIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("armorer"), "armorer is a valid skill");
    ExpectEq("crafting", Dictionary->skillType("armorer"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("armorer"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("armorer", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("armorer", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void BlacksmithingIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("blacksmithing"), "blacksmithing is a valid skill");
    ExpectEq("crafting", Dictionary->skillType("blacksmithing"), "returns proper skill type");
    ExpectEq("strength", Dictionary->attributeForSkill("blacksmithing"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("blacksmithing", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("blacksmithing", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void BowyerAndFletcherIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("bowyer and fletcher"), "bowyer and fletcher is a valid skill");
    ExpectEq("crafting", Dictionary->skillType("bowyer and fletcher"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("bowyer and fletcher"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("bowyer and fletcher", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("bowyer and fletcher", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void CarpentryIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("carpentry"), "carpentry is a valid skill");
    ExpectEq("crafting", Dictionary->skillType("carpentry"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("carpentry"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("carpentry", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("carpentry", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void DancingIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("dancing"), "dancing is a valid skill");
    ExpectEq("crafting", Dictionary->skillType("dancing"), "returns proper skill type");
    ExpectEq("dexterity", Dictionary->attributeForSkill("dancing"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("dancing", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("dancing", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void gemGraftingIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("gem crafting"), "gem crafting is a valid skill");
    ExpectEq("crafting", Dictionary->skillType("gem crafting"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("gem crafting"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("gem crafting", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("gem crafting", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void LeatherworkingIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("leatherworking"), "leatherworking is a valid skill");
    ExpectEq("crafting", Dictionary->skillType("leatherworking"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("leatherworking"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("leatherworking", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("leatherworking", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void MetalCraftingIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("metal crafting"), "metal crafting is a valid skill");
    ExpectEq("crafting", Dictionary->skillType("metal crafting"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("metal crafting"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("metal crafting", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("metal crafting", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void MiningIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("mining"), "mining is a valid skill");
    ExpectEq("crafting", Dictionary->skillType("mining"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("mining"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("mining", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("mining", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void InstrumentPluckedIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("instrument: plucked"), "instrument: plucked is a valid skill");
    ExpectEq("crafting", Dictionary->skillType("instrument: plucked"), "returns proper skill type");
    ExpectEq("charisma", Dictionary->attributeForSkill("instrument: plucked"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("instrument: plucked", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("instrument: plucked", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void InstrumentBowedIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("instrument: bowed"), "instrument: bowed is a valid skill");
    ExpectEq("crafting", Dictionary->skillType("instrument: bowed"), "returns proper skill type");
    ExpectEq("charisma", Dictionary->attributeForSkill("instrument: bowed"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("instrument: bowed", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("instrument: bowed", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void InstrumentWoodwindIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("instrument: woodwind"), "instrument: woodwind is a valid skill");
    ExpectEq("crafting", Dictionary->skillType("instrument: woodwind"), "returns proper skill type");
    ExpectEq("charisma", Dictionary->attributeForSkill("instrument: woodwind"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("instrument: woodwind", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("instrument: woodwind", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void InstrumentBrassIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("instrument: brass"), "instrument: brass is a valid skill");
    ExpectEq("crafting", Dictionary->skillType("instrument: brass"), "returns proper skill type");
    ExpectEq("charisma", Dictionary->attributeForSkill("instrument: brass"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("instrument: brass", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("instrument: brass", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void InstrumentPercussionIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("instrument: percussion"), "instrument: percussion is a valid skill");
    ExpectEq("crafting", Dictionary->skillType("instrument: percussion"), "returns proper skill type");
    ExpectEq("charisma", Dictionary->attributeForSkill("instrument: percussion"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("instrument: percussion", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("instrument: percussion", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void PotteryIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("pottery"), "pottery is a valid skill");
    ExpectEq("crafting", Dictionary->skillType("pottery"), "returns proper skill type");
    ExpectEq("dexterity", Dictionary->attributeForSkill("pottery"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("pottery", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("pottery", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void SculptureIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("sculpture"), "sculpture is a valid skill");
    ExpectEq("crafting", Dictionary->skillType("sculpture"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("sculpture"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("sculpture", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("sculpture", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void SewingIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("sewing"), "sewing is a valid skill");
    ExpectEq("crafting", Dictionary->skillType("sewing"), "returns proper skill type");
    ExpectEq("dexterity", Dictionary->attributeForSkill("sewing"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("sewing", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("sewing", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void SingingIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("singing"), "singing is a valid skill");
    ExpectEq("crafting", Dictionary->skillType("singing"), "returns proper skill type");
    ExpectEq("charisma", Dictionary->attributeForSkill("singing"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("singing", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("singing", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void StonemasonryIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("stonemasonry"), "stonemasonry is a valid skill");
    ExpectEq("crafting", Dictionary->skillType("stonemasonry"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("stonemasonry"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("stonemasonry", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("stonemasonry", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void WeaponSmithingIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("weapon smithing"), "weapon smithing is a valid skill");
    ExpectEq("crafting", Dictionary->skillType("weapon smithing"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("weapon smithing"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("weapon smithing", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("weapon smithing", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void WeavingAndBeadworkIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("weaving and beadwork"), "weaving and beadwork is a valid skill");
    ExpectEq("crafting", Dictionary->skillType("weaving and beadwork"), "returns proper skill type");
    ExpectEq("dexterity", Dictionary->attributeForSkill("weaving and beadwork"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("weaving and beadwork", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("weaving and beadwork", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void WoodCraftingIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("wood crafting"), "wood crafting is a valid skill");
    ExpectEq("crafting", Dictionary->skillType("wood crafting"), "returns proper skill type");
    ExpectEq("dexterity", Dictionary->attributeForSkill("wood crafting"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("wood crafting", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("wood crafting", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void AnatomyAndPhysiologyIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("anatomy and physiology"), "anatomy and physiology is a valid skill");
    ExpectEq("erudite", Dictionary->skillType("anatomy and physiology"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("anatomy and physiology"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("anatomy and physiology", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-5, Dictionary->skillBonus("anatomy and physiology", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void PerceptionIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("perception"), "perception is a valid skill");
    ExpectEq("erudite", Dictionary->skillType("perception"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("perception"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("perception", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("perception", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void AncientHistoryIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("ancient history"), "ancient history is a valid skill");
    ExpectEq("erudite", Dictionary->skillType("ancient history"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("ancient history"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("ancient history", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("ancient history", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void AstronomyIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("astronomy"), "astronomy is a valid skill");
    ExpectEq("erudite", Dictionary->skillType("astronomy"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("astronomy"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("astronomy", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("astronomy", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ChemistryIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("chemistry"), "chemistry is a valid skill");
    ExpectEq("erudite", Dictionary->skillType("chemistry"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("chemistry"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("chemistry", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("chemistry", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void EngineeringIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("engineering"), "engineering is a valid skill");
    ExpectEq("erudite", Dictionary->skillType("engineering"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("engineering"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("engineering", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("engineering", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void GeologyIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("geology"), "geology is a valid skill");
    ExpectEq("erudite", Dictionary->skillType("geology"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("geology"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("geology", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("geology", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void HerbalismIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("herbalism"), "herbalism is a valid skill");
    ExpectEq("erudite", Dictionary->skillType("herbalism"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("herbalism"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("herbalism", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("herbalism", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void LinguisticsIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("linguistics"), "linguistics is a valid skill");
    ExpectEq("erudite", Dictionary->skillType("linguistics"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("linguistics"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("linguistics", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("linguistics", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void LocalHistoryIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("local history"), "local history is a valid skill");
    ExpectEq("erudite", Dictionary->skillType("local history"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("local history"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("local history", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("local history", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void MathematicsIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("mathematics"), "mathematics is a valid skill");
    ExpectEq("erudite", Dictionary->skillType("mathematics"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("mathematics"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("mathematics", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("mathematics", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void NavigationIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("navigation"), "navigation is a valid skill");
    ExpectEq("erudite", Dictionary->skillType("navigation"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("navigation"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("navigation", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("navigation", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void PhilosophyIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("philosophy"), "philosophy is a valid skill");
    ExpectEq("erudite", Dictionary->skillType("philosophy"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("philosophy"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("philosophy", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("philosophy", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void PhysicsIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("physics"), "physics is a valid skill");
    ExpectEq("erudite", Dictionary->skillType("physics"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("physics"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("physics", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("physics", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ReadingIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("reading"), "reading is a valid skill");
    ExpectEq("erudite", Dictionary->skillType("reading"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("reading"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("reading", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("reading", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void SpellcraftIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("spellcraft"), "spellcraft is a valid skill");
    ExpectEq("erudite", Dictionary->skillType("spellcraft"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("spellcraft"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("spellcraft", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("spellcraft", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void TheologyIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("theology"), "theology is a valid skill");
    ExpectEq("erudite", Dictionary->skillType("theology"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("theology"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("theology", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("theology", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void WritingIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("writing"), "writing is a valid skill");
    ExpectEq("erudite", Dictionary->skillType("writing"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("writing"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("writing", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("writing", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ZoologyIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("zoology"), "zoology is a valid skill");
    ExpectEq("erudite", Dictionary->skillType("zoology"), "returns proper skill type");
    ExpectEq("charisma", Dictionary->attributeForSkill("zoology"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("zoology", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("zoology", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void BluffIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("bluff"), "bluff is a valid skill");
    ExpectEq("subterfuge", Dictionary->skillType("bluff"), "returns proper skill type");
    ExpectEq("charisma", Dictionary->attributeForSkill("bluff"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("bluff", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("bluff", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ClimbIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("climb"), "climb is a valid skill");
    ExpectEq("subterfuge", Dictionary->skillType("climb"), "returns proper skill type");
    ExpectEq("dexterity", Dictionary->attributeForSkill("climb"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("climb", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("climb", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void DisableTrapsIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("disable traps"), "disable traps is a valid skill");
    ExpectEq("subterfuge", Dictionary->skillType("disable traps"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("disable traps"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("disable traps", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("disable traps", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void DisguiseIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("disguise"), "disguise is a valid skill");
    ExpectEq("subterfuge", Dictionary->skillType("disguise"), "returns proper skill type");
    ExpectEq("charisma", Dictionary->attributeForSkill("disguise"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("disguise", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("disguise", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void FindTrapsIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("find traps"), "find traps is a valid skill");
    ExpectEq("subterfuge", Dictionary->skillType("find traps"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("find traps"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("find traps", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("find traps", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void HideIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("hide"), "hide is a valid skill");
    ExpectEq("subterfuge", Dictionary->skillType("hide"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("hide"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("hide", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("hide", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void DirectionSenseIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("direction sense"), "direction sense is a valid skill");
    ExpectEq("subterfuge", Dictionary->skillType("direction sense"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("direction sense"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("direction sense", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("direction sense", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ListenIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("listen"), "listen is a valid skill");
    ExpectEq("subterfuge", Dictionary->skillType("listen"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("listen"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("listen", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("listen", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void MoveSilentlyIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("move silently"), "move silently is a valid skill");
    ExpectEq("subterfuge", Dictionary->skillType("move silently"), "returns proper skill type");
    ExpectEq("dexterity", Dictionary->attributeForSkill("move silently"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("move silently", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("move silently", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void OpenLockIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("open lock"), "open lock is a valid skill");
    ExpectEq("subterfuge", Dictionary->skillType("open lock"), "returns proper skill type");
    ExpectEq("dexterity", Dictionary->attributeForSkill("open lock"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("open lock", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("open lock", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void SearchIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("search"), "search is a valid skill");
    ExpectEq("subterfuge", Dictionary->skillType("search"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("search"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("search", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("search", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void SetTrapsAndSnaresIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("set traps and snares"), "set traps and snares is a valid skill");
    ExpectEq("subterfuge", Dictionary->skillType("set traps and snares"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("set traps and snares"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("set traps and snares", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("set traps and snares", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void SpotIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("spot"), "spot is a valid skill");
    ExpectEq("subterfuge", Dictionary->skillType("spot"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("spot"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("spot", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("spot", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void TrackingIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("tracking"), "tracking is a valid skill");
    ExpectEq("subterfuge", Dictionary->skillType("tracking"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("tracking"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("tracking", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("tracking", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void AgricultureIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("agriculture"), "agriculture is a valid skill");
    ExpectEq("general", Dictionary->skillType("agriculture"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("agriculture"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("agriculture", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("agriculture", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void AnimalHandlingAndTrainingIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("animal handling"), "animal handling is a valid skill");
    ExpectEq("general", Dictionary->skillType("animal handling"), "returns proper skill type");
    ExpectEq("charisma", Dictionary->attributeForSkill("animal handling"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("animal handling", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("animal handling", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void CampSkillsIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("camp skills"), "camp skills is a valid skill");
    ExpectEq("general", Dictionary->skillType("camp skills"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("camp skills"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("camp skills", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("camp skills", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void CookingIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("cooking"), "cooking is a valid skill");
    ExpectEq("general", Dictionary->skillType("cooking"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("cooking"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("cooking", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("cooking", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void EtiquetteIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("etiquette"), "etiquette is a valid skill");
    ExpectEq("general", Dictionary->skillType("etiquette"), "returns proper skill type");
    ExpectEq("charisma", Dictionary->attributeForSkill("etiquette"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("etiquette", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("etiquette", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void PersuasionIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("persuasion"), "persuasion is a valid skill");
    ExpectEq("general", Dictionary->skillType("persuasion"), "returns proper skill type");
    ExpectEq("charisma", Dictionary->attributeForSkill("persuasion"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("persuasion", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("persuasion", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void IntimidationIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("intimidation"), "intimidation is a valid skill");
    ExpectEq("general", Dictionary->skillType("intimidation"), "returns proper skill type");
    ExpectEq("charisma", Dictionary->attributeForSkill("intimidation"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("intimidation", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("intimidation", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void BarterIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("barter"), "barter is a valid skill");
    ExpectEq("general", Dictionary->skillType("barter"), "returns proper skill type");
    ExpectEq("charisma", Dictionary->attributeForSkill("barter"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("barter", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("barter", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void DiplomacyIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("diplomacy"), "diplomacy is a valid skill");
    ExpectEq("general", Dictionary->skillType("diplomacy"), "returns proper skill type");
    ExpectEq("charisma", Dictionary->attributeForSkill("diplomacy"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("diplomacy", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("diplomacy", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void HuntingIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("hunting"), "hunting is a valid skill");
    ExpectEq("general", Dictionary->skillType("hunting"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("hunting"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("hunting", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("hunting", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void NauticalSkillsIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("nautical skills"), "nautical skills is a valid skill");
    ExpectEq("general", Dictionary->skillType("nautical skills"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("nautical skills"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("nautical skills", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("nautical skills", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void RopeSkillsIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("rope skills"), "rope skills is a valid skill");
    ExpectEq("general", Dictionary->skillType("rope skills"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("rope skills"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("rope skills", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("rope skills", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void SwimmingIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("swimming"), "swimming is a valid skill");
    ExpectEq("general", Dictionary->skillType("swimming"), "returns proper skill type");
    ExpectEq("dexterity", Dictionary->attributeForSkill("swimming"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("swimming", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("swimming", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void WeatherSenseIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("weather sense"), "weather sense is a valid skill");
    ExpectEq("general", Dictionary->skillType("weather sense"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("weather sense"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("weather sense", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(0, Dictionary->skillBonus("weather sense", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void EvocationIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("evocation"), "evocation is a valid skill");
    ExpectEq("magic", Dictionary->skillType("evocation"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("evocation"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("evocation", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Dictionary->skillBonus("evocation", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void TransformationIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("transformation"), "transformation is a valid skill");
    ExpectEq("magic", Dictionary->skillType("transformation"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("transformation"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("transformation", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Dictionary->skillBonus("transformation", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void DestructionIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("destruction"), "destruction is a valid skill");
    ExpectEq("magic", Dictionary->skillType("destruction"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("destruction"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("destruction", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Dictionary->skillBonus("destruction", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ManipulationIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("manipulation"), "manipulation is a valid skill");
    ExpectEq("magic", Dictionary->skillType("manipulation"), "returns proper skill type");
    ExpectEq("charisma", Dictionary->attributeForSkill("manipulation"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("manipulation", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Dictionary->skillBonus("manipulation", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void DivinationIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("divination"), "divination is a valid skill");
    ExpectEq("magic", Dictionary->skillType("divination"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("divination"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("divination", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Dictionary->skillBonus("divination", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ElementalAirIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("elemental air"), "elemental air is a valid skill");
    ExpectEq("magic", Dictionary->skillType("elemental air"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("elemental air"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("elemental air", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Dictionary->skillBonus("elemental air", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ElementalEarthIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("elemental earth"), "elemental earth is a valid skill");
    ExpectEq("magic", Dictionary->skillType("elemental earth"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("elemental earth"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("elemental earth", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Dictionary->skillBonus("elemental earth", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ElementalFireIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("elemental fire"), "elemental fire is a valid skill");
    ExpectEq("magic", Dictionary->skillType("elemental fire"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("elemental fire"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("elemental fire", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Dictionary->skillBonus("elemental fire", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ElementalWaterIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("elemental water"), "elemental water is a valid skill");
    ExpectEq("magic", Dictionary->skillType("elemental water"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("elemental water"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("elemental water", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Dictionary->skillBonus("elemental water", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void MagicalEssenceIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("magical essence"), "magical essence is a valid skill");
    ExpectEq("magic", Dictionary->skillType("magical essence"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("magical essence"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("magical essence", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Dictionary->skillBonus("magical essence", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void MindIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("mind"), "mind is a valid skill");
    ExpectEq("magic", Dictionary->skillType("mind"), "returns proper skill type");
    ExpectEq("charisma", Dictionary->attributeForSkill("mind"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("mind", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Dictionary->skillBonus("mind", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void SensesIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("senses"), "senses is a valid skill");
    ExpectEq("magic", Dictionary->skillType("senses"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("senses"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("senses", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Dictionary->skillBonus("senses", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void PlantIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("plant"), "plant is a valid skill");
    ExpectEq("magic", Dictionary->skillType("plant"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("plant"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("plant", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Dictionary->skillBonus("plant", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void AnimalIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("animal"), "animal is a valid skill");
    ExpectEq("magic", Dictionary->skillType("animal"), "returns proper skill type");
    ExpectEq("wisdom", Dictionary->attributeForSkill("animal"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("animal", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Dictionary->skillBonus("animal", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void BodyIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("body"), "body is a valid skill");
    ExpectEq("magic", Dictionary->skillType("body"), "returns proper skill type");
    ExpectEq("constitution", Dictionary->attributeForSkill("body"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("body", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Dictionary->skillBonus("body", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void SpiritIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("spirit"), "spirit is a valid skill");
    ExpectEq("magic", Dictionary->skillType("spirit"), "returns proper skill type");
    ExpectEq("charisma", Dictionary->attributeForSkill("spirit"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("spirit", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Dictionary->skillBonus("spirit", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void BloodIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("blood"), "blood is a valid skill");
    ExpectEq("magic", Dictionary->skillType("blood"), "returns proper skill type");
    ExpectEq("constitution", Dictionary->attributeForSkill("blood"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("blood", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-15, Dictionary->skillBonus("blood", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void DwarvenIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("dwarven"), "dwarven is a valid skill");
    ExpectEq("language", Dictionary->skillType("dwarven"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("dwarven"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("dwarven", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("dwarven", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void HighElvenIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("high elven"), "high elven is a valid skill");
    ExpectEq("language", Dictionary->skillType("high elven"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("high elven"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("high elven", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("high elven", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void ElvenIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("elven"), "elven is a valid skill");
    ExpectEq("language", Dictionary->skillType("elven"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("elven"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("elven", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("elven", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void SylvanIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("sylvan"), "sylvan is a valid skill");
    ExpectEq("language", Dictionary->skillType("sylvan"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("sylvan"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("sylvan", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("sylvan", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void TirnostiIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("tirnosti"), "tirnosti is a valid skill");
    ExpectEq("language", Dictionary->skillType("tirnosti"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("tirnosti"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("tirnosti", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("tirnosti", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void HillgarathiIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("hillgarathi"), "hillgarathi is a valid skill");
    ExpectEq("language", Dictionary->skillType("hillgarathi"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("hillgarathi"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("hillgarathi", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("hillgarathi", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void AndurathiIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("andurathi"), "andurathi is a valid skill");
    ExpectEq("language", Dictionary->skillType("andurathi"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("andurathi"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("andurathi", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("andurathi", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void MenadrostiIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("menadrosti"), "menadrosti is a valid skill");
    ExpectEq("language", Dictionary->skillType("menadrosti"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("menadrosti"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("menadrosti", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("menadrosti", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void EndurghulIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("endurghul"), "endurghul is a valid skill");
    ExpectEq("language", Dictionary->skillType("endurghul"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("endurghul"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("endurghul", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("endurghul", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void OrcishIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("orcish"), "orcish is a valid skill");
    ExpectEq("language", Dictionary->skillType("orcish"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("orcish"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("orcish", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("orcish", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void CommonIsAValidSkill()
{
    ExpectTrue(Dictionary->isValidSkill("common"), "common is a valid skill");
    ExpectEq("language", Dictionary->skillType("common"), "returns proper skill type");
    ExpectEq("intelligence", Dictionary->attributeForSkill("common"), "returns proper attribute");
    ExpectEq(5, Dictionary->skillBonus("common", 10), "skill of 10 returns a 5 bonus");
    ExpectEq(-10, Dictionary->skillBonus("common", 0), "returns correct value when untrained");
}

/////////////////////////////////////////////////////////////////////////////
void OneForTwoSkillReturnsProperBonus()
{
    ExpectEq(5, Dictionary->skillBonus("swimming", 10), "One for two skill of 10 returns a 5 bonus");
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

    ExpectTrue(Dictionary->addSkill("thing", newSkill));
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

    ExpectTrue(Dictionary->addSkill("thing", newSkill));
    ExpectEq(10, Dictionary->skillBonus("thing", 10), "One for one skill of 10 returns a 10 bonus");
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

    ExpectTrue(Dictionary->addSkill("thing", newSkill));
    ExpectEq(5, Dictionary->skillBonus("thing", 32), "One for one skill of 32 returns a 5 bonus");
}

/////////////////////////////////////////////////////////////////////////////
void CanAdvanceSkillReturnsCorrectly()
{
    object skillOwner = clone_object("/lib/modules/attributes");

    skillOwner->Dex(20);

    ExpectFalse(Dictionary->canAdvanceSkill(skillOwner, "dodge", -5), "cannot advance skill negatively");
    ExpectFalse(Dictionary->canAdvanceSkill(skillOwner, "dodge", 0), "cannot advance skill by 0");
    ExpectTrue(Dictionary->canAdvanceSkill(skillOwner, "dodge", 10), "can advance when skill lower than attribute");
    ExpectFalse(Dictionary->canAdvanceSkill(skillOwner, "dodge", 31), "cannot advance when skill higher than attribute+10");
}


