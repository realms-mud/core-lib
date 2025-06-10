//*****************************************************************************
// Class: instantaneousPersistedActiveResearchItem
// File Name: instantaneousPersistedActiveResearchItem.c
//
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    else if(sscanf(type, "bonus %s", bonusToCheck) ||
            sscanf(type, "penalty to %s", bonusToCheck) ||
            sscanf(type, "apply %s", bonusToCheck))
    {
        object bonusDictionary = getDictionary("bonuses");
        if(bonusDictionary &&
            bonusDictionary->isValidBonusModifier(bonusToCheck, value))
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
        else if(bonusDictionary)
        {
            raise_error(sprintf("ERROR - instantaneousPersistedActiveResearchItem: the '%s'"
                " specification must be a valid modifier as defined in %s\n",
                type, program_name(getDictionary("bonuses"))));
        }
    }
    else if (member(({"trait", "negative trait"}), type) > -1)
    {
        object traitsDictionary = getDictionary("traits");

        if (stringp(value) && traitsDictionary &&
            traitsDictionary->isValidPersistedTrait(value))
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
protected int applyBeneficialEffect(object initiator, object target)
{
    int ret = 0;

    if (member(specificationData, "increase hit points"))
    {
        ret = 1;
        target->hitPoints(applyFormula(initiator, "increase hit points"));
    }
    if (member(specificationData, "increase spell points"))
    {
        ret = 1;
        target->spellPoints(applyFormula(initiator, "increase spell points"));
    }
    if (member(specificationData, "increase stamina points"))
    {
        ret = 1;
        target->staminaPoints(applyFormula(initiator, "increase stamina points"));
    }
    if (member(specificationData, "decrease intoxication"))
    {
        ret = 1;
        target->addIntoxication(-applyFormula(initiator, "decrease intoxication"));
    }
    if (member(specificationData, "decrease druggedness"))
    {
        ret = 1;
        target->addDrugged(-applyFormula(initiator, "decrease druggedness"));
    }
    if (member(specificationData, "decrease soaked"))
    {
        ret = 1;
        target->addSoaked(-applyFormula(initiator, "decrease soaked"));
    }
    if (member(specificationData, "decrease stuffed"))
    {
        ret = 1;
        target->addStuffed(-applyFormula(initiator, "decrease stuffed"));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected int applyEffect(object initiator, object target)
{
    int ret = 0;

    int isSelf = (initiator == target);
    int isHostile = canApplyNegativeEffect(initiator, target);

    // Hostile effects (never to self)
    if (!isSelf && isHostile)
    {
        if(member(specificationData, "damage spell points"))
        {
            target->spellPoints(-applyFormula(initiator, "damage spell points"));
            ret = 1;
        }
        if(member(specificationData, "damage stamina points"))
        {
            target->staminaPoints(-applyFormula(initiator, "damage stamina points"));
            ret = 1;
        }
        if(member(specificationData, "increase intoxication"))
        {
            target->addIntoxication(applyFormula(initiator, "increase intoxication"));
            ret = 1;
        }
        if(member(specificationData, "increase druggedness"))
        {
            target->addDrugged(applyFormula(initiator, "increase druggedness"));
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

    ret = applyBeneficialEffect(initiator, target) || ret;
    ret = applyPersistedEffects(initiator, target) || ret;

    return ret;
}
