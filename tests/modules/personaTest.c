//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Persona;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Persona = clone_object("/lib/realizations/monster");
    Persona->Name("Bob");
    Persona->Gender(1);
    move_object(Persona, this_object());
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Persona);
}

/////////////////////////////////////////////////////////////////////////////
void SetUpPersonaOfLevelWorksForMonsters()
{
    ExpectEq(0, Persona->effectiveLevel());
    ExpectEq(0, Persona->Str());
    ExpectEq(0, Persona->getSkill("long sword"));
    ExpectFalse(Persona->isTraitOf("lib/modules/traits/personas/fighters/swordsman.c"));
    Persona->SetUpPersonaOfLevel("swordsman", 10);
    ExpectTrue(Persona->isTraitOf("lib/modules/traits/personas/fighters/swordsman.c"));
    ExpectEq(1120, Persona->maxHitPoints());
    ExpectEq(220, Persona->maxSpellPoints());
    ExpectEq(620, Persona->staminaPoints());
    ExpectEq(10, Persona->effectiveLevel());
    ExpectEq(20, Persona->Str());
    ExpectEq(20, Persona->Int());
    ExpectEq(20, Persona->Dex());
    ExpectEq(20, Persona->Wis());
    ExpectEq(20, Persona->Con());
    ExpectEq(20, Persona->Chr());
    ExpectEq(20, Persona->getSkill("parry"));
    ExpectEq(20, Persona->getSkill("dodge"));
    ExpectEq(20, Persona->getSkill("shield"));
    ExpectEq(20, Persona->getSkill("long sword"));
    ExpectEq(20, Persona->getSkill("hand and a half sword"));
    ExpectEq(20, Persona->getSkill("short sword"));
    ExpectEq(20, Persona->getSkill("dagger"));
    ExpectEq(20, Persona->getSkill("two-handed sword"));
    ExpectEq(20, Persona->getSkill("plate armor"));
    ExpectEq(20, Persona->getSkill("splint armor"));
    ExpectEq(20, Persona->getSkill("chainmail"));
    ExpectEq(20, Persona->getSkill("scalemail"));
    ExpectEq(20, Persona->getSkill("hard leather"));
    ExpectEq(20, Persona->getSkill("soft leather"));
    ExpectEq(20, Persona->getSkill("no armor"));
    ExpectEq(10, Persona->getSkill("anatomy and physiology"));
    ExpectEq(10, Persona->getSkill("perception"));
    ExpectEq(10, Persona->getSkill("listen"));
    ExpectEq(10, Persona->getSkill("spot"));
    ExpectEq(10, Persona->getSkill("common"));
    ExpectEq(10, Persona->getSkill("dual wield"));
}

/////////////////////////////////////////////////////////////////////////////
void SetUpPersonaOfLevelCanOnlyBeCalledOnce()
{
    Persona->SetUpPersonaOfLevel("swordsman", 1);
    string error = catch (load_object("/lib/dictionaries/personaDictionary.c")->setupPersona("axeman", Persona));
    ExpectSubStringMatch("personaDictionary: A character may only have one persona", error);
}

/////////////////////////////////////////////////////////////////////////////
void CannotSetInvalidPersona()
{
    string error = catch (Persona->SetUpPersonaOfLevel("blargman", 10));
    ExpectSubStringMatch("personaDictionary: An invalid persona was selected", error);
}

/////////////////////////////////////////////////////////////////////////////
void SetUpPersonaOfLevelWorksForHenchmen()
{
    destruct(Persona);
    Persona = clone_object("/lib/realizations/henchman.c");

    Persona->SetUpPersonaOfLevel("swordsman", 1);
    ExpectEq(112, Persona->maxHitPoints());
    ExpectEq(22, Persona->maxSpellPoints());
    ExpectEq(62, Persona->staminaPoints());
    ExpectEq(1, Persona->effectiveLevel());
}

/////////////////////////////////////////////////////////////////////////////
void SetUpPersonaOfLevelWorksForNPC()
{
    destruct(Persona);
    Persona = clone_object("/lib/realizations/npc.c");

    Persona->SetUpPersonaOfLevel("swordsman", 1);
    ExpectEq(112, Persona->maxHitPoints());
    ExpectEq(22, Persona->maxSpellPoints());
    ExpectEq(62, Persona->staminaPoints());
    ExpectEq(1, Persona->effectiveLevel());
}

/////////////////////////////////////////////////////////////////////////////
void SetUpPersonaOfLevelWorksForCompanion()
{
    destruct(Persona);
    Persona = clone_object("/lib/realizations/companion.c");

    Persona->SetUpPersonaOfLevel("swordsman", 1);
    ExpectEq(112, Persona->maxHitPoints());
    ExpectEq(22, Persona->maxSpellPoints());
    ExpectEq(62, Persona->staminaPoints());
    ExpectEq(1, Persona->effectiveLevel());
}

/////////////////////////////////////////////////////////////////////////////
void SetUpPersonaOfLevelWorksForAI()
{
    destruct(Persona);
    Persona = clone_object("/lib/realizations/monsterWithAI.c");

    Persona->SetUpPersonaOfLevel("swordsman", 1);
    ExpectEq(112, Persona->maxHitPoints());
    ExpectEq(22, Persona->maxSpellPoints());
    ExpectEq(62, Persona->staminaPoints());
    ExpectEq(1, Persona->effectiveLevel());
}

/////////////////////////////////////////////////////////////////////////////
void SetUpPersonaOfLevelWorksForSeneschal()
{
    destruct(Persona);
    Persona = clone_object("/lib/realizations/seneschal.c");

    Persona->SetUpPersonaOfLevel("swordsman", 1);
    ExpectEq(112, Persona->maxHitPoints());
    ExpectEq(22, Persona->maxSpellPoints());
    ExpectEq(62, Persona->staminaPoints());
    ExpectEq(1, Persona->effectiveLevel());
}

/////////////////////////////////////////////////////////////////////////////
void SetUpPersonaOfLevelWorksForWanderer()
{
    destruct(Persona);
    Persona = clone_object("/lib/realizations/wanderingMonster.c");

    Persona->SetUpPersonaOfLevel("swordsman", 1);
    ExpectEq(112, Persona->maxHitPoints());
    ExpectEq(22, Persona->maxSpellPoints());
    ExpectEq(62, Persona->staminaPoints());
    ExpectEq(1, Persona->effectiveLevel());
}

/////////////////////////////////////////////////////////////////////////////
void SetUpPersonaOfLevelFailsOnNonMonsterOrHenchman()
{
    destruct(Persona);
    Persona = clone_object("/lib/realizations/player.c");

    string error = catch(load_object("/lib/dictionaries/personaDictionary.c")->setupPersona("swordsman", Persona));
    ExpectSubStringMatch("personaDictionary: Personas can only be set for NPCs", error);
}

/////////////////////////////////////////////////////////////////////////////
void SetUpRandomEquipmentFailsWhenPersonaNotSet()
{
    string error = catch (Persona->setUpRandomEquipment());
    ExpectSubStringMatch("personaDictionary: A character must have a persona before creating equipment.", error);
}

/////////////////////////////////////////////////////////////////////////////
void SetUpRandomEquipmentSetsUpEquipmentForPersona()
{
    Persona->SetUpPersonaOfLevel("swordsman", 10);
    Persona->setUpRandomEquipment();

    object *equipment = all_inventory(Persona);
    ExpectEq(3, sizeof(equipment));
    ExpectTrue(Persona->isEquipped(equipment[0]));
    ExpectTrue(Persona->isEquipped(equipment[1]));
    ExpectTrue(Persona->isEquipped(equipment[2]));
    ExpectFalse(equipment[0]->query("enchanted"));
    ExpectFalse(equipment[1]->query("enchanted"));
    ExpectFalse(equipment[2]->query("enchanted"));
}

/////////////////////////////////////////////////////////////////////////////
void SetUpRandomEquipmentWithEnchantmentSetsUpEquipmentForPersona()
{
    Persona->SetUpPersonaOfLevel("swordsman", 10);
    Persona->setUpRandomEquipment(100);

    object *equipment = all_inventory(Persona);
    ExpectEq(3, sizeof(equipment));
    ExpectTrue(Persona->isEquipped(equipment[0]));
    ExpectTrue(Persona->isEquipped(equipment[1]));
    ExpectTrue(Persona->isEquipped(equipment[2]));
    ExpectTrue(equipment[0]->query("enchanted"));
    ExpectTrue(equipment[1]->query("enchanted"));
    ExpectTrue(equipment[2]->query("enchanted"));
}

/////////////////////////////////////////////////////////////////////////////
void MinimumLevelNotMetReturnsError()
{
    string error = catch (Persona->SetUpPersonaOfLevel("chimera", 10));
    ExpectSubStringMatch("personaDictionary: The character's level is lower than that required for this persona", error);
}

/////////////////////////////////////////////////////////////////////////////
void CreaturesGetAllAttacksSet()
{
    Persona->SetUpPersonaOfLevel("gorgon", 30);

    ExpectEq(({ 
        ([ "attack type": "claw", "damage": 40, "to hit": 120 ]), 
        ([ "attack type": "fangs", "damage": 45, "to hit": 120 ]), 
        ([ "attack type": "fire", "damage": 50, "to hit": 120 ]), 
        }), Persona->getAttacks());
}

/////////////////////////////////////////////////////////////////////////////
void CreaturesWithWeaponsGetAllAttacksSet()
{
    Persona->SetUpPersonaOfLevel("skeleton", 10);
    Persona->setUpRandomEquipment();

    ExpectEq(3, sizeof(all_inventory(Persona)));
    ExpectEq(({
        (["attack type":"undead", "damage" : 15, "to hit" : 90]),
        (["attack type":"wielded primary"]),
        }), Persona->getAttacks());
}

/////////////////////////////////////////////////////////////////////////////
void PersonaRaceWithSpecialAttackHasAttackApplied()
{
    Persona->Race("fuin-nedesar");
    Persona->SetUpPersonaOfLevel("swordsman", 10);
    Persona->setUpRandomEquipment();

    ExpectEq(3, sizeof(all_inventory(Persona)));
    ExpectEq(({
        (["attack type":"electricity", "damage" : 15, "to hit" : 75]),
        (["attack type":"wielded primary"]),
        }), Persona->getAttacks());
}

/////////////////////////////////////////////////////////////////////////////
void PersonaRaceModifiesStatistics()
{
    Persona->Race("troll");
    Persona->SetUpPersonaOfLevel("swordsman", 10);

    ExpectEq(1244, Persona->maxHitPoints());
    ExpectEq(1244, Persona->hitPoints());
    ExpectEq(0, Persona->maxSpellPoints());
    ExpectEq(681, Persona->maxStaminaPoints());
    ExpectEq(10, Persona->effectiveLevel());
    ExpectEq(28, Persona->Str());
    ExpectEq(16, Persona->Int());
    ExpectEq(16, Persona->Dex());
    ExpectEq(16, Persona->Wis());
    ExpectEq(24, Persona->Con());
    ExpectEq(16, Persona->Chr());
    ExpectEq(4, Persona->racesBonusTo("BonusHealHitPoints"));
    ExpectEq(8, Persona->racesBonusTo("BonusHealHitPointsRate"));
    ExpectEq(-8, Persona->racesBonusTo("BonusHealSpellPointsRate"));
    ExpectEq(4, Persona->racesBonusTo("DefenseBonus"));
    ExpectEq(-50, Persona->racesBonusTo("resist fire"));
}

/////////////////////////////////////////////////////////////////////////////
void MagicUsersGetResearchAdded()
{
    Persona->SetUpPersonaOfLevel("aeromancer", 30);

    ExpectEq(({ "lib/instances/research/personas/aeromancer/lightning.c", 
        "lib/instances/research/personas/aeromancer/maelstrom.c", 
        "lib/instances/research/personas/aeromancer/tempest.c" }), 
        Persona->completedResearch());
}

/////////////////////////////////////////////////////////////////////////////
void WillNotAddResearchIfNotHighEnoughLevel()
{
    Persona->SetUpPersonaOfLevel("aeromancer", 10);

    ExpectEq(({ "lib/instances/research/personas/aeromancer/lightning.c",
        "lib/instances/research/personas/aeromancer/tempest.c" }),
        Persona->completedResearch());
}

/////////////////////////////////////////////////////////////////////////////
void CanExecuteAddedResearch()
{
    Persona->SetUpPersonaOfLevel("aeromancer", 20);

    object target = clone_object("/lib/realizations/monster");
    target->Name("Frank");
    target->SetUpPersonaOfLevel("skeleton", 50);
    target->Gender(1);
    move_object(target, this_object());
    object shadow = clone_object("/lib/tests/support/services/catchShadow.c");
    shadow->beginShadow(target);

    Persona->attack(target);
    ExpectSubStringMatch("Bob (screams words of power. Wind and lightning batters "
        "everyone in the area|raises his arms and tendrils of lightning descend upon you|"
        "raises his hand and a stream of lightning slams into you)", 
        target->caughtMessages());
}

/////////////////////////////////////////////////////////////////////////////
void CreaturesCanExecuteBreathWeapons()
{
    Persona->SetUpPersonaOfLevel("chimera", 25);

    object target = clone_object("/lib/realizations/monster");
    target->Name("Frank");
    target->SetUpPersonaOfLevel("skeleton", 50);
    target->Gender(1);
    move_object(target, this_object());
    object shadow = clone_object("/lib/tests/support/services/catchShadow.c");
    shadow->beginShadow(target);

    Persona->attack(target);
    ExpectSubStringMatch("Bob opens his maw and breathes (caustic acid|"
        "a ball of electrical plasma|fiery death|icy death) (on|at) you",
        target->caughtMessages());
}

/////////////////////////////////////////////////////////////////////////////
void PersonasWithSpacesInNamesAndResearchCanExecuteResearch()
{
    Persona->SetUpPersonaOfLevel("keeper of the night", 20);

    object target = clone_object("/lib/realizations/monster");
    target->Name("Frank");
    target->SetUpPersonaOfLevel("skeleton", 50);
    target->Gender(1);
    move_object(target, this_object());
    object shadow = clone_object("/lib/tests/support/services/catchShadow.c");
    shadow->beginShadow(target);

    Persona->attack(target);
    ExpectSubStringMatch("Bob (raises his arms and tendrils of dark red "
        "lightning descend upon you|raises his hand and a dark purple "
        "bolt imbeds itself in you|screams words of power at you, "
        "enveloping you in a ball of dark purple)",
        target->caughtMessages());
}

/////////////////////////////////////////////////////////////////////////////
void AreaEffectSpellsHitAllTargetsInArea()
{
    Persona->SetUpPersonaOfLevel("aeromancer", 20);

    object target = clone_object("/lib/realizations/monster");
    target->Name("Frank");
    target->SetUpPersonaOfLevel("skeleton", 50);
    target->Gender(1);
    move_object(target, this_object());

    object target2 = clone_object("/lib/realizations/monster");
    target2->Name("Jim");
    target2->SetUpPersonaOfLevel("skeleton", 50);
    target2->Gender(2);
    move_object(target2, this_object());

    int initialTargetOneHP = target->hitPoints();
    int initialTargetTwoHP = target2->hitPoints();

    Persona->executePersonaResearch(target->RealName(),
        "lib/instances/research/personas/aeromancer/maelstrom.c");

    ExpectNotEq(initialTargetOneHP, target->hitPoints());
    ExpectNotEq(initialTargetTwoHP, target2->hitPoints());
}
