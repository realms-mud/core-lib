//*****************************************************************************
// Class: knowledgeResearchItem
// File Name: knowledgeResearchItem.c
//
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
    addSpecification("type", "knowledge");
    addSpecification("scope", "self");
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
        object dictionary = getDictionary("research");

        foreach(string researchItem in specificationData["related research"])
        {
            object research = dictionary->researchObject(researchItem);
            if (research)
            {
                ret += research->getRelatedResearchEffects(this_object(),
                    colorConfiguration, configuration);
            }
        }
    }
    return ret;
}
