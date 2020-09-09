//*****************************************************************************
// Class: effectModifier
// File Name: effectModifier.c
//
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private string ModifierObject = "/lib/items/modifierObject.c";

private string *modifierTypes = ({ "skill", "attribute", "skill bonus", 
                                   "attribute bonus", "level", "research", "trait" });
private string *modifierFormulas = ({ "additive", "subtractive", "logarithmic",
                                      "multiplicative" });
                                      
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

            ret += applyModifierToFormula(value, modifierTypeValue, 
                modifier["formula"], modifier["rate"]);          
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
protected nomask object getModifierObject(object owner, mapping researchData)
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
        string *listOfSpecifications = m_indices(researchData);
        object bonusDictionary = getDictionary("bonuses");
        if (bonusDictionary && listOfSpecifications)
        {
            string bonusToCheck;
            foreach(string specification in listOfSpecifications)
            {
                if (sscanf(specification, "bonus %s", bonusToCheck) &&
                    bonusDictionary->isValidBonus(bonusToCheck))
                {
                    ret->set(specification,
                        applyModifiers(ritualMultiplier(specification,
                            researchData[specification]), owner, researchData["modifiers"]));
                }
                else if (sscanf(specification, "apply %s", bonusToCheck) &&
                    bonusDictionary->isValidBonus(bonusToCheck))
                {
                    ret->set(bonusToCheck,
                        applyModifiers(ritualMultiplier(bonusToCheck,
                            researchData[specification]), owner, researchData["modifiers"]));
                    if(owner->isNegativeCombatModifier(bonusToCheck))
                    {
                        ret->set("check kill list", 1);
                    }
                }
                else if (sscanf(specification, "penalty to %s", bonusToCheck) &&
                    bonusDictionary->isValidBonus(bonusToCheck))
                {
                    ret->set(specification,
                        applyModifiers(ritualMultiplier(specification,
                            researchData[specification]), owner, researchData["modifiers"]));
                    ret->set("check kill list", 1);
                }
            }
        }
    }
    return ret;
}
