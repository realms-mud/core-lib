//*****************************************************************************
// Class: instantaneousEffect
// File Name: instantaneousEffect.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

virtual inherit "/lib/core/specification.c";
virtual inherit "/lib/core/prerequisites.c";
virtual inherit "/lib/commands/baseCommand.c";
virtual inherit "/lib/modules/research/effectModifier.c";

/////////////////////////////////////////////////////////////////////////////
private nomask object attackDictionary()
{
    object ret = 0;
    
    string dictionary = "/lib/dictionaries/attacksDictionary.c";
    if(file_size(dictionary) > -1)
    {
        ret = load_object(dictionary);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int isValidFormula(mapping *formulas)
{
    int ret = 0;
    
    if(formulas && pointerp(formulas) && sizeof(formulas))
    {
        ret = 1;
        
        // At the end of the loop, this MUST be 100
        int cumulativeProbability = 0;
        
        foreach(mapping formula in formulas)
        {
            ret &&= (formula && mappingp(formula) && 
                member(formula, "probability") && 
                intp(formula["probability"])) &&
                ((member(formula, "base damage") && 
                intp(formula["base damage"]) &&
                member(formula, "range") && 
                intp(formula["range"])) || 
                (member(formula, "custom method") &&
                stringp(formula["custom method"]) &&
                function_exists(formula["custom method"], this_object())));
                
            if(ret)
            {
                cumulativeProbability += formula["probability"];
            }
        }
        
        ret &&= cumulativeProbability == 100;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int applyFormula(object initiator, string type)
{
    int ret = 0;
    
    if(member(researchData, type) && isValidFormula(researchData[type]))
    {
        // First, build the probability dictionary
        mapping formulaDictionary = ([ ]);
        
        int currentProbability = 0;
        foreach(mapping formula in researchData[type])
        {      
            int bottomOfRange = currentProbability;
            int topOfRange = bottomOfRange + formula["probability"];
            
            int tmpFormula = 0;
            // If this exists, we already know that we have this method 
            // available since we passed the call to isValidFormula.
            if(member(formula, "custom method"))
            {
                tmpFormula = 
                    call_other(this_object(), formula["custom method"], 
                               initiator);
            }
            else
            {
                tmpFormula =
                    formula["base damage"] + random(formula["range"] + 1);
            }

            for(int i = bottomOfRange; i < topOfRange; i++)
            {
                formulaDictionary[i] = tmpFormula;
            }
                
            currentProbability += formula["probability"];       
        }
        
        ret = formulaDictionary[random(100)];
        
        if(member(researchData, "modifiers"))
        {
            ret = applyModifiers(ret, initiator, researchData["modifiers"]);
        }
    }    
    return ret;    
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int addInstantaneousSpecification(string type, mixed value)
{
    int ret = 0;

    switch(type)
    {
        case "damage hit points":
        case "damage spell points":
        case "damage stamina points":        
        case "increase hit points":
        case "increase spell points":
        case "increase stamina points":
        case "decrease intoxication":
        case "decrease druggedness":
        case "decrease soaked":
        case "decrease stuffed":
        case "increase intoxication":
        case "increase druggedness":
        case "increase soaked":
        case "increase stuffed":
        {
            if(isValidFormula(value))
            {
                researchData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error(sprintf("ERROR - instantaneousEffect: "
                    "the '%s' specification must be a properly formatted "
                    "formula.\n" , type));
            }
            break;
        }
        case "modifiers":
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
                    raise_error(sprintf("ERROR - instantaneousEffect: "
                        "the '%s' specification must be a properly formatted "
                        "modifier.\n" , type));
                }                
            }
            else
            {
                raise_error(sprintf("ERROR - instantaneousEffect: "
                    "the '%s' specification must be a properly formatted "
                    "modifier.\n" , type));
            }
            break;
        }      
        case "damage type":
        {
            object attacks = attackDictionary();
            if(stringp(value) && attacks && attacks->isValidDamageType(value))
            {
                researchData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error("ERROR - instantaneousEffect: the "
                    "'damage type' specification must be a valid attack type "
                    "as defined in attacksDictionary.\n");
            }
            break;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected int applyBeneficialEffect(object initiator, object target)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
protected int applyEffect(object initiator, object target)
{
    return 0;
}
    
/////////////////////////////////////////////////////////////////////////////
protected nomask int executeOnSelf(object owner, string researchName)
{
    int ret = 0;

    // checks for this item being researched are already done in execute()
    // as are checks to verify that owner is a living object. We don't
    // allow the caster to do negative things to themselves here...    
    ret = applyBeneficialEffect(owner, owner);
    
    if(ret && member(researchData, "use ability message") &&
       stringp(researchData["use ability message"]))
    {
        displayMessage(researchData["use ability message"],
            owner, owner);
    }   
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int executeOnTarget(string unparsedCommand, object owner,
    string researchName)
{
    int ret = 0;
    object target = getTarget(owner, unparsedCommand);
    if(target)
    {
        ret = applyEffect(owner, target);
    
        if(ret && member(researchData, "use ability message") &&
           stringp(researchData["use ability message"]))
        {
            displayMessage(researchData["use ability message"],
                owner, target);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int executeInArea(object owner, string researchName)
{
    int ret = 1;

    object *environmentObjects = all_inventory(environment(owner));
    foreach(object target in environmentObjects)
    {
        if(function_exists("has", target) && target->has("combat"))
        {
            ret += applyEffect(owner, target);
        }
    }
          
    if(member(researchData, "use ability message") 
       && stringp(researchData["use ability message"]))
    {
        displayMessage(researchData["use ability message"],
            owner, owner);
    }
    return ret;
}
