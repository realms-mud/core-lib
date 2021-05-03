//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Attacker;
object Target;
object Room;

/////////////////////////////////////////////////////////////////////////////
void SetUpAttacker()
{
    Attacker = clone_object("/lib/tests/support/services/combatWithMockServices");
    Attacker.Name("Bob");
    Attacker.Str(20);
    Attacker.Dex(20);
    Attacker.Con(20);
    Attacker.Int(20);
    Attacker.Wis(20);
}

/////////////////////////////////////////////////////////////////////////////
void SetUpTarget()
{
    Target = clone_object("/lib/tests/support/services/testMonster.c");
    Target.Name("Nukulevee");
    Target.Race("undead horse");
    Target.effectiveLevel(20);
    Target.Str(20);
    Target.Dex(20);
    Target.Con(20);
    Target.Int(20);
    Target.Wis(20);
}

/////////////////////////////////////////////////////////////////////////////
object CreateWeapon(string name)
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", name);
    weapon.set("defense class", 2);
    weapon.set("weapon class", 10);
    weapon.set("bonus hit points", 2);
    weapon.set("material", "galvorn");
    weapon.set("weapon type", "long sword");
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Attacker);

    return weapon;
}

/////////////////////////////////////////////////////////////////////////////
object CreateShield(string name)
{
    object shield = clone_object("/lib/items/weapon");
    shield.set("name", name);
    shield.set("defense class", 1);
    shield.set("bonus constitution", 3);
    shield.set("material", "steel");
    shield.set("craftsmanship", 20);
    shield.set("equipment locations", Shield);
    shield.set("weapon type", "shield");
    move_object(shield, Attacker);

    return shield;
}

/////////////////////////////////////////////////////////////////////////////
object CreateArmor(string name)
{
    object armor = clone_object("/lib/items/armor");
    armor.set("name", name);
    armor.set("bonus hit points", 4);
    armor.set("armor class", 5);
    armor.set("armor type", "chainmail");
    armor.set("equipment locations", Armor);
    move_object(armor, Attacker);

    return armor;
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "SetUpAttacker", "SetUpTarget", "CreateWeapon", "CreateArmor",
        "CreateShield" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    SetUpAttacker();
    SetUpTarget();
    Room = clone_object("/lib/tests/support/environment/fakeCombatRoom");
    move_object(Attacker, Room);
    move_object(Target, Room);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Room);
    destruct(Target);
    destruct(Attacker);
}

/////////////////////////////////////////////////////////////////////////////
void CalculateDefendAttackUsesCorrectAttributeBonuses()
{
    // 2 for dexterity of 20 and 2 for wisdom of 20
    ExpectEq(4, Attacker.calculateDefendAttack());

    Attacker.ToggleMockResearch();

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus dexterity", 4);

    ExpectEq(1, modifier.set("registration list", ({ Attacker })), "registration list can be set");
    ExpectEq(9, Attacker.calculateDefendAttack());
}

/////////////////////////////////////////////////////////////////////////////
void CalculateDefendAttackUsesCorrectPrimaryWeaponData()
{
    object weapon = CreateWeapon("blah");

    Attacker.addSkillPoints(100);

    ExpectEq(4, Attacker.calculateDefendAttack(), "nothing is equipped");

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectEq(-11, Attacker.calculateDefendAttack(), "weapon with dc of 2 is equipped");

    Attacker.advanceSkill("long sword", 1);
    ExpectEq(0, Attacker.calculateDefendAttack(), "weapon with dc of 2 is equipped");

    Attacker.advanceSkill("long sword", 8);
    ExpectEq(5, Attacker.calculateDefendAttack(), "weapon with dc of 2 is equipped and skill of 9");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateDefendAttackHandlesSkillPenalty()
{
    object weapon = CreateWeapon("blah");
    weapon.set("skill penalty", 1);
    Attacker.addSkillPoints(100);

    ExpectEq(4, Attacker.calculateDefendAttack(), "nothing is equipped");

    ExpectTrue(weapon.equip("blah offhand"), "weapon equip called");
    ExpectEq(-13, Attacker.calculateDefendAttack(), "weapon with dc of 2 is equipped");

    Attacker.advanceSkill("long sword", 1);
    ExpectEq(-2, Attacker.calculateDefendAttack(), "weapon with dc of 2 is equipped");

    Attacker.advanceSkill("long sword", 8);
    ExpectEq(3, Attacker.calculateDefendAttack(), "weapon with dc of 2 is equipped and skill of 9");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateDefendAttackHandlesBlindness()
{
    destruct(Attacker);
    Attacker = clone_object("/lib/realizations/player.c");
    Attacker.Name("Bob");
    Attacker.Str(20);
    Attacker.Dex(20);
    Attacker.Con(20);
    Attacker.Int(20);
    Attacker.Wis(20);
    move_object(Attacker, Room);

    object weapon = CreateWeapon("blah");
    weapon.set("skill penalty", 1);
    Attacker.addSkillPoints(100);
    ExpectTrue(Attacker.addTrait("/lib/instances/traits/diseases/cataracts.c"));

    ExpectEq(-21, Attacker.calculateDefendAttack(), "nothing is equipped");

    ExpectTrue(weapon.equip("blah offhand"), "weapon equip called");
    ExpectEq(-38, Attacker.calculateDefendAttack(), "weapon with dc of 2 is equipped");

    Attacker.advanceSkill("long sword", 1);
    ExpectEq(-27, Attacker.calculateDefendAttack(), "weapon with dc of 2 is equipped");

    Attacker.advanceSkill("blind fighting", 10);
    ExpectEq(-6, Attacker.calculateDefendAttack(), "weapon with dc of 2 is equipped and skill of 9");
}


/////////////////////////////////////////////////////////////////////////////
void CalculateDefendAttackUsesCorrectOffhandWeaponData()
{
    object weapon = CreateWeapon("blah");

    Attacker.addSkillPoints(100);

    ExpectEq(4, Attacker.calculateDefendAttack(), "nothing is equipped");

    ExpectTrue(weapon.equip("blah offhand"), "weapon equip called");
    ExpectEq(-11, Attacker.calculateDefendAttack(), "weapon with dc of 2 is equipped");

    Attacker.advanceSkill("long sword", 1);
    ExpectEq(0, Attacker.calculateDefendAttack(), "weapon with dc of 2 is equipped");

    Attacker.advanceSkill("long sword", 8);
    ExpectEq(5, Attacker.calculateDefendAttack(), "weapon with dc of 2 is equipped and skill of 9");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateDefendAttackUsesCorrectShieldData()
{
    object shield = CreateShield("shield");

    Attacker.addSkillPoints(100);
    Attacker.advanceSkill("shield", 1);

    ExpectEq(4, Attacker.calculateDefendAttack(), "nothing is equipped");

    // If your skill can't overcome the encumberance, it's a bad thing.
    ExpectTrue(shield.equip("shield offhand"), "shield equip called");
    ExpectEq(3, Attacker.calculateDefendAttack(), "shield of dc 1 with skill of 1 equipped");

    Attacker.advanceSkill("shield", 5);
    ExpectEq(12, Attacker.calculateDefendAttack(), "shield skill increased");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateDefendAttackUsesCorrectArmorData()
{
    object armor = CreateArmor("stuff");
    armor.set("material", "galvorn");
    armor.set("craftsmanship", 40);

    Attacker.addSkillPoints(200);

    ExpectEq(4, Attacker.calculateDefendAttack(), "nothing is equipped");

    ExpectTrue(armor.equip("stuff"), "armor equip called");
    // Wearing heavier armor untrained is kinda a bad thing... it'll block, but 
    // you'll get hit. The untrained penalty for chainmail is -20. There is also 
    // an encumberance penalty based on both the item type (-10) and material (-2) 
    ExpectEq(-38, Attacker.calculateDefendAttack());

    // Now, there is no negative for not knowing "how to wear" the armor, but there's still
    // the other penalties.
    Attacker.advanceSkill("chainmail", 1);
    ExpectEq(-16, Attacker.calculateDefendAttack());

    Attacker.advanceSkill("chainmail", 14);
    ExpectEq(-6, Attacker.calculateDefendAttack());
}

/////////////////////////////////////////////////////////////////////////////
void CalculateDefendAttackUsesCorrectModifierData()
{
    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus defense class", 3);
    modifier.set("bonus dexterity", 4);

    ExpectEq(4, Attacker.calculateDefendAttack(), "nothing is equipped");
    ExpectEq(1, modifier.set("registration list", ({ Attacker })), "registration list can be set");
    ExpectEq(8, Attacker.calculateDefendAttack());
}

/////////////////////////////////////////////////////////////////////////////
void CalculateDefendAttackCorrectlyAppliesDisease()
{
    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus defense class", 10);

    ExpectEq(4, Attacker.calculateDefendAttack(), "nothing is equipped");
    ExpectEq(1, modifier.set("registration list", ({ Attacker })), "registration list can be set");
    ExpectEq(14, Attacker.calculateDefendAttack(), "before disease is applied");
    modifier.set("disease", 1);
    ExpectEq(1, modifier.set("registration list", ({ Attacker })), "registration list can be set");
    ExpectEq(13, Attacker.calculateDefendAttack(), "disease applied");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateDefendAttackCorrectlyAppliesMagicalDefendAttackBonus()
{
    ExpectEq(4, Attacker.calculateDefendAttack(), "nothing is equipped");
    Attacker.ToggleMagicalDefendAttackBonus();
    ExpectEq(9, Attacker.calculateDefendAttack(), "magical defend method called");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateDefendAttackUsesCorrectServiceBonuses()
{
    ExpectEq(4, Attacker.calculateDefendAttack(), "base from attributes");
    Attacker.ToggleMockGuilds();
    ExpectEq(9, Attacker.calculateDefendAttack(), "guild modifier is active");
    Attacker.ToggleMockResearch();
    ExpectEq(13, Attacker.calculateDefendAttack(), "research modifier is active");
    Attacker.ToggleMockTrait();
    ExpectEq(15, Attacker.calculateDefendAttack(), "trait modifier is active");
    Attacker.ToggleMockBackground();
    ExpectEq(17, Attacker.calculateDefendAttack(), "background modifier is active");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateDefendAttackUsesCorrectInventoryData()
{
    object weapon = CreateWeapon("blah");
    object shield = CreateShield("shield");
    object armor = CreateArmor("stuff");
    armor.set("material", "steel");
    armor.set("craftsmanship", 20);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus defense class", 3);
    modifier.set("bonus chainmail", 4);
    modifier.set("bonus dexterity", 6);

    Attacker.addSkillPoints(100);
    Attacker.advanceSkill("shield", 1);
    Attacker.advanceSkill("long sword", 1);

    ExpectEq(4, Attacker.calculateDefendAttack(), "nothing is equipped");

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectEq(0, Attacker.calculateDefendAttack(), "weapon with dc of 2 is equipped");

    Attacker.advanceSkill("long sword", 8);
    ExpectEq(5, Attacker.calculateDefendAttack(), "weapon with dc of 2 is equipped and skill of 9");

    ExpectTrue(shield.equip("shield offhand"), "shield equip called");
    ExpectEq(4, Attacker.calculateDefendAttack(), "shield of dc 1 with skill of 1 equipped");
    Attacker.advanceSkill("shield", 5);
    ExpectEq(13, Attacker.calculateDefendAttack(), "shield skill increased");

    ExpectTrue(armor.equip("stuff"), "armor equip called");
    ExpectEq(-27, Attacker.calculateDefendAttack(), "armor equipped");

    Attacker.advanceSkill("chainmail", 1);
    ExpectEq(-5, Attacker.calculateDefendAttack(), "chainmail skill increased to 1");
    Attacker.advanceSkill("chainmail", 10);
    ExpectEq(1, Attacker.calculateDefendAttack(), "chainmail skill increased by 10");

    ExpectEq(1, modifier.set("registration list", ({ Attacker })), "registration list can be set");
    ExpectEq(10, Attacker.calculateDefendAttack(), "modifier object added");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateAttackWithWeaponCorrectlyAppliesWeaponData()
{
    object weapon = CreateWeapon("blah");

    Attacker.addSkillPoints(100);

    ExpectEq(0, Attacker.calculateAttack(Target, weapon, 1), "initial attack");
    ExpectTrue(weapon.equip("blah"), "weapon equip called");

    // This includes: -4 for defender's defend attack, 2 dexterity bonus, 
    // 2 intelligence bonus, -20 for attacking untrained with longsword, 
    // -7 weapon encumberance (materials (-2) plus lack of skill (-5)),
    // 5 for weapon attack and 5 for galvorn's attack bonus
    ExpectEq(-17, Attacker.calculateAttack(Target, weapon, 1), "untrained attack");
    
    Attacker.advanceSkill("long sword", 1);
    ExpectEq(5, Attacker.calculateAttack(Target, weapon, 1), "trained attack");

    Attacker.advanceSkill("long sword", 10);
    ExpectEq(15, Attacker.calculateAttack(Target, weapon, 1), "trained to 10 attack");

    ExpectTrue(weapon.unequip("blah"), "weapon equip called");
    weapon.set("bonus attack", 3);
    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectEq(18, Attacker.calculateAttack(Target, weapon, 1), "bonus attack applied");

    ExpectTrue(weapon.unequip("blah"), "weapon equip called");
    weapon.set("bonus dexterity", 2);
    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectEq(19, Attacker.calculateAttack(Target, weapon, 1), "bonus dexterity applied");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateAttackWithWeaponCorrectlyAppliesSkillPenalty()
{
    object weapon = CreateWeapon("blah");
    weapon.set("skill penalty", 1);

    Attacker.addSkillPoints(100);

    ExpectEq(0, Attacker.calculateAttack(Target, weapon, 1), "initial attack");
    ExpectTrue(weapon.equip("blah"), "weapon equip called");

    // This includes: -4 for defender's defend attack, 2 dexterity bonus, 
    // 2 intelligence bonus, -20 for attacking untrained with longsword, 
    // -7 weapon encumberance (materials (-2) plus lack of skill (-5)),
    // -1 for the skill penalty, 5 for weapon attack and 5 for 
    // galvorn's attack bonus
    ExpectEq(-19, Attacker.calculateAttack(Target, weapon, 1), "untrained attack");

    Attacker.advanceSkill("long sword", 1);
    ExpectEq(3, Attacker.calculateAttack(Target, weapon, 1), "trained attack");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateAttackWithDualWieldWeaponCorrectlyAppliesWeaponData()
{
    object weapon = CreateWeapon("blah");
    object offhand = CreateWeapon("blarg");

    Attacker.addSkillPoints(100);

    ExpectEq(0, Attacker.calculateAttack(Target, weapon, 1), "initial attack");
    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectTrue(offhand.equip("blarg offhand"), "offhand weapon equip called");

    // This includes: -4 for defender's defend attack, 2 dexterity bonus, 
    // 2 intelligence bonus, -20 for attacking untrained with longsword, 
    // -14 weapon encumberance (materials (-4) plus regular (-10)),
    // 5 for galvorn's attack bonus, -5 for untrained dual wield, and -5 for
    // base primary weapon dual wield penalty, 4 for attribute bonus for skill,
    // and 5 for weapon attack
    ExpectEq(-44, Attacker.calculateAttack(Target, weapon, 1), "untrained attack");
    ExpectEq(-49, Attacker.calculateAttack(Target, offhand, 1), "untrained offhand attack");

    Attacker.advanceSkill("dual wield", 1);
    ExpectEq(-38, Attacker.calculateAttack(Target, weapon, 1), "dual wield attack");
    ExpectEq(-43, Attacker.calculateAttack(Target, offhand, 1), "dual wield offhand attack");

    Attacker.advanceSkill("dual wield", 9);
    ExpectEq(-33, Attacker.calculateAttack(Target, weapon, 1), "dual wield attack");
    ExpectEq(-38, Attacker.calculateAttack(Target, offhand, 1), "dual wield offhand attack");

    Attacker.advanceSkill("long sword", 10);
    ExpectEq(15, Attacker.calculateAttack(Target, weapon, 1), "trained to 10 attack");
    ExpectEq(10, Attacker.calculateAttack(Target, offhand, 1), "trained to 10 attack - offhand");

    ExpectTrue(weapon.unequip("blah"), "weapon equip called");
    weapon.set("bonus attack", 3);
    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectEq(18, Attacker.calculateAttack(Target, weapon, 1), "bonus attack applied");
    ExpectEq(10, Attacker.calculateAttack(Target, offhand, 1), "bonus has no effect on offhand");

    ExpectTrue(weapon.unequip("blah"), "weapon equip called");
    weapon.set("bonus dexterity", 2);
    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectEq(19, Attacker.calculateAttack(Target, weapon, 1), "bonus dexterity applied");
    ExpectEq(11, Attacker.calculateAttack(Target, offhand, 1), "bonus dexterity applied offhand");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateAttackWhileWearingArmorAppliesArmorModifiers()
{
    object weapon = CreateWeapon("blah");

    object armor = CreateArmor("stuff");
    armor.set("material", "steel");
    armor.set("craftsmanship", 20);

    Attacker.addSkillPoints(100);
    Attacker.advanceSkill("long sword", 12);

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectEq(17, Attacker.calculateAttack(Target, weapon, 1), "weapon equipped");

    ExpectTrue(armor.equip("stuff"), "armor equip called");
    ExpectEq(-13, Attacker.calculateAttack(Target, weapon, 1), "armor equipped");

    Attacker.advanceSkill("chainmail", 10);
    ExpectEq(1, Attacker.calculateAttack(Target, weapon, 1), "armor skill advanced");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateAttackUsesCorrectInventoryData()
{
    object weapon = CreateWeapon("blah");
    weapon.set("craftsmanship", 35);
    weapon.set("material", "iron");

    object shield = CreateShield("shield");

    object armor = CreateArmor("stuff");
    armor.set("material", "steel");
    armor.set("craftsmanship", 20);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus attack", 5);
    modifier.set("bonus dexterity", 2);
    modifier.set("bonus intelligence", 2);

    Attacker.addSkillPoints(100);
    Attacker.advanceSkill("shield", 1);
    Attacker.advanceSkill("long sword", 1);

    ExpectEq(0, Attacker.calculateAttack(Target, weapon, 1), "nothing is equipped");

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    // The sword is "masterwork" because the skill greatly exceeded that required.
    // This accounts for the bonus as the attack would otherwise be -5.
    ExpectEq(6, Attacker.calculateAttack(Target, weapon, 1), "weapon is equipped");

    Attacker.advanceSkill("long sword", 10);
    ExpectEq(15, Attacker.calculateAttack(Target, weapon, 1), "weapon is equipped and skill of 11");

    ExpectTrue(shield.equip("shield offhand"), "shield equip called");
    ExpectEq(11, Attacker.calculateAttack(Target, weapon, 1), "shield with skill of 1 equipped");
    Attacker.advanceSkill("shield", 5);
    ExpectEq(14, Attacker.calculateAttack(Target, weapon, 1), "shield skill increased");

    ExpectTrue(armor.equip("stuff"), "armor equip called");
    ExpectEq(-16, Attacker.calculateAttack(Target, weapon, 1), "armor equipped");

    Attacker.advanceSkill("chainmail", 1);
    ExpectEq(-5, Attacker.calculateAttack(Target, weapon, 1), "chainmail skill increased to 1");
    Attacker.advanceSkill("chainmail", 10);
    ExpectEq(-2, Attacker.calculateAttack(Target, weapon, 1), "chainmail skill increased by 10");

    ExpectEq(1, modifier.set("registration list", ({ Attacker })), "registration list can be set");
    ExpectEq(5, Attacker.calculateAttack(Target, weapon, 1), "modifier object added");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateAttackUsesCorrectServiceBonuses()
{
    object weapon = CreateWeapon("blah");

    Attacker.addSkillPoints(100);
    Attacker.advanceSkill("long sword", 12);
    ExpectTrue(weapon.equip("blah"), "weapon equip called");

    ExpectEq(17, Attacker.calculateAttack(Target, weapon, 1), "weapon is equipped");

    Attacker.ToggleMockGuilds();
    ExpectEq(24, Attacker.calculateAttack(Target, weapon, 1), "guild modifier is active");
    Attacker.ToggleMockResearch();
    ExpectEq(29, Attacker.calculateAttack(Target, weapon, 1), "research modifier is active");
    Attacker.ToggleMockTrait();
    ExpectEq(32, Attacker.calculateAttack(Target, weapon, 1), "trait modifier is active");
    Attacker.ToggleMockBackground();
    ExpectEq(35, Attacker.calculateAttack(Target, weapon, 1), "background modifier is active");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateAttackUsesHandlesBlindness()
{
    destruct(Attacker);
    Attacker = clone_object("/lib/realizations/player.c");
    Attacker.Name("Bob");
    Attacker.Str(20);
    Attacker.Dex(20);
    Attacker.Con(20);
    Attacker.Int(20);
    Attacker.Wis(20);
    move_object(Attacker, Room);

    object weapon = CreateWeapon("blah");
    Attacker.addSkillPoints(100);
    Attacker.advanceSkill("long sword", 5);
    ExpectTrue(weapon.equip("blah"), "weapon equip called");

    ExpectEq(9, Attacker.calculateAttack(Target, weapon, 1), "weapon is equipped");

    ExpectTrue(Attacker.addTrait("/lib/instances/traits/diseases/cataracts.c"));
    ExpectEq(-16, Attacker.calculateAttack(Target, weapon, 1), "attacker is blind!");

    Attacker.advanceSkill("blind fighting", 10);
    ExpectEq(-2, Attacker.calculateDefendAttack(), "blind fighting skill added");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateAttackDecreasesAttackForDisease()
{
    object weapon = CreateWeapon("blah");

    Attacker.addSkillPoints(100);
    Attacker.advanceSkill("long sword", 12);
    ExpectTrue(weapon.equip("blah"), "weapon equip called");

    ExpectEq(17, Attacker.calculateAttack(Target, weapon, 1), "weapon is equipped");

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("disease", 1);

    ExpectEq(1, modifier.set("registration list", ({ Attacker })), "registration list can be set");
    ExpectEq(15, Attacker.calculateAttack(Target, weapon, 1), "disease object added");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateAttackDecreasesAttackForEnfeebled()
{
    object weapon = CreateWeapon("blah");

    Attacker.addSkillPoints(100);
    Attacker.advanceSkill("long sword", 18);
    ExpectTrue(weapon.equip("blah"), "weapon equip called");

    ExpectEq(20, Attacker.calculateAttack(Target, weapon, 1), "weapon is equipped");

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("enfeebled", 1);

    ExpectEq(1, modifier.set("registration list", ({ Attacker })), "registration list can be set");
    ExpectEq(17, Attacker.calculateAttack(Target, weapon, 1), "enfeebled object added");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateAttackIncreasesAttackForFortified()
{
    object weapon = CreateWeapon("blah");

    Attacker.addSkillPoints(100);
    Attacker.advanceSkill("long sword", 18);
    ExpectTrue(weapon.equip("blah"), "weapon equip called");

    ExpectEq(20, Attacker.calculateAttack(Target, weapon, 1), "weapon is equipped");

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("fortified", 1);

    ExpectEq(1, modifier.set("registration list", ({ Attacker })), "registration list can be set");
    ExpectEq(22, Attacker.calculateAttack(Target, weapon, 1), "fortified object added");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateAttackCorrectlyAppliesMagicalAttackBonus()
{
    object weapon = CreateWeapon("blah");
    Attacker.addSkillPoints(100);
    Attacker.advanceSkill("long sword", 10);
    
    ExpectTrue(weapon.equip("blah"), "weapon equip called");

    Attacker.ToggleMagicalAttackBonus();
    ExpectEq(19, Attacker.calculateAttack(Target, weapon, 1), "magical attack method called");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateAttackCorrectlyAppliesAttackTypes()
{
    object weapon = clone_object("/lib/dictionaries/attacks/clawAttack.c");
    weapon.setAttackValues(10, 10);
    ExpectTrue(10 <= Attacker.calculateAttack(Target, weapon, 1));
}

/////////////////////////////////////////////////////////////////////////////
void CalculateAttackCanBeRandomized()
{
    object weapon = CreateWeapon("blah");

    Attacker.addSkillPoints(100);
    Attacker.advanceSkill("long sword", 18);
    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    
    // There is a very small chance that this test will fail due to identical
    // random numbers, so this calls up to 5 times to almost remove that risk
    int firstEval = Attacker.calculateAttack(Target, weapon);
    int compareEval = firstEval;
    for(int i = 0; (i < 5) && (firstEval == compareEval); i++)
    {
        compareEval = Attacker.calculateAttack(Target, weapon);
    }
    ExpectTrue(firstEval != compareEval);
}

/////////////////////////////////////////////////////////////////////////////
void CalculateSoakDamageCorrectlyAppliesMagicalDefenseBonus()
{
    // This includes 2 from con and 2 from str
    ExpectEq(4, Attacker.calculateSoakDamage("physical"), "nothing is equipped");
    Attacker.ToggleMagicalDefenseBonus();
    ExpectEq(6, Attacker.calculateSoakDamage("physical"), "magical defend method called");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateSoakDamageCorrectlyAppliesWhenWearingArmor()
{
    object armor = CreateArmor("stuff");
    armor.set("material", "steel");

    object gloves = clone_object("/lib/items/armor");
    gloves.set("name", "gloves");
    gloves.set("armor class", 1);
    gloves.set("material", "steel");
    gloves.set("armor type", "chainmail");
    gloves.set("equipment locations", Gloves);
    move_object(gloves, Attacker);

    Attacker.addSkillPoints(100);
    ExpectEq(4, Attacker.calculateSoakDamage("physical"), "armor not equipped");

    // +5 for AC and +1 for being made out of steel
    ExpectTrue(armor.equip("stuff"), "armor equip called");
    ExpectEq(10, Attacker.calculateSoakDamage("physical"), "armor equipped");

    armor.set("craftsmanship", 20);
    ExpectEq(10, Attacker.calculateSoakDamage("physical"), "craftsmanship bonus");

    ExpectTrue(gloves.equip("gloves"), "glove equip called");
    ExpectEq(11, Attacker.calculateSoakDamage("physical"), "gloves equipped");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateSoakDamageCorrectlyAppliesServiceBonuses()
{
    ExpectEq(4, Attacker.calculateSoakDamage("physical"), "initial case");

    Attacker.ToggleMockGuilds();
    ExpectEq(9, Attacker.calculateSoakDamage("physical"), "guild modifier is active");
    Attacker.ToggleMockResearch();
    ExpectEq(13, Attacker.calculateSoakDamage("physical"), "research modifier is active");
    Attacker.ToggleMockTrait();
    ExpectEq(15, Attacker.calculateSoakDamage("physical"), "trait modifier is active");
    Attacker.ToggleMockBackground();
    ExpectEq(17, Attacker.calculateSoakDamage("physical"), "background modifier is active");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateSoakDamageCorrectlyAppliesForInventory()
{
    object weapon = CreateWeapon("blah");
    weapon.set("bonus defense", 3);

    object armor = CreateArmor("stuff");
    armor.set("material", "steel");
    armor.set("craftsmanship", 30);

    object gloves = clone_object("/lib/items/armor");
    gloves.set("name", "gloves");
    gloves.set("armor class", 1);
    gloves.set("material", "steel");
    gloves.set("armor type", "chainmail");
    gloves.set("equipment locations", Gloves);
    move_object(gloves, Attacker);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus defense", 2);
    modifier.set("bonus constitution", 2);
    modifier.set("bonus strength", 2);

    Attacker.addSkillPoints(100);
    ExpectEq(4, Attacker.calculateSoakDamage("physical"), "armor not equipped");

    // +5 for AC, +1 for being made out of steel, and +1 for craftsmanship
    ExpectTrue(armor.equip("stuff"), "armor equip called");
    ExpectEq(11, Attacker.calculateSoakDamage("physical"), "craftsmanship bonus");

    ExpectTrue(gloves.equip("gloves"), "glove equip called");
    ExpectEq(12, Attacker.calculateSoakDamage("physical"), "gloves equipped");

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectEq(15, Attacker.calculateSoakDamage("physical"), "weapon equipped");

    ExpectEq(1, modifier.set("registration list", ({ Attacker })), "registration list can be set");
    ExpectEq(19, Attacker.calculateSoakDamage("physical"), "modifier registered");
}

/////////////////////////////////////////////////////////////////////////////
void ParalysisAffectsSoakDamage()
{
    object armor = CreateArmor("stuff");
    armor.set("material", "steel");
    armor.set("armor class", 10);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("paralysis", 1);

    ExpectTrue(armor.equip("stuff"), "armor equip called");
    ExpectEq(15, Attacker.calculateSoakDamage("physical"), "armor equipped");

    ExpectEq(1, modifier.set("registration list", ({ Attacker })), "registration list can be set");
    ExpectEq(13, Attacker.calculateSoakDamage("physical"), "modifier registered");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateDamageCorrectlyAppliesAttackTypes()
{
    object weapon = clone_object("/lib/dictionaries/attacks/clawAttack.c");
    weapon.setAttackValues(10, 10);
    ExpectTrue(14 <= Attacker.calculateDamage(weapon, weapon.getDamageType(), 1));
}

/////////////////////////////////////////////////////////////////////////////
void CalculateDamageCorrectlyAppliesMagicalDamageBonus()
{
    object weapon = CreateWeapon("blah");

    // 2 from str, 1 from int, and 1 from wis
    ExpectEq(4, Attacker.calculateDamage(weapon, "physical", 1), "nothing is equipped");
    Attacker.ToggleMagicalDamageBonus();
    ExpectEq(7, Attacker.calculateDamage(weapon, "physical", 1), "magical damage method called");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateDamageCorrectlyAppliesSkillPenalty()
{
    object weapon = CreateWeapon("blah");
    Attacker.addSkillPoints(100);
    Attacker.advanceSkill("long sword", 1);

    // 2 from str, 1 from int, and 1 from wis
    ExpectEq(4, Attacker.calculateDamage(weapon, "physical", 1), "nothing is equipped");

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectEq(22, Attacker.calculateDamage(weapon, "physical", 1), "no skill penalty applied");

    ExpectTrue(weapon.unequip("blah"), "weapon equip called");
    weapon.set("skill penalty", 2);
    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectEq(20, Attacker.calculateDamage(weapon, "physical", 1), "skill penalty applied");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateDamageReturnsTheCorrectDamageForWeapons()
{
    object weapon = CreateWeapon("blah");

    Attacker.addSkillPoints(100);
    Attacker.advanceSkill("long sword", 1);

    // 2 from str, 1 from int, and 1 from wis
    ExpectEq(4, Attacker.calculateDamage(weapon, "physical", 1), "No weapon equipped");
    ExpectTrue(weapon.equip("blah"), "weapon equip called");

    // wc is 10 and the bonus from galvorn is 8.
    ExpectEq(22, Attacker.calculateDamage(weapon, "physical", 1, "physical damage"));

    Attacker.advanceSkill("long sword", 11);
    ExpectEq(25, Attacker.calculateDamage(weapon, "physical", 1, "physical damage after skill increased"));

    ExpectEq(7, Attacker.calculateDamage(weapon, "magical", 1, "Only attribute and magical damage from galvorn are counted"));
}

/////////////////////////////////////////////////////////////////////////////
void CalculateDamageReturnsTheCorrectDamageForInventory()
{
    object weapon = CreateWeapon("blah");

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus damage", 5);
    modifier.set("enchantments", (["magical":3, "fire" : 10, "acid" : 10]));

    Attacker.addSkillPoints(100);
    Attacker.advanceSkill("long sword", 8);

    // 2 from str, 1 from int, and 1 from wis
    ExpectEq(4, Attacker.calculateDamage(weapon, "physical", 1), "No weapon equipped");
    ExpectEq(0, Attacker.calculateDamage(weapon, "magical", 1), "magical weapon equipped");

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectEq(1, modifier.set("registration list", ({ Attacker })), "registration list can be set");

    ExpectEq(29, Attacker.calculateDamage(weapon, "physical", 1), "total physical damage");
    ExpectEq(10, Attacker.calculateDamage(weapon, "magical", 1), "total magical damage");
    ExpectEq(12, Attacker.calculateDamage(weapon, "fire", 1), "total fire damage");
    ExpectEq(12, Attacker.calculateDamage(weapon, "acid", 1), "total acid damage");
    ExpectEq(0, Attacker.calculateDamage(weapon, "cold", 1), "total cold damage");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateDamageCorrectlyEnfeebles()
{
    object weapon = CreateWeapon("blah");

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("enfeebled", 5);

    Attacker.addSkillPoints(100);
    Attacker.advanceSkill("long sword", 8);

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectEq(24, Attacker.calculateDamage(weapon, "physical", 1), "weapon equipped");
    ExpectEq(1, modifier.set("registration list", ({ Attacker })), "registration list can be set");
    ExpectEq(18, Attacker.calculateDamage(weapon, "physical", 1), "total physical damage");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateDamageCorrectlyFortifies()
{
    object weapon = CreateWeapon("blah");

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("fortified", 5);

    Attacker.addSkillPoints(100);
    Attacker.advanceSkill("long sword", 8);

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectEq(24, Attacker.calculateDamage(weapon, "physical", 1), "weapon equipped");
    ExpectEq(1, modifier.set("registration list", ({ Attacker })), "registration list can be set");
    ExpectEq(30, Attacker.calculateDamage(weapon, "physical", 1), "total physical damage");
}
