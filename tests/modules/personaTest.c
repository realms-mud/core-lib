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
    ExpectEq(1060, Persona->maxHitPoints());
    ExpectEq(160, Persona->maxSpellPoints());
    ExpectEq(560, Persona->staminaPoints());
    ExpectEq(10, Persona->effectiveLevel());
    ExpectEq(10, Persona->Str());
    ExpectEq(10, Persona->Int());
    ExpectEq(10, Persona->Dex());
    ExpectEq(10, Persona->Wis());
    ExpectEq(10, Persona->Con());
    ExpectEq(10, Persona->Chr());
    ExpectEq(10, Persona->getSkill("parry"));
    ExpectEq(10, Persona->getSkill("dodge"));
    ExpectEq(10, Persona->getSkill("shield"));
    ExpectEq(10, Persona->getSkill("long sword"));
    ExpectEq(10, Persona->getSkill("hand and a half sword"));
    ExpectEq(10, Persona->getSkill("short sword"));
    ExpectEq(10, Persona->getSkill("dagger"));
    ExpectEq(10, Persona->getSkill("two-handed sword"));
    ExpectEq(10, Persona->getSkill("plate armor"));
    ExpectEq(10, Persona->getSkill("splint armor"));
    ExpectEq(10, Persona->getSkill("chainmail"));
    ExpectEq(10, Persona->getSkill("scalemail"));
    ExpectEq(10, Persona->getSkill("hard leather"));
    ExpectEq(10, Persona->getSkill("soft leather"));
    ExpectEq(10, Persona->getSkill("no armor"));
    ExpectEq(5, Persona->getSkill("anatomy and physiology"));
    ExpectEq(5, Persona->getSkill("perception"));
    ExpectEq(5, Persona->getSkill("listen"));
    ExpectEq(5, Persona->getSkill("spot"));
    ExpectEq(5, Persona->getSkill("common"));
    ExpectEq(5, Persona->getSkill("dual wield"));
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
    ExpectEq(106, Persona->maxHitPoints());
    ExpectEq(16, Persona->maxSpellPoints());
    ExpectEq(56, Persona->staminaPoints());
    ExpectEq(1, Persona->effectiveLevel());
}

/////////////////////////////////////////////////////////////////////////////
void SetUpPersonaOfLevelWorksForNPC()
{
    destruct(Persona);
    Persona = clone_object("/lib/realizations/npc.c");

    Persona->SetUpPersonaOfLevel("swordsman", 1);
    ExpectEq(106, Persona->maxHitPoints());
    ExpectEq(16, Persona->maxSpellPoints());
    ExpectEq(56, Persona->staminaPoints());
    ExpectEq(1, Persona->effectiveLevel());
}

/////////////////////////////////////////////////////////////////////////////
void SetUpPersonaOfLevelWorksForCompanion()
{
    destruct(Persona);
    Persona = clone_object("/lib/realizations/companion.c");

    Persona->SetUpPersonaOfLevel("swordsman", 1);
    ExpectEq(106, Persona->maxHitPoints());
    ExpectEq(16, Persona->maxSpellPoints());
    ExpectEq(56, Persona->staminaPoints());
    ExpectEq(1, Persona->effectiveLevel());
}

/////////////////////////////////////////////////////////////////////////////
void SetUpPersonaOfLevelWorksForAI()
{
    destruct(Persona);
    Persona = clone_object("/lib/realizations/monsterWithAI.c");

    Persona->SetUpPersonaOfLevel("swordsman", 1);
    ExpectEq(106, Persona->maxHitPoints());
    ExpectEq(16, Persona->maxSpellPoints());
    ExpectEq(56, Persona->staminaPoints());
    ExpectEq(1, Persona->effectiveLevel());
}

/////////////////////////////////////////////////////////////////////////////
void SetUpPersonaOfLevelWorksForSeneschal()
{
    destruct(Persona);
    Persona = clone_object("/lib/realizations/seneschal.c");

    Persona->SetUpPersonaOfLevel("swordsman", 1);
    ExpectEq(106, Persona->maxHitPoints());
    ExpectEq(16, Persona->maxSpellPoints());
    ExpectEq(56, Persona->staminaPoints());
    ExpectEq(1, Persona->effectiveLevel());
}

/////////////////////////////////////////////////////////////////////////////
void SetUpPersonaOfLevelWorksForWanderer()
{
    destruct(Persona);
    Persona = clone_object("/lib/realizations/wanderingMonster.c");

    Persona->SetUpPersonaOfLevel("swordsman", 1);
    ExpectEq(106, Persona->maxHitPoints());
    ExpectEq(16, Persona->maxSpellPoints());
    ExpectEq(56, Persona->staminaPoints());
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
        ([ "attack type": "claw", "damage": 25, "to hit": 80 ]), 
        ([ "attack type": "fangs", "damage": 30, "to hit": 80 ]), 
        ([ "attack type": "fire", "damage": 35, "to hit": 80 ]), 
        }), Persona->getAttacks());
}

/////////////////////////////////////////////////////////////////////////////
void CreaturesWithWeaponsGetAllAttacksSet()
{
    Persona->SetUpPersonaOfLevel("skeleton", 10);
    Persona->setUpRandomEquipment();

    ExpectEq(3, sizeof(all_inventory(Persona)));
    ExpectEq(({
        (["attack type":"undead", "damage" : 10, "to hit" : 40]),
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
        (["attack type":"electricity", "damage" : 15, "to hit" : 35]),
        (["attack type":"wielded primary"]),
        }), Persona->getAttacks());
}

/////////////////////////////////////////////////////////////////////////////
void PersonaRaceModifiesStatistics()
{
    Persona->Race("troll");
    Persona->SetUpPersonaOfLevel("swordsman", 10);

    ExpectEq(1184, Persona->maxHitPoints());
    ExpectEq(1184, Persona->hitPoints());
    ExpectEq(0, Persona->maxSpellPoints());
    ExpectEq(621, Persona->maxStaminaPoints());
    ExpectEq(10, Persona->effectiveLevel());
    ExpectEq(18, Persona->Str());
    ExpectEq(6, Persona->Int());
    ExpectEq(6, Persona->Dex());
    ExpectEq(6, Persona->Wis());
    ExpectEq(14, Persona->Con());
    ExpectEq(6, Persona->Chr());
    ExpectEq(4, Persona->racesBonusTo("BonusHealHitPoints"));
    ExpectEq(8, Persona->racesBonusTo("BonusHealHitPointsRate"));
    ExpectEq(-8, Persona->racesBonusTo("BonusHealSpellPointsRate"));
    ExpectEq(4, Persona->racesBonusTo("DefenseBonus"));
    ExpectEq(-50, Persona->racesBonusTo("resist fire"));
}
