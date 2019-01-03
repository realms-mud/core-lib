//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "personality");
        addSpecification("name", "diligent");
        addSpecification("description", "You have an unwavering resolve "
            "to perform your duties to your utmost ability.");
        addSpecification("root", "self-motivated");
        addSpecification("opposing root", "lazy");
        addSpecification("opinion", 10);
        addSpecification("opposing opinion", -5);
        "baseTrait"::reset(arg);
    }
}
