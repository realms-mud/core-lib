//*****************************************************************************
// Class: activeResearchItem
// File Name: activeResearchItem.c
//
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/research/researchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "active");
    }
}

/////////////////////////////////////////////////////////////////////////////
protected int addSpecification(string type, mixed value)
{
    int ret = 0;
    switch(type)
    {
        case "hit point cost":
        case "spell point cost":
        case "stamina point cost":
        case "cooldown":
        {
            if(intp(value) && (value > 0))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error(sprintf("ERROR - activeResearchItem: the '%s'"
                    " specification must be an integer greater than 0.\n",
                    type));
            }
            break;
        }
        case "event handler":
        case "use ability message":
        case "use ability fail message":
        case "use ability cooldown message":
        case "use combination message":
        {
            if (value && stringp(value))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error(sprintf("ERROR - activeResearchItem: the '%s'"
                    " specification must be a string.\n",
                    type));
            }
            break;
        }
        case "command template":
        {
            if(value && stringp(value))
            {
                ret = addCommandTemplate(value);
            }
            else
            {
                raise_error(sprintf("ERROR - activeResearchItem: the '%s'"
                    " specification must be a string.\n",
                    type));
            }
            break;
        }
        default:
        {
            ret = "researchItem"::addSpecification(type, value);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected int executeOnSelf(string unparsedCommand, object owner, 
    string researchName)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
protected int executeOnTarget(string unparsedCommand, object owner,
    string researchName)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
protected int executeInArea(string unparsedCommand, object owner,
    string researchName)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
protected int executeOnEnvironment(string unparsedCommand, object owner,
    string researchName)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
protected int executeOnRegion(string unparsedCommand, object owner, 
    string researchName)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
protected int executeGlobally(string unparsedCommand, object owner, 
    string researchName)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int applyToScope(string command, object owner,
    string researchName)
{
    int ret = 0;
    if(member(specificationData, "scope"))
    {
        switch(specificationData["scope"])
        {
            case "self":
            {
                ret = executeOnSelf(command, owner, researchName);
                break;
            }
            case "targeted":
            {
                ret = executeOnTarget(command, owner, researchName);
                break;
            }
            case "area":
            {
                ret = executeInArea(command, owner, researchName);
                break;
            }
            case "environmental":
            {
                ret = executeOnEnvironment(command, owner, researchName);
                break;
            }
            case "region":
            {
                ret = executeOnRegion(command, owner, researchName);
                break;
            }
            case "global":
            {
                ret = executeGlobally(command, owner, researchName);
                break;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected mapping getUsageCosts(string command, object initiator)
{
    return ([
        "hit point cost": query("hit point cost"),
        "spell point cost": query("spell point cost"),
        "stamina point cost": query("stamina point cost")
    ]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;
    string researchName = program_name(this_object());

    if(initiator && objectp(initiator) && canExecuteCommand(command) &&
       function_exists("isResearched", initiator) &&
       initiator->isResearched(researchName))
    {
        notify_fail("");
        ret = 1;
        if(initiator->blockedByCooldown(researchName))
        {
            string coolDownMessage = 
                (member(specificationData, "use ability cooldown message") && 
                stringp(specificationData["use ability cooldown message"])) ?
                specificationData["use ability cooldown message"] :
                sprintf("You must wait longer before you use '%s' again.\n",
                    member(specificationData, "name") ? specificationData["name"] :
                    "that skill");
                    
            displayMessageToSelf(coolDownMessage, initiator);
            ret = 0;
        }

        mapping costs = getUsageCosts(command, initiator);
        if(ret && ((costs["hit point cost"] > initiator->hitPoints()) ||
            (costs["spell point cost"] > initiator->spellPoints()) ||
            (costs["stamina point cost"] > initiator->staminaPoints())))
        {
            string costsTooMuch = sprintf("You do not have the required "
                "energy reserve to use '%s'.\n", member(specificationData, "name") ?
                specificationData["name"] : "that skill");
                
            displayMessageToSelf(costsTooMuch, initiator);
            ret = 0;
        }
        
        if(ret && !initiator->spellAction())
        {
            ret = applyToScope(command, initiator, researchName);
            if(ret)
            {
                if(costs["hit point cost"])
                {
                    initiator->hitPoints(-costs["hit point cost"]);
                }
                if(costs["spell point cost"])
                {
                    initiator->spellPoints(-costs["spell point cost"]);
                }
                if(costs["stamina point cost"])
                {
                    initiator->staminaPoints(-costs["stamina point cost"]);
                }
            }
            initiator->spellAction(1);
        }
    }
    return ret;
}
