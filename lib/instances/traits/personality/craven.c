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
        addSpecification("type", "personality");
        addSpecification("name", "craven");
        addSpecification("description", "You are a contemptable coward - "
            "when strife comes calling, you flee to your safe place.");
        addSpecification("root", "coward");
        addSpecification("opposing root", "brave");
        addSpecification("opinion", -5);
        addSpecification("opposing opinion", -20);
        "baseTrait"::reset(arg);
    }
}
