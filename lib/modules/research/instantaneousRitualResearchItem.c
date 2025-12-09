//*****************************************************************************
// Class: instantaneousRitualResearchItem
// File Name: instantaneousRitualResearchItem.c
//
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
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
        ret = ritualResearchItem::addSpecification(type, value);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected int ritualMultiplier(string type, int value)
{
    return value;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int applyBeneficialEffect(object initiator, object target,
    mapping effectData)
{
    int ret = 0;
    if(member(effectData, "increase hit points"))
    {
        ret ||= target->hitPoints(ritualMultiplier("increase hit points",
            applyFormula(initiator, "increase hit points", effectData)));
    }
    if(member(effectData, "increase spell points"))
    {
        ret ||= target->spellPoints(ritualMultiplier("increase spell points",
            applyFormula(initiator, "increase spell points", effectData)));
    }
    if(member(effectData, "increase stamina points"))
    {
        ret ||= 
            target->staminaPoints(ritualMultiplier("increase stamina points",
            applyFormula(initiator, "increase stamina points", effectData)));
    }
    if(member(effectData, "decrease intoxication"))
    {
        ret ||= target->addIntoxication(
            -ritualMultiplier("decrease intoxication",
            applyFormula(initiator, "decrease intoxication", effectData)));
    }
    if(member(effectData, "decrease druggedness"))
    {
        ret ||= target->addDrugged(-ritualMultiplier("decrease druggedness",
            applyFormula(initiator, "decrease druggedness", effectData)));
    }
    if(member(effectData, "decrease soaked"))
    {
        ret ||= target->addSoaked(-ritualMultiplier("decrease soaked",
            applyFormula(initiator, "decrease soaked", effectData)));
    }
    if(member(effectData, "decrease stuffed"))
    {
        ret ||= target->addStuffed(-ritualMultiplier("decrease stuffed",
            applyFormula(initiator, "decrease stuffed", effectData)));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int applyEffect(object initiator, object target,
    mapping effectData)
{
    int ret = 0;
    if(target && objectp(target) && member(effectData, "damage type") && 
        ((target->onKillList() && !target->isRealizationOf("player")) ||
        (target->isRealizationOf("player") && initiator->isRealizationOf("player") &&
        target->onKillList() && initiator->onKillList())))
    {
        if(member(effectData, "damage spell points"))
        {
            target->spellPoints(-ritualMultiplier("damage spell points",
                applyFormula(initiator, "damage spell points", effectData)));
            ret = 1;
        }
        if(member(effectData, "damage stamina points"))
        {
            target->staminaPoints(-ritualMultiplier("damage stamina points",
                applyFormula(initiator, "damage stamina points", effectData)));
            ret = 1;
        }
        if(member(effectData, "increase intoxication"))
        {
            target->addIntoxication(ritualMultiplier("increase intoxication",
                applyFormula(initiator, "increase intoxication", effectData)));
            ret = 1;
        }
        if(member(effectData, "increase druggedness"))
        {
            target->addDrugged(ritualMultiplier("increase druggedness",
                applyFormula(initiator, "increase druggedness", effectData)));
            ret = 1;
        }
        if(member(effectData, "increase soaked"))
        {
            target->addSoaked(ritualMultiplier("increase soaked",
                applyFormula(initiator, "increase soaked", effectData)));
            ret = 1;
        }
        if(member(effectData, "increase stuffed"))
        {
            target->addStuffed(ritualMultiplier("increase stuffed",
                applyFormula(initiator, "increase stuffed", effectData)));
            ret = 1;
        }
        
        if(member(effectData, "damage hit points"))
        {
            target->hit(ritualMultiplier("damage hit points",
                applyFormula(initiator, "damage hit points", effectData)), 
                effectData["damage type"], initiator);
            ret = 1;
        }

        if (ret)
        {
            target->registerAttacker(initiator);
            initiator->registerAttacker(target);
        }
    }
    
    ret ||= applyBeneficialEffect(initiator, target, effectData);
    return ret;
}
