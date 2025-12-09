//*****************************************************************************
// Class: instantaneousActiveResearchItem
// File Name: instantaneousActiveResearchItem.c
//
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/research/activeResearchItem.c";
virtual inherit "/lib/modules/research/instantaneousEffect.c";

/////////////////////////////////////////////////////////////////////////////
protected int addAdditionalSpecification(string type, mixed value)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int addSpecification(string type, mixed value)
{
    int ret = addInstantaneousSpecification(type, value) ||
        addAdditionalSpecification(type, value);

    if(!ret)
    {
        ret = activeResearchItem::addSpecification(type, value);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int applyBeneficialEffect(object initiator, object target,
    mapping effectData)
{
    int ret = 0;
    if(member(effectData, "increase hit points"))
    {
        ret = 1;
        target->hitPoints(applyFormula(initiator, 
            "increase hit points", effectData));
    }
    if(member(effectData, "increase spell points"))
    {
        ret = 1;
        target->spellPoints(applyFormula(initiator,
            "increase spell points", effectData));
    }
    if(member(effectData, "increase stamina points"))
    {
        ret = 1;
        target->staminaPoints(applyFormula(initiator,
            "increase stamina points", effectData));
    }
    if(member(effectData, "decrease intoxication"))
    {
        ret = 1;
        target->addIntoxication(-applyFormula(initiator,
            "decrease intoxication", effectData));
    }
    if(member(effectData, "decrease druggedness"))
    {
        ret = 1;
        target->addDrugged(-applyFormula(initiator,
            "decrease druggedness", effectData));
    }
    if(member(effectData, "decrease soaked"))
    {
        ret = 1;
        target->addSoaked(-applyFormula(initiator, "decrease soaked", effectData));
    }
    if(member(effectData, "decrease stuffed"))
    {
        ret = 1;
        target->addStuffed(-applyFormula(initiator,
            "decrease stuffed", effectData));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int applyEffect(object initiator, object target,
    mapping effectData)
{
    int ret = 0;

    if(target && objectp(target) && 
        (member(effectData, "damage type") ||
            member(effectData, "supercede targets")) &&
        ((target->onKillList() && !target->isRealizationOf("player")) || 
        (target->isRealizationOf("player") && initiator->isRealizationOf("player") &&
        target->onKillList() && initiator->onKillList()) ||
        target->canAttack(initiator)))
    {
        if(member(effectData, "damage spell points"))
        {
            target->spellPoints(-applyFormula(initiator, 
                "damage spell points", effectData));
            ret = 1;
        }
        if(member(effectData, "damage stamina points"))
        {
            target->staminaPoints(-applyFormula(initiator, 
                "damage stamina points", effectData));
            ret = 1;
        }
        if(member(effectData, "increase intoxication"))
        {
            target->addIntoxication(applyFormula(initiator,
                "increase intoxication", effectData));
            ret = 1;
        }
        if(member(effectData, "increase druggedness"))
        {
            target->addDrugged(applyFormula(initiator, 
                "increase druggedness", effectData));
            ret = 1;
        }
        if(member(effectData, "increase soaked"))
        {
            target->addSoaked(applyFormula(initiator, "increase soaked", effectData));
            ret = 1;
        }
        if(member(effectData, "increase stuffed"))
        {
            target->addStuffed(applyFormula(initiator, "increase stuffed", effectData));
            ret = 1;
        }  
        if (member(effectData, "siphon spell points"))
        {
            int amount = applyFormula(initiator, "siphon spell points", effectData);
            int addBack = amount / 4;

            target->spellPoints(-amount);
            initiator->hitPoints(addBack);
            initiator->spellPoints(addBack);
            initiator->staminaPoints(addBack);
            ret = 1;
        }
        if (member(effectData, "siphon stamina points"))
        {
            int amount = applyFormula(initiator, "siphon stamina points", effectData);
            int addBack = amount / 4;

            target->staminaPoints(-amount);
            initiator->hitPoints(addBack);
            initiator->spellPoints(addBack);
            initiator->staminaPoints(addBack);
            ret = 1;
        }
        if(member(effectData, "damage hit points"))
        {
            target->hit(applyFormula(initiator, "damage hit points", effectData), 
                effectData["damage type"], initiator);
            ret = 1;
        }
        if (target && member(effectData, "siphon hit points"))
        {
            int amount = applyFormula(initiator, "siphon hit points", effectData);
            int addBack = amount / 4;

            target->hit(amount, effectData["damage type"], initiator);
            initiator->hitPoints(addBack);
            initiator->spellPoints(addBack);
            initiator->staminaPoints(addBack);
            ret = 1;
        }
        if(ret && target)
        {
            target->registerAttacker(initiator);
            initiator->registerAttacker(target);
        }
        else if (target &&
            member(effectData, "supercede targets"))
        {
            ret = 1;
            initiator->registerAttacker(target);
            target->supercedeAttackers(initiator);
        }
    }
    
    ret ||= applyBeneficialEffect(initiator, target, effectData);
    return ret;
}
