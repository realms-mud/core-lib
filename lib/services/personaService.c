//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "personas/creatures.h"
#include "personas/dragons.h"
#include "personas/fighters.h"
#include "personas/magicUsers.h"
#include "personas/clerics.h"

/////////////////////////////////////////////////////////////////////////////
private nomask mapping personaBlueprints()
{
    return creatureBlueprints + 
        dragonBlueprints +
        magicUserBlueprints +
        fighterBlueprints + 
        divineUserBlueprints + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidPersona(string persona)
{
    return member(personaBlueprints(), persona);
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
private nomask varargs void SetDescription(object character,
    string persona)
{
    if (objectp(character) && (sizeof(character->description()) < 1) &&
        member(personaBlueprints()[persona], "description"))
    {
        character->description(personaBlueprints()[persona]["description"] +
            " " + getService("racial")->racialDescription(character));
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs void SetPrimarySkills(object character, 
    string persona, int onlyAdvanceLevel)
{
    string *primarySkills = personaBlueprints()[persona]["primary skills"];
    int level = onlyAdvanceLevel ? 2 :
        to_int(character->effectiveLevel() * 2);

    foreach(string skill in primarySkills)
    {
        int neededSkillPoints = character->advanceSkillCost(skill, level);
        character->addSkillPoints(neededSkillPoints);
        character->advanceSkill(skill, level);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs void SetSecondarySkills(object character, 
    string persona, int onlyAdvanceLevel)
{
    string *secondarySkills = personaBlueprints()[persona]["secondary skills"];
    int skillLevel = onlyAdvanceLevel ? 1 : character->effectiveLevel();

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
private nomask void SetResearch(object character, string persona)
{
    if (member(personaBlueprints()[persona], "research"))
    {
        string *researchItems = m_indices(personaBlueprints()[persona]["research"]);

        if (sizeof(researchItems))
        {
            foreach(string research in researchItems)
            {
                if (character->effectiveLevel() >=
                    personaBlueprints()[persona]["research"][research])
                {
                    string fullyQualifiedResearch =
                        sprintf("/lib/instances/research/personas/%s/%s.c",
                            regreplace(persona, " ", "-", 1),
                            regreplace(research, " ", "-", 1));

                    character->initiateResearch(fullyQualifiedResearch);
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void SetTraits(object character, string persona)
{
    string *traits = personaBlueprints()[persona]["traits"];

    character->addTrait(sprintf("/lib/instances/traits/personas/%s/%s.c",
        personaBlueprints()[persona]["category"], 
        regreplace(persona, " ", "-", 1)));

    if (sizeof(traits))
    {
        object traitsService = getService("traits");

        foreach(string trait in traits)
        {
            object traitObject = traitsService->traitObject(trait);
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
        object traitsService = getService("traits");
        int numberOfPossibleTraits = random(sizeof(potentialTraits));

        while (numberOfPossibleTraits > 0)
        {
            string trait = potentialTraits[random(sizeof(potentialTraits))];
            potentialTraits -= ({ trait });

            object traitObject = traitsService->traitObject(trait);
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

        character->clearAttacks();
        foreach(string attack in attacks)
        {
            character->addAttack(attack,
                personaBlueprints()[persona]["attacks"][attack] + level,
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
private nomask void SetRace(object character, string persona)
{
    object RaceService = getService("racial");

    if (!character->Race())
    {
        character->Race(member(personaBlueprints()[persona], "is humanoid") ?
            RaceService->getRandomRace() : persona);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void SetAliases(object character, string persona)
{
    if (member(personaBlueprints()[persona], "aliases"))
    {
        string *aliases = personaBlueprints()[persona]["aliases"];
 
        foreach(string alias in aliases)
        {
            character->addAlias(alias);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setupPersona(string persona, object character)
{
    if (objectp(character) &&
        ((member(inherit_list(character), "/lib/realizations/monster.c") > -1) ||
        (member(inherit_list(character), "/lib/realizations/henchman.c") > -1)))
    {
        if (sizeof(character->Traits("persona")))
        {
            raise_error("personaService: A character may only have "
                "one persona.\n");
        }
        if (!character->effectiveLevel())
        {
            raise_error("personaService: The character's level must be set "
                "before a persona is selected.\n");
        }
        if (persona && member(personaBlueprints(), persona))
        {
            if (minimumLevelMet(character, persona))
            {
                SetRace(character, persona);
                SetDescription(character, persona);
                SetStats(character);
                SetPrimarySkills(character, persona);
                SetSecondarySkills(character, persona);
                SetAttacks(character, persona);
                SetTraits(character, persona);
                SetRandomTraits(character, persona);
                SetCombatAttributes(character, persona);
                SetResearch(character, persona);
                SetAliases(character, persona);
            }
            else
            {
                raise_error("personaService: The character's level is lower "
                    "than that required for this persona.\n");
            }
        }
        else
        {
            raise_error("personaService: An invalid persona was selected.\n");
        }
    }
    else
    {
        raise_error("personaService: Personas can only be set for NPCs.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void advanceLevel(object character)
{
    if (objectp(character) && character->persona() &&
        sizeof(character->Traits("persona")) &&
        ((member(inherit_list(character), "/lib/realizations/monster.c") > -1) ||
            (member(inherit_list(character), "/lib/realizations/henchman.c") > -1)))
    {
        SetStats(character);
        SetPrimarySkills(character, character->persona(), 1);
        SetSecondarySkills(character, character->persona(), 1);
        SetAttacks(character, character->persona());
        SetCombatAttributes(character, character->persona());
    }
}

/////////////////////////////////////////////////////////////////////////////
private mapping getEquipmentList(string personaTrait)
{
    mapping equipmentList = 0;

    object personaObj = 
        getService("traits")->traitObject(personaTrait);

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
        if (!persona->persona())
        {
            raise_error("personaService: A character must have a persona "
                "before creating equipment.\n");
        }

        if(sizeof(personas))
        {
            object materialsService = getService("materials");
        
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

                    equipment += ({ materialsService->generateRandomItem(
                        type, subtype, chanceForMagicalItems, listOfPotentialItems) });

                }
            }
        }
    }
    return equipment + ({});
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getRandomPersona(string type, int level)
{
    string ret = type;
    mapping blueprints = personaBlueprints();

    switch (ret)
    {
        case "outlaw":
        case "ruffian":
        {
            string *personas = filter(m_indices(blueprints),
                (: $2[$1]["category"] == "fighters" :), blueprints);
            personas -= ({ "knight", "phaedra", "knight of the storm" });

            ret = personas[random(sizeof(personas))];
            break;
        }
        case "magic user":
        {
            string *personas = filter(m_indices(blueprints),
                (: $2[$1]["category"] == "mages" :), blueprints);

            ret = personas[random(sizeof(personas))];
            break;
        }
        case "dragon":
        {
            string *personas = filter(m_indices(blueprints),
                (: $2[$1]["category"] == "dragons" :), blueprints);

            ret = personas[random(sizeof(personas))];
            break;
        }
        case "creature":
        {
            string *personas = filter(m_indices(blueprints),
                (: $2[$1]["category"] == "creatures" :), blueprints);

            ret = personas[random(sizeof(personas))];
            break;
        }
        case "undead":
        {
            string *personas = filter(m_indices(blueprints),
                (: $2[$1]["category"] == "undead" :), blueprints);

            ret = personas[random(sizeof(personas))];
            break;
        }
        case "hunter":
        {
            ret = random(2) ? "archer" : "crossbowman";
            break;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getValidLevel(string persona, int level, object target)
{
    int ret = (level > 0) ? level : 1;

    mapping blueprints = personaBlueprints();

    if (member(blueprints, persona) &&
        (member(inherit_list(target), "/lib/realizations/henchman.c") == -1))
    {
        if (member(blueprints[persona], "minimum level") &&
            (ret < blueprints[persona]["minimum level"]))
        {
            ret = blueprints[persona]["minimum level"];
        }
        else if (member(blueprints[persona], "maximum level") &&
            (ret > blueprints[persona]["maximum level"]))
        {
            ret = blueprints[persona]["maximum level"];
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *filterEncountersForLevel(string *encounters, int level)
{
    mapping blueprints = personaBlueprints();

    return filter(encounters, (: (!member($2, $1) ||
        ((!member($2[$1], "minimum level") || (member($2[$1], "minimum level") && 
            (level >= $2[$1]["minimum level"]))) &&
        (!member($2[$1], "maximum level") || (member($2[$1], "maximum level") && 
            (level <= $2[$1]["maximum level"]))))) :), blueprints);
}
