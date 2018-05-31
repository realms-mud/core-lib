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
        addSpecification("name", "Basic Building");
        addSpecification("source", "domains");
        addSpecification("description", "This skill provides the user with the "
            "knowledge required to oversee simple domain construction projects.");
        addSpecification("research type", "granted");
    }
}
