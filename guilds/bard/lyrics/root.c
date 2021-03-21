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
        addSpecification("name", "Lyrical Components");
        addSpecification("source", "bard");
        addSpecification("description", "This skill provides the user with the "
            "basic knowledge of creating spell-like effects with lyrics.");

        addSpecification("scope", "self");
        addSpecification("research type", "tree root");
    }
}
