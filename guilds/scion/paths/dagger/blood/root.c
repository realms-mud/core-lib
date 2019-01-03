//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "The Wounded");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This skill provides the user with "
            "the knowledge to express their raw magical energy as blood "
            "magic.");

        addSpecification("limited by", (["equipment":({
            "dagger", "short sword" }) ]));

        addSpecification("scope", "self");
        addSpecification("research type", "tree root");
        addSpecification("bonus blood", 1);
    }
}
