//*****************************************************************************
// Class: activeResearchItem
// File Name: activeResearchItem.c
//
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/research/researchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{

}

/////////////////////////////////////////////////////////////////////////////
public void create()
{
    addSpecification("type", "active");
    Setup();
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
        case "repeat effect":
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
        case "cooldown modifiers":
        {
            if(mappingp(value) && (sizeof(value) == sizeof(filter(value,
                (: intp($2) && ($2 < query("cooldown")) :)))))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error(sprintf("ERROR - activeResearchItem: the '%s'"
                    " specification must be a valid cooldown modifier mapping.\n",
                    type));
            }
            break;
        }
        case "hit point cost modifiers":
        case "spell point cost modifiers":
        case "stamina point cost modifiers":
        {
            string cost = regreplace(type, "(.*) modifiers", "\\1", 1);

            if(mappingp(value) && (sizeof(value) == sizeof(filter(value,
                (: intp($2) && ($2 < query($3)) :), cost))))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error(sprintf("ERROR - activeResearchItem: the '%s'"
                    " specification must be a valid cost modifier mapping.\n",
                    type));
            }
            break;
        }
        case "composite research":
        case "composite type":
        case "composite class":
        case "default composite description":
        case "event handler":
        case "cooldown group":
        case "use composite message":
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
                specificationData[type] = value;
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
        case "consumables":
        {
            if (mappingp(value) && (sizeof(value) == sizeof(filter(value,
                (: (stringp($1) && intp($2)) :)))))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error(sprintf("ERROR - activeResearchItem: the '%s'"
                    " specification must be a valid mapping.\n",
                    type));
            }
            break;
        }
        default:
        {
            ret = researchItem::addSpecification(type, value);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int cooldown(object initiator)
{
    int ret = query("cooldown");
    mapping modifiers = query("cooldown modifiers");

    if (mappingp(modifiers) && objectp(initiator))
    {
        modifiers = filter(modifiers, (: $3->isResearched($1) :), initiator);
        foreach(string item in modifiers)
        {
            ret -= modifiers[item];
        }
        if (ret < 2)
        {
            ret = 2;
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
public nomask void repeatEffect(int timesRemaining, string command, 
    object owner, string researchName)
{
    int ret = applyToScope(command, owner, researchName);
    if (ret && (timesRemaining > 1))
    {
        call_out("repeatEffect", 2, timesRemaining - 1,
            command, owner, researchName);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask int useConsumables(object initiator)
{
    int ret = 1;

    if (member(specificationData, "consumables"))
    {
        object *potentialConsumables = all_inventory(initiator) +
            all_inventory(environment(initiator));
        mapping itemsToConsume = ([]);

        foreach(string item in m_indices(specificationData["consumables"]))
        {
            for (int i = 0; i < specificationData["consumables"][item]; i++)
            {
                object *consumables = filter(potentialConsumables,
                    (: ($1->id($2) && 
                        !(($1->query("quantity") <= itemsToConsume[$1]) &&
                        $1->doNotDestroyWhenConsumed())) :), item);

                if (sizeof(consumables))
                {
                    if (member(itemsToConsume, consumables[0]))
                    {
                        itemsToConsume[consumables[0]]++;
                    }
                    else
                    {
                        itemsToConsume[consumables[0]] = 1;
                    }
                }
                else
                {
                    ret = 0;
                    itemsToConsume = ([]);
                    break;
                }
            }
        }

        if (ret)
        {
            foreach(object item in m_indices(itemsToConsume))
            {
                if (item->query("quantity") > 0)
                {
                    int newQty = item->query("quantity") - itemsToConsume[item];
                    item->set("quantity", newQty);
                }
                if ((item->query("quantity") < 1) &&
                    !item->doNotDestroyWhenConsumed())
                {
                    destruct(item);
                }
            }
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;
    string researchName = program_name(this_object());

    string compositeResearch = member(specificationData, "composite research") ?
        specificationData["composite research"] : 0;

    if(initiator && objectp(initiator) && 
        (canExecuteCommand(command) || (compositeResearch == command)) &&
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
        
        if(ret && (!initiator->spellAction() || compositeResearch))
        {
            ret = useConsumables(initiator) && 
                applyToScope(command, initiator, researchName);

            if (member(specificationData, "repeat effect"))
            {
                call_out("repeatEffect", 2, specificationData["repeat effect"],
                    command, initiator, researchName);
            }

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
