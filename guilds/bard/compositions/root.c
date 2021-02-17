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
        addSpecification("name", "Musical Compositions");
        addSpecification("source", "bard");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of composing and playing songs that can provide "
            "complex effects.");

        addSpecification("limited by", ([
            "equipment": ({ "instrument: plucked", "instrument: bowed",
                "instrument: woodwind", "instrument: brass",
                "instrument: percussion" }) ]));

        addSpecification("scope", "self");
        addSpecification("research type", "tree root");
        addSpecification("bonus attack", 1);
    }
}
