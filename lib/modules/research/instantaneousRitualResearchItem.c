//*****************************************************************************
// Class: instantaneousRitualResearchItem
// File Name: instantaneousRitualResearchItem.c
//
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/research/ritualResearchItem.c";
virtual inherit "/lib/modules/research/instantaneousEffect.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask int addSpecification(string type, mixed value)
{
    int ret = addInstantaneousSpecification(type, value);
    if(!ret)
    {
        ret = "ritualResearchItem"::addSpecification(type, value);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected int ritualMultiplier(string type, int value)
{
    return value;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int applyBeneficialEffect(object initiator, object target)
{
    int ret = 0;
    if(member(specificationData, "increase hit points"))
    {
        ret ||= target->hitPoints(ritualMultiplier("increase hit points",
            applyFormula(initiator, "increase hit points")));
    }
    if(member(specificationData, "increase spell points"))
    {
        ret ||= target->spellPoints(ritualMultiplier("increase spell points",
            applyFormula(initiator, "increase spell points")));
    }
    if(member(specificationData, "increase stamina points"))
    {
        ret ||= 
            target->staminaPoints(ritualMultiplier("increase stamina points",
            applyFormula(initiator, "increase stamina points")));
    }
    if(member(specificationData, "decrease intoxication"))
    {
        ret ||= target->addIntoxication(
            -ritualMultiplier("decrease intoxication",
            applyFormula(initiator, "decrease intoxication")));
    }
    if(member(specificationData, "decrease druggedness"))
    {
        ret ||= target->addDrugged(-ritualMultiplier("decrease druggedness",
            applyFormula(initiator, "decrease druggedness")));
    }
    if(member(specificationData, "decrease soaked"))
    {
        ret ||= target->addSoaked(-ritualMultiplier("decrease soaked",
            applyFormula(initiator, "decrease soaked")));
    }
    if(member(specificationData, "decrease stuffed"))
    {
        ret ||= target->addStuffed(-ritualMultiplier("decrease stuffed",
            applyFormula(initiator, "decrease stuffed")));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int applyEffect(object initiator, object target)
{
    int ret = 0;
    if(target && objectp(target) && member(specificationData, "damage type") && 
        ((target->onKillList() && !target->isRealizationOf("player")) ||
        (target->isRealizationOf("player") && initiator->isRealizationOf("player") &&
        target->onKillList() && initiator->onKillList())))
    {
        if(member(specificationData, "damage spell points"))
        {
            target->spellPoints(-ritualMultiplier("damage spell points",
                applyFormula(initiator, "damage spell points")));
            ret = 1;
        }
        if(member(specificationData, "damage stamina points"))
        {
            target->staminaPoints(-ritualMultiplier("damage stamina points",
                applyFormula(initiator, "damage stamina points")));
            ret = 1;
        }
        if(member(specificationData, "increase intoxication"))
        {
            target->addIntoxication(ritualMultiplier("increase intoxication",
                applyFormula(initiator, "increase intoxication")));
            ret = 1;
        }
        if(member(specificationData, "increase druggedness"))
        {
            target->addDrugged(ritualMultiplier("increase druggedness",
                applyFormula(initiator, "increase druggedness")));
            ret = 1;
        }
        if(member(specificationData, "increase soaked"))
        {
            target->addSoaked(ritualMultiplier("increase soaked",
                applyFormula(initiator, "increase soaked")));
            ret = 1;
        }
        if(member(specificationData, "increase stuffed"))
        {
            target->addStuffed(ritualMultiplier("increase stuffed",
                applyFormula(initiator, "increase stuffed")));
            ret = 1;
        }
        
        if(member(specificationData, "damage hit points"))
        {
            target->hit(ritualMultiplier("damage hit points",
                applyFormula(initiator, "damage hit points")), 
                specificationData["damage type"], initiator);
            ret = 1;
        }

        if (ret)
        {
            // Trigger combat
            target->registerAttacker(initiator);
            initiator->registerAttacker(target);
        }
    }
    
    ret ||= applyBeneficialEffect(initiator, target);
    return ret;
}


