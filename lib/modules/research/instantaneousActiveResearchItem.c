//*****************************************************************************
// Class: instantaneousActiveResearchItem
// File Name: instantaneousActiveResearchItem.c
//
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/research/activeResearchItem.c";
virtual inherit "/lib/modules/research/instantaneousEffect.c";

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
protected nomask int applyBeneficialEffect(object initiator, object target)
{
    int ret = 0;
    if(member(specificationData, "increase hit points"))
    {
        ret = 1;
        target->hitPoints(applyFormula(initiator, 
            "increase hit points"));
    }
    if(member(specificationData, "increase spell points"))
    {
        ret = 1;
        target->spellPoints(applyFormula(initiator,
            "increase spell points"));
    }
    if(member(specificationData, "increase stamina points"))
    {
        ret = 1;
        target->staminaPoints(applyFormula(initiator,
            "increase stamina points"));
    }
    if(member(specificationData, "decrease intoxication"))
    {
        ret = 1;
        target->addIntoxication(-applyFormula(initiator,
            "decrease intoxication"));
    }
    if(member(specificationData, "decrease druggedness"))
    {
        ret = 1;
        target->addDrugged(-applyFormula(initiator,
            "decrease druggedness"));
    }
    if(member(specificationData, "decrease soaked"))
    {
        ret = 1;
        target->addSoaked(-applyFormula(initiator, "decrease soaked"));
    }
    if(member(specificationData, "decrease stuffed"))
    {
        ret = 1;
        target->addStuffed(-applyFormula(initiator,
            "decrease stuffed"));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int applyEffect(object initiator, object target)
{
    int ret = 0;

    if(target && objectp(target) && 
        (member(specificationData, "damage type") ||
            member(specificationData, "supercede targets")) &&
        ((target->onKillList() && !target->isRealizationOf("player")) || 
        (target->isRealizationOf("player") && initiator->isRealizationOf("player") &&
        target->onKillList() && initiator->onKillList()) ||
        target->canAttack(initiator)))
    {
        if(member(specificationData, "damage spell points"))
        {
            target->spellPoints(-applyFormula(initiator, 
                "damage spell points"));
            ret = 1;
        }
        if(member(specificationData, "damage stamina points"))
        {
            target->staminaPoints(-applyFormula(initiator, 
                "damage stamina points"));
            ret = 1;
        }
        if(member(specificationData, "increase intoxication"))
        {
            target->addIntoxication(applyFormula(initiator,
                "increase intoxication"));
            ret = 1;
        }
        if(member(specificationData, "increase druggedness"))
        {
            target->addDrugged(applyFormula(initiator, 
                "increase druggedness"));
            ret = 1;
        }
        if(member(specificationData, "increase soaked"))
        {
            target->addSoaked(applyFormula(initiator, "increase soaked"));
            ret = 1;
        }
        if(member(specificationData, "increase stuffed"))
        {
            target->addStuffed(applyFormula(initiator, "increase stuffed"));
            ret = 1;
        }  
        if (member(specificationData, "siphon spell points"))
        {
            int amount = applyFormula(initiator, "siphon spell points");
            int addBack = amount / 4;

            target->spellPoints(-amount);
            initiator->hitPoints(addBack);
            initiator->spellPoints(addBack);
            initiator->staminaPoints(addBack);
            ret = 1;
        }
        if (member(specificationData, "siphon stamina points"))
        {
            int amount = applyFormula(initiator, "siphon stamina points");
            int addBack = amount / 4;

            target->staminaPoints(-amount);
            initiator->hitPoints(addBack);
            initiator->spellPoints(addBack);
            initiator->staminaPoints(addBack);
            ret = 1;
        }
        if(member(specificationData, "damage hit points"))
        {
            target->hit(applyFormula(initiator, "damage hit points"), 
                specificationData["damage type"], initiator);
            ret = 1;
        }
        if (target && member(specificationData, "siphon hit points"))
        {
            int amount = applyFormula(initiator, "siphon hit points");
            int addBack = amount / 4;

            target->hit(amount, specificationData["damage type"], initiator);
            initiator->hitPoints(addBack);
            initiator->spellPoints(addBack);
            initiator->staminaPoints(addBack);
            ret = 1;
        }
        if(ret && target)
        {
            // Trigger combat
            target->registerAttacker(initiator);
            initiator->registerAttacker(target);
        }
        else if (target &&
            member(specificationData, "supercede targets"))
        {
            ret = 1;
            initiator->registerAttacker(target);
            target->supercedeAttackers(initiator);
        }
    }
    
    ret ||= applyBeneficialEffect(initiator, target);
    return ret;
}
