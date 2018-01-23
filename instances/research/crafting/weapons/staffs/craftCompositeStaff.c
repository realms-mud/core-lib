//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        knowledgeResearchItem::reset(arg);
        addSpecification("name", "Craft Composite Staff");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "knowledge required to craft complex staffs like sword staffs and brogit staffs.");
        addSpecification("research type", "granted");
        addPrerequisite("lib/instances/research/crafting/weapons/craftWeapons.c", (["type":"research"]));
    }
}

