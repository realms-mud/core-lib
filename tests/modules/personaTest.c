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

    Persona->SetUpPersonaOfLevel("swordsman", 10);
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