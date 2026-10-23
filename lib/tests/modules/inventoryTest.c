//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Inventory;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    getService("environment");

    Inventory = clone_object("/lib/tests/support/services/mockPlayer.c");
    Inventory.Name("Bob");
    Inventory.Gender("male");
    move_object(Inventory, this_object());
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Inventory);
}

/////////////////////////////////////////////////////////////////////////////
void IsEquippedReturnsTrueWhenItemIsEquipped()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    ExpectFalse(Inventory.isEquipped(weapon), "weapon is not equipped yet");
    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectTrue(Inventory.isEquipped(weapon), "weapon has been equipped");    
}

/////////////////////////////////////////////////////////////////////////////
void EquipmentInSlotReturnsNothingWhenSlotIsEmpty()
{
    ExpectFalse(Inventory.equipmentInSlot("wielded primary"), "weapon is not equipped");
}

/////////////////////////////////////////////////////////////////////////////
void EquipmentInSlotReturnsCorrectItemWhenSlotIsUsed()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectTrue(objectp(Inventory.equipmentInSlot("wielded primary")), "wielded primary has been equipped");
    ExpectEq("blah", Inventory.equipmentInSlot("wielded primary").query("name"), "wielded primary has correct name");
}

/////////////////////////////////////////////////////////////////////////////
void OffhandWeaponReturnsCorrectItemWhenSlotIsUsed()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    ExpectTrue(weapon.equip("blah offhand"), "weapon equip called offhand");
    ExpectFalse(objectp(Inventory.equipmentInSlot("wielded primary")), "wielded primary has not been equipped");
    ExpectTrue(objectp(Inventory.equipmentInSlot("wielded offhand")), "wielded offhand has been equipped");
    ExpectEq("blah", Inventory.equipmentInSlot("wielded offhand").query("name"), "wielded offhand has correct name");
}

/////////////////////////////////////////////////////////////////////////////
void TwoHandedWeaponReturnsCorrectItemWhenSlotIsUsed()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("equipment locations", TwohandedWeapon);
    move_object(weapon, Inventory);

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectTrue(objectp(Inventory.equipmentInSlot("wielded primary")), "wielded primary has been equipped");
    ExpectEq("blah", Inventory.equipmentInSlot("wielded primary").query("name"), "wielded primary has correct name");

    ExpectTrue(objectp(Inventory.equipmentInSlot("wielded offhand")), "wielded offhand has been equipped");
    ExpectEq("blah", Inventory.equipmentInSlot("wielded offhand").query("name"), "wielded offhand has correct name");
}

/////////////////////////////////////////////////////////////////////////////
void EquipmentInSlotResetToEmptyWhenSlotUnequipped()
{
    object armor = clone_object("/lib/items/armor");
    armor.set("name", "blah");
    armor.set("equipment locations", Gloves);
    move_object(armor, Inventory);

    ExpectTrue(armor.equip("blah"), "armor equip called");
    ExpectTrue(objectp(Inventory.equipmentInSlot("gloves")), "gloves has been equipped");
    ExpectTrue(armor.unequip("blah"), "armor unequip called");
    ExpectFalse(objectp(Inventory.equipmentInSlot("gloves")), "gloves has been unequipped");
}

/////////////////////////////////////////////////////////////////////////////
void EquipmentInMultipleSlotsReturnCorrectSlotUsed()
{
    object armor = clone_object("/lib/items/armor");
    armor.set("name", "blah");
    armor.set("equipment locations", Gloves | Armor | ArmGreaves | LegGreaves | Boots);
    move_object(armor, Inventory);

    ExpectTrue(armor.equip("blah"), "armor equip called");
    ExpectTrue(objectp(Inventory.equipmentInSlot("armor")), "armor has been equipped");
    ExpectTrue(objectp(Inventory.equipmentInSlot("arm greaves")), "arm greaves has been equipped");
    ExpectTrue(objectp(Inventory.equipmentInSlot("boots")), "boots has been equipped");
    ExpectTrue(objectp(Inventory.equipmentInSlot("gloves")), "gloves has been equipped");
    ExpectTrue(objectp(Inventory.equipmentInSlot("leg greaves")), "leg greaves has been equipped");

    ExpectTrue(armor.unequip("blah"), "armor unequip called");
    ExpectFalse(objectp(Inventory.equipmentInSlot("armor")), "armor has been equipped");
    ExpectFalse(objectp(Inventory.equipmentInSlot("arm greaves")), "arm greaves has been equipped");
    ExpectFalse(objectp(Inventory.equipmentInSlot("boots")), "boots has been equipped");
    ExpectFalse(objectp(Inventory.equipmentInSlot("gloves")), "gloves has been equipped");
    ExpectFalse(objectp(Inventory.equipmentInSlot("leg greaves")), "leg greaves has been equipped");
}

/////////////////////////////////////////////////////////////////////////////
void OnlyCorrectItemEquippedAndUnequipped()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    object armor = clone_object("/lib/items/armor");
    armor.set("name", "stuff");
    armor.set("equipment locations", Gloves);
    move_object(armor, Inventory);

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectTrue(objectp(Inventory.equipmentInSlot("wielded primary")), "wielded primary has been equipped");
    ExpectFalse(objectp(Inventory.equipmentInSlot("gloves")), "gloves have been equipped");

    ExpectTrue(armor.equip("stuff"), "armor equip called");
    ExpectEq("blah", Inventory.equipmentInSlot("wielded primary").query("name"), "wielded primary has correct name");
    ExpectEq("stuff", Inventory.equipmentInSlot("gloves").query("name"), "wielded primary has correct name");

    ExpectTrue(weapon.unequip("blah"), "weapon unequip called");
    ExpectFalse(Inventory.equipmentInSlot("wielded primary"), "wielded primary has correct name");
    ExpectEq("stuff", Inventory.equipmentInSlot("gloves").query("name"), "wielded primary has correct name");
}

/////////////////////////////////////////////////////////////////////////////
void EquipEventHandlerTriggersOnEquip()
{
    ToggleCallOutBypass();
    object armor = clone_object("/lib/tests/support/items/mockArmorWithEvents");
    armor.set("name", "blah");
    armor.set("equipment locations", Gloves);
    armor.set("register event handler", 1);
    move_object(armor, Inventory);

    string err = catch (ExpectTrue(armor.equip("blah"), "armor equip called"); nolog);
    ExpectEq("*event handler: onEquip called", err, "onEquip event fired");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void UnequipEventHandlerTriggersOnUnequip()
{
    ToggleCallOutBypass();
    object armor = clone_object("/lib/tests/support/items/mockArmorWithEvents");
    armor.set("name", "blah");
    armor.set("equipment locations", Gloves);
    move_object(armor, Inventory);
    armor.set("register event handler", 1);

    catch (ExpectTrue(armor.equip("blah"), "armor equip called"); nolog);

    armor.set("register event handler", 1);
    string err = catch (ExpectTrue(armor.unequip("blah"), "armor unequip called"); nolog);
    ExpectEq("*event handler: onUnequip called", err, "onUnequip event fired");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void RegisteredInventoryObjectReturnsCorrectObject()
{
    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");

    ExpectEq(1, modifier.set("registration list", ({ Inventory })), "registration list can be set");

    ExpectTrue(Inventory.registeredInventoryObject("blah"), "modifier with correct FQN is registered");
    ExpectEq("blah", Inventory.registeredInventoryObject("blah").query("fully qualified name"), "modifier has the correct name");
}

/////////////////////////////////////////////////////////////////////////////
void UnregisteredInventoryObjectRemovesCorrectRegisteredObject()
{
    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");

    ExpectEq(1, modifier.set("registration list", ({ Inventory })), "registration list can be set");

    ExpectTrue(Inventory.registeredInventoryObject("blah"), "modifier with correct FQN is registered");
    ExpectEq("blah", Inventory.registeredInventoryObject("blah").query("fully qualified name"), "modifier has the correct name");

    ExpectTrue(modifier.unregisterModifierFromTargetList(), "unregister modifier");
    ExpectFalse(Inventory.registeredInventoryObject("blah"), "modifier object not in inventory");
}

/////////////////////////////////////////////////////////////////////////////
void CanHaveMultipleRegisteredObjects()
{
    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");

    object modifier2 = clone_object("/lib/items/modifierObject");
    modifier2.set("fully qualified name", "stuff");

    ExpectEq(1, modifier.set("registration list", ({ Inventory })), "registration list can be set");
    ExpectEq(1, modifier2.set("registration list", ({ Inventory })), "registration list can be set");

    ExpectTrue(Inventory.registeredInventoryObject("blah"), "modifier with correct FQN is registered");
    ExpectEq("blah", Inventory.registeredInventoryObject("blah").query("fully qualified name"), "modifier has the correct name");

    ExpectTrue(Inventory.registeredInventoryObject("stuff"), "modifier with correct FQN is registered");
    ExpectEq("stuff", Inventory.registeredInventoryObject("stuff").query("fully qualified name"), "modifier has the correct name");

    ExpectTrue(modifier.unregisterModifierFromTargetList(), "unregister modifier");
    ExpectFalse(Inventory.registeredInventoryObject("blah"), "modifier object not in inventory");
    ExpectTrue(Inventory.registeredInventoryObject("stuff"), "modifier with correct FQN is registered");
}

/////////////////////////////////////////////////////////////////////////////
void RegisterEventHandlerTriggersOnRegister()
{
    ToggleCallOutBypass();
    object modifier = clone_object("/lib/tests/support/items/mockModifierObjWithEvents");
    modifier.set("register event handler", 1);
    modifier.set("fully qualified name", "blah");

    string err = catch (ExpectEq(1, modifier.set("registration list", ({ Inventory })), "registration list can be set"); nolog);
    ExpectEq("*event handler: onRegisterItem called", err, "onRegisterItem event fired");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void UnregisterEventHandlerTriggersOnUnregister()
{
    ToggleCallOutBypass();
    object modifier = clone_object("/lib/tests/support/items/mockModifierObjWithEvents");
    modifier.set("register event handler", 1);
    modifier.set("fully qualified name", "blah");
  
    object *list = ({ Inventory });
    catch (ExpectEq(1, modifier.set("registration list", list), "registration list can be set"); nolog);

    string err = catch (ExpectTrue(modifier.unregisterModifierFromTargetList(), "unregister modifier"); nolog);
    ExpectEq("*event handler: onUnregisterItem called", err, "onUnregisterItem event fired");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void InventoryGetModifierReturnsCorrectValue()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("bonus dodge", 2);
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    object armor = clone_object("/lib/items/armor");
    armor.set("name", "stuff");
    armor.set("bonus dodge", 3);
    armor.set("equipment locations", Gloves);
    move_object(armor, Inventory);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus dodge", 4);

    ExpectEq(0, Inventory.inventoryGetModifier("bonusSkills", "bonus dodge"), "initial dodge");

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectEq(2, Inventory.inventoryGetModifier("bonusSkills", "bonus dodge"), "dodge with weapon");

    ExpectTrue(armor.equip("stuff"), "armor equip called");
    ExpectEq(5, Inventory.inventoryGetModifier("bonusSkills", "bonus dodge"), "dodge with weapon and armor");

    ExpectEq(1, modifier.set("registration list", ({ Inventory })), "registration list can be set");
    ExpectEq(9, Inventory.inventoryGetModifier("bonusSkills", "bonus dodge"), "dodge with everything");
}

/////////////////////////////////////////////////////////////////////////////
void InventoryAttributeBonusReturnsCorrectValue()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("bonus strength", 1);
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    object armor = clone_object("/lib/items/armor");
    armor.set("name", "stuff");
    armor.set("bonus strength", 2);
    armor.set("equipment locations", Gloves);
    move_object(armor, Inventory);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus strength", 3);

    ExpectEq(0, Inventory.inventoryAttributeBonus("strength"), "initial strength bonus");

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectEq(1, Inventory.inventoryAttributeBonus("strength"), "strength with weapon");

    ExpectTrue(armor.equip("stuff"), "armor equip called");
    ExpectEq(3, Inventory.inventoryAttributeBonus("strength"), "strength with weapon and armor");

    ExpectEq(1, modifier.set("registration list", ({ Inventory })), "registration list can be set");
    ExpectEq(6, Inventory.inventoryAttributeBonus("strength"), "strength with everything");
}

/////////////////////////////////////////////////////////////////////////////
void InventoryGetArmorClassReturnsCorrectValue()
{
    object armor = clone_object("/lib/items/armor");
    armor.set("name", "stuff");
    armor.set("armor class", 5);
    armor.set("equipment locations", Armor);
    move_object(armor, Inventory);

    object gloves = clone_object("/lib/items/armor");
    gloves.set("name", "blah");
    gloves.set("armor class", 2);
    gloves.set("equipment locations", Gloves);
    move_object(gloves, Inventory);

    ExpectEq(0, Inventory.inventoryGetArmorClass(), "initial ac bonus");

    ExpectTrue(gloves.equip("blah"), "gloves equip called");
    ExpectEq(2, Inventory.inventoryGetArmorClass(), "ac with gloves");

    ExpectTrue(armor.equip("stuff"), "armor equip called");
    ExpectEq(7, Inventory.inventoryGetArmorClass(), "ac with gloves and armor");
}

/////////////////////////////////////////////////////////////////////////////
void InventoryGetDefenseBonusReturnsCorrectValue()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("bonus defense", 2);
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    object armor = clone_object("/lib/items/armor");
    armor.set("name", "stuff");
    armor.set("bonus defense", 2);
    armor.set("armor class", 5);
    armor.set("material", "steel");
    armor.set("equipment locations", Armor);
    move_object(armor, Inventory);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus defense", 3);

    ExpectEq(0, Inventory.inventoryGetDefenseBonus("physical"), "initial defense bonus");

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectEq(2, Inventory.inventoryGetDefenseBonus("physical"), "defense with weapon");

    ExpectTrue(armor.equip("stuff"), "armor equip called");
    ExpectEq(10, Inventory.inventoryGetDefenseBonus("physical"), "defense with weapon and armor");

    ExpectEq(1, modifier.set("registration list", ({ Inventory })), "registration list can be set");
    ExpectEq(13, Inventory.inventoryGetDefenseBonus("physical"), "defense with everything");
}

/////////////////////////////////////////////////////////////////////////////
void InventoryGetEncumberanceReturnsCorrectValue()
{
    Inventory.addSkillPoints(100);
    Inventory.Str(20);

    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("encumberance", 2);
    weapon.set("material", "steel");
    weapon.set("weapon type", "long sword");
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    object shield = clone_object("/lib/items/weapon");
    shield.set("name", "shield");
    shield.set("defense class", 1);
    shield.set("material", "lunarite");
    shield.set("equipment locations", Shield);
    shield.set("weapon type", "shield");
    move_object(shield, Inventory);

    object armor = clone_object("/lib/items/armor");
    armor.set("name", "stuff");
    armor.set("encumberance", 5);
    armor.set("material", "steel");
    armor.set("armor type", "chainmail");
    armor.set("equipment locations", Armor);
    move_object(armor, Inventory);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus chainmail", 6);

    ExpectEq(0, Inventory.inventoryGetEncumberance(), "initial encumberance");

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectEq(12, Inventory.inventoryGetEncumberance(), "encumberance with weapon");

    Inventory.advanceSkill("long sword", 8);
    ExpectEq(0, Inventory.inventoryGetEncumberance(), "encumberance with weapon and skill 8");

    ExpectTrue(armor.equip("stuff"), "armor equip called");
    ExpectEq(15, Inventory.inventoryGetEncumberance(), "encumberance with weapon and armor");

    Inventory.advanceSkill("chainmail", 8);
    ExpectEq(2, Inventory.inventoryGetEncumberance(), "encumberance with chainmail trained");

    ExpectEq(1, modifier.set("registration list", ({ Inventory })), "registration list can be set");
    ExpectEq(0, Inventory.inventoryGetEncumberance(), "encumberance with everything");

    ExpectTrue(shield.equip("shield offhand"), "shield equip called");
    ExpectEq(11, Inventory.inventoryGetEncumberance(), "encumberance with shield");

    Inventory.advanceSkill("shield", 8);
    ExpectEq(0, Inventory.inventoryGetEncumberance(), "encumberance with shield and skill at 8");
}

/////////////////////////////////////////////////////////////////////////////
void InventoryGetDefendAttackAppliesOffhandSkillPenalty()
{
    Inventory.addSkillPoints(100);
    Inventory.Str(40);
    Inventory.advanceSkill("shield", 6);

    object shield = clone_object("/lib/items/weapon");
    shield.set("name", "shield");
    shield.set("defense class", 1);
    shield.set("material", "steel");
    shield.set("craftsmanship", 20);
    shield.set("equipment locations", Shield);
    shield.set("weapon type", "shield");
    move_object(shield, Inventory);

    ExpectEq(0, Inventory.inventoryGetDefendAttackBonus(), "initial defense bonus");

    ExpectTrue(shield.equip("shield offhand"), "shield equip called");
    ExpectEq(10, Inventory.inventoryGetDefendAttackBonus(), "defense with shield");

    shield.set("skill penalty", 2);
    ExpectEq(8, Inventory.inventoryGetDefendAttackBonus(), "defense with skill penalty");
}

/////////////////////////////////////////////////////////////////////////////
void InventoryGetAttackBonusReturnsCorrectValue()
{
    Inventory.addSkillPoints(100);
    Inventory.Str(16);
    Inventory.advanceSkill("long sword", 6);

    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("weapon class", 8);
    weapon.set("material", "lunarite");
    weapon.set("weapon type", "long sword");
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    object shield = clone_object("/lib/items/weapon");
    shield.set("name", "shield");
    shield.set("defense class", 1);
    shield.set("material", "lunarite");
    shield.set("equipment locations", Shield);
    shield.set("weapon type", "shield");
    move_object(shield, Inventory);

    object armor = clone_object("/lib/items/armor");
    armor.set("name", "stuff");
    armor.set("bonus attack", 1);
    armor.set("armor class", 5);
    armor.set("armor type", "chainmail");
    armor.set("equipment locations", Armor);
    move_object(armor, Inventory);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus attack", 3);
    modifier.set("bonus long sword", 5);

    ExpectEq(0, Inventory.inventoryGetAttackBonus(weapon), "initial attack bonus");

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectEq(11, Inventory.inventoryGetAttackBonus(weapon), "attack with weapon");

    ExpectTrue(shield.equip("shield offhand"), "shield equip called");
    ExpectEq(11, Inventory.inventoryGetAttackBonus(weapon), "attack with shield");

    ExpectTrue(armor.equip("stuff"), "armor equip called");
    ExpectEq(12, Inventory.inventoryGetAttackBonus(weapon), "attack with weapon and armor");

    ExpectEq(1, modifier.set("registration list", ({ Inventory })), "registration list can be set");
    ExpectEq(17, Inventory.inventoryGetAttackBonus(weapon), "attack with everything");
}

/////////////////////////////////////////////////////////////////////////////
void InventoryGetAttackBonusReturnsPenaltyWhenDualWielding()
{
    Inventory.addSkillPoints(100);
    Inventory.Str(16);
    Inventory.Dex(16);
    Inventory.advanceSkill("long sword", 6);

    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("weapon class", 8);
    weapon.set("material", "lunarite");
    weapon.set("weapon type", "long sword");
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    object offhand = clone_object("/lib/items/weapon");
    offhand.set("name", "blarg");
    offhand.set("defense class", 1);
    offhand.set("material", "lunarite");
    offhand.set("equipment locations", OnehandedWeapon);
    offhand.set("weapon type", "long sword");
    move_object(offhand, Inventory);

    object armor = clone_object("/lib/items/armor");
    armor.set("name", "stuff");
    armor.set("bonus attack", 1);
    armor.set("armor class", 5);
    armor.set("armor type", "chainmail");
    armor.set("equipment locations", Armor);
    move_object(armor, Inventory);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus attack", 3);
    modifier.set("bonus long sword", 5);

    ExpectEq(0, Inventory.inventoryGetAttackBonus(weapon), "initial attack bonus");

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectEq(11, Inventory.inventoryGetAttackBonus(weapon), "attack with weapon");

    ExpectTrue(offhand.equip("blarg offhand"), "offhand equip called");
    ExpectEq(1, Inventory.inventoryGetAttackBonus(weapon), "attack with offhand");
    ExpectEq(-4, Inventory.inventoryGetAttackBonus(offhand), "attack with offhand");

    Inventory.advanceSkill("dual wield", 1);
    ExpectEq(6, Inventory.inventoryGetAttackBonus(weapon), "attack with offhand");
    ExpectEq(1, Inventory.inventoryGetAttackBonus(offhand), "attack with offhand");

    ExpectTrue(armor.equip("stuff"), "armor equip called");
    ExpectEq(7, Inventory.inventoryGetAttackBonus(weapon), "attack with weapon and armor");

    ExpectEq(1, modifier.set("registration list", ({ Inventory })), "registration list can be set");
    ExpectEq(12, Inventory.inventoryGetAttackBonus(weapon), "attack with everything");
}

/////////////////////////////////////////////////////////////////////////////
void InventoryGetAttackBonusAppliesSkillPenalty()
{
    Inventory.addSkillPoints(100);
    Inventory.Str(16);
    Inventory.Dex(16);
    Inventory.advanceSkill("long sword", 6);

    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("weapon class", 8);
    weapon.set("material", "lunarite");
    weapon.set("weapon type", "long sword");
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    ExpectEq(0, Inventory.inventoryGetAttackBonus(weapon), "initial attack bonus");

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectEq(11, Inventory.inventoryGetAttackBonus(weapon), "attack with weapon");

    weapon.set("skill penalty", 2);
    ExpectEq(9, Inventory.inventoryGetAttackBonus(weapon), "attack with weapon");
}

/////////////////////////////////////////////////////////////////////////////
void InventoryGetDamageBonusReturnsCorrectValue()
{
    Inventory.addSkillPoints(100);
    Inventory.Str(16);
    Inventory.advanceSkill("long sword", 6);

    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("weapon class", 8);
    weapon.set("material", "lunarite");
    weapon.set("weapon type", "long sword");
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    object shield = clone_object("/lib/items/weapon");
    shield.set("name", "shield");
    shield.set("defense class", 1);
    shield.set("material", "lunarite");
    shield.set("equipment locations", Shield);
    shield.set("weapon type", "shield");
    move_object(shield, Inventory);

    object armor = clone_object("/lib/items/armor");
    armor.set("name", "stuff");
    armor.set("bonus damage", 1);
    armor.set("armor class", 5);
    armor.set("armor type", "chainmail");
    armor.set("equipment locations", Armor);
    move_object(armor, Inventory);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus damage", 3);
    modifier.set("bonus long sword", 5);

    ExpectEq(0, Inventory.inventoryGetDamageBonus(weapon, "physical"), "initial damage bonus");

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectEq(12, Inventory.inventoryGetDamageBonus(weapon, "physical"), "damage with weapon");

    ExpectTrue(shield.equip("shield offhand"), "shield equip called");
    ExpectEq(12, Inventory.inventoryGetDamageBonus(weapon, "physical"), "damage with shield");

    ExpectTrue(armor.equip("stuff"), "armor equip called");
    ExpectEq(13, Inventory.inventoryGetDamageBonus(weapon, "physical"), "damage with weapon and armor");

    ExpectEq(1, modifier.set("registration list", ({ Inventory })), "registration list can be set");
    ExpectEq(17, Inventory.inventoryGetDamageBonus(weapon, "physical"), "damage with everything");

    weapon.set("enchantments", (["physical": 5]));
    ExpectEq(22, Inventory.inventoryGetDamageBonus(weapon, "physical"), "damage with enchantments");
}

/////////////////////////////////////////////////////////////////////////////
void InventoryGetDamageBonusHandlesSkillPenalty()
{
    Inventory.addSkillPoints(100);
    Inventory.Str(16);
    Inventory.advanceSkill("long sword", 6);

    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("weapon class", 8);
    weapon.set("material", "lunarite");
    weapon.set("weapon type", "long sword");
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    ExpectEq(0, Inventory.inventoryGetDamageBonus(weapon, "physical"), "initial damage bonus");

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectEq(12, Inventory.inventoryGetDamageBonus(weapon, "physical"), "damage with weapon");

    weapon.set("skill penalty", 2);
    ExpectEq(10, Inventory.inventoryGetDamageBonus(weapon, "physical"), "damage with skill penalty");
}

/////////////////////////////////////////////////////////////////////////////
void GetExtraDamageTypesReturnsCorrectValue()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("weapon class", 8);
    weapon.set("material", "kirdarium");
    weapon.set("weapon type", "long sword");
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);
    ExpectTrue(weapon.equip("blah"), "weapon equip called");

    string *damageTypes = Inventory.getExtraDamageTypes(weapon);
    ExpectEq(4, sizeof(damageTypes), "4 damage types");
    ExpectTrue((member(damageTypes, "physical") > -1), "physical is one of the damage types");
    ExpectTrue((member(damageTypes, "magical") > -1), "magical is one of the damage types");
    ExpectTrue((member(damageTypes, "electricity") > -1), "electricity is one of the damage types");
    ExpectTrue((member(damageTypes, "cold") > -1), "cold is one of the damage types");

    ExpectTrue(weapon.unequip("blah"), "weapon equip called");
    weapon.set("enchantments", (["fire": 10, "cold": 10 ]));
    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    damageTypes = Inventory.getExtraDamageTypes(weapon);
    // Though cold is both default and an enchantment, it should not get counted twice
    ExpectEq(5, sizeof(damageTypes), "5 damage types");
    ExpectTrue((member(damageTypes, "physical") > -1), "physical is one of the damage types");
    ExpectTrue((member(damageTypes, "magical") > -1), "magical is one of the damage types");
    ExpectTrue((member(damageTypes, "fire") > -1), "fire is one of the damage types");
    ExpectTrue((member(damageTypes, "electricity") > -1), "electricity is one of the damage types");
    ExpectTrue((member(damageTypes, "cold") > -1), "cold is one of the damage types");
}

/////////////////////////////////////////////////////////////////////////////
void MoneyReturnsCorrectValue()
{
    ExpectEq(0, Inventory.Money(), "Money is initially 0");
    ExpectEq(1000, Inventory.Money(1000), "Money can be set to zero");
    ExpectEq(1000, Inventory.Money(), "Money is still 1000");
}

/////////////////////////////////////////////////////////////////////////////
void MoneyCannotBeZeroOrNegative()
{
    Inventory.Money(1000);
    ExpectEq(1000, Inventory.Money(0), "call of zero doesn't change money");
    ExpectEq(1000, Inventory.Money(-20000), "call of a negative number doesn't change money");
}

/////////////////////////////////////////////////////////////////////////////
void AddMoneyIncrementsMoneyByValue()
{
    Inventory.Money(1000);
    ExpectTrue(Inventory.addMoney(150), "add money returns true");
    ExpectEq(1150, Inventory.Money(), "call to money returns the correct value (1150)");
    ExpectTrue(Inventory.addMoney(-550), "add negative money returns true");
    ExpectEq(600, Inventory.Money(), "call to money returns the correct value (600)");
}

/////////////////////////////////////////////////////////////////////////////
void AddMoneyWillNotSetMoneyBelowZero()
{
    Inventory.Money(1000);
    ExpectTrue(Inventory.addMoney(150), "add money returns true");
    ExpectEq(1150, Inventory.Money(), "call to money returns the correct value");
}

/////////////////////////////////////////////////////////////////////////////
void TransferMoneyFromRemovesMoneyAndReturnsMoneyObjectOfRemovedValue()
{
    Inventory.Money(1000);

    object money = Inventory.transferMoneyFrom(250);
    ExpectEq("/lib/items/money.c", program_name(money), "A money object was created");
    ExpectEq(250, money.query("value"), "money object has a value of 250");
    ExpectEq(750, Inventory.Money(), "750 money left on user");
}

/////////////////////////////////////////////////////////////////////////////
void TransferMoneyFromReturnsNullIfTransferFails()
{
    Inventory.Money(100);

    ExpectFalse(Inventory.transferMoneyFrom(250), "transfer money returns false");
    ExpectEq(100, Inventory.Money(), "100 money left on user");
}

/////////////////////////////////////////////////////////////////////////////
void TransferMoneyToReturnsFalseIfMoneyNotPassed()
{
    ExpectFalse(Inventory.transferMoneyTo());
    ExpectFalse(Inventory.transferMoneyTo(Inventory));
    ExpectFalse(Inventory.transferMoneyTo(Inventory, 30));
}

/////////////////////////////////////////////////////////////////////////////
void TransferMoneyToAddsCorrectAmountAndMoneyObjectDestroyed()
{
    object money = clone_object("/lib/items/money.c");
    money.set("value", 100);
    ExpectEq(0, Inventory.Money());
    ExpectTrue(objectp(money));

    ExpectTrue(Inventory.transferMoneyTo(money));
    ExpectEq(100, Inventory.Money());
    ExpectFalse(objectp(money));
}

/////////////////////////////////////////////////////////////////////////////
void TransferMoneyToCanTransferPartialQuantity()
{
    object money = clone_object("/lib/items/money.c");
    money.set("value", 100);
    ExpectEq(0, Inventory.Money());

    ExpectTrue(Inventory.transferMoneyTo(money, 75));
    ExpectEq(75, Inventory.Money());
    ExpectEq(25, money.query("value"));
}

/////////////////////////////////////////////////////////////////////////////
void TransferMoneyToWillNotTransferNegativeValues()
{
    object money = clone_object("/lib/items/money.c");
    money.set("value", 100);
    ExpectEq(0, Inventory.Money());

    ExpectFalse(Inventory.transferMoneyTo(money, -75));
    ExpectEq(0, Inventory.Money());
    ExpectEq(100, money.query("value"));
}

/////////////////////////////////////////////////////////////////////////////
void TransferMoneyToWillNotExceedValueOnMoneyObject()
{
    object money = clone_object("/lib/items/money.c");
    money.set("value", 100);
    ExpectEq(0, Inventory.Money());

    ExpectFalse(Inventory.transferMoneyTo(money, 200));
    ExpectEq(0, Inventory.Money());
    ExpectEq(100, money.query("value"));
}

/////////////////////////////////////////////////////////////////////////////
void TransferItemsToUnequipsAndMovesAllDroppableItemsToDestination()
{
    object other = clone_object("/lib/realizations/player");

    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("weapon class", 8);
    weapon.set("material", "lunarite");
    weapon.set("weapon type", "long sword");
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    object shield = clone_object("/lib/items/weapon");
    shield.set("name", "shield");
    shield.set("defense class", 1);
    shield.set("material", "lunarite");
    shield.set("equipment locations", Shield);
    shield.set("weapon type", "shield");
    move_object(shield, Inventory);

    object armor = clone_object("/lib/items/armor");
    armor.set("name", "stuff");
    armor.set("bonus attack", 1);
    armor.set("armor class", 5);
    armor.set("armor type", "chainmail");
    armor.set("equipment locations", Armor);
    move_object(armor, Inventory);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "thingy");
    modifier.set("bonus attack", 3);
    modifier.set("bonus long sword", 5);

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectTrue(shield.equip("shield offhand"), "shield equip called");
    ExpectTrue(armor.equip("stuff"), "armor equip called");
    ExpectEq(1, modifier.set("registration list", ({ Inventory })), "registration list can be set");

    ExpectEq(0, sizeof(all_inventory(other)), "zero items in other's inventory");
    ExpectTrue(Inventory.transferItemsTo(other), "transferItemsTo returns true");

    object *inv = all_inventory(other);
    ExpectEq(3, sizeof(inv), "three items in other's inventory");
    ExpectTrue((member(inv, weapon) > -1), "weapon is one of the transferred items");
    ExpectTrue((member(inv, shield) > -1), "shield is one of the transferred items");
    ExpectTrue((member(inv, armor) > -1), "armor is one of the transferred items");
}

/////////////////////////////////////////////////////////////////////////////
void TransferItemsToDoesNotMoveCursedOrUnmoveableObjects()
{
    object other = clone_object("/lib/realizations/player");

    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("weapon class", 8);
    weapon.set("material", "lunarite");
    weapon.set("weapon type", "long sword");
    weapon.set("equipment locations", OnehandedWeapon);
    mapping curseInfo = ([
        "equip message": "you're cursed",
            "failed unequip message" : "nope... can't do that"
    ]);

    weapon.set("cursed", curseInfo);
    move_object(weapon, Inventory);

    object shield = clone_object("/lib/items/weapon");
    shield.set("name", "shield");
    shield.set("defense class", 1);
    shield.set("material", "lunarite");
    shield.set("equipment locations", Shield);
    shield.set("weapon type", "shield");
    move_object(shield, Inventory);

    object armor = clone_object("/lib/items/armor");
    armor.set("name", "stuff");
    armor.set("bonus attack", 1);
    armor.set("armor class", 5);
    armor.set("armor type", "chainmail");
    armor.set("equipment locations", Armor);
    move_object(armor, Inventory);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "thingy");
    modifier.set("bonus attack", 3);
    modifier.set("bonus long sword", 5);
    move_object(modifier, Inventory);

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectTrue(shield.equip("shield offhand"), "shield equip called");
    ExpectTrue(armor.equip("stuff"), "armor equip called");
    ExpectEq(1, modifier.set("registration list", ({ Inventory })), "registration list can be set");

    ExpectEq(0, sizeof(all_inventory(other)), "zero items in other's inventory");
    ExpectTrue(Inventory.transferItemsTo(other), "transferItemsTo returns true");

    object *inv = all_inventory(other);
    ExpectEq(2, sizeof(inv), "two items in other's inventory");
    ExpectTrue((member(all_inventory(Inventory), weapon) > -1), "weapon is not one of the transferred items");
    ExpectTrue((member(inv, shield) > -1), "shield is one of the transferred items");
    ExpectTrue((member(inv, armor) > -1), "armor is one of the transferred items");
    ExpectTrue((member(all_inventory(Inventory), modifier) > -1), "modifier not is one of the transferred items");
}

/////////////////////////////////////////////////////////////////////////////
void CanCarryCorrectlyDeterminesCurrentCarryWeight()
{
    Inventory.Str(3);
    ExpectEq(27, Inventory.canCarry(), "Initial is 2 * Str + 21");

    object item = clone_object("/lib/tests/support/items/testSword.c");
    move_object(item, Inventory);
    ExpectEq(13, Inventory.canCarry(item), "obsynite sword by default weighs 7");

    item.set("weight", 100);
    ExpectFalse(Inventory.canCarry(item), "returns false when max carry is exceeded");
}

/////////////////////////////////////////////////////////////////////////////
void can_put_and_getReturnsOne()
{
    ExpectTrue(Inventory.can_put_and_get());
}

/////////////////////////////////////////////////////////////////////////////
void UsingEquipmentOfTypeReturnsTrueForWeaponWhenCorrectTypeIsUsed()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("weapon type", "long sword");
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectTrue(Inventory.usingEquipmentOfType("long sword"), "correct weapon type wielded");
}

/////////////////////////////////////////////////////////////////////////////
void UsingEquipmentOfTypeReturnsFalseForWeaponWhenIncorrectTypeIsUsed()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("weapon type", "axe");
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectFalse(Inventory.usingEquipmentOfType("long sword"), "incorrect weapon type wielded");
}

/////////////////////////////////////////////////////////////////////////////
void UsingEquipmentOfTypeReturnsFalseWhenNoEquipmentIsUsed()
{
    ExpectFalse(objectp(Inventory.usingEquipmentOfType("long sword")), "correct weapon type wielded");
}

/////////////////////////////////////////////////////////////////////////////
void UsingEquipmentOfTypeReturnsTrueForArmorWhenCorrectTypeIsUsed()
{
    object armor = clone_object("/lib/items/armor");
    armor.set("name", "blah");
    armor.set("armor type", "chainmail");
    armor.set("equipment locations", Armor);
    move_object(armor, Inventory);

    ExpectTrue(armor.equip("blah"), "armor equip called");
    ExpectTrue(Inventory.usingEquipmentOfType("chainmail"), "correct armor type worn");
}

/////////////////////////////////////////////////////////////////////////////
void UsingEquipmentOfTypeReturnsFalseForArmorWhenIncorrectTypeIsUsed()
{
    object armor = clone_object("/lib/items/armor");
    armor.set("name", "blah");
    armor.set("armor type", "soft leather");
    armor.set("equipment locations", Armor);
    move_object(armor, Inventory);

    ExpectTrue(armor.equip("blah"), "armor equip called");
    ExpectFalse(Inventory.usingEquipmentOfType("chainmail"), "incorrect armor type worn");
}

/////////////////////////////////////////////////////////////////////////////
void UsingEquipmentOfTypeReturnsTrueForEquipmentWhenCorrectTypeIsUsed()
{
    object armor = clone_object("/lib/items/armor");
    armor.set("name", "blah");
    armor.set("armor type", "chainmail");
    armor.set("equipment locations", Gloves);
    move_object(armor, Inventory);

    ExpectTrue(armor.equip("blah"), "armor equip called");
    ExpectTrue(Inventory.usingEquipmentOfType("gloves"), "correct armor type worn");
}

/////////////////////////////////////////////////////////////////////////////
void UsingEquipmentOfTypeReturnsFalseForEquipmentWhenIncorrectTypeIsUsed()
{
    object armor = clone_object("/lib/items/armor");
    armor.set("name", "blah");
    armor.set("armor type", "chainmail");
    armor.set("equipment locations", Cloak);
    move_object(armor, Inventory);

    ExpectTrue(armor.equip("blah"), "armor equip called");
    ExpectFalse(Inventory.usingEquipmentOfType("gloves"), "incorrect armor type worn");
}

/////////////////////////////////////////////////////////////////////////////
void UsingEquipmentOfTypeReturnsCorrectlyForMultipleEquippedItems()
{
    object armor = clone_object("/lib/items/armor");
    armor.set("name", "blah");
    armor.set("armor type", "chainmail");
    armor.set("equipment locations", Cloak);
    move_object(armor, Inventory);
    ExpectTrue(armor.equip("blah"), "cloak equip called");

    armor = clone_object("/lib/items/armor");
    armor.set("name", "blarg");
    armor.set("armor type", "chainmail");
    armor.set("equipment locations", Armor);
    move_object(armor, Inventory);
    ExpectTrue(armor.equip("blarg"), "armor equip called");

    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "weapon");
    weapon.set("weapon type", "axe");
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);
    ExpectTrue(weapon.equip("weapon"), "weapon equip called");

    ExpectFalse(Inventory.usingEquipmentOfType("gloves"), "gloves not worn");
    ExpectFalse(Inventory.usingEquipmentOfType("long sword"), "long sword not wielded");
    ExpectTrue(Inventory.usingEquipmentOfType("cloak"), "cloak worn");
    ExpectTrue(Inventory.usingEquipmentOfType("chainmail"), "chainmail worn");
    ExpectFalse(Inventory.usingEquipmentOfType("soft leather"), "leather not worn");
    ExpectTrue(Inventory.usingEquipmentOfType("axe"), "axe wielded");
}

/////////////////////////////////////////////////////////////////////////////
void InventoryDescriptionReturnsCorrectDescription()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("user description", "##UserName## has a shiny blah!");

    ExpectEq("", Inventory.inventoryDescription());

    move_object(weapon, Inventory);
    ExpectEq("Bob has a shiny blah!\n", Inventory.inventoryDescription());
}

/////////////////////////////////////////////////////////////////////////////
void InventoryDescriptionAddsRegisteredModifiers()
{
    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "thingy");
    modifier.set("user description", "##UserSubjective## sees an object registered but not in ##UserPossessive## inventory");
    ExpectEq(1, modifier.set("registration list", ({ Inventory })), "registration list can be set");

    ExpectEq("He sees an object registered but not in his inventory\n", Inventory.inventoryDescription());
}

/////////////////////////////////////////////////////////////////////////////
void InventoryDescriptionReturnsCorrectListOfDescriptions()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("user description", "##UserName## has a shiny blah!");
    move_object(weapon, Inventory);

    weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah2");
    move_object(weapon, Inventory);

    object armor = clone_object("/lib/items/armor");
    armor.set("name", "stuff");
    armor.set("user description", "##UserSubjective## is using stuff");
    move_object(armor, Inventory);

    object item = clone_object("/lib/items/item");
    item.set("user description", "##UserSubjective## has a hidden item.");
    move_object(item, Inventory);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "thingy");
    modifier.set("user description", "##UserSubjective## sees an object registered but not in ##UserPossessive## inventory");
    ExpectEq(1, modifier.set("registration list", ({ Inventory })), "registration list can be set");

    modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "thingy2");
    modifier.set("user description", "This item is not seen twice");
    move_object(modifier, Inventory);
    ExpectEq(1, modifier.set("registration list", ({ Inventory })), "registration list can be set");

    string expectedMessage = "He is using stuff\nHe has a hidden item.\nHe sees an object registered but not in his inventory\nThis item is not seen twice\nBob has a shiny blah!\n";
    ExpectEq(expectedMessage, Inventory.inventoryDescription());
}

/////////////////////////////////////////////////////////////////////////////
void EquippingSecondItemOfTypeUnequipsFirstItemAndEquipsSecond()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("blueprint", "long sword");
    weapon.set("name", "blah");
    move_object(weapon, Inventory);

    object weapon2 = clone_object("/lib/items/weapon");
    weapon2.set("blueprint", "long sword");
    weapon2.set("name", "blah2");
    move_object(weapon2, Inventory);

    ExpectFalse(Inventory.isEquipped(weapon), "weapon initially unequipped");
    ExpectFalse(Inventory.isEquipped(weapon2), "weapon2 initially unequipped");
    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectTrue(Inventory.isEquipped(weapon), "weapon equipped after weapon equip called");
    ExpectFalse(Inventory.isEquipped(weapon2), "weapon2 unequipped after weapon equip called");
    ExpectTrue(weapon2.equip("blah2"), "weapon2 equip called");
    ExpectFalse(Inventory.isEquipped(weapon), "weapon unequipped after weapon2 equip called");
    ExpectTrue(Inventory.isEquipped(weapon2), "weapon2 equipped after weapon2 equip called");
}

/////////////////////////////////////////////////////////////////////////////
void CanEquipTwoRings()
{
    object ring = clone_object("/lib/instances/items/armor/accessories/ring.c");
    ring.set("name", "Ring of Weasels");
    move_object(ring, Inventory);

    object ring2 = clone_object("/lib/instances/items/armor/accessories/ring.c");
    ring2.set("name", "Ring of Spiffiness");
    move_object(ring2, Inventory);

    ExpectFalse(Inventory.isEquipped(ring), "first initially unequipped");
    ExpectFalse(Inventory.isEquipped(ring2), "second initially unequipped");
    ExpectEq(0x00001000, ring.query("equipment locations"));
    ExpectEq(0x00001000, ring2.query("equipment locations"));
    command("wear first Ring of Weasels", Inventory);
    ExpectTrue(Inventory.isEquipped(ring), "first ring is equipped");
    ExpectFalse(Inventory.isEquipped(ring2), "second ring unequipped");
    command("wear second Ring of Spiffiness", Inventory);
    ExpectEq(0x00001000, ring.query("equipment locations"));
    ExpectEq(0x00002000, ring2.query("equipment locations"));
    ExpectTrue(Inventory.isEquipped(ring), "first ring still equipped");
    ExpectTrue(Inventory.isEquipped(ring2), "second ring is equipped");
}

/////////////////////////////////////////////////////////////////////////////
void UnequippingSecondRingResetsTheMaskToRing()
{
    object ring = clone_object("/lib/instances/items/armor/accessories/ring.c");
    ring.set("name", "Ring of Weasels");
    move_object(ring, Inventory);

    ExpectEq(0x00001000, ring.query("equipment locations"));
    ExpectFalse(Inventory.isEquipped(ring), "first ring is equipped");
    command("wear second ring", Inventory);
    ExpectTrue(Inventory.isEquipped(ring), "first ring is equipped");
    ExpectEq(0x00002000, ring.query("equipment locations"));
    command("remove ring", Inventory);
    ExpectEq(0x00001000, ring.query("equipment locations"));
    ExpectFalse(Inventory.isEquipped(ring), "first ring is equipped");
}

/////////////////////////////////////////////////////////////////////////////
void DamageBonusCalledFirstDoesNotCorruptAttackBonusCache()
{
    Inventory.addSkillPoints(100);
    Inventory.Str(16);
    Inventory.advanceSkill("long sword", 6);

    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("weapon class", 8);
    weapon.set("material", "lunarite");
    weapon.set("weapon type", "long sword");
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    ExpectTrue(weapon.equip("blah"), "weapon equip called");

    ExpectEq(12, Inventory.inventoryGetDamageBonus(weapon, "physical"),
        "damage bonus is correct on first call");
    ExpectEq(11, Inventory.inventoryGetAttackBonus(weapon),
        "attack bonus is correct after damage bonus was cached first");
}

/////////////////////////////////////////////////////////////////////////////
void AttackBonusCalledFirstDoesNotCorruptDamageBonusCache()
{
    Inventory.addSkillPoints(100);
    Inventory.Str(16);
    Inventory.advanceSkill("long sword", 6);

    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("weapon class", 8);
    weapon.set("material", "lunarite");
    weapon.set("weapon type", "long sword");
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    ExpectTrue(weapon.equip("blah"), "weapon equip called");

    ExpectEq(11, Inventory.inventoryGetAttackBonus(weapon),
        "attack bonus is correct on first call");
    ExpectEq(12, Inventory.inventoryGetDamageBonus(weapon, "physical"),
        "damage bonus is correct after attack bonus was cached first");
}

/////////////////////////////////////////////////////////////////////////////
void DamageAndAttackBonusReturnSameValuesRegardlessOfCallOrder()
{
    object playerA = clone_object("/lib/tests/support/services/mockPlayer.c");
    playerA.Name("Alice");
    playerA.Gender("female");
    move_object(playerA, this_object());
    playerA.addSkillPoints(100);
    playerA.Str(16);
    playerA.advanceSkill("long sword", 6);

    object weaponA = clone_object("/lib/items/weapon");
    weaponA.set("name", "bladeA");
    weaponA.set("weapon class", 8);
    weaponA.set("material", "lunarite");
    weaponA.set("weapon type", "long sword");
    weaponA.set("equipment locations", OnehandedWeapon);
    move_object(weaponA, playerA);
    weaponA.equip("bladeA");

    int damageFirst = playerA.inventoryGetDamageBonus(weaponA, "physical");
    int attackAfterDamage = playerA.inventoryGetAttackBonus(weaponA);
    destruct(playerA);

    object playerB = clone_object("/lib/tests/support/services/mockPlayer.c");
    playerB.Name("Carol");
    playerB.Gender("female");
    move_object(playerB, this_object());
    playerB.addSkillPoints(100);
    playerB.Str(16);
    playerB.advanceSkill("long sword", 6);

    object weaponB = clone_object("/lib/items/weapon");
    weaponB.set("name", "bladeB");
    weaponB.set("weapon class", 8);
    weaponB.set("material", "lunarite");
    weaponB.set("weapon type", "long sword");
    weaponB.set("equipment locations", OnehandedWeapon);
    move_object(weaponB, playerB);
    weaponB.equip("bladeB");

    int attackFirst = playerB.inventoryGetAttackBonus(weaponB);
    int damageAfterAttack = playerB.inventoryGetDamageBonus(weaponB, "physical");
    destruct(playerB);

    ExpectEq(damageFirst, damageAfterAttack,
        "damage bonus is identical regardless of which was called first");
    ExpectEq(attackFirst, attackAfterDamage,
        "attack bonus is identical regardless of which was called first");
}

/////////////////////////////////////////////////////////////////////////////
void WearRingWithNoQualifierUsesRing1WhenBothSlotsEmpty()
{
    object ring = clone_object("/lib/instances/items/armor/accessories/ring.c");
    ring.set("name", "Ring of Weasels");
    move_object(ring, Inventory);

    command("wear Ring of Weasels", Inventory);
    ExpectTrue(Inventory.isEquipped(ring), "ring is equipped");
    ExpectEq(0x00001000, ring.query("equipment locations"), "ring is in ring 1 slot");
    ExpectTrue(objectp(Inventory.equipmentInSlot("ring 1")), "ring 1 slot is occupied");
    ExpectFalse(Inventory.equipmentInSlot("ring 2"), "ring 2 slot is empty");
}

/////////////////////////////////////////////////////////////////////////////
void WearRingWithNoQualifierAutoFillsRing2WhenRing1IsOccupied()
{
    object ring1 = clone_object("/lib/instances/items/armor/accessories/ring.c");
    ring1.set("name", "Ring of Weasels");
    move_object(ring1, Inventory);

    object ring2 = clone_object("/lib/instances/items/armor/accessories/ring.c");
    ring2.set("name", "Ring of Spiffiness");
    move_object(ring2, Inventory);

    command("wear Ring of Weasels", Inventory);
    ExpectTrue(Inventory.isEquipped(ring1), "first ring is equipped");
    ExpectEq(0x00001000, ring1.query("equipment locations"), "first ring is in ring 1");

    command("wear Ring of Spiffiness", Inventory);
    ExpectTrue(Inventory.isEquipped(ring1), "first ring still equipped after second wear");
    ExpectTrue(Inventory.isEquipped(ring2), "second ring is equipped");
    ExpectEq(0x00001000, ring1.query("equipment locations"), "first ring remains in ring 1");
    ExpectEq(0x00002000, ring2.query("equipment locations"), "second ring auto-selected ring 2");
}

/////////////////////////////////////////////////////////////////////////////
void WearRingWithNoQualifierDisplacesRing1WhenBothSlotsOccupied()
{
    object ring1 = clone_object("/lib/instances/items/armor/accessories/ring.c");
    ring1.set("name", "Ring of Weasels");
    move_object(ring1, Inventory);

    object ring2 = clone_object("/lib/instances/items/armor/accessories/ring.c");
    ring2.set("name", "Ring of Spiffiness");
    move_object(ring2, Inventory);

    object ring3 = clone_object("/lib/instances/items/armor/accessories/ring.c");
    ring3.set("name", "Ring of Power");
    move_object(ring3, Inventory);

    command("wear Ring of Weasels", Inventory);
    command("wear Ring of Spiffiness", Inventory);
    ExpectTrue(Inventory.isEquipped(ring1), "ring 1 equipped");
    ExpectTrue(Inventory.isEquipped(ring2), "ring 2 equipped");

    command("wear Ring of Power", Inventory);
    ExpectFalse(Inventory.isEquipped(ring1), "ring 1 displaced when both slots were full");
    ExpectTrue(Inventory.isEquipped(ring2), "ring 2 undisturbed");
    ExpectTrue(Inventory.isEquipped(ring3), "ring 3 now in ring 1 slot");
    ExpectEq(0x00001000, ring3.query("equipment locations"), "ring 3 is in ring 1");
}

/////////////////////////////////////////////////////////////////////////////
void UnregisterObjectsOfTypeRemovesAllMatchingModifiers()
{
    object poison1 = clone_object("/lib/items/modifierObject");
    poison1.set("fully qualified name", "poison effect 1");
    poison1.set("penalty to strength", 2);
    poison1.set("poison", 1);

    object poison2 = clone_object("/lib/items/modifierObject");
    poison2.set("fully qualified name", "poison effect 2");
    poison2.set("penalty to constitution", 3);
    poison2.set("poison", 1);

    object disease = clone_object("/lib/items/modifierObject");
    disease.set("fully qualified name", "disease effect");
    disease.set("penalty to strength", 1);
    disease.set("disease", 1);

    ExpectEq(1, poison1.set("registration list", ({ Inventory })), "poison1 registered");
    ExpectEq(1, poison2.set("registration list", ({ Inventory })), "poison2 registered");
    ExpectEq(1, disease.set("registration list", ({ Inventory })), "disease registered");

    ExpectTrue(Inventory.registeredInventoryObject("poison effect 1"), "poison1 is registered");
    ExpectTrue(Inventory.registeredInventoryObject("poison effect 2"), "poison2 is registered");
    ExpectTrue(Inventory.registeredInventoryObject("disease effect"), "disease is registered");

    ExpectTrue(Inventory.inventoryGetModifier("combatModifiers", "poison"), "poison is registered");

    ExpectTrue(Inventory.unregisterObjectsOfType("poison"), "unregisterObjectsOfType returns true");

    ExpectFalse(Inventory.registeredInventoryObject("poison effect 1"), "poison1 is unregistered");
    ExpectFalse(Inventory.registeredInventoryObject("poison effect 2"), "poison2 is unregistered");
    ExpectTrue(Inventory.registeredInventoryObject("disease effect"), "disease is still registered");
    ExpectFalse(Inventory.inventoryGetModifier("combatModifiers", "poison"), "poison is registered");
}

/////////////////////////////////////////////////////////////////////////////
void UnregisterObjectsOfTypeReturnsFalseWhenNoMatchingModifiers()
{
    object disease = clone_object("/lib/items/modifierObject");
    disease.set("fully qualified name", "disease effect");
    disease.set("penalty to strength", 1);
    disease.set("disease", 1);

    ExpectEq(1, disease.set("registration list", ({ Inventory })), "disease registered");

    ExpectFalse(Inventory.unregisterObjectsOfType("poison"), "unregisterObjectsOfType returns false");
    ExpectTrue(Inventory.registeredInventoryObject("disease effect"), "disease is still registered");
}

/////////////////////////////////////////////////////////////////////////////
void UnregisterObjectsOfTypeReturnsFalseWhenNoRegisteredObjects()
{
    ExpectFalse(Inventory.unregisterObjectsOfType("poison"), "unregisterObjectsOfType returns false with no objects");
}

/////////////////////////////////////////////////////////////////////////////
void UnregisterObjectsOfTypeRemovesSlowModifier()
{
    object slow = clone_object("/lib/items/modifierObject");
    slow.set("fully qualified name", "slow effect");
    slow.set("penalty to dexterity", 3);
    slow.set("slow", 1);

    ExpectEq(1, slow.set("registration list", ({ Inventory })), "slow registered");
    ExpectTrue(Inventory.registeredInventoryObject("slow effect"), "slow is registered");

    ExpectTrue(Inventory.unregisterObjectsOfType("slow"), "unregisterObjectsOfType returns true");
    ExpectFalse(Inventory.registeredInventoryObject("slow effect"), "slow is unregistered");
}

/////////////////////////////////////////////////////////////////////////////
void UnregisterObjectsOfTypeRemovesEnfeebledModifier()
{
    object enfeebled = clone_object("/lib/items/modifierObject");
    enfeebled.set("fully qualified name", "enfeebled effect");
    enfeebled.set("penalty to strength", 5);
    enfeebled.set("enfeebled", 1);

    ExpectEq(1, enfeebled.set("registration list", ({ Inventory })), "enfeebled registered");
    ExpectTrue(Inventory.registeredInventoryObject("enfeebled effect"), "enfeebled is registered");

    ExpectTrue(Inventory.unregisterObjectsOfType("enfeebled"), "unregisterObjectsOfType returns true");
    ExpectFalse(Inventory.registeredInventoryObject("enfeebled effect"), "enfeebled is unregistered");
}

/////////////////////////////////////////////////////////////////////////////
void UnregisterObjectsOfTypeRemovesParalysisModifier()
{
    object paralysis = clone_object("/lib/items/modifierObject");
    paralysis.set("fully qualified name", "paralysis effect");
    paralysis.set("penalty to dexterity", 10);
    paralysis.set("paralysis", 1);

    ExpectEq(1, paralysis.set("registration list", ({ Inventory })), "paralysis registered");
    ExpectTrue(Inventory.registeredInventoryObject("paralysis effect"), "paralysis is registered");

    ExpectTrue(Inventory.unregisterObjectsOfType("paralysis"), "unregisterObjectsOfType returns true");
    ExpectFalse(Inventory.registeredInventoryObject("paralysis effect"), "paralysis is unregistered");
}

/////////////////////////////////////////////////////////////////////////////
void RemoveRing2ThenWearRingGoesToRing1()
{
    object ring1 = clone_object("/lib/instances/items/armor/accessories/ring.c");
    ring1.set("name", "Ring of Weasels");
    move_object(ring1, Inventory);

    object ring2 = clone_object("/lib/instances/items/armor/accessories/ring.c");
    ring2.set("name", "Ring of Spiffiness");
    move_object(ring2, Inventory);

    object ring3 = clone_object("/lib/instances/items/armor/accessories/ring.c");
    ring3.set("name", "Ring of Power");
    move_object(ring3, Inventory);

    command("wear Ring of Weasels", Inventory);
    command("wear Ring of Spiffiness", Inventory);
    ExpectEq(0x00001000, ring1.query("equipment locations"), "ring1 in ring 1 before remove");
    ExpectEq(0x00002000, ring2.query("equipment locations"), "ring2 in ring 2 before remove");

    command("remove Ring of Spiffiness", Inventory);
    ExpectFalse(Inventory.isEquipped(ring2), "ring2 unequipped");
    ExpectTrue(Inventory.isEquipped(ring1), "ring1 still equipped");

    command("wear Ring of Power", Inventory);
    ExpectTrue(Inventory.isEquipped(ring3), "ring3 equipped after remove");
    ExpectEq(0x00002000, ring3.query("equipment locations"), "ring3 went into ring 2 (ring1 occupied)");
    ExpectTrue(Inventory.isEquipped(ring1), "ring1 undisturbed");
}

/////////////////////////////////////////////////////////////////////////////
void WearingOtherItemDoesNotCorruptRing2LocationFlag()
{
    object ring1 = clone_object("/lib/instances/items/armor/accessories/ring.c");
    ring1.set("name", "Ring of Weasels");
    move_object(ring1, Inventory);

    object ring2 = clone_object("/lib/instances/items/armor/accessories/ring.c");
    ring2.set("name", "Ring of Spiffiness");
    move_object(ring2, Inventory);

    command("wear Ring of Weasels", Inventory);
    command("wear Ring of Spiffiness", Inventory);
    ExpectEq(0x00002000, ring2.query("equipment locations"), "ring2 location before equipping unrelated item");

    object gloves = clone_object("/lib/items/armor");
    gloves.set("name", "leather gloves");
    gloves.set("equipment locations", Gloves);
    move_object(gloves, Inventory);
    command("wear leather gloves", Inventory);

    ExpectTrue(Inventory.isEquipped(ring1), "ring1 still equipped after wearing gloves");
    ExpectTrue(Inventory.isEquipped(ring2), "ring2 still equipped after wearing gloves");
    ExpectEq(0x00001000, ring1.query("equipment locations"), "ring1 location not corrupted");
    ExpectEq(0x00002000, ring2.query("equipment locations"), "ring2 location not corrupted");
}

/////////////////////////////////////////////////////////////////////////////
void OffhandUnequipPreservesOffhandFlagOnFailure()
{
    object primary = clone_object("/lib/items/weapon");
    primary.set("name", "sword");
    primary.set("equipment locations", OnehandedWeapon);
    move_object(primary, Inventory);

    object offhand = clone_object("/lib/items/weapon");
    offhand.set("name", "kama");
    offhand.set("equipment locations", OnehandedWeapon);
    offhand.set("cursed", (["equip message": "The kama bonds to your hand!",
        "failed unequip message": "The kama won't let go!"]));
    move_object(offhand, Inventory);

    primary.equip("sword");
    offhand.equip("kama offhand");
    ExpectTrue(Inventory.isEquipped(offhand), "kama equipped offhand");
    ExpectTrue(offhand.query("offhand"), "offhand flag set");

    offhand.unequip("kama");
    ExpectTrue(offhand.query("offhand"), "offhand flag preserved after failed unequip");
    ExpectTrue(Inventory.isEquipped(offhand), "kama still equipped after failed unequip");
    ExpectEq(Inventory.equipmentInSlot("wielded offhand"), offhand,
        "wielded offhand slot still holds kama");
}

/////////////////////////////////////////////////////////////////////////////
void OffhandUnequipClearsOffhandFlagOnSuccess()
{
    object primary = clone_object("/lib/items/weapon");
    primary.set("name", "sword");
    primary.set("equipment locations", OnehandedWeapon);
    move_object(primary, Inventory);

    object offhand = clone_object("/lib/items/weapon");
    offhand.set("name", "kama");
    offhand.set("equipment locations", OnehandedWeapon);
    move_object(offhand, Inventory);

    primary.equip("sword");
    offhand.equip("kama offhand");
    ExpectTrue(offhand.query("offhand"), "offhand flag set before unequip");

    offhand.unequip("kama");
    ExpectFalse(Inventory.isEquipped(offhand), "kama unequipped");
    ExpectFalse(offhand.query("offhand"), "offhand flag cleared after successful unequip");
    ExpectFalse(Inventory.equipmentInSlot("wielded offhand"),
        "wielded offhand slot cleared");
}

/////////////////////////////////////////////////////////////////////////////
void WieldPrimaryWeaponOffhandWhenOffhandSlotEmpty()
{
    object sword = clone_object("/lib/items/weapon");
    sword.set("name", "sword");
    sword.set("equipment locations", OnehandedWeapon);
    move_object(sword, Inventory);

    sword.equip("sword");
    ExpectTrue(Inventory.isEquipped(sword), "sword equipped as primary");
    ExpectEq(Inventory.equipmentInSlot("wielded primary"), sword, "sword in primary slot");

    sword.unequip("sword");
    ExpectFalse(Inventory.isEquipped(sword), "sword unequipped from primary");

    sword.equip("sword offhand");
    ExpectTrue(Inventory.isEquipped(sword), "sword wielded offhand");
    ExpectFalse(Inventory.equipmentInSlot("wielded primary"), "primary slot empty");
    ExpectEq(Inventory.equipmentInSlot("wielded offhand"), sword, "sword in offhand slot");
}

/////////////////////////////////////////////////////////////////////////////
void WieldingOffhandDisplacesExistingOffhandWeapon()
{
    object sword = clone_object("/lib/items/weapon");
    sword.set("name", "sword");
    sword.set("equipment locations", OnehandedWeapon);
    move_object(sword, Inventory);

    object kama = clone_object("/lib/items/weapon");
    kama.set("name", "kama");
    kama.set("equipment locations", OnehandedWeapon);
    move_object(kama, Inventory);

    object angrist = clone_object("/lib/items/weapon");
    angrist.set("name", "angrist");
    angrist.set("equipment locations", OnehandedWeapon);
    move_object(angrist, Inventory);

    sword.equip("sword");
    kama.equip("kama offhand");
    ExpectEq(Inventory.equipmentInSlot("wielded primary"), sword, "sword primary");
    ExpectEq(Inventory.equipmentInSlot("wielded offhand"), kama, "kama offhand");

    angrist.equip("angrist offhand");
    ExpectEq(Inventory.equipmentInSlot("wielded primary"), sword, "sword still primary");
    ExpectEq(Inventory.equipmentInSlot("wielded offhand"), angrist,
        "angrist displaced kama in offhand slot");
    ExpectFalse(Inventory.isEquipped(kama), "kama displaced");
}

/////////////////////////////////////////////////////////////////////////////
void WearByNumberSelectsCorrectItem()
{
    object boots1 = clone_object("/lib/items/armor");
    boots1.set("name", "boots");
    boots1.set("short", "a pair of boots");
    boots1.set("equipment locations", Boots);
    move_object(boots1, Inventory);

    object boots2 = clone_object("/lib/items/armor");
    boots2.set("name", "boots");
    boots2.set("short", "a pair of boots");
    boots2.set("equipment locations", Boots);
    move_object(boots2, Inventory);

    object resolvedByPresent = present("boots 2", Inventory);
    ExpectEq(boots2, resolvedByPresent, "present boots 2 resolves to boots2");

    ExpectTrue(boots2.equip("boots"), "equip boots2 directly by name succeeds");
    ExpectFalse(Inventory.isEquipped(boots1), "boots1 not equipped");
    ExpectTrue(Inventory.isEquipped(boots2), "boots2 equipped");
}

/////////////////////////////////////////////////////////////////////////////
void DropEquippedItemShowsFailureMessage()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "sword");
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    weapon.equip("sword");
    ExpectTrue(Inventory.isEquipped(weapon), "sword equipped before drop");

    command("drop sword", Inventory);
    ExpectTrue(Inventory.isEquipped(weapon), "sword still equipped after drop without -f");
    ExpectTrue(objectp(weapon), "sword object still exists");
}

/////////////////////////////////////////////////////////////////////////////
void DropEquippedItemWithForceFlagUnequipsAndDrops()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "sword");
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    weapon.equip("sword");
    ExpectTrue(Inventory.isEquipped(weapon), "sword equipped before drop -f");

    weapon.drop();
    ExpectFalse(Inventory.isEquipped(weapon), "sword unequipped by drop");
}
