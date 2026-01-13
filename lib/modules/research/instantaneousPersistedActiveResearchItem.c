//*****************************************************************************
// Class: instantaneousPersistedActiveResearchItem
// File Name: instantaneousPersistedActiveResearchItem.c
//
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/research/activeResearchItem.c";
virtual inherit "/lib/modules/research/effectModifier.c";
virtual inherit "/lib/modules/research/instantaneousEffect.c";

/////////////////////////////////////////////////////////////////////////////
private int canApplyNegativeEffect(object initiator, object target)
{
    return target && objectp(target) &&
        (member(specificationData, "damage type") ||
            member(specificationData, "supercede targets")) &&
        ((target->onKillList() && !target->isRealizationOf("player")) ||
            (target->isRealizationOf("player") && initiator->isRealizationOf("player") &&
                target->onKillList() && initiator->onKillList()) ||
            target->canAttack(initiator));
}

/////////////////////////////////////////////////////////////////////////////
protected int addSpecification(string type, mixed value)
{
    int ret = 0;
    string bonusToCheck;

    if (addInstantaneousSpecification(type, value))
    {
        ret = 1;
    }
    else if (!ret && (type == "remove modifier"))
    {
        if (stringp(value) || (pointerp(value) && sizeof(value) &&
            stringp(value[0])))
        {
            specificationData[type] = stringp(value) ? ({ value }) : value;
            ret = 1;
        }
        else
        {
            raise_error("ERROR - instantaneousActiveResearchItem: "
                "the 'remove modifier' specification must be a string "
                "or an array of strings.\n");
        }
    }
    else if(sscanf(type, "bonus %s", bonusToCheck) ||
            sscanf(type, "penalty to %s", bonusToCheck) ||
            sscanf(type, "apply %s", bonusToCheck))
    {
        object bonusService = getService("bonuses");
        if(bonusService &&
            bonusService->isValidBonusModifier(bonusToCheck, value))
        {
            specificationData[type] = value;

            if (sizeof(regexp(({ type }), "penalty to")) ||
                isNegativeAppliedEffect(bonusToCheck))
            {
                specificationData["is negative effect"] = 1;
            }
            else
            {
                specificationData["is beneficial"] = 1;
            }
            ret = 1;
        }
        else if(bonusService)
        {
            raise_error(sprintf("ERROR - instantaneousPersistedActiveResearchItem: the '%s'"
                " specification must be a valid modifier as defined in %s\n",
                type, program_name(getService("bonuses"))));
        }
    }
    else if (member(({"trait", "negative trait"}), type) > -1)
    {
        object traitsService = getService("traits");

        if (stringp(value) && traitsService &&
            traitsService->isValidPersistedTrait(value))
        {
            specificationData[type] = value;
            ret = 1;
        }
        else
        {
            raise_error("ERROR - instantaneousPersistedActiveResearchItem: the trait "
                "specification must be a valid effect-based trait.\n");
        }
    }
    else if(type == "duration")
    {
        if(intp(value) && (value > 0))
        {
            specificationData[type] = value;
            ret = 1;
        }
        else
        {
            raise_error("ERROR - instantaneousPersistedActiveResearchItem: the duration "
                "specification must be a positive integer.\n");
        }
    }
    else if(type == "modifiers")
    {
        if(value && pointerp(value) && sizeof(value) && mappingp(value[0]))
        {
            int validModifier = 1;
            foreach(mapping modifierValue in value)
            {
                validModifier &&= isValidModifier(modifierValue);
            }
            if(validModifier)
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error(sprintf("ERROR - instantaneousPersistedActiveResearchItem: "
                    "the '%s' specification must be a properly formatted "
                    "modifier.\n" , type));
            }
        }
        else
        {
            raise_error(sprintf("ERROR - instantaneousPersistedActiveResearchItem: "
                "the '%s' specification must be a properly formatted "
                "modifier.\n" , type));
        }
    }
    else if ((type == "supercede targets") &&
        (member(specificationData, "negative trait") ||
            member(specificationData, "is negative effect")))
    {
        specificationData[type] = value;
        ret = 1;
    }
    else
    {
        ret = activeResearchItem::addSpecification(type, value);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected int applyPersistedEffects(object initiator, object target)
{
    int ret = 0;

    // Apply beneficial trait
    if (target && member(specificationData, "trait") && target->has("traits"))
    {
        ret = target->addTrait(specificationData["trait"]) || ret;
    }
    // Apply negative trait only if allowed
    if (target && member(specificationData, "negative trait") && target->has("traits") &&
        canApplyNegativeEffect(initiator, target))
    {
        ret = target->addTrait(specificationData["negative trait"]) || ret;
    }

    // Apply modifiers with duration
    if (target && member(specificationData, "duration"))
    {
        if ((!member(specificationData, "is negative effect") 
            && (!canApplyNegativeEffect(initiator, target) ||
                (initiator == target))) ||
            (member(specificationData, "is negative effect") &&
                canApplyNegativeEffect(initiator, target)))
        {
            object modifier = getModifierObject(initiator, specificationData);
            if (modifier)
            {
                modifier->registerModifierWithTargetList(({ target }));
                call_out("deactivateModifierObject", specificationData["duration"], modifier);
                ret = 1;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected int applyBeneficialEffect(object initiator, object target,
    mapping effectData)
{
    int ret = 0;

    if (member(effectData, "increase hit points"))
    {
        ret = 1;
        target->hitPoints(applyFormula(initiator, "increase hit points", effectData));
    }
    if (member(effectData, "increase spell points"))
    {
        ret = 1;
        target->spellPoints(applyFormula(initiator, "increase spell points", effectData));
    }
    if (member(effectData, "increase stamina points"))
    {
        ret = 1;
        target->staminaPoints(applyFormula(initiator, "increase stamina points", effectData));
    }
    if (member(effectData, "decrease intoxication"))
    {
        ret = 1;
        target->addIntoxication(-applyFormula(initiator, "decrease intoxication", effectData));
    }
    if (member(effectData, "decrease druggedness"))
    {
        ret = 1;
        target->addDrugged(-applyFormula(initiator, "decrease druggedness", effectData));
    }
    if (member(effectData, "decrease soaked"))
    {
        ret = 1;
        target->addSoaked(-applyFormula(initiator, "decrease soaked", effectData));
    }
    if (member(effectData, "decrease stuffed"))
    {
        ret = 1;
        target->addStuffed(-applyFormula(initiator, "decrease stuffed", effectData));
    }
    if (member(effectData, "remove modifier"))
    {
        foreach(string modifier in effectData["remove modifier"])
        {
            ret = target->unregisterObjectsOfType(modifier) || ret;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected int applyEffect(object initiator, object target,
    mapping effectData)
{
    int ret = 0;

    int isSelf = (initiator == target);
    int isHostile = canApplyNegativeEffect(initiator, target);

    // Hostile effects (never to self)
    if (!isSelf && isHostile)
    {
        if(member(effectData, "damage spell points"))
        {
            target->spellPoints(-applyFormula(initiator, "damage spell points", effectData));
            ret = 1;
        }
        if(member(effectData, "damage stamina points"))
        {
            target->staminaPoints(-applyFormula(initiator, "damage stamina points", effectData));
            ret = 1;
        }
        if(member(effectData, "increase intoxication"))
        {
            target->addIntoxication(applyFormula(initiator, "increase intoxication", effectData));
            ret = 1;
        }
        if(member(effectData, "increase druggedness"))
        {
            target->addDrugged(applyFormula(initiator, "increase druggedness", effectData));
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

    ret = applyBeneficialEffect(initiator, target, effectData) || ret;
    ret = applyPersistedEffects(initiator, target) || ret;

    return ret;
}
