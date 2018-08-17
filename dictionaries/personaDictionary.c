//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "personas/fighters.h"

/////////////////////////////////////////////////////////////////////////////
private nomask mapping personaBlueprints()
{
    return fighterBlueprints + ([]);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void SetStats(object character)
{
    int level = character->effectiveLevel();
    character->Str(level);
    character->Int(level);
    character->Dex(level);
    character->Wis(level);
    character->Con(level);
    character->Chr(level);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void SetPrimarySkills(object character, string persona)
{
    string *primarySkills = personaBlueprints()[persona]["primary skills"];
    int level = character->effectiveLevel();

    foreach(string skill in primarySkills)
    {
        int neededSkillPoints = character->advanceSkillCost(skill, level);
        character->addSkillPoints(neededSkillPoints);
        character->advanceSkill(skill, level);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void SetSecondarySkills(object character, string persona)
{
    string *secondarySkills = personaBlueprints()[persona]["secondary skills"];
    int skillLevel = character->effectiveLevel() / 2;

    if (skillLevel)
    {
        foreach(string skill in secondarySkills)
        {
            int neededSkillPoints = character->advanceSkillCost(skill, skillLevel);
            character->addSkillPoints(neededSkillPoints);
            character->advanceSkill(skill, skillLevel);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void SetTraits(object character, string persona)
{
    string *traits = personaBlueprints()[persona]["traits"];
    if (sizeof(traits))
    {
        object traitsDictionary = load_object("/lib/dictionaries/traitsDictionary.c");

        foreach(string trait in traits)
        {
            object traitObject = traitsDictionary->traitObject(trait);
            if (traitObject)
            {
                character->addTrait(trait);
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void SetRandomTraits(object character, string persona)
{
    string *potentialTraits = personaBlueprints()[persona]["potential traits"] + ({});
    if (sizeof(potentialTraits))
    {
        object traitsDictionary = load_object("/lib/dictionaries/traitsDictionary.c");
        int numberOfPossibleTraits = random(sizeof(potentialTraits));

        while (numberOfPossibleTraits > 0)
        {
            string trait = potentialTraits[random(sizeof(potentialTraits))];
            potentialTraits -= ({ trait });

            object traitObject = traitsDictionary->traitObject(trait);
            if (traitObject)
            {
                character->addTrait(trait);
            }
            numberOfPossibleTraits--;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void SetCombatAttributes(object character, string persona)
{
    int level = character->effectiveLevel();
    character->setMaxHitPoints(
        personaBlueprints()[persona]["base hit points"] * level);

    character->setMaxSpellPoints(
        personaBlueprints()[persona]["base spell points"] * level);

    character->setMaxStaminaPoints(
        personaBlueprints()[persona]["base stamina points"] * level);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setupPersona(string persona, object character)
{
    if (objectp(character) &&
        ((member(inherit_list(character), "lib/realizations/monster.c") > -1) ||
        (member(inherit_list(character), "lib/realizations/henchman.c") > -1)))
    {
        if (!character->effectiveLevel())
        {
            raise_error("personaDictionary: The character's level must be set "
                "before a persona is selected.");
        }

        if (persona && member(personaBlueprints(), persona))
        {
            SetStats(character);
            SetPrimarySkills(character, persona);
            SetSecondarySkills(character, persona);
            SetTraits(character, persona);
            SetRandomTraits(character, persona);
            SetCombatAttributes(character, persona);
        }
        else
        {
            raise_error("personaDictionary: An invalid persona was selected.");
        }
    }
    else
    {
        raise_error("personaDictionary: Personas can only be set for NPCs.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask object *getRandomEquipment(object persona, int chanceForMagicalItems)
{

}
