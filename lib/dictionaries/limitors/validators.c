//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
private nomask int validRaceLimitor(mixed raceValue)
{
    int ret = 0;
    object racialDictionary = getDictionary("racial");
    if (racialDictionary)
    {
        if (pointerp(raceValue) && sizeof(raceValue))
        {
            int isValid = 0;
            foreach(string race in raceValue)
            {
                isValid ||= 
                    racialDictionary->isValidRace(race) ||
                    racialDictionary->isCreatureRace(race);
            }
            ret = isValid;
        }
        else
        {
            ret = racialDictionary->isValidRace(raceValue) ||
                racialDictionary->isCreatureRace(raceValue);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validGuildLimitor(mixed guildValue)
{
    int ret = 0;
    object guildDictionary = getDictionary("guilds");
    if (guildDictionary)
    {
        if (pointerp(guildValue) && sizeof(guildValue))
        {
            int isValid = 0;
            foreach(string guild in guildValue)
            {
                isValid ||= 
                    guildDictionary->isValidGuild(guild);
            }
            ret = isValid;
        }
        else
        {
            ret = guildDictionary->isValidGuild(guildValue);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validFactionLimitor(mixed factionValue)
{
    int ret = 0;
    object factionDictionary = getDictionary("factions");
    if (factionDictionary)
    {
        if (pointerp(factionValue) && sizeof(factionValue))
        {
            int isValid = 0;
            foreach(string faction in factionValue)
            {
                isValid ||= 
                    factionDictionary->isValidFaction(faction);
            }
            ret = isValid;
        }
        else
        {
            ret = factionDictionary->isValidFaction(factionValue);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validSkillLimitor(mapping skills)
{
    int ret = 0;

    object skillsDictionary = getDictionary("skills");
    if (skillsDictionary && mappingp(skills) &&
        sizeof(skills))
    {
        ret = 1;
        foreach(string skill in m_indices(skills))
        {
            ret &&= skillsDictionary->isValidSkill(skill) && 
                intp(skills[skill]);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validAttributeLimitor(mixed attributes)
{
    int ret = 0;
    if (mappingp(attributes) && sizeof(attributes))
    {
        ret = 1;
        foreach(string attribute in m_indices(attributes))
        {
            ret &&= getDictionary("attribute")->isValidAttribute(attribute) &&
                intp(attributes[attribute]);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validQuestLimitor(mixed questValue)
{
    int ret = 0;

    object questDictionary = getDictionary("quests");
    if (questDictionary)
    {
        if (pointerp(questValue) && sizeof(questValue))
        {
            int isValid = 0;
            foreach(string quest in questValue)
            {
                isValid ||= 
                    objectp(questDictionary->questObject(quest));
            }
            ret = isValid;
        }
        else
        {
            ret = objectp(questDictionary->questObject(questValue));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validResearchLimitor(mixed researchValue)
{
    int ret = 0;
    object researchDictionary = getDictionary("research");
    if (researchDictionary)
    {
        if (pointerp(researchValue) && sizeof(researchValue))
        {
            int isValid = 0;
            foreach(string research in researchValue)
            {
                isValid ||=
                    researchDictionary->validResearch(research);
            }
            ret = isValid;
        }
        else
        {
            ret = 
                researchDictionary->validResearch(researchValue);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validResearchIsActiveLimitor(mixed researchValue)
{
    int ret = 0;
    object researchDictionary = getDictionary("research");
    if (researchDictionary)
    {
        if (pointerp(researchValue) && sizeof(researchValue))
        {
            int isValid = 0;
            foreach(string research in researchValue)
            {
                isValid ||= 
                    researchDictionary->isSustainedResearchItem(research);
            }
            ret = isValid;
        }
        else
        {
            ret = 
                researchDictionary->isSustainedResearchItem(researchValue);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validTraitsLimitor(mixed traitValue)
{
    int ret = 0;
    object traitDictionary = getDictionary("traits");
    if (traitDictionary)
    {
        if (pointerp(traitValue) && sizeof(traitValue))
        {
            int isValid = 0;
            foreach(string trait in traitValue)
            {
                isValid ||= 
                    traitDictionary->validTrait(trait);
            }
            ret = isValid;
        }
        else
        {
            ret = traitDictionary->validTrait(traitValue);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validTimeOfDayLimitor(mixed timeOfDayValue)
{
    int ret = 0;
    object environmentDictionary = getDictionary("environment");
    if (environmentDictionary)
    {
        if (pointerp(timeOfDayValue) && sizeof(timeOfDayValue))
        {
            int isValid = 0;
            foreach(string timeOfDay in timeOfDayValue)
            {
                isValid ||= environmentDictionary->isValidTimeOfDay(
                    timeOfDay);
            }
            ret = isValid;
        }
        else
        {
            ret = environmentDictionary->isValidTimeOfDay(timeOfDayValue);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validSeasonLimitor(mixed seasonValue)
{
    int ret = 0;
    object environmentDictionary = getDictionary("environment");
    if (environmentDictionary)
    {
        if (pointerp(seasonValue) && sizeof(seasonValue))
        {
            int isValid = 0;
            foreach(string season in seasonValue)
            {
                isValid ||= environmentDictionary->isValidSeason(
                    season);
            }
            ret = isValid;
        }
        else
        {
            ret = environmentDictionary->isValidSeason(seasonValue);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validMoonPhaseLimitor(mixed moonPhaseValue)
{
    int ret = 0;
    object environmentDictionary = getDictionary("environment");
    if (environmentDictionary)
    {
        if (pointerp(moonPhaseValue) && sizeof(moonPhaseValue))
        {
            int isValid = 0;
            foreach(string moonPhase in moonPhaseValue)
            {
                isValid ||= environmentDictionary->isValidMoonPhase(
                    moonPhase);
            }
            ret = isValid;
        }
        else
        {
            ret = environmentDictionary->isValidMoonPhase(
                moonPhaseValue);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validCraftingTypeLimitor(mixed type)
{
    int ret = 0;
    object craftingDictionary = getDictionary("crafting");
    if (craftingDictionary)
    {
        ret = craftingDictionary->isValidType(type);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validEnvironmentLimitor(mixed type)
{
    int ret = 0;
    object environmentDictionary = getDictionary("environment");
    if (environmentDictionary)
    {
        ret = environmentDictionary->isValidType(type);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validEquipmentLimitor(mixed equipmentValue)
{
    int ret = 0;

    object materialsDictionary = getDictionary("materials");
    if (materialsDictionary)
    {
        if (pointerp(equipmentValue) && sizeof(equipmentValue))
        {
            int isValid = 0;
            foreach(string equipment in equipmentValue)
            {
                isValid ||= materialsDictionary->isValidArmorType(equipment) ||
                    materialsDictionary->isValidArmorBlueprint(equipment) ||
                    materialsDictionary->isValidWeaponType(equipment) ||
                    materialsDictionary->isValidWeaponBlueprint(equipment);
            }
            ret = isValid;
        }
        else
        {
            ret = materialsDictionary->isValidArmorType(equipmentValue) ||
                materialsDictionary->isValidArmorBlueprint(equipmentValue) ||
                materialsDictionary->isValidWeaponType(equipmentValue) ||
                materialsDictionary->isValidWeaponBlueprint(equipmentValue);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int validLimitor(mapping limitor)
{
    int ret = 0;
    if (limitor && mappingp(limitor))
    {
        string *limitorKeys = m_indices(limitor);
        if (sizeof(limitorKeys))
        {
            ret = 1;
        }

        object limitorDictionary = getDictionary("limitor");
        foreach(string key in limitorKeys)
        {
            if (key && stringp(key))
            {
                switch (key)
                {
                    case "race":
                    case "opponent race":
                    {
                        ret &&= validRaceLimitor(limitor[key]);
                        break;
                    }
                    case "guild":
                    case "opponent guild":
                    {
                        ret &&= validGuildLimitor(limitor[key]);
                        break;
                    }
                    case "faction":
                    case "opponent faction":
                    {
                        ret &&= validFactionLimitor(limitor[key]);
                        break;
                    }
                    case "skill":
                    {
                        ret &&= validSkillLimitor(limitor[key]);
                        break;
                    }
                    case "attribute":
                    {
                        ret &&= validAttributeLimitor(limitor[key]);
                        break;
                    }
                    case "quests":
                    {
                        ret &&= validQuestLimitor(limitor[key]);
                        break;
                    }
                    case "research":
                    {
                        ret &&= validResearchLimitor(limitor[key]);
                        break;
                    }
                    case "research active":
                    {
                        ret &&= validResearchIsActiveLimitor(limitor[key]);
                        break;
                    }
                    case "traits":
                    {
                        ret &&= validTraitsLimitor(limitor[key]);
                        break;
                    }
                    case "time of day":
                    {
                        ret &&= validTimeOfDayLimitor(limitor[key]);
                        break;
                    }
                    case "season":
                    {
                        ret &&= validSeasonLimitor(limitor[key]);
                        break;
                    }
                    case "moon phase":
                    {
                        ret &&= validMoonPhaseLimitor(limitor[key]);
                        break;
                    }
                    case "crafting type":
                    {
                        ret &&= validCraftingTypeLimitor(limitor[key]);
                        break;
                    }
                    case "environment":
                    {
                        ret &&= validEnvironmentLimitor(limitor[key]);
                        break;
                    }
                    case "environment state":
                    {
                        ret &&= (pointerp(limitor[key]) && sizeof(limitor[key])) ||
                            stringp(limitor[key]);
                        break;
                    }
                    case "equipment":
                    {
                        ret &&= validEquipmentLimitor(limitor[key]);
                        break;
                    }
                    case "intoxicated":
                    case "drugged":
                    {
                        ret &&= intp(limitor[key]);
                        break;
                    }
                    case "near death":
                    case "stamina drained":
                    case "spell points drained":
                    {
                        ret &&= intp(limitor[key]) && (limitor[key] >= 0)
                            && (limitor[key] <= 100);
                        break;
                    }
                    default:
                    {
                        ret = 0;
                    }
                }
            }
            else
            {
                ret = 0;
            }
        }
    }
    return ret;
}
