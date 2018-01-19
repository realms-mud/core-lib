//*****************************************************************************
// Class: ritualResearchItem
// File Name: ritualResearchItem.c
//
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/research/researchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "ritual");
    }
}

/////////////////////////////////////////////////////////////////////////////
protected int addSpecification(string type, mixed value)
{
    int ret = 0;
    switch(type)
    {
        case "cooldown":
        {
            if(intp(value) && (value > 0))
            {
                researchData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error(sprintf("ERROR - ritualResearchItem: the '%s'"
                    " specification must be an integer greater than 0.\n",
                    type));
            }
            break;
        }
        case "event handler":
        case "use ability message":
        case "use ability fail message":
        case "use ability cooldown message":
        {
            if (value && stringp(value))
            {
                researchData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error(sprintf("ERROR - ritualResearchItem: the '%s'"
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
                ret = 1;
            }
            else
            {
                raise_error(sprintf("ERROR - ritualResearchItem: the '%s'"
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
protected int executeOnSelf(object owner, string researchName)
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
protected int executeInArea(object owner, string researchName)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
protected int executeOnEnvironment(object owner, string researchName)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
protected int executeOnRegion(object owner, string researchName)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
protected int executeGlobally(object owner, string researchName)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int applyToScope(string command, object owner,
    string researchName)
{
    int ret = 0;
    if(member(researchData, "scope"))
    {
        switch(researchData["scope"])
        {
            case "self":
            {
                ret = executeOnSelf(owner, researchName);
                break;
            }
            case "targeted":
            {
                ret = executeOnTarget(command, owner, researchName);
                break;
            }
            case "area":
            {
                ret = executeInArea(owner, researchName);
                break;
            }
            case "environmental":
            {
                ret = executeOnEnvironment(owner, researchName);
                break;
            }
            case "region":
            {
                ret = executeOnRegion(owner, researchName);
                break;
            }
            case "global":
            {
                ret = executeGlobally(owner, researchName);
                break;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected int performRitual(object initiator)
{
    return 0;
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
        ret = 1;
        if(initiator->blockedByCooldown(researchName))
        {
            string coolDownMessage = 
                (member(researchData, "use ability cooldown message") && 
                stringp(researchData["use ability cooldown message"])) ?
                researchData["use ability cooldown message"] :
                sprintf("You must wait longer before you use '%s' again.\n",
                    member(researchData, "name") ? researchData["name"] :
                    "that skill");
                    
            displayMessage(coolDownMessage, initiator, initiator);
            ret = 0;
        }
        ret &&= performRitual(initiator);
        
        if(ret && !initiator->spellAction())
        {
            ret = applyToScope(command, initiator, researchName);
            if(!ret && member(researchData, "use ability fail message"))
            {
                displayMessage(researchData["use ability fail message"], 
                    initiator, initiator);
            }
            initiator->spellAction(1);
        }
    }
    return ret;
}

