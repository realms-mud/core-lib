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
        addSpecification("name", "Chants and Songs Without Instruments");
        addSpecification("source", "bard");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of various chants and other songs that do not "
            "require a musical instrument to perform - in other words, "
            "those songs that can be played while using a weapon.");

        addSpecification("scope", "self");
        addSpecification("research type", "tree root");
        addSpecification("bonus singing", 1);
    }
}
