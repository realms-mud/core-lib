//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        sustainedResearchItem::reset(arg);
        addSpecification("name", "Sustained research");
        addSpecification("scope", "targeted");
        addSpecification("research type", "granted");
        addSpecification("cooldown", 4);
        addSpecification("command template", "throw turnip at ##Target##");
        addSpecification("trait", "lib/tests/support/traits/testTraitForSustainedResearch.c");
    }
}

