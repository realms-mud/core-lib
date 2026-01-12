//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
protected nomask int checkOpponentRaceLimitor(mapping specificationData, 
    object target, int verbose, string colorConfiguration, 
    object configuration)
{
    int ret = 1;
 
    if (member(specificationData["limited by"], "opponent race"))
    {
        string *races = 
            pointerp(specificationData["limited by"]["opponent race"]) ?
            specificationData["limited by"]["opponent race"] :
            ({ specificationData["limited by"]["opponent race"] });

        ret &&= target && objectp(target) &&
            function_exists("Race", target) && 
            (member(races, target->Race()) > -1);

        if (!ret && verbose)
        {
            write(configuration->decorate(
                sprintf("Your opponent is not of the %s race.\n",
                specificationData["limited by"]["opponent race"]),
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int checkOpponentGuildLimitor(mapping specificationData, 
    object target, int verbose, string colorConfiguration, 
    object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "opponent guild"))
    {
        ret &&= target && objectp(target) &&
            function_exists("memberOfGuild", target) &&
            target->memberOfGuild(
                specificationData["limited by"]["opponent guild"]);

        if (!ret && verbose)
        {
            write(configuration->decorate(
                sprintf("Your opponent is not of the %s guild.\n",
                specificationData["limited by"]["opponent guild"]),
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int checkOpponentFactionLimitor(mapping specificationData, 
    object target, int verbose, string colorConfiguration, 
    object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "opponent faction"))
    {
        ret &&= target && objectp(target) &&
            function_exists("memberOfFaction", target) &&
            target->memberOfFaction(
                specificationData["limited by"]["opponent faction"]);

        if (!ret && verbose)
        {
            object faction = getService("factions")->factionObject(
                specificationData["limited by"]["opponent faction"]);

            if (faction)
            {
                write(configuration->decorate(
                    sprintf("Your opponent is not of the %s faction.\n",
                    faction->name()),
                    "missing prerequisites", "research", colorConfiguration));
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int checkOpponentEquipmentMaterialLimitor(mapping specificationData, 
    object target, int verbose, string colorConfiguration, 
    object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "opponent equipment material"))
    {
        ret = 0;

        if (target && objectp(target) && 
            function_exists("equipmentInSlot", target))
        {
            object materialsService = getService("materials");

            if (materialsService)
            {
                string *validMaterials = 
                    pointerp(specificationData["limited by"]["opponent equipment material"]) ?
                    specificationData["limited by"]["opponent equipment material"] :
                    ({ specificationData["limited by"]["opponent equipment material"] });

                string *slots = ({ "wielded primary", "wielded offhand", "armor", 
                    "gloves", "helmet", "boots", "ring 1", "ring 2", "cloak", 
                    "amulet", "belt", "arm greaves", "leg greaves", "bracers" });

                foreach(string slot in slots)
                {
                    object item = target->equipmentInSlot(slot);

                    if (item && objectp(item))
                    {
                        string material = item->query("material");
                        if (material)
                        {
                            string materialClass = 
                                materialsService->getMaterialTypeForMaterial(material);

                            if (member(validMaterials, materialClass) > -1)
                            {
                                ret = 1;
                                break;
                            }
                        }
                    }
                }
            }
        }

        if (!ret && verbose)
        {
            string materialList = 
                pointerp(specificationData["limited by"]["opponent equipment material"]) ?
                implode(specificationData["limited by"]["opponent equipment material"], ", ") :
                specificationData["limited by"]["opponent equipment material"];

            write(configuration->decorate(
                sprintf("Your opponent is not using equipment made of %s.\n",
                    materialList),
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int checkCraftingTypeLimitor(mapping specificationData, 
    object target, int verbose, string colorConfiguration, 
    object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "crafting type"))
    {
        ret &&= objectp(target);

        if (stringp(specificationData["limited by"]["crafting type"]) &&
            target)
        {
            ret &&= ((target->query("crafting type") ==
                specificationData["limited by"]["crafting type"]) ||
                (getService("materials")->getBlueprintDetails(target,
                    "skill to use") == 
                    specificationData["limited by"]["crafting type"]));
        }
        else if (pointerp(specificationData["limited by"]["crafting type"]) &&
            target)
        {
            int checkList = 0;
            object materials = getService("materials");

            foreach(string key in specificationData["limited by"]["crafting type"])
            {
                checkList += ((target->query("crafting type") == key) ||
                    (materials->getBlueprintDetails(target,
                        "skill to use") == key));
            }
            ret &&= checkList;
        }
        if (!ret && verbose)
        {
            write(configuration->decorate(
                "The item is of the wrong type to be affected by this research.\n",
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int checkIntoxicatedLimitor(mapping specificationData, 
    object owner, int verbose, string colorConfiguration, 
    object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "intoxicated"))
    {
        ret &&= function_exists("Intoxicated", owner) &&
            (owner->Intoxicated() >=
                specificationData["limited by"]["intoxicated"]);
        if (!ret && verbose)
        {
            write(configuration->decorate(
                "You are not intoxicated enough to do that.\n",
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int checkDruggedLimitor(mapping specificationData, 
    object owner, int verbose, string colorConfiguration, 
    object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "drugged"))
    {
        ret &&= function_exists("Drugged", owner) &&
            (owner->Drugged() >= specificationData["limited by"]["drugged"]);
        if (!ret && verbose)
        {
            write(configuration->decorate(
                "You are not drugged enough to do that.\n",
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int checkNearDeathLimitor(mapping specificationData, 
    object owner, int verbose, string colorConfiguration, 
    object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "near death"))
    {
        ret &&= function_exists("hitPoints", owner) &&
            (owner->hitPoints() <= specificationData["limited by"]["near death"]);
        if (!ret && verbose)
        {
            write(configuration->decorate(
                "You are not injured enough to do that.\n",
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int checkStaminaDrainedLimitor(mapping specificationData, 
    object owner, int verbose, string colorConfiguration, 
    object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "stamina drained"))
    {
        ret &&= function_exists("staminaPoints", owner) &&
            (owner->staminaPoints() <= specificationData["limited by"]["stamina drained"]);
        if (!ret && verbose)
        {
            write(configuration->decorate(
                "You are not weary enough to do that.\n",
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int checkSpellPointsDrainedLimitor(mapping specificationData, 
    object owner, int verbose, string colorConfiguration, 
    object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "spell points drained"))
    {
        ret &&= function_exists("spellPoints", owner) &&
            (owner->spellPoints() <= specificationData["limited by"]["spell points drained"]);
        if (!ret && verbose)
        {
            write(configuration->decorate(
                "You are not drained enough to do that.\n",
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int checkEquipmentLimitor(mapping specificationData, 
    object owner, int verbose, string colorConfiguration, 
    object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "equipment"))
    {
        if (pointerp(specificationData["limited by"]["equipment"]) &&
            sizeof(specificationData["limited by"]["equipment"]))
        {
            int hasEquipment = 0;
            string *list = specificationData["limited by"]["equipment"];
            foreach(string equipment in list)
            {
                hasEquipment ||= owner->usingEquipmentOfType(equipment);
            }
            ret &&= hasEquipment;
        }
        else
        {
            ret &&= function_exists("usingEquipmentOfType", owner) &&
                owner->usingEquipmentOfType(specificationData["limited by"]["equipment"]);
        }

        if (!ret && verbose)
        {
            write(configuration->decorate(
                sprintf("You must be using the proper equipment for that (%s).\n",
                stringp(specificationData["limited by"]["equipment"]) ? 
                    specificationData["limited by"]["equipment"] :
                    implode(sort_array(specificationData["limited by"]["equipment"], 
                        (: $1 > $2 :)), ", ")),
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int checkSkillLimitor(mapping specificationData, object owner, 
    int verbose, string colorConfiguration, object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "skill"))
    {
        foreach(string skill in 
            m_indices(specificationData["limited by"]["skill"]))
        {
            int skillCheck = (owner->getSkill(skill) >=
                specificationData["limited by"]["skill"][skill]);

            ret &&= skillCheck;
            if (!skillCheck && verbose)
            {
                write(configuration->decorate(
                    sprintf("You need a minimum of %d in %s to do that.\n",
                        specificationData["limited by"]["skill"][skill], skill),
                    "missing prerequisites", "research", colorConfiguration));
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int checkAttributeLimitor(mapping specificationData, 
    object owner, int verbose, string colorConfiguration, 
    object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "attribute"))
    {
        foreach(string attribute in
            m_indices(specificationData["limited by"]["attribute"]))
        {
            int attributeCheck = (owner->attributeValue(attribute) >=
                specificationData["limited by"]["attribute"][attribute]);

            ret &&= attributeCheck;
            if (!attributeCheck && verbose)
            {
                write(configuration->decorate(
                    sprintf("You need a minimum %s of %dto do that.\n",
                        attribute,
                        specificationData["limited by"]["attribute"][attribute]),
                    "missing prerequisites", "research", colorConfiguration));
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int checkRaceLimitor(mapping specificationData, object owner, 
    int verbose, string colorConfiguration, object configuration)
{
    int ret = 1;
 
    if (member(specificationData["limited by"], "race"))
    {
        string *races = pointerp(specificationData["limited by"]["race"]) ?
            specificationData["limited by"]["race"] :
            ({ specificationData["limited by"]["race"] });

        ret &&= owner && objectp(owner) &&
            function_exists("Race", owner) &&
            (member(races, owner->Race()) > -1);

        if (!ret && verbose)
        {
            write(configuration->decorate(
                sprintf("You are not of the %s race.\n",
                specificationData["limited by"]["opponent race"]),
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int checkGuildLimitor(mapping specificationData, object owner, 
    int verbose, string colorConfiguration, object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "guild"))
    {
        ret &&= owner && objectp(owner) &&
            function_exists("memberOfGuild", owner) &&
            owner->memberOfGuild(
                specificationData["limited by"]["guild"]);

        if (!ret && verbose)
        {
            write(configuration->decorate(
                sprintf("You are not in the %s guild.\n",
                specificationData["limited by"]["opponent guild"]),
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int checkFactionLimitor(mapping specificationData, 
    object owner, int verbose, string colorConfiguration, 
    object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "faction") && objectp(owner))
    {
        ret &&= function_exists("memberOfFaction", owner) &&
            owner->memberOfFaction(
                specificationData["limited by"]["faction"]);

        if (!ret && verbose)
        {
            object faction = getService("factions")->factionObject(
                specificationData["limited by"]["faction"]);

            if (faction)
            {
                write(configuration->decorate(
                    sprintf("You are not in the %s faction.\n",
                    faction->name()),
                    "missing prerequisites", "research", colorConfiguration));
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int checkQuestLimitor(mapping specificationData, object owner, 
    int verbose, string colorConfiguration, object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "quests") && objectp(owner))
    {
        int hasOneOf = 0;

        foreach(string quest in specificationData["limited by"]["quests"])
        {
            hasOneOf ||= owner->questIsCompleted(quest);
        }
        ret = pointerp(specificationData["limited by"]["quests"]) &&
            function_exists("questIsCompleted", owner) && hasOneOf;

        if (!ret && verbose)
        {
            string *questNames = ({});
            foreach(string quest in specificationData["limited by"]["quests"])
            {
                questNames += ({ 
                    getService("quests")->questSummary(quest)
                });
            }

            if (sizeof(questNames))
            {
                write(configuration->decorate(
                    sprintf("You have not completed any of the following "
                        "quests: %s.\n", implode(questNames, ", ")),
                    "missing prerequisites", "research", colorConfiguration));
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int checkResearchLimitor(mapping specificationData, 
    object owner, int verbose, string colorConfiguration, 
    object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "research") && objectp(owner))
    {
        int hasOneOf = 0;

        foreach(string research in specificationData["limited by"]["research"])
        {
            hasOneOf ||= owner->isResearched(research);
        }
        ret = pointerp(specificationData["limited by"]["research"]) &&
            function_exists("isResearched", owner) && hasOneOf;

        if (!ret && verbose)
        {
            string *researchNames = ({});
            foreach(string research in specificationData["limited by"]["research"])
            {
                object researchObj = getService("research")->researchObject(research);
                
                if (researchObj)
                {
                    researchNames += ({ researchObj->query("name") });
                }
            }

            if (sizeof(researchNames))
            {
                write(configuration->decorate(
                    sprintf("You have not completed any of the following "
                        "research: %s.\n", implode(researchNames, ", ")),
                    "missing prerequisites", "research", colorConfiguration));
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int checkTraitLimitor(mapping specificationData, object owner, 
    int verbose, string colorConfiguration, object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "traits") && objectp(owner))
    {
        int hasOneOf = 0;

        foreach(string trait in specificationData["limited by"]["traits"])
        {
            hasOneOf ||= owner->isTraitOf(trait);
        }
        ret = pointerp(specificationData["limited by"]["traits"]) &&
            function_exists("isTraitOf", owner) && hasOneOf;

        if (!ret && verbose)
        {
            string *traitNames = ({});
            foreach(string trait in specificationData["limited by"]["traits"])
            {
                object traitObj = getService("traits")->traitObject(trait);
                
                if (traitObj)
                {
                    traitNames += ({ traitObj->query("name") });
                }
            }

            if (sizeof(traitNames))
            {
                write(configuration->decorate(
                    sprintf("You do not have any of the following "
                        "traits: %s.\n", implode(traitNames, ", ")),
                    "missing prerequisites", "research", colorConfiguration));
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int checkResearchActiveLimitor(mapping specificationData, 
    object owner, int verbose, string colorConfiguration, 
    object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "research active") &&
        sizeof(specificationData["limited by"]["research active"]) &&
        objectp(owner))
    {
        int hasResearchActive = 0;

        foreach(string research in
            specificationData["limited by"]["research active"])
        {
            hasResearchActive ||= owner->sustainedResearchIsActive(research);
        }
        ret = function_exists("sustainedResearchIsActive", owner) &&
            hasResearchActive;

        if (!ret && verbose)
        {
            string *researchNames = ({});
            foreach(string research in
                specificationData["limited by"]["research active"])
            {
                object researchObj =
                    getService("research")->researchObject(research);
                researchNames += ({ researchObj->query("name") });
            }
            if (sizeof(researchNames))
            {
                write(configuration->decorate(
                    sprintf("You do not have any of the following research active: "
                        "%s.\n", implode(researchNames, ", ")),
                    "missing prerequisites", "research", colorConfiguration));
            }
        }
    }
    return ret;
}
