//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/research/researchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask int addSpecification(string type, mixed value)
{
    int ret = 0;

    switch(type)
    {  
        case "related research":
        {
            if(pointerp(value) && sizeof(value) && stringp(value[0]))
            {
                specificationData[type] = value;
                ret = 1;           
            }
            else
            {
                raise_error(sprintf("ERROR - knowledgeResearchItem: "
                    "the '%s' specification must be a list of related "
                    "research.\n" , type));
            }
            break;
        }    
        case "damage type":
        {
            object attacks = getService("attacks");
            if(stringp(value) && attacks && attacks->isValidDamageType(value))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error("ERROR - constructedResearchComponent: the "
                    "'damage type' specification must be a valid attack type "
                    "as defined in attacksService.\n");
            }
            break;
        }
        case "additional hit point cost":
        case "additional spell point cost":
        case "additional stamina point cost":
        case "additional cooldown":
        {
            if(intp(value) && (value > 0))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error(sprintf("ERROR - constructedResearchComponent: the '%s'"
                    " specification must be an integer greater than 0.\n",
                    type));
            }
            break;
        }
        case "use combination message":
        {
            if (value && stringp(value))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error(sprintf("ERROR - constructedResearchComponent: the '%s'"
                    " specification must be a string.\n",
                    type));
            }
            break;
        }
    }

    if(!ret)
    {
        ret = researchItem::addSpecification(type, value);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{

}

/////////////////////////////////////////////////////////////////////////////
public void create()
{
    addSpecification("type", "constructed");
    addSpecification("effect", "strategic");
    Setup();
}

/////////////////////////////////////////////////////////////////////////////
protected string displayRelatedResearchEffects(string colorConfiguration,
    object configuration)
{
    string ret = "";
    if (member(specificationData, "related research"))
    {
        object Service = getService("research");

        foreach(string researchItem in specificationData["related research"])
        {
            object research = Service->researchObject(researchItem);
            if (research)
            {
                ret += research->getRelatedResearchEffects(this_object(),
                    colorConfiguration, configuration);
            }
        }
    }

    if (member(specificationData, "damage type"))
    {
        ret = configuration->decorate(
            sprintf("Constructed items cause %s damage,\n",
                specificationData["damage type"]),
            "bonus text", "research", colorConfiguration);
    }

    if (member(specificationData, "additional hit point cost"))
    {
        ret = configuration->decorate(
            sprintf("Hit point cost of constructed items increased by %d%%\n",
                specificationData["additional hit point cost"]),
            "bonus text", "research", colorConfiguration);
    }

    if (member(specificationData, "additional spell point cost"))
    {
        ret = configuration->decorate(
            sprintf("Spell point cost of constructed items increased by %d%%\n",
                specificationData["additional spell point cost"]),
            "bonus text", "research", colorConfiguration);
    }

    if (member(specificationData, "additional stamina point cost"))
    {
        ret = configuration->decorate(
            sprintf("Stamina cost of constructed items increased by %d%%\n",
                specificationData["additional stamina point cost"]),
            "bonus text", "research", colorConfiguration);
    }

    if (member(specificationData, "additional cooldown"))
    {
        ret = configuration->decorate(
            sprintf("Cooldown of constructed items increased by %ds.\n",
                specificationData["additional cooldown"]),
            "bonus text", "research", colorConfiguration);
    }

    return ret;
}
