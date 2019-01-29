//*****************************************************************************
// Class: knowledgeResearchItem
// File Name: knowledgeResearchItem.c
//
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/research/researchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask int addSpecification(string type, mixed value)
{
    int ret = 0;

    switch(type)
    { 
        case "affected research":
        {
            if(mappingp(value))
            {
                int validModifier = 1;
                foreach(mixed key in m_indices(value))
                {
                    validModifier &&= stringp(key) && intp(value[key]);
                }
                if(validModifier)
                {
                    researchData[type] = value;
                    ret = 1;
                }
                else
                {
                    raise_error(sprintf("ERROR - knowledgeResearchItem: "
                        "the '%s' specification must be a properly formatted "
                        "modifier.\n" , type));
                }                
            }
            else
            {
                raise_error(sprintf("ERROR - knowledgeResearchItem: "
                    "the '%s' specification must be a properly formatted "
                    "modifier.\n" , type));
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
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "knowledge");
        addSpecification("scope", "self");
        addSpecification("effect", "strategic");
    }
}
