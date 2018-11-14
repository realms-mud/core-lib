//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "The Flame");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This skill provides the user with the"
            " knowledge to express their raw magical energy as flame.");

        addSpecification("limited by", (["equipment":({ "axe" })]));

        addSpecification("scope", "self");
        addSpecification("research type", "tree root");
        addSpecification("bonus elemental fire", 1);
    }
}
