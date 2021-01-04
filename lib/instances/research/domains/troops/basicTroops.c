//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        knowledgeResearchItem::reset(arg);
        addSpecification("name", "Basic Troops");
        addSpecification("source", "domains");
        addSpecification("description", "This skill provides the user with the "
            "knowledge required to form armies, use formations, and assign "
            "activities.");
        addSpecification("research type", "granted");
    }
}
