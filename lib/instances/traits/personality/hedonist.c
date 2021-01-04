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
        addSpecification("name", "hedonist");
        addSpecification("description", "You believe that the pursuit of "
            "sensual pleasures is paramount.");
        addSpecification("root", "hedonist");
        addSpecification("opposing root", "celibate");
        addSpecification("opinion", 5);
        addSpecification("opposing opinion", -15);
        "baseTrait"::reset(arg);
    }
}
