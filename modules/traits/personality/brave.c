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
        addSpecification("name", "brave");
        addSpecification("description", "You are fearless in the face of "
            "danger.");
        addSpecification("root", "brave");
        addSpecification("opposing root", "coward");
        addSpecification("opinion", 10);
        addSpecification("opposing opinion", -5);
        "baseTrait"::reset(arg);
    }
}
