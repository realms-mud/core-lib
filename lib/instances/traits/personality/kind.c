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
        addSpecification("name", "kind");
        addSpecification("description", "You tend to be a very pleasant and "
            "well-intentioned person.");
        addSpecification("root", "kind");
        addSpecification("opposing root", "cruel");
        addSpecification("opinion", 10);
        addSpecification("opposing opinion", 5);
        addSpecification("bonus persuasion", 1);
        addSpecification("penalty to intimidation", 1);
        "baseTrait"::reset(arg);
    }
}
