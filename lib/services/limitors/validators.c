//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
private nomask int validRaceLimitor(mixed raceValue)
{
    int ret = 0;
    object RaceService = getService("racial");
    if (RaceService)
    {
        if (pointerp(raceValue) && sizeof(raceValue))
        {
            int isValid = 0;
            foreach(string race in raceValue)
            {
                isValid ||= 
                    RaceService->isValidRace(race) ||
                    RaceService->isCreatureRace(race);
            }
            ret = isValid;
        }
        else
        {
            ret = RaceService->isValidRace(raceValue) ||
                RaceService->isCreatureRace(raceValue);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validGuildLimitor(mixed guildValue)
{
    int ret = 0;
    object guildService = getService("guilds");
    if (guildService)
    {
        if (pointerp(guildValue) && sizeof(guildValue))
        {
            int isValid = 0;
            foreach(string guild in guildValue)
            {
                isValid ||= 
                    guildService->isValidGuild(guild);
            }
            ret = isValid;
        }
        else
        {
            ret = guildService->isValidGuild(guildValue);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validFactionLimitor(mixed factionValue)
{
    int ret = 0;
    object factionService = getService("factions");
    if (factionService)
    {
        if (pointerp(factionValue) && sizeof(factionValue))
        {
            int isValid = 0;
            foreach(string faction in factionValue)
            {
                isValid ||= 
                    factionService->isValidFaction(faction);
            }
            ret = isValid;
        }
        else
        {
            ret = factionService->isValidFaction(factionValue);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validSkillLimitor(mapping skills)
{
    int ret = 0;

    object skillsService = getService("skills");
    if (skillsService && mappingp(skills) &&
        sizeof(skills))
    {
        ret = 1;
        foreach(string skill in m_indices(skills))
        {
            ret &&= skillsService->isValidSkill(skill) && 
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
            ret &&= getService("attribute")->isValidAttribute(attribute) &&
                intp(attributes[attribute]);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validQuestLimitor(mixed questValue)
{
    int ret = 0;

    object questService = getService("quests");
    if (questService)
    {
        if (pointerp(questValue) && sizeof(questValue))
        {
            int isValid = 0;
            foreach(string quest in questValue)
            {
                isValid ||= 
                    objectp(questService->questObject(quest));
            }
            ret = isValid;
        }
        else
        {
            ret = objectp(questService->questObject(questValue));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validResearchLimitor(mixed researchValue)
{
    int ret = 0;
    object researchService = getService("research");
    if (researchService)
    {
        if (pointerp(researchValue) && sizeof(researchValue))
        {
            int isValid = 0;
            foreach(string research in researchValue)
            {
                isValid ||=
                    researchService->validResearch(research);
            }
            ret = isValid;
        }
        else
        {
            ret = 
                researchService->validResearch(researchValue);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validResearchIsActiveLimitor(mixed researchValue)
{
    int ret = 0;
    object researchService = getService("research");
    if (researchService)
    {
        if (pointerp(researchValue) && sizeof(researchValue))
        {
            int isValid = 0;
            foreach(string research in researchValue)
            {
                isValid ||= 
                    researchService->isSustainedResearchItem(research);
            }
            ret = isValid;
        }
        else
        {
            ret = 
                researchService->isSustainedResearchItem(researchValue);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validTraitsLimitor(mixed traitValue)
{
    int ret = 0;
    object TraitService = getService("traits");
    if (TraitService)
    {
        if (pointerp(traitValue) && sizeof(traitValue))
        {
            int isValid = 0;
            foreach(string trait in traitValue)
            {
                isValid ||= 
                    TraitService->validTrait(trait);
            }
            ret = isValid;
        }
        else
        {
            ret = TraitService->validTrait(traitValue);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validTimeOfDayLimitor(mixed timeOfDayValue)
{
    int ret = 0;
    object environmentService = getService("environment");
    if (environmentService)
    {
        if (pointerp(timeOfDayValue) && sizeof(timeOfDayValue))
        {
            int isValid = 0;
            foreach(string timeOfDay in timeOfDayValue)
            {
                isValid ||= environmentService->isValidTimeOfDay(
                    timeOfDay);
            }
            ret = isValid;
        }
        else
        {
            ret = environmentService->isValidTimeOfDay(timeOfDayValue);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validSeasonLimitor(mixed seasonValue)
{
    int ret = 0;
    object environmentService = getService("environment");
    if (environmentService)
    {
        if (pointerp(seasonValue) && sizeof(seasonValue))
        {
            int isValid = 0;
            foreach(string season in seasonValue)
            {
                isValid ||= environmentService->isValidSeason(
                    season);
            }
            ret = isValid;
        }
        else
        {
            ret = environmentService->isValidSeason(seasonValue);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validMoonPhaseLimitor(mixed moonPhaseValue)
{
    int ret = 0;
    object environmentService = getService("environment");
    if (environmentService)
    {
        if (pointerp(moonPhaseValue) && sizeof(moonPhaseValue))
        {
            int isValid = 0;
            foreach(string moonPhase in moonPhaseValue)
            {
                isValid ||= environmentService->isValidMoonPhase(
                    moonPhase);
            }
            ret = isValid;
        }
        else
        {
            ret = environmentService->isValidMoonPhase(
                moonPhaseValue);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validCraftingTypeLimitor(mixed type)
{
    object craftingService = getService("crafting");
	object vehicleService = getService("vehicle");

    return (craftingService && craftingService->isValidType(type)) ||
		(vehicleService && vehicleService->isValidType(type));
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validEnvironmentLimitor(mixed type)
{
    int ret = 0;
    object environmentService = getService("environment");
    if (environmentService)
    {
        ret = environmentService->isValidType(type);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validEquipmentLimitor(mixed equipmentValue)
{
    int ret = 0;

    object materialsService = getService("materials");
    if (materialsService)
    {
        if (pointerp(equipmentValue) && sizeof(equipmentValue))
        {
            int isValid = 0;
            foreach(string equipment in equipmentValue)
            {
                isValid ||= materialsService->isValidArmorType(equipment) ||
                    materialsService->isValidArmorBlueprint(equipment) ||
                    materialsService->isValidInstrumentBlueprint(equipment) ||
                    materialsService->isValidWeaponType(equipment) ||
                    materialsService->isValidWeaponBlueprint(equipment);
            }
            ret = isValid;
        }
        else
        {
            ret = materialsService->isValidArmorType(equipmentValue) ||
                materialsService->isValidArmorBlueprint(equipmentValue) ||
                materialsService->isValidInstrumentBlueprint(equipmentValue) ||
                materialsService->isValidWeaponType(equipmentValue) ||
                materialsService->isValidWeaponBlueprint(equipmentValue);
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

        object limitorService = getService("limitor");
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
