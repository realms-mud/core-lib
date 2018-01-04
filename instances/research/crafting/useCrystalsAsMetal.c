//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        knowledgeResearchItem::reset(arg);
        addSpecification("name", "Substitute metals with crystals");
        addSpecification("description", "This skill provides the user with the "
            "knowledge required to use gems and crystals as substitues for "
            "metals when crafting.");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addPrerequisite("lib/instances/research/crafting/craftGems.c", (["type":"research"]));
        addPrerequisite("lib/instances/research/crafting/craftReconditeMetal.c", (["type":"research"]));
    }
}

