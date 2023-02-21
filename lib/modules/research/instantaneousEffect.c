//*****************************************************************************
// Class: instantaneousEffect
// File Name: instantaneousEffect.c
//
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/specification.c";
virtual inherit "/lib/core/prerequisites.c";
virtual inherit "/lib/commands/baseCommand.c";
virtual inherit "/lib/modules/research/effectModifier.c";

protected string *validEffects = ({ 
    "increase hit points", 
    "increase spell points",
    "increase stamina points", 
    "decrease intoxication",
    "decrease druggedness", 
    "decrease soaked", 
    "decrease stuffed",
    "damage hit points", 
    "siphon hit points",
    "damage spell points",
    "siphon spell points",
    "damage stamina points",
    "siphon stamina points",
    "increase intoxication",
    "increase druggedness", 
    "increase soaked",
    "increase stuffed",
    "supercede targets"
});

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
    
    if(member(specificationData, type) && isValidFormula(specificationData[type]))
    {
        // First, build the probability dictionary
        mapping formulaDictionary = ([ ]);
        
        int currentProbability = 0;
        foreach(mapping formula in specificationData[type])
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
        
        if(member(specificationData, "modifiers"))
        {
            ret = applyModifiers(ret, initiator, specificationData["modifiers"]);
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
        case "increase hit points":
        case "increase spell points":
        case "increase stamina points":
        case "decrease intoxication":
        case "decrease druggedness":
        case "decrease soaked":
        case "decrease stuffed":
        {
            specificationData["is beneficial"] = 1;
            // This should fall through to the next session.
        }
        case "damage hit points":
        case "damage spell points":
        case "damage stamina points":        
        case "increase intoxication":
        case "increase druggedness":
        case "increase soaked":
        case "increase stuffed":
        case "siphon hit points":
        case "siphon spell points":
        case "siphon stamina points":
        {
            if(isValidFormula(value))
            {
                specificationData[type] = value;
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
                    specificationData[type] = value;
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
            object attacks = getDictionary("attacks");
            if(stringp(value) && attacks && attacks->isValidDamageType(value))
            {
                specificationData[type] = value;
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
        case "supercede targets":
        {
            specificationData[type] = value;
            ret = 1;
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
protected nomask int executeOnSelf(string unparsedCommand, object owner, 
    string researchName)
{
    int ret = 0;

    // checks for this item being researched are already done in execute()
    // as are checks to verify that owner is a living object. We don't
    // allow the caster to do negative things to themselves here...    
    ret = applyBeneficialEffect(owner, owner);
    
    if(ret && member(specificationData, "use ability message") &&
       stringp(specificationData["use ability message"]))
    {
        displayMessage(specificationData["use ability message"],
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
        if(member(specificationData, "use ability message") &&
           stringp(specificationData["use ability message"]))
        {
            displayMessage(specificationData["use ability message"],
                owner, target);
        }
        ret = applyEffect(owner, target);
    }
    else
    {
        displayMessageToSelf("You must specify a target.\n", owner);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int executeInArea(string unparsedCommand, object owner, 
    string researchName)
{
    int ret = 1;

    object *environmentObjects = filter(all_inventory(environment(owner)),
        (: $1 != $2 :), owner);

    foreach(object target in environmentObjects)
    {
        if(function_exists("has", target) && target->has("combat"))
        {
            ret += applyEffect(owner, target);
        }
    }
          
    if(member(specificationData, "use ability message") 
       && stringp(specificationData["use ability message"]))
    {
        displayMessage(specificationData["use ability message"],
            owner, owner);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getEffectsToApply(object initiator)
{
    mapping ret = ([
        "damage type": specificationData["damage type"],
        "use combination message": 
            member(specificationData, "use combination message") ?
            specificationData["use combination message"] : "",
        "effects": ([])
    ]);

    string *effectList = filter(validEffects,
        (: member(specificationData, $1) :));

    foreach(string type in effectList)
    {
        if (member(specificationData, type))
        {
            ret["effects"][type] = applyFormula(initiator, type);
        }
    }
    return ret;
}
