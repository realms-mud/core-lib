//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/research/researchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask int addSpecification(string type, mixed value)
{
    int ret = 0;

    switch(type)
    {
        case "power":
        {
            if(intp(value) && (value > 0))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error(sprintf("ERROR - domainResearchItem: the '%s'"
                    " specification must be an integer greater than 0.\n",
                    type));
            }
            break;           
        }      
        case "affected buildings":
        {
            object domains = getDictionary("domain");

            if (pointerp(value) && sizeof(value) && domains &&
                domains->validBuildings(value))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error(sprintf("ERROR - domainResearchItem: the '%s'"
                    " specification must be a set of valid buildings.\n",
                    type));
            }
            break;
        }   
        case "building effects":
        {
            object domains = getDictionary("domain");

            if (mappingp(value) && sizeof(value) && domains &&
                domains->validBuildingEffects(value))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error(sprintf("ERROR - domainResearchItem: the '%s'"
                    " specification must be a valid building effects mapping.\n",
                    type));
            }
            break;
        }   
        case "troop effects":
        {
            object domains = getDictionary("domain");

            if (mappingp(value) && sizeof(value) && domains &&
                domains->validTroopEffects(value))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error(sprintf("ERROR - domainResearchItem: the '%s'"
                    " specification must be a valid troop effects mapping.\n",
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
protected void Setup()
{

}

/////////////////////////////////////////////////////////////////////////////
public void create()
{
    addSpecification("type", "domain");
    addSpecification("scope", "domain");
    addSpecification("effect", "strategic");
    Setup();
}
