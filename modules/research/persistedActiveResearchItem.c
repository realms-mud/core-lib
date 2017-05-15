//*****************************************************************************
// Class: persistedActiveResearchItem
// File Name: persistedActiveResearchItem.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//
// Description: TBD
//
//*****************************************************************************
virtual inherit "/lib/modules/research/activeResearchItem.c";
virtual inherit "/lib/modules/research/effectModifier.c";

/////////////////////////////////////////////////////////////////////////////
protected int addSpecification(string type, mixed value)
{
    int ret = 0;
    
    string bonusToCheck;
    if(sscanf(type, "bonus %s", bonusToCheck) || 
       sscanf(type, "penalty to %s", bonusToCheck))
    {
        if(getDictionary("bonuses") &&
           getDictionary("bonuses")->isValidBonusModifier(bonusToCheck, value))
        {
            researchData[type] = value;
            ret = 1;
        }
        else if(getDictionary("bonuses"))
        {
            raise_error(sprintf("ERROR - persistedActiveResearchItem: the '%s'"
                " specification must be a valid modifier as defined in %s\n",
                type, program_name(getDictionary("bonuses"))));
        }
    }
    else if(type == "duration")
    {
        if(intp(value) && (value > 0))
        {
            researchData[type] = value;
            ret = 1;
        }
        else
        {
            raise_error("ERROR - persistedActiveResearchItem: the duration "
                "specification must be a positive integer.\n");
        }
    }
    else if(type == "modifier")
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
                researchData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error(sprintf("ERROR - persistedActiveResearchItem: "
                    "the '%s' specification must be a properly formatted "
                    "modifier.\n" , type));
            }                
        }
        else
        {
            raise_error(sprintf("ERROR - persistedActiveResearchItem: "
                "the '%s' specification must be a properly formatted "
                "modifier.\n" , type));
        }    
    }
    else
    {
        ret = "activeResearchItem"::addSpecification(type, value);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void deactivateModifierObject(object modifierToDeactivate)
{
    remove_call_out("deactivateModifierObject");
    effectModifier::deactivateModifierObject(modifierToDeactivate);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int executeOnSelf(object owner, string researchName)
{
    int ret = 0;

    // checks for this item being researched are already done in execute()
    // as are checks to verify that owner is a living object.
    object modifier = getModifierObject(owner, researchData);
    if(modifier && member(researchData, "duration"))
    {
        ret = modifier->registerModifierWithTargetList(({ owner }));

        if(ret)
        {
            call_out("deactivateModifierObject", researchData["duration"],
                modifier);

            if(member(researchData, "use ability message") &&
               stringp(researchData["use ability message"]))
            { 
                displayMessage(researchData["use ability message"],
                    owner, owner);
            }
        }
    }        
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int executeOnTarget(string unparsedCommand, object owner,
    string researchName)
{
    int ret = 0;
    object target = getTarget(owner, unparsedCommand);
    if(target && member(researchData, "duration"))
    {
        object modifier = getModifierObject(owner, researchData);

        if(modifier && (!modifier->query("check kill list") || (modifier->query("check kill list") &&
            ((target->onKillList() && !target->isRealizationOf("player")) ||
            (target->isRealizationOf("player") && owner->isRealizationOf("player") &&
            target->onKillList() && owner->onKillList())))))
        {
            ret = modifier->registerModifierWithTargetList(({ target }));
            
            if (ret)
            {
                call_out("deactivateModifierObject", researchData["duration"],
                    modifier);

                if (member(researchData, "use ability message") &&
                    stringp(researchData["use ability message"]))
                {
                    displayMessage(researchData["use ability message"],
                        owner, target);
                }
            }
        }  
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int executeInArea(object owner, string researchName)
{
    int ret = 0;
    object modifier = getModifierObject(owner, researchData);
    if(modifier && environment(owner) && member(researchData, "duration"))
    {
        object *environmentObjects = all_inventory(environment(owner));
        object *targetObjects = ({ });
        foreach(object target in environmentObjects)
        {
            if(function_exists("registerObjectAsInventory", target) &&
                ((!modifier->query("check kill list") && !target->isRealizationOf("monster")) || 
                (modifier->query("check kill list") &&
                ((target->onKillList() && !target->isRealizationOf("player")) ||
                (target->isRealizationOf("player") && owner->isRealizationOf("player") &&
                target->onKillList() && owner->onKillList() && target != owner)))))
            {
                targetObjects += ({ target });
            }
        }
        
        ret = modifier->registerModifierWithTargetList( targetObjects );
         
        if (ret)
        {
            call_out("deactivateModifierObject", researchData["duration"],
                modifier);

            if (member(researchData, "use ability message")
                && stringp(researchData["use ability message"]))
            {
                displayMessage(researchData["use ability message"],
                    owner, owner);
            }
        }
    }
    return ret;
}


