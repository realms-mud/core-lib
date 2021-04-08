//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/research/activeResearchItem.c";
virtual inherit "/lib/modules/research/combinedInstantaneousEffect.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask int addSpecification(string type, mixed value)
{
    int ret = addInstantaneousSpecification(type, value);
    if(!ret)
    {
        ret = activeResearchItem::addSpecification(type, value);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int applyBeneficialEffect(object initiator, 
    object *combo)
{
    int ret = 0;
    if(member(specificationData, "increase hit points"))
    {
        ret ||= initiator->hitPoints(applyAllFormulas(combo,
            initiator, "increase hit points"));
    }
    if(member(specificationData, "increase spell points"))
    {
        ret ||= initiator->spellPoints(applyAllFormulas(combo,
            initiator,"increase spell points"));
    }
    if(member(specificationData, "increase stamina points"))
    {
        ret ||= initiator->staminaPoints(applyAllFormulas(combo,
            initiator, "increase stamina points"));
    }
    if(member(specificationData, "decrease intoxication"))
    {
        ret ||= initiator->addIntoxication(-applyAllFormulas(combo,
            initiator, "decrease intoxication"));
    }
    if(member(specificationData, "decrease druggedness"))
    {
        ret ||= initiator->addDrugged(-applyAllFormulas(combo,
            initiator, "decrease druggedness"));
    }
    if(member(specificationData, "decrease soaked"))
    {
        ret ||= initiator->addSoaked(-applyAllFormulas(combo,
            initiator, "decrease soaked"));
    }
    if(member(specificationData, "decrease stuffed"))
    {
        ret ||= initiator->addStuffed(-applyAllFormulas(combo,
            initiator, "decrease stuffed"));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int applyEffect(object initiator, object target,
    object *combo)
{
    int ret = 0;

    if(target && objectp(target) && (target != initiator) &&
        member(specificationData, "damage type") && 
        ((target->onKillList() && !target->isRealizationOf("player")) || 
        (target->isRealizationOf("player") && initiator->isRealizationOf("player") &&
        target->onKillList() && initiator->onKillList())))
    {
        if(member(specificationData, "damage spell points"))
        {
            target->spellPoints(-applyAllFormulas(combo,
                initiator, "damage spell points"));
            ret = 1;
        }
        if(member(specificationData, "damage stamina points"))
        {
            target->staminaPoints(-applyAllFormulas(combo,
                initiator, "damage stamina points"));
            ret = 1;
        }
        if(member(specificationData, "increase intoxication"))
        {
            target->addIntoxication(applyAllFormulas(combo,
                initiator, "increase intoxication"));
            ret = 1;
        }
        if(member(specificationData, "increase druggedness"))
        {
            target->addDrugged(applyAllFormulas(combo,
                initiator, "increase druggedness"));
            ret = 1;
        }
        if(member(specificationData, "increase soaked"))
        {
            target->addSoaked(applyAllFormulas(combo,
                initiator, "increase soaked"));
            ret = 1;
        }
        if(member(specificationData, "increase stuffed"))
        {
            target->addStuffed(applyAllFormulas(combo,
                initiator, "increase stuffed"));
            ret = 1;
        }    
        if(member(specificationData, "damage hit points"))
        {
            target->hit(applyAllFormulas(combo,
                initiator, "damage hit points"),
                specificationData["damage type"], initiator);
            ret = 1;
        }

        if(ret && target)
        {
            // Trigger combat
            target->registerAttacker(initiator);
            initiator->registerAttacker(target);
        }
    }
    
    ret ||= applyBeneficialEffect(initiator, combo);
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected mapping getUsageCosts(string command, object initiator)
{
    object *combo = getCombinationList(command, initiator, 1);

    mapping costs = researchItem::getUsageCosts(command, initiator);

    if (sizeof(combo))
    {
        foreach(object item in combo)
        {
            mapping costData = item->getUsageCosts(command, initiator);
            costs["hit point cost"] += costData["hit point cost"];
            costs["spell point cost"] += costData["spell point cost"];
            costs["stamina point cost"] += costData["stamina point cost"];
        }
    }

    return costs + ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected string displayRelatedResearchEffects(string colorConfiguration,
    object configuration)
{
    string ret = "";

    mapping rules = query("combination rules");
    if (mappingp(rules) && sizeof(rules))
    {
        object dictionary = getDictionary("research");
        foreach(string ruleType in m_indices(rules))
        {
            ret += configuration->decorate(sprintf("%-15s : ", "Combination Rule"),
                "field header", "research", colorConfiguration) +
                configuration->decorate(capitalize(ruleType) + ":\n",
                    "field data", "research", colorConfiguration);

            if (sizeof(rules[ruleType]))
            {
                foreach(string item in rules[ruleType])
                {
                    object researchObj = dictionary->researchObject(item);
                    if (researchObj && researchObj->query("usage summary"))
                    {
                        ret += sprintf("%-18s", "") +
                            configuration->decorate(
                                lower_case(researchObj->query("name")) + ": ",
                                "field data", "research", colorConfiguration) +
                            configuration->decorate(
                                capitalize(researchObj->query("usage summary")) + "\n",
                                "formula", "research", colorConfiguration);
                    }
                }
            }
        }
    }

    if (query("maximum combination chain"))
    {
        ret += configuration->decorate(sprintf("%-15s : ", "Max Combo Size"),
                "field header", "research", colorConfiguration) +
            configuration->decorate(sprintf("%d\n", 
                query("maximum combination chain")),
                "field data", "research", colorConfiguration);
    }

    return ret;
}
