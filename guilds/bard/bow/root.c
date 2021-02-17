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
        addSpecification("name", "Archery");
        addSpecification("source", "bard");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of advanced archery techniques");

        addSpecification("limited by", (["equipment":({ "bow" }) ]));

        addSpecification("scope", "self");
        addSpecification("research type", "tree root");
        addSpecification("bonus bow", 1);
    }
}
