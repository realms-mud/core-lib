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
        addSpecification("name", "on benzos");
        addSpecification("description", "You are impaired from the effects of benzodiazepine.");
        addSpecification("root", "biological");
        addSpecification("opinion", -15);
        addSpecification("duration", 300);
        addSpecification("expire message", "You are no longer impaired from benzodiazepine.");
        "baseTrait"::reset(arg);
    }
}
