//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
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
void MaxHitPointsWithConOf20Returns150()
{
    ExpectEq(150, Attacker.maxHitPoints());
}

/////////////////////////////////////////////////////////////////////////////
void InventoryCorrectlyAffectsMaxHitPoints()
{
    object weapon = CreateWeapon("blah");
    object shield = CreateShield("shield");
    object armor = CreateArmor("stuff");

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus hit points", 6);

    ExpectEq(150, Attacker.maxHitPoints(), "hit points still 150 until equipment equipped");

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectTrue(shield.equip("shield offhand"), "shield equip called");
    ExpectTrue(armor.equip("stuff"), "armor equip called");
    ExpectEq(1, modifier.set("registration list", ({ Attacker })), "registration list can be set");
    ExpectEq(180, Attacker.maxHitPoints(), "hit points 180 with equipment equipped");
    ExpectEq(12, Attacker.inventoryGetModifier("combatModifiers", "bonus hit points"));
}

/////////////////////////////////////////////////////////////////////////////
void MaxHitPointsCorrectlyAppliesRacialModifiers()
{
    Attacker.Race("dwarf");
    ExpectEq(187, Attacker.maxHitPoints());
}

/////////////////////////////////////////////////////////////////////////////
void MaxHitPointsCorrectlyAppliesGuildsModifiers()
{
    ExpectEq(150, Attacker.maxHitPoints());
    Attacker.ToggleMockGuilds();
    ExpectEq(155, Attacker.maxHitPoints());
}

/////////////////////////////////////////////////////////////////////////////
void MaxHitPointsCorrectlyAppliesResearchModifiers()
{
    ExpectEq(150, Attacker.maxHitPoints());
    Attacker.ToggleMockResearch();
    ExpectEq(164, Attacker.maxHitPoints());
}

/////////////////////////////////////////////////////////////////////////////
void MaxHitPointsCorrectlyAppliesTraitsModifiers()
{
    ExpectEq(150, Attacker.maxHitPoints());
    Attacker.ToggleMockTrait();

    // This should apply a +6 for a consititution attribute bonus and a +2 for the trait
    ExpectEq(158, Attacker.maxHitPoints());
}

/////////////////////////////////////////////////////////////////////////////
void MaxHitPointsCorrectlyAppliesBackgroundModifiers()
{
    ExpectEq(150, Attacker.maxHitPoints());
    Attacker.ToggleMockBackground();
    ExpectEq(152, Attacker.maxHitPoints());
}

/////////////////////////////////////////////////////////////////////////////
void MaxHitPointsCorrectlyAppliesAllModifiers()
{
    object weapon = CreateWeapon("blah");
    object shield = CreateShield("shield");
    object armor = CreateArmor("stuff");

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus hit points", 6);

    ExpectEq(150, Attacker.maxHitPoints(), "hit points still 150 until equipment equipped");

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectTrue(shield.equip("shield offhand"), "shield equip called");
    ExpectTrue(armor.equip("stuff"), "armor equip called");
    ExpectEq(1, modifier.set("registration list", ({ Attacker })), "registration list can be set");
    Attacker.Race("dwarf");
    Attacker.ToggleMockGuilds();
    Attacker.ToggleMockResearch();
    Attacker.ToggleMockTrait();
    Attacker.ToggleMockBackground();
    ExpectEq(246, Attacker.maxHitPoints());
}

/////////////////////////////////////////////////////////////////////////////
void HitPointsIncrementsSetValue()
{
    ExpectEq(0, Attacker.hitPoints());
    ExpectEq(50, Attacker.hitPoints(50));
    ExpectEq(50, Attacker.hitPoints());
    ExpectEq(100, Attacker.hitPoints(50));
    ExpectEq(100, Attacker.hitPoints());
}

/////////////////////////////////////////////////////////////////////////////
void HitPointsCapsAtMaxHitPoints()
{
    Attacker.Race("dwarf");
    Attacker.ToggleMockTrait();

    ExpectEq(0, Attacker.hitPoints());
    ExpectEq(195, Attacker.hitPoints(200));
    ExpectEq(195, Attacker.hitPoints());
    ExpectEq(195, Attacker.maxHitPoints());
}

/////////////////////////////////////////////////////////////////////////////
void HitPointsDoesNotDecreaseValue()
{
    ExpectEq(100, Attacker.hitPoints(100));
    ExpectEq(100, Attacker.hitPoints(-50));
}

/////////////////////////////////////////////////////////////////////////////
void HitPointsFiresOnHitPointsChangedEvent()
{
    load_object("/lib/dictionaries/environmentDictionary.c");

    ToggleCallOutBypass();
    ExpectEq(100, Attacker.hitPoints(100));

    object handler = clone_object("/lib/tests/support/events/mockEventSubscriber");
    ExpectTrue(Attacker.registerEvent(handler), "event handler registered");

    ExpectEq(100, Attacker.hitPoints());
    ExpectEq(100, Attacker.hitPoints(-50));

    string err = catch (ExpectEq(Attacker.hitPoints(100), "hit points increased"); nolog);
    ExpectEq("*event handler: onHitPointsChanged called", err, "onHitPointsChanged event fired");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void HealthDescriptionReturnsInGoodShapeWhenHealthy()
{
    Attacker.hitPoints(180);
    ExpectEq("is in good shape.", Attacker.healthDescription());
}

/////////////////////////////////////////////////////////////////////////////
void HealthDescriptionReturnsBarelyInjuredWhenNearFullHealth()
{
    Attacker.hitPoints(120);
    ExpectEq("is barely inured.", Attacker.healthDescription());
}

/////////////////////////////////////////////////////////////////////////////
void HealthDescriptionReturnsMinorInjuriesBelow75Percent()
{
    Attacker.hitPoints(100);
    ExpectEq("has some minor injuries.", Attacker.healthDescription());
}

/////////////////////////////////////////////////////////////////////////////
void HealthDescriptionReturnsRoughedUpBelow50Percent()
{
    Attacker.hitPoints(74);
    ExpectEq("has been roughed up.", Attacker.healthDescription());
}

/////////////////////////////////////////////////////////////////////////////
void HealthDescriptionReturnsTakenBeatingBelow25Percent()
{
    Attacker.hitPoints(36);
    ExpectEq("has taken a beating.", Attacker.healthDescription());
}

/////////////////////////////////////////////////////////////////////////////
void HealthDescriptionReturnsSeverelInjuredBelow13Percent()
{
    Attacker.hitPoints(14);
    ExpectEq("is severely injured.", Attacker.healthDescription());
}

/////////////////////////////////////////////////////////////////////////////
void HealthDescriptionReturnsSeverelInjuredBelow6Percent()
{
    Attacker.hitPoints(4);
    ExpectEq("is knocking on death's door.", Attacker.healthDescription());
}

/////////////////////////////////////////////////////////////////////////////
void MaxSpellPointsCorrectlyAppliesAllModifiers()
{
    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus intelligence", 2);
    modifier.set("bonus spell points", 10);

    ExpectEq(1, modifier.set("registration list", ({ Attacker })), "registration list can be set");
    ExpectEq(166, Attacker.maxSpellPoints());
    modifier.set("bonus wisdom", 1);
    Attacker.resetCaches();
    ExpectEq(169, Attacker.maxSpellPoints());
    Attacker.Race("elf");
    Attacker.resetCaches();
    // 25 for elf plus 3 for int
    ExpectEq(197, Attacker.maxSpellPoints());
    Attacker.ToggleMockGuilds();
    ExpectEq(202, Attacker.maxSpellPoints());
    Attacker.ToggleMockResearch();
    ExpectEq(216, Attacker.maxSpellPoints());
    Attacker.ToggleMockTrait();
    ExpectEq(224, Attacker.maxSpellPoints());
    Attacker.ToggleMockBackground();
    ExpectEq(226, Attacker.maxSpellPoints());
}

/////////////////////////////////////////////////////////////////////////////
void MaxStaminaPointsCorrectlyAppliesAllModifiers()
{
    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus strength", 2);
    modifier.set("bonus stamina points", 5);

    ExpectEq(1, modifier.set("registration list", ({ Attacker })), "registration list can be set");
    ExpectEq(161, Attacker.maxStaminaPoints());
    modifier.set("bonus constitution", 1);
    Attacker.resetCaches();

    ExpectEq(164, Attacker.maxStaminaPoints());
    Attacker.Race("dwarf");
    Attacker.resetCaches();

    // 25 for dwarf plus 3 for strength plus 6 for con
    ExpectEq(198, Attacker.maxStaminaPoints());
    Attacker.ToggleMockGuilds();
    ExpectEq(203, Attacker.maxStaminaPoints());
    Attacker.ToggleMockResearch();
    ExpectEq(217, Attacker.maxStaminaPoints());
    Attacker.ToggleMockTrait();
    ExpectEq(225, Attacker.maxStaminaPoints());
    Attacker.ToggleMockBackground();
    ExpectEq(227, Attacker.maxStaminaPoints());
}

/////////////////////////////////////////////////////////////////////////////
void SpellPointsIncrementsSetValue()
{
    ExpectEq(0, Attacker.spellPoints());
    ExpectEq(50, Attacker.spellPoints(50));
    ExpectEq(50, Attacker.spellPoints());
    ExpectEq(100, Attacker.spellPoints(50));
    ExpectEq(100, Attacker.spellPoints());
}

/////////////////////////////////////////////////////////////////////////////
void SpellPointsCapsAtMaxSpellPoints()
{
    Attacker.Race("elf");
    Attacker.ToggleMockTrait();

    ExpectEq(0, Attacker.spellPoints());
    ExpectEq(186, Attacker.spellPoints(200));
    ExpectEq(186, Attacker.spellPoints());
    ExpectEq(186, Attacker.maxSpellPoints());
}

/////////////////////////////////////////////////////////////////////////////
void SpellPointsIncreaseIncludesBonusRecoverSpellPoints()
{
    Attacker.Race("elf");
    Attacker.ToggleMockGuilds();
    Attacker.ToggleMockResearch();
    Attacker.ToggleMockTrait();
    Attacker.ToggleMockBackground();

    object armor = CreateArmor("stuff");
    armor.set("bonus recover spell points", 4);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus recover spell points", 1);

    ExpectTrue(armor.equip("stuff"), "armor equip called");
    ExpectEq(1, modifier.set("registration list", ({ Attacker })), "registration list can be set");

    ExpectEq(66, Attacker.spellPoints(50));
}

/////////////////////////////////////////////////////////////////////////////
void SpellPointsDecreaseIncludesBonusReduceSpellPoints()
{
    Attacker.spellPoints(100);

    Attacker.Race("elf");
    Attacker.ToggleMockGuilds();
    Attacker.ToggleMockResearch();
    Attacker.ToggleMockTrait();
    Attacker.ToggleMockBackground();

    object armor = CreateArmor("stuff");
    armor.set("bonus reduce spell points", 2);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus reduce spell points", 4);

    ExpectTrue(armor.equip("stuff"), "armor equip called");
    ExpectEq(1, modifier.set("registration list", ({ Attacker })), "registration list can be set");

    ExpectEq(97, Attacker.spellPoints(-20));
}

/////////////////////////////////////////////////////////////////////////////
void SpellPointsFiresOnSpellPointsChangedEvent()
{
    load_object("/lib/dictionaries/environmentDictionary.c");

    ToggleCallOutBypass();
    ExpectEq(100, Attacker.spellPoints(100));

    object handler = clone_object("/lib/tests/support/events/mockEventSubscriber");
    ExpectTrue(Attacker.registerEvent(handler), "event handler registered");

    ExpectEq(100, Attacker.spellPoints());

    string err = catch (ExpectEq(Attacker.spellPoints(-50), "spell points increased"); nolog);
    ExpectEq("*event handler: onSpellPointsChanged called", err, "onSpellPointsChanged event fired");

    err = catch (ExpectEq(Attacker.spellPoints(100), "spell points increased"); nolog);
    ExpectEq("*event handler: onSpellPointsChanged called", err, "onSpellPointsChanged event fired");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void StaminaPointsIncrementsSetValue()
{
    ExpectEq(0, Attacker.staminaPoints());
    ExpectEq(50, Attacker.staminaPoints(50));
    ExpectEq(50, Attacker.staminaPoints());
    ExpectEq(100, Attacker.staminaPoints(50));
    ExpectEq(100, Attacker.staminaPoints());
}

/////////////////////////////////////////////////////////////////////////////
void StaminaPointsCapsAtMaxStaminaPoints()
{
    Attacker.Race("dwarf");
    Attacker.ToggleMockTrait();

    ExpectEq(0, Attacker.staminaPoints(), "initial stamina points is zero");
    ExpectEq(192, Attacker.staminaPoints(200), "incrementing by 200 caps at maxStaminaPoints");
    ExpectEq(192, Attacker.staminaPoints(), "querying stamina returns expected result");
    ExpectEq(192, Attacker.maxStaminaPoints(), "max stamina matches");
}

/////////////////////////////////////////////////////////////////////////////
void StaminaPointsIncreaseIncludesBonusRecoverStaminaPoints()
{
    Attacker.Race("elf");
    Attacker.ToggleMockGuilds();
    Attacker.ToggleMockResearch();
    Attacker.ToggleMockTrait();
    Attacker.ToggleMockBackground();

    object armor = CreateArmor("stuff");
    armor.set("bonus recover stamina points", 4);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus recover stamina points", 1);

    ExpectTrue(armor.equip("stuff"), "armor equip called");
    ExpectEq(1, modifier.set("registration list", ({ Attacker })), "registration list can be set");

    ExpectEq(66, Attacker.staminaPoints(50));
}

/////////////////////////////////////////////////////////////////////////////
void StaminaPointsDecreaseIncludesBonusReduceStaminaPoints()
{
    Attacker.staminaPoints(100);

    Attacker.Race("elf");
    Attacker.ToggleMockGuilds();
    Attacker.ToggleMockResearch();
    Attacker.ToggleMockTrait();
    Attacker.ToggleMockBackground();

    object armor = CreateArmor("stuff");
    armor.set("bonus reduce stamina points", 2);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus reduce stamina points", 4);

    ExpectTrue(armor.equip("stuff"), "armor equip called");
    ExpectEq(1, modifier.set("registration list", ({ Attacker })), "registration list can be set");

    ExpectEq(97, Attacker.staminaPoints(-20));
}

/////////////////////////////////////////////////////////////////////////////
void StaminaPointsFiresOnStaminaPointsChangedEvent()
{
    load_object("/lib/dictionaries/environmentDictionary.c");

    ToggleCallOutBypass();
    ExpectEq(100, Attacker.staminaPoints(100));

    object handler = clone_object("/lib/tests/support/events/mockEventSubscriber");
    ExpectTrue(Attacker.registerEvent(handler), "event handler registered");

    ExpectEq(100, Attacker.staminaPoints());

    string err = catch (ExpectEq(Attacker.staminaPoints(-50), "stamina points increased"); nolog);
    ExpectEq("*event handler: onStaminaPointsChanged called", err, "onStaminaPointsChanged event fired");

    err = catch (ExpectEq(Attacker.staminaPoints(100), "stamina points increased"); nolog);
    ExpectEq("*event handler: onStaminaPointsChanged called", err, "onStaminaPointsChanged event fired");
    ToggleCallOutBypass();
}
