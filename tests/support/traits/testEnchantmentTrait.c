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
        addSpecification("type", "health");
        addSpecification("name", "Stuff");
        addSpecification("description", "blah blah blah");
        addSpecification("root", "disfigured");
        addSpecification("opposing root", "normal");
        addSpecification("opinion", 10);
        addSpecification("opposing opinion", -10);
        addSpecification("cost", 1);
        addSpecification("bonus fire enchantment", 2);
        addSpecification("bonus electricity enchantment", 5);
        addSpecification("bonus magical enchantment", 1);
        "baseTrait"::reset(arg);
    }
}
