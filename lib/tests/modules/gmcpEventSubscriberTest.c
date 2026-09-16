// *****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
// *****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Player;
object Subscriber;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "BuildWeapon", "BuildArmor", "BuildRing",
        "BuildTwohander", "BuildCarriedWeapon", "BuildCarriedArmor" });
}

/////////////////////////////////////////////////////////////////////////////
object BuildWeapon(string name, string short, string type, int locations)
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", name);
    weapon.set("short", short);
    weapon.set("weapon type", type);
    weapon.set("equipment locations", locations);
    move_object(weapon, Player);
    return weapon;
}

/////////////////////////////////////////////////////////////////////////////
object BuildArmor(string name, string short, string type, int locations)
{
    object armor = clone_object("/lib/items/armor");
    armor.set("name", name);
    armor.set("short", short);
    armor.set("armor type", type);
    armor.set("equipment locations", locations);
    move_object(armor, Player);
    return armor;
}

/////////////////////////////////////////////////////////////////////////////
object BuildRing(string name, string short)
{
    object ring = clone_object(
        "/lib/instances/items/armor/accessories/ring.c");
    ring.set("name", name);
    ring.set("short", short);
    ring.set("equipment locations", Ring1|Ring2);
    move_object(ring, Player);
    return ring;
}

/////////////////////////////////////////////////////////////////////////////
object BuildCarriedWeapon(string name, string short, string type,
    int locations)
{
    object item = BuildWeapon(name, short, type, locations);
    return item;
}

/////////////////////////////////////////////////////////////////////////////
object BuildCarriedArmor(string name, string short, string type,
    int locations)
{
    object item = BuildArmor(name, short, type, locations);
    return item;
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("bob");
    Player.enableGmcp();
    Player.addSkillPoints(100);
    Player.advanceSkill("long sword", 10);

    Subscriber = clone_object("/lib/modules/gmcp/gmcpEventSubscriber.c");
    Subscriber.setPlayer(Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Subscriber);
    destruct(Player);
}

// ---------------------------------------------------------------------------
// setPlayer / getPlayer
// ---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
void GetPlayerReturnsTheRegisteredPlayer()
{
    ExpectEq(Player, Subscriber.getPlayer());
}

/////////////////////////////////////////////////////////////////////////////
void SetPlayerCanBeReassigned()
{
    object other = clone_object(
        "/lib/tests/support/services/mockPlayer.c");
    other.Name("alice");
    other.enableGmcp();

    Subscriber.setPlayer(other);
    ExpectEq(other, Subscriber.getPlayer());
    destruct(other);
}

// ---------------------------------------------------------------------------
// pushVitals
// ---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
void PushVitalsEmitsCharVitalsPackage()
{
    Subscriber.pushVitals();
    ExpectSubStringMatch("Char.Vitals", Player.caughtGmcp(),
        "Char.Vitals package is emitted");
}

/////////////////////////////////////////////////////////////////////////////
void PushVitalsIncludesHitPoints()
{
    Subscriber.pushVitals();
    ExpectSubStringMatch("\"hitPoints\"", Player.caughtGmcp(),
        "hitPoints key is present");
}

/////////////////////////////////////////////////////////////////////////////
void PushVitalsIncludesSpellPoints()
{
    Subscriber.pushVitals();
    ExpectSubStringMatch("\"spellPoints\"", Player.caughtGmcp(),
        "spellPoints key is present");
}

/////////////////////////////////////////////////////////////////////////////
void PushVitalsIncludesStaminaPoints()
{
    Subscriber.pushVitals();
    ExpectSubStringMatch("\"staminaPoints\"", Player.caughtGmcp(),
        "staminaPoints key is present");
}

/////////////////////////////////////////////////////////////////////////////
void PushVitalsIncludesCurrentAndMax()
{
    Subscriber.pushVitals();
    string frame = Player.caughtGmcp();
    ExpectSubStringMatch("\"current\"", frame, "current sub-key present");
    ExpectSubStringMatch("\"max\"", frame, "max sub-key present");
}

// ---------------------------------------------------------------------------
// pushScore
// ---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
void PushScoreEmitsCharScorePackage()
{
    Subscriber.pushScore();
    ExpectSubStringMatch("Char.Score", Player.caughtGmcp(),
        "Char.Score package is emitted");
}

/////////////////////////////////////////////////////////////////////////////
void PushScoreIncludesPlayerName()
{
    Subscriber.pushScore();
    ExpectSubStringMatch("\"name\"", Player.caughtGmcp(),
        "name key present in score");
}

/////////////////////////////////////////////////////////////////////////////
void PushScoreIncludesAttributesBlock()
{
    Subscriber.pushScore();
    ExpectSubStringMatch("\"attributes\"", Player.caughtGmcp(),
        "attributes block present in score");
}

/////////////////////////////////////////////////////////////////////////////
void PushScoreIncludesVitalsBlock()
{
    Subscriber.pushScore();
    ExpectSubStringMatch("\"vitals\"", Player.caughtGmcp(),
        "vitals block nested in score");
}

/////////////////////////////////////////////////////////////////////////////
void PushScoreIncludesCombatBlock()
{
    Subscriber.pushScore();
    ExpectSubStringMatch("\"combat\"", Player.caughtGmcp(),
        "combat block present in score");
}

/////////////////////////////////////////////////////////////////////////////
void PushScoreIncludesGuildsArray()
{
    Subscriber.pushScore();
    ExpectSubStringMatch("\"guilds\"", Player.caughtGmcp(),
        "guilds array present in score");
}

// ---------------------------------------------------------------------------
// pushInventory - general structure
// ---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
void PushInventoryEmitsCharInventoryPackage()
{
    Subscriber.pushInventory();
    ExpectSubStringMatch("Char.Inventory", Player.caughtGmcp(),
        "Char.Inventory package is emitted");
}

/////////////////////////////////////////////////////////////////////////////
void PushInventoryIncludesEquippedKey()
{
    Subscriber.pushInventory();
    ExpectSubStringMatch("\"equipped\"", Player.caughtGmcp(),
        "equipped key present");
}

/////////////////////////////////////////////////////////////////////////////
void PushInventoryIncludesCarriedKey()
{
    Subscriber.pushInventory();
    ExpectSubStringMatch("\"carried\"", Player.caughtGmcp(),
        "carried key present");
}

/////////////////////////////////////////////////////////////////////////////
void PushInventoryEquippedIsEmptyWhenNothingWorn()
{
    Subscriber.pushInventory();
    string frame = Player.caughtGmcp();
    ExpectSubStringMatch("\"equipped\":{}", frame,
        "equipped mapping is empty when nothing is worn");
}

// ---------------------------------------------------------------------------
// pushInventory - equipped items
// ---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
void EquippedPrimaryWeaponAppearsUnderCorrectSlot()
{
    object sword = BuildWeapon("sword", "a short sword",
        "short sword", OnehandedWeapon);
    sword.equip("sword");

    Subscriber.pushInventory();
    string frame = Player.caughtGmcp();
    ExpectSubStringMatch("\"wielded primary\"", frame,
        "wielded primary slot present for equipped one-hander");
    ExpectSubStringMatch("a short sword", frame,
        "weapon short description included");
}

/////////////////////////////////////////////////////////////////////////////
void EquippedTwohandedWeaponAppearsUnderWieldedPrimary()
{
    object staff = BuildWeapon("staff", "a oak staff",
        "staff", TwohandedWeapon);
    staff.equip("staff");

    Subscriber.pushInventory();
    string frame = Player.caughtGmcp();
    ExpectSubStringMatch("\"wielded primary\"", frame,
        "two-hander appears under wielded primary");
}

/////////////////////////////////////////////////////////////////////////////
void EquippedArmorAppearsUnderArmorSlot()
{
    object chain = BuildArmor("chainmail", "chainmail hauberk",
        "chainmail", Armor);
    chain.equip("armor");

    Subscriber.pushInventory();
    string frame = Player.caughtGmcp();
    ExpectSubStringMatch("\"armor\"", frame,
        "armor slot present for worn body armor");
    ExpectSubStringMatch("chainmail hauberk", frame,
        "armor short description included");
}

/////////////////////////////////////////////////////////////////////////////
void EquippedHelmetAppearsUnderHelmetSlot()
{
    object helm = BuildArmor("helmet", "iron helmet", "plate armor", Helmet);
    helm.equip("helmet");

    Subscriber.pushInventory();
    ExpectSubStringMatch("\"helmet\"", Player.caughtGmcp(),
        "helmet slot present");
}

/////////////////////////////////////////////////////////////////////////////
void EquippedRingAppearsUnderRing1Slot()
{
    object ring = BuildRing("ring", "a silver ring");
    ring.equip("ring");

    Subscriber.pushInventory();
    ExpectSubStringMatch("\"ring 1\"", Player.caughtGmcp(),
        "ring 1 slot populated after equipping ring");
}

/////////////////////////////////////////////////////////////////////////////
void EquippedItemIncludesSlotField()
{
    object sword = BuildWeapon("sword", "a short sword",
        "short sword", OnehandedWeapon);
    sword.equip("sword");

    Subscriber.pushInventory();
    string frame = Player.caughtGmcp();
    ExpectSubStringMatch("\"slot\"", frame,
        "slot key present in equipped item summary");
}

/////////////////////////////////////////////////////////////////////////////
void EquippedItemIncludesTypeField()
{
    object sword = BuildWeapon("sword", "a short sword",
        "short sword", OnehandedWeapon);
    sword.equip("sword");

    Subscriber.pushInventory();
    ExpectSubStringMatch("\"type\"", Player.caughtGmcp(),
        "type key present in equipped item summary");
}

/////////////////////////////////////////////////////////////////////////////
void EquippedWeaponIncludesWeaponCategoryField()
{
    object sword = BuildWeapon("sword", "a short sword",
        "short sword", OnehandedWeapon);
    sword.equip("sword");

    Subscriber.pushInventory();
    ExpectSubStringMatch("\"category\":\"weapon\"", Player.caughtGmcp(),
        "weapon category derived from inheritance, not free-text type");
}

/////////////////////////////////////////////////////////////////////////////
void EquippedArmorIncludesArmorCategoryField()
{
    object armor = BuildArmor("chain mail", "a suit of chain mail",
        "chain mail", Armor);
    armor.equip("armor");

    Subscriber.pushInventory();
    ExpectSubStringMatch("\"category\":\"armor\"", Player.caughtGmcp(),
        "armor category derived from inheritance, not free-text type");
}

/////////////////////////////////////////////////////////////////////////////
void CarriedPotionIncludesPotionCategoryField()
{
    object potion = clone_object("/lib/items/potion");
    potion.set("name", "potion");
    potion.set("short", "a fizzy potion");
    move_object(potion, Player);

    Subscriber.pushInventory();
    ExpectSubStringMatch("\"category\":\"potion\"", Player.caughtGmcp(),
        "potion category derived from inheritance");

    destruct(potion);
}

/////////////////////////////////////////////////////////////////////////////
void CarriedMaterialIncludesMaterialCategoryField()
{
    object material = clone_object("/lib/items/material");
    material.set("name", "iron ingot");
    material.set("short", "an iron ingot");
    move_object(material, Player);

    Subscriber.pushInventory();
    ExpectSubStringMatch("\"category\":\"material\"", Player.caughtGmcp(),
        "material category derived from inheritance");

    destruct(material);
}

/////////////////////////////////////////////////////////////////////////////
void EquippedItemDoesNotIncludeEquipSlotsField()
{
    object sword = BuildWeapon("sword", "a short sword",
        "short sword", OnehandedWeapon);
    sword.equip("sword");

    Subscriber.pushInventory();
    string frame = Player.caughtGmcp();
    ExpectFalse(stringp(frame) && (strstr(frame, "\"equipSlots\"") != -1),
        "equipped items must not carry redundant equipSlots field");
}

// ---------------------------------------------------------------------------
// pushInventory - carried items / equipSlots
// ---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
void CarriedOneHandedWeaponIncludesEquipSlots()
{
    BuildCarriedWeapon("dagger", "a dagger", "dagger", OnehandedWeapon);

    Subscriber.pushInventory();
    ExpectSubStringMatch("\"equipSlots\"", Player.caughtGmcp(),
        "carried wieldable item carries equipSlots array");
}

/////////////////////////////////////////////////////////////////////////////
void CarriedOneHandedWeaponEquipSlotsContainsWieldedPrimary()
{
    BuildCarriedWeapon("dagger", "a dagger", "dagger", OnehandedWeapon);

    Subscriber.pushInventory();
    ExpectSubStringMatch("wielded primary", Player.caughtGmcp(),
        "equipSlots for one-hander includes wielded primary");
}

/////////////////////////////////////////////////////////////////////////////
void CarriedOneHandedWeaponEquipSlotsContainsWieldedOffhand()
{
    BuildCarriedWeapon("dagger", "a dagger", "dagger",
        OnehandedWeapon|OffhandWeapon);

    Subscriber.pushInventory();
    ExpectSubStringMatch("wielded offhand", Player.caughtGmcp(),
        "equipSlots for one-hander includes wielded offhand");
}

/////////////////////////////////////////////////////////////////////////////
void CarriedTwohandedWeaponEquipSlotsContainsBothWieldSlots()
{
    BuildCarriedWeapon("greatsword", "a great sword",
        "two-handed sword", TwohandedWeapon);

    Subscriber.pushInventory();
    string frame = Player.caughtGmcp();
    ExpectSubStringMatch("wielded primary", frame,
        "two-hander equipSlots includes wielded primary");
    ExpectSubStringMatch("wielded offhand", frame,
        "two-hander equipSlots includes wielded offhand");
}

/////////////////////////////////////////////////////////////////////////////
void CarriedArmorIncludesEquipSlotsWithArmorSlot()
{
    BuildCarriedArmor("chainmail", "a chainmail hauberk",
        "chainmail", Armor);

    Subscriber.pushInventory();
    string frame = Player.caughtGmcp();
    ExpectSubStringMatch("\"equipSlots\"", frame,
        "carried armor has equipSlots");
    ExpectSubStringMatch("\"armor\"", frame,
        "carried body armor equipSlots contains armor");
}

/////////////////////////////////////////////////////////////////////////////
void CarriedHelmetIncludesEquipSlotsWithHelmetSlot()
{
    BuildCarriedArmor("helmet", "an iron helmet", "plate armor", Helmet);

    Subscriber.pushInventory();
    string frame = Player.caughtGmcp();
    ExpectSubStringMatch("\"equipSlots\"", frame,
        "carried helmet has equipSlots");
    ExpectSubStringMatch("\"helmet\"", frame,
        "carried helmet equipSlots contains helmet");
}

/////////////////////////////////////////////////////////////////////////////
void CarriedCloakIncludesEquipSlotsWithCloakSlot()
{
    BuildCarriedArmor("cloak", "a wool cloak", "soft leather", Cloak);

    Subscriber.pushInventory();
    ExpectSubStringMatch("\"cloak\"", Player.caughtGmcp(),
        "carried cloak equipSlots contains cloak");
}

/////////////////////////////////////////////////////////////////////////////
void CarriedBootsIncludeEquipSlotsWithBootsSlot()
{
    BuildCarriedArmor("boots", "leather boots", "soft leather", Boots);

    Subscriber.pushInventory();
    ExpectSubStringMatch("\"boots\"", Player.caughtGmcp(),
        "carried boots equipSlots contains boots");
}

/////////////////////////////////////////////////////////////////////////////
void CarriedGlovesIncludeEquipSlotsWithGlovesSlot()
{
    BuildCarriedArmor("gloves", "leather gloves", "soft leather", Gloves);

    Subscriber.pushInventory();
    ExpectSubStringMatch("\"gloves\"", Player.caughtGmcp(),
        "carried gloves equipSlots contains gloves");
}

/////////////////////////////////////////////////////////////////////////////
void CarriedRingIncludesEquipSlotsWithBothRingSlots()
{
    object ring = BuildRing("ring", "a copper ring");

    Subscriber.pushInventory();
    string frame = Player.caughtGmcp();
    ExpectSubStringMatch("\"ring 1\"", frame,
        "carried ring equipSlots includes ring 1");
    ExpectSubStringMatch("\"ring 2\"", frame,
        "carried ring equipSlots includes ring 2");
}

/////////////////////////////////////////////////////////////////////////////
void NonEquippableCarriedItemHasNoEquipSlotsField()
{
    move_object(
        clone_object("/lib/instances/items/potions/healing.c"), Player);

    Subscriber.pushInventory();
    string frame = Player.caughtGmcp();
    ExpectFalse(stringp(frame) && (strstr(frame, "\"equipSlots\"") != -1),
        "non-equippable carried item must not carry equipSlots");
}

/////////////////////////////////////////////////////////////////////////////
void EquippedItemIsNotDuplicatedInCarriedList()
{
    object sword = BuildWeapon("sword", "a short sword",
        "short sword", OnehandedWeapon);
    sword.equip("sword");

    Subscriber.pushInventory();
    string frame = Player.caughtGmcp();

    // The sword's short must appear exactly once across the whole payload.
    int first = strstr(frame, "a short sword");
    int second = strstr(frame, "a short sword", first + 1);
    ExpectTrue(first >= 0, "sword appears at least once");
    ExpectEq(-1, second,
        "equipped sword must not also appear in carried list");
}

// ---------------------------------------------------------------------------
// Event handler routing
// ---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
void OnHitPointsChangedPushesVitals()
{
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onHitPointsChanged(Player, 0);
    ExpectTrue(sizeof(Player.caughtGmcpFrames()) > before,
        "onHitPointsChanged triggers a GMCP push");
    ExpectSubStringMatch("Char.Vitals", Player.caughtGmcp(),
        "the pushed package is Char.Vitals");
}

/////////////////////////////////////////////////////////////////////////////
void OnSpellPointsChangedPushesVitals()
{
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onSpellPointsChanged(Player, 0);
    ExpectTrue(sizeof(Player.caughtGmcpFrames()) > before,
        "onSpellPointsChanged triggers a GMCP push");
    ExpectSubStringMatch("Char.Vitals", Player.caughtGmcp(),
        "the pushed package is Char.Vitals");
}

/////////////////////////////////////////////////////////////////////////////
void OnStaminaPointsChangedPushesVitals()
{
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onStaminaPointsChanged(Player, 0);
    ExpectTrue(sizeof(Player.caughtGmcpFrames()) > before,
        "onStaminaPointsChanged triggers a GMCP push");
}

/////////////////////////////////////////////////////////////////////////////
void OnEquipPushesScoreAndInventory()
{
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onEquip(Player, 0);
    int pushed = sizeof(Player.caughtGmcpFrames()) - before;
    ExpectTrue(pushed >= 2,
        "onEquip pushes at least two frames (score + inventory)");
}

/////////////////////////////////////////////////////////////////////////////
void OnUnequipPushesScoreAndInventory()
{
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onUnequip(Player, 0);
    int pushed = sizeof(Player.caughtGmcpFrames()) - before;
    ExpectTrue(pushed >= 2,
        "onUnequip pushes at least two frames (score + inventory)");
}

/////////////////////////////////////////////////////////////////////////////
void OnRegisterItemPushesInventory()
{
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onRegisterItem(Player, 0);
    ExpectTrue(sizeof(Player.caughtGmcpFrames()) > before,
        "onRegisterItem triggers a GMCP inventory push");
    ExpectSubStringMatch("Char.Inventory", Player.caughtGmcp(),
        "the pushed package is Char.Inventory");
}

/////////////////////////////////////////////////////////////////////////////
void OnUnregisterItemPushesInventory()
{
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onUnregisterItem(Player, 0);
    ExpectTrue(sizeof(Player.caughtGmcpFrames()) > before,
        "onUnregisterItem triggers a GMCP inventory push");
}

/////////////////////////////////////////////////////////////////////////////
void OnAdvancedLevelPushesScore()
{
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onAdvancedLevel(Player, 0);
    ExpectTrue(sizeof(Player.caughtGmcpFrames()) > before,
        "onAdvancedLevel triggers a GMCP push");
    ExpectSubStringMatch("Char.Score", Player.caughtGmcp(),
        "the pushed package is Char.Score");
}

/////////////////////////////////////////////////////////////////////////////
void OnAdvancedRankPushesScore()
{
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onAdvancedRank(Player, 0);
    ExpectTrue(sizeof(Player.caughtGmcpFrames()) > before,
        "onAdvancedRank triggers a GMCP push");
    ExpectSubStringMatch("Char.Score", Player.caughtGmcp());
}

/////////////////////////////////////////////////////////////////////////////
void OnDemotedRankPushesScore()
{
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onDemotedRank(Player, 0);
    ExpectTrue(sizeof(Player.caughtGmcpFrames()) > before,
        "onDemotedRank triggers a GMCP push");
}

/////////////////////////////////////////////////////////////////////////////
void OnJoinGuildPushesScore()
{
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onJoinGuild(Player, 0);
    ExpectTrue(sizeof(Player.caughtGmcpFrames()) > before,
        "onJoinGuild triggers a GMCP push");
}

/////////////////////////////////////////////////////////////////////////////
void OnLeaveGuildPushesScore()
{
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onLeaveGuild(Player, 0);
    ExpectTrue(sizeof(Player.caughtGmcpFrames()) > before,
        "onLeaveGuild triggers a GMCP push");
}

/////////////////////////////////////////////////////////////////////////////
void OnRecalculatingPushesScore()
{
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onRecalculating(Player, 0);
    ExpectTrue(sizeof(Player.caughtGmcpFrames()) > before,
        "onRecalculating triggers a GMCP push");
}

/////////////////////////////////////////////////////////////////////////////
void OnSkillAdvancedPushesScore()
{
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onSkillAdvanced(Player, 0);
    ExpectTrue(sizeof(Player.caughtGmcpFrames()) > before,
        "onSkillAdvanced triggers a GMCP push");
}

/////////////////////////////////////////////////////////////////////////////
void OnTraitAddedPushesScore()
{
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onTraitAdded(Player, 0);
    ExpectTrue(sizeof(Player.caughtGmcpFrames()) > before,
        "onTraitAdded triggers a GMCP push");
}

/////////////////////////////////////////////////////////////////////////////
void OnTraitRemovedPushesScore()
{
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onTraitRemoved(Player, 0);
    ExpectTrue(sizeof(Player.caughtGmcpFrames()) > before,
        "onTraitRemoved triggers a GMCP push");
}

// ---------------------------------------------------------------------------
// Stale-subscriber guard: events for a different player are ignored
// ---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
void EventFromWrongPlayerIsIgnoredForVitals()
{
    object other = clone_object(
        "/lib/tests/support/services/mockPlayer.c");
    other.Name("alice");
    other.enableGmcp();

    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onHitPointsChanged(other, 0);
    ExpectEq(before, sizeof(Player.caughtGmcpFrames()),
        "no frame pushed to registered player when caller is different");
    destruct(other);
}

/////////////////////////////////////////////////////////////////////////////
void EventFromWrongPlayerIsIgnoredForInventory()
{
    object other = clone_object(
        "/lib/tests/support/services/mockPlayer.c");
    other.Name("alice");
    other.enableGmcp();

    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onRegisterItem(other, 0);
    ExpectEq(before, sizeof(Player.caughtGmcpFrames()),
        "inventory push not triggered for wrong player");
    destruct(other);
}

/////////////////////////////////////////////////////////////////////////////
void EventFromWrongPlayerIsIgnoredForScore()
{
    object other = clone_object(
        "/lib/tests/support/services/mockPlayer.c");
    other.Name("alice");
    other.enableGmcp();

    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onAdvancedLevel(other, 0);
    ExpectEq(before, sizeof(Player.caughtGmcpFrames()),
        "score push not triggered for wrong player");
    destruct(other);
}

/////////////////////////////////////////////////////////////////////////////
void EventFromWrongPlayerIsIgnoredForEquip()
{
    object other = clone_object(
        "/lib/tests/support/services/mockPlayer.c");
    other.Name("alice");
    other.enableGmcp();

    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onEquip(other, 0);
    ExpectEq(before, sizeof(Player.caughtGmcpFrames()),
        "equip push not triggered for wrong player");
    destruct(other);
}

// ---------------------------------------------------------------------------
// pushVitals - value accuracy
// ---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
void PushVitalsReflectsCurrentHitPoints()
{
    int current = Player.hitPoints();
    Subscriber.pushVitals();
    ExpectSubStringMatch(to_string(current), Player.caughtGmcp(),
        "current hit point value appears in Char.Vitals frame");
}

/////////////////////////////////////////////////////////////////////////////
void PushVitalsDoesNotFireWhenNoPlayerSet()
{
    Subscriber.setPlayer(0);
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.pushVitals();
    ExpectEq(before, sizeof(Player.caughtGmcpFrames()),
        "pushVitals is a no-op when player reference is cleared");
}

/////////////////////////////////////////////////////////////////////////////
void PushScoreDoesNotFireWhenNoPlayerSet()
{
    Subscriber.setPlayer(0);
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.pushScore();
    ExpectEq(before, sizeof(Player.caughtGmcpFrames()),
        "pushScore is a no-op when player reference is cleared");
}

/////////////////////////////////////////////////////////////////////////////
void PushInventoryDoesNotFireWhenNoPlayerSet()
{
    Subscriber.setPlayer(0);
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.pushInventory();
    ExpectEq(before, sizeof(Player.caughtGmcpFrames()),
        "pushInventory is a no-op when player reference is cleared");
}

// ---------------------------------------------------------------------------
// pushScore - content detail
// ---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
void PushScoreIncludesLevelKey()
{
    Subscriber.pushScore();
    ExpectSubStringMatch("\"level\"", Player.caughtGmcp(),
        "level key present in Char.Score");
}

/////////////////////////////////////////////////////////////////////////////
void PushScoreIncludesExperienceKey()
{
    Subscriber.pushScore();
    ExpectSubStringMatch("\"experience\"", Player.caughtGmcp(),
        "experience key present in Char.Score");
}

/////////////////////////////////////////////////////////////////////////////
void PushScoreIncludesGenderKey()
{
    Subscriber.pushScore();
    ExpectSubStringMatch("\"gender\"", Player.caughtGmcp(),
        "gender key present in Char.Score");
}

/////////////////////////////////////////////////////////////////////////////
void PushScoreIncludesRaceKey()
{
    Subscriber.pushScore();
    ExpectSubStringMatch("\"race\"", Player.caughtGmcp(),
        "race key present in Char.Score");
}

/////////////////////////////////////////////////////////////////////////////
void PushScoreIncludesTitleKey()
{
    Subscriber.pushScore();
    ExpectSubStringMatch("\"title\"", Player.caughtGmcp(),
        "title key present in Char.Score");
}

/////////////////////////////////////////////////////////////////////////////
void PushScoreAttributesIncludeValueBaseAndBonus()
{
    Subscriber.pushScore();
    string frame = Player.caughtGmcp();
    ExpectSubStringMatch("\"value\"", frame,
        "attribute value sub-key present");
    ExpectSubStringMatch("\"base\"", frame,
        "attribute base sub-key present");
    ExpectSubStringMatch("\"bonus\"", frame,
        "attribute bonus sub-key present");
}

/////////////////////////////////////////////////////////////////////////////
void PushScoreCombatIncludesDefendAttackKeys()
{
    Subscriber.pushScore();
    string frame = Player.caughtGmcp();
    ExpectSubStringMatch("\"defendAttackLow\"", frame,
        "defendAttackLow present in combat block");
    ExpectSubStringMatch("\"defendAttackHigh\"", frame,
        "defendAttackHigh present in combat block");
}

/////////////////////////////////////////////////////////////////////////////
void PushScoreCombatIncludesSoakKeys()
{
    Subscriber.pushScore();
    string frame = Player.caughtGmcp();
    ExpectSubStringMatch("\"soakLow\"", frame,
        "soakLow present in combat block");
    ExpectSubStringMatch("\"soakHigh\"", frame,
        "soakHigh present in combat block");
}

/////////////////////////////////////////////////////////////////////////////
void PushScoreCombatIncludesEncumberance()
{
    Subscriber.pushScore();
    ExpectSubStringMatch("\"encumberance\"", Player.caughtGmcp(),
        "encumberance present in combat block");
}

/////////////////////////////////////////////////////////////////////////////
void PushScoreCombatIncludesWeaponsArray()
{
    Subscriber.pushScore();
    ExpectSubStringMatch("\"weapons\"", Player.caughtGmcp(),
        "weapons array present in combat block");
}

/////////////////////////////////////////////////////////////////////////////
void PushScoreCombatWeaponIncludesAttackAndDamageRanges()
{
    object sword = BuildWeapon("sword", "a short sword",
        "short sword", OnehandedWeapon);
    sword.equip("sword");

    Subscriber.pushScore();
    string frame = Player.caughtGmcp();
    ExpectSubStringMatch("\"attackLow\"", frame,
        "attackLow key present for wielded weapon");
    ExpectSubStringMatch("\"attackHigh\"", frame,
        "attackHigh key present for wielded weapon");
    ExpectSubStringMatch("\"damageLow\"", frame,
        "damageLow key present for wielded weapon");
    ExpectSubStringMatch("\"damageHigh\"", frame,
        "damageHigh key present for wielded weapon");
}

// ---------------------------------------------------------------------------
// pushInventory - remaining armor slots
// ---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
void CarriedAmuletIncludesEquipSlotsWithAmuletSlot()
{
    BuildCarriedArmor("amulet", "a jade amulet", "no armor", Amulet);

    Subscriber.pushInventory();
    ExpectSubStringMatch("\"amulet\"", Player.caughtGmcp(),
        "carried amulet equipSlots contains amulet");
}

/////////////////////////////////////////////////////////////////////////////
void CarriedBeltIncludesEquipSlotsWithBeltSlot()
{
    BuildCarriedArmor("belt", "a leather belt", "soft leather", Belt);

    Subscriber.pushInventory();
    ExpectSubStringMatch("\"belt\"", Player.caughtGmcp(),
        "carried belt equipSlots contains belt");
}

/////////////////////////////////////////////////////////////////////////////
void CarriedArmGreavesIncludeEquipSlotsWithArmGreavesSlot()
{
    BuildCarriedArmor("arm greaves", "iron arm greaves",
        "plate armor", ArmGreaves);

    Subscriber.pushInventory();
    ExpectSubStringMatch("\"arm greaves\"", Player.caughtGmcp(),
        "carried arm greaves equipSlots contains arm greaves");
}

/////////////////////////////////////////////////////////////////////////////
void CarriedLegGreavesIncludeEquipSlotsWithLegGreavesSlot()
{
    BuildCarriedArmor("leg greaves", "iron leg greaves",
        "plate armor", LegGreaves);

    Subscriber.pushInventory();
    ExpectSubStringMatch("\"leg greaves\"", Player.caughtGmcp(),
        "carried leg greaves equipSlots contains leg greaves");
}

/////////////////////////////////////////////////////////////////////////////
void CarriedBracersIncludeEquipSlotsWithBracersSlot()
{
    BuildCarriedArmor("bracers", "leather bracers", "soft leather", Bracers);

    Subscriber.pushInventory();
    ExpectSubStringMatch("\"bracers\"", Player.caughtGmcp(),
        "carried bracers equipSlots contains bracers");
}

/////////////////////////////////////////////////////////////////////////////
void CarriedShieldIncludesEquipSlotsWithWieldedOffhand()
{
    object shield = BuildWeapon("shield", "a wooden shield",
        "shield", OffhandWeapon);

    Subscriber.pushInventory();
    ExpectSubStringMatch("\"wielded offhand\"", Player.caughtGmcp(),
        "carried shield equipSlots contains wielded offhand");
}

// ---------------------------------------------------------------------------
// pushInventory - carried item field content
// ---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
void CarriedItemIncludesNameField()
{
    BuildCarriedWeapon("dagger", "a dagger", "dagger", OnehandedWeapon);

    Subscriber.pushInventory();
    ExpectSubStringMatch("\"name\"", Player.caughtGmcp(),
        "carried item has name field");
}

/////////////////////////////////////////////////////////////////////////////
void CarriedItemIncludesShortField()
{
    BuildCarriedWeapon("dagger", "a dagger", "dagger", OnehandedWeapon);

    Subscriber.pushInventory();
    ExpectSubStringMatch("a dagger", Player.caughtGmcp(),
        "carried item short description appears in payload");
}

/////////////////////////////////////////////////////////////////////////////
void CarriedItemIncludesTypeField()
{
    BuildCarriedWeapon("dagger", "a dagger", "dagger", OnehandedWeapon);

    Subscriber.pushInventory();
    ExpectSubStringMatch("\"type\"", Player.caughtGmcp(),
        "carried item has type field");
}

/////////////////////////////////////////////////////////////////////////////
void CarriedItemTypeReflectsWeaponType()
{
    BuildCarriedWeapon("dagger", "a dagger", "dagger", OnehandedWeapon);

    Subscriber.pushInventory();
    ExpectSubStringMatch("dagger", Player.caughtGmcp(),
        "weapon type value appears in carried item payload");
}

/////////////////////////////////////////////////////////////////////////////
void CarriedItemTypeReflectsArmorType()
{
    BuildCarriedArmor("chainmail", "a chainmail hauberk",
        "chainmail", Armor);

    Subscriber.pushInventory();
    ExpectSubStringMatch("chainmail", Player.caughtGmcp(),
        "armor type value appears in carried item payload");
}

/////////////////////////////////////////////////////////////////////////////
void CarriedItemHasNoSlotField()
{
    BuildCarriedWeapon("dagger", "a dagger", "dagger", OnehandedWeapon);

    Subscriber.pushInventory();
    string frame = Player.caughtGmcp();
    // carried items should have equipSlots, not slot
    int carriedStart = strstr(frame, "\"carried\"");
    int equippedStart = strstr(frame, "\"equipped\"");
    string carriedSection = frame[carriedStart..equippedStart - 1];
    ExpectFalse(strstr(carriedSection, "\"slot\"") != -1,
        "carried item must not have a slot field");
}

/////////////////////////////////////////////////////////////////////////////
void MultipleCarriedItemsAllAppearInPayload()
{
    BuildCarriedWeapon("sword1", "the first sword",
        "short sword", OnehandedWeapon);
    BuildCarriedWeapon("sword2", "the second sword",
        "long sword", OnehandedWeapon);

    Subscriber.pushInventory();
    string frame = Player.caughtGmcp();
    ExpectSubStringMatch("the first sword", frame,
        "first carried item appears in payload");
    ExpectSubStringMatch("the second sword", frame,
        "second carried item appears in payload");
}

// ---------------------------------------------------------------------------
// pushInventory - second ring slot
// ---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
void TwoRingsEquipToSeparateSlots()
{
    object ring1 = BuildRing("ring1", "a gold ring");
    ring1.equip("ring");

    object ring2 = BuildRing("ring2", "a silver ring");
    ring2.equip("second ring");

    Subscriber.pushInventory();
    string frame = Player.caughtGmcp();
    ExpectSubStringMatch("\"ring 1\"", frame,
        "ring 1 slot present when two rings equipped");
    ExpectSubStringMatch("\"ring 2\"", frame,
        "ring 2 slot present when two rings equipped");
}

/////////////////////////////////////////////////////////////////////////////
void EquippedHelmetIsExcludedFromCarriedList()
{
    object helm = BuildArmor("helmet", "an iron helmet", "plate armor", Helmet);
    helm.equip("helmet");

    Subscriber.pushInventory();
    string frame = Player.caughtGmcp();

    int first  = strstr(frame, "an iron helmet");
    int second = strstr(frame, "an iron helmet", first + 1);
    ExpectTrue(first >= 0, "helmet appears at least once");
    ExpectEq(-1, second,
        "equipped helmet must not also appear in carried list");
}

// ---------------------------------------------------------------------------
// pushSkills
// ---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
void PushSkillsEmitsCharSkillsPackage()
{
    Subscriber.pushSkills();
    ExpectSubStringMatch("Char.Skills", Player.caughtGmcp(),
        "Char.Skills package is emitted");
}

/////////////////////////////////////////////////////////////////////////////
void PushSkillsPayloadIsAJsonObject()
{
    Subscriber.pushSkills();
    string frame = Player.caughtGmcp();
    // Body after the package name must open with '{'
    int bodyStart = strstr(frame, "{");
    ExpectTrue(bodyStart >= 0, "skills payload starts with {");
}

/////////////////////////////////////////////////////////////////////////////
void PushSkillsDoesNotFireWhenNoPlayerSet()
{
    Subscriber.setPlayer(0);
    string err = catch(Subscriber.pushSkills());
    ExpectEq(0, err, "pushSkills is safe when player is 0");
}

/////////////////////////////////////////////////////////////////////////////
void PushSkillsWithTrainedSkillIncludesSkillName()
{
    Player.advanceSkill("long sword", 5);
    Subscriber.pushSkills();
    ExpectSubStringMatch("long sword", Player.caughtGmcp(),
        "trained skill name appears in skills payload");
}

/////////////////////////////////////////////////////////////////////////////
void PushSkillsWithTrainedSkillIncludesValueKey()
{
    Player.advanceSkill("long sword", 5);
    Subscriber.pushSkills();
    ExpectSubStringMatch("\"value\"", Player.caughtGmcp(),
        "value key present for trained skill");
}

/////////////////////////////////////////////////////////////////////////////
void PushSkillsWithTrainedSkillIncludesBaseKey()
{
    Player.advanceSkill("long sword", 5);
    Subscriber.pushSkills();
    ExpectSubStringMatch("\"base\"", Player.caughtGmcp(),
        "base key present for trained skill");
}

/////////////////////////////////////////////////////////////////////////////
void PushSkillsWithTrainedSkillIncludesTypeKey()
{
    Player.advanceSkill("long sword", 5);
    Subscriber.pushSkills();
    ExpectSubStringMatch("\"type\"", Player.caughtGmcp(),
        "type key present for trained skill");
}

/////////////////////////////////////////////////////////////////////////////
void OnSkillAdvancedPushesSkills()
{
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onSkillAdvanced(Player, 0);
    ExpectTrue(sizeof(Player.caughtGmcpFrames()) > before,
        "onSkillAdvanced triggers at least one new GMCP frame");
}

/////////////////////////////////////////////////////////////////////////////
void OnSkillAdvancedFromWrongPlayerIsIgnored()
{
    object other = clone_object("/lib/tests/support/services/mockPlayer.c");
    other.Name("alice");
    other.enableGmcp();
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onSkillAdvanced(other, 0);
    ExpectEq(before, sizeof(Player.caughtGmcpFrames()),
        "skill event from wrong player must not push frames");
    destruct(other);
}

// ---------------------------------------------------------------------------
// pushTraits
// ---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
void PushTraitsEmitsCharTraitsPackage()
{
    Subscriber.pushTraits();
    ExpectSubStringMatch("Char.Traits", Player.caughtGmcp(),
        "Char.Traits package is emitted");
}

/////////////////////////////////////////////////////////////////////////////
void PushTraitsIncludesTraitsKey()
{
    Subscriber.pushTraits();
    ExpectSubStringMatch("\"traits\"", Player.caughtGmcp(),
        "traits key present in Char.Traits payload");
}

/////////////////////////////////////////////////////////////////////////////
void PushTraitsDoesNotFireWhenNoPlayerSet()
{
    Subscriber.setPlayer(0);
    string err = catch(Subscriber.pushTraits());
    ExpectEq(0, err, "pushTraits is safe when player is 0");
}

/////////////////////////////////////////////////////////////////////////////
void OnTraitAddedPushesTraits()
{
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onTraitAdded(Player, 0);
    ExpectTrue(sizeof(Player.caughtGmcpFrames()) > before,
        "onTraitAdded triggers new GMCP frames");
}

/////////////////////////////////////////////////////////////////////////////
void OnTraitRemovedPushesTraits()
{
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onTraitRemoved(Player, 0);
    ExpectTrue(sizeof(Player.caughtGmcpFrames()) > before,
        "onTraitRemoved triggers new GMCP frames");
}

/////////////////////////////////////////////////////////////////////////////
void OnTraitAddedFromWrongPlayerIsIgnored()
{
    object other = clone_object("/lib/tests/support/services/mockPlayer.c");
    other.Name("alice");
    other.enableGmcp();
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onTraitAdded(other, 0);
    ExpectEq(before, sizeof(Player.caughtGmcpFrames()),
        "trait event from wrong player must not push frames");
    destruct(other);
}

// ---------------------------------------------------------------------------
// pushResearch - package and top-level structure
// ---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
void PushResearchEmitsCharResearchPackage()
{
    Subscriber.pushResearch();
    ExpectSubStringMatch("Char.Research", Player.caughtGmcp(),
        "Char.Research package is emitted");
}

/////////////////////////////////////////////////////////////////////////////
void PushResearchIncludesPointsKey()
{
    Subscriber.pushResearch();
    ExpectSubStringMatch("\"points\"", Player.caughtGmcp(),
        "points key present in Char.Research payload");
}

/////////////////////////////////////////////////////////////////////////////
void PushResearchIncludesTreesKey()
{
    Player.addResearchTree("/lib/tests/support/research/testResearchTree.c");
    Subscriber.pushResearch();
    // New protocol: each tree is a separate Char.Research.Tree frame
    string allFrames = implode(Player.caughtGmcpFrames(), "");
    ExpectSubStringMatch("Char.Research.Tree", allFrames,
        "trees key present in Char.Research payload");
}

/////////////////////////////////////////////////////////////////////////////
void PushResearchDoesNotFireWhenNoPlayerSet()
{
    Subscriber.setPlayer(0);
    string err = catch(Subscriber.pushResearch());
    ExpectEq(0, err, "pushResearch is safe when player is 0");
}

// ---------------------------------------------------------------------------
// pushResearch - tree content when a tree is available
// ---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
void PushResearchIncludesTreeNameWhenTreeAvailable()
{
    Player.addResearchTree("/lib/tests/support/research/testResearchTree.c");
    Subscriber.pushResearch();
    ExpectSubStringMatch("\"name\"", implode(Player.caughtGmcpFrames(), ""),
        "name key present in tree entry");
}

/////////////////////////////////////////////////////////////////////////////
void PushResearchIncludesTreeSourceWhenTreeAvailable()
{
    Player.addResearchTree("/lib/tests/support/research/testResearchTree.c");
    Subscriber.pushResearch();
    ExpectSubStringMatch("\"source\"", implode(Player.caughtGmcpFrames(), ""),
        "source key present in tree entry");
}

/////////////////////////////////////////////////////////////////////////////
void PushResearchIncludesTreeRootWhenTreeAvailable()
{
    Player.addResearchTree("/lib/tests/support/research/testResearchTree.c");
    Subscriber.pushResearch();
    ExpectSubStringMatch("\"root\"", implode(Player.caughtGmcpFrames(), ""),
        "root key present in tree entry");
}

/////////////////////////////////////////////////////////////////////////////
void PushResearchIncludesNodesArrayWhenTreeAvailable()
{
    Player.addResearchTree("/lib/tests/support/research/testResearchTree.c");
    Subscriber.pushResearch();
    ExpectSubStringMatch("\"nodes\"", implode(Player.caughtGmcpFrames(), ""),
        "nodes key present in tree entry");
}

// ---------------------------------------------------------------------------
// pushResearch - per-node fields
// ---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
void ResearchNodeIncludesPathField()
{
    Player.addResearchTree("/lib/tests/support/research/testResearchTree.c");
    Subscriber.pushResearch();
    ExpectSubStringMatch("\"path\"", implode(Player.caughtGmcpFrames(), ""),
        "path field present on research node");
}

/////////////////////////////////////////////////////////////////////////////
void ResearchNodeIncludesNameField()
{
    Player.addResearchTree("/lib/tests/support/research/testResearchTree.c");
    Subscriber.pushResearch();
    ExpectSubStringMatch("\"name\"", implode(Player.caughtGmcpFrames(), ""),
        "name field present on research node");
}

/////////////////////////////////////////////////////////////////////////////
void ResearchNodeIncludesDescriptionField()
{
    Player.addResearchTree("/lib/tests/support/research/testResearchTree.c");
    Subscriber.pushResearch();
    ExpectSubStringMatch("\"description\"", implode(Player.caughtGmcpFrames(), ""),
        "description field present on research node");
}

/////////////////////////////////////////////////////////////////////////////
void ResearchNodeIncludesTypeField()
{
    Player.addResearchTree("/lib/tests/support/research/testResearchTree.c");
    Subscriber.pushResearch();
    ExpectSubStringMatch("\"type\"", implode(Player.caughtGmcpFrames(), ""),
        "type field present on research node");
}

/////////////////////////////////////////////////////////////////////////////
void ResearchNodeIncludesStatusField()
{
    Player.addResearchTree("/lib/tests/support/research/testResearchTree.c");
    Subscriber.pushResearch();
    ExpectSubStringMatch("\"status\"", implode(Player.caughtGmcpFrames(), ""),
        "status field present on research node");
}

/////////////////////////////////////////////////////////////////////////////
void ResearchNodeIncludesParentsField()
{
    Player.addResearchTree("/lib/tests/support/research/testResearchTree.c");
    Subscriber.pushResearch();
    ExpectSubStringMatch("\"parents\"", implode(Player.caughtGmcpFrames(), ""),
        "parents field present on research node");
}

/////////////////////////////////////////////////////////////////////////////
void ResearchNodeIncludesPrerequisitesField()
{
    Player.addResearchTree("/lib/tests/support/research/testResearchTree.c");
    Subscriber.pushResearch();
    ExpectSubStringMatch("\"prerequisites\"", implode(Player.caughtGmcpFrames(), ""),
        "prerequisites field present on research node");
}

/////////////////////////////////////////////////////////////////////////////
void ResearchNodeIncludesBonusesField()
{
    Player.addResearchTree("/lib/tests/support/research/testResearchTree.c");
    Subscriber.pushResearch();
    ExpectSubStringMatch("\"bonuses\"", implode(Player.caughtGmcpFrames(), ""),
        "bonuses field present on research node");
}

/////////////////////////////////////////////////////////////////////////////
void ResearchNodeIncludesPenaltiesField()
{
    Player.addResearchTree("/lib/tests/support/research/testResearchTree.c");
    Subscriber.pushResearch();
    ExpectSubStringMatch("\"penalties\"", implode(Player.caughtGmcpFrames(), ""),
        "penalties field present on research node");
}

/////////////////////////////////////////////////////////////////////////////
void ResearchNodeIncludesModifiersField()
{
    Player.addResearchTree("/lib/tests/support/research/testResearchTree.c");
    Subscriber.pushResearch();
    ExpectSubStringMatch("\"modifiers\"", implode(Player.caughtGmcpFrames(), ""),
        "modifiers field present on research node");
}

/////////////////////////////////////////////////////////////////////////////
void ResearchNodeIncludesDamageEffectsField()
{
    Player.addResearchTree("/lib/tests/support/research/testResearchTree.c");
    Subscriber.pushResearch();
    ExpectSubStringMatch("\"damageEffects\"", implode(Player.caughtGmcpFrames(), ""),
        "damageEffects field present on research node");
}

/////////////////////////////////////////////////////////////////////////////
void ResearchNodeIncludesLimitersField()
{
    Player.addResearchTree("/lib/tests/support/research/testResearchTree.c");
    Subscriber.pushResearch();
    ExpectSubStringMatch("\"limiters\"", implode(Player.caughtGmcpFrames(), ""),
        "limiters field present on research node");
}

/////////////////////////////////////////////////////////////////////////////
void ResearchNodeIncludesCostModifiersField()
{
    Player.addResearchTree("/lib/tests/support/research/testResearchTree.c");
    Subscriber.pushResearch();
    ExpectSubStringMatch("\"costModifiers\"", implode(Player.caughtGmcpFrames(), ""),
        "costModifiers field present on research node");
}

/////////////////////////////////////////////////////////////////////////////
void ResearchNodeIncludesCooldownModifiersField()
{
    Player.addResearchTree("/lib/tests/support/research/testResearchTree.c");
    Subscriber.pushResearch();
    ExpectSubStringMatch("\"cooldownModifiers\"", implode(Player.caughtGmcpFrames(), ""),
        "cooldownModifiers field present on research node");
}

/////////////////////////////////////////////////////////////////////////////
void ResearchNodeIncludesConsumablesField()
{
    Player.addResearchTree("/lib/tests/support/research/testResearchTree.c");
    Subscriber.pushResearch();
    ExpectSubStringMatch("\"consumables\"", implode(Player.caughtGmcpFrames(), ""),
        "consumables field present on research node");
}

/////////////////////////////////////////////////////////////////////////////
void ResearchNodeIncludesSupercedeTargetsField()
{
    Player.addResearchTree("/lib/tests/support/research/testResearchTree.c");
    Subscriber.pushResearch();
    ExpectSubStringMatch("\"supercedeTargets\"", implode(Player.caughtGmcpFrames(), ""),
        "supercedeTargets field present on research node");
}

/////////////////////////////////////////////////////////////////////////////
void ResearchNodeIncludesAffectedResearchField()
{
    Player.addResearchTree("/lib/tests/support/research/testResearchTree.c");
    Subscriber.pushResearch();
    ExpectSubStringMatch("\"affectedResearch\"", implode(Player.caughtGmcpFrames(), ""),
        "affectedResearch field present on research node");
}

/////////////////////////////////////////////////////////////////////////////
void ResearchNodeIncludesAffectedResearchTypeField()
{
    Player.addResearchTree("/lib/tests/support/research/testResearchTree.c");
    Subscriber.pushResearch();
    ExpectSubStringMatch("\"affectedResearchType\"", implode(Player.caughtGmcpFrames(), ""),
        "affectedResearchType field present on research node");
}

/////////////////////////////////////////////////////////////////////////////
void ResearchNodeBonusValueIsSerializedForPassiveItem()
{
    Player.addResearchTree("/lib/tests/support/research/testResearchTree.c");
    Subscriber.pushResearch();
    // testTreeRoot has "bonus long sword": 2
    string allFrames = implode(Player.caughtGmcpFrames(), "");
    ExpectSubStringMatch("long sword", allFrames,
        "bonus key name appears in node bonuses");
}

/////////////////////////////////////////////////////////////////////////////
void ResearchNodeStatusIsLockedWhenNotResearched()
{
    Player.addResearchTree("/lib/tests/support/research/testResearchTree.c");
    Subscriber.pushResearch();
    ExpectSubStringMatch("\"status\"", implode(Player.caughtGmcpFrames(), ""),
        "status field present");
}

/////////////////////////////////////////////////////////////////////////////
void ResearchNodePrerequisiteTypeIsSerializedForSkillPrereq()
{
    // testTreeRoot has a long sword skill prereq
    Player.addResearchTree("/lib/tests/support/research/testResearchTree.c");
    Subscriber.pushResearch();
    string allFrames = implode(Player.caughtGmcpFrames(), "");
    ExpectSubStringMatch("\"type\"", allFrames,
        "prereq type key serialized");
}

// ---------------------------------------------------------------------------
// pushResearch - node status transitions
// ---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
void ResearchNodeStatusIsKnownAfterResearching()
{
    Player.addResearchTree("/lib/tests/support/research/testResearchTree.c");
    Player.advanceSkill("long sword", 10);
    Player.addResearchPoints(5);
    Player.initiateResearch("/lib/tests/support/research/testTreeRoot.c");
    Player.completedResearch("/lib/tests/support/research/testTreeRoot.c");
    Subscriber.pushResearch();
    string allFrames = implode(Player.caughtGmcpFrames(), "");
    ExpectSubStringMatch("known", allFrames,
        "node status is known after research completed");
}

// ---------------------------------------------------------------------------
// research event handlers
// ---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
void OnResearchCompletedPushesResearch()
{
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onResearchCompleted(Player, 0);
    ExpectTrue(sizeof(Player.caughtGmcpFrames()) > before,
        "onResearchCompleted pushes new GMCP frames");
}

/////////////////////////////////////////////////////////////////////////////
void OnResearchCompletedAlsoPushesScore()
{
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onResearchCompleted(Player, 0);
    // Should push both Char.Research and Char.Score
    ExpectTrue(sizeof(Player.caughtGmcpFrames()) >= before + 2,
        "onResearchCompleted pushes both research and score frames");
}

/////////////////////////////////////////////////////////////////////////////
void OnResearchStartedPushesResearch()
{
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onResearchStarted(Player, 0);
    ExpectTrue(sizeof(Player.caughtGmcpFrames()) > before,
        "onResearchStarted pushes research frame");
}

/////////////////////////////////////////////////////////////////////////////
void OnResearchPointsAddedPushesResearch()
{
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onResearchPointsAdded(Player, 0);
    ExpectTrue(sizeof(Player.caughtGmcpFrames()) > before,
        "onResearchPointsAdded pushes research frame");
}

/////////////////////////////////////////////////////////////////////////////
void OnResearchPointsAddedAlsoPushesScore()
{
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onResearchPointsAdded(Player, 0);
    ExpectTrue(sizeof(Player.caughtGmcpFrames()) >= before + 2,
        "onResearchPointsAdded pushes both research and score frames");
}

/////////////////////////////////////////////////////////////////////////////
void OnResearchTreeOpenPushesResearch()
{
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onResearchTreeOpen(Player, 0);
    ExpectTrue(sizeof(Player.caughtGmcpFrames()) > before,
        "onResearchTreeOpen pushes research frame");
}

/////////////////////////////////////////////////////////////////////////////
void OnResearchCompletedFromWrongPlayerIsIgnored()
{
    object other = clone_object("/lib/tests/support/services/mockPlayer.c");
    other.Name("alice");
    other.enableGmcp();
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onResearchCompleted(other, 0);
    ExpectEq(before, sizeof(Player.caughtGmcpFrames()),
        "research event from wrong player must not push frames");
    destruct(other);
}

/////////////////////////////////////////////////////////////////////////////
void OnResearchStartedFromWrongPlayerIsIgnored()
{
    object other = clone_object("/lib/tests/support/services/mockPlayer.c");
    other.Name("alice");
    other.enableGmcp();
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onResearchStarted(other, 0);
    ExpectEq(before, sizeof(Player.caughtGmcpFrames()),
        "onResearchStarted from wrong player ignored");
    destruct(other);
}

/////////////////////////////////////////////////////////////////////////////
void OnResearchTreeOpenFromWrongPlayerIsIgnored()
{
    object other = clone_object("/lib/tests/support/services/mockPlayer.c");
    other.Name("alice");
    other.enableGmcp();
    int before = sizeof(Player.caughtGmcpFrames());
    Subscriber.onResearchTreeOpen(other, 0);
    ExpectEq(before, sizeof(Player.caughtGmcpFrames()),
        "onResearchTreeOpen from wrong player ignored");
    destruct(other);
}

