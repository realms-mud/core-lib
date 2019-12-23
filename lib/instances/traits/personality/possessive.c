//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "personality");
        addSpecification("name", "possessive");
        addSpecification("description", "You tend to be over-protective and "
            "controlling of what you deem to be your things - be they real "
            "possessions or the people in your life.");
        addSpecification("root", "harsh");
        addSpecification("opposing root", "kind");
        addSpecification("opinion", -10);
        addSpecification("opposing opinion", -15);
        addSpecification("penalty to diplomacy", 1);
        addSpecification("bonus intimidation", 1);
        "baseTrait"::reset(arg);
    }
}
