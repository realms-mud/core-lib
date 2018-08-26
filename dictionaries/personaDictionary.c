//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "personas/creatures.h"
#include "personas/fighters.h"

/////////////////////////////////////////////////////////////////////////////
private nomask mapping personaBlueprints()
{
    return creatureBlueprints + 
        fighterBlueprints + ([]);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void SetStats(object character)
{
    int level = character->effectiveLevel() * 2;
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
    int level = to_int(character->effectiveLevel() * 2);

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
    int skillLevel = character->effectiveLevel();

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
    character->addTrait(sprintf("lib/modules/traits/personas/%s/%s.c", 
        personaBlueprints()[persona]["category"], persona));

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
private nomask void SetAttacks(object character, string persona)
{
    if (member(personaBlueprints()[persona], "attacks"))
    {
        string *attacks = m_indices(personaBlueprints()[persona]["attacks"]);
        int level = character->effectiveLevel();

        foreach(string attack in attacks)
        {
            character->addAttack(attack,
                personaBlueprints()[persona]["attacks"][attack] + level / 2,
                75 + to_int(level * 1.5));
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

    character->hitPoints(character->maxHitPoints());
    character->spellPoints(character->maxSpellPoints());
    character->staminaPoints(character->maxStaminaPoints());
}

/////////////////////////////////////////////////////////////////////////////
private int minimumLevelMet(object character, string persona)
{
    return (member(personaBlueprints(), persona) &&
        (!member(personaBlueprints()[persona], "minimum level") ||
        (personaBlueprints()[persona]["minimum level"] <=
            character->effectiveLevel())));
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setupPersona(string persona, object character)
{
    if (objectp(character) &&
        ((member(inherit_list(character), "lib/realizations/monster.c") > -1) ||
        (member(inherit_list(character), "lib/realizations/henchman.c") > -1)))
    {
        if (sizeof(character->Traits("persona")))
        {
            raise_error("personaDictionary: A character may only have "
                "one persona.\n");
        }
        if (!character->effectiveLevel())
        {
            raise_error("personaDictionary: The character's level must be set "
                "before a persona is selected.\n");
        }
        if (persona && member(personaBlueprints(), persona))
        {
            if (minimumLevelMet(character, persona))
            {
                SetStats(character);
                SetPrimarySkills(character, persona);
                SetSecondarySkills(character, persona);
                SetAttacks(character, persona);
                SetTraits(character, persona);
                SetRandomTraits(character, persona);
                SetCombatAttributes(character, persona);
            }
            else
            {
                raise_error("personaDictionary: The character's level is lower "
                    "than that required for this persona.\n");
            }
        }
        else
        {
            raise_error("personaDictionary: An invalid persona was selected.\n");
        }
    }
    else
    {
        raise_error("personaDictionary: Personas can only be set for NPCs.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
private mapping getEquipmentList(string personaTrait)
{
    mapping equipmentList = 0;

    object personaObj = 
        load_object("/lib/dictionaries/traitsDictionary.c")->traitObject(personaTrait);

    if(personaObj)
    {
        string personaName = personaObj->query("name");

        if (personaName && member(personaBlueprints(), personaName) &&
            member(personaBlueprints()[personaName], "equipment"))
        {
            equipmentList = personaBlueprints()[personaName]["equipment"];
        }
    }
    return equipmentList;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object *getRandomEquipment(object persona, int chanceForMagicalItems)
{
    object *equipment = ({});
    if (objectp(persona))
    {
        string *personas = persona->Traits("persona");
        if (!sizeof(personas))
        {
            raise_error("personaDictionary: A character must have a persona "
                "before creating equipment.\n");
        }

        object materialsDictionary =
            load_object("/lib/dictionaries/materialsDictionary.c");
        
        mapping equipmentList = getEquipmentList(personas[0]);
        if (equipmentList)
        {
            foreach(string item in m_indices(equipmentList))
            {
                string type;
                string subtype;
                string *listOfPotentialItems = 0;

                if (sizeof(regexp(({ item }), "[a-z]+/[a-z]+")))
                {
                    string *types = explode(item, "/");
                    type = types[0];
                    subtype = types[1];
                    listOfPotentialItems = equipmentList[item];
                }
                else
                {
                    type = item;
                    if (sizeof(regexp(({ equipmentList[item] }), "[a-z]+/[a-z]+")))
                    {
                    
                        string *subtypes = explode(equipmentList[item][
                            random(sizeof(equipmentList[item]))], "/");
                        subtype = subtypes[0];
                        listOfPotentialItems = ({ subtypes[1] });
                    }
                    else
                    {
                        subtype = equipmentList[item][
                            random(sizeof(equipmentList[item]))];
                    }
                }

                equipment += ({ materialsDictionary->generateRandomItem(
                    type, subtype, chanceForMagicalItems, listOfPotentialItems) });

            }
        }
    }
    return equipment + ({});
}
