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
        addSpecification("name", "impaired");
        addSpecification("description", "You are impaired from the effects of barbituates.");
        addSpecification("root", "biological");
        addSpecification("opinion", -15);
        addSpecification("duration", 300);
        addSpecification("expire message", "You are no longer impaired from barbituates.");
        "baseTrait"::reset(arg);
    }
}
