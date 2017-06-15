//*****************************************************************************
// Class: researchItem
// File Name: researchItem.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/specification.c";
virtual inherit "/lib/core/prerequisites.c";
virtual inherit "/lib/commands/baseCommand.c";
    
private nosave string ResearchItemLocation = "lib/modules/research";
    
/////////////////////////////////////////////////////////////////////////////
protected nomask int checkValidType(string typeToCheck)
{
    int ret = 1;
    if(typeToCheck && stringp(typeToCheck))
    {
        switch(typeToCheck)
        {
            case "active":
            {
                if(member(inherit_list(this_object()), 
                   sprintf("%s/activeResearchItem.c", ResearchItemLocation)) 
                   < 0)
                {
                    ret = 0;
                }
                break;
            }
            case "sustained":
            {
                if(member(inherit_list(this_object()), 
                   sprintf("%s/sustainedResearchItem.c", ResearchItemLocation)) 
                   < 0)
                {
                    ret = 0;
                }
                break;
            }
            case "passive":
            {
                if(member(inherit_list(this_object()), 
                   sprintf("%s/passiveResearchItem.c", ResearchItemLocation)) 
                   < 0)
                {
                    ret = 0;
                }
                break;
            }
            case "ritual":
            {
                if(member(inherit_list(this_object()), 
                   sprintf("%s/ritualResearchItem.c", ResearchItemLocation)) 
                   < 0)
                {
                    ret = 0;
                }
                break;
            }
            case "knowledge":
            {
                if(member(inherit_list(this_object()), 
                   sprintf("%s/knowledgeResearchItem.c", ResearchItemLocation))
                   < 0)
                {
                    ret = 0;
                }
                break;
            }                
            default:
            {
                ret = 0;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidResearchItem()
{
    // All items that use research items check isValidResearchItem. Trying to
    // circumvent addSpecification won't work particularly well given that
    // the inherit_list and this method are called in unison.
    return member(researchData, "type") && 
        checkValidType(researchData["type"]);
}

/////////////////////////////////////////////////////////////////////////////
protected int addSpecification(string type, mixed value)
{
    int ret = 0;
    if(type && stringp(type))
    {
        switch(type)
        {
            case "prerequisites":
            {
                if(value && mappingp(value))
                {
                    string *indices = m_indices(value);
                    if (sizeof(indices))
                    {
                        ret = 1;
                        foreach(string index in indices)
                        {
                            ret &&= addPrerequisite(index, value[index]);
                        }
                    }
                }
            }
            case "type":
            {
                if(checkValidType(value))
                {
                    ret = 1;
                    researchData["type"] = value;
                }
                else if(stringp(value) && (member(({ "active", "passive", 
                    "sustained", "ritual", "knowledge" }), value) > -1))
                {
                
                    raise_error(sprintf("ERROR - researchItem: A '%s' type "
                        "specification can only be used if "
                        "'%sResearchItem.c' is inherited.\n", value, value));
                }
                else
                {
                    raise_error("ERROR - researchItem: The value of 'type' must"
                        " be one of: active, passive, sustained, ritual, or "
                        "knowledge.\n");
                }                        
                break;
            }
            case "scope":
            {
                if(value && stringp(value) && (member(({ "self", "targeted",
                   "area", "environmental", "region", "global" }),value) > -1))
                {
                    ret = 1;
                    researchData["scope"] = value;
                }
                else
                {
                    raise_error("ERROR - researchItem: The value of 'scope' must"
                        " be one of: self, targeted, area, environmental, "
                        "region, or global.\n");
                }
                break;
            }
            case "effect":
            {
                if(value && stringp(value) && (member(({"beneficial", "combat",
                   "enchantment", "summoning", "strategic" }),value) > -1))
                {
                    ret = 1;
                    researchData["effect"] = value;
                }
                else
                {
                    raise_error("ERROR - researchItem: The value of 'effect' must"
                        " be one of: beneficial, combat, enchantment, "
                        "summoning, or strategic.\n");
                }
                break;
            }
            case "research type":
            {
                if(value && stringp(value) && (member(({ "points", "timed",
                   "tree root", "granted" }),value) > -1))
                {
                    ret = 1;
                    researchData["research type"] = value;
                }
                else
                {
                    raise_error("ERROR - researchItem: The value of 'research "
                        "type' must be one of: points, timed, or tree "
                        "root.\n");
                }
                break;
            }
            case "research cost":
            {
                if(value && intp(value) && (value > 0))
                {
                    ret = 1;
                    researchData["research cost"] = value;
                }
                else
                {
                    raise_error("ERROR - researchItem: The value of 'research "
                        "cost' must be an integer value greater than 0.\n");
                }
                break;
            }
            default:
            {
                ret = specification::addSpecification(type, value);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mixed query(string element)
{
    mixed ret = 0;
    if (element == "prerequisites")
    {
        ret = getPrerequisites();
    }
    else
    {
        ret = specification::query(element);
    }
    return ret;
}
