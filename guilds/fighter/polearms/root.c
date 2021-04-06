//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "Pole Arms");
        addSpecification("source", "fighter");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of general polearm attack techniques.");

        addSpecification("limited by", (["equipment": ({ "pole arm" }) ]));

        addSpecification("scope", "self");
        addSpecification("research type", "tree root");
        addSpecification("bonus attack", 1);
    }
}
