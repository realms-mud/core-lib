//*****************************************************************************
// Class: effectModifier
// File Name: effectModifier.c
//
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private string ModifierObject = "/lib/items/modifierObject.c";

private string *modifierTypes = ({ "skill", "attribute", "skill bonus", 
                                   "attribute bonus", "level", "research", "trait",
                                   "highest skill", "weapon damage", 
                                   "offhand damage", "deferred attack" });
private string *modifierFormulas = ({ "additive", "subtractive", "logarithmic",
                                      "multiplicative" });

/////////////////////////////////////////////////////////////////////////////
protected nomask int isNegativeAppliedEffect(string effect)
{
    return (member(({ "slow", "enfeebled", "poison", 
        "paralysis", "disease" }), effect) > -1);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int isValidModifier(mapping modifier)
{
    return (modifier && mappingp(modifier) && member(modifier, "type") &&
        (member(modifierTypes, modifier["type"]) > -1) && 
        member(modifier, "formula") && 
        (member(modifierFormulas, modifier["formula"]) > -1) && 
        member(modifier, "rate") && floatp(modifier["rate"]) &&
        member(modifier, "name") && stringp(modifier["name"]));
}

/////////////////////////////////////////////////////////////////////////////
protected float specialModifier()
{
    return 1.0;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int modifierValueByType(object initiator, mapping modifier)
{
    int ret = 0;

    if(isValidModifier(modifier))
    {    
        switch(modifier["type"])
        {
            case "highest skill":
            {
                mapping items = ([]);
                if (initiator->has("skills") &&
                    pointerp(modifier["skills"]) && sizeof(modifier["skills"]))
                {
                    foreach(string skill in modifier["skills"])
                    {
                        items[skill] = initiator->getSkill(skill) - 
                            (member(modifier, "base value") ? 
                                modifier["base value"] : 0);
                    }
                    ret = sort_array(m_values(items), (: $1 < $2 :))[0];
                }
                break;
            }
            case "skill":
            {
                if(initiator->has("skills"))
                {
                    ret = initiator->getSkill(modifier["name"]) -
                        (member(modifier, "base value") ? 
                        modifier["base value"] : 0);
                }
                break;
            }
            case "attribute":
            {
                if(initiator->has("attributes"))
                {
                    ret = initiator->attributeValue(modifier["name"]) -
                        (member(modifier, "base value") ? 
                        modifier["base value"] : 0);
                }
                break;
            }
            case "skill bonus":
            {
                if(initiator->has("skills"))
                {
                    ret = initiator->getSkillModifier(modifier["name"]) -
                        (member(modifier, "base value") ? 
                        modifier["base value"] : 0);
                }
                break;
            }
            case "attribute bonus":
            {
                if(initiator->has("attributes") && modifier["name"] &&
                    function_exists(sprintf("%sBonus", modifier["name"]), initiator))
                {
                    ret = call_other(initiator, sprintf("%sBonus", modifier["name"])) - 
                        (member(modifier, "base value") ? modifier["base value"] : 0);
                }
                break;
            }
            case "level":
            {
                if(initiator->has("guilds"))
                {
                    ret = initiator->guildLevel(modifier["name"]) -
                        (member(modifier, "base value") ? 
                        modifier["base value"] : 0);
                }
                break;
            }
            case "research":
            {
                if(initiator->has("research") && 
                   member(modifier, "research item") &&
                   initiator->isResearched(modifier["research item"]))
                {
                    ret = modifier["base value"];
                }
                break;
            }   
            case "trait":
            {
                if (initiator->has("traits") &&
                    member(modifier, "trait") &&
                    initiator->isTraitOf(modifier["trait"]))
                {
                    ret = modifier["base value"];
                }
                break;
            }
            case "deferred attack":
            {
                if (initiator->has("traits") &&
                    member(modifier, "trait") &&
                    initiator->isTraitOf(modifier["trait"]))
                {
                    int delayedRounds = initiator->roundsSinceLastAttack();
                    switch (delayedRounds)
                    {
                        case 1:
                        {
                            ret = 165;
                            break;
                        }
                        case 2:
                        {
                            ret = 190;
                            break;
                        }
                        case 3:
                        {
                            ret = 225;
                            break;
                        }
                        case 4:
                        {
                            ret = 240;
                            break;
                        }
                        case 5..10:
                        {
                            ret = 240 +
                                ((delayedRounds - 4) * 10);
                            break;
                        }
                        default:
                        {
                            ret = 100;
                            break;
                        }
                    }
                    initiator->resetRoundsSinceLastAttack();
                }
                break;
            }
            case "weapon damage":
            case "offhand damage":
            {
                object weapon = (modifier["type"] == "weapon damage") ?
                    initiator->equipmentInSlot("wielded primary") :
                    initiator->equipmentInSlot("wielded offhand");

                if (objectp(weapon) && pointerp(modifier["types"]) &&
                    (member(modifier["types"], weapon->query("weapon type")) > -1))
                {
                    string *damageTypes = 
                        getService("materials")->getMaterialDamageType(
                            weapon) +
                        m_indices(weapon->query("enchantments"));

                    damageTypes = m_indices(mkmapping(damageTypes));
                    ret -= modifier["base value"];

                    foreach(string damageType in damageTypes)
                    {
                        ret += initiator->calculateDamage(weapon, damageType, 1);
                    }
                }
                break;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int applyModifierToFormula(int initialValue, int valueToApply,
    string formula, float rate)
{
    int ret = 0;
    
    switch(formula)
    {
        case "additive":
        {
            ret = to_int(valueToApply * rate);
            break;
        }
        case "subtractive":
        {
            ret = valueToApply - to_int(valueToApply * rate);
            break;
        }
        case "logarithmic":
        {
            if((rate > 1.0) && (valueToApply > 0.0))
            {
                ret = to_int(initialValue * rate * 
                    log(valueToApply) / log(2.0)) - initialValue;
            }
            break;
        }
        case "multiplicative":
        {
            ret = to_int(initialValue * valueToApply * rate) - initialValue;
            break;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int applyModifiers(int value, object initiator,
    mapping *modifiers)
{
    int ret = value;
    
    if(pointerp(modifiers) && sizeof(modifiers) && initiator &&
       function_exists("has", initiator))
    {
        foreach(mapping modifier in modifiers)
        {
            int modifierTypeValue = modifierValueByType(initiator, modifier);

            if (modifierTypeValue > 0)
            {
                ret += applyModifierToFormula(value, modifierTypeValue,
                    modifier["formula"], modifier["rate"]);
            }
        }
    }
    return to_int(ret * specialModifier());
}

/////////////////////////////////////////////////////////////////////////////
protected void deactivateModifierObject(object modifierToDeactivate)
{
    if (modifierToDeactivate && objectp(modifierToDeactivate))
    {
        modifierToDeactivate->unregisterModifierFromTargetList();
        destruct(modifierToDeactivate);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected int ritualMultiplier(string type, int value)
{
    return value;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask object getModifierObject(object owner, mapping specificationData)
{
    object ret = clone_object(ModifierObject);

    if (ret)
    {
        string fullyQualifiedName = program_name(this_object()) + "#" + owner->RealName();
        object previousModifier = owner->registeredInventoryObject(fullyQualifiedName);
        if (previousModifier)
        {
            deactivateModifierObject(previousModifier);
        }

        ret->set("fully qualified name", fullyQualifiedName);
        string *listOfSpecifications = m_indices(specificationData);
        object bonusService = getService("bonuses");
        if (bonusService && listOfSpecifications)
        {
            string bonusToCheck;
            foreach(string specification in listOfSpecifications)
            {
                if (sscanf(specification, "bonus %s", bonusToCheck) &&
                    bonusService->isValidBonus(bonusToCheck))
                {
                    ret->set(specification,
                        applyModifiers(ritualMultiplier(specification,
                            specificationData[specification]), owner, specificationData["modifiers"]));
                }
                else if (sscanf(specification, "apply %s", bonusToCheck) &&
                    bonusService->isValidBonus(bonusToCheck))
                {
                    ret->set(bonusToCheck,
                        applyModifiers(ritualMultiplier(bonusToCheck,
                            specificationData[specification]), owner, specificationData["modifiers"]));
                    if(owner->isNegativeCombatModifier(bonusToCheck))
                    {
                        ret->set("check kill list", 1);
                    }
                }
                else if (sscanf(specification, "penalty to %s", bonusToCheck) &&
                    bonusService->isValidBonus(bonusToCheck))
                {
                    ret->set(specification,
                        applyModifiers(ritualMultiplier(specification,
                            specificationData[specification]), owner, specificationData["modifiers"]));
                    ret->set("check kill list", 1);
                }
            }
        }
    }
    return ret;
}
