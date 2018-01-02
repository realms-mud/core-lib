//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/prerequisites.c";
virtual inherit "/lib/items/item.c";

/////////////////////////////////////////////////////////////////////////////
private nomask int setPrerequisiteData(mapping data)
{
    int ret = 1;
    if (member(data, "crafting prerequisites"))
    {
        mapping prereqs = data["crafting prerequisites"];
        string *prereqList = m_indices(prereqs);
        if (sizeof(prereqList))
        {
            foreach(string prereq in prereqList)
            {
                addPrerequisite(prereq, prereqs[prereq]);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int set(string element, mixed data)
{
    int ret = 0;
    
    if(element && stringp(element))
    {
        switch(element)
        {
            case "blueprint data":
            {
                ret = mappingp(data) &&
                    setPrerequisiteData(data);
                break;
            }
            default:
            {
                ret = "item"::set(element, data);
            }
        }
    }
    return ret;
}