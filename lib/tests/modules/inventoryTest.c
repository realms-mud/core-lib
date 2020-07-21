//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Inventory;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    load_object("/lib/dictionaries/environmentDictionary.c");

    Inventory = clone_object("/lib/tests/support/services/mockPlayer.c");
    Inventory->Name("Bob");
    Inventory->Gender("male");
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
    weapon->set("name", "blah");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    ExpectFalse(Inventory->isEquipped(weapon), "weapon is not equipped yet");
    ExpectTrue(weapon->equip("blah"), "weapon equip called");
    ExpectTrue(Inventory->isEquipped(weapon), "weapon has been equipped");    
}

/////////////////////////////////////////////////////////////////////////////
void EquipmentInSlotReturnsNothingWhenSlotIsEmpty()
{
    ExpectFalse(Inventory->equipmentInSlot("wielded primary"), "weapon is not equipped");
}

/////////////////////////////////////////////////////////////////////////////
void EquipmentInSlotReturnsCorrectItemWhenSlotIsUsed()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    ExpectTrue(weapon->equip("blah"), "weapon equip called");
    ExpectTrue(objectp(Inventory->equipmentInSlot("wielded primary")), "wielded primary has been equipped");
    ExpectEq("blah", Inventory->equipmentInSlot("wielded primary")->query("name"), "wielded primary has correct name");
}

/////////////////////////////////////////////////////////////////////////////
void OffhandWeaponReturnsCorrectItemWhenSlotIsUsed()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    ExpectTrue(weapon->equip("blah offhand"), "weapon equip called offhand");
    ExpectFalse(objectp(Inventory->equipmentInSlot("wielded primary")), "wielded primary has not been equipped");
    ExpectTrue(objectp(Inventory->equipmentInSlot("wielded offhand")), "wielded offhand has been equipped");
    ExpectEq("blah", Inventory->equipmentInSlot("wielded offhand")->query("name"), "wielded offhand has correct name");
}

/////////////////////////////////////////////////////////////////////////////
void TwoHandedWeaponReturnsCorrectItemWhenSlotIsUsed()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("equipment locations", TwohandedWeapon);
    move_object(weapon, Inventory);

    ExpectTrue(weapon->equip("blah"), "weapon equip called");
    ExpectTrue(objectp(Inventory->equipmentInSlot("wielded primary")), "wielded primary has been equipped");
    ExpectEq("blah", Inventory->equipmentInSlot("wielded primary")->query("name"), "wielded primary has correct name");

    ExpectTrue(objectp(Inventory->equipmentInSlot("wielded offhand")), "wielded offhand has been equipped");
    ExpectEq("blah", Inventory->equipmentInSlot("wielded offhand")->query("name"), "wielded offhand has correct name");
}

/////////////////////////////////////////////////////////////////////////////
void EquipmentInSlotResetToEmptyWhenSlotUnequipped()
{
    object armor = clone_object("/lib/items/armor");
    armor->set("name", "blah");
    armor->set("equipment locations", Gloves);
    move_object(armor, Inventory);

    ExpectTrue(armor->equip("blah"), "armor equip called");
    ExpectTrue(objectp(Inventory->equipmentInSlot("gloves")), "gloves has been equipped");
    ExpectTrue(armor->unequip("blah"), "armor unequip called");
    ExpectFalse(objectp(Inventory->equipmentInSlot("gloves")), "gloves has been unequipped");
}

/////////////////////////////////////////////////////////////////////////////
void EquipmentInMultipleSlotsReturnCorrectSlotUsed()
{
    object armor = clone_object("/lib/items/armor");
    armor->set("name", "blah");
    armor->set("equipment locations", Gloves | Armor | ArmGreaves | LegGreaves | Boots);
    move_object(armor, Inventory);

    ExpectTrue(armor->equip("blah"), "armor equip called");
    ExpectTrue(objectp(Inventory->equipmentInSlot("armor")), "armor has been equipped");
    ExpectTrue(objectp(Inventory->equipmentInSlot("arm greaves")), "arm greaves has been equipped");
    ExpectTrue(objectp(Inventory->equipmentInSlot("boots")), "boots has been equipped");
    ExpectTrue(objectp(Inventory->equipmentInSlot("gloves")), "gloves has been equipped");
    ExpectTrue(objectp(Inventory->equipmentInSlot("leg greaves")), "leg greaves has been equipped");

    ExpectTrue(armor->unequip("blah"), "armor unequip called");
    ExpectFalse(objectp(Inventory->equipmentInSlot("armor")), "armor has been equipped");
    ExpectFalse(objectp(Inventory->equipmentInSlot("arm greaves")), "arm greaves has been equipped");
    ExpectFalse(objectp(Inventory->equipmentInSlot("boots")), "boots has been equipped");
    ExpectFalse(objectp(Inventory->equipmentInSlot("gloves")), "gloves has been equipped");
    ExpectFalse(objectp(Inventory->equipmentInSlot("leg greaves")), "leg greaves has been equipped");
}

/////////////////////////////////////////////////////////////////////////////
void OnlyCorrectItemEquippedAndUnequipped()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    object armor = clone_object("/lib/items/armor");
    armor->set("name", "stuff");
    armor->set("equipment locations", Gloves);
    move_object(armor, Inventory);

    ExpectTrue(weapon->equip("blah"), "weapon equip called");
    ExpectTrue(objectp(Inventory->equipmentInSlot("wielded primary")), "wielded primary has been equipped");
    ExpectFalse(objectp(Inventory->equipmentInSlot("gloves")), "gloves have been equipped");

    ExpectTrue(armor->equip("stuff"), "armor equip called");
    ExpectEq("blah", Inventory->equipmentInSlot("wielded primary")->query("name"), "wielded primary has correct name");
    ExpectEq("stuff", Inventory->equipmentInSlot("gloves")->query("name"), "wielded primary has correct name");

    ExpectTrue(weapon->unequip("blah"), "weapon unequip called");
    ExpectFalse(Inventory->equipmentInSlot("wielded primary"), "wielded primary has correct name");
    ExpectEq("stuff", Inventory->equipmentInSlot("gloves")->query("name"), "wielded primary has correct name");
}

/////////////////////////////////////////////////////////////////////////////
void EquipEventHandlerTriggersOnEquip()
{
    ToggleCallOutBypass();
    object armor = clone_object("/lib/tests/support/items/mockArmorWithEvents");
    armor->set("name", "blah");
    armor->set("equipment locations", Gloves);
    armor->set("register event handler", 1);
    move_object(armor, Inventory);

    string err = catch (ExpectTrue(armor->equip("blah"), "armor equip called"));
    ExpectEq("*event handler: onEquip called", err, "onEquip event fired");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void UnequipEventHandlerTriggersOnUnequip()
{
    ToggleCallOutBypass();
    object armor = clone_object("/lib/tests/support/items/mockArmorWithEvents");
    armor->set("name", "blah");
    armor->set("equipment locations", Gloves);
    move_object(armor, Inventory);
    armor->set("register event handler", 1);

    catch (ExpectTrue(armor->equip("blah"), "armor equip called"));

    armor->set("register event handler", 1);
    string err = catch (ExpectTrue(armor->unequip("blah"), "armor unequip called"));
    ExpectEq("*event handler: onUnequip called", err, "onUnequip event fired");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void RegisteredInventoryObjectReturnsCorrectObject()
{
    object modifier = clone_object("/lib/items/modifierObject");
    modifier->set("fully qualified name", "blah");

    ExpectEq(1, modifier->set("registration list", ({ Inventory })), "registration list can be set");

    ExpectTrue(Inventory->registeredInventoryObject("blah"), "modifier with correct FQN is registered");
    ExpectEq("blah", Inventory->registeredInventoryObject("blah")->query("fully qualified name"), "modifier has the correct name");
}

/////////////////////////////////////////////////////////////////////////////
void UnregisteredInventoryObjectRemovesCorrectRegisteredObject()
{
    object modifier = clone_object("/lib/items/modifierObject");
    modifier->set("fully qualified name", "blah");

    ExpectEq(1, modifier->set("registration list", ({ Inventory })), "registration list can be set");

    ExpectTrue(Inventory->registeredInventoryObject("blah"), "modifier with correct FQN is registered");
    ExpectEq("blah", Inventory->registeredInventoryObject("blah")->query("fully qualified name"), "modifier has the correct name");

    ExpectTrue(modifier->unregisterModifierFromTargetList(), "unregister modifier");
    ExpectFalse(Inventory->registeredInventoryObject("blah"), "modifier object not in inventory");
}

/////////////////////////////////////////////////////////////////////////////
void CanHaveMultipleRegisteredObjects()
{
    object modifier = clone_object("/lib/items/modifierObject");
    modifier->set("fully qualified name", "blah");

    object modifier2 = clone_object("/lib/items/modifierObject");
    modifier2->set("fully qualified name", "stuff");

    ExpectEq(1, modifier->set("registration list", ({ Inventory })), "registration list can be set");
    ExpectEq(1, modifier2->set("registration list", ({ Inventory })), "registration list can be set");

    ExpectTrue(Inventory->registeredInventoryObject("blah"), "modifier with correct FQN is registered");
    ExpectEq("blah", Inventory->registeredInventoryObject("blah")->query("fully qualified name"), "modifier has the correct name");

    ExpectTrue(Inventory->registeredInventoryObject("stuff"), "modifier with correct FQN is registered");
    ExpectEq("stuff", Inventory->registeredInventoryObject("stuff")->query("fully qualified name"), "modifier has the correct name");

    ExpectTrue(modifier->unregisterModifierFromTargetList(), "unregister modifier");
    ExpectFalse(Inventory->registeredInventoryObject("blah"), "modifier object not in inventory");
    ExpectTrue(Inventory->registeredInventoryObject("stuff"), "modifier with correct FQN is registered");
}

/////////////////////////////////////////////////////////////////////////////
void RegisterEventHandlerTriggersOnRegister()
{
    ToggleCallOutBypass();
    object modifier = clone_object("/lib/tests/support/items/mockModifierObjWithEvents");
    modifier->set("register event handler", 1);
    modifier->set("fully qualified name", "blah");

    string err = catch (ExpectEq(1, modifier->set("registration list", ({ Inventory })), "registration list can be set"));
    ExpectEq("*event handler: onRegisterItem called", err, "onRegisterItem event fired");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void UnregisterEventHandlerTriggersOnUnregister()
{
    ToggleCallOutBypass();
    object modifier = clone_object("/lib/tests/support/items/mockModifierObjWithEvents");
    modifier->set("register event handler", 1);
    modifier->set("fully qualified name", "blah");
  
    object *list = ({ Inventory });
    catch (ExpectEq(1, modifier->set("registration list", list), "registration list can be set"));

    string err = catch (ExpectTrue(modifier->unregisterModifierFromTargetList(), "unregister modifier"));
    ExpectEq("*event handler: onUnregisterItem called", err, "onUnregisterItem event fired");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void InventoryGetModifierReturnsCorrectValue()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("bonus dodge", 2);
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    object armor = clone_object("/lib/items/armor");
    armor->set("name", "stuff");
    armor->set("bonus dodge", 3);
    armor->set("equipment locations", Gloves);
    move_object(armor, Inventory);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier->set("fully qualified name", "blah");
    modifier->set("bonus dodge", 4);

    ExpectEq(0, Inventory->inventoryGetModifier("bonusSkills", "bonus dodge"), "initial dodge");

    ExpectTrue(weapon->equip("blah"), "weapon equip called");
    ExpectEq(2, Inventory->inventoryGetModifier("bonusSkills", "bonus dodge"), "dodge with weapon");

    ExpectTrue(armor->equip("stuff"), "armor equip called");
    ExpectEq(5, Inventory->inventoryGetModifier("bonusSkills", "bonus dodge"), "dodge with weapon and armor");

    ExpectEq(1, modifier->set("registration list", ({ Inventory })), "registration list can be set");
    ExpectEq(9, Inventory->inventoryGetModifier("bonusSkills", "bonus dodge"), "dodge with everything");
}

/////////////////////////////////////////////////////////////////////////////
void InventoryAttributeBonusReturnsCorrectValue()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("bonus strength", 1);
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    object armor = clone_object("/lib/items/armor");
    armor->set("name", "stuff");
    armor->set("bonus strength", 2);
    armor->set("equipment locations", Gloves);
    move_object(armor, Inventory);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier->set("fully qualified name", "blah");
    modifier->set("bonus strength", 3);

    ExpectEq(0, Inventory->inventoryAttributeBonus("strength"), "initial strength bonus");

    ExpectTrue(weapon->equip("blah"), "weapon equip called");
    ExpectEq(1, Inventory->inventoryAttributeBonus("strength"), "strength with weapon");

    ExpectTrue(armor->equip("stuff"), "armor equip called");
    ExpectEq(3, Inventory->inventoryAttributeBonus("strength"), "strength with weapon and armor");

    ExpectEq(1, modifier->set("registration list", ({ Inventory })), "registration list can be set");
    ExpectEq(6, Inventory->inventoryAttributeBonus("strength"), "strength with everything");
}

/////////////////////////////////////////////////////////////////////////////
void InventoryGetArmorClassReturnsCorrectValue()
{
    object armor = clone_object("/lib/items/armor");
    armor->set("name", "stuff");
    armor->set("armor class", 5);
    armor->set("equipment locations", Armor);
    move_object(armor, Inventory);

    object gloves = clone_object("/lib/items/armor");
    gloves->set("name", "blah");
    gloves->set("armor class", 2);
    gloves->set("equipment locations", Gloves);
    move_object(gloves, Inventory);

    ExpectEq(0, Inventory->inventoryGetArmorClass(), "initial ac bonus");

    ExpectTrue(gloves->equip("blah"), "gloves equip called");
    ExpectEq(2, Inventory->inventoryGetArmorClass(), "ac with gloves");

    ExpectTrue(armor->equip("stuff"), "armor equip called");
    ExpectEq(7, Inventory->inventoryGetArmorClass(), "ac with gloves and armor");
}

/////////////////////////////////////////////////////////////////////////////
void InventoryGetDefenseBonusReturnsCorrectValue()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("bonus defense", 2);
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    object armor = clone_object("/lib/items/armor");
    armor->set("name", "stuff");
    armor->set("bonus defense", 2);
    armor->set("armor class", 5);
    armor->set("material", "steel");
    armor->set("equipment locations", Armor);
    move_object(armor, Inventory);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier->set("fully qualified name", "blah");
    modifier->set("bonus defense", 3);

    ExpectEq(0, Inventory->inventoryGetDefenseBonus("physical"), "initial defense bonus");

    ExpectTrue(weapon->equip("blah"), "weapon equip called");
    ExpectEq(2, Inventory->inventoryGetDefenseBonus("physical"), "defense with weapon");

    ExpectTrue(armor->equip("stuff"), "armor equip called");
    ExpectEq(10, Inventory->inventoryGetDefenseBonus("physical"), "defense with weapon and armor");

    ExpectEq(1, modifier->set("registration list", ({ Inventory })), "registration list can be set");
    ExpectEq(13, Inventory->inventoryGetDefenseBonus("physical"), "defense with everything");
}

/////////////////////////////////////////////////////////////////////////////
void InventoryGetEncumberanceReturnsCorrectValue()
{
    Inventory->addSkillPoints(100);
    Inventory->Str(20);

    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("encumberance", 2);
    weapon->set("material", "steel");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    object shield = clone_object("/lib/items/weapon");
    shield->set("name", "shield");
    shield->set("defense class", 1);
    shield->set("material", "mithril");
    shield->set("equipment locations", Shield);
    shield->set("weapon type", "shield");
    move_object(shield, Inventory);

    object armor = clone_object("/lib/items/armor");
    armor->set("name", "stuff");
    armor->set("encumberance", 5);
    armor->set("material", "steel");
    armor->set("armor type", "chainmail");
    armor->set("equipment locations", Armor);
    move_object(armor, Inventory);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier->set("fully qualified name", "blah");
    modifier->set("bonus chainmail", 6);

    ExpectEq(0, Inventory->inventoryGetEncumberance(), "initial encumberance");

    ExpectTrue(weapon->equip("blah"), "weapon equip called");
    ExpectEq(12, Inventory->inventoryGetEncumberance(), "encumberance with weapon");

    Inventory->advanceSkill("long sword", 8);
    ExpectEq(0, Inventory->inventoryGetEncumberance(), "encumberance with weapon and skill 8");

    ExpectTrue(armor->equip("stuff"), "armor equip called");
    ExpectEq(15, Inventory->inventoryGetEncumberance(), "encumberance with weapon and armor");

    Inventory->advanceSkill("chainmail", 8);
    ExpectEq(2, Inventory->inventoryGetEncumberance(), "encumberance with chainmail trained");

    ExpectEq(1, modifier->set("registration list", ({ Inventory })), "registration list can be set");
    ExpectEq(0, Inventory->inventoryGetEncumberance(), "encumberance with everything");

    ExpectTrue(shield->equip("shield offhand"), "shield equip called");
    ExpectEq(11, Inventory->inventoryGetEncumberance(), "encumberance with shield");

    Inventory->advanceSkill("shield", 8);
    ExpectEq(0, Inventory->inventoryGetEncumberance(), "encumberance with shield and skill at 8");
}

/////////////////////////////////////////////////////////////////////////////
void InventoryGetDefendAttackAppliesOffhandSkillPenalty()
{
    Inventory->addSkillPoints(100);
    Inventory->Str(40);
    Inventory->advanceSkill("shield", 6);

    object shield = clone_object("/lib/items/weapon");
    shield->set("name", "shield");
    shield->set("defense class", 1);
    shield->set("material", "steel");
    shield->set("craftsmanship", 20);
    shield->set("equipment locations", Shield);
    shield->set("weapon type", "shield");
    move_object(shield, Inventory);

    ExpectEq(0, Inventory->inventoryGetDefendAttackBonus(), "initial defense bonus");

    ExpectTrue(shield->equip("shield offhand"), "shield equip called");
    ExpectEq(10, Inventory->inventoryGetDefendAttackBonus(), "defense with shield");

    shield->set("skill penalty", 2);
    ExpectEq(8, Inventory->inventoryGetDefendAttackBonus(), "defense with skill penalty");
}

/////////////////////////////////////////////////////////////////////////////
void InventoryGetAttackBonusReturnsCorrectValue()
{
    Inventory->addSkillPoints(100);
    Inventory->Str(16);
    Inventory->advanceSkill("long sword", 6);

    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("weapon class", 8);
    weapon->set("material", "mithril");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    object shield = clone_object("/lib/items/weapon");
    shield->set("name", "shield");
    shield->set("defense class", 1);
    shield->set("material", "mithril");
    shield->set("equipment locations", Shield);
    shield->set("weapon type", "shield");
    move_object(shield, Inventory);

    object armor = clone_object("/lib/items/armor");
    armor->set("name", "stuff");
    armor->set("bonus attack", 1);
    armor->set("armor class", 5);
    armor->set("armor type", "chainmail");
    armor->set("equipment locations", Armor);
    move_object(armor, Inventory);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier->set("fully qualified name", "blah");
    modifier->set("bonus attack", 3);
    modifier->set("bonus long sword", 5);

    ExpectEq(0, Inventory->inventoryGetAttackBonus(weapon), "initial attack bonus");

    ExpectTrue(weapon->equip("blah"), "weapon equip called");
    ExpectEq(11, Inventory->inventoryGetAttackBonus(weapon), "attack with weapon");

    ExpectTrue(shield->equip("shield offhand"), "shield equip called");
    ExpectEq(11, Inventory->inventoryGetAttackBonus(weapon), "attack with shield");

    ExpectTrue(armor->equip("stuff"), "armor equip called");
    ExpectEq(12, Inventory->inventoryGetAttackBonus(weapon), "attack with weapon and armor");

    ExpectEq(1, modifier->set("registration list", ({ Inventory })), "registration list can be set");
    ExpectEq(17, Inventory->inventoryGetAttackBonus(weapon), "attack with everything");
}

/////////////////////////////////////////////////////////////////////////////
void InventoryGetAttackBonusReturnsPenaltyWhenDualWielding()
{
    Inventory->addSkillPoints(100);
    Inventory->Str(16);
    Inventory->Dex(16);
    Inventory->advanceSkill("long sword", 6);

    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("weapon class", 8);
    weapon->set("material", "mithril");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    object offhand = clone_object("/lib/items/weapon");
    offhand->set("name", "blarg");
    offhand->set("defense class", 1);
    offhand->set("material", "mithril");
    offhand->set("equipment locations", OnehandedWeapon);
    offhand->set("weapon type", "long sword");
    move_object(offhand, Inventory);

    object armor = clone_object("/lib/items/armor");
    armor->set("name", "stuff");
    armor->set("bonus attack", 1);
    armor->set("armor class", 5);
    armor->set("armor type", "chainmail");
    armor->set("equipment locations", Armor);
    move_object(armor, Inventory);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier->set("fully qualified name", "blah");
    modifier->set("bonus attack", 3);
    modifier->set("bonus long sword", 5);

    ExpectEq(0, Inventory->inventoryGetAttackBonus(weapon), "initial attack bonus");

    ExpectTrue(weapon->equip("blah"), "weapon equip called");
    ExpectEq(11, Inventory->inventoryGetAttackBonus(weapon), "attack with weapon");

    ExpectTrue(offhand->equip("blarg offhand"), "offhand equip called");
    ExpectEq(1, Inventory->inventoryGetAttackBonus(weapon), "attack with offhand");
    ExpectEq(-4, Inventory->inventoryGetAttackBonus(offhand), "attack with offhand");

    Inventory->advanceSkill("dual wield", 1);
    ExpectEq(6, Inventory->inventoryGetAttackBonus(weapon), "attack with offhand");
    ExpectEq(1, Inventory->inventoryGetAttackBonus(offhand), "attack with offhand");

    ExpectTrue(armor->equip("stuff"), "armor equip called");
    ExpectEq(7, Inventory->inventoryGetAttackBonus(weapon), "attack with weapon and armor");

    ExpectEq(1, modifier->set("registration list", ({ Inventory })), "registration list can be set");
    ExpectEq(12, Inventory->inventoryGetAttackBonus(weapon), "attack with everything");
}

/////////////////////////////////////////////////////////////////////////////
void InventoryGetAttackBonusAppliesSkillPenalty()
{
    Inventory->addSkillPoints(100);
    Inventory->Str(16);
    Inventory->Dex(16);
    Inventory->advanceSkill("long sword", 6);

    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("weapon class", 8);
    weapon->set("material", "mithril");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    ExpectEq(0, Inventory->inventoryGetAttackBonus(weapon), "initial attack bonus");

    ExpectTrue(weapon->equip("blah"), "weapon equip called");
    ExpectEq(11, Inventory->inventoryGetAttackBonus(weapon), "attack with weapon");

    weapon->set("skill penalty", 2);
    ExpectEq(9, Inventory->inventoryGetAttackBonus(weapon), "attack with weapon");
}

/////////////////////////////////////////////////////////////////////////////
void InventoryGetDamageBonusReturnsCorrectValue()
{
    Inventory->addSkillPoints(100);
    Inventory->Str(16);
    Inventory->advanceSkill("long sword", 6);

    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("weapon class", 8);
    weapon->set("material", "mithril");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    object shield = clone_object("/lib/items/weapon");
    shield->set("name", "shield");
    shield->set("defense class", 1);
    shield->set("material", "mithril");
    shield->set("equipment locations", Shield);
    shield->set("weapon type", "shield");
    move_object(shield, Inventory);

    object armor = clone_object("/lib/items/armor");
    armor->set("name", "stuff");
    armor->set("bonus damage", 1);
    armor->set("armor class", 5);
    armor->set("armor type", "chainmail");
    armor->set("equipment locations", Armor);
    move_object(armor, Inventory);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier->set("fully qualified name", "blah");
    modifier->set("bonus damage", 3);
    modifier->set("bonus long sword", 5);

    ExpectEq(0, Inventory->inventoryGetDamageBonus(weapon, "physical"), "initial damage bonus");

    ExpectTrue(weapon->equip("blah"), "weapon equip called");
    ExpectEq(12, Inventory->inventoryGetDamageBonus(weapon, "physical"), "damage with weapon");

    ExpectTrue(shield->equip("shield offhand"), "shield equip called");
    ExpectEq(12, Inventory->inventoryGetDamageBonus(weapon, "physical"), "damage with shield");

    ExpectTrue(armor->equip("stuff"), "armor equip called");
    ExpectEq(13, Inventory->inventoryGetDamageBonus(weapon, "physical"), "damage with weapon and armor");

    ExpectEq(1, modifier->set("registration list", ({ Inventory })), "registration list can be set");
    ExpectEq(17, Inventory->inventoryGetDamageBonus(weapon, "physical"), "damage with everything");

    weapon->set("enchantments", (["physical": 5]));
    ExpectEq(22, Inventory->inventoryGetDamageBonus(weapon, "physical"), "damage with enchantments");
}

/////////////////////////////////////////////////////////////////////////////
void InventoryGetDamageBonusHandlesSkillPenalty()
{
    Inventory->addSkillPoints(100);
    Inventory->Str(16);
    Inventory->advanceSkill("long sword", 6);

    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("weapon class", 8);
    weapon->set("material", "mithril");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    ExpectEq(0, Inventory->inventoryGetDamageBonus(weapon, "physical"), "initial damage bonus");

    ExpectTrue(weapon->equip("blah"), "weapon equip called");
    ExpectEq(12, Inventory->inventoryGetDamageBonus(weapon, "physical"), "damage with weapon");

    weapon->set("skill penalty", 2);
    ExpectEq(10, Inventory->inventoryGetDamageBonus(weapon, "physical"), "damage with skill penalty");
}

/////////////////////////////////////////////////////////////////////////////
void GetExtraDamageTypesReturnsCorrectValue()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("weapon class", 8);
    weapon->set("material", "kirdarium");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);
    ExpectTrue(weapon->equip("blah"), "weapon equip called");

    string *damageTypes = Inventory->getExtraDamageTypes(weapon);
    ExpectEq(4, sizeof(damageTypes), "4 damage types");
    ExpectTrue((member(damageTypes, "physical") > -1), "physical is one of the damage types");
    ExpectTrue((member(damageTypes, "magical") > -1), "magical is one of the damage types");
    ExpectTrue((member(damageTypes, "electricity") > -1), "electricity is one of the damage types");
    ExpectTrue((member(damageTypes, "cold") > -1), "cold is one of the damage types");

    ExpectTrue(weapon->unequip("blah"), "weapon equip called");
    weapon->set("enchantments", (["fire": 10, "cold": 10 ]));
    ExpectTrue(weapon->equip("blah"), "weapon equip called");
    damageTypes = Inventory->getExtraDamageTypes(weapon);
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
    ExpectEq(0, Inventory->Money(), "Money is initially 0");
    ExpectEq(1000, Inventory->Money(1000), "Money can be set to zero");
    ExpectEq(1000, Inventory->Money(), "Money is still 1000");
}

/////////////////////////////////////////////////////////////////////////////
void MoneyCannotBeZeroOrNegative()
{
    Inventory->Money(1000);
    ExpectEq(1000, Inventory->Money(0), "call of zero doesn't change money");
    ExpectEq(1000, Inventory->Money(-20000), "call of a negative number doesn't change money");
}

/////////////////////////////////////////////////////////////////////////////
void AddMoneyIncrementsMoneyByValue()
{
    Inventory->Money(1000);
    ExpectTrue(Inventory->addMoney(150), "add money returns true");
    ExpectEq(1150, Inventory->Money(), "call to money returns the correct value (1150)");
    ExpectTrue(Inventory->addMoney(-550), "add negative money returns true");
    ExpectEq(600, Inventory->Money(), "call to money returns the correct value (600)");
}

/////////////////////////////////////////////////////////////////////////////
void AddMoneyWillNotSetMoneyBelowZero()
{
    Inventory->Money(1000);
    ExpectTrue(Inventory->addMoney(150), "add money returns true");
    ExpectEq(1150, Inventory->Money(), "call to money returns the correct value");
}

/////////////////////////////////////////////////////////////////////////////
void TransferMoneyFromRemovesMoneyAndReturnsMoneyObjectOfRemovedValue()
{
    Inventory->Money(1000);

    object money = Inventory->transferMoneyFrom(250);
    ExpectEq("lib/items/money.c", program_name(money), "A money object was created");
    ExpectEq(250, money->query("value"), "money object has a value of 250");
    ExpectEq(750, Inventory->Money(), "750 money left on user");
}

/////////////////////////////////////////////////////////////////////////////
void TransferMoneyFromReturnsNullIfTransferFails()
{
    Inventory->Money(100);

    ExpectFalse(Inventory->transferMoneyFrom(250), "transfer money returns false");
    ExpectEq(100, Inventory->Money(), "100 money left on user");
}

/////////////////////////////////////////////////////////////////////////////
void TransferMoneyToReturnsFalseIfMoneyNotPassed()
{
    ExpectFalse(Inventory->transferMoneyTo());
    ExpectFalse(Inventory->transferMoneyTo(Inventory));
    ExpectFalse(Inventory->transferMoneyTo(Inventory, 30));
}

/////////////////////////////////////////////////////////////////////////////
void TransferMoneyToAddsCorrectAmountAndMoneyObjectDestroyed()
{
    object money = clone_object("/lib/items/money.c");
    money->set("value", 100);
    ExpectEq(0, Inventory->Money());
    ExpectTrue(objectp(money));

    ExpectTrue(Inventory->transferMoneyTo(money));
    ExpectEq(100, Inventory->Money());
    ExpectFalse(objectp(money));
}

/////////////////////////////////////////////////////////////////////////////
void TransferMoneyToCanTransferPartialQuantity()
{
    object money = clone_object("/lib/items/money.c");
    money->set("value", 100);
    ExpectEq(0, Inventory->Money());

    ExpectTrue(Inventory->transferMoneyTo(money, 75));
    ExpectEq(75, Inventory->Money());
    ExpectEq(25, money->query("value"));
}

/////////////////////////////////////////////////////////////////////////////
void TransferMoneyToWillNotTransferNegativeValues()
{
    object money = clone_object("/lib/items/money.c");
    money->set("value", 100);
    ExpectEq(0, Inventory->Money());

    ExpectFalse(Inventory->transferMoneyTo(money, -75));
    ExpectEq(0, Inventory->Money());
    ExpectEq(100, money->query("value"));
}

/////////////////////////////////////////////////////////////////////////////
void TransferMoneyToWillNotExceedValueOnMoneyObject()
{
    object money = clone_object("/lib/items/money.c");
    money->set("value", 100);
    ExpectEq(0, Inventory->Money());

    ExpectFalse(Inventory->transferMoneyTo(money, 200));
    ExpectEq(0, Inventory->Money());
    ExpectEq(100, money->query("value"));
}

/////////////////////////////////////////////////////////////////////////////
void TransferItemsToUnequipsAndMovesAllDroppableItemsToDestination()
{
    object other = clone_object("/lib/realizations/player");

    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("weapon class", 8);
    weapon->set("material", "mithril");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    object shield = clone_object("/lib/items/weapon");
    shield->set("name", "shield");
    shield->set("defense class", 1);
    shield->set("material", "mithril");
    shield->set("equipment locations", Shield);
    shield->set("weapon type", "shield");
    move_object(shield, Inventory);

    object armor = clone_object("/lib/items/armor");
    armor->set("name", "stuff");
    armor->set("bonus attack", 1);
    armor->set("armor class", 5);
    armor->set("armor type", "chainmail");
    armor->set("equipment locations", Armor);
    move_object(armor, Inventory);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier->set("fully qualified name", "thingy");
    modifier->set("bonus attack", 3);
    modifier->set("bonus long sword", 5);

    ExpectTrue(weapon->equip("blah"), "weapon equip called");
    ExpectTrue(shield->equip("shield offhand"), "shield equip called");
    ExpectTrue(armor->equip("stuff"), "armor equip called");
    ExpectEq(1, modifier->set("registration list", ({ Inventory })), "registration list can be set");

    ExpectEq(0, sizeof(all_inventory(other)), "zero items in other's inventory");
    ExpectTrue(Inventory->transferItemsTo(other), "transferItemsTo returns true");

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
    weapon->set("name", "blah");
    weapon->set("weapon class", 8);
    weapon->set("material", "mithril");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);
    mapping curseInfo = ([
        "equip message":"you're cursed",
            "failed unequip message" : "nope... can't do that"
    ]);

    weapon->set("cursed", curseInfo);
    move_object(weapon, Inventory);

    object shield = clone_object("/lib/items/weapon");
    shield->set("name", "shield");
    shield->set("defense class", 1);
    shield->set("material", "mithril");
    shield->set("equipment locations", Shield);
    shield->set("weapon type", "shield");
    move_object(shield, Inventory);

    object armor = clone_object("/lib/items/armor");
    armor->set("name", "stuff");
    armor->set("bonus attack", 1);
    armor->set("armor class", 5);
    armor->set("armor type", "chainmail");
    armor->set("equipment locations", Armor);
    move_object(armor, Inventory);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier->set("fully qualified name", "thingy");
    modifier->set("bonus attack", 3);
    modifier->set("bonus long sword", 5);
    move_object(modifier, Inventory);

    ExpectTrue(weapon->equip("blah"), "weapon equip called");
    ExpectTrue(shield->equip("shield offhand"), "shield equip called");
    ExpectTrue(armor->equip("stuff"), "armor equip called");
    ExpectEq(1, modifier->set("registration list", ({ Inventory })), "registration list can be set");

    ExpectEq(0, sizeof(all_inventory(other)), "zero items in other's inventory");
    ExpectTrue(Inventory->transferItemsTo(other), "transferItemsTo returns true");

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
    Inventory->Str(3);
    ExpectEq(27, Inventory->canCarry(), "Initial is 2 * Str + 21");

    object item = clone_object("/lib/tests/support/items/testSword.c");
    move_object(item, Inventory);
    ExpectEq(13, Inventory->canCarry(item), "Galvorn sword by default weighs 7");

    item->set("weight", 100);
    ExpectFalse(Inventory->canCarry(item), "returns false when max carry is exceeded");
}

/////////////////////////////////////////////////////////////////////////////
void can_put_and_getReturnsOne()
{
    ExpectTrue(Inventory->can_put_and_get());
}

/////////////////////////////////////////////////////////////////////////////
void UsingEquipmentOfTypeReturnsTrueForWeaponWhenCorrectTypeIsUsed()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    ExpectTrue(weapon->equip("blah"), "weapon equip called");
    ExpectTrue(Inventory->usingEquipmentOfType("long sword"), "correct weapon type wielded");
}

/////////////////////////////////////////////////////////////////////////////
void UsingEquipmentOfTypeReturnsFalseForWeaponWhenIncorrectTypeIsUsed()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("weapon type", "axe");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);

    ExpectTrue(weapon->equip("blah"), "weapon equip called");
    ExpectFalse(Inventory->usingEquipmentOfType("long sword"), "incorrect weapon type wielded");
}

/////////////////////////////////////////////////////////////////////////////
void UsingEquipmentOfTypeReturnsFalseWhenNoEquipmentIsUsed()
{
    ExpectFalse(objectp(Inventory->usingEquipmentOfType("long sword")), "correct weapon type wielded");
}

/////////////////////////////////////////////////////////////////////////////
void UsingEquipmentOfTypeReturnsTrueForArmorWhenCorrectTypeIsUsed()
{
    object armor = clone_object("/lib/items/armor");
    armor->set("name", "blah");
    armor->set("armor type", "chainmail");
    armor->set("equipment locations", Armor);
    move_object(armor, Inventory);

    ExpectTrue(armor->equip("blah"), "armor equip called");
    ExpectTrue(Inventory->usingEquipmentOfType("chainmail"), "correct armor type worn");
}

/////////////////////////////////////////////////////////////////////////////
void UsingEquipmentOfTypeReturnsFalseForArmorWhenIncorrectTypeIsUsed()
{
    object armor = clone_object("/lib/items/armor");
    armor->set("name", "blah");
    armor->set("armor type", "soft leather");
    armor->set("equipment locations", Armor);
    move_object(armor, Inventory);

    ExpectTrue(armor->equip("blah"), "armor equip called");
    ExpectFalse(Inventory->usingEquipmentOfType("chainmail"), "incorrect armor type worn");
}

/////////////////////////////////////////////////////////////////////////////
void UsingEquipmentOfTypeReturnsTrueForEquipmentWhenCorrectTypeIsUsed()
{
    object armor = clone_object("/lib/items/armor");
    armor->set("name", "blah");
    armor->set("armor type", "chainmail");
    armor->set("equipment locations", Gloves);
    move_object(armor, Inventory);

    ExpectTrue(armor->equip("blah"), "armor equip called");
    ExpectTrue(Inventory->usingEquipmentOfType("gloves"), "correct armor type worn");
}

/////////////////////////////////////////////////////////////////////////////
void UsingEquipmentOfTypeReturnsFalseForEquipmentWhenIncorrectTypeIsUsed()
{
    object armor = clone_object("/lib/items/armor");
    armor->set("name", "blah");
    armor->set("armor type", "chainmail");
    armor->set("equipment locations", Cloak);
    move_object(armor, Inventory);

    ExpectTrue(armor->equip("blah"), "armor equip called");
    ExpectFalse(Inventory->usingEquipmentOfType("gloves"), "incorrect armor type worn");
}

/////////////////////////////////////////////////////////////////////////////
void UsingEquipmentOfTypeReturnsCorrectlyForMultipleEquippedItems()
{
    object armor = clone_object("/lib/items/armor");
    armor->set("name", "blah");
    armor->set("armor type", "chainmail");
    armor->set("equipment locations", Cloak);
    move_object(armor, Inventory);
    ExpectTrue(armor->equip("blah"), "cloak equip called");

    armor = clone_object("/lib/items/armor");
    armor->set("name", "blarg");
    armor->set("armor type", "chainmail");
    armor->set("equipment locations", Armor);
    move_object(armor, Inventory);
    ExpectTrue(armor->equip("blarg"), "armor equip called");

    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "weapon");
    weapon->set("weapon type", "axe");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Inventory);
    ExpectTrue(weapon->equip("weapon"), "weapon equip called");

    ExpectFalse(Inventory->usingEquipmentOfType("gloves"), "gloves not worn");
    ExpectFalse(Inventory->usingEquipmentOfType("long sword"), "long sword not wielded");
    ExpectTrue(Inventory->usingEquipmentOfType("cloak"), "cloak worn");
    ExpectTrue(Inventory->usingEquipmentOfType("chainmail"), "chainmail worn");
    ExpectFalse(Inventory->usingEquipmentOfType("soft leather"), "leather not worn");
    ExpectTrue(Inventory->usingEquipmentOfType("axe"), "axe wielded");
}

/////////////////////////////////////////////////////////////////////////////
void InventoryDescriptionReturnsCorrectDescription()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("user description", "##UserName## has a shiny blah!");

    ExpectEq("", Inventory->inventoryDescription());

    move_object(weapon, Inventory);
    ExpectEq("Bob has a shiny blah!\n", Inventory->inventoryDescription());
}

/////////////////////////////////////////////////////////////////////////////
void InventoryDescriptionAddsRegisteredModifiers()
{
    object modifier = clone_object("/lib/items/modifierObject");
    modifier->set("fully qualified name", "thingy");
    modifier->set("user description", "##UserSubjective## sees an object registered but not in ##UserPossessive## inventory");
    ExpectEq(1, modifier->set("registration list", ({ Inventory })), "registration list can be set");

    ExpectEq("He sees an object registered but not in his inventory\n", Inventory->inventoryDescription());
}

/////////////////////////////////////////////////////////////////////////////
void InventoryDescriptionReturnsCorrectListOfDescriptions()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("user description", "##UserName## has a shiny blah!");
    move_object(weapon, Inventory);

    weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah2");
    move_object(weapon, Inventory);

    object armor = clone_object("/lib/items/armor");
    armor->set("name", "stuff");
    armor->set("user description", "##UserSubjective## is using stuff");
    move_object(armor, Inventory);

    object item = clone_object("/lib/items/item");
    item->set("user description", "##UserSubjective## has a hidden item.");
    move_object(item, Inventory);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier->set("fully qualified name", "thingy");
    modifier->set("user description", "##UserSubjective## sees an object registered but not in ##UserPossessive## inventory");
    ExpectEq(1, modifier->set("registration list", ({ Inventory })), "registration list can be set");

    modifier = clone_object("/lib/items/modifierObject");
    modifier->set("fully qualified name", "thingy2");
    modifier->set("user description", "This item is not seen twice");
    move_object(modifier, Inventory);
    ExpectEq(1, modifier->set("registration list", ({ Inventory })), "registration list can be set");

    string expectedMessage = "He is using stuff\nHe has a hidden item.\nHe sees an object registered but not in his inventory\nThis item is not seen twice\nBob has a shiny blah!\n";
    ExpectEq(expectedMessage, Inventory->inventoryDescription());
}

/////////////////////////////////////////////////////////////////////////////
void EquippingSecondItemOfTypeUnequipsFirstItemAndEquipsSecond()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("blueprint", "long sword");
    weapon->set("name", "blah");
    move_object(weapon, Inventory);

    object weapon2 = clone_object("/lib/items/weapon");
    weapon2->set("blueprint", "long sword");
    weapon2->set("name", "blah2");
    move_object(weapon2, Inventory);

    ExpectFalse(Inventory->isEquipped(weapon), "weapon initially unequipped");
    ExpectFalse(Inventory->isEquipped(weapon2), "weapon2 initially unequipped");
    ExpectTrue(weapon->equip("blah"), "weapon equip called");
    ExpectTrue(Inventory->isEquipped(weapon), "weapon equipped after weapon equip called");
    ExpectFalse(Inventory->isEquipped(weapon2), "weapon2 unequipped after weapon equip called");
    ExpectTrue(weapon2->equip("blah2"), "weapon2 equip called");
    ExpectFalse(Inventory->isEquipped(weapon), "weapon unequipped after weapon2 equip called");
    ExpectTrue(Inventory->isEquipped(weapon2), "weapon2 equipped after weapon2 equip called");
}

/////////////////////////////////////////////////////////////////////////////
void CanEquipTwoRings()
{
    object ring = clone_object("/lib/instances/items/armor/accessories/ring.c");
    ring->set("name", "Ring of Weasels");
    move_object(ring, Inventory);

    object ring2 = clone_object("/lib/instances/items/armor/accessories/ring.c");
    ring2->set("name", "Ring of Spiffiness");
    move_object(ring2, Inventory);

    ExpectFalse(Inventory->isEquipped(ring), "first initially unequipped");
    ExpectFalse(Inventory->isEquipped(ring2), "second initially unequipped");
    ExpectEq(0x00001000, ring->query("equipment locations"));
    ExpectEq(0x00001000, ring2->query("equipment locations"));
    command("wear first Ring of Weasels", Inventory);
    ExpectTrue(Inventory->isEquipped(ring), "first ring is equipped");
    ExpectFalse(Inventory->isEquipped(ring2), "second ring unequipped");
    command("wear second Ring of Spiffiness", Inventory);
    ExpectEq(0x00001000, ring->query("equipment locations"));
    ExpectEq(0x00002000, ring2->query("equipment locations"));
    ExpectTrue(Inventory->isEquipped(ring), "first ring still equipped");
    ExpectTrue(Inventory->isEquipped(ring2), "second ring is equipped");
}

/////////////////////////////////////////////////////////////////////////////
void UnequippingSecondRingResetsTheMaskToRing()
{
    object ring = clone_object("/lib/instances/items/armor/accessories/ring.c");
    ring->set("name", "Ring of Weasels");
    move_object(ring, Inventory);

    ExpectEq(0x00001000, ring->query("equipment locations"));
    ExpectFalse(Inventory->isEquipped(ring), "first ring is equipped");
    command("wear second ring", Inventory);
    ExpectTrue(Inventory->isEquipped(ring), "first ring is equipped");
    ExpectEq(0x00002000, ring->query("equipment locations"));
    command("remove ring", Inventory);
    ExpectEq(0x00001000, ring->query("equipment locations"));
    ExpectFalse(Inventory->isEquipped(ring), "first ring is equipped");
}
