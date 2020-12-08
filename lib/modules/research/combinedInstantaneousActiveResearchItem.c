//*****************************************************************************
// Class: instantaneousActiveResearchItem
// File Name: instantaneousActiveResearchItem.c
//
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
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
        ret = "activeResearchItem"::addSpecification(type, value);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int applyBeneficialEffect(object initiator, 
    string *combo)
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
    string *combo)
{
    int ret = 0;

    if(target && objectp(target) && member(specificationData, "damage type") && 
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
