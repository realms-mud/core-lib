//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "health");
        addSpecification("name", "Stuff 2");
        addSpecification("description", "blah blah blah - yes, blah");
        addSpecification("root", "disfigured");
        addSpecification("opposing root", "normal");
        addSpecification("opinion", 10);
        addSpecification("opposing opinion", -10);
        addSpecification("cost", 1);
        addSpecification("bonus fire enchantment", 4);
        "baseTrait"::reset(arg);
    }
}
