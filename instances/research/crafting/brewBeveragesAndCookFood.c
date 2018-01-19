//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        knowledgeResearchItem::reset(arg);
        addSpecification("name", "Brew Beverages / Cook Food");
        addSpecification("description", "This skill provides the user with the "
            "knowledge required to brew beverages (such as ale) and cook finer cuisine.");
        addSpecification("research type", "granted");
    }
}

