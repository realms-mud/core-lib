//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "personality");
        addSpecification("name", "coward");
        addSpecification("description", "You are a craven - when strife "
            "comes calling, you flee to your safe place.");
        addSpecification("root", "coward");
        addSpecification("opposing root", "brave");
        addSpecification("opinion", 5);
        addSpecification("opposing opinion", -10);
        "baseTrait"::reset(arg);
    }
}
